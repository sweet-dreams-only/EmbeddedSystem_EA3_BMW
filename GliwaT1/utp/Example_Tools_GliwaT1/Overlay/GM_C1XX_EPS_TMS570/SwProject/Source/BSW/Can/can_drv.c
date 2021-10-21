/* Kernbauer Version: 1.14 Konfiguration: can_driver Erzeugungsgangnummer: 1 */

/* STARTSINGLE_OF_MULTIPLE */


/* KB begin CanLL_Header */
#ifdef C_COMP_TI_TMS470_DCAN
/* ***************************************************************************
| Project Name: DrvCan_TMS470Dcan
|    CBD: File Name: CAN_DRV.C
|    Asr: File Name: Can.c
|
|  Description: Implementation of the CAN driver
|               Target systems: TMS470PSF761
|               Compiler:       Texas Instruments
|               TechnicalReference: TechnicalReference_DrvCanAsr_Tms470_Dcan.pdf */
#endif
/*----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 1996-2010 by Vctr Informatik GmbH.       All rights reserved.
|
| This software is copyright protected and proprietary 
| to Vctr Informatik GmbH. Vctr Informatik GmbH 
| grants to you only those rights as set out in the 
| license conditions. All other rights remain with 
| Vctr Informatik GmbH.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Ht           Heike Honert              Vctr Informatik GmbH
| Bir          Holger Birke              Vctr Informatik GmbH
| Pl           Georg Pfluegel            Vctr Informatik GmbH
| Kk           Karol Kostolny            Vctr Informatik GmbH
| Seg          Sebastian Gaertner        Vctr Informatik GmbH
| Ou           Mihai Olariu              Vctr Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Ver  Author  Description
| ---------  ---  ------  ----------------------------------------------------
| 2006-11-06   1.00    Pl     - ESCAN00020209: Create a new can-driver for the TMS470PSF761
| 2007-06-12   1.01    Pl     - ESCAN00020210: Support all features for a standard can-driver 
|                                              (Extended and Mixed ID, RAM-check added)
| 2007-09-04   1.02    Kk     - ESCAN00022217: Support low level message transmit feature
|                             - ESCAN00022235: Issue in RAM check in function CanLL_IsMailboxCorrupt() fixed
| 2007-11-01   1.03    Pl     - ESCAN00023055: Support Autosar 2.1 for the TMS470PSF761
| 2008-04-24   1.04    Pl     - ESCAN00025297: Support new platform Nios from Altera
|                             - ESCAN00026389: Inside the Tx-Task there is a missing Interruptlock necessary
| 2008-07-01   1.05    Pl     - ESCAN00027990: Update to Autosar 3.0 for the Platform TMS470/TMS570 DCAN
| 2009-06-16   1.06    Pl     - ESCAN00035177: Update to new Highlevel Version 3.07.01
|                             - ESCAN00034736: Compiler Warnings: function declared implicitly
|                             - ESCAN00034821: Compiler Warnings: variable "canHwRxBasicStartIdx" was set but never used
|                             - ESCAN00034825: Compiler Warnings: variable "status_stop" was set but never used
| 2009-07-23   1.07    Seg    - ESCAN00029495: Support of Highend Features and Multiple Configuration for the Platform TMS470/TMS570 DCAN
| 2009-09-29   1.08    Seg    - ESCAN00038099: Add Compiler Abstraction and Memory mapping
|                             - ESCAN00038181: CAN communication fails
| 2009-11-04   1.09    Seg    - ESCAN00038927: Can ISR prototype CanIsr_0 is always set and cannot be disabled
| 2009-11-18   1.10    Seg    - ESCAN00039366: support local power down mode
|                             - ESCAN00039256: ECU is blocked and nothing was working or other unexpected behaviour
| 2010-04-08   1.10.01 Pl     - ESCAN00042030: If a single channel configuration use not the first hardware channel, the reception of messages did not work
| 2010-07-12   1.11    Ou     - ESCAN00043180: Autosar only: Compiler Warnings: function declared implicitly
|                             - ESCAN00043953: Implement the DCAN "Init bit" errata
| 2010-10-25   1.12    Pl     - ESCAN00046368: Support of the TMS570PSFC66 for CANbedded added
|************************************************************************* */
/* KB end CanLL_Header */
/*****************************************************************************
|
|    ************    Version and change information of      **********        
|    ************    high level part only                   **********        
|
|    Please find the version number of the whole module in the previous 
|    File header.
|
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Ht           Heike Honert              Vctr Informatik GmbH
| Pl           Georg Pfluegel            Vctr Informatik GmbH
| Vg           Frank Voorburg            Vector CANtech, Inc.
| An           Ahmad Nasser              Vector CANtech, Inc.
| Ml           Patrick Markl             Vctr Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Ver  Author  Description
| ---------  ---  ------  ----------------------------------------------------
| 19-Jan-01  0.02  Ht     - derived form C16x V3.3
| 18-Apr-01  1.00  Pl     - derived for ARM7 TDMI
| 02-May-01  1.01  Ht     - adaption to LI1.2
|                         - change from code doupling to indexed
| 31-Oct-01  1.02  Ht     - support hash search
|                  Ht     - optimisation for message access (hardware index)
|                  Vg     - adaption for PowerPC
| 07-Nov-01  1.03  Ht     - remove some comments
|                         - support of basicCAN polling extended
| 12-Dez-01  1.04  Ht     - avoid compiler warnings for KEIL C166
|                         - ESCAN00001881: warning in CanInitPowerOn
|                         - ESCAN00001913: call of CanLL_TxEnd()
|                  Fz     - ESCAN00001914: CanInterruptRestore changed for M32C
| 02-Jan-02  1.05  Ht     - ESCAN00002009: support of polling mode improved
|                         - ESCAN00002010: Prototype of CanHL_TxConfirmation() 
|                                          not available in every case.
| 12-Feb-02  1.06 Pl      - ESCAN00002279: - now it is possible to use only the error-task without the tx-task
|                                          - support of the makro  REENTRANT
|                                          - support of the makro C_HL_ENABLE_RX_INFO_STRUCT_PTR
|                                          - For better performance for the T89C51C there is a switch-case
|                                            instruction for direct call of the PreTransmitfunction
|                                          - add C_ENABLE_RX_BASICCAN_POLLING in CanInitPowerOn
| 18-Mai-02  1.07 Ht      - ESCAN....    : support Hash search with FullCAN controller
|                         - ESCAN00002707: Reception could went wrong if IL and Hash Search
|                         - ESCAN00002893: adaption to LI 1.3
| 29-Mai-02  1.08 Ht      - ESCAN00003028: Transmission could fail in Polling mode
|                         - ESCAN00003082: call Can_LL_TxEnd() in CanMsgTransmit()
|                         - ESCAN00003083: Hash search with extended ID
|                         - ESCAN00003084: Support C_COMP_METROWERKS_PPC
|                         - ESCAN00002164: Temporary vaiable "i" not defined in function CanBasicCanMsgReceived
|                         - ESCAN00003085: support C_HL_ENABLE_IDTYPE_IN_ID
| 25-Jun     1.08.01 Vg   - Declared localInterruptOldFlag in CanRxTask()
|                         - Corrected call to CanWakeUp for multichannel
| 11-Jul-02  1.08.02 Ht   - ESCAN00003203: Hash Search routine does not work will with extended IDs
|                         - ESCAN00003205: Support of ranges could went wrong on some platforms
| 08-Aug-02  1.08.03 Ht   - ESCAN00003447: Transmission without databuffer and pretransmit-function 
| 08-Aug-02  1.08.04 An   - Added support to Green Hills
| 09-Sep-02  1.09    Ht   - ESCAN00003837: code optimication with KernelBuilder
|                         - ESCAN00004479: change the place oft the functioncall of CanLL_TxCopyMsgTransmit
|                                          in CanMsgTransmit 
| 2002-12-06 1.10    Ht   -                Support consistancy for polling tasks
|                         - ESCAN00004567: Definiton of V_NULL pointer
|                         -                remove include of string.h
|                         -                support Dummy functions for indirect function call 
|                         -                optimization for one single Tx mail box
| 2003-02-04 1.11    Ht   -                optimization for polling mode
| 2003-03-19 1.12    Ht   - ESCAN00005152: optimization of CanInit() in case of Direct Tx Objects
|                         - ESCAN00005143: CompilerWarning about function prototype 
|                                          CanHL_ReceivedRxHandle() and CanHL_IndRxHandle
|                         - ESCAN00005130: Wrong result of Heash Search on second or higher channel               
| 2003-05-12 1.13    Ht   - ESCAN00005624: support CantxMsgDestroyed for multichannel system
|                         - ESCAN00005209: Support confirmation and indication flags for EasyCAN4
|                         - ESCAN00004721: Change data type of Handle in CanRxInfoStruct
| 2003-06-18 1.20   Ht    - ESCAN00005908: support features of RI1.4
|                         - ESCAN: Support FJ16LX-Workaround for multichannel system
|                         - ESCAN00005671: Dynamic Transmit Objects: ID in extended ID frames is wrong
|                         - ESCAN00005863: Notification about cancelation failes in case of CanTxMsgDestroyed
| 2003-06-30 1.21   Ht   - ESCAN00006117: Common Confirmation Function: Write access to wrong memory location
|                        - ESCAN00006008: CanCanInterruptDisable in case of polling
|                        - ESCAN00006118: Optimization for Mixed ID and ID type in Own Register or ID type in ID Register
|                        - ESCAN00006100: transmission with wrong ID in mixed ID mode
|                        - ESCAN00006063: Undesirable hardware dependency for 
|                                         CAN_HL (CanLL_RxBasicTxIdReceived)
| 2003-09-10 1.22   Ht   - ESCAN00006853: Support V_MEMROM0
|                        - ESCAN00006854: suppress some Compiler warnings
|                        - ESCAN00006856: support CanTask if only Wakeup in polling mode
|                        - ESCAN00006857: variable newDLC not defined in case of Variable DataLen
| 2003-10-14 1.23   Ht   - ESCAN00006858: support BrsTime for internal runtime measurement
|                        - ESCAN00006860: support Conditional Msg Receive
|                        - ESCAN00006865: support "Cancel in HW" with CanTask
|                        - ESCAN00006866: support Direct Tx Objects
|                        - ESCAN00007109: support new memory qualifier for const data and pointer to const
| 2004-01-05 1.24   Ml   - ESCAN00007206: resolved preprocessor error for Hitachi compiler
|                   Ml   - ESCAN00007254: several changes
| 2004-02-06 1.25   Ml   - ESCAN00007281: solved compilerwarning
|                   Ml   - removed compiler warnings
| 2004-02-21 1.26   Ml   - ESCAN00007670: CAN RAM check
|                   Ml   - ESCAN00007671: fixed dyn Tx object issue
|                   Ml   - ESCAN00007764: added possibility to adjust Rx handle in LL drv
|                   Ml   - ESCAN00007681: solved compilerwarning in CanHL_IndRxHandle
|                   Ml   - ESCAN00007272: solved queue transmission out of LowLevel object
|                   Ml   - ESCAN00008064: no changes
| 2004-04-16 1.27   Ml   - ESCAN00008204: no changes
|                   Ml   - ESCAN00008160: no changes
|                   Ml   - ESCAN00008266: changed name of parameter of function CanTxGetActHandle
|                   Fz   - ESCAN00008272: Compiler error due to missing array canPollingTaskActive
| 2004-05-10 1.28   Fz   - ESCAN00008328: Compiler error if cancel in hardware is active
|                        - ESCAN00008363: Hole closed when TX in interrupt and cancel in HW is used
|                        - ESCAN00008365: Switch C_ENABLE_APPLCANPREWAKEUP_FCT added
|                        - ESCAN00008391: Wrong parameter macro used in call of 
|                                         CanLL_WakeUpHandling
| 2004-05-24 1.29   Ht   - ESCAN00008441: Interrupt not restored in case of internal error if TX Polling is used
| 2004-09-21 1.30   Ht   - ESCAN00008914: CAN channel may stop transmission for a certain time
|                        - ESCAN00008824: check of reference implementation version added
|                        - ESCAN00008825: No call of ApplCanMsgCancelNotification during CanInit()
|                        - ESCAN00008826: Support asssertions for "Conditional Message Received"  
|                   Ml   - ESCAN00008752: Added function qualifier macros
|                   Ht   - ESCAN00008823: compiler error due to array size 0
|                        - ESCAN00008977: label without instructions
|                        - ESCAN00009485: Message via Normal Tx Object will not be sent  
|                        - ESCAN00009497: support of CommonCAN and RX queue added
|                        - ESCAN00009521: Inconsitancy in total polling mode
| 2004-09-28 1.31   Ht   - ESCAN00009703: unresolved functions CAN_POLLING_IRQ_DISABLE/RESTORE()
| 2004-11-25 1.32   Ht   - move fix for ESCAN00007671 to CAN-LL of DrvCan_MpcToucanHll
|                        - ESCAN00010350: Dynamic Tx messages are send always with Std. ID
|                        - ESCAN00010388: ApplCanMsgConfirmed will only be called if realy transmitted
|                    Ml  - ESCAN00009931: The HardwareLoopCheck should have a channelparameter in multichannel systems.
|                    Ml  - ESCAN00010093: lint warning: function type inconsistent "CanCheckMemory"
|                    Ht  - ESCAN00010811: remove Misra and compiler warnings
|                        - ESCAN00010812: support Multi ECU
|                        - ESCAN00010526: CAN interrupts will be disabled accidently
|                        - ESCAN00010584: ECU may crash or behave strange with Rx queue active
| 2005-01-20 1.33    Ht  - ESCAN00010877: ApplCanMsgTransmitConf() is called erronemous
| 2005-03-03 1.34    Ht  - ESCAN00011139: Improvement/Correction of C_ENABLE_MULTI_ECU_CONFIG
|                        - ESCAN00011511: avoid PC-Lint warnings
|                        - ESCAN00011512: copy DLC in case of variable Rx Datalen
|                        - ESCAN00010847: warning due to missing brakets in can_par.c at CanChannelObject
| 2005-05-23 1.35   Ht   - ESCAN00012445: compiler error "V_MEMROMO undefined"in case of multi ECU
|                        - ESCAN00012350: Compiler Error "Illegal token channel"
| 2005-07-06 1.36   Ht   - ESCAN00012153: Compile Error: missing declaration of variable i
|                        - ESCAN00012460: Confirmation of LowLevel message will run into assertion (C_ENABLE_MULTI_ECU_PHYS enabled)
|                        - support Testpoints for CanTestKit
| 2005-07-14 1.37   Ht   - ESCAN00012892: compile error due to missing logTxObjHandle
|                        - ESCAN00012998: Compile Error: missing declaration of txHandle in CanInit()
|                        - support Testpoints for CanTestKit for FullCAN controller
| 2005-09-21 1.38   Ht   - ESCAN00013597: Linker error: Undefined symbol 'CanHL_IndRxHandle'
| 2005-11-10 1.39.00 Ht  - ESCAN00014331: Compile error due to missing 'else' in function CanTransmit
|
| 2005-04-26 2.00.00  Ht - ESCAN00016698: support RI1.5
|                        - ESCAN00014770: Cosmic compiler reports truncating assignement
|                        - ESCAN00016191: Compiler warning about unused variable in CanTxTask
|
| 2007-01-23 2.01.00  Ht - ESCAN00017279: Usage of SingleGlobalInterruptDisable lead to assertion in OSEK
|                        - ESCAN00017148: Compile error in higher layer due to missing declaration of CanTxMsgHandleToChannel
| 2007-03-14 2.02.00  Ht - ESCAN00019825: error directives added and misra changes
|                        - ESCAN00019827: adaption to never version of VStdLib.
|                        - ESCAN00019619: V_CALLBACK_1 and V_CALLBACK_2 not defined
|                        - ESCAN00019953: Handling of FullCAN reception in interrupt instead of polling or vice versa.
|                        - ESCAN00019958: CanDynTxObjSetId() or CanDynTxObjSetExtId() will run into assertion
| 2007-03-26 2.03.00  Ht - ESCAN00019988: Compile warnings in can_drv.c
|                        - ESCAN00018831: polling mode: function prototype without function implemenation (CanRxFullCANTask + CanRxBasicCANTask)
| 2007-04-20 2.04.00  dH - ESCAN00020299: user assertion fired irregularly due to unknown parameter (in case of CommonCAN)
| 2007-05-02 2.05.00  Ht - ESCAN00021069: Handling of canStatus improved, usage of preprocessor defines unified
|                        - ESCAN00021070: support relocation of HW objects in case of Multiple configuration
|                        - ESCAN00021166: Compiler Warnings: canHwChannel & canReturnCode not used in CanGetStatus
|                        - ESCAN00021223: CanCanInterruptDisabled called during Sleepmode in CanWakeupTask
|                        - ESCAN00022048: Parameter of ApplCancorruptMailbox is hardware channel instead of logical channel - Error directive added
| 2007-11-12 2.06.00  Ht - ESCAN00023188: support CAN Controller specific polling sequence for BasicCAN objects
|                        - ESCAN00023208: Compile issue about undefined variable kCanTxQueuePadBits in the CAN driver in Bit based Tx queue
| 2008-10-20 2.07.00  Ht - ESCAN00023010: support disabled mailboxes in case of extended RAM check
|                        - ESCAN00025706: provide C_SUPPORTS_MULTI_ECU_PHYS
|                        - ESCAN00026120: compiler warnings found on DrvCan_V85xAfcanHll RI 1.5     ##Ht: reviewed 2008-09-03
|                        - ESCAN00026322: ApplCanMsgNotMatched not called in special configuration
|                        - ESCAN00026413: Add possibility to reject remote frames received by FullCAN message objects
|                        - ESCAN00028758: CAN HL must support QNX
|                        - ESCAN00029788: CommonCAN for Driver which support only one Tx object improved (CanInit()).
|                        - ESCAN00029889: Compiler warning about uninitialized variable canHwChannel in CanCanInterruptDisable/Restore()
|                        - ESCAN00029891: Compiler warning: variable "rxHandle" was set but never used
|                        - ESCAN00029929: Support Extended ID Masking for Tx Fullcan messages 
|                        - ESCAN00030371: Improvements (assertions, misra)
|                        - ESCAN00027931: Wrong check of "queueBitPos" size
| 2009-04-08 2.08.00  Ht - ESCAN00034492: no automatic remove of CanCanInterruptDisable/Restore
|                        - ESCAN00031816: CANRANGExIDTYPE can be removed and direct expression used
|                        - ESCAN00032027: CanMsgTransmit shall support tCanMsgTransmitStruct pointer accesses to far RAM
|                        - ESCAN00034488: Postfix for unsigned const in perprocessor directives are not supported by all Compiler (ARM-Compiler 1.2)
| 2009-06-04 2.08.01  Ht - ESCAN00035426: Compiler warning about truncation in CanGetStatus removed
| 2009-10-21 2.09.00  Ht - ESCAN00036258: Compiler warning about "CanHL_ReceivedRxHandle" was declared but never referenced
|                        - ESCAN00038642: Support reentrant functions for compiler with own keyword
|                        - ESCAN00038645: support new switch C_ENABLE_UPDATE_BASE_ADDRESS
| 2010-02-01 2.10.00  Ht - ESCAN00036260: Support configuartion without static Tx messages and only one channel (remove compiler warning)
|                        - ESCAN00040478: Handle update of virtual CanBaseAdress in accordance to QNX documentation
|                        - ESCAN00039235: Compiler Warning: Narrowing or Signed-to-Unsigned type conversion

|
|
|    ************    Version and change information of      **********        
|    ************    high level part only                   **********        
|
|    Please find the version number of the whole module in the previous 
|    File header.
|
|***************************************************************************/

#define C_DRV_INTERNAL

/* PRQA S 3453 EOF */      /* suppress messages: a function should probably used instead of function like macro. misra 19.7 */
/* PRQA S 3109 EOF */      /* suppress messages about empty statements. misra 14.3 */
/* PRQA S 2006 EOF */      /* suppress misra message about multiple return. misra 14.7 */


/*lint -function(exit,ApplCanFatalError)*/

/***************************************************************************/
/* Include files                                                           */
/***************************************************************************/
/* KB begin canLL_Include */
/* KB end canLL_Include */

#include "can_inc.h"
#include "Metrics.h"

#ifndef T1_ENABLE
#error "This version of can_drv.c is only intended for a metrics build."
#endif

/* KB begin canLL_PostInclude */
/* KB end canLL_PostInclude */

/***************************************************************************/
/* Version check                                                           */
/***************************************************************************/
/* KB begin canLL_VersionCheck */
#if( DRVCAN_TMS470DCANHLL_VERSION != 0x0112)
 #error "Source and Header file are inconsistent!"
#endif

#if( DRVCAN_TMS470DCANHLL_RELEASE_VERSION != 0x00)
 #error "Source and Header file are inconsistent!"
#endif

/* KB end canLL_VersionCheck */

#if( C_VERSION_REF_IMPLEMENTATION != 0x150)
# error "Generated Data and CAN driver source file are inconsistent!"
#endif

#if( DRVCAN__COREHLL_VERSION != 0x0210)
# error "Source and Header file are inconsistent!"
#endif
#if( DRVCAN__COREHLL_RELEASE_VERSION != 0x00)
# error "Source and Header file are inconsistent!"
#endif

/* KB begin CanHL_TxQueueVersionC */
#if ( ( DRVCAN__HLLTXQUEUEBIT_VERSION != 0x0106) )
# error "TxQueue Source and Header Version inconsistent!"
#endif
#if ( ( DRVCAN__HLLTXQUEUEBIT_RELEASE_VERSION != 0x02) )
# error "TxQueue Source and Header Version inconsistent!"
#endif
/* KB end CanHL_TxQueueVersionC */


#if defined( DRVCAN__HLLTXQUEUEBIT_VERSION )
# if ( ( DRVCAN__HLLTXQUEUEBIT_VERSION != 0x0106) || \
       ( DRVCAN__HLLTXQUEUEBIT_RELEASE_VERSION != 0x02)  )
#  error "TxQueue Version inconsistent!"
# endif

/* defines to satisfy MISRA checker tool */
# define DRVCAN__HLLTXQUEUEBYTE_VERSION 0x0000
# define DRVCAN__HLLTXQUEUEBYTE_RELEASE_VERSION 0x00

#else
# if defined( DRVCAN__HLLTXQUEUEBYTE_VERSION )
#  if ( ( DRVCAN__HLLTXQUEUEBYTE_VERSION != 0x0104) || \
       ( DRVCAN__HLLTXQUEUEBYTE_RELEASE_VERSION != 0x00)  )
#   error "TxQueue Version inconsistent!"
#  endif
# else
#  error "No TxQueue available"
# endif

/* defines to satisfy MISRA checker tool */
# define DRVCAN__HLLTXQUEUEBIT_VERSION 0x0000
# define DRVCAN__HLLTXQUEUEBIT_RELEASE_VERSION 0x00

#endif


/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/


/* ##RI-1.1: Object parameters for Tx-Observe functions */
/* status of transmit objects */
#define kCanBufferFree                                     ((CanTransmitHandle)0xFFFFFFFFU)   /* mark a transmit object is free */
#define kCanBufferCancel                                   ((CanTransmitHandle)0xFFFFFFFEU)   /* mark a transmit object as canceled */
#define kCanBufferMsgDestroyed                             ((CanTransmitHandle)0xFFFFFFFDU)   /* mark a transmit object as destroyed */
/* reserved value because of definition in header:    0xFFFFFFFCU */
/* valid transmit message handle:   0x0 to kCanNumberOfTxObjects   */

/* return values */ 
#define kCanHlFinishRx                                     ((vuint8)0x00)
#define kCanHlContinueRx                                   ((vuint8)0x01)

/* KB begin CanHL_TxQueueDefines */
#define  CANHL_TX_QUEUE_BIT
/* KB end CanHL_TxQueueDefines */
/* KB begin CanLL_Defines */
/* Define chiphardware                     */
/* Constants concerning can chip registers */
/* control registers for msg objects       */
   
#define kClearAll          ((vuint16)0x0000)       /* 00000000 00000000 */ /* use to clear all Bit in a word     */
#define kErrBusOff         ((vuint16)0x0080)       /* 00000000 10000000 */ /* Error:  Busoff  Limit reached      */
#define kErrWarning        ((vuint16)0x0040)       /* 00000000 01000000 */ /* Error:  Warning Limit reached      */
#define kErrPassive        ((vuint16)0x0020)       /* 00000000 00100000 */ /* Error:  Passive Limit reached      */
#define kWakeupPending     ((vuint16)0x0200)       /* 00000000 00100000 */ /* Status: CAN was waked up           */


/* defines to test a bit in a register */
#define kIFxBusy           ((vuint16)0x8000)       /* 10000000 00000000 */ /* Test IFx Command Request           */ 
#define kCanStatusInt      ((vuint16)0x8000)       /* 10000000 00000000 */ /* Statusinterrupt in CAN_Cell        */

/* defines to set a Bit in the CAN Control Register */
#if defined( C_ENABLE_SLEEP_WAKEUP )
# if defined( C_ENABLE_NO_WAKEUP_BY_BUS ) 
#  define kSetWUBA         ((vuint32)0x00000000)   /* 00000000 00000000 */
# else
#  define kSetWUBA         ((vuint32)0x02000000)   /* 00000000 00000000 */
# endif
#else
#  define kSetWUBA         ((vuint32)0x00000000)   /* 00000000 00000000 */
#endif
#define kSetPDR            ((vuint32)0x01000000)   /* 00000000 00000000 */
#define kSetDE3            ((vuint32)0x00100000)   /* 00000000 00000000 */
#define kSetDE2            ((vuint32)0x00080000)   /* 00000000 00000000 */
#define kSetDE1            ((vuint32)0x00040000)   /* 00000000 00000000 */
#define kSetIE1            ((vuint32)0x00020000)   /* 00000000 00000000 */
#define kSetInitDbg        ((vuint32)0x00010000)   /* 00000000 00000000 */
#define kSetSWR            ((vuint32)0x00008001)   /* 00000000 00000000 */ /* Ou: Init bit must be same time set in case of 16/32-bit accesses  */
#define kSetPMD            ((vuint32)0x00002800)   /* 00000000 00000000 */ /* Nxtr Edit for parity anomaly 3632 correction */
#define kSetABO            ((vuint32)0x00000200)   /* 00000000 00000000 */
#define kSetIDS            ((vuint32)0x00000100)   /* 00000000 00000000 */
                                               
#define kSetTest           ((vuint32)0x00000080)   /* 00000000 10000000 */
#define kSetCCE            ((vuint32)0x00000040)   /* 00000000 01000000 */
#define kSetDAR            ((vuint32)0x00000020)   /* 00000000 00100000 */
#define kSetEIE            ((vuint32)0x00000008)   /* 00000000 00001000 */
#define kSetSIE            ((vuint32)0x00000004)   /* 00000000 00000100 */
#define kSetIE             ((vuint32)0x00000002)   /* 00000000 00000010 */
#define kSetInit           ((vuint32)0x00000001)   /* 00000000 00000001 */

/* defines to set a Bit in the Status Register */
#define kPDA               ((vuint16)0x0400)       /* 00000100 00000000 */
#define kRxOk              ((vuint16)0x0010)       /* 00000000 00010000 */
#define kTxOk              ((vuint16)0x0008)       /* 00000000 00001000 */

/* defines to set a Bit in the IFx Command Mask Register */
#define kSetWrRd           ((vuint16)0x0080)       /* 00000000 10000000 */
#define kSetMask           ((vuint16)0x0040)       /* 00000000 01000000 */
#define kSetArb            ((vuint16)0x0020)       /* 00000000 00100000 */
#define kSetControl        ((vuint16)0x0010)       /* 00000000 00010000 */
#define kSetClrIntPnd      ((vuint16)0x0008)       /* 00000000 00001000 */
#define kSetTxRqstNDat     ((vuint16)0x0004)       /* 00000000 00000100 */
#define kSetDataA          ((vuint16)0x0002)       /* 00000000 00000010 */
#define kSetDataB          ((vuint16)0x0001)       /* 00000000 00000001 */

/* defines to set a Bit in the IFx Mask Register */
#define kSetMsgVal         ((vuint16)0x8000)       /* 10000000 00000000 */
#define kSetDir            ((vuint16)0x2000)       /* 00100000 00000000 */

/* defines to set a Bit in the IFx Message Control Register */
#define kSetNewData       ((vuint16)0x8000)        /* 10000000 00000000 */
#define kSetMsgLst        ((vuint16)0x4000)        /* 01000000 00000000 */
#define kSetIntPnd        ((vuint16)0x2000)        /* 00100000 00000000 */
#define kSetUMask         ((vuint16)0x1000)        /* 00010000 00000000 */
#define kSetTxIE          ((vuint16)0x0800)        /* 00001000 00000000 */
#define kSetRxIE          ((vuint16)0x0400)        /* 00000100 00000000 */
#define kSetRmtEn         ((vuint16)0x0200)        /* 00000010 00000000 */
#define kSetTxRqst        ((vuint16)0x0100)        /* 00000001 00000000 */
#define kSetEoB           ((vuint16)0x0080)        /* 00000000 10000000 */

/* define to set a Bit in the Mask Register */
#define kSetMDir          ((vuint16)0x4000)        /* 01000000 00000000 */
#define kSetXtd           ((vuint16)0x4000)        /* 01000000 00000000 */
#define kSetMXtd          ((vuint16)0x8000)        /* 10000000 00000000 */

/* define to handle Stopmode */ 
#define kSetStopMode       ((vuint8)0x0001)

#if defined ( C_ENABLE_ERROR_POLLING )
# define kSetEnableErrorInt                        kClearAll
#else
# define kSetEnableErrorInt                        kSetEIE
#endif

#if defined ( C_ENABLE_INDIVIDUAL_POLLING ) 
#define CAN_INDIV_POLLING(channel,hwObjHandle)     CanHwObjIndivPolling[channel][hwObjHandle]
# define kSetEnableTxCanInt                        kSetTxIE
# define kSetEnableRxBasicCanInt                   kSetRxIE
# define kSetEnableRxFullCanInt                    kSetRxIE
#else
# define CAN_INDIV_POLLING(channel,hwObjHandle)    0
# if defined ( C_ENABLE_TX_POLLING )
# define kSetEnableTxCanInt                        kClearAll
# else
# define kSetEnableTxCanInt                        kSetTxIE
# endif

# if defined ( C_ENABLE_RX_BASICCAN_POLLING )
# define kSetEnableRxBasicCanInt                   kClearAll
# else
# define kSetEnableRxBasicCanInt                   kSetRxIE
# endif

# if defined ( C_ENABLE_RX_FULLCAN_POLLING )
# define kSetEnableRxFullCanInt                    kClearAll
# else
# define kSetEnableRxFullCanInt                    kSetRxIE
# endif
#endif

#if defined( C_ENABLE_MIXED_ID )
# define kSetUseUMask                              kSetUMask
#else
# define kSetUseUMask                              kClearAll
#endif

# if defined (kCanErrata22Iterations)
#  define CAN_GLOBAL_CONFIG(CanErrata22Iterations) kCanErrata22Iterations
# else
#  define CAN_GLOBAL_CONFIG(CanErrata22Iterations) (vuint16)0xFF
# endif
/* KB end CanLL_Defines */

/***************************************************************************/
/* macros                                                                  */
/***************************************************************************/

#if !(defined( C_HL_DISABLE_RX_INFO_STRUCT_PTR ) || defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR ))
# define C_HL_ENABLE_RX_INFO_STRUCT_PTR
#endif

#if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
# define CAN_HL_P_RX_INFO_STRUCT(channel)                  (pCanRxInfoStruct)  
# define CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)           (pCanRxInfoStruct->Handle)  
#else
# define CAN_HL_P_RX_INFO_STRUCT(channel)                  (&canRxInfoStruct[channel])
# define CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)           (canRxInfoStruct[channel].Handle)  
#endif 


/*disabled - lint -emacro( (572,778), C_RANGE_MATCH) */


#if defined( C_SINGLE_RECEIVE_CHANNEL )
# if (kCanNumberOfUsedCanRxIdTables == 1)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, mask, code) \
                  (  ((idRaw0) & (tCanRxId0)~MK_RX_RANGE_MASK_IDSTD0(mask)) == MK_RX_RANGE_CODE_IDSTD0(code) )
#  define C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, mask, code) \
                  (  ((idRaw0) & (tCanRxId0)~MK_RX_RANGE_MASK_IDEXT0(mask)) == MK_RX_RANGE_CODE_IDEXT0(code) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 2)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDSTD0(mask)) == MK_RX_RANGE_CODE_IDSTD0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDSTD1(mask)) == MK_RX_RANGE_CODE_IDSTD1(code) ) )
#  define C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDEXT0(mask)) == MK_RX_RANGE_CODE_IDEXT0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDEXT1(mask)) == MK_RX_RANGE_CODE_IDEXT1(code) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 3)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDSTD0(mask)) == MK_RX_RANGE_CODE_IDSTD0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDSTD1(mask)) == MK_RX_RANGE_CODE_IDSTD1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDSTD2(mask)) == MK_RX_RANGE_CODE_IDSTD2(code) ) )
#  define C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDEXT0(mask)) == MK_RX_RANGE_CODE_IDEXT0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDEXT1(mask)) == MK_RX_RANGE_CODE_IDEXT1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDEXT2(mask)) == MK_RX_RANGE_CODE_IDEXT2(code) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 4)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDSTD0(mask)) == MK_RX_RANGE_CODE_IDSTD0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDSTD1(mask)) == MK_RX_RANGE_CODE_IDSTD1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDSTD2(mask)) == MK_RX_RANGE_CODE_IDSTD2(code) ) && \
                    ( ((idRaw3) & (tCanRxId3)~ MK_RX_RANGE_MASK_IDSTD3(mask)) == MK_RX_RANGE_CODE_IDSTD3(code) ) )
#  define C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDEXT0(mask)) == MK_RX_RANGE_CODE_IDEXT0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDEXT1(mask)) == MK_RX_RANGE_CODE_IDEXT1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDEXT2(mask)) == MK_RX_RANGE_CODE_IDEXT2(code) ) && \
                    ( ((idRaw3) & (tCanRxId3)~ MK_RX_RANGE_MASK_IDEXT3(mask)) == MK_RX_RANGE_CODE_IDEXT3(code) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 5)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDSTD0(mask)) == MK_RX_RANGE_CODE_IDSTD0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDSTD1(mask)) == MK_RX_RANGE_CODE_IDSTD1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDSTD2(mask)) == MK_RX_RANGE_CODE_IDSTD2(code) ) && \
                    ( ((idRaw3) & (tCanRxId3)~ MK_RX_RANGE_MASK_IDSTD3(mask)) == MK_RX_RANGE_CODE_IDSTD3(code) ) && \
                    ( ((idRaw4) & (tCanRxId4)~ MK_RX_RANGE_MASK_IDSTD4(mask)) == MK_RX_RANGE_CODE_IDSTD4(code) ) )
#  define C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, mask, code) \
                  ( ( ((idRaw0) & (tCanRxId0)~ MK_RX_RANGE_MASK_IDEXT0(mask)) == MK_RX_RANGE_CODE_IDEXT0(code) ) && \
                    ( ((idRaw1) & (tCanRxId1)~ MK_RX_RANGE_MASK_IDEXT1(mask)) == MK_RX_RANGE_CODE_IDEXT1(code) ) && \
                    ( ((idRaw2) & (tCanRxId2)~ MK_RX_RANGE_MASK_IDEXT2(mask)) == MK_RX_RANGE_CODE_IDEXT2(code) ) && \
                    ( ((idRaw3) & (tCanRxId3)~ MK_RX_RANGE_MASK_IDEXT3(mask)) == MK_RX_RANGE_CODE_IDEXT3(code) ) && \
                    ( ((idRaw4) & (tCanRxId4)~ MK_RX_RANGE_MASK_IDEXT4(mask)) == MK_RX_RANGE_CODE_IDEXT4(code) ) )
# endif
#else     /* C_MULTIPLE_RECEIVE_CHANNEL */

# if (kCanNumberOfUsedCanRxIdTables == 1)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH( CAN_RX_IDRAW_PARA, mask, code)    \
                                (  ((idRaw0) & (tCanRxId0)~((mask).Id0)) == ((code).Id0) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 2)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH( CAN_RX_IDRAW_PARA, mask, code)    \
                                ( ( ((idRaw0) & (tCanRxId0)~((mask).Id0)) == ((code).Id0) ) &&\
                                  ( ((idRaw1) & (tCanRxId1)~((mask).Id1)) == ((code).Id1) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 3)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH( CAN_RX_IDRAW_PARA, mask, code)    \
                                ( ( ((idRaw0) & (tCanRxId0)~((mask).Id0)) == ((code).Id0) ) &&\
                                  ( ((idRaw1) & (tCanRxId1)~((mask).Id1)) == ((code).Id1) ) &&\
                                  ( ((idRaw2) & (tCanRxId2)~((mask).Id2)) == ((code).Id2) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 4)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH( CAN_RX_IDRAW_PARA, mask, code)    \
                                ( ( ((idRaw0) & (tCanRxId0)~((mask).Id0)) == ((code).Id0) ) &&\
                                  ( ((idRaw1) & (tCanRxId1)~((mask).Id1)) == ((code).Id1) ) &&\
                                  ( ((idRaw2) & (tCanRxId2)~((mask).Id2)) == ((code).Id2) ) &&\
                                  ( ((idRaw3) & (tCanRxId3)~((mask).Id3)) == ((code).Id3) ) )
# endif
# if (kCanNumberOfUsedCanRxIdTables == 5)
/* Msg(4:3410) Macro parameter not enclosed in (). MISRA Rule 96 - no change */
#  define C_RANGE_MATCH( CAN_RX_IDRAW_PARA, mask, code)    \
                                ( ( ((idRaw0) & (tCanRxId0)~((mask).Id0)) == ((code).Id0) ) &&\
                                  ( ((idRaw1) & (tCanRxId1)~((mask).Id1)) == ((code).Id1) ) &&\
                                  ( ((idRaw2) & (tCanRxId2)~((mask).Id2)) == ((code).Id2) ) &&\
                                  ( ((idRaw3) & (tCanRxId3)~((mask).Id3)) == ((code).Id3) ) &&\
                                  ( ((idRaw4) & (tCanRxId4)~((mask).Id4)) == ((code).Id4) ) )
# endif
#endif


#if (kCanNumberOfUsedCanRxIdTables == 1)
# define CAN_RX_IDRAW_PARA                                 idRaw0
#endif
#if (kCanNumberOfUsedCanRxIdTables == 2)
# define CAN_RX_IDRAW_PARA                                 idRaw0,idRaw1
#endif
#if (kCanNumberOfUsedCanRxIdTables == 3)
# define CAN_RX_IDRAW_PARA                                 idRaw0,idRaw1,idRaw2
#endif
#if (kCanNumberOfUsedCanRxIdTables == 4)
# define CAN_RX_IDRAW_PARA                                 idRaw0,idRaw1,idRaw2,idRaw3
#endif
#if (kCanNumberOfUsedCanRxIdTables == 5)
# define CAN_RX_IDRAW_PARA                                 idRaw0,idRaw1,idRaw2,idRaw3,idRaw4
#endif


#if defined( C_SINGLE_RECEIVE_CHANNEL )
# define channel                                           ((CanChannelHandle)0)
# define canHwChannel                                      ((CanChannelHandle)0)
# define CAN_HL_HW_CHANNEL_STARTINDEX(channel)             ((CanChannelHandle)0)
# define CAN_HL_HW_CHANNEL_STOPINDEX(channel)              ((CanChannelHandle)0)
# define CAN_HL_HW_MSG_TRANSMIT_INDEX(canHwChannel)        (kCanMsgTransmitObj)
# define CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel)           (kCanHwTxNormalIndex)

/* Offset which has to be added to change the hardware Tx handle into a logical handle, which is unique over all channels */
/*        Tx-Hardware-Handle - CAN_HL_HW_TX_STARTINDEX(canHwChannel) + CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel) */
# define CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)          ((vsintx)0-kCanHwTxStartIndex)

# define CAN_HL_TX_STARTINDEX(channel)                     ((CanTransmitHandle)0)
# define CAN_HL_TX_STAT_STARTINDEX(channel)                ((CanTransmitHandle)0)
# define CAN_HL_TX_DYN_ROM_STARTINDEX(channel)             (kCanNumberOfTxStatObjects)
# define CAN_HL_TX_DYN_RAM_STARTINDEX(channel)             ((CanTransmitHandle)0)
/* # define CAN_HL_RX_STARTINDEX(channel)                     ((CanReceiveHandle)0) */
/* index to access the ID tables - Basic index only for linear search 
   for hash search this is the start index of the ??? */
# define CAN_HL_RX_BASIC_STARTINDEX(channel)               ((CanReceiveHandle)0)
# if defined( C_SEARCH_HASH ) 
#  define CAN_HL_RX_FULL_STARTINDEX(canHwChannel)          ((CanReceiveHandle)0)
# else
#  define CAN_HL_RX_FULL_STARTINDEX(canHwChannel)          (kCanNumberOfRxBasicCANObjects)
# endif
# define CAN_HL_INIT_OBJ_STARTINDEX(channel)               ((vuint8)0)
# define CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel)         ((CanObjectHandle)0)
# define CAN_HL_HW_TX_STARTINDEX(canHwChannel)             (kCanHwTxStartIndex)
# define CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel)        (kCanHwRxFullStartIndex)
# define CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)       (kCanHwRxBasicStartIndex)
# define CAN_HL_HW_UNUSED_STARTINDEX(canHwChannel)         (kCanHwUnusedStartIndex)

# define CAN_HL_TX_STOPINDEX(channel)                      (kCanNumberOfTxObjects)
# define CAN_HL_TX_STAT_STOPINDEX(channel)                 (kCanNumberOfTxStatObjects)
# define CAN_HL_TX_DYN_ROM_STOPINDEX(channel)              (kCanNumberOfTxObjects)
# define CAN_HL_TX_DYN_RAM_STOPINDEX(channel)              (kCanNumberOfTxDynObjects)
/* # define CAN_HL_RX_STOPINDEX(channel)                      (kCanNumberOfRxObjects) */
# define CAN_HL_RX_BASIC_STOPINDEX(channel)                (kCanNumberOfRxBasicCANObjects)
# if defined( C_SEARCH_HASH ) 
#  define CAN_HL_RX_FULL_STOPINDEX(canHwChannel)           (kCanNumberOfRxFullCANObjects)
# else
#  define CAN_HL_RX_FULL_STOPINDEX(canHwChannel)           (kCanNumberOfRxBasicCANObjects+kCanNumberOfRxFullCANObjects)
# endif
# define CAN_HL_INIT_OBJ_STOPINDEX(channel)                (kCanNumberOfInitObjects)
# define CAN_HL_LOG_HW_TX_STOPINDEX(canHwChannel)          (kCanNumberOfUsedTxCANObjects)
# define CAN_HL_HW_TX_STOPINDEX(canHwChannel)              (kCanHwTxStartIndex     +kCanNumberOfUsedTxCANObjects)
# define CAN_HL_HW_RX_FULL_STOPINDEX(canHwChannel)         (kCanHwRxFullStartIndex +kCanNumberOfRxFullCANObjects)
# define CAN_HL_HW_RX_BASIC_STOPINDEX(canHwChannel)        (kCanHwRxBasicStartIndex+kCanNumberOfUsedRxBasicCANObjects)
# define CAN_HL_HW_UNUSED_STOPINDEX(canHwChannel)          (kCanHwUnusedStartIndex +kCanNumberOfUnusedObjects)

#else
#  define canHwChannel                                     channel   /*brackets are not allowed here due to compiler error with Renesas HEW compiler for SH2*/
#  define CAN_HL_HW_CHANNEL_STARTINDEX(channel)            (channel)
#  define CAN_HL_HW_CHANNEL_STOPINDEX(channel)             (channel)

#  define CAN_HL_HW_MSG_TRANSMIT_INDEX(canHwChannel)       (CanHwMsgTransmitIndex[(canHwChannel)])
#  define CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel)          (CanHwTxNormalIndex[(canHwChannel)])
/* Offset which has to be added to change the hardware Tx handle into a logical handle, which is unique over all channels */
/*        Tx-Hardware-Handle - CAN_HL_HW_TX_STARTINDEX(canHwChannel) + CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel) */
#  define CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)         (CanTxOffsetHwToLog[(canHwChannel)])

# define CAN_HL_TX_STARTINDEX(channel)                     (CanTxStartIndex[(channel)])
# define CAN_HL_TX_STAT_STARTINDEX(channel)                (CanTxStartIndex[(channel)])
# define CAN_HL_TX_DYN_ROM_STARTINDEX(channel)             (CanTxDynRomStartIndex[(channel)])
# define CAN_HL_TX_DYN_RAM_STARTINDEX(channel)             (CanTxDynRamStartIndex[(channel)])
/* # define CAN_HL_RX_STARTINDEX(channel)                     (CanRxStartIndex[(channel)]) */
/* index to access the ID tables - Basic index only for linear search */
# define CAN_HL_RX_BASIC_STARTINDEX(channel)               (CanRxBasicStartIndex[(channel)])      
# define CAN_HL_RX_FULL_STARTINDEX(canHwChannel)           (CanRxFullStartIndex[(canHwChannel)])
# define CAN_HL_INIT_OBJ_STARTINDEX(channel)               (CanInitObjectStartIndex[(channel)])      
# define CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel)         (CanLogHwTxStartIndex[(canHwChannel)])
#  define CAN_HL_HW_TX_STARTINDEX(canHwChannel)             (CanHwTxStartIndex[(canHwChannel)])   
#  define CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel)        (CanHwRxFullStartIndex[(canHwChannel)])
#  define CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)       (CanHwRxBasicStartIndex[(canHwChannel)]) 
#  define CAN_HL_HW_UNUSED_STARTINDEX(canHwChannel)         (CanHwUnusedStartIndex[(canHwChannel)])
                                                           
# define CAN_HL_TX_STOPINDEX(channel)                      (CanTxStartIndex[(channel) + 1]) 
# define CAN_HL_TX_STAT_STOPINDEX(channel)                 (CanTxDynRomStartIndex[(channel)])
# define CAN_HL_TX_DYN_ROM_STOPINDEX(channel)              (CanTxStartIndex[(channel) + 1]) 
# define CAN_HL_TX_DYN_RAM_STOPINDEX(channel)              (CanTxDynRamStartIndex[(channel) + 1])
/* # define CAN_HL_RX_STOPINDEX(channel)                      (CanRxStartIndex[(channel) + 1]) */
/* index to access the ID tables - Basic index only for linear search */
# define CAN_HL_RX_BASIC_STOPINDEX(channel)                (CanRxFullStartIndex[CAN_HL_HW_CHANNEL_STARTINDEX(channel)])
# define CAN_HL_INIT_OBJ_STOPINDEX(channel)                (CanInitObjectStartIndex[(channel) + 1])
# define CAN_HL_LOG_HW_TX_STOPINDEX(canHwChannel)          (CanLogHwTxStartIndex[(canHwChannel) +1])      
#  define CAN_HL_HW_TX_STOPINDEX(canHwChannel)              (CanHwTxStopIndex[(canHwChannel)])
#  define CAN_HL_HW_RX_FULL_STOPINDEX(canHwChannel)         (CanHwRxFullStopIndex[(canHwChannel)])
#  define CAN_HL_HW_RX_BASIC_STOPINDEX(canHwChannel)         (CanHwRxBasicStopIndex[(canHwChannel)])
#  define CAN_HL_HW_UNUSED_STOPINDEX(canHwChannel)         (CanHwUnusedStopIndex[(canHwChannel)])

#endif


#if defined( C_SINGLE_RECEIVE_CHANNEL )

# define CANRANGE0ACCMASK(i)                               C_RANGE0_ACC_MASK
# define CANRANGE0ACCCODE(i)                               C_RANGE0_ACC_CODE
# define CANRANGE1ACCMASK(i)                               C_RANGE1_ACC_MASK
# define CANRANGE1ACCCODE(i)                               C_RANGE1_ACC_CODE
# define CANRANGE2ACCMASK(i)                               C_RANGE2_ACC_MASK
# define CANRANGE2ACCCODE(i)                               C_RANGE2_ACC_CODE
# define CANRANGE3ACCMASK(i)                               C_RANGE3_ACC_MASK
# define CANRANGE3ACCCODE(i)                               C_RANGE3_ACC_CODE

# define APPL_CAN_MSG_RECEIVED( i )                        (APPL_CAN_MSGRECEIVED( i ))

# define APPLCANRANGE0PRECOPY( i )                         (ApplCanRange0Precopy( i ))   
# define APPLCANRANGE1PRECOPY( i )                         (ApplCanRange1Precopy( i ))   
# define APPLCANRANGE2PRECOPY( i )                         (ApplCanRange2Precopy( i ))   
# define APPLCANRANGE3PRECOPY( i )                         (ApplCanRange3Precopy( i ))   

# define APPL_CAN_BUSOFF( i )                              (ApplCanBusOff())
# define APPL_CAN_WAKEUP( i )                              (ApplCanWakeUp())

# if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
#  define APPLCANCANCELNOTIFICATION( i, j )                (APPL_CAN_CANCELNOTIFICATION( j ))
# else
#  define APPLCANCANCELNOTIFICATION( i, j )
# endif
# if defined( C_ENABLE_CAN_MSG_TRANSMIT_CANCEL_NOTIFICATION )
#  define APPLCANMSGCANCELNOTIFICATION( i )                (APPL_CAN_MSGCANCELNOTIFICATION())
# else
#  define APPLCANMSGCANCELNOTIFICATION( i )
# endif

# define CAN_RX_INDEX_TBL(channel,id)                      (CanRxIndexTbl[id])

#else

# define CANRANGE0ACCMASK(i)                               (CanChannelObject[i].RangeMask[0])
# define CANRANGE0ACCCODE(i)                               (CanChannelObject[i].RangeCode[0])
# define CANRANGE1ACCMASK(i)                               (CanChannelObject[i].RangeMask[1])
# define CANRANGE1ACCCODE(i)                               (CanChannelObject[i].RangeCode[1])
# define CANRANGE2ACCMASK(i)                               (CanChannelObject[i].RangeMask[2])
# define CANRANGE2ACCCODE(i)                               (CanChannelObject[i].RangeCode[2])
# define CANRANGE3ACCMASK(i)                               (CanChannelObject[i].RangeMask[3])
# define CANRANGE3ACCCODE(i)                               (CanChannelObject[i].RangeCode[3])

/* generated id type of the range */
# define CANRANGE0IDTYPE(i)                                (CanChannelObject[i].RangeIdType[0])
# define CANRANGE1IDTYPE(i)                                (CanChannelObject[i].RangeIdType[1])
# define CANRANGE2IDTYPE(i)                                (CanChannelObject[i].RangeIdType[2])
# define CANRANGE3IDTYPE(i)                                (CanChannelObject[i].RangeIdType[3])

# define APPL_CAN_MSG_RECEIVED( i )                        (CanChannelObject[(i)->Channel].ApplCanMsgReceivedFct(i))

# define APPLCANRANGE0PRECOPY( i )                         (CanChannelObject[(i)->Channel].ApplCanRangeFct[0](i))
# define APPLCANRANGE1PRECOPY( i )                         (CanChannelObject[(i)->Channel].ApplCanRangeFct[1](i))   
# define APPLCANRANGE2PRECOPY( i )                         (CanChannelObject[(i)->Channel].ApplCanRangeFct[2](i))   
# define APPLCANRANGE3PRECOPY( i )                         (CanChannelObject[(i)->Channel].ApplCanRangeFct[3](i))   

# define APPL_CAN_BUSOFF( i )                              (CanChannelObject[i].ApplCanBusOffFct(i))
# define APPL_CAN_WAKEUP( i )                              (CanChannelObject[i].ApplCanWakeUpFct(i))

# if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
#  define APPLCANCANCELNOTIFICATION( i, j )                (CanChannelObject[i].ApplCanCancelNotificationFct( j ))
# else
#  define APPLCANCANCELNOTIFICATION( i, j )
# endif

# if defined( C_ENABLE_CAN_MSG_TRANSMIT_CANCEL_NOTIFICATION )
#  define APPLCANMSGCANCELNOTIFICATION( i )                (CanChannelObject[i].ApplCanMsgTransmitCancelNotifyFct( i ))
# else
#  define APPLCANMSGCANCELNOTIFICATION( i )
# endif

# define CAN_RX_INDEX_TBL(channel,id)                      (CanRxIndexTbl[channel][id])

#endif


#if defined ( C_ENABLE_CAN_CAN_INTERRUPT_CONTROL )
# define CAN_CAN_INTERRUPT_DISABLE(i)                        (CanCanInterruptDisable(i))
# define CAN_CAN_INTERRUPT_RESTORE(i)                        (CanCanInterruptRestore(i))
#else
# define CAN_CAN_INTERRUPT_DISABLE(i)
# define CAN_CAN_INTERRUPT_RESTORE(i)
#endif


#if defined( C_ENABLE_INDIVIDUAL_POLLING )
/* define first index to array CanHwObjIndivPolling[][] */
#  define CAN_HWOBJINDIVPOLLING_INDEX0                     (canHwChannel)
#endif


/* mask for range enable status */
#define kCanRange0                                         ((vuint16)1)
#define kCanRange1                                         ((vuint16)2)
#define kCanRange2                                         ((vuint16)4)
#define kCanRange3                                         ((vuint16)8)


/* Assertions ----------------------------------------------------------------*/
/*lint -function(exit,ApplCanFatalError)*/

/*lint -emacro( (506), assertUser) */
#if defined( C_ENABLE_USER_CHECK )
# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define assertUser(p,c,e)                                if (!(p))   {ApplCanFatalError(e);}                    /* PRQA S 3412 */
# else
#  define assertUser(p,c,e)                                if (!(p))   {ApplCanFatalError((c),(e));}              /* PRQA S 3412 */
# endif
#else
# define assertUser(p,c,e)
#endif

/*lint -emacro( (506), assertGen) */
#if defined( C_ENABLE_GEN_CHECK )
# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define assertGen(p,c,e)                                 if (!(p))   {ApplCanFatalError(e);}                    /* PRQA S 3412 */
# else
#  define assertGen(p,c,e)                                 if (!(p))   {ApplCanFatalError((c),(e));}              /* PRQA S 3412 */
# endif
#else
# define assertGen(p,c,e)
#endif

/*lint -emacro( (506), assertHardware) */
#if defined( C_ENABLE_HARDWARE_CHECK )
# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define assertHardware(p,c,e)                            if (!(p))   {ApplCanFatalError(e);}                    /* PRQA S 3412 */
# else
#  define assertHardware(p,c,e)                            if (!(p))   {ApplCanFatalError((c),(e));}              /* PRQA S 3412 */
# endif
#else
# define assertHardware(p,c,e)
#endif

/*lint -emacro( (506), assertInternal) */
#if defined( C_ENABLE_INTERNAL_CHECK )
# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define assertInternal(p,c,e)                            if (!(p))   {ApplCanFatalError(e);}                   /* PRQA S 3412 */
# else
#  define assertInternal(p,c,e)                            if (!(p))   {ApplCanFatalError((c),(e));}             /* PRQA S 3412 */
# endif
#else
# define assertInternal(p,c,e)
#endif

#if defined( C_ENABLE_TRANSMIT_QUEUE )
/* KB begin CanHL_TxQueueMacros */
#if defined( C_CPUTYPE_32BIT )
# define kCanTxQueueShift     5
#endif

#if defined( C_CPUTYPE_16BIT )
# define kCanTxQueueShift     4
#endif

#if defined( C_CPUTYPE_8BIT )
# define kCanTxQueueShift     3
#endif

/* mask used to get the flag index from the handle */
# define kCanTxQueueMask      (((vuint8)1 << kCanTxQueueShift) - (vuint8)1)


#if defined( C_SINGLE_RECEIVE_CHANNEL )
# define CAN_HL_TXQUEUE_PADBITS(channel)             ((CanTransmitHandle)0)
# define CAN_HL_TXQUEUE_STARTINDEX(channel)          ((CanSignedTxHandle)0)
# define CAN_HL_TXQUEUE_STOPINDEX(channel)           ((CanSignedTxHandle)kCanTxQueueSize)
#else
# define CAN_HL_TXQUEUE_PADBITS(channel)             ((CanTransmitHandle)CanTxQueuePadBits[(channel)])
# define CAN_HL_TXQUEUE_STARTINDEX(channel)          (CanTxQueueStartIndex[(channel)])
# define CAN_HL_TXQUEUE_STOPINDEX(channel)           (CanTxQueueStartIndex[(channel) + (CanChannelHandle)1])
#endif


/* KB end CanHL_TxQueueMacros */
#endif
/* KB begin CanLL_Macros */

# if defined (C_SINGLE_RECEIVE_CHANNEL )

#  define CAN_BASIS_ADR(channel)                   (CAN_CellAddrMapPtr) kCanBasisAdr
#  define CAN_NUMBER_OF_MSG(channel)               kCanNumberOfMsgObj
#  define CAN_LL_STATUS(channel)                   canllStatus[0]
#  define STATUS_STOP_MODE(channel)                status_stop[0]
#  define STATUS_BUS_OFF(channel)                  status_busoff[0]
#  define STATUS_SLEEP(channel)                    status_sleep[0]
#  define NORMAL_MODE(channel)                     normal_mode[0]
#  define TX_SEND_FLAG(channel,k)                  txsendflag[k]
#  define RX_MSGOBJ(channel)                       rxMsgObj
#  define RX_MSGOBJ_ID_LOW(channel)                rxMsgObj.Id[0]
#  define RX_MSGOBJ_ID_HIGH(channel)               rxMsgObj.Id[1]
#  define RX_MSGOBJ_DLC(channel)                   rxMsgObj.Dlc
#  define RX_MSGOBJ_DATA(channel)                  rxMsgObj.Data.ucData[0]
#  define RX_MSGOBJ_MSGCNTRL(channel)              rxMsgObj.MessageCntrl
#  define LAST_RXOBJECT(channel)                   kCanNumberOfMsgObj

#  ifdef C_COMP_TI_TMS470_DCAN
#   define VIM_MASK(channel)                       (V_DEF_P2VAR(V_NONE ,vuint32, VAR_NOINIT, INT_CTRL)) kCanVimSetReg
#   define VIM_CLRMASK(channel)                    (V_DEF_P2VAR(V_NONE ,vuint32, VAR_NOINIT, INT_CTRL)) kCanVimClrReg
#   define VIM_SETMASK(channel)                    (V_DEF_P2VAR(V_NONE ,vuint32, VAR_NOINIT, INT_CTRL)) kCanVimSetReg
#   define INTERRUPT_SRC(channel)                  kCanInterruptSrc
#  endif



# else

#  define CAN_BASIS_ADR(channel)                   (CAN_CellAddrMapPtr) CanBasisAdr[channel]
#  define CAN_NUMBER_OF_MSG(channel)               CanNumberOfMsgObj[channel]
#  define CAN_LL_STATUS(channel)                   canllStatus[channel]
#  define STATUS_STOP_MODE(channel)                status_stop[channel]
#  define STATUS_BUS_OFF(channel)                  status_busoff[channel]
#  define STATUS_SLEEP(channel)                    status_sleep[channel]
#  define NORMAL_MODE(channel)                     normal_mode[channel]
#  define TX_SEND_FLAG(channel,k)                  txsendflag[k][channel]
#  define RX_MSGOBJ(channel)                       rxMsgObj[channel]
#  define RX_MSGOBJ_ID_LOW(channel)                rxMsgObj[channel].Id[0]
#  define RX_MSGOBJ_ID_HIGH(channel)               rxMsgObj[channel].Id[1]
#  define RX_MSGOBJ_DLC(channel)                   rxMsgObj[channel].Dlc
#  define RX_MSGOBJ_DATA(channel)                  rxMsgObj[channel].Data.ucData[0]
#  define RX_MSGOBJ_MSGCNTRL(channel)              rxMsgObj[channel].MessageCntrl
#  define LAST_RXOBJECT(channel)                   CanNumberOfMsgObj[channel]

#  ifdef C_COMP_TI_TMS470_DCAN
#   define VIM_MASK(channel)                       (V_DEF_P2VAR(V_NONE ,vuint32, VAR_NOINIT, INT_CTRL)) vimSetReg[channel]
#   define VIM_CLRMASK(channel)                    (V_DEF_P2VAR(V_NONE ,vuint32, VAR_NOINIT, INT_CTRL)) vimClrReg[channel]
#   define VIM_SETMASK(channel)                    (V_DEF_P2VAR(V_NONE ,vuint32, VAR_NOINIT, INT_CTRL)) vimSetReg[channel]
#   define INTERRUPT_SRC(channel)                  interruptSrc[channel]
#  endif



# endif


#define TX_MSGOBJ_ID_LOW(txlogobj)                 txMsgObj[txlogobj].Id[0]
#define TX_MSGOBJ_ID_HIGH(txlogobj)                txMsgObj[txlogobj].Id[1]
#define TX_MSGOBJ_DLC(txlogobj)                    txMsgObj[txlogobj].Dlc
#define TX_MSGOBJ_UCDATA(txlogobj)                 txMsgObj[txlogobj].Data.ucData



#if defined(C_ENABLE_HW_LOOP_TIMER)
#  define CanDeclareTimerResult       vuint8 canTimerResult
#  define APPLCANTIMERSTART(x)        ApplCanTimerStart(CAN_CHANNEL_CANPARA_FIRST (x))
#  define CANTIMERRESULT_UPDATE(x)    canTimerResult = ApplCanTimerLoop(CAN_CHANNEL_CANPARA_FIRST (x))
#  define WHILE_CONDITON(x)           while((x) && (canTimerResult != 0))
#  define APPLCANTIMEREND(x)          ApplCanTimerEnd(CAN_CHANNEL_CANPARA_FIRST (x))
#else
# define CanDeclareTimerResult
# define APPLCANTIMERSTART(x)
# define CANTIMERRESULT_UPDATE(x)   
# define WHILE_CONDITON(x)            while(x)
# define APPLCANTIMEREND(x)
#endif

#if !defined (C_DISABLE_DCAN_ISSUE22_WORKAROUND) && !defined (C_ENABLE_DCAN_ISSUE22_WORKAROUND)
# define C_ENABLE_DCAN_ISSUE22_WORKAROUND
#endif

#ifdef C_COMP_TI_TMS470_DCAN
# define CanLL_CanInterruptDisable(canHwChannel, localInterruptOldFlagPtr)                 \
{                                                                                          \
  *localInterruptOldFlagPtr = *VIM_MASK(canHwChannel) & INTERRUPT_SRC(canHwChannel);       \
  *VIM_CLRMASK(canHwChannel) = INTERRUPT_SRC(canHwChannel);                                \
}
#endif



#ifdef C_COMP_TI_TMS470_DCAN
# define CanLL_CanInterruptRestore(canHwChannel, localInterruptOldFlag)                    \
{                                                                                          \
  if ((localInterruptOldFlag & INTERRUPT_SRC(canHwChannel)) != 0 )                         \
  {                                                                                        \
    *VIM_SETMASK(canHwChannel) = INTERRUPT_SRC(canHwChannel);                              \
  }                                                                                        \
}
#endif



/* CanLL_TxIsHWObjFree() is implemented as function below in the section reserved for functions */

#if defined( C_ENABLE_SLEEP_WAKEUP )
# define CanLL_HwIsSleep( CAN_HW_CHANNEL_CANPARA_ONLY)  (STATUS_SLEEP(channel) == kCanTrue)
#else
# define CanLL_HwIsSleep( CAN_HW_CHANNEL_CANPARA_ONLY)  (kCanFalse)
#endif


#define CanLL_HwIsStop( CAN_HW_CHANNEL_CANPARA_ONLY ) (STATUS_STOP_MODE(channel))

#define CanLL_HwIsBusOff( CAN_HW_CHANNEL_CANPARA_ONLY ) (CAN_LL_STATUS(channel) & kErrBusOff)

#if defined( C_ENABLE_EXTENDED_STATUS )
# define CanLL_HwIsPassive( CAN_HW_CHANNEL_CANPARA_ONLY )              \
    ( ((CanRxActualErrorCounter(CAN_HW_CHANNEL_CANPARA_ONLY) > 127) || \
       (CanTxActualErrorCounter(CAN_HW_CHANNEL_CANPARA_ONLY) > 127)) )

# define CanLL_HwIsWarning( CAN_HW_CHANNEL_CANPARA_ONLY )             \
    ( ((CanRxActualErrorCounter(CAN_HW_CHANNEL_CANPARA_ONLY) > 95) || \
       (CanTxActualErrorCounter(CAN_HW_CHANNEL_CANPARA_ONLY) > 95)))
#endif /* C_ENABLE_EXTENDED_STATUS */
/* KB end CanLL_Macros */

/***************************************************************************/
/* Defines / data types / structs / unions                                 */
/***************************************************************************/

#if defined( C_ENABLE_TRANSMIT_QUEUE )
/* KB begin CanHL_TxQueueDefinesDataTypesStructsUnions */
/* KB end CanHL_TxQueueDefinesDataTypesStructsUnions */
#endif
/* KB begin CanLL_DefinesDataTypesStructsUnions */
/* Define CAN Chip hardware; segment must be located in locator file    */
/* register layout of the can chip                                      */
/* Structure describing CAN receive buffer. */

#if defined(C_CPUTYPE_BIGENDIAN)
typedef volatile struct
{
  vuint16      ComMask;              /* Command Mask register      */
  vuint16      ComRequest;           /* Command Request register   */
  vuint16      Mask2;                /* Mask register 2            */
  vuint16      Mask1;                /* Mask register 1            */
  vuint16      ArbitrFld2;           /* Arbitration 2              */
  vuint16      ArbitrFld1;           /* Arbitration 1              */
  vuint16      notused10;            /* not used                   */   
  vuint16      MessageCntrl;         /* Message Control Register   */
  can_data     Data;                 /* CAN Data Register          */
  vuint16      notused11[4];         /* not used                   */   
   
} CanMsgObj;


typedef volatile struct
{
  vuint32      CntrlReg;             /* CAN Control Register            Baseaddress + 0x00  */

  vuint16      notused1;
  vuint16      StatReg;              /* CAN Status Register             Baseaddress + 0x04  */

  vuint16      notused2;         
  vuint16      ErrorCount;           /* CAN Errorcounter Register       Baseaddress + 0x08  */

  vuint16      BRP_Reg;              /* Baud Rate Prescaler Register    Baseaddress + 0x0E  */
  vuint16      BitTiming;            /* CAN Bittiming Register          Baseaddress + 0x0C  */

  vuint16      InterruptReg1;        /* CAN Interrupt Register          Baseaddress + 0x12  */
  vuint16      InterruptReg;         /* CAN Interrupt Register1         Baseaddress + 0x10  */

  vuint16      notused3;
  vuint16      TestReg;              /* Test Register                   Baseaddress + 0x14  */

  vuint16      notused4[3];         
  vuint16      ParityErrorCode;      /* ParityErrorCode                 Baseaddress + 0x1C  */

  vuint16      notused5[48];

  vuint16      AutoBusOnTime2;       /* BusOnTime Regsiter2             Baseaddress + 0x82  */
  vuint16      AutoBusOnTime1;       /* BusOnTime Regsiter1             Baseaddress + 0x80  */

  vuint16      notused6;         
  vuint16      TransRequestX;        /* Transmission request Register   Baseaddress + 0x84  */

  vuint32      TransRequest[4];      /* Transmission request Register   Baseaddress + 0x88  */

  vuint16      notused7;         
  vuint16      NewDataX;             /* New Data Register               Baseaddress + 0x98  */

  vuint32      NewData[4];           /* New Data Register               Baseaddress + 0x9C  */

  vuint16      notused8;         
  vuint16      InterrPendingX;       /* InterrPending Register          Baseaddress + 0xAC  */

  vuint32      InterrPending[4];     /* InterrPending Register          Baseaddress + 0xB0  */

  vuint16      notused9;         
  vuint16      MessageValidX;        /* MessageValid Register           Baseaddress + 0xC0  */

  vuint32      MessageValid[4];      /* MessageValid Register           Baseaddress + 0xC4  */

  vuint32      notused10;

  vuint16      IntPndMux[8];         /* NIntPndMux Register             Baseaddress + 0xD8  */
  vuint16      notused11[12];           
 
  CanMsgObj    sMsgObj[3];           /* Message Interface Register      Baseaddress + 0x100 */
  vuint16      notused12[50];           

  vuint32      can_IO_ctrlTx;        /*  can_IO_ctrlTx Register         Baseaddress + 0x1E0 */
  vuint32      can_IO_ctrlRx;        /*  can_IO_ctrlRx Register         Baseaddress + 0x1E0 */
    
} CAN_CellAddrMap;
V_DEF_P2SFR_CAN_TYPE(V_NONE, CAN_CellAddrMap) CAN_CellAddrMapPtr;
#endif


/* KB end CanLL_DefinesDataTypesStructsUnions */

/****************************************************************************/
/* Constants                                                                */
/****************************************************************************/

#if defined( C_ENABLE_TRANSMIT_QUEUE )
/* KB begin CanHl_TxQueueConstants */
/* ROM CATEGORY 1 START*/
/* lookup table for setting the flags in the queue */
V_MEMROM0 static V_MEMROM1 tCanQueueElementType V_MEMROM2 CanShiftLookUp[1 << kCanTxQueueShift] = 
{
#if defined( C_CPUTYPE_32BIT ) || defined( C_CPUTYPE_16BIT ) || defined( C_CPUTYPE_8BIT )
  (tCanQueueElementType)0x00000001, (tCanQueueElementType)0x00000002, (tCanQueueElementType)0x00000004, (tCanQueueElementType)0x00000008, 
  (tCanQueueElementType)0x00000010, (tCanQueueElementType)0x00000020, (tCanQueueElementType)0x00000040, (tCanQueueElementType)0x00000080
#endif

#if defined( C_CPUTYPE_32BIT ) || defined( C_CPUTYPE_16BIT )
 ,(tCanQueueElementType)0x00000100, (tCanQueueElementType)0x00000200, (tCanQueueElementType)0x00000400, (tCanQueueElementType)0x00000800, 
  (tCanQueueElementType)0x00001000, (tCanQueueElementType)0x00002000, (tCanQueueElementType)0x00004000, (tCanQueueElementType)0x00008000
#endif

#if defined( C_CPUTYPE_32BIT )
 ,(tCanQueueElementType)0x00010000, (tCanQueueElementType)0x00020000, (tCanQueueElementType)0x00040000, (tCanQueueElementType)0x00080000, 
  (tCanQueueElementType)0x00100000, (tCanQueueElementType)0x00200000, (tCanQueueElementType)0x00400000, (tCanQueueElementType)0x00800000,
  (tCanQueueElementType)0x01000000, (tCanQueueElementType)0x02000000, (tCanQueueElementType)0x04000000, (tCanQueueElementType)0x08000000, 
  (tCanQueueElementType)0x10000000, (tCanQueueElementType)0x20000000, (tCanQueueElementType)0x40000000, (tCanQueueElementType)0x80000000
#endif
};

/* returns the highest pending flag from the lower nibble */
V_MEMROM0 static V_MEMROM1 vsint8 V_MEMROM2 CanGetHighestFlagFromNibble[16] =        /* PRQA S 3218 */ /* Misra rule 8.7: only accessed in one function. - depends on configuration */
{    
  (vsint8)-1,                /* (vsint8)0xFF - changed due to misra ; cast due to R32C */
  0x00,
  0x01, 0x01,
  0x02, 0x02, 0x02, 0x02,
  0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
};
/* ROM CATEGORY 1 END*/
/* KB end CanHl_TxQueueConstants */
#endif
/* KB begin CanLL_Constants */
/* Global constants with CAN driver main and subversion */
/* ROM CATEGORY 4 START */
V_DEF_CONST(V_NONE, vuint8, CONST) kCanMainVersion   = (vuint8)(( DRVCAN_TMS470DCANHLL_VERSION ) >> 8 );   /* lint !e572 !e778 */
V_DEF_CONST(V_NONE, vuint8, CONST) kCanSubVersion    = (vuint8)(( DRVCAN_TMS470DCANHLL_VERSION ) & 0x00FF );
V_DEF_CONST(V_NONE, vuint8, CONST) kCanBugFixVersion = (vuint8)(( DRVCAN_TMS470DCANHLL_RELEASE_VERSION) );
/* ROM CATEGORY 4 END */
/* KB end CanLL_Constants */

/***************************************************************************/
/* CAN-Hardware Data Definitions                                            */
/***************************************************************************/

/* KB begin CanLL_CanHardwareDataDefinitions */
/* KB end CanLL_CanHardwareDataDefinitions */

/***************************************************************************/
/* external declarations                                                    */
/***************************************************************************/

#if !defined( CANDRV_SET_CODE_TEST_POINT )
# define CANDRV_SET_CODE_TEST_POINT(x)
#else
extern vuint8 tscCTKTestPointState[CTK_MAX_TEST_POINT];       /* PRQA S 3447 */
#endif
/* KB begin CanLL_ExternalDeclarations */
/* KB end CanLL_ExternalDeclarations */

/***************************************************************************/
/* global data definitions                                                 */
/***************************************************************************/

/* RAM CATEGORY 1 START*/
volatile CanReceiveHandle canRxHandle[kCanNumberOfChannels];        /* PRQA S 1514 */
/* RAM CATEGORY 1 END*/

/* RAM CATEGORY 3 START*/
#if defined( C_ENABLE_CONFIRMATION_FCT ) && \
    defined( C_ENABLE_DYN_TX_OBJECTS )   && \
    defined( C_ENABLE_TRANSMIT_QUEUE )
CanTransmitHandle          confirmHandle[kCanNumberOfChannels];
#endif
/* RAM CATEGORY 3 END*/

/* RAM CATEGORY 1 START*/
#if defined( C_ENABLE_CONFIRMATION_FLAG )
/* Msg(4:0750) A union type has been used. MISRA Rules 110 - no change */
V_MEMRAM0 volatile V_MEMRAM1_NEAR union CanConfirmationBits V_MEMRAM2_NEAR CanConfirmationFlags;       /* PRQA S 0759 */
#endif

#if defined( C_ENABLE_INDICATION_FLAG )
/* Msg(4:0750) A union type has been used. MISRA Rules 110 - no change */
V_MEMRAM0 volatile V_MEMRAM1_NEAR union CanIndicationBits   V_MEMRAM2_NEAR CanIndicationFlags;         /* PRQA S 0759 */
#endif
/* RAM CATEGORY 1 END*/

/* RAM CATEGORY 1 START*/
#if defined( C_ENABLE_VARIABLE_RX_DATALEN )
/* ##RI1.4 - 3.31: Dynamic Receive DLC */
volatile vuint8 canVariableRxDataLen[kCanNumberOfRxObjects];
#endif
/* RAM CATEGORY 1 END*/

/* RAM CATEGORY 1 START*/
CanChipDataPtr canRDSRxPtr[kCanNumberOfChannels];                  /* PRQA S 1514 */
/* RAM CATEGORY 1 END*/
/* RAM CATEGORY 1 START*/
CanChipDataPtr canRDSTxPtr[kCanNumberOfUsedTxCANObjects];          /* PRQA S 1514 */
/* RAM CATEGORY 1 END*/

/* KB begin CanLL_GlobalDataDefinition */

/* RAM CATEGORY 1 START*/
tTxMsgObj   txMsgObj[kCanNumberOfUsedTxCANObjects];
# if defined (C_SINGLE_RECEIVE_CHANNEL )
tRxMsgObj   rxMsgObj;
# else
tRxMsgObj   rxMsgObj[kCanNumberOfChannels];
# endif
/* RAM CATEGORY 1 END*/

/* KB end CanLL_GlobalDataDefinition */

/***************************************************************************/
/* local data definitions                                                  */
/***************************************************************************/

/* support for CAN driver features : */
/* RAM CATEGORY 1 START*/
static volatile CanTransmitHandle canHandleCurTxObj[kCanNumberOfUsedTxCANObjects];
/* RAM CATEGORY 1 END*/

/* RAM CATEGORY 2 START*/
#if defined( C_ENABLE_ECU_SWITCH_PASS )
static vuint8 canPassive[kCanNumberOfChannels];
#endif
/* RAM CATEGORY 2 END*/

/* RAM CATEGORY 2 START*/
#if defined( C_ENABLE_CAN_RAM_CHECK )
static vuint8 canComStatus[kCanNumberOfChannels]; /* stores the decision of the App after the last CAN RAM check */
#endif

#if defined( C_ENABLE_DYN_TX_OBJECTS )
static volatile vuint8 canTxDynObjReservedFlag[kCanNumberOfTxDynObjects];

# if defined( C_ENABLE_DYN_TX_ID )
static tCanTxId0 canDynTxId0[kCanNumberOfTxDynObjects];
#  if (kCanNumberOfUsedCanTxIdTables > 1)
static tCanTxId1 canDynTxId1[kCanNumberOfTxDynObjects];
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 2)
static tCanTxId2 canDynTxId2[kCanNumberOfTxDynObjects];
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 3)
static tCanTxId3 canDynTxId3[kCanNumberOfTxDynObjects];
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 4)
static tCanTxId4 canDynTxId4[kCanNumberOfTxDynObjects];
#  endif
#  if defined( C_ENABLE_MIXED_ID )
#   if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#   else
static tCanIdType                 canDynTxIdType[kCanNumberOfTxDynObjects];
#   endif
#  endif
# endif

# if defined( C_ENABLE_DYN_TX_DLC )
static vuint8                   canDynTxDLC[kCanNumberOfTxDynObjects];
# endif
# if defined( C_ENABLE_DYN_TX_DATAPTR )
static vuint8*                  canDynTxDataPtr[kCanNumberOfTxDynObjects];
# endif
# if defined( C_ENABLE_CONFIRMATION_FCT )
# endif 
#endif /* C_ENABLED_DYN_TX_OBJECTS */


#if defined( C_ENABLE_TX_MASK_EXT_ID )
static tCanTxId0 canTxMask0[kCanNumberOfChannels];
# if (kCanNumberOfUsedCanTxIdTables > 1)
static tCanTxId1 canTxMask1[kCanNumberOfChannels];
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
static tCanTxId2 canTxMask2[kCanNumberOfChannels];
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
static tCanTxId3 canTxMask3[kCanNumberOfChannels];
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
static tCanTxId4 canTxMask4[kCanNumberOfChannels];
# endif
#endif

#if defined( C_ENABLE_VARIABLE_DLC )
static vuint8 canTxDLC_RAM[kCanNumberOfTxObjects];
#endif

#if defined( C_HL_ENABLE_COPROCESSOR_SUPPORT )
#else
static volatile vuint8 canStatus[kCanNumberOfChannels];

# if defined( C_ENABLE_PART_OFFLINE )
static vuint8 canTxPartOffline[kCanNumberOfChannels];
# endif
#endif
/* RAM CATEGORY 2 END*/

/* RAM CATEGORY 1 START*/
static vsintx          canCanInterruptCounter[kCanNumberOfChannels];
#if defined( C_HL_ENABLE_CAN_IRQ_DISABLE )
static tCanLLCanIntOld canCanInterruptOldStatus[kCanNumberOfHwChannels];
#endif
/* RAM CATEGORY 1 END*/

#if defined( C_HL_ENABLE_LAST_INIT_OBJ )
/* RAM CATEGORY 4 START*/
static CanInitHandle lastInitObject[kCanNumberOfChannels];
/* RAM CATEGORY 4 END*/
#endif
#if defined( C_ENABLE_TX_POLLING )          || \
    defined( C_ENABLE_RX_FULLCAN_POLLING )  || \
    defined( C_ENABLE_RX_BASICCAN_POLLING ) || \
    defined( C_ENABLE_ERROR_POLLING )       || \
    defined( C_ENABLE_WAKEUP_POLLING )      || \
    (defined( C_HL_ENABLE_CANCEL_IN_HW_TASK ) && defined( C_ENABLE_CANCEL_IN_HW ))
/* RAM CATEGORY 2 START*/
static vuint8 canPollingTaskActive[kCanNumberOfChannels];
/* RAM CATEGORY 2 END*/
#endif

/* RAM CATEGORY 1 START*/
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )  || \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
static tCanRxInfoStruct        canRxInfoStruct[kCanNumberOfChannels];
#endif
#if defined( C_ENABLE_CAN_TX_CONF_FCT )
/* ##RI-1.10 Common Callbackfunction in TxInterrupt */
static tCanTxConfInfoStruct    txInfoStructConf[kCanNumberOfChannels];
#endif

#if defined( C_ENABLE_COND_RECEIVE_FCT )
static volatile vuint8 canMsgCondRecState[kCanNumberOfChannels];
#endif

#if defined( C_ENABLE_RX_QUEUE )
static tCanRxQueue canRxQueue;         /* the rx queue (buffer and queue variables) */
#endif
/* RAM CATEGORY 1 END*/

#if defined( C_ENABLE_TRANSMIT_QUEUE )
/* KB begin CanHl_TxQueueLocalDataDefinition */
/* RAM CATEGORY 1 START*/
static volatile tCanQueueElementType canTxQueueFlags[kCanTxQueueSize];
/* RAM CATEGORY 1 END*/
/* KB end CanHl_TxQueueLocalDataDefinition */
#endif
/* KB begin CanLL_LocalDataDefinition */
/* RAM CATEGORY 1 START*/

# if defined( C_ENABLE_SLEEP_WAKEUP )
static vuint8  status_sleep[kCanNumberOfChannels];
# endif
static vuint8  status_stop[kCanNumberOfChannels];
static vuint16 status_busoff[kCanNumberOfChannels];
static vuint16 normal_mode[kCanNumberOfChannels];  
static vuint32 canllStatus[kCanNumberOfChannels];

# if defined (C_SINGLE_RECEIVE_CHANNEL )
static vuint32  txsendflag[4];
# else
static vuint32  txsendflag[4][kCanNumberOfChannels];
# endif

/* RAM CATEGORY 1 END*/
/* KB end CanLL_LocalDataDefinition */

/***************************************************************************/
/*  local prototypes                                                       */
/***************************************************************************/
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )  || \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
# if defined( C_ENABLE_RX_QUEUE )
/* CODE CATEGORY 1 START*/
static vuint8 CanHL_ReceivedRxHandleQueue(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 1 END*/
# endif
/* CODE CATEGORY 1 START*/
# if ( kCanNumberOfRxObjects > 0 )
#  if defined( C_ENABLE_RX_QUEUE )
static vuint8 CanHL_ReceivedRxHandle( CAN_CHANNEL_CANTYPE_FIRST tCanRxInfoStruct *pCanRxInfoStruct );
#  else
static vuint8 CanHL_ReceivedRxHandle( CAN_CHANNEL_CANTYPE_ONLY );
#  endif
# endif /* ( kCanNumberOfRxObjects > 0 )*/ 
/* CODE CATEGORY 1 END*/
# if defined( C_ENABLE_INDICATION_FLAG ) || \
     defined( C_ENABLE_INDICATION_FCT )
/* CODE CATEGORY 1 START*/
static void CanHL_IndRxHandle( CanReceiveHandle rxHandle );
/* CODE CATEGORY 1 END*/
# endif
#endif
#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/* CODE CATEGORY 1 START*/
static void CanBasicCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle);  
/* CODE CATEGORY 1 END*/
#endif
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/* CODE CATEGORY 1 START*/
static void CanFullCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle);
/* CODE CATEGORY 1 END*/
#endif

/* CODE CATEGORY 1 START*/
static void CanHL_TxConfirmation(CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txObjHandle);
/* CODE CATEGORY 1 END*/
# if defined( C_ENABLE_CAN_TRANSMIT )
/* CODE CATEGORY 1 START*/
static vuint8 CanCopyDataAndStartTransmission(CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txObjHandle, CanTransmitHandle txHandle)  C_API_3;   /*lint !e14 !e31*/
/* CODE CATEGORY 1 END*/
# endif   /* C_ENABLE_CAN_TRANSMIT */

#if defined( C_ENABLE_TRANSMIT_QUEUE )
/* CODE CATEGORY 4 START*/
static void CanDelQueuedObj( CAN_CHANNEL_CANTYPE_ONLY ) C_API_3;
/* CODE CATEGORY 4 END*/
# if defined( C_ENABLE_TX_POLLING ) || \
     (defined( C_HL_ENABLE_CANCEL_IN_HW_TASK )  && defined( C_ENABLE_CANCEL_IN_HW ))
/* CODE CATEGORY 2 START*/
static void CanHl_RestartTxQueue( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 2 END*/
# endif
#endif 

/* CODE CATEGORY 2 START*/
static void CanHL_ErrorHandling( CAN_HW_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 2 END*/

#if defined( C_ENABLE_VARIABLE_RX_DATALEN )
/* CODE CATEGORY 1 START*/
static void CanSetVariableRxDatalen ( CanReceiveHandle rxHandle, vuint8 dataLen );
/* CODE CATEGORY 1 END*/
#endif


/* KB begin CanLL_LocalPrototypes */
#if defined( C_ENABLE_SLEEP_WAKEUP )
/* CODE CATEGORY 4 START */
V_DEF_FUNC(STATIC, void, CODE) CanLL_WakeUpHandling(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */
#endif
#if defined( C_ENABLE_CAN_RAM_CHECK )
/* CODE CATEGORY 4 START */
V_DEF_FUNC(STATIC, vuint8, CODE) CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle hwObjHandle);
/* CODE CATEGORY 4 END */
#endif

/* CODE CATEGORY 1 START */
# if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
      (defined( C_ENABLE_RX_FULLCAN_OBJECTS )  && !defined( C_ENABLE_RX_FULLCAN_POLLING  )) || \
       !defined( C_ENABLE_TX_POLLING )        || \
       defined( C_ENABLE_INDIVIDUAL_POLLING ) || \
       !defined( C_ENABLE_ERROR_POLLING )     ||\
       !defined( C_ENABLE_WAKEUP_POLLING ))        /* ISR necessary; no pure polling configuration*/
V_DEF_FUNC(STATIC, void, CODE) Can_CellIsr( CAN_HW_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 1 END */
# endif

/* KB end CanLL_LocalPrototypes */

/***************************************************************************/
/*  Error Check                                                            */
/***************************************************************************/

/***************** error check for Organi process **************************/







/***************** error check for not supported feature  **************************/




#if defined( C_ENABLE_COMMON_CAN )
# error "Common CAN is not supported with this CAN driver implementation"
#endif

#if defined( C_ENABLE_MULTI_ECU_CONFIG )
# error "Multiple Configuration is not supported with this CAN driver implementation"
#endif

#if defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )
# error "Extended RAM Check is not supported with this CAN driver implementation"
#endif

#if (VSTDLIB__COREHLL_VERSION  <  0x0213 )
# error "Incompatible version of VStdLib. Core Version 2.13.00 or higher is necessary."
#endif

#if defined( C_CPUTYPE_8BIT )
# if (kCanNumberOfTxObjects > 250)
#  error "Too many transmit messages. This driver can only handle up to 250 transmit messages"
# endif
# if (kCanNumberOfRxObjects > 250)
#  error "Too many receive messages. This driver can only handle up to 250 receive messages"
# endif
#endif

#if (kCanNumberOfHwChannels > 255)
#  error "Too many CAN channels. This driver can only handle up to 255 channels"
#endif

#if defined( C_SEARCH_HASH )
# if !defined( kHashSearchListCountEx )
#  error "kHashSearchListCountEx not defined"
# endif
# if !defined( kHashSearchMaxStepsEx )
#  error "kHashSearchMaxStepsEx not defined"
# endif
# if !defined( kHashSearchListCount )
#  error "kHashSearchListCount not defined"
# endif
# if !defined( kHashSearchMaxSteps )
#  error "kHashSearchMaxSteps not defined"
# endif
# if ( (kHashSearchMaxStepsEx < 1) ||(kHashSearchMaxStepsEx > 32768) )
#  error "kHashSearchMaxStepsEx has ilegal value"
# endif
# if ( kHashSearchListCountEx > 32768 )
#  error "Hash table for extended ID is too large"
# endif
# if ( (kHashSearchMaxSteps < 1) ||(kHashSearchMaxSteps > 32768) )
#  error "kHashSearchMaxStepsEx has ilegal value"
# endif
# if ( kHashSearchListCount > 32768 )
#  error "Hash table for standard ID is too large"
# endif
# if !defined( C_ENABLE_EXTENDED_ID) && (kHashSearchListCountEx > 0)
#  error "kHashSearchListCountEx has to be 0 in this configuration"
# endif
# if defined( C_ENABLE_EXTENDED_ID) && !defined( C_ENABLE_MIXED_ID) &&(kHashSearchListCount > 0)
#  error "kHashSearchListCount has to be 0 in this configuration"
# endif
#endif





#if defined( C_ENABLE_RX_QUEUE )
# if defined( C_CPUTYPE_8BIT ) && ( kCanRxQueueSize > 256 )
#  error "With 8 Bit CPU the Rx queue size has to be smaller or equal to 256"
# endif
# if !defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
#  error "RX-Queue requires C_HL_ENABLE_RX_INFO_STRUCT_PTR"
# endif
#endif




#if defined ( CAN_POLLING_IRQ_DISABLE ) || defined ( CAN_POLLING_IRQ_RESTORE )
# error "Feature has changed - use C_DISABLE_CAN_CAN_INTERRUPT_CONTROL to remove the CAN interrupt disabling"
#endif

/* KB begin CanLL_ErrorCheck */
/* KB end CanLL_ErrorCheck */


/***************************************************************************/
/*  Functions                                                              */
/***************************************************************************/

/* KB begin CanLL_Functions */

# if defined( C_ENABLE_MEMCOPY_SUPPORT )
/* **************************************************************************
| NAME:             CanCopyFromCan
| CALLED BY:        Application
| PRECONDITIONS:    none
|
| INPUT PARAMETERS: void *             dst        | pointer to destionation buffer
|                   CanChipDataPtr     src        | pointer to CAN buffer
|                   vuint8             len        | number of bytes to copy
|
| RETURN VALUES:    -
|
| DESCRIPTION:      copy data from CAN receive buffer to RAM.
|
| ATTENTION:        
************************************************************************** */
/* Msg(4:3673) The object addressed by the pointer "src" is not modified in this function.
   The use of "const" should be considered to indicate that it never changes. MISRA Rule 81 - no change */
/* CODE CATEGORY 1 START */
V_DEF_FUNC_API(V_NONE, void, CODE) CanCopyFromCan(V_DEF_P2VAR_PARA(V_NONE, void, AUTOMATIC, APPL_VAR) dst, CanChipDataPtr src, vuint8 len)    /* PRQA S 3673 */      /* suppress message about const pointer */
{
  while(len--)
  {
    *((V_DEF_P2VAR(V_NONE, vuint8, AUTOMATIC, APPL_VAR)) dst) = *src++;
    dst = ((V_DEF_P2VAR(V_NONE, vuint8, AUTOMATIC, VAR_NOINIT)) dst)+1;
  }
}
/* CODE CATEGORY 1 END */

/* **************************************************************************
| NAME:             CanCopyToCan
| CALLED BY:        Application
| PRECONDITIONS:    none
|
| INPUT PARAMETERS: void *             src        | pointer to source buffer
|                   CanChipDataPtr     dst        | pointer to CAN buffer
|                   vuint8             len        | number of bytes to copy
|
| RETURN VALUES:    -
|
| DESCRIPTION:      copy data from CAN receive buffer to RAM.
|
| ATTENTION:        
************************************************************************** */
/* Msg(4:3673) The object addressed by the pointer "src" is not modified in this function.
   The use of "const" should be considered to indicate that it never changes. MISRA Rule 81 - no change */
/* CODE CATEGORY 1 START */
V_DEF_FUNC_API(V_NONE, void, CODE) CanCopyToCan(CanChipDataPtr dst, V_DEF_P2VAR_PARA(V_NONE, void, AUTOMATIC, APPL_VAR) src, vuint8 len)       /* PRQA S 3673 */     /* suppress message about const pointer */
{
  while(len--)
  {
    *dst++ = *((V_DEF_P2VAR(V_NONE, vuint8, AUTOMATIC, VAR_NOINIT)) src);
    src = ((V_DEF_P2VAR(V_NONE, vuint8, AUTOMATIC, VAR_NOINIT)) src)+1;
  }
}
/* CODE CATEGORY 1 END */
# endif


#if defined( C_ENABLE_SLEEP_WAKEUP ) 
/* **************************************************************************
| NAME:             CanLL_WakeUpHandling
| CALLED BY:        CanWakeUpTask() and WakeUp-ISR
| PRECONDITIONS:    none
|
| INPUT PARAMETERS: CanChannelHandle  channel        | current CAN channel
|                   and parameters which are defined in CanLL_WakeUpTaskLocalParameter
|
| RETURN VALUES:    -
|
| DESCRIPTION:      perform wakeup handling.
|
| ATTENTION:        CanLL_WakeUpHandling has to contain:
|                     ApplCanPreWakeUp(CAN_CHANNEL_CANPARA_ONLY);
|                     CanWakeUp(CAN_CHANNEL_CANPARA_ONLY);        - if hardware does not wake up automatically
|                     APPL_CAN_WAKEUP( channel );
|                   In case of CommonCAN, it might be necessary to call CanWakeUp even if the hardware
|                   wakes up automatically to make sure all associated HW channels are awaken.
************************************************************************** */
/* CODE CATEGORY 4 START */
V_DEF_FUNC(STATIC, void, CODE) CanLL_WakeUpHandling(CAN_CHANNEL_CANTYPE_ONLY)
{
# if defined( C_ENABLE_APPLCANPREWAKEUP_FCT )
  ApplCanPreWakeUp(CAN_CHANNEL_CANPARA_ONLY);
# endif
# if defined( C_ENABLE_NO_WAKEUP_BY_BUS )
  CanWakeUp(CAN_CHANNEL_CANPARA_ONLY);         /* if hardware does not wake up automatically */
# endif
  APPL_CAN_WAKEUP( channel );
}
/* CODE CATEGORY 4 END */
#endif /*C_ENABLE_SLEEP_WAKEUP*/

# if defined( C_ENABLE_CAN_TRANSMIT )
/****************************************************************************
| NAME:             CanLL_IsHWTxObjNotFree
| CALLED BY:        CanTransmit(), CanCopyDataAndStartTransmit(),
|                   CanMsgTransmit()
| PRECONDITIONS:    none
| INPUT PARAMETERS: - logical handle to hardware transmit object
| RETURN VALUES:    True, False
| DESCRIPTION:      return kCanTrue, if hardware transmit object is free
|                   return kCanFalse otherwise
****************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(STATIC, vuintx, CODE) CanLL_TxIsHWObjFree(CanChannelHandle localchannel,  CanObjectHandle txObjHandle )
{
  vuint8  returnvalue;
  V_DEF_P2SFR_CAN(V_NONE, CAN_CellAddrMap, AUTOMATIC) pCanNode;

  pCanNode = CAN_BASIS_ADR(localchannel);
  returnvalue = kCanFailed;

  if (txObjHandle < 32)
  {
    if(((TRANSREQUEST(0) & ((vuint32)0x1<<(txObjHandle))) == 0))
    returnvalue = kCanTrue;
  }
  else
  {
    if(((TRANSREQUEST(1) & ((vuint32)0x1<<(txObjHandle-32))) == 0))
    returnvalue = kCanTrue;
  }

  return returnvalue;
}
/* CODE CATEGORY 4 END*/
#endif /* C_ENABLE_CAN_TRANSMIT */

#if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
     (defined( C_ENABLE_RX_FULLCAN_OBJECTS )  && !defined( C_ENABLE_RX_FULLCAN_POLLING  )) || \
      !defined( C_ENABLE_TX_POLLING )        || \
      !defined( C_ENABLE_ERROR_POLLING )     ||\
      !defined( C_ENABLE_WAKEUP_POLLING ))        /* ISR necessary; no pure polling configuration*/
/****************************************************************************
| NAME:             CanLL_HandleIllIrptNumber
| CALLED BY:        Can_CellIsr()
|                  
| PRECONDITIONS:    none
| INPUT PARAMETERS: Interruptnumber of Hardwareobject
| RETURN VALUES:    
| DESCRIPTION:      Clear the interrupt of a Hardwareobject
|                  
****************************************************************************/
V_DEF_FUNC(STATIC, void, CODE) CanLL_HandleIllIrptNumber(CAN_CHANNEL_CANTYPE_FIRST vuint16 intnumber)
{
  #if defined( C_ENABLE_HW_LOOP_TIMER )
  vuint8 canTimerResult;
  #endif

  CanDeclarePointerToCanHardware;
  CanSetPointerToCanHardware;

  assertHardware( ((IF_RECEIVE.ComRequest & kIFxBusy) != kIFxBusy), channel, kErrorRxHwBufferBusy );

  APPLCANTIMERSTART(kCanLoopBusyReq);

  do{
      CANTIMERRESULT_UPDATE(kCanLoopBusyReq);

    } WHILE_CONDITON( ((IF_RECEIVE.ComRequest & kIFxBusy) == kIFxBusy) );

  APPLCANTIMEREND(kCanLoopBusyReq);


  /* WrRd,Mask,Arb,Control,ClrIntPnd,TxRqstNDat,DataA,DataB set */
  IF_RECEIVE.ComMask    = kSetMask | kSetArb | kSetControl | kSetClrIntPnd | kSetTxRqstNDat | kSetDataA | kSetDataB;
  IF_RECEIVE.ComRequest = intnumber;
}
#endif

# if defined(C_ENABLE_CAN_RAM_CHECK)
/* **************************************************************************
| NAME:             CanLL_IsMailboxCorrupt
| CALLED BY:        CanCheckMemory()
| PRECONDITIONS:    none
|
| INPUT PARAMETERS: CanChannelHandle  channel        | current CAN channel
|                   CanObjectHandle   hwObjHandle    | Handle to hardware object
|
| RETURN VALUES:    kCanTrue:  Mailbox is corrupt
|                   kCanFalse: Mailbox is not corrupt  
|
| DESCRIPTION:      check the current mailbox at index hwObjHandle
************************************************************************** */
/* CODE CATEGORY 4 START */
V_DEF_FUNC(STATIC, vuint8, CODE) CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle hwObjHandle)
{
  vuint8  i;
  vuint8  retval;
  vuint16 CanMemCheckPattern[4] = {0x0000,0x5555,0xAAAA,0x0000};
  CanDeclarePointerToCanHardware;
#if defined( C_ENABLE_HW_LOOP_TIMER )
  vuint8 canTimerResult;
#endif

  retval = kCanFalse; 
  CanSetPointerToCanHardware;

  for(i = 0; i < 4; i++)
  {
    /************************************************************************************/
    /* write testvalues into the CAN-Register                                           */
    /************************************************************************************/

    APPLCANTIMERSTART(kCanLoopBusyReq);

    do{
        CANTIMERRESULT_UPDATE(kCanLoopBusyReq);

      } WHILE_CONDITON( ((IF_TRANSMIT.ComRequest & kIFxBusy) == kIFxBusy) );

    APPLCANTIMEREND(kCanLoopBusyReq);


    /* Mask,Arb,Control,DataA,DataB set */
    IF_TRANSMIT.ComMask         =  kSetWrRd  |  kSetMask  |  kSetArb  |  kSetControl  |  kSetDataA  |  kSetDataB;
    IF_TRANSMIT.ArbitrFld1      =  CanMemCheckPattern[i];
    IF_TRANSMIT.ArbitrFld2      =  CanMemCheckPattern[i];
    IF_TRANSMIT.Data.usData[0]  =  CanMemCheckPattern[i];
    IF_TRANSMIT.Data.usData[1]  =  CanMemCheckPattern[i];
    IF_TRANSMIT.Data.usData[2]  =  CanMemCheckPattern[i];
    IF_TRANSMIT.Data.usData[3]  =  CanMemCheckPattern[i];
    IF_TRANSMIT.MessageCntrl    = (CanMemCheckPattern[i] & 0x000F) | kSetEoB;

    /* start copy data from IFx to ObjectRAM */
    IF_TRANSMIT.ComRequest   =  hwObjHandle + 1;
 
    APPLCANTIMERSTART(kCanLoopBusyReq);

    do{
        CANTIMERRESULT_UPDATE(kCanLoopBusyReq);

      } WHILE_CONDITON( ((IF_TRANSMIT.ComRequest & kIFxBusy) == kIFxBusy) );

    APPLCANTIMEREND(kCanLoopBusyReq);


    /************************************************************************************/
    /* read testvalues from the CAN-Register                                            */
    /************************************************************************************/

    APPLCANTIMERSTART(kCanLoopBusyReq);

    do{
        CANTIMERRESULT_UPDATE(kCanLoopBusyReq);

      } WHILE_CONDITON( ((IF_RECEIVE.ComRequest & kIFxBusy) == kIFxBusy) );

    APPLCANTIMEREND(kCanLoopBusyReq);


    /* Mask,Arb,Control,DataA,DataB set */
    IF_RECEIVE.ComMask     =  kSetMask  |  kSetArb  |  kSetControl  |  kSetDataA  |  kSetDataB;

    /* start copy data from ObjectRAM to IFx */
    IF_RECEIVE.ComRequest  =  hwObjHandle + 1;

    APPLCANTIMERSTART(kCanLoopBusyReq);

    do{
        CANTIMERRESULT_UPDATE(kCanLoopBusyReq);

      } WHILE_CONDITON( ((IF_RECEIVE.ComRequest & kIFxBusy) == kIFxBusy) );

    APPLCANTIMEREND(kCanLoopBusyReq);


    if( (IF_RECEIVE.ArbitrFld1             != CanMemCheckPattern[i]) || 
        (IF_RECEIVE.ArbitrFld2             != CanMemCheckPattern[i]) ||
        (IF_RECEIVE.Data.usData[0]         != CanMemCheckPattern[i]) || 
        (IF_RECEIVE.Data.usData[1]         != CanMemCheckPattern[i]) ||
        (IF_RECEIVE.Data.usData[2]         != CanMemCheckPattern[i]) || 
        (IF_RECEIVE.Data.usData[3]         != CanMemCheckPattern[i]) ||
       ((IF_RECEIVE.MessageCntrl & 0x000F) != (CanMemCheckPattern[i] & 0x000F)) )
    {
      retval = kCanTrue; /* the mailbox is corrupt */
      break;
    }
  } 

  return(retval);
}
/* CODE CATEGORY 4 END */
# endif

#if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
     (defined( C_ENABLE_RX_FULLCAN_OBJECTS )  && !defined( C_ENABLE_RX_FULLCAN_POLLING  )) || \
      !defined( C_ENABLE_TX_POLLING )        || \
      defined( C_ENABLE_INDIVIDUAL_POLLING ) || \
      !defined( C_ENABLE_ERROR_POLLING )     ||\
      !defined( C_ENABLE_WAKEUP_POLLING ))        /* ISR necessary; no pure polling configuration*/
/* **************************************************************************
| NAME:             Can_CellIsr
| CALLED BY:        CanIsr_<x>, where x=0..2
| PRECONDITIONS:
| INPUT PARAMETERS: canHwChannel
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt stucture
|                   - check for the interrupt reason ( interrupt source )
|                   - work appropriate interrupt:
|                     + status/error interrupt (busoff, wakeup, error warning)
|                     + basic can receive
|                     + full can receive
|                     + can transmit
|
|                   If an Rx-Interrupt occurs while the CAN controller is in Sleep mode, 
|                   a wakeup has to be generated. 
|
|                   If an Tx-Interrupt occurs while the CAN controller is in Sleep mode, 
|                   an assertion has to be called and the interrupt has to be ignored.
|
|                   The name of BrsTimeStrt...() and BrsTimeStop...() can be addapted to 
|                   realy used name of the interrupt functions.
|
************************************************************************** */
/* CODE CATEGORY 1 START */
V_DEF_FUNC(STATIC, void, CODE) Can_CellIsr( CAN_HW_CHANNEL_CANTYPE_ONLY )
{
# if defined( C_ENABLE_HW_LOOP_TIMER )
  vuint8 canTimerResult;
# endif

  vuint16 intnumber;
  CanDeclarePointerToCanHardware;
  CanSetPointerToCanHardware;

  intnumber = INTERRUPTREG;

  APPLCANTIMERSTART(kCanLoopIrqReq);

  do
  {
    if ((intnumber & 0x8000) == kCanStatusInt) 
    {
      /*********************************************************************/
      /* Status Interrupt                                                  */
      /*********************************************************************/
# if (defined( C_ENABLE_ERROR_POLLING ) && defined( C_ENABLE_WAKEUP_POLLING ))
      assertInternal (0, channel, kErrorHwObjNotInPolling);                                         
# else     
      CanHL_ErrorHandling( CAN_CHANNEL_CANPARA_ONLY );
# endif
    }
    else
    {
      /*********************************************************************/
      /* CAN-Message Interrupt                                             */
      /*********************************************************************/
      assertInternal (intnumber<=CAN_NUMBER_OF_MSG(channel), channel, kErrorIllIrptNumber); 

      if(intnumber >= CAN_HL_HW_RX_BASIC_STARTINDEX(channel) + 1)

 
      {
# if defined ( C_ENABLE_RX_BASICCAN_OBJECTS )
        /*******************************************************************/
        /* BasicCAN-Interrupt                                              */
        /*******************************************************************/
#  if (defined ( C_ENABLE_RX_BASICCAN_POLLING ) && !defined (C_ENABLE_INDIVIDUAL_POLLING))
        assertInternal (0, channel, kErrorHwObjNotInPolling);                                     
#  else
        CanBasicCanMsgReceived( CAN_CHANNEL_CANPARA_FIRST intnumber - 1); 
#  endif
# endif
      }
      else
      {                
        if(intnumber >= CAN_HL_HW_RX_FULL_STARTINDEX(channel) + 1)
        {
# if defined ( C_ENABLE_RX_FULLCAN_OBJECTS )
          /*****************************************************************/
          /* FullCAN-Interrupt                                             */
          /*****************************************************************/
#  if (defined (C_ENABLE_RX_FULLCAN_POLLING) && !defined (C_ENABLE_INDIVIDUAL_POLLING))
          assertInternal (0, channel, kErrorHwObjNotInPolling);                       
#  else
          CanFullCanMsgReceived( CAN_CHANNEL_CANPARA_FIRST intnumber - 1);
#  endif
# endif
        }
        else
        {
          if(intnumber >= CAN_HL_HW_TX_STOPINDEX(channel) + 1)
          {
            /***************************************************************/
            /* Illegal-Interrupt                                           */
            /***************************************************************/
            assertInternal (0, channel, kErrorIllIrptNumber);                  
            CanLL_HandleIllIrptNumber(CAN_CHANNEL_CANPARA_FIRST intnumber - 1);
          }
          else
          {
            if (intnumber == 0) 
            {
                /* unexpected interrupt, do nothing */
            }
            else
            {
# if (defined( C_ENABLE_TX_POLLING) && !defined (C_ENABLE_INDIVIDUAL_POLLING))
                /***************************************************************/
                /* TxSend-Interrupt                                            */
                /***************************************************************/
                assertInternal (0, channel, kErrorHwObjNotInPolling);                
# else 
                /* Tx Confirmation-Interrupt --------------------------------- */
                CanHL_TxConfirmation(CAN_CHANNEL_CANPARA_FIRST intnumber - 1);
# endif
            }
          }
        }
      }
    }

    intnumber = INTERRUPTREG;

    CANTIMERRESULT_UPDATE(kCanLoopIrqReq);

  } WHILE_CONDITON( (intnumber != 0) );

  APPLCANTIMEREND(kCanLoopIrqReq);
}
/* CODE CATEGORY 1 END*/
#endif
/* KB end CanLL_Functions */
/* KB begin CanLL_FunctionsISR */
#if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
     (defined( C_ENABLE_RX_FULLCAN_OBJECTS )  && !defined( C_ENABLE_RX_FULLCAN_POLLING  )) || \
      !defined( C_ENABLE_TX_POLLING )        || \
      defined( C_ENABLE_INDIVIDUAL_POLLING ) || \
      !defined( C_ENABLE_ERROR_POLLING )     ||\
      !defined( C_ENABLE_WAKEUP_POLLING ))        /* ISR necessary; no pure polling configuration*/
/* **************************************************************************
| NAME:             CanIsr_0
| CALLED BY:        HLL, Asr: Interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt stucture
|
|  Attention:  <Name> has to be repleased with the name of the ISR. 
|              Naming conventions: with Name = "", "Rx", "Tx", "RxTx", "Wakeup", "Status" 
|  The name of the ISR will always have a channel index at the end. Even in single channel
|  systems.
************************************************************************** */
/* CODE CATEGORY 1 START */
# if defined( kCanPhysToLogChannelIndex_0 )
#  if defined( C_ENABLE_OSEK_OS ) && \
      defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsr_0 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && \
       defined (osdIsrCanIsr_0Cat)
#    if (osdIsrCanIsr_0Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_0( void )
#  endif /* C_ENABLE_OSEK_OS */
{
  Metrics_TaskStart(T1_DCan1_level0_Irq_ID);

#   if defined( C_SINGLE_RECEIVE_CHANNEL )
  Can_CellIsr();
#   else
  Can_CellIsr(kCanPhysToLogChannelIndex_0);            /* call Interrupthandling with logical channel */
#   endif

  Metrics_TaskEnd(T1_DCan1_level0_Irq_ID);
} /* END OF CanISR */
# endif /* (kCanPhysToLogChannelIndex_0) */
/* CODE CATEGORY 1 END */
/* **************************************************************************
| NAME:             CanIsr_1
| CALLED BY:        HLL, Asr: Interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt stucture
|
|  Attention:  <Name> has to be repleased with the name of the ISR. 
|              Naming conventions: with Name = "", "Rx", "Tx", "RxTx", "Wakeup", "Status" 
|  The name of the ISR will always have a channel index at the end. Even in single channel
|  systems.
************************************************************************** */
/* CODE CATEGORY 1 START */
# if defined( kCanPhysToLogChannelIndex_1 )
#  if defined( C_ENABLE_OSEK_OS ) && \
      defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_1Cat)
#    if (osdIsrCanIsr_1Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsr_1 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && \
       defined (osdIsrCanIsr_1Cat)
#    if (osdIsrCanIsr_1Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_1( void )
#  endif /* C_ENABLE_OSEK_OS */
{
  Metrics_TaskStart(T1_DCan2_level0_Irq_ID);

#   if defined( C_SINGLE_RECEIVE_CHANNEL )
  Can_CellIsr();
#   else
  Can_CellIsr(kCanPhysToLogChannelIndex_1);            /* call Interrupthandling with logical channel */
#   endif

  Metrics_TaskEnd(T1_DCan2_level0_Irq_ID);
} /* END OF CanISR */
# endif /* (kCanPhysToLogChannelIndex_1) */
/* CODE CATEGORY 1 END */
/* **************************************************************************
| NAME:             CanIsr_2
| CALLED BY:        HLL, Asr: Interrupt
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt stucture
|
|  Attention:  <Name> has to be repleased with the name of the ISR. 
|              Naming conventions: with Name = "", "Rx", "Tx", "RxTx", "Wakeup", "Status" 
|  The name of the ISR will always have a channel index at the end. Even in single channel
|  systems.
************************************************************************** */
/* CODE CATEGORY 1 START */
# if defined( kCanPhysToLogChannelIndex_2 )
#  if defined( C_ENABLE_OSEK_OS ) && \
      defined( C_ENABLE_OSEK_OS_INTCAT2 )
#   if defined (osdIsrCanIsr_2Cat)
#    if (osdIsrCanIsr_2Cat != 2)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
ISR( CanIsr_2 )
#  else
#   if defined( C_ENABLE_OSEK_OS ) && \
       defined (osdIsrCanIsr_2Cat)
#    if (osdIsrCanIsr_2Cat != 1)
#     error "inconsistent configuration of Osek-OS interrupt categorie between CANgen/GENy and OIL-configurator (CanIsr)"
#    endif
#   endif
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_2( void )
#  endif /* C_ENABLE_OSEK_OS */
{

#   if defined( C_SINGLE_RECEIVE_CHANNEL )
  Can_CellIsr();
#   else
  Can_CellIsr(kCanPhysToLogChannelIndex_2);            /* call Interrupthandling with logical channel */
#   endif

} /* END OF CanISR */
# endif /* (kCanPhysToLogChannelIndex_2) */
/* CODE CATEGORY 1 END */

#endif  /* Not a pure polling configuration */

/* KB end CanLL_FunctionsISR */

/****************************************************************************
| NAME:             CanInit
| CALLED BY:        CanInitPowerOn(), Network management
| PRECONDITIONS:    none
| INPUT PARAMETERS: Handle to initstructure
| RETURN VALUES:    none
| DESCRIPTION:      initialization of chip-hardware
|                   initialization of receive and transmit message objects
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanInit( CAN_CHANNEL_CANTYPE_FIRST CanInitHandle initObject )     /* PRQA S 1505 */
{
#if defined( C_ENABLE_CAN_RAM_CHECK )
  vuint8                 canRamCheckStatus;
#endif
  CanObjectHandle        hwObjHandle;
#if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION ) || \
    defined( C_ENABLE_CAN_MSG_TRANSMIT_CANCEL_NOTIFICATION )
  CanTransmitHandle      txHandle;
#endif
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
  CanReceiveHandle       rxHandle;
#endif
  CanObjectHandle        logTxObjHandle;

  /* KB begin CanLL_InitLocalParameter */
  vuint8    index;
  
  #if defined( C_ENABLE_HW_LOOP_TIMER )
  vuint8 canTimerResult;
  #endif
  
  CanDeclarePointerToCanHardware;
  
  #if defined( C_ENABLE_DCAN_ISSUE22_WORKAROUND )
  vuint16 nbOfIterations;
  vuint32 tmpCNTRLREG;
  #endif
  /* KB end CanLL_InitLocalParameter */

#if defined( C_HL_ENABLE_LAST_INIT_OBJ )  
  lastInitObject[channel] = initObject;
#endif

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
/* Msg(4:3759) Implicit conversion: int to unsigned short. MISRA Rule 43 - no change in RI 1.4 */
  initObject  += CAN_HL_INIT_OBJ_STARTINDEX(channel);
#endif


#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#endif
  assertUser(initObject < kCanNumberOfInitObjects, channel, kErrorInitObjectHdlTooLarge);    /* PRQA S 3109 */
  assertUser(initObject < CAN_HL_INIT_OBJ_STOPINDEX(channel), channel, kErrorInitObjectHdlTooLarge);     /* PRQA S 3109 */

#if defined( C_ENABLE_CAN_RAM_CHECK )
  canRamCheckStatus = kCanRamCheckOk;
#endif

  {

    /* KB begin CanLL_InitBegin */
    #if defined( V_ENABLE_USE_DUMMY_STATEMENT )
    lastInitObject[channel] = lastInitObject[channel];  /* dummy assignment to avoid compiler warning */
    #endif
    
    STATUS_BUS_OFF(channel) = 0;
    CanSetPointerToCanHardware;
    
    #if defined( C_ENABLE_SLEEP_WAKEUP )
    STATUS_SLEEP(channel) = 0;
    #endif
    
    #if defined( C_ENABLE_DCAN_ISSUE22_WORKAROUND )
    tmpCNTRLREG = CNTRLREG;
    #endif
    
    /* set CAN-cell into Initmode */
    CNTRLREG = kSetInit;
    
    #if defined( C_ENABLE_DCAN_ISSUE22_WORKAROUND )
    if((tmpCNTRLREG & kSetInit) == 0)
    {
      /* neither power-on nor bus-off did occur -> DCAN#22 issue workaround is necessary */
      /* according to the erratum the CAN interrupts have to locked at this point */
    
      /* wait into the loop at least 6 CAN clock cycles */
      nbOfIterations = CAN_GLOBAL_CONFIG(CanErrata22Iterations);
      while(nbOfIterations > 0)
      {
        nbOfIterations--;
        asm(" nop");
        asm(" nop");
        asm(" nop");
        asm(" nop");
        asm(" nop");
        asm(" nop");
      }
    
      CNTRLREG |= kSetSWR;
    }
    #endif
    
    /* allow CCE to write in the Configregister and configure wakeup */
    CNTRLREG |= (kSetCCE | kSetWUBA);
    
    /* clear Statregister and Testregister */ 
    CAN_LL_STATUS(channel) = STATREG;
    TESTREG  = kClearAll;
    
    /* init Bit-Timing with user-generated Data */ 
    BITTIMING = CanInitBitTiming[initObject]; 
    
    /* init Baud Rate Prescaler Extension with user-generated Data */
    BRP_REG = CanInitBRP_Reg[initObject]; 
    
    /* KB end CanLL_InitBegin */
    
    /* Init Tx-Objects -------------------------------------------------------- */
    /* init saved Tx handles: */                   
    /* in case of CommonCAN, transmission is always on the frist HW channel of a CommonCAN channel */
    {
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
      assertGen( (vsintx)CAN_HL_HW_TX_STOPINDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel) 
                 == CAN_HL_LOG_HW_TX_STOPINDEX(canHwChannel), channel, kErrorHwToLogTxObjCalculation);          /* PRQA S 3109 */
      assertGen( (vsintx)CAN_HL_HW_TX_STARTINDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel) 
                 == CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel), channel, kErrorHwToLogTxObjCalculation);         /* PRQA S 3109 */
      assertGen( CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel) <= CAN_HL_LOG_HW_TX_STOPINDEX(canHwChannel), channel, kErrorHwToLogTxObjCalculation);  /* PRQA S 3109 */
#endif
  
      for (hwObjHandle=CAN_HL_HW_TX_STARTINDEX(canHwChannel); hwObjHandle<CAN_HL_HW_TX_STOPINDEX(canHwChannel); hwObjHandle++ )     /*lint !e661*/
      {
        logTxObjHandle = (CanObjectHandle)((vsintx)hwObjHandle + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));     /*lint !e661*/

#if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION ) || \
    defined( C_ENABLE_CAN_MSG_TRANSMIT_CANCEL_NOTIFICATION )
        if((canStatus[channel] & kCanHwIsInit) == kCanHwIsInit)                    /*lint !e661*/
        {
          /* inform application, if a pending transmission is canceled */
          txHandle = canHandleCurTxObj[logTxObjHandle];

# if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
          if( txHandle < kCanNumberOfTxObjects )
          {
            APPLCANCANCELNOTIFICATION(channel, txHandle);
          }
# endif
# if defined( C_ENABLE_CAN_MSG_TRANSMIT_CANCEL_NOTIFICATION )
          if( txHandle == kCanBufferMsgTransmit)
          { 
            APPLCANMSGCANCELNOTIFICATION(channel);
          } 
# endif
        }
#endif

        canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;                   /* MsgObj is free */

#if defined( C_ENABLE_CAN_RAM_CHECK )
        if(kCanTrue == CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANPARA_FIRST hwObjHandle))
        {
# if defined( C_ENABLE_NOTIFY_CORRUPT_MAILBOX )
          ApplCanCorruptMailbox(CAN_CHANNEL_CANPARA_FIRST hwObjHandle);
# endif
          canRamCheckStatus = kCanRamCheckFailed;
        }
#endif

        /* KB begin CanLL_InitTxObj */
        APPLCANTIMERSTART(kCanLoopBusyReq);
        
        do{
            CANTIMERRESULT_UPDATE(kCanLoopBusyReq);
        
          } WHILE_CONDITON( ((IF_INIT.ComRequest & kIFxBusy) == kIFxBusy) );
        
        APPLCANTIMEREND(kCanLoopBusyReq);
        
        
         /* WrRd,Mask,Arb,Control,DataA,DataB set */
        IF_INIT.ComMask        = kSetWrRd | kSetMask | kSetArb | kSetControl | kSetDataA | kSetDataB;
        
        /* ID=0,MsgVal,Dir set */
        IF_INIT.ArbitrFld2     = kSetMsgVal | kSetDir;
        IF_INIT.ArbitrFld1     = kClearAll;
        
        if(CAN_INDIV_POLLING(channel,hwObjHandle) != 0)
        {
        IF_INIT.MessageCntrl   = kSetEoB; /* EoB set */
        }
        else
        {
        IF_INIT.MessageCntrl   = kSetEoB |  kSetEnableTxCanInt; /* EoB,TxIE set */
        }
        
        /* Mask and Data=0, MDir set */ 
        IF_INIT.Mask1          = kClearAll;
        IF_INIT.Mask2          = kSetMDir;
        IF_INIT.Data.ulData[0] = kClearAll;
        IF_INIT.Data.ulData[1] = kClearAll;
        
        /* start copy data from IFx to ObjectRAM */
        /* first address of Objekt in CAN-Cell starts with 1 ! */
        IF_INIT.ComRequest     = hwObjHandle + 1;
        
        /* KB end CanLL_InitTxObj */
      }

    }

    /* init unused msg objects ------------------------------------------------ */
    for (hwObjHandle=CAN_HL_HW_UNUSED_STARTINDEX(canHwChannel); hwObjHandle<CAN_HL_HW_UNUSED_STOPINDEX(canHwChannel); hwObjHandle++ )  /*lint !e661 !e681*/
    {
      /* KB begin CanLL_InitUnusedObj */
      APPLCANTIMERSTART(kCanLoopBusyReq);
      
      do{
          CANTIMERRESULT_UPDATE(kCanLoopBusyReq);
      
        } WHILE_CONDITON( ((IF_INIT.ComRequest & kIFxBusy) == kIFxBusy) );
      
      APPLCANTIMEREND(kCanLoopBusyReq);
      
      
      /* Mask,Arb,Control,DataA,DataB set */
      IF_INIT.ComMask        = kSetWrRd | kSetMask | kSetArb | kSetControl | kSetDataA | kSetDataB;
      
      /* Unused MsgObjekt => MsgVal=0 */  
      IF_INIT.ArbitrFld1     = kClearAll;
      IF_INIT.ArbitrFld2     = kClearAll;
      
      /* Mask and Data=0 */ 
      IF_INIT.Mask1          = kClearAll;
      IF_INIT.Mask2          = kClearAll;
      IF_INIT.Data.ulData[0] = kClearAll;
      IF_INIT.Data.ulData[1] = kClearAll;
      
      IF_INIT.MessageCntrl   = kSetEoB;
      
      /* start copy data from IFx to ObjectRAM */
      /* first address of Objekt in CAN-Cell starts with 1 ! */
      IF_INIT.ComRequest     = hwObjHandle + 1;
      
      /* KB end CanLL_InitUnusedObj */
    }


#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
    /* init full can receive msg objects: ------------------------------------- */
    for (hwObjHandle=CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel); hwObjHandle<CAN_HL_HW_RX_FULL_STOPINDEX(canHwChannel); hwObjHandle++ )
    {
      /* brackets to avoid lint info 834 */
      rxHandle = (hwObjHandle-CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel))+CAN_HL_RX_FULL_STARTINDEX(canHwChannel);

#if defined( C_ENABLE_CAN_RAM_CHECK )
      if(kCanTrue == CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANPARA_FIRST hwObjHandle))
      {
# if defined( C_ENABLE_NOTIFY_CORRUPT_MAILBOX )
        ApplCanCorruptMailbox(CAN_CHANNEL_CANPARA_FIRST hwObjHandle);
# endif
        canRamCheckStatus = kCanRamCheckFailed;
      }
#endif

      /* KB begin CanLL_InitFullCANObj */
      APPLCANTIMERSTART(kCanLoopBusyReq);
      
      do{
          CANTIMERRESULT_UPDATE(kCanLoopBusyReq);
      
        } WHILE_CONDITON( ((IF_INIT.ComRequest & kIFxBusy) == kIFxBusy) );
      
      APPLCANTIMEREND(kCanLoopBusyReq);
      
      
      /* WrRd,Mask,Arb,Control,DataA,DataB set */
      IF_INIT.ComMask        = kSetWrRd | kSetMask | kSetArb | kSetControl | kSetDataA | kSetDataB;                                      
      
      /* ID=0,Dir=0,MsgVal */
      #if defined( C_ENABLE_EXTENDED_ID )
      IF_INIT.ArbitrFld1     = (vuint16)((CanGetRxId1(rxHandle)));
      #endif  
      IF_INIT.ArbitrFld2     = kSetMsgVal | (vuint16)((CanGetRxId0(rxHandle))); 
      
      IF_INIT.Mask1          = kClearAll;
      IF_INIT.Mask2          = kSetMXtd | kSetMDir;
      
      /* EoB,RxIE,DLC set */
      if(CAN_INDIV_POLLING(channel,hwObjHandle) != 0)
      {
        IF_INIT.MessageCntrl   = kSetEoB;
      }
      else
      {
        IF_INIT.MessageCntrl   = kSetEoB | kSetEnableRxFullCanInt;
      }
      
      #if defined( C_ENABLE_EXTENDED_ID ) &&  defined( C_ENABLE_RX_MASK_EXT_ID )
      
      # if defined( C_ENABLE_MIXED_ID )
      if ( (CanGetRxIdType(rxHandle)) == kCanIdTypeExt )
      # endif
      {
        /* because of RX_MASK_EXT_ID override old value of mask register */
        IF_INIT.Mask1        = MK_EXTID1(C_MASK_EXT_ID);
        IF_INIT.Mask2        = MK_EXTID0(C_MASK_EXT_ID) | kSetMXtd | kSetMDir;
      }
      
      /* EoB,RxIE,DLC set, because of RX_MASK_EXT_ID UMask must set (override old value) */
      if(CAN_INDIV_POLLING(channel,hwObjHandle) != 0)
      {
        IF_INIT.MessageCntrl   = kSetEoB;
      }
      else
      {
        IF_INIT.MessageCntrl   = kSetEoB | kSetEnableRxFullCanInt | kSetUseUMask;
      }
      
      #endif
         
      /* Data=0 */
      IF_INIT.Data.ulData[0] = kClearAll;
      IF_INIT.Data.ulData[1] = kClearAll;
      
      assertGen( hwObjHandle >= CAN_HL_HW_RX_FULL_STARTINDEX(channel), channel, kErrorToManyFullCanObjects);
      
      /* start copy data from IFx to ObjectRAM */
      /* first address of Objekt in CAN-Cell starts with 1 ! */
      IF_INIT.ComRequest     = hwObjHandle + 1;
      
      /* KB end CanLL_InitFullCANObj */
    }
#endif

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
    /* init basic can receive msg object: ------------------------------------- */
    for (hwObjHandle=CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel); hwObjHandle<CAN_HL_HW_RX_BASIC_STOPINDEX(canHwChannel); hwObjHandle++ )
    {
#if defined( C_ENABLE_CAN_RAM_CHECK )
      if(kCanTrue == CanLL_IsMailboxCorrupt(CAN_HW_CHANNEL_CANPARA_FIRST hwObjHandle))
      {
# if defined( C_ENABLE_NOTIFY_CORRUPT_MAILBOX )
        ApplCanCorruptMailbox(CAN_CHANNEL_CANPARA_FIRST hwObjHandle);
# endif
        canRamCheckStatus = kCanRamCheckFailed;
      }
#endif

      /* the LL driver has to know which ID tpyes have to be received by which object */
      /* KB begin CanLL_InitBasicCanObj */
      APPLCANTIMERSTART(kCanLoopBusyReq);
      
      do{
          CANTIMERRESULT_UPDATE(kCanLoopBusyReq);
      
        } WHILE_CONDITON( ((IF_INIT.ComRequest & kIFxBusy) == kIFxBusy) );
      
      APPLCANTIMEREND(kCanLoopBusyReq);
      
      /* WrRd,Mask,Arb,Control,DataA,DataB set */
      IF_INIT.ComMask     =  kSetWrRd | kSetMask | kSetArb | kSetControl | kSetDataA | kSetDataB;
      
      IF_INIT.ArbitrFld1  =  CanInitBasicCod1[initObject][((hwObjHandle - CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)) & (vuint8)0xFE)>>1];
      IF_INIT.ArbitrFld2  =  CanInitBasicCod2[initObject][((hwObjHandle - CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)) & (vuint8)0xFE)>>1] | kSetMsgVal;
      IF_INIT.Mask1       =  CanInitBasicMsk1[initObject][((hwObjHandle - CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)) & (vuint8)0xFE)>>1];
      IF_INIT.Mask2       =  CanInitBasicMsk2[initObject][((hwObjHandle - CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)) & (vuint8)0xFE)>>1] | kSetMDir;                        
                                 
      if((hwObjHandle & 0x0001) == 0)
      {
        if(CAN_INDIV_POLLING(channel,hwObjHandle) != 0)
        {
          IF_INIT.MessageCntrl = kSetUMask;
        }
        else
        {
          IF_INIT.MessageCntrl = kSetUMask | kSetEnableRxBasicCanInt;
        }
      
      }
      else
      {
        if(CAN_INDIV_POLLING(channel,hwObjHandle) != 0)
        {
          IF_INIT.MessageCntrl = kSetUMask | kSetEoB;
        }
        else
        {
          IF_INIT.MessageCntrl = kSetUMask | kSetEoB | kSetEnableRxBasicCanInt;
        }
      }
      
      
      /* start copy data from IFx to ObjectRAM */
      /* first address of Objekt in CAN-Cell starts with 1 ! */
      IF_INIT.ComRequest  =  hwObjHandle + 1;
            
      /* KB end CanLL_InitBasicCanObj */
    }
#endif
                     
    /* KB begin CanLL_InitEnd */
    /* KB begin CanLL_InitEnd_InitMode */
    for ( index = 0; index < 4; index++ )
    {
      TX_SEND_FLAG(channel, index) = 0;
    }
    
    #if defined( C_ENABLE_RX_BASICCAN_POLLING ) && defined( C_ENABLE_RX_FULLCAN_POLLING ) && \
        defined( C_ENABLE_TX_POLLING )          && defined( C_ENABLE_ERROR_POLLING )      && \
        defined( C_ENABLE_WAKEUP_POLLING )
    NORMAL_MODE(channel) = (vuint16)(kSetPMD | kSetEnableErrorInt | kSetWUBA);
    #else
    NORMAL_MODE(channel) = (vuint16)(kSetPMD | kSetEnableErrorInt | kSetIE | kSetWUBA);
    #endif    
    
    
    
    /* KB end CanLL_InitEnd_InitMode */
    /* KB begin CanLL_InitEnd_StartMode */
    /* Change into Normal Mode: */
    CNTRLREG = NORMAL_MODE(channel); 
    
    /* KB end CanLL_InitEnd_StartMode */
    /* KB end CanLL_InitEnd */
  } /* end of loop over all hw channels */

#if defined( C_ENABLE_TX_OBSERVE )
  ApplCanInit( CAN_CHANNEL_CANPARA_FIRST CAN_HL_LOG_HW_TX_STARTINDEX(canHwChannel), CAN_HL_LOG_HW_TX_STOPINDEX(canHwChannel) );
#endif
#if defined( C_ENABLE_MSG_TRANSMIT_CONF_FCT )
  APPL_CAN_MSGTRANSMITINIT( CAN_CHANNEL_CANPARA_ONLY );
#endif

#if defined( C_ENABLE_CAN_RAM_CHECK )
  if( canRamCheckStatus == kCanRamCheckFailed)
  {
    /* let the application decide if communication is disabled */
    if (ApplCanMemCheckFailed(CAN_CHANNEL_CANPARA_ONLY) == kCanDisableCommunication)
    {
      canComStatus[channel] = kCanDisableCommunication;
    }  
  }
#endif


} /* END OF CanInit */
/* CODE CATEGORY 4 END*/


/****************************************************************************
| NAME:             CanInitPowerOn
| CALLED BY:        Application
| PRECONDITIONS:    This function must be called by the application before
|                   any other CAN driver function 
|                   Interrupts must be disabled
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Initialization of the CAN chip
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanInitPowerOn( void )
{ 

#if defined( C_ENABLE_VARIABLE_DLC )        || \
      defined( C_ENABLE_DYN_TX_OBJECTS )      || \
      defined( C_ENABLE_INDICATION_FLAG )     || \
      defined( C_ENABLE_CONFIRMATION_FLAG )
  CanTransmitHandle txHandle;
#endif
#if defined( C_ENABLE_VARIABLE_RX_DATALEN )
  CanReceiveHandle rxHandle;
#endif
  CAN_CHANNEL_CANTYPE_LOCAL


  VStdInitPowerOn();

#if defined( C_ENABLE_VARIABLE_DLC )
  for (txHandle = 0; txHandle < kCanNumberOfTxObjects; txHandle++)
  {
    assertGen(XT_TX_DLC(CanGetTxDlc(txHandle))<(vuint8)9, kCanAllChannels, kErrorTxROMDLCTooLarge);      /* PRQA S 3109 */
    canTxDLC_RAM[txHandle] = CanGetTxDlc(txHandle);
  }
#endif

#if defined( C_ENABLE_DYN_TX_OBJECTS )
  /*  Reset dynamic transmission object management -------------------------- */
  for (txHandle = 0; txHandle < kCanNumberOfTxDynObjects; txHandle++)
  {
    /*  Reset management information  */
    canTxDynObjReservedFlag[txHandle] = 0;
  }
#endif /* C_ENABLE_DYN_TX_OBJECTS */

#if defined( C_ENABLE_VARIABLE_RX_DATALEN )
  /*  Initialize the array with received dlc -------------------------- */
  for (rxHandle = 0; rxHandle < kCanNumberOfRxObjects; rxHandle++) {
    canVariableRxDataLen[rxHandle] = CanGetRxDataLen(rxHandle);
  }
#endif

#if defined( C_ENABLE_INDICATION_FLAG )
/* txHandle as loop variable is ok here, because the number of indication bytes is not as high as the number of Rx Messages */
  for (txHandle = 0; txHandle < kCanNumberOfIndBytes; txHandle++) {
    CanIndicationFlags._c[txHandle] = 0;
  }
#endif

#if defined( C_ENABLE_CONFIRMATION_FLAG )
  for (txHandle = 0; txHandle < kCanNumberOfConfBytes; txHandle++) {
    CanConfirmationFlags._c[txHandle] = 0;
  }
#endif

#if defined( C_ENABLE_RX_QUEUE )
  CanDeleteRxQueue();
#endif

#if defined( C_ENABLE_TRANSMIT_QUEUE )
  /* KB begin CanHL_TxQueueInitPowerOn */
  /* KB end CanHL_TxQueueInitPowerOn */
#endif

  /* KB begin CanLL_InitPowerOn */
  #if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  STATUS_STOP_MODE(0) = STATUS_STOP_MODE(0); /* dummy assignment to avoid compiler warning */
  #endif
  #if defined (C_SINGLE_RECEIVE_CHANNEL )
  CAN_LL_STATUS(channel)    = 0;
  STATUS_STOP_MODE(channel) = 0;
  #else
  {
    vuint16 channel_number;
  
    for(channel_number=0; channel_number<kCanNumberOfChannels; channel_number++)
    {
      CAN_LL_STATUS(channel_number)    = 0;
      STATUS_STOP_MODE(channel_number) = 0;
    }  
  }
  #endif
  
  /* KB end CanLL_InitPowerOn */

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  for (channel=0; channel<kCanNumberOfChannels; channel++)
#endif
  {

#if defined( C_ENABLE_CAN_RAM_CHECK )
    canComStatus[channel] = kCanEnableCommunication;
#endif
   
    canStatus[channel]              = kCanStatusInit;

    /* KB begin CanLL_InitPowerOnChannelSpecific */
    
    /* KB end CanLL_InitPowerOnChannelSpecific */

#if defined( C_ENABLE_CAN_TX_CONF_FCT )
    txInfoStructConf[channel].Channel = channel;
#endif
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )  || \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
    canRxInfoStruct[channel].Channel  = channel;
#endif
    canCanInterruptCounter[channel] = 0; 

#if defined( C_ENABLE_TX_POLLING )          || \
      defined( C_ENABLE_RX_FULLCAN_POLLING )  || \
      defined( C_ENABLE_RX_BASICCAN_POLLING ) || \
      defined( C_ENABLE_ERROR_POLLING )       || \
      defined( C_ENABLE_WAKEUP_POLLING )      || \
      (defined( C_HL_ENABLE_CANCEL_IN_HW_TASK ) && defined( C_ENABLE_CANCEL_IN_HW ))
    canPollingTaskActive[channel] = 0;
#endif

#if defined( C_ENABLE_DYN_TX_OBJECTS )   && \
    defined( C_ENABLE_CONFIRMATION_FCT ) && \
    defined( C_ENABLE_TRANSMIT_QUEUE )
  /*  Reset dynamic transmission object management -------------------------- */
    confirmHandle[channel] = kCanBufferFree;
#endif

#if defined( C_ENABLE_TX_MASK_EXT_ID )
    canTxMask0[channel] = 0;
# if (kCanNumberOfUsedCanTxIdTables > 1)
    canTxMask1[channel] = 0;
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
    canTxMask2[channel] = 0;
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
    canTxMask3[channel] = 0;
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
    canTxMask4[channel] = 0;
# endif
#endif

#if defined( C_ENABLE_ECU_SWITCH_PASS )
    canPassive[channel]             = 0;
#endif

#if defined( C_ENABLE_PART_OFFLINE )
    canTxPartOffline[channel]       = kCanTxPartInit;
#endif
#if defined( C_ENABLE_COND_RECEIVE_FCT )
    canMsgCondRecState[channel]     = kCanTrue;
#endif

    canRxHandle[channel] = kCanRxHandleNotUsed;

    {
#if defined( C_ENABLE_TRANSMIT_QUEUE )
  /* clear all Tx queue flags */
      CanDelQueuedObj( CAN_CHANNEL_CANPARA_ONLY );
#endif

      CanInit( CAN_CHANNEL_CANPARA_FIRST 0 );

      /* canStatus is only set to init and online, if CanInit() is called for this channel. */
      canStatus[channel]              |= (kCanHwIsInit | kCanTxOn);
    }

  }

} /* END OF CanInitPowerOn */
/* CODE CATEGORY 4 END*/

#if defined( C_ENABLE_TRANSMIT_QUEUE )
/************************************************************************
* NAME:               CanDelQueuedObj
* CALLED BY:          
* PRECONDITIONS:      
* PARAMETER:          notify: if set to 1 for every deleted obj the appl is notified
* RETURN VALUE:       -
* DESCRIPTION:        Resets the bits with are set to 0 in mask
*                     Clearing the Transmit-queue
*************************************************************************/
/* CODE CATEGORY 4 START*/
static void CanDelQueuedObj( CAN_CHANNEL_CANTYPE_ONLY ) C_API_3
{ 
  /* KB begin CanHL_LocalParameterTxQueueDelQueuedObjects */
  CanSignedTxHandle     queueElementIdx;
  #if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
  CanSignedTxHandle     elementBitIdx;
  CanTransmitHandle     txHandle;
  tCanQueueElementType  elem;
  #endif
  /* KB end CanHL_LocalParameterTxQueueDelQueuedObjects */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(channel < kCanNumberOfChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);    /* PRQA S 3109 */
# endif

  /* KB begin CanHL_TxQueueDelQueuedObjects */
  #  if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
  if((canStatus[channel] & kCanHwIsInit) == kCanHwIsInit)
  {
    CAN_CAN_INTERRUPT_DISABLE(CAN_CHANNEL_CANPARA_ONLY);        /* avoid interruption by CanHL_TxConfirmation */
    for(queueElementIdx = CAN_HL_TXQUEUE_STARTINDEX(channel); queueElementIdx < CAN_HL_TXQUEUE_STOPINDEX(channel); queueElementIdx++)
    { 
      elem = canTxQueueFlags[queueElementIdx];
      if(elem != (tCanQueueElementType)0) /* is there any flag set in the queue element? */
      {
        /* iterate through all flags and notify application for every scheduled transmission */
        for(elementBitIdx = ((CanSignedTxHandle)1 << kCanTxQueueShift) - (CanSignedTxHandle)1; elementBitIdx >= (CanSignedTxHandle)0; elementBitIdx--)
        { 
          if( ( elem & CanShiftLookUp[elementBitIdx] ) != (tCanQueueElementType)0)
          { 
            txHandle = (CanTransmitHandle)((((CanTransmitHandle)queueElementIdx << kCanTxQueueShift) + (CanTransmitHandle)elementBitIdx) - CAN_HL_TXQUEUE_PADBITS(channel));  /* ESCAN00039235 */
            APPLCANCANCELNOTIFICATION(channel, txHandle);
          } 
        } 
        canTxQueueFlags[queueElementIdx] = (tCanQueueElementType)0;
      }
    } 
    CAN_CAN_INTERRUPT_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
  } 
  else
  #  endif
  {
    for(queueElementIdx = CAN_HL_TXQUEUE_STARTINDEX(channel); queueElementIdx < CAN_HL_TXQUEUE_STOPINDEX(channel); queueElementIdx++)
    { 
      canTxQueueFlags[queueElementIdx] = (tCanQueueElementType)0;
    } 
  }
  /* KB end CanHL_TxQueueDelQueuedObjects */

# if defined( C_HL_ENABLE_COPROCESSOR_SUPPORT )
  /* KB begin CanHl_CoprocessorDelQueuedObj */
  /* KB end CanHl_CoprocessorDelQueuedObj */
# endif
}
/* CODE CATEGORY 4 END*/
#endif

#if defined( C_ENABLE_CAN_TRANSMIT )
# if defined( C_ENABLE_CAN_CANCEL_TRANSMIT )
/* CODE CATEGORY 3 START*/
/****************************************************************************
| NAME:             CanCancelTransmit
| CALLED BY:        Application
| PRECONDITIONS:    none
| INPUT PARAMETERS: Tx-Msg-Handle
| RETURN VALUES:    none
| DESCRIPTION:      delete on Msg-Object
****************************************************************************/
C_API_1 void C_API_2 CanCancelTransmit( CanTransmitHandle txHandle )
{
  CanDeclareGlobalInterruptOldStatus
  CAN_CHANNEL_CANTYPE_LOCAL 
  CanObjectHandle        logTxObjHandle;
  /* ##RI1.4 - 1.6: CanCancelTransmit and CanCancelMsgTransmit */
#  if defined( C_ENABLE_CANCEL_IN_HW )
  CanObjectHandle        txObjHandle;
#  endif

# if defined( C_ENABLE_TRANSMIT_QUEUE )
  /* KB begin CanHL_LocalParameterTxQueueModifyEntry */
  CanSignedTxHandle queueElementIdx; /* index for accessing the tx queue */
  CanSignedTxHandle elementBitIdx;  /* bit index within the tx queue element */
  CanTransmitHandle queueBitPos;  /* physical bitposition of the handle */
  /* KB end CanHL_LocalParameterTxQueueModifyEntry */
# endif

  if (txHandle < kCanNumberOfTxObjects)         /* legal txHandle ? */
  {
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    channel = CanGetChannelOfTxObj(txHandle);
# endif

# if defined( C_ENABLE_MULTI_ECU_PHYS )
    assertUser(((CanTxIdentityAssignment[txHandle] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk)0 ), channel , kErrorDisabledTxMessage);    /* PRQA S 3109 */
# endif

    CanNestedGlobalInterruptDisable();
# if defined( C_ENABLE_TRANSMIT_QUEUE )
    /* KB begin CanHL_TxQueueIfTxRequest */
    #if defined( C_ENABLE_INTERNAL_CHECK ) &&\
        defined( C_MULTIPLE_RECEIVE_CHANNEL )
    if (sizeof(queueBitPos) == 1)
    {
      assertInternal( (((vuint16)kCanNumberOfTxObjects + (vuint16)CanTxQueuePadBits[kCanNumberOfChannels-1]) <= 256u), kCanAllChannels, kErrorTxQueueTooManyHandle) /* PRQA S 3109 */ /*lint !e572 !e506*/
    }
    else
    {
      assertInternal( (((vuint32)kCanNumberOfTxObjects + (vuint32)CanTxQueuePadBits[kCanNumberOfChannels-1]) <= 65536u), kCanAllChannels, kErrorTxQueueTooManyHandle) /* PRQA S 3109 */ /*lint !e572 !e506*/
    }
    #endif
    queueBitPos  = txHandle + CAN_HL_TXQUEUE_PADBITS(channel);
    queueElementIdx = (CanSignedTxHandle)(queueBitPos >> kCanTxQueueShift); /* get the queue element where to set the flag */
    elementBitIdx  = (CanSignedTxHandle)(queueBitPos & kCanTxQueueMask);   /* get the flag index wihtin the queue element */
    if( (canTxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) != (tCanQueueElementType)0 )
    {
    /* KB end CanHL_TxQueueIfTxRequest */
      /* KB begin CanHL_TxQueueRemoveTxRequest */
      canTxQueueFlags[queueElementIdx] &= ~CanShiftLookUp[elementBitIdx]; /* clear flag from the queue */
      /* KB end CanHL_TxQueueRemoveTxRequest */
      APPLCANCANCELNOTIFICATION(channel, txHandle);
    }
# endif

# if defined( C_ENABLE_TX_FULLCAN_OBJECTS )
    logTxObjHandle = (CanObjectHandle)((vsintx)CanGetTxHwObj(txHandle) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));
# else
    logTxObjHandle = (CanObjectHandle)((vsintx)CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));
# endif/* C_ENABLE_TX_FULLCAN_OBJECTS */
    if (canHandleCurTxObj[logTxObjHandle] == txHandle)
    {
      canHandleCurTxObj[logTxObjHandle] = kCanBufferCancel;

      /* ##RI1.4 - 1.6: CanCancelTransmit and CanCancelMsgTransmit */
# if defined( C_ENABLE_CANCEL_IN_HW )
#  if defined( C_ENABLE_TX_FULLCAN_OBJECTS )
      txObjHandle = CanGetTxHwObj(txHandle);
#  else
      txObjHandle = CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel);
#  endif /* C_ENABLE_TX_FULLCAN_OBJECTS */
      /* KB begin CanLL_CancelInHw */
      {
        CanDeclarePointerToCanHardware;
      #if defined( C_ENABLE_HW_LOOP_TIMER )
        vuint8 canTimerResult;
      #endif
      
        CanSetPointerToCanHardware;
      
        APPLCANTIMERSTART(kCanLoopBusyReq);
      
        do{
            CANTIMERRESULT_UPDATE(kCanLoopBusyReq);
      
          } WHILE_CONDITON( ((IF_TRANSMIT.ComRequest & kIFxBusy) == kIFxBusy) );
      
        APPLCANTIMEREND(kCanLoopBusyReq);
      
        /* clear the Tx-Request */
        if(CAN_INDIV_POLLING(channel,hwObjHandle) != 0)
        {
          IF_TRANSMIT.MessageCntrl    =  kSetEoB;
        }
        else
        {
          IF_TRANSMIT.MessageCntrl    =  kSetEoB | kSetEnableTxCanInt;
        }
      
        IF_TRANSMIT.ComRequest    =  txObjHandle + 1;
      
        /* clear the Softwareflag */
        if (txObjHandle < 32)
        {
          TX_SEND_FLAG(channel,0) &= ~((vuint32)0x1<<(txObjHandle));
        }
        else
        {
          TX_SEND_FLAG(channel,1) &= ~((vuint32)0x1<<(txObjHandle-32));
        }
      
        ApplCanTxCancelInHwStart(logTxObjHandle); 
      }
      /* KB end CanLL_CancelInHw */
# endif /* C_ENABLE_CANCEL_IN_HW */
      APPLCANCANCELNOTIFICATION(channel, txHandle);
    }

    CanNestedGlobalInterruptRestore();
  } /* if (txHandle < kCanNumberOfTxObjects) */
}
/* CODE CATEGORY 3 END*/
# endif /* defined( C_ENABLE_CAN_CANCEL_TRANSMIT ) */

#endif /* if defined( C_ENABLE_CAN_TRANSMIT ) */


#if defined( C_ENABLE_MSG_TRANSMIT_CONF_FCT )
/****************************************************************************
| NAME:             CanCancelMsgTransmit
| CALLED BY:        Application
| PRECONDITIONS:    none
| INPUT PARAMETERS: none or channel
| RETURN VALUES:    none
| DESCRIPTION:      delete on Msg-Object
****************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 void C_API_2 CanCancelMsgTransmit( CAN_CHANNEL_CANTYPE_ONLY )
{
  CanDeclareGlobalInterruptOldStatus
  CanObjectHandle  logTxObjHandle;
# if defined( C_ENABLE_CANCEL_IN_HW )
  CanObjectHandle  txObjHandle;    /* ##RI1.4 - 1.6: CanCancelTransmit and CanCancelMsgTransmit */
# endif

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif


  logTxObjHandle = (CanObjectHandle)((vsintx)CAN_HL_HW_MSG_TRANSMIT_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));

  CanNestedGlobalInterruptDisable();
  if (canHandleCurTxObj[logTxObjHandle] == kCanBufferMsgTransmit)
  {
    canHandleCurTxObj[logTxObjHandle] = kCanBufferCancel;

    /* ##RI1.4 - 1.6: CanCancelTransmit and CanCancelMsgTransmit */
# if defined( C_ENABLE_CANCEL_IN_HW )
    txObjHandle = CAN_HL_HW_MSG_TRANSMIT_INDEX(canHwChannel);
    /* KB begin CanLL_CancelInHw */
    {
      CanDeclarePointerToCanHardware;
    #if defined( C_ENABLE_HW_LOOP_TIMER )
      vuint8 canTimerResult;
    #endif
    
      CanSetPointerToCanHardware;
    
      APPLCANTIMERSTART(kCanLoopBusyReq);
    
      do{
          CANTIMERRESULT_UPDATE(kCanLoopBusyReq);
    
        } WHILE_CONDITON( ((IF_TRANSMIT.ComRequest & kIFxBusy) == kIFxBusy) );
    
      APPLCANTIMEREND(kCanLoopBusyReq);
    
      /* clear the Tx-Request */
      if(CAN_INDIV_POLLING(channel,hwObjHandle) != 0)
      {
        IF_TRANSMIT.MessageCntrl    =  kSetEoB;
      }
      else
      {
        IF_TRANSMIT.MessageCntrl    =  kSetEoB | kSetEnableTxCanInt;
      }
    
      IF_TRANSMIT.ComRequest    =  txObjHandle + 1;
    
      /* clear the Softwareflag */
      if (txObjHandle < 32)
      {
        TX_SEND_FLAG(channel,0) &= ~((vuint32)0x1<<(txObjHandle));
      }
      else
      {
        TX_SEND_FLAG(channel,1) &= ~((vuint32)0x1<<(txObjHandle-32));
      }
    
      ApplCanTxCancelInHwStart(logTxObjHandle); 
    }
    /* KB end CanLL_CancelInHw */
# endif
    APPLCANMSGCANCELNOTIFICATION(channel);
  }
  CanNestedGlobalInterruptRestore();
}
/* CODE CATEGORY 3 END*/
#endif


#if defined( C_ENABLE_CAN_TRANSMIT )
# if defined( C_ENABLE_VARIABLE_DLC )
/* CODE CATEGORY 2 START*/
/****************************************************************************
| NAME:             CanTransmitVarDLC
| CALLED BY:        Netmanagement, application
| PRECONDITIONS:    Can driver must be initialized
| INPUT PARAMETERS: Handle to Tx message, DLC of Tx message
| RETURN VALUES:    kCanTxFailed: transmit failed
|                   kCanTxOk    : transmit was succesful
| DESCRIPTION:      If the CAN driver is not ready for send, the application
|                   decide, whether the transmit request is repeated or not.
****************************************************************************/
C_API_1 vuint8 C_API_2 CanTransmitVarDLC(CanTransmitHandle txHandle, vuint8 dlc) C_API_3
{
  assertUser(dlc<(vuint8)9, kCanAllChannels, kErrorTxDlcTooLarge);         /* PRQA S 3109 */
  assertUser(txHandle<kCanNumberOfTxObjects, kCanAllChannels , kErrorTxHdlTooLarge);     /* PRQA S 3109 */

  canTxDLC_RAM[ txHandle ] = (canTxDLC_RAM[ txHandle ] & CanLL_DlcMask) | MK_TX_DLC(dlc);

  return CanTransmit( txHandle );
} /* END OF CanTransmitVarDLC */
/* CODE CATEGORY 2 END*/
# endif   /* C_ENABLE_VARIABLE_DLC */

/****************************************************************************
| NAME:             CanTransmit
| CALLED BY:        application
| PRECONDITIONS:    Can driver must be initialized
| INPUT PARAMETERS: Handle of the transmit object to be send
| RETURN VALUES:    kCanTxFailed: transmit failed
|                   kCanTxOk    : transmit was succesful
| DESCRIPTION:      If the CAN driver is not ready for send, the application
|                   decide, whether the transmit request is repeated or not.
****************************************************************************/
/* CODE CATEGORY 2 START*/

C_API_1 vuint8 C_API_2 CanTransmit(CanTransmitHandle txHandle) C_API_3   /*lint !e14 !e31*/
{
  CanDeclareGlobalInterruptOldStatus

# if !defined( C_ENABLE_TX_POLLING )          ||\
     !defined( C_ENABLE_TRANSMIT_QUEUE )      ||\
     defined( C_ENABLE_TX_FULLCAN_OBJECTS )   ||\
     defined( C_ENABLE_INDIVIDUAL_POLLING )
  CanObjectHandle      txObjHandle;
  CanObjectHandle      logTxObjHandle;
  vuint8             rc;
# endif   /* ! C_ENABLE_TX_POLLING  || ! C_ENABLE_TRANSMIT_QUEUE || C_ENABLE_TX_FULLCAN_OBJECTS || C_ENABLE_INDIVIDUAL_POLLING */
  CAN_CHANNEL_CANTYPE_LOCAL

# if defined( C_ENABLE_TRANSMIT_QUEUE )
  /* KB begin CanHL_LocalParameterTxQueueModifyEntry */
  CanSignedTxHandle queueElementIdx; /* index for accessing the tx queue */
  CanSignedTxHandle elementBitIdx;  /* bit index within the tx queue element */
  CanTransmitHandle queueBitPos;  /* physical bitposition of the handle */
  /* KB end CanHL_LocalParameterTxQueueModifyEntry */
# endif
  /* KB begin CanLL_TransmitLocalParameter */
  /* KB end CanLL_TransmitLocalParameter */



  assertUser(txHandle<kCanNumberOfTxObjects, kCanAllChannels , kErrorTxHdlTooLarge);      /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);          /*lint !e661*/
# endif

# if defined( C_ENABLE_MULTI_ECU_PHYS )
  assertUser(((CanTxIdentityAssignment[txHandle] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk)0 ), channel , kErrorDisabledTxMessage);    /* PRQA S 3109 */
# endif

  /* test offline ---------------------------------------------------------- */
  if ( (canStatus[channel] & kCanTxOn) != kCanTxOn )           /* transmit path switched off */
  {
    return kCanTxFailed;
  }

# if defined( C_ENABLE_PART_OFFLINE )
  if ( (canTxPartOffline[channel] & CanTxSendMask[txHandle]) != (vuint8)0)   /*lint !e661*/ /* CAN off ? */
  {
    return (kCanTxPartOffline);
  }
# endif

# if defined( C_ENABLE_CAN_RAM_CHECK )
  if(canComStatus[channel] == kCanDisableCommunication)
  {
    return(kCanCommunicationDisabled);
  }
# endif

# if defined( C_ENABLE_SLEEP_WAKEUP )
  assertUser(!CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanSleep);    /* PRQA S 3109 */
# endif
  assertUser(!CanLL_HwIsStop(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanStop);      /* PRQA S 3109 */

  /* passive mode ---------------------------------------------------------- */
# if defined( C_ENABLE_ECU_SWITCH_PASS )
  if ( canPassive[channel] != (vuint8)0)                             /*  set passive ? */
  {
#  if defined( C_ENABLE_CAN_TX_CONF_FCT ) || \
      defined( C_ENABLE_CONFIRMATION_FCT )
    CAN_CAN_INTERRUPT_DISABLE(CAN_CHANNEL_CANPARA_ONLY);      /* avoid CAN Rx interruption */
#  endif

#  if defined( C_ENABLE_CAN_TX_CONF_FCT )
/* ##RI-1.10 Common Callbackfunction in TxInterrupt */
    txInfoStructConf[channel].Handle  = txHandle;
    /* KB begin CanLL_AddTxConfStructMember */
    /* KB end CanLL_AddTxConfStructMember */
    APPL_CAN_TX_CONFIRMATION(&txInfoStructConf[channel]);
#  endif

#  if defined( C_ENABLE_CONFIRMATION_FLAG )       /* set transmit ready flag  */
#   if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptDisable();
#   endif
    CanConfirmationFlags._c[CanGetConfirmationOffset(txHandle)] |= CanGetConfirmationMask(txHandle);      /*lint !e661*/
#   if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptRestore();
#   endif
#  endif

#  if defined( C_ENABLE_CONFIRMATION_FCT )
    {
#   if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
#   else
      if ( CanGetApplConfirmationPtr(txHandle) != V_NULL )
#   endif
      {
         (CanGetApplConfirmationPtr(txHandle))(txHandle);   /* call completion routine  */
      }
    }
#  endif /* C_ENABLE_CONFIRMATION_FCT */

#  if defined( C_ENABLE_CAN_TX_CONF_FCT ) || \
      defined( C_ENABLE_CONFIRMATION_FCT )
    CAN_CAN_INTERRUPT_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
#  endif

    return kCanTxOk;
  }
# endif


   /* can transmit enabled ================================================== */

   /* ----------------------------------------------------------------------- */
   /* ---  transmit queue with one objects ---------------------------------- */
   /* ---  transmit using fullcan objects ----------------------------------- */
   /* ----------------------------------------------------------------------- */

#  if !defined( C_ENABLE_TX_POLLING )          ||\
      !defined( C_ENABLE_TRANSMIT_QUEUE )      ||\
      defined( C_ENABLE_TX_FULLCAN_OBJECTS )   ||\
      defined( C_ENABLE_INDIVIDUAL_POLLING )

#   if defined( C_ENABLE_TX_FULLCAN_OBJECTS )
  txObjHandle = CanGetTxHwObj(txHandle);    /*lint !e661*/
#   else
  txObjHandle = CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel);                                          /* msg in object 0 */
#   endif

  logTxObjHandle = (CanObjectHandle)((vsintx)txObjHandle + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));
#  endif   /* ! C_ENABLE_TX_POLLING  || ! C_ENABLE_TRANSMIT_QUEUE || C_ENABLE_TX_FULLCAN_OBJECTS || C_ENABLE_INDIVIDUAL_POLLING */

  CanNestedGlobalInterruptDisable();
 
  /* test offline after interrupt disable ---------------------------------- */
  if ( (canStatus[channel] & kCanTxOn) != kCanTxOn )                /* transmit path switched off */
  {
    CanNestedGlobalInterruptRestore();
    return kCanTxFailed;
  }

# if defined( C_ENABLE_TRANSMIT_QUEUE )
#  if defined( C_ENABLE_TX_FULLCAN_OBJECTS )  ||\
      !defined( C_ENABLE_TX_POLLING )         ||\
      defined( C_ENABLE_INDIVIDUAL_POLLING )
  if (
#   if defined( C_ENABLE_TX_FULLCAN_OBJECTS )
       (txObjHandle == CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel))                                   /*disabled - lint !e774 */
#   endif
#   if defined( C_ENABLE_TX_FULLCAN_OBJECTS )  &&\
       ( !defined( C_ENABLE_TX_POLLING )         ||\
          defined( C_ENABLE_INDIVIDUAL_POLLING ) )
     &&
#   endif

#   if defined( C_ENABLE_TX_POLLING )
#    if defined( C_ENABLE_INDIVIDUAL_POLLING )
       ( ( CanHwObjIndivPolling[CAN_HWOBJINDIVPOLLING_INDEX0][txObjHandle] != (vuint8)0 )       /* Object is used in polling mode! */
                         || (canHandleCurTxObj[logTxObjHandle] != kCanBufferFree) )    /* MsgObj used?  */
#    else
        /* write always to queue; transmission is started out of TxTask */
#    endif
#   else
       ( canHandleCurTxObj[logTxObjHandle] != kCanBufferFree)    /* MsgObj used?  */
#   endif
     )
#  endif   /*  ( C_ENABLE_TX_FULLCAN_OBJECTS )  || !( C_ENABLE_TX_POLLING ) || ( C_ENABLE_INDIVIDUAL_POLLING ) */

    {
      /* tx object 0 used -> set msg in queue: -----------------------------*/
      /* KB begin CanHL_TxQueueNewEntry */
      queueBitPos  = txHandle + CAN_HL_TXQUEUE_PADBITS(channel);
      queueElementIdx = (CanSignedTxHandle)(queueBitPos >> kCanTxQueueShift); /* get the queue element where to set the flag */
      elementBitIdx  = (CanSignedTxHandle)(queueBitPos & kCanTxQueueMask);   /* get the flag index wihtin the queue element */
      canTxQueueFlags[queueElementIdx] |= CanShiftLookUp[elementBitIdx];
      /* KB end CanHL_TxQueueNewEntry */
      CanNestedGlobalInterruptRestore();
      return kCanTxOk;                          
  }
# endif  /* C_ENABLE_TRANSMIT_QUEUE */

# if !defined( C_ENABLE_TX_POLLING )          ||\
     !defined( C_ENABLE_TRANSMIT_QUEUE )      ||\
     defined( C_ENABLE_TX_FULLCAN_OBJECTS )   ||\
     defined( C_ENABLE_INDIVIDUAL_POLLING )

#  if defined( C_ENABLE_TRANSMIT_QUEUE )    && \
      ( defined( C_ENABLE_TX_FULLCAN_OBJECTS )  ||\
        !defined( C_ENABLE_TX_POLLING )         ||\
        defined( C_ENABLE_INDIVIDUAL_POLLING )  )
  else
#  endif
  {
  /* check for transmit message object free ---------------------------------*/
    if (( canHandleCurTxObj[logTxObjHandle] != kCanBufferFree)    /* MsgObj used?  */
       || ( !CanLL_TxIsHWObjFree( canHwChannel, txObjHandle ) )

      /* hareware-txObject is not free --------------------------------------*/
       )  /* end of if question */

    {  /* object used */
      /* tx object n used, quit with error */
      CanNestedGlobalInterruptRestore();
      return kCanTxFailed;
    }
  }

  /* Obj, pMsgObject points to is free, transmit msg object: ----------------*/
  canHandleCurTxObj[logTxObjHandle] = txHandle;/* Save hdl of msgObj to be transmitted*/
  CanNestedGlobalInterruptRestore();

  rc = CanCopyDataAndStartTransmission( CAN_CHANNEL_CANPARA_FIRST txObjHandle, txHandle);

#  if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
  if ( rc == kCanTxNotify)
  {
    rc = kCanTxFailed;      /* ignore notification if calls of CanCopy.. is performed within CanTransmit */
  }
#  endif


  return(rc);

# else   /* ! C_ENABLE_TX_POLLING  || ! C_ENABLE_TRANSMIT_QUEUE || C_ENABLE_TX_FULLCAN_OBJECTS || C_ENABLE_INDIVIDUAL_POLLING */
# endif   /* ! C_ENABLE_TX_POLLING  || ! C_ENABLE_TRANSMIT_QUEUE || C_ENABLE_TX_FULLCAN_OBJECTS || C_ENABLE_INDIVIDUAL_POLLING */

} /* END OF CanTransmit */
/* CODE CATEGORY 2 END*/


/****************************************************************************
| NAME:             CanCopyDataAndStartTransmission
| CALLED BY:        CanTransmit, CanHl_RestartTxQueue and CanHL_TxConfirmation
| PRECONDITIONS:    - Can driver must be initialized
|                   - canTxCurHandle[logTxObjHandle] must be set
|                   - the hardwareObject (txObjHandle) must be free
| INPUT PARAMETERS: txHandle: Handle of the transmit object to be send
|                   txObjHandle:  Nr of the HardwareObjects to use
| RETURN VALUES:    kCanTxFailed: transmit failed
|                   kCanTxOk    : transmit was succesful
| DESCRIPTION:      If the CAN driver is not ready for send, the application
|                   decide, whether the transmit request is repeated or not.
****************************************************************************/
/* PRQA S 2001 ++ */    /* suppress misra message about usage of goto */
/* CODE CATEGORY 1 START*/
static vuint8 CanCopyDataAndStartTransmission( CAN_CHANNEL_CANTYPE_FIRST CanObjectHandle txObjHandle, CanTransmitHandle txHandle) C_API_3   /*lint !e14 !e31*/
{
   CanDeclareGlobalInterruptOldStatus
   vuint8             rc;
   CanObjectHandle      logTxObjHandle;
#  if defined( C_ENABLE_COPY_TX_DATA )  
   TxDataPtr   CanMemCopySrcPtr;
#  endif
# if defined( C_ENABLE_DYN_TX_OBJECTS )
   CanTransmitHandle    dynTxObj;
# endif /* C_ENABLE_DYN_TX_OBJECTS */
# if defined( C_ENABLE_PRETRANSMIT_FCT )
   CanTxInfoStruct      txStruct;
# endif

   /* KB begin CanLL_TxTransmissionLocalParameter */
   #if defined( C_ENABLE_HW_LOOP_TIMER )
   vuint8 canTimerResult;
   #endif
   
   CanDeclarePointerToCanHardware;
   CanSetPointerToCanHardware; 
   
   /* KB end CanLL_TxTransmissionLocalParameter */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
   assertInternal(channel < kCanNumberOfChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);      /* PRQA S 3109 */
# endif
   assertInternal(txHandle < kCanNumberOfTxObjects, kCanAllChannels , kErrorInternalTxHdlTooLarge);        /* PRQA S 3109 */

# if defined( C_ENABLE_DYN_TX_OBJECTS )
#  if ( kCanNumberOfTxStatObjects == 0)
   dynTxObj = txHandle;               /* only dynamic messages are used */
#  else   /* ( kCanNumberOfTxStatObjects == 0) */
   /* dynamic and static messages are in the system */
   if (txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel))
   {
     dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel);    /* PRQA S 3382,0291 */
   }
   else
   {
     dynTxObj = kCanTxHandleNotUsed;
   }
#  endif /* ( kCanNumberOfTxStatObjects == 0) */
# endif /* C_ENABLE_DYN_TX_OBJECTS */

   assertInternal(txObjHandle < CAN_HL_HW_TX_STOPINDEX(canHwChannel), channel, kErrorTxObjHandleWrong);      /* PRQA S 3109 */
   logTxObjHandle = (CanObjectHandle)((vsintx)txObjHandle + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));

   assertHardware( CanLL_TxIsHWObjFree( canHwChannel, txObjHandle ), channel, kErrorTxBufferBusy);          /* PRQA S 3109 */

   /* KB begin CanLL_TxBegin */
   #if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   txObjHandle = txObjHandle;
   #endif
   /* KB end CanLL_TxBegin */

   /* set id and dlc  -------------------------------------------------------- */
   {
# if defined( C_ENABLE_DYN_TX_DLC ) || \
      defined( C_ENABLE_DYN_TX_ID )
     if (dynTxObj < kCanNumberOfTxDynObjects)
     {           /* set dynamic part of dynamic objects ----------------------*/
#  if defined( C_ENABLE_DYN_TX_ID )
        /* KB begin CanLL_TxSetId */
        #if defined( C_ENABLE_EXTENDED_ID )
        TX_MSGOBJ_ID_LOW(logTxObjHandle)  = (vuint16)canDynTxId1[dynTxObj];
        #endif
        TX_MSGOBJ_ID_HIGH(logTxObjHandle) = (vuint16)canDynTxId0[dynTxObj]  | kSetMsgVal | kSetDir;
        /* KB end CanLL_TxSetId */
#  endif
 
#  if defined( C_ENABLE_DYN_TX_DLC )
        /* KB begin CanLL_TxSetDlc */
        TX_MSGOBJ_DLC(logTxObjHandle) = (canDynTxDLC[dynTxObj]);
        /* KB end CanLL_TxSetDlc */
#  endif
     }
     else
     {          /* set part of static objects assocciated the dynamic --------*/
#  if defined( C_ENABLE_DYN_TX_ID )
#   if defined( C_ENABLE_TX_MASK_EXT_ID )
#    if defined( C_ENABLE_MIXED_ID )
        if (CanGetTxIdType(txHandle)==kCanIdTypeStd)
        {
          /* KB begin CanLL_TxSetId */
          #if defined( C_ENABLE_EXTENDED_ID )
          TX_MSGOBJ_ID_LOW(logTxObjHandle)  = (vuint16)CanGetTxId1(txHandle);
          #endif
          TX_MSGOBJ_ID_HIGH(logTxObjHandle) = (vuint16)CanGetTxId0(txHandle)  | kSetMsgVal | kSetDir;
          /* KB end CanLL_TxSetId */
        }
        else
#    endif
        {
          /* mask extened ID */
          /* KB begin CanLL_TxSetId */
          #if defined( C_ENABLE_EXTENDED_ID )
          TX_MSGOBJ_ID_LOW(logTxObjHandle)  = (vuint16)(CanGetTxId1(txHandle)|canTxMask1[channel]);
          #endif
          TX_MSGOBJ_ID_HIGH(logTxObjHandle) = (vuint16)(CanGetTxId0(txHandle)|canTxMask0[channel])  | kSetMsgVal | kSetDir;
          /* KB end CanLL_TxSetId */
        }
#   else
        /* KB begin CanLL_TxSetId */
        #if defined( C_ENABLE_EXTENDED_ID )
        TX_MSGOBJ_ID_LOW(logTxObjHandle)  = (vuint16)CanGetTxId1(txHandle);
        #endif
        TX_MSGOBJ_ID_HIGH(logTxObjHandle) = (vuint16)CanGetTxId0(txHandle)  | kSetMsgVal | kSetDir;
        /* KB end CanLL_TxSetId */
#   endif
#  endif

#  if defined( C_ENABLE_DYN_TX_DLC )
#   if defined( C_ENABLE_VARIABLE_DLC )
        /* init DLC, RAM */
        /* KB begin CanLL_TxSetDlc */
        TX_MSGOBJ_DLC(logTxObjHandle) = (canTxDLC_RAM[txHandle]);
        /* KB end CanLL_TxSetDlc */
#   else
        /* init DLC, ROM */
        /* KB begin CanLL_TxSetDlc */
        TX_MSGOBJ_DLC(logTxObjHandle) = CanGetTxDlc(txHandle);
        /* KB end CanLL_TxSetDlc */
#   endif
#  endif
     }
# endif
     /* set static part commen for static and dynamic objects ----------------*/
# if defined( C_ENABLE_DYN_TX_ID )
# else
#  if defined( C_ENABLE_TX_MASK_EXT_ID )
#   if defined( C_ENABLE_MIXED_ID )
     if (CanGetTxIdType(txHandle)==kCanIdTypeStd)
     {
       /* KB begin CanLL_TxSetId */
       #if defined( C_ENABLE_EXTENDED_ID )
       TX_MSGOBJ_ID_LOW(logTxObjHandle)  = (vuint16)CanGetTxId1(txHandle);
       #endif
       TX_MSGOBJ_ID_HIGH(logTxObjHandle) = (vuint16)CanGetTxId0(txHandle)  | kSetMsgVal | kSetDir;
       /* KB end CanLL_TxSetId */
     }
     else
#   endif
     {
       /* mask extened ID */
       /* KB begin CanLL_TxSetId */
       #if defined( C_ENABLE_EXTENDED_ID )
       TX_MSGOBJ_ID_LOW(logTxObjHandle)  = (vuint16)(CanGetTxId1(txHandle)|canTxMask1[channel]);
       #endif
       TX_MSGOBJ_ID_HIGH(logTxObjHandle) = (vuint16)(CanGetTxId0(txHandle)|canTxMask0[channel])  | kSetMsgVal | kSetDir;
       /* KB end CanLL_TxSetId */
     }
#  else
     /* KB begin CanLL_TxSetId */
     #if defined( C_ENABLE_EXTENDED_ID )
     TX_MSGOBJ_ID_LOW(logTxObjHandle)  = (vuint16)CanGetTxId1(txHandle);
     #endif
     TX_MSGOBJ_ID_HIGH(logTxObjHandle) = (vuint16)CanGetTxId0(txHandle)  | kSetMsgVal | kSetDir;
     /* KB end CanLL_TxSetId */
#  endif
# endif
# if defined( C_ENABLE_DYN_TX_DLC )
# else
#  if defined( C_ENABLE_VARIABLE_DLC )
     /* init DLC, RAM */
     /* KB begin CanLL_TxSetDlc */
     TX_MSGOBJ_DLC(logTxObjHandle) = (canTxDLC_RAM[txHandle]);
     /* KB end CanLL_TxSetDlc */
#  else
     /* init DLC, ROM */
     /* KB begin CanLL_TxSetDlc */
     TX_MSGOBJ_DLC(logTxObjHandle) = CanGetTxDlc(txHandle);
     /* KB end CanLL_TxSetDlc */
#  endif
# endif

# if defined( C_ENABLE_MIXED_ID )
#  if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#  else
#   if defined( C_ENABLE_DYN_TX_DLC ) || \
       defined( C_ENABLE_DYN_TX_ID )
     if (dynTxObj < kCanNumberOfTxDynObjects)
     {                      /* set dynamic part of dynamic objects */
#    if defined( C_ENABLE_DYN_TX_ID )
       /* KB begin CanLL_TxSetIdType */
       /* KB end CanLL_TxSetIdType */
#    else
       /* KB begin CanLL_TxSetIdType */
       /* KB end CanLL_TxSetIdType */
#    endif
     }
#   else
#   endif
#  endif
# endif

   }


 /* call pretransmit function ----------------------------------------------- */
# if defined( C_ENABLE_PRETRANSMIT_FCT )

   /* pointer needed for other modules */
   /* KB begin CanLL_TxGetCANDataPtr */
   (txStruct.pChipData) = (CanChipDataPtr)TX_MSGOBJ_UCDATA(logTxObjHandle);
   /* KB end CanLL_TxGetCANDataPtr */
   canRDSTxPtr[logTxObjHandle] = txStruct.pChipData;
   txStruct.Handle      = txHandle;

   {  
#  if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
#  else
    /* Is there a PreTransmit function ? ------------------------------------- */ 
    if ( CanGetApplPreTransmitPtr(txHandle) != V_NULL )    /* if PreTransmit exists */ 
#  endif
    { 
      if ( (CanGetApplPreTransmitPtr(txHandle)) (txStruct) == kCanNoCopyData)  
      { 
      
        /* KB begin CanLL_TxPretransmitCopyToCan */
        /* KB end CanLL_TxPretransmitCopyToCan */
        
        /* Do not copy the data - already done by the PreTransmit-function */  
        /* --- start transmission --- */  
        goto startTransmission; 
      } 
    } 
   }  
# endif /* C_ENABLE_PRETRANSMIT_FCT */

 /* copy data --------------------------------------------------------------- */
# if defined( C_ENABLE_COPY_TX_DATA )  
#  if defined( C_ENABLE_DYN_TX_DATAPTR )  
   if (dynTxObj < kCanNumberOfTxDynObjects)  
   {  
      CanMemCopySrcPtr = canDynTxDataPtr[dynTxObj];  
   }  
   else  
#  endif  
   {  
     CanMemCopySrcPtr = CanGetTxDataPtr(txHandle);  
   }  
 /* copy via index in MsgObj data field, copy always 8 bytes -----------*/  
   if ( CanMemCopySrcPtr != V_NULL )   /* copy if buffer exists */
   {
#  if C_SECURITY_LEVEL > 10
     CanNestedGlobalInterruptDisable();  
#  endif

     /* KB begin CanLL_TxCopyToCan */
     {
       vuint16 copy_counter;
     
       for(copy_counter=0; copy_counter<8; copy_counter++)
       {
         txMsgObj[logTxObjHandle].Data.ucData[copy_counter] = *CanMemCopySrcPtr;
         CanMemCopySrcPtr++;
       }
     }
     
     /* KB end CanLL_TxCopyToCan */

#  if C_SECURITY_LEVEL > 10
     CanNestedGlobalInterruptRestore();  
#  endif
   }
# endif /* ( C_ENABLE_COPY_TX_DATA ) */  

   CANDRV_SET_CODE_TEST_POINT(0x10A);

# if defined( C_ENABLE_PRETRANSMIT_FCT )
/* Msg(4:2015) This label is not a case or default label for a switch statement. MISRA Rule 55 */
startTransmission:
# endif

   /* test offline and handle and start transmission ------------------------ */
   CanNestedGlobalInterruptDisable();  
   /* If CanTransmit was interrupted by a re-initialization or CanOffline */  
   /* no transmitrequest of this action should be started      */  
   if ((canHandleCurTxObj[logTxObjHandle] == txHandle) && ((canStatus[channel] & kCanTxOn) == kCanTxOn))
   {  
     /* KB begin CanLL_TxStart */
     CanSetPointerToCanHardware;
     
     APPLCANTIMERSTART(kCanLoopBusyReq);
     
     do{
         CANTIMERRESULT_UPDATE(kCanLoopBusyReq);
     
       } WHILE_CONDITON( ((IF_TRANSMIT.ComRequest & kIFxBusy) == kIFxBusy) );
     
     APPLCANTIMEREND(kCanLoopBusyReq);
     
     
     /* WrRd,Mask,Arb,Control,DataA,DataB set */
     IF_TRANSMIT.ComMask         =  kSetWrRd | kSetMask | kSetArb | kSetControl | kSetDataA | kSetDataB;
     
     /* copy ID, Dlc and Data from the MsgObjectBuffer in IF1 */ 
     
     #if defined( C_ENABLE_EXTENDED_ID )
     IF_TRANSMIT.ArbitrFld1      =  TX_MSGOBJ_ID_LOW(logTxObjHandle);
     #endif
     IF_TRANSMIT.ArbitrFld2      =  TX_MSGOBJ_ID_HIGH(logTxObjHandle);
     
     #if defined (C_ENABLE_INDIVIDUAL_POLLING)     
     /* set Dlc and TxRqst */
     if(CAN_INDIV_POLLING(channel, txObjHandle) != 0)
     {
       IF_TRANSMIT.MessageCntrl  =  TX_MSGOBJ_DLC(logTxObjHandle) | kSetTxRqst | kSetEoB;
     }
     else
     {
       IF_TRANSMIT.MessageCntrl  =  TX_MSGOBJ_DLC(logTxObjHandle) | kSetTxRqst | kSetEoB | kSetEnableTxCanInt;
     }
     #else     
     # if defined (C_ENABLE_TX_POLLING)     
      IF_TRANSMIT.MessageCntrl  =  TX_MSGOBJ_DLC(logTxObjHandle) | kSetTxRqst | kSetEoB;
     # else
      IF_TRANSMIT.MessageCntrl  =  TX_MSGOBJ_DLC(logTxObjHandle) | kSetTxRqst | kSetEoB | kSetEnableTxCanInt;
     # endif /* C_ENABLE_TX_POLLING */
     #endif /* C_ENABLE_INDIVIDUAL_POLLING */
     
     #if defined(C_CPUTYPE_BIGENDIAN)
     IF_TRANSMIT.Data.ucData[0]  =  txMsgObj[logTxObjHandle].Data.ucData[3]; 
     IF_TRANSMIT.Data.ucData[1]  =  txMsgObj[logTxObjHandle].Data.ucData[2]; 
     IF_TRANSMIT.Data.ucData[2]  =  txMsgObj[logTxObjHandle].Data.ucData[1]; 
     IF_TRANSMIT.Data.ucData[3]  =  txMsgObj[logTxObjHandle].Data.ucData[0]; 
     IF_TRANSMIT.Data.ucData[4]  =  txMsgObj[logTxObjHandle].Data.ucData[7]; 
     IF_TRANSMIT.Data.ucData[5]  =  txMsgObj[logTxObjHandle].Data.ucData[6]; 
     IF_TRANSMIT.Data.ucData[6]  =  txMsgObj[logTxObjHandle].Data.ucData[5]; 
     IF_TRANSMIT.Data.ucData[7]  =  txMsgObj[logTxObjHandle].Data.ucData[4]; 
     #endif
     
     
     /* start copy data from IF1 to ObjectRAM */
     IF_TRANSMIT.ComRequest      =  txObjHandle + 1;
     
     if (txObjHandle < 32)
     {
       TX_SEND_FLAG(channel,0) |= ((vuint32)0x1<<(txObjHandle));
     }
     else
     {
       TX_SEND_FLAG(channel,1) |= ((vuint32)0x1<<(txObjHandle-32));
     }
     /* KB end CanLL_TxStart */

# if defined( C_ENABLE_TX_OBSERVE )
     ApplCanTxObjStart( CAN_CHANNEL_CANPARA_FIRST logTxObjHandle );
# endif
     rc = kCanTxOk;                                    
   }  
   else  
   {  
# if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
     if (canHandleCurTxObj[logTxObjHandle] == txHandle)
     {
       /* only CanOffline was called on higher level */
       rc = kCanTxNotify;
     }
     else
# endif
     {
       rc = kCanTxFailed;   
     }
     assertInternal((canHandleCurTxObj[logTxObjHandle] == txHandle) || (canHandleCurTxObj[logTxObjHandle] == kCanBufferFree),
                                                                                       channel, kErrorTxHandleWrong);  /* PRQA S 3109 */
     canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;  /* release TxHandle (CanOffline) */
   }  

   CanNestedGlobalInterruptRestore();

   /* KB begin CanLL_TxEnd */
   /* KB end CanLL_TxEnd */
   
   return (rc);   

} /* END OF CanCopyDataAndStartTransmission */
/* CODE CATEGORY 1 END*/
/* PRQA S 2001 ++ */    /* suppress misra message about usage of goto */
#endif /* if defined( C_ENABLE_CAN_TRANSMIT ) */


#if defined( C_ENABLE_TX_POLLING ) || \
    defined( C_ENABLE_RX_FULLCAN_POLLING )  || \
    defined( C_ENABLE_RX_BASICCAN_POLLING ) || \
    defined( C_ENABLE_ERROR_POLLING ) || \
    defined( C_ENABLE_WAKEUP_POLLING ) || \
    (defined( C_HL_ENABLE_CANCEL_IN_HW_TASK ) && defined( C_ENABLE_CANCEL_IN_HW ))
/****************************************************************************
| NAME:             CanTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling error bus off
|                   - polling Tx objects
|                   - polling Rx objects
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanTask(void)
{
  CAN_CHANNEL_CANTYPE_LOCAL

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  for (channel = 0; channel < kCanNumberOfChannels; channel++)
# endif
  {
    {
# if defined( C_ENABLE_ERROR_POLLING )
      CanErrorTask(CAN_CHANNEL_CANPARA_ONLY);
# endif

# if defined( C_ENABLE_SLEEP_WAKEUP )
#  if defined( C_ENABLE_WAKEUP_POLLING )
      CanWakeUpTask(CAN_CHANNEL_CANPARA_ONLY);
#  endif
# endif

# if defined( C_ENABLE_TX_POLLING ) || \
     (defined( C_HL_ENABLE_CANCEL_IN_HW_TASK )  && defined( C_ENABLE_CANCEL_IN_HW ))
      CanTxTask(CAN_CHANNEL_CANPARA_ONLY);
# endif

# if defined( C_ENABLE_RX_FULLCAN_POLLING ) && \
     defined( C_ENABLE_RX_FULLCAN_OBJECTS )
      CanRxFullCANTask(CAN_CHANNEL_CANPARA_ONLY);
# endif

# if defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && \
    defined( C_ENABLE_RX_BASICCAN_POLLING )
      CanRxBasicCANTask(CAN_CHANNEL_CANPARA_ONLY);
# endif
    }
  }
}
/* CODE CATEGORY 2 END*/
#endif

#if defined( C_ENABLE_ERROR_POLLING )
/****************************************************************************
| NAME:             CanErrorTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling error status
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanErrorTask( CAN_CHANNEL_CANTYPE_ONLY )
{

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);     /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;

    {
# if defined( C_ENABLE_SLEEP_WAKEUP )
      if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY))
# endif
      {
        CAN_CAN_INTERRUPT_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
        CanHL_ErrorHandling(CAN_HW_CHANNEL_CANPARA_ONLY);
        CAN_CAN_INTERRUPT_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
      }
    }

    canPollingTaskActive[channel] = 0;
  }
}
/* CODE CATEGORY 2 END*/
#endif

#if defined( C_ENABLE_SLEEP_WAKEUP )
# if defined( C_ENABLE_WAKEUP_POLLING )
/****************************************************************************
| NAME:             CanWakeUpTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling CAN wakeup event
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanWakeUpTask(CAN_CHANNEL_CANTYPE_ONLY)
{
  CanDeclareGlobalInterruptOldStatus
  /* KB begin CanLL_WakeUpTaskLocalParameter */
  CanDeclarePointerToCanHardware;
  /* KB end CanLL_WakeUpTaskLocalParameter */

#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#  endif
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);    /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;

    /* KB begin CanLL_if_WakeUpOccured */
    pCanNode = CAN_BASIS_ADR(Controller);
       
    CAN_LL_STATUS(Controller) |= (STATREG & (kErrBusOff | kWakeupPending));
    
    if ((CAN_LL_STATUS(Controller) & kWakeupPending) == kWakeupPending)
    {
      CAN_LL_STATUS(Controller) &= ~kWakeupPending;  
    /* KB end CanLL_if_WakeUpOccured */
      CANDRV_SET_CODE_TEST_POINT(0x111);
      CanNestedGlobalInterruptDisable();          /* ESCAN00021223 */
      CanLL_WakeUpHandling(CAN_CHANNEL_CANPARA_ONLY);
      CanNestedGlobalInterruptRestore();          /* ESCAN00021223 */
    }
    canPollingTaskActive[channel] = 0;
  }
}
/* CODE CATEGORY 2 END*/
# endif /* C_ENABLE_WAKEUP_POLLING */
#endif /* C_ENABLE_SLEEP_WAKEUP */

#if defined( C_ENABLE_TX_POLLING ) || \
    (defined( C_HL_ENABLE_CANCEL_IN_HW_TASK )  && defined( C_ENABLE_CANCEL_IN_HW ))
/****************************************************************************
| NAME:             CanTxTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling Tx objects
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanTxTask( CAN_CHANNEL_CANTYPE_ONLY ) C_API_3
{
  CanObjectHandle      txObjHandle;

  /* KB begin CanLL_TxTaskLocalParameter */
  #if defined( C_ENABLE_TX_POLLING )
    CanDeclarePointerToCanHardware;
    vuint8  can_transrequest;
  #endif
  /* KB end CanLL_TxTaskLocalParameter */


# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);    /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;


# if defined( C_ENABLE_SLEEP_WAKEUP )
    if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY))
# endif
    {
      /*--  polling Tx objects ----------------------------------------*/

# if defined( C_ENABLE_TX_POLLING )
      /* check for global confirmation Pending and may be reset global pending confirmation */
      /* KB begin CanLL_if_TxIsGlobalConfPending */
      {
      CanSetPointerToCanHardware;
      /* KB end CanLL_if_TxIsGlobalConfPending */
        for ( txObjHandle = CAN_HL_HW_TX_STARTINDEX(canHwChannel); txObjHandle < CAN_HL_HW_TX_STOPINDEX(canHwChannel) ; txObjHandle++ )
        {
#  if defined( C_ENABLE_INDIVIDUAL_POLLING )
          if ( CanHwObjIndivPolling[CAN_HWOBJINDIVPOLLING_INDEX0][txObjHandle] != (vuint8)0 )
#  endif
          {
            /* check for dedicated confirmation pending */
            /* KB begin CanLL_if_TxIsObjConfPending */
            CanDeclareGlobalInterruptOldStatus
            CanSetPointerToCanHardware;
            can_transrequest = 0;
            
            CanNestedGlobalInterruptDisable();
            if (txObjHandle < 32)
            {
              if (TX_SEND_FLAG(channel,0) != 0)
              {
                if ( ((TRANSREQUEST(0)         & ((vuint32)0x1<<(txObjHandle))) == 0) && \
                     ((TX_SEND_FLAG(channel,0) & ((vuint32)0x1<<(txObjHandle))) != 0)    )
                  {
                    can_transrequest = 1;
                    TX_SEND_FLAG(channel,0) &= ~((vuint32)0x1<<(txObjHandle));
                  }
              }
            }
            else
            {
              if (TX_SEND_FLAG(channel,1) != 0)
              {
                if ( ((TRANSREQUEST(1)         & ((vuint32)0x1<<(txObjHandle-32))) == 0) && \
                     ((TX_SEND_FLAG(channel,1) & ((vuint32)0x1<<(txObjHandle-32))) != 0)    )
                  {
                    can_transrequest = 1;
                    TX_SEND_FLAG(channel,1) &= ~((vuint32)0x1<<(txObjHandle-32));
                  }
              }
            }
            CanNestedGlobalInterruptRestore();
            
            if (can_transrequest != 0)
            {
            /* KB end CanLL_if_TxIsObjConfPending */
              CANDRV_SET_CODE_TEST_POINT(0x110);
              CAN_CAN_INTERRUPT_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
              /* do tx confirmation */
              CanHL_TxConfirmation(CAN_HW_CHANNEL_CANPARA_FIRST txObjHandle );
              CAN_CAN_INTERRUPT_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
            }
          } /* if individual polling & object has to be polled */
        }
      }
# endif /*( C_ENABLE_TX_POLLING ) */

# if defined( C_ENABLE_CANCEL_IN_HW ) && \
          defined( C_HL_ENABLE_CANCEL_IN_HW_TASK )
      /* search for pending cancelation */
    
      for ( txObjHandle = CAN_HL_HW_TX_STARTINDEX(canHwChannel); txObjHandle < CAN_HL_HW_TX_STOPINDEX(canHwChannel) ; txObjHandle++ )
      {
        /* check for dedicated cancel pending */
        /* KB begin CanLL_if_TxIsObjCanceledAcknowledged */
        if (canHandleCurTxObj[(vsintx)txObjHandle+CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)] == kCanBufferCancel)
        {
          if (ApplCanTxCancelInHwConfirmed(txObjHandle + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)) == 0)
        /* KB end CanLL_if_TxIsObjCanceledAcknowledged */
          canHandleCurTxObj[(vsintx)txObjHandle+ CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)] = kCanBufferFree;     /* release the hardware buffer */
        }
      }
# endif

# if defined( C_ENABLE_TRANSMIT_QUEUE )
      CanHl_RestartTxQueue( CAN_CHANNEL_CANPARA_ONLY );
# endif /*  C_ENABLE_TRANSMIT_QUEUE */

    } /* if ( CanLL_HwIsSleep... ) */

    canPollingTaskActive[channel] = 0;
  }


} /* END OF CanTxTask */
/* CODE CATEGORY 2 END*/
#endif /* C_ENABLE_TX_POLLING */

#if defined( C_ENABLE_TRANSMIT_QUEUE )
# if defined( C_ENABLE_TX_POLLING ) || \
     (defined( C_HL_ENABLE_CANCEL_IN_HW_TASK )  && defined( C_ENABLE_CANCEL_IN_HW ))
/****************************************************************************
| NAME:             CanHl_RestartTxQueue
| CALLED BY:        CanTxTask, via CanLL (TxMsgDestroyed)
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      start transmission if queue entry exists and HW is free
****************************************************************************/
/* CODE CATEGORY 2 START*/
static void CanHl_RestartTxQueue( CAN_CHANNEL_CANTYPE_ONLY )
{
  CanTransmitHandle    txHandle;
#  if  defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
  vuint8             rc;
#  endif
  CanDeclareGlobalInterruptOldStatus

  /* KB begin CanHL_LocalParameterTxQueueRestart */
  CanSignedTxHandle         queueElementIdx;    /* use as signed due to loop */
  CanSignedTxHandle         elementBitIdx;
  tCanQueueElementType             elem;
  /* KB end CanHL_LocalParameterTxQueueRestart */

#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(channel < kCanNumberOfChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);      /* PRQA S 3109 */
#  endif


  if (canHandleCurTxObj[(vsintx)CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)] == kCanBufferFree)
  {
    /* KB begin CanHL_TxQueueIsAnyObjQueuedBegin */
    for(queueElementIdx = CAN_HL_TXQUEUE_STOPINDEX(channel) - (CanSignedTxHandle)1; 
                             queueElementIdx >= CAN_HL_TXQUEUE_STARTINDEX(channel); queueElementIdx--)
    {
      elem = canTxQueueFlags[queueElementIdx];
      if(elem != (tCanQueueElementType)0) /* is there any flag set in the queue element? */
      {
    /* KB end CanHL_TxQueueIsAnyObjQueuedBegin */

        /* Transmit Queued Objects */
        /* KB begin CanHL_TxQueueSearchQueuedTxHandleBegin */
        /* start the bitsearch */
        #if defined( C_CPUTYPE_32BIT )
        if((elem & (tCanQueueElementType)0xFFFF0000) != (tCanQueueElementType)0)
        {
          if((elem & (tCanQueueElementType)0xFF000000) != (tCanQueueElementType)0)
          {
            if((elem & (tCanQueueElementType)0xF0000000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 28] + 28;
            }
            else /*0x0F000000*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 24] + 24;
            }
          }
          else
          {
            if((elem & (tCanQueueElementType)0x00F00000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 20] + 20;
            }
            else /* 0x000F0000*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 16] + 16;
            }
          }
        }
        else
        #endif
        {
        #if defined( C_CPUTYPE_32BIT ) || defined( C_CPUTYPE_16BIT )
          if((elem & (tCanQueueElementType)0x0000FF00) != (tCanQueueElementType)0)
          {
            if((elem & (tCanQueueElementType)0x0000F000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 12] + 12;
            }
            else /*0x00000F00*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 8] + 8;
            }
          }
          else
        #endif
          {
            if((elem & (tCanQueueElementType)0x000000F0) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 4] + 4;
            }
            else /* 0x0000000F*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem];
            }
          }
        }
        txHandle = (CanTransmitHandle)((((CanTransmitHandle)queueElementIdx << kCanTxQueueShift) + (CanTransmitHandle)elementBitIdx) - CAN_HL_TXQUEUE_PADBITS(channel));
        {
        /* KB end CanHL_TxQueueSearchQueuedTxHandleBegin */

            CanNestedGlobalInterruptDisable();
            if (canHandleCurTxObj[(vsintx)CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)] == kCanBufferFree)
            {
              /* KB begin CanHL_TxQueueVerifyAndRemoveRequest */
              if ( (canTxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) != (tCanQueueElementType)0 )
              {
                canTxQueueFlags[queueElementIdx] &= ~CanShiftLookUp[elementBitIdx]; /* clear flag from the queue */
              /* KB end CanHL_TxQueueVerifyAndRemoveRequest */
                /* Save hdl of msgObj to be transmitted*/
                canHandleCurTxObj[(vsintx)CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)] = txHandle;
                CanNestedGlobalInterruptRestore();  
#  if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
                rc = CanCopyDataAndStartTransmission(CAN_CHANNEL_CANPARA_FIRST CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel), txHandle);
                if ( rc == kCanTxNotify)
                {
                  APPLCANCANCELNOTIFICATION(channel, txHandle);
                }
#  else
                (void)CanCopyDataAndStartTransmission(CAN_CHANNEL_CANPARA_FIRST CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel), txHandle);
#  endif
                return;
              }

            }
            CanNestedGlobalInterruptRestore();
            return;
        /* KB begin CanHL_TxQueueSearchQueuedTxHandleEnd */
        }
        /* KB end CanHL_TxQueueSearchQueuedTxHandleEnd */
    /* KB begin CanHL_TxQueueIsAnyObjQueuedEnd */
      }
    }
    /* KB end CanHL_TxQueueIsAnyObjQueuedEnd */
  }
} /* End of CanHl_RestartTxQueue */
/* CODE CATEGORY 2 END*/
# endif
#endif /*  C_ENABLE_TRANSMIT_QUEUE */

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS ) && \
    defined( C_ENABLE_RX_FULLCAN_POLLING )  
/****************************************************************************
| NAME:             CanRxFullCANTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling Rx FullCAN objects
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanRxFullCANTask(CAN_CHANNEL_CANTYPE_ONLY) C_API_3
{
  /* KB begin CanLL_RxFullCANTaskLocalParameter */
  vuint8 can_newdata;
  CanDeclarePointerToCanHardware;
  /* KB end CanLL_RxFullCANTaskLocalParameter */

  CanObjectHandle     rxObjHandle;        /* keyword register removed 2005-06-29 Ht */


# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
# endif
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);    /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;

    {
# if defined( C_ENABLE_SLEEP_WAKEUP )
      if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY))
# endif
      {
        /*--  polling fullcan Rx objects ----------------------------------------*/

        /* check for global fullCan Rx indication pending and may be reset global */
        /* indication pending */
        /* KB begin CanLL_if_RxFullIsGlobalIndPending */
        {
        CanSetPointerToCanHardware;
        /* KB end CanLL_if_RxFullIsGlobalIndPending */
          for (rxObjHandle=CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel); rxObjHandle<CAN_HL_HW_RX_FULL_STOPINDEX(canHwChannel); rxObjHandle++ )
          {
# if defined( C_ENABLE_INDIVIDUAL_POLLING )
            if ( CanHwObjIndivPolling[CAN_HWOBJINDIVPOLLING_INDEX0][rxObjHandle] != (vuint8)0 )
# endif
            {
              /* check for dedicated indication pending */
              /* KB begin CanLL_if_RxFullIsObjIndPending */
              can_newdata = 0;
              CanSetPointerToCanHardware;
              
              
              if (rxObjHandle < 32)
              {
                if (NEWDATA(0) != 0)
                {
                  if ((NEWDATA(0) & ((vuint32)0x1<<(rxObjHandle))) != 0)
                    can_newdata = 1;
                }
              }
              else
              {
                if ((NEWDATA(1) & 0x3FFFFFFF) != 0)
                {
                  if ((NEWDATA(1) & ((vuint32)0x1<<(rxObjHandle-32))) != 0)
                    can_newdata = 1;
                }
              }
              
              if (can_newdata != 0) 
              {
              /* KB end CanLL_if_RxFullIsObjIndPending */
                CANDRV_SET_CODE_TEST_POINT(0x109);
                CAN_CAN_INTERRUPT_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
                CanFullCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxObjHandle);
                CAN_CAN_INTERRUPT_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
              }
            }  /* if individual polling & object has to be polled */
          } /* for ( txObjHandle ) */
        } /* if (global pending) */
      } /* if ( CanLL_HwIsSleep ... )  */
    }  /* for (all associated HW channel) */
    canPollingTaskActive[channel] = 0;
  }

} /* END OF CanRxTask */
/* CODE CATEGORY 2 END*/
#endif /*  C_ENABLE_RX_FULLCAN_OBJECTS && C_ENABLE_RX_FULLCAN_POLLING */

#if defined( C_ENABLE_RX_BASICCAN_POLLING ) && \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/****************************************************************************
| NAME:             CanRxBasicCANTask
| CALLED BY:        application
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - cyclic Task, 
|                   - polling Rx BasicCAN objects
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanRxBasicCANTask(CAN_CHANNEL_CANTYPE_ONLY) C_API_3
{
  /* KB begin CanLL_RxBasicCANTaskLocalParameter */
  CanDeclarePointerToCanHardware;
  vuint8 can_newdata;
  /* KB end CanLL_RxBasicCANTaskLocalParameter */

  CanObjectHandle     rxObjHandle;          /* keyword register removed 2005-06-29 Ht */


# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);   /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;


# if defined( C_ENABLE_SLEEP_WAKEUP )
    if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY))
# endif
    {

      /* KB begin CanLL_if_RxBasicIsGlobalIndPending */
      {
      CanSetPointerToCanHardware;
      /* KB end CanLL_if_RxBasicIsGlobalIndPending */
        for (rxObjHandle=CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel); rxObjHandle<CAN_HL_HW_RX_BASIC_STOPINDEX(canHwChannel); rxObjHandle++ )
        {
# if defined( C_ENABLE_INDIVIDUAL_POLLING )
          if ( CanHwObjIndivPolling[CAN_HWOBJINDIVPOLLING_INDEX0][rxObjHandle] != (vuint8)0 )
# endif
          {
            /* check for dedicated indication pending */
            /* KB begin CanLL_if_RxBasicIsObjIndPending */
            can_newdata = 0;
            CanSetPointerToCanHardware;
              
            if (rxObjHandle < 32)
            {
              if ((NEWDATA(0) & ((vuint32)0x1<<(rxObjHandle))) != 0)     {can_newdata = 1;}
            }  
            else
            {
              if ((NEWDATA(1) & ((vuint32)0x1<<(rxObjHandle-32))) != 0)  {can_newdata = 1;}
            }
            
            
            if (can_newdata != 0) 
            {
            /* KB end CanLL_if_RxBasicIsObjIndPending */
              CANDRV_SET_CODE_TEST_POINT(0x108);

              CAN_CAN_INTERRUPT_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
              CanBasicCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxObjHandle);
              CAN_CAN_INTERRUPT_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
            }
          } /* if individual polling & object has to be polled */
        }
      }
    } /* if ( CanLL_HwIsSleep... )  */

    canPollingTaskActive[channel] = 0;
  }

} /* END OF CanRxTask */
/* CODE CATEGORY 2 END*/
#endif /* C_ENABLE_RX_BASICCAN_POLLING && C_ENABLE_RX_BASICCAN_OBJECTS */

/****************************************************************************
| NAME:             CanHL_ErrorHandling
| CALLED BY:        CanISR(), CanErrorTask()
| PRECONDITIONS:
| INPUT PARAMETERS: none 
| RETURN VALUES:    none
| DESCRIPTION:      - error interrupt (busoff, error warning,...)
****************************************************************************/
/* CODE CATEGORY 2 START*/
static void CanHL_ErrorHandling( CAN_HW_CHANNEL_CANTYPE_ONLY )
{
  /* KB begin CanLL_ErrorHandlingLocalParameter */
  CanDeclarePointerToCanHardware;
  /* KB end CanLL_ErrorHandlingLocalParameter */

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);      /* PRQA S 3109 */
#endif



  /* KB begin CanLL_ErrorHandlingBegin */
  CanSetPointerToCanHardware;
  CAN_LL_STATUS(channel) |= (STATREG & (kErrBusOff | kWakeupPending));
  /* KB end CanLL_ErrorHandlingBegin */

  /* check for status register (bus error)--*/
  /* KB begin CanLL_if_BusOffOccured */
  #if defined (C_ENABLE_SLEEP_WAKEUP)
  # if defined (C_ENABLE_WAKEUP_POLLING)
  # else
  if ((CAN_LL_STATUS(channel) & kWakeupPending) == kWakeupPending)
  {
    CAN_LL_STATUS(channel) &= ~kWakeupPending;  
    CanLL_WakeUpHandling(CAN_CHANNEL_CANPARA_ONLY);  
  }
  # endif /* C_ENABLE_WAKEUP_POLLING */
  #endif /* C_ENABLE_SLEEP_WAKEUP */
  
  if ( (STATUS_BUS_OFF(channel) == 0) && \
       ((CAN_LL_STATUS(channel) & kErrBusOff) == kErrBusOff) && \
       ((CNTRLREG & kSetInit) == kSetInit) )
  {
    STATUS_BUS_OFF(channel) = 1; 
    CAN_LL_STATUS(channel) &= ~kErrBusOff;
  {
  /* KB end CanLL_if_BusOffOccured */
    /*==BUS OFF ERROR=========================*/
    APPL_CAN_BUSOFF( CAN_CHANNEL_CANPARA_ONLY );            /* call application specific function */
  }

  /* KB begin CanLL_ErrorHandlingEnd */
    /* clear status in hardware and software */
  #if defined( C_ENABLE_ERROR_POLLING )
  #else
    CAN_LL_STATUS(channel) = STATREG;    
  #endif
    CAN_LL_STATUS(channel) &= ~kErrBusOff; 
  }
  /* KB end CanLL_ErrorHandlingEnd */

} /* END OF CanHL_ErrorHandling */
/* CODE CATEGORY 2 END*/


#if defined( C_ENABLE_INDIVIDUAL_POLLING )
# if defined( C_ENABLE_TX_POLLING )
/****************************************************************************
| NAME:             CanTxObjTask()
| CALLED BY:        
| PRECONDITIONS:    
| INPUT PARAMETERS: CAN_HW_CHANNEL_CANTYPE_FIRST 
|                   CanObjectHandle txObjHandle
| RETURN VALUES:    none
| DESCRIPTION:      Polling special Object
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanTxObjTask(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle txObjHandle)      /* PRQA S 1330 */
{

  /* KB begin CanLL_TxTaskLocalParameter */
  #if defined( C_ENABLE_TX_POLLING )
    CanDeclarePointerToCanHardware;
    vuint8  can_transrequest;
  #endif
  /* KB end CanLL_TxTaskLocalParameter */


#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorChannelHdlTooLarge);  /* PRQA S 3109 */
#  endif
  assertUser(txObjHandle < CAN_HL_HW_TX_STOPINDEX(canHwChannel), channel, kErrorHwHdlTooLarge);     /* PRQA S 3109 */
  assertUser((CanSignedTxHandle)txObjHandle >= (CanSignedTxHandle)CAN_HL_HW_TX_STARTINDEX(canHwChannel), channel, kErrorHwHdlTooSmall);   /* PRQA S 3109 */ /*lint !e568 */
  assertUser(CanHwObjIndivPolling[CAN_HWOBJINDIVPOLLING_INDEX0][txObjHandle] != (vuint8)0, channel, kErrorHwObjNotInPolling);    /* PRQA S 3109 */
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);     /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;

#  if defined( C_ENABLE_SLEEP_WAKEUP )
    if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY))
#  endif
    {

      /* check for dedicated confirmation pending */
      /* KB begin CanLL_if_TxIsObjConfPending */
      CanDeclareGlobalInterruptOldStatus
      CanSetPointerToCanHardware;
      can_transrequest = 0;
      
      CanNestedGlobalInterruptDisable();
      if (txObjHandle < 32)
      {
        if (TX_SEND_FLAG(channel,0) != 0)
        {
          if ( ((TRANSREQUEST(0)         & ((vuint32)0x1<<(txObjHandle))) == 0) && \
               ((TX_SEND_FLAG(channel,0) & ((vuint32)0x1<<(txObjHandle))) != 0)    )
            {
              can_transrequest = 1;
              TX_SEND_FLAG(channel,0) &= ~((vuint32)0x1<<(txObjHandle));
            }
        }
      }
      else
      {
        if (TX_SEND_FLAG(channel,1) != 0)
        {
          if ( ((TRANSREQUEST(1)         & ((vuint32)0x1<<(txObjHandle-32))) == 0) && \
               ((TX_SEND_FLAG(channel,1) & ((vuint32)0x1<<(txObjHandle-32))) != 0)    )
            {
              can_transrequest = 1;
              TX_SEND_FLAG(channel,1) &= ~((vuint32)0x1<<(txObjHandle-32));
            }
        }
      }
      CanNestedGlobalInterruptRestore();
      
      if (can_transrequest != 0)
      {
      /* KB end CanLL_if_TxIsObjConfPending */
        CAN_CAN_INTERRUPT_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
        /* do tx confirmation */
        CanHL_TxConfirmation(CAN_HW_CHANNEL_CANPARA_FIRST txObjHandle );
        CAN_CAN_INTERRUPT_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
      }

#  if defined( C_ENABLE_TRANSMIT_QUEUE )
      if ( txObjHandle == CAN_HL_HW_TX_NORMAL_INDEX(channel) )
      {
        CanHl_RestartTxQueue( CAN_CHANNEL_CANPARA_ONLY );
      }
#  endif /*  C_ENABLE_TRANSMIT_QUEUE */
    }

    canPollingTaskActive[channel] = 0;
  }
} /*CanTxObjTask*/
/* CODE CATEGORY 2 END*/
# endif    /* defined( C_ENABLE_INDIVIDUAL_POLLING ) && defined( C_ENABLE_TX_POLLING ) */

# if defined( C_ENABLE_RX_FULLCAN_OBJECTS ) && \
    defined( C_ENABLE_RX_FULLCAN_POLLING )  
/****************************************************************************
| NAME:             CanRxFullCANObjTask()
| CALLED BY:        
| PRECONDITIONS:    
| INPUT PARAMETERS: CAN_HW_CHANNEL_CANTYPE_FIRST 
|                   CanObjectHandle rxObjHandle
| RETURN VALUES:    none
| DESCRIPTION:      Polling special Object
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanRxFullCANObjTask(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle)      /* PRQA S 1330 */
{

  /* KB begin CanLL_RxFullCANTaskLocalParameter */
  vuint8 can_newdata;
  CanDeclarePointerToCanHardware;
  /* KB end CanLL_RxFullCANTaskLocalParameter */


#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
#  endif
  assertUser(rxObjHandle < CAN_HL_HW_RX_FULL_STOPINDEX(canHwChannel), channel, kErrorHwHdlTooLarge);   /* PRQA S 3109 */
  assertUser((CanSignedRxHandle)rxObjHandle >= (CanSignedRxHandle)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel), channel, kErrorHwHdlTooSmall);  /* PRQA S 3109 */ /*lint !e568 */
  assertUser(CanHwObjIndivPolling[CAN_HWOBJINDIVPOLLING_INDEX0][rxObjHandle] != (vuint8)0, channel, kErrorHwObjNotInPolling);   /* PRQA S 3109 */
  assertUser((canPollingTaskActive[channel] == 0), channel, kErrorPollingTaskRecursion);   /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;

#  if defined( C_ENABLE_SLEEP_WAKEUP )
    if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY))
#  endif
    {
      /* check for dedicated indication pending */
      /* KB begin CanLL_if_RxFullIsObjIndPending */
      can_newdata = 0;
      CanSetPointerToCanHardware;
      
      
      if (rxObjHandle < 32)
      {
        if (NEWDATA(0) != 0)
        {
          if ((NEWDATA(0) & ((vuint32)0x1<<(rxObjHandle))) != 0)
            can_newdata = 1;
        }
      }
      else
      {
        if ((NEWDATA(1) & 0x3FFFFFFF) != 0)
        {
          if ((NEWDATA(1) & ((vuint32)0x1<<(rxObjHandle-32))) != 0)
            can_newdata = 1;
        }
      }
      
      if (can_newdata != 0) 
      {
      /* KB end CanLL_if_RxFullIsObjIndPending */
        CANDRV_SET_CODE_TEST_POINT(0x109);
        CAN_CAN_INTERRUPT_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
        CanFullCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxObjHandle);
        CAN_CAN_INTERRUPT_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
      }
    }
    canPollingTaskActive[channel] = 0;
  }
} /*CanRxFullCANObjTask*/
/* CODE CATEGORY 2 END*/
# endif

# if defined( C_ENABLE_RX_BASICCAN_POLLING ) && \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/****************************************************************************
| NAME:             CanRxBasicCANObjTask()
| CALLED BY:        
| PRECONDITIONS:    
| INPUT PARAMETERS: CAN_HW_CHANNEL_CANTYPE_FIRST 
|                   CanObjectHandle rxObjHandle
| RETURN VALUES:    none
| DESCRIPTION:      Polling special Object
****************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanRxBasicCANObjTask(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle)        /* PRQA S 1330 */
{
#  if kCanNumberOfHwObjPerBasicCan > 1
  CanObjectHandle i;
#  endif

  /* KB begin CanLL_RxBasicCANTaskLocalParameter */
  CanDeclarePointerToCanHardware;
  vuint8 can_newdata;
  /* KB end CanLL_RxBasicCANTaskLocalParameter */


#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
#  endif
  assertUser(rxObjHandle < CAN_HL_HW_RX_BASIC_STOPINDEX(canHwChannel), channel, kErrorHwHdlTooLarge);  /* PRQA S 3109 */
  assertUser((CanSignedRxHandle)rxObjHandle >= (CanSignedRxHandle)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel), channel, kErrorHwHdlTooSmall); /* PRQA S 3109 */ /*lint !e568 */
  assertUser(CanHwObjIndivPolling[CAN_HWOBJINDIVPOLLING_INDEX0][rxObjHandle] != (vuint8)0, channel, kErrorHwObjNotInPolling);   /* PRQA S 3109 */
  assertUser((canPollingTaskActive[channel] == (vuint8)0), channel, kErrorPollingTaskRecursion);  /* PRQA S 3109 */

  if (canPollingTaskActive[channel] == (vuint8)0)  /* avoid reentrance */
  {
    canPollingTaskActive[channel] = 1;

#  if defined( C_ENABLE_SLEEP_WAKEUP )
    if ( !CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY) )
#  endif
    {

#  if kCanNumberOfHwObjPerBasicCan > 1
#    if defined( C_ENABLE_HW_OBJ_BASICCAN_TBL )
      /* loop over all HW objects assigned to one BasicCAN  */
      for (i = 0; i < CanNumberOfHwObjPerBasicCan[channel]; i++)
#    else
      /* loop over all HW objects assigned to one BasicCAN  */
      for (i = 0; i < kCanNumberOfHwObjPerBasicCan; i++)
#    endif
      {
#  endif
        /* check for dedicated indication pending */
        /* KB begin CanLL_if_RxBasicIsObjIndPending */
        can_newdata = 0;
        CanSetPointerToCanHardware;
          
        if (rxObjHandle < 32)
        {
          if ((NEWDATA(0) & ((vuint32)0x1<<(rxObjHandle))) != 0)     {can_newdata = 1;}
        }  
        else
        {
          if ((NEWDATA(1) & ((vuint32)0x1<<(rxObjHandle-32))) != 0)  {can_newdata = 1;}
        }
        
        
        if (can_newdata != 0) 
        {
        /* KB end CanLL_if_RxBasicIsObjIndPending */
          CANDRV_SET_CODE_TEST_POINT(0x109);
          CAN_CAN_INTERRUPT_DISABLE(CAN_CHANNEL_CANPARA_ONLY);
          CanBasicCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxObjHandle);
          CAN_CAN_INTERRUPT_RESTORE(CAN_CHANNEL_CANPARA_ONLY);
        }
#  if kCanNumberOfHwObjPerBasicCan > 1
        rxObjHandle++;
      }
#  endif
    }
    canPollingTaskActive[channel] = 0;
  }
} /*CanRxBasicCANObjTask*/
/* CODE CATEGORY 2 END*/
# endif
#endif /*C_ENABLE_INDIVIDUAL_POLLING*/

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/****************************************************************************
| NAME:             CanBasicCanMsgReceived
| CALLED BY:        CanISR()
| PRECONDITIONS:
| INPUT PARAMETERS: internal can chip number
| RETURN VALUES:    none
| DESCRIPTION:      - basic can receive
****************************************************************************/
/* PRQA S 2001 ++ */    /* suppress misra message about usage of goto */
/* CODE CATEGORY 1 START*/
static void CanBasicCanMsgReceived( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle)
{
# if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  tCanRxInfoStruct    *pCanRxInfoStruct;
# endif  
  
# if ( !defined( C_SEARCH_HASH ) )  ||\
     defined( C_ENABLE_RANGE_0 ) || \
     defined( C_ENABLE_RANGE_1 ) || \
     defined( C_ENABLE_RANGE_2 ) || \
     defined( C_ENABLE_RANGE_3 )
  tCanRxId0 idRaw0;
#  if (kCanNumberOfUsedCanRxIdTables > 1)
  tCanRxId1 idRaw1;
#  endif
#  if (kCanNumberOfUsedCanRxIdTables > 2)
  tCanRxId2 idRaw2;
#  endif
#  if (kCanNumberOfUsedCanRxIdTables > 3)
  tCanRxId3 idRaw3;
#  endif
#  if (kCanNumberOfUsedCanRxIdTables > 4)
  tCanRxId4 idRaw4;
#  endif
# endif

# if defined( C_SEARCH_HASH )
#  if (kCanNumberOfRxBasicCANObjects > 0)
#   if (kHashSearchListCountEx > 0)
  vuint32          idExt;
#    if (kHashSearchListCountEx > 1)
  vuint32          winternExt;        /* prehashvalue         */
#    endif
#   endif
#   if (kHashSearchListCount > 0)
  vuint16          idStd;
#    if (kHashSearchListCount > 1)
  vuint16          winternStd;        /* prehashvalue         */
#    endif
#   endif
#   if (((kHashSearchListCountEx > 1) && (kHashSearchMaxStepsEx > 1)) ||\
        ((kHashSearchListCount > 1)   && (kHashSearchMaxSteps > 1))) 
  vuint16          i_increment;    /* delta for next step  */
  vsint16          count;
#   endif
#  endif  /* kCanNumberOfRxBasicCANObjects > 0 */
# endif

  /* KB begin CanLL_RxBasicCanMsgReceivedLocalParameter */
  #if defined( C_ENABLE_HW_LOOP_TIMER )
  vuint8 canTimerResult;
  #endif
  
  CanDeclarePointerToCanHardware;
  /* KB end CanLL_RxBasicCanMsgReceivedLocalParameter */

# if defined( C_ENABLE_GENERIC_PRECOPY ) || \
    defined( C_ENABLE_PRECOPY_FCT )     || \
    defined( C_ENABLE_COPY_RX_DATA )    || \
    defined( C_ENABLE_INDICATION_FLAG ) || \
    defined( C_ENABLE_INDICATION_FCT )  || \
    defined( C_ENABLE_DLC_CHECK )       || \
    defined( C_ENABLE_NOT_MATCHED_FCT )
#  if (kCanNumberOfRxBasicCANObjects > 0)

  CanReceiveHandle         rxHandle;

  rxHandle = kCanRxHandleNotUsed;

#  endif /* kCanNumberOfRxBasicCANObjects > 0 */
# endif

  CANDRV_SET_CODE_TEST_POINT(0x100);

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);  /* PRQA S 3109 */
# endif

  /* KB begin CanLL_RxBasicMsgReceivedBegin */
  CanSetPointerToCanHardware;
  
  assertHardware( ((IF_RECEIVE.ComRequest & kIFxBusy) != kIFxBusy), channel, kErrorRxHwBufferBusy );
  
  /* WrRd,Mask,Arb,Control,ClrIntPnd,TxRqstNDat,DataA,DataB set */
  IF_RECEIVE.ComMask     =  kSetMask | kSetArb | kSetControl | kSetClrIntPnd | kSetTxRqstNDat | kSetDataA | kSetDataB;
  IF_RECEIVE.ComRequest  =  rxObjHandle + 1;
  
  APPLCANTIMERSTART(kCanLoopBusyReq);
  
  do{
      CANTIMERRESULT_UPDATE(kCanLoopBusyReq);
  
    } WHILE_CONDITON( ((IF_RECEIVE.ComRequest & kIFxBusy) == kIFxBusy) );
  
  APPLCANTIMEREND(kCanLoopBusyReq);
  
  
  # if defined( C_ENABLE_EXTENDED_ID )  
  RX_MSGOBJ_ID_LOW(channel)          =  IF_RECEIVE.ArbitrFld1;
  # endif
  RX_MSGOBJ_ID_HIGH(channel)         =  IF_RECEIVE.ArbitrFld2;
  
  RX_MSGOBJ_DLC(channel)             =  IF_RECEIVE.MessageCntrl & 0xF;  /* only Bit0-3 are interesting for DLC */
  
  #if defined(C_CPUTYPE_BIGENDIAN)
  RX_MSGOBJ(channel).Data.ucData[3]  =  IF_RECEIVE.Data.ucData[0];
  RX_MSGOBJ(channel).Data.ucData[2]  =  IF_RECEIVE.Data.ucData[1];
  RX_MSGOBJ(channel).Data.ucData[1]  =  IF_RECEIVE.Data.ucData[2];
  RX_MSGOBJ(channel).Data.ucData[0]  =  IF_RECEIVE.Data.ucData[3];
  RX_MSGOBJ(channel).Data.ucData[7]  =  IF_RECEIVE.Data.ucData[4];
  RX_MSGOBJ(channel).Data.ucData[6]  =  IF_RECEIVE.Data.ucData[5];
  RX_MSGOBJ(channel).Data.ucData[5]  =  IF_RECEIVE.Data.ucData[6];
  RX_MSGOBJ(channel).Data.ucData[4]  =  IF_RECEIVE.Data.ucData[7];
  #endif
  
  
  RX_MSGOBJ_MSGCNTRL(channel)        =  IF_RECEIVE.MessageCntrl;
  /* KB end CanLL_RxBasicMsgReceivedBegin */

# if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  pCanRxInfoStruct =  &canRxInfoStruct[channel];
  /* KB begin CanLL_RxBasicGetCANObjPtr */
  (pCanRxInfoStruct->pChipMsgObj) = (CanChipMsgPtr)&RX_MSGOBJ(channel);
  /* KB end CanLL_RxBasicGetCANObjPtr */
  /* KB begin CanLL_RxBasicGetCANDataPtr */
  (pCanRxInfoStruct->pChipData)         = (CanChipDataPtr)&(RX_MSGOBJ_DATA(channel));  
  /* KB end CanLL_RxBasicGetCANDataPtr */
  canRDSRxPtr[channel] = pCanRxInfoStruct->pChipData;
# else
  /* KB begin CanLL_RxBasicGetCANObjPtr */
  (canRxInfoStruct[channel].pChipMsgObj) = (CanChipMsgPtr)&RX_MSGOBJ(channel);
  /* KB end CanLL_RxBasicGetCANObjPtr */
  /* KB begin CanLL_RxBasicGetCANDataPtr */
  (canRxInfoStruct[channel].pChipData)         = (CanChipDataPtr)&(RX_MSGOBJ_DATA(channel));  
  /* KB end CanLL_RxBasicGetCANDataPtr */
  canRDSRxPtr[channel] = canRxInfoStruct[channel].pChipData;
# endif
  CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)      = kCanRxHandleNotUsed;  

# if defined( C_ENABLE_CAN_RAM_CHECK )
  if(canComStatus[channel] == kCanDisableCommunication)
  {
    goto finishBasicCan; /* ignore reception */
  }
# endif

#  if defined( C_ENABLE_OVERRUN )
  /* KB begin CanLL_if_RxBasicCanOverrun */
  if (RX_MSGOBJ_MSGCNTRL(channel) & kSetMsgLst)
  {
    /* clear Bit MsgLst in rxMsgObj */
    /* WrRd,Mask,Arb,Control,ClrIntPnd,TxRqstNDat,DataA,DataB set */
    IF_RECEIVE.ComMask = kSetWrRd | kSetControl;
  
    if((rxObjHandle & 0x0001) == 0)
    {
      if(CAN_INDIV_POLLING(channel,rxObjHandle) != 0)
      {
      /* EoB=1 => last Element of FIFO, clear MsgLst */
      IF_RECEIVE.MessageCntrl =  kSetUMask | kSetEoB;  /* EoB = 1 */
      }
      else
      {
      /* EoB=1 => last Element of FIFO, clear MsgLst */
      IF_RECEIVE.MessageCntrl =  kSetEnableRxBasicCanInt | kSetUMask | kSetEoB;  /* EoB = 1 */
      }
    }
    else
    {
      if(CAN_INDIV_POLLING(channel,rxObjHandle) != 0)
      {
      /* EoB=0 => first Element of FIFO, clear MsgLst */
      IF_RECEIVE.MessageCntrl =  kSetUMask;            /* EoB = 0 */
      }
      else
      {
      /* EoB=0 => first Element of FIFO, clear MsgLst */
      IF_RECEIVE.MessageCntrl =  kSetEnableRxBasicCanInt | kSetUMask;            /* EoB = 0 */
      }
    }
  
    IF_RECEIVE.ComRequest = rxObjHandle + 1;
  
  /* KB end CanLL_if_RxBasicCanOverrun */
    ApplCanOverrun( CAN_CHANNEL_CANPARA_ONLY );
  }
#  endif

  /**************************** reject remote frames  ****************************************/


  /**************************** reject messages with unallowed ID type ****************************************/
# if defined( C_HL_ENABLE_REJECT_UNWANTED_IDTYPE )
#  if defined( C_ENABLE_EXTENDED_ID )
#   if defined( C_ENABLE_MIXED_ID )
#   else
  if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) != kCanIdTypeExt)
  {
    goto finishBasicCan;
  }
#   endif
#  else
  if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) != kCanIdTypeStd)
  {
    goto finishBasicCan;
  }
#  endif
# endif /* C_HL_ENABLE_REJECT_UNWANTED_IDTYPE */


# if defined( C_ENABLE_COND_RECEIVE_FCT )
  /**************************** conditional message receive function  ****************************************/
  if(canMsgCondRecState[channel]==kCanTrue)
  {
    ApplCanMsgCondReceived( CAN_HL_P_RX_INFO_STRUCT(channel) );
  }
# endif

# if defined( C_ENABLE_RECEIVE_FCT )
  /**************************** call ApplCanMsgReceived() ****************************************************/
  if (APPL_CAN_MSG_RECEIVED( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanNoCopyData)
  {
    goto finishBasicCan;
  }
# endif
  

# if ( !defined( C_SEARCH_HASH ) ) || \
     defined( C_ENABLE_RANGE_0 ) || \
     defined( C_ENABLE_RANGE_1 ) || \
     defined( C_ENABLE_RANGE_2 ) || \
     defined( C_ENABLE_RANGE_3 )
  /**************************** calculate idRaw for filtering ************************************************/
#  if defined( C_ENABLE_EXTENDED_ID )
#   if defined( C_ENABLE_MIXED_ID )
  if (CanRxActualIdType(CAN_HL_P_RX_INFO_STRUCT(channel)) == kCanIdTypeExt)
#   endif
  {
#   if defined( C_ENABLE_RX_MASK_EXT_ID )
    idRaw0 = CanRxActualIdRaw0( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID0(C_MASK_EXT_ID);
#    if (kCanNumberOfUsedCanRxIdTables > 1)
    idRaw1 = CanRxActualIdRaw1( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID1(C_MASK_EXT_ID);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 2)
    idRaw2 = CanRxActualIdRaw2( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID2(C_MASK_EXT_ID);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 3)
    idRaw3 = CanRxActualIdRaw3( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID3(C_MASK_EXT_ID);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 4)
    idRaw4 = CanRxActualIdRaw4( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID4(C_MASK_EXT_ID);
#    endif
#   else
    idRaw0 = CanRxActualIdRaw0( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID0(0x1FFFFFFF);
#    if (kCanNumberOfUsedCanRxIdTables > 1)
    idRaw1 = CanRxActualIdRaw1( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID1(0x1FFFFFFF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 2)
    idRaw2 = CanRxActualIdRaw2( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID2(0x1FFFFFFF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 3)
    idRaw3 = CanRxActualIdRaw3( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID3(0x1FFFFFFF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 4)
    idRaw4 = CanRxActualIdRaw4( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_EXTID4(0x1FFFFFFF);
#    endif
#   endif /*  C_ENABLE_RX_MASK_EXT_ID */
  }
#   if defined( C_ENABLE_MIXED_ID )
  else
  {
    idRaw0 = CanRxActualIdRaw0( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID0(0x7FF);
#    if (kCanNumberOfUsedCanRxIdTables > 1)
    idRaw1 = CanRxActualIdRaw1( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID1(0x7FF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 2)
    idRaw2 = CanRxActualIdRaw2( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID2(0x7FF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 3)
    idRaw3 = CanRxActualIdRaw3( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID3(0x7FF);
#    endif
#    if (kCanNumberOfUsedCanRxIdTables > 4)
    idRaw4 = CanRxActualIdRaw4( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID4(0x7FF);
#    endif
  }
#   endif
#  else /* C_ENABLE_EXTENDED_ID */
  {
    idRaw0 = CanRxActualIdRaw0( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID0(0x7FF);
#   if (kCanNumberOfUsedCanRxIdTables > 1)
    idRaw1 = CanRxActualIdRaw1( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID1(0x7FF);
#   endif
#   if (kCanNumberOfUsedCanRxIdTables > 2)
    idRaw2 = CanRxActualIdRaw2( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID2(0x7FF);
#   endif
#   if (kCanNumberOfUsedCanRxIdTables > 3)
    idRaw3 = CanRxActualIdRaw3( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID3(0x7FF);
#   endif
#   if (kCanNumberOfUsedCanRxIdTables > 4)
    idRaw4 = CanRxActualIdRaw4( CAN_HL_P_RX_INFO_STRUCT(channel) ) & MK_STDID4(0x7FF);
#   endif
  }
#  endif /* C_ENABLE_EXTENDED_ID */
# endif /* ( !defined( C_SEARCH_HASH ) && ...  defined( C_ENABLE_RANGE_3 )*/

  /******************* Range filtering ********************************************************************/

  {
#  if defined( C_ENABLE_RANGE_0 )
#   if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    if ( (CanChannelObject[channel].RangeActiveFlag & kCanRange0) != (vuint16)0 )
    {
#    if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == CANRANGE0IDTYPE(channel))
#    endif
      {
        if ( C_RANGE_MATCH( CAN_RX_IDRAW_PARA, CANRANGE0ACCMASK(channel), CANRANGE0ACCCODE(channel)) )
#   else    /* C_SINGLE_RECEIVE_CHANNEL) */
    {
#    if (C_RANGE0_IDTYPE == kCanIdTypeStd )
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeStd)
#     endif
      {
        if ( C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, CANRANGE0ACCMASK(channel), CANRANGE0ACCCODE(channel)) )
#    else  /* C_RANGE_0_IDTYPE == kCanIdTypeExt */
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeExt)
#     endif
      {
        if ( C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, CANRANGE0ACCMASK(channel), CANRANGE0ACCCODE(channel)) )
#    endif
#   endif
        {
#   if defined( C_ENABLE_RX_QUEUE_RANGE )
          if (CanRxQueueRange0[channel] == kCanTrue)
          {
            pCanRxInfoStruct->Handle      = kCanRxHandleRange0;
            (void)CanHL_ReceivedRxHandleQueue( CAN_CHANNEL_CANPARA_ONLY );
            goto finishBasicCan;
          }
          else
#   endif  /* C_ENABLE_RX_QUEUE */
          {
            if (APPLCANRANGE0PRECOPY( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanNoCopyData)
            {
              goto finishBasicCan;
            }
          }
        }
      }
    }
#  endif  /* C_ENABLE_RANGE_0 */

#  if defined( C_ENABLE_RANGE_1 )
#   if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    if ( (CanChannelObject[channel].RangeActiveFlag & kCanRange1) != (vuint16)0 )
    {
#    if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == CANRANGE1IDTYPE(channel))
#    endif
      {
        if ( C_RANGE_MATCH( CAN_RX_IDRAW_PARA, CANRANGE1ACCMASK(channel), CANRANGE1ACCCODE(channel)) )
#   else    /* C_SINGLE_RECEIVE_CHANNEL) */
    {
#    if (C_RANGE1_IDTYPE == kCanIdTypeStd )
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeStd)
#     endif
      {
        if ( C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, CANRANGE1ACCMASK(channel), CANRANGE1ACCCODE(channel)) )
#    else  /* C_RANGE_1_IDTYPE == kCanIdTypeExt */
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeExt)
#     endif
      {
        if ( C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, CANRANGE1ACCMASK(channel), CANRANGE1ACCCODE(channel)) )
#    endif
#   endif
        {
#   if defined( C_ENABLE_RX_QUEUE_RANGE )
          if (CanRxQueueRange1[channel] == kCanTrue)
          {
            pCanRxInfoStruct->Handle      = kCanRxHandleRange1;
            (void)CanHL_ReceivedRxHandleQueue( CAN_CHANNEL_CANPARA_ONLY );
            goto finishBasicCan;
          }
          else
#   endif  /* C_ENABLE_RX_QUEUE */
          {
            if (APPLCANRANGE1PRECOPY( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanNoCopyData)
            {
              goto finishBasicCan;
            }
          }
        }
      }
    }
#  endif  /* C_ENABLE_RANGE_1 */

#  if defined( C_ENABLE_RANGE_2 )
#   if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    if ( (CanChannelObject[channel].RangeActiveFlag & kCanRange2) != (vuint16)0 )
    {
#    if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == CANRANGE2IDTYPE(channel))
#    endif
      {
        if ( C_RANGE_MATCH( CAN_RX_IDRAW_PARA, CANRANGE2ACCMASK(channel), CANRANGE2ACCCODE(channel)) )
#   else    /* C_SINGLE_RECEIVE_CHANNEL) */
    {
#    if (C_RANGE2_IDTYPE == kCanIdTypeStd )
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeStd)
#     endif
      {
        if ( C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, CANRANGE2ACCMASK(channel), CANRANGE2ACCCODE(channel)) )
#    else  /* C_RANGE_2_IDTYPE == kCanIdTypeExt */
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeExt)
#     endif
      {
        if ( C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, CANRANGE2ACCMASK(channel), CANRANGE2ACCCODE(channel)) )
#    endif
#   endif
        {
#   if defined( C_ENABLE_RX_QUEUE_RANGE )
          if (CanRxQueueRange2[channel] == kCanTrue)
          {
            pCanRxInfoStruct->Handle      = kCanRxHandleRange2;
            (void)CanHL_ReceivedRxHandleQueue( CAN_CHANNEL_CANPARA_ONLY );
            goto finishBasicCan;
          }
          else
#   endif  /* C_ENABLE_RX_QUEUE */
          {
            if (APPLCANRANGE2PRECOPY( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanNoCopyData)
            {
              goto finishBasicCan;
            }
          }
        }
      }
    }
#  endif  /* C_ENABLE_RANGE_2 */

#  if defined( C_ENABLE_RANGE_3 )
#   if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    if ( (CanChannelObject[channel].RangeActiveFlag & kCanRange3) != (vuint16)0 )
    {
#    if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == CANRANGE3IDTYPE(channel))
#    endif
      {
        if ( C_RANGE_MATCH( CAN_RX_IDRAW_PARA, CANRANGE3ACCMASK(channel), CANRANGE3ACCCODE(channel)) )
#   else    /* C_SINGLE_RECEIVE_CHANNEL) */
    {
#    if (C_RANGE3_IDTYPE == kCanIdTypeStd )
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeStd)
#     endif
      {
        if ( C_RANGE_MATCH_STD( CAN_RX_IDRAW_PARA, CANRANGE3ACCMASK(channel), CANRANGE3ACCCODE(channel)) )
#    else  /* C_RANGE_3_IDTYPE == kCanIdTypeExt */
#     if defined( C_ENABLE_MIXED_ID ) && !defined( C_HL_ENABLE_IDTYPE_IN_ID )
      if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanIdTypeExt)
#     endif
      {
        if ( C_RANGE_MATCH_EXT( CAN_RX_IDRAW_PARA, CANRANGE3ACCMASK(channel), CANRANGE3ACCCODE(channel)) )
#    endif
#   endif
        {
#   if defined( C_ENABLE_RX_QUEUE_RANGE )
          if (CanRxQueueRange3[channel] == kCanTrue)
          {
            pCanRxInfoStruct->Handle      = kCanRxHandleRange3;
            (void)CanHL_ReceivedRxHandleQueue( CAN_CHANNEL_CANPARA_ONLY );
            goto finishBasicCan;
          }
          else
#   endif  /* C_ENABLE_RX_QUEUE */
          {
            if (APPLCANRANGE3PRECOPY( CAN_HL_P_RX_INFO_STRUCT(channel) ) == kCanNoCopyData)
            {
              goto finishBasicCan;
            }
          }
        }
      }
    }
#  endif  /* C_ENABLE_RANGE_3 */

  }


# if defined( C_ENABLE_GENERIC_PRECOPY ) || \
    defined( C_ENABLE_PRECOPY_FCT )     || \
    defined( C_ENABLE_COPY_RX_DATA )    || \
    defined( C_ENABLE_INDICATION_FLAG ) || \
    defined( C_ENABLE_INDICATION_FCT )  || \
    defined( C_ENABLE_DLC_CHECK )       || \
    defined( C_ENABLE_NOT_MATCHED_FCT )
# if (kCanNumberOfRxBasicCANObjects > 0)

   /* search the received id in ROM table: */

  /* KB begin CanLL_HwSpecificAcceptanceFilter */
  /* KB end CanLL_HwSpecificAcceptanceFilter */

#  if defined( C_SEARCH_LINEAR )
  /* ************* Linear search ******************************************** */
  for (rxHandle = CAN_HL_RX_BASIC_STARTINDEX(channel); rxHandle < CAN_HL_RX_BASIC_STOPINDEX(channel) ;rxHandle++)
  {
    if( idRaw0 == CanGetRxId0(rxHandle) )
    {
#   if (kCanNumberOfUsedCanRxIdTables > 1)
      if( idRaw1 == CanGetRxId1(rxHandle) )
#   endif
      {
#   if (kCanNumberOfUsedCanRxIdTables > 2)
        if( idRaw2 == CanGetRxId2(rxHandle) )
#   endif
        {
#   if (kCanNumberOfUsedCanRxIdTables > 3)
          if( idRaw3 == CanGetRxId3(rxHandle) )
#   endif
          {
#   if (kCanNumberOfUsedCanRxIdTables > 4)
            if( idRaw4 == CanGetRxId4(rxHandle) )
#   endif
            {
#   if defined( C_ENABLE_MIXED_ID ) 
#    if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#    else
              /* verify ID type, if not already done with the ID raw */
              if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) == CanGetRxIdType(rxHandle))
#    endif
#   endif
              {
                break;    /*exit loop with index rxHandle */
              }
            }
          }
        }
      }
    }
  }
#  endif

#  if defined( C_SEARCH_HASH )
  /* ************* Hash search ********************************************* */
#   if defined( C_CPUTYPE_8BIT )
#    error "Hash search with 8-Bit CPU not tested yet"
#   endif   
    
#   if defined( C_ENABLE_EXTENDED_ID ) 
  /* one or more Extended ID listed */
#    if defined( C_ENABLE_MIXED_ID )
  if((CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) )) == kCanIdTypeExt)
#    endif
#    if (kHashSearchListCountEx > 0)
  {
  /* calculate the logical ID */
#     if defined( C_ENABLE_RX_MASK_EXT_ID )
    idExt          = (CanRxActualId( CAN_HL_P_RX_INFO_STRUCT(channel) ) &  C_MASK_EXT_ID ) | \
                                                                               ((vuint32)channel << 29);                
#     else
    idExt          = CanRxActualId( CAN_HL_P_RX_INFO_STRUCT(channel) )| ((vuint32)channel << 29);
#     endif

#     if (kHashSearchListCountEx == 1)
    rxHandle       = (CanReceiveHandle)0;
#     else
    winternExt     = idExt + kHashSearchRandomNumberEx;                    
    rxHandle       = (CanReceiveHandle)(winternExt % kHashSearchListCountEx);
#     endif /* (kHashSearchListCountEx == 1) */

#     if ((kHashSearchListCountEx == 1) || (kHashSearchMaxStepsEx == 1))
    if (idExt != CanRxHashIdEx[rxHandle])   
    { 
#      if defined( C_ENABLE_NOT_MATCHED_FCT )
      ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#      endif
      goto finishBasicCan;
    }
#     else /* (kHashSearchListCountEx == 1) || (kHashSearchMaxStepsEx == 1) */

    i_increment = (vuint16)((winternExt % (kHashSearchListCountEx - 1)) + (vuint8)1);          /* ST10-CCAN Keil compiler complains without cast */
    count       = (vsint16)kHashSearchMaxStepsEx - 1;               
  
    while(idExt != CanRxHashIdEx[rxHandle])   
    {
      if(count == (vsint16)0)  
      {
#      if defined( C_ENABLE_NOT_MATCHED_FCT )
        ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#      endif
        goto finishBasicCan;
      }
      count--;
      rxHandle += i_increment;
      if( rxHandle >= (vuint16)kHashSearchListCountEx ) 
      {
        rxHandle -= kHashSearchListCountEx;
      }
    }
#     endif  /* (kHashSearchListCountEx == 1) || (kHashSearchMaxStepsEx == 1) */
    rxHandle = CanRxMsgIndirection[rxHandle+kHashSearchListCount];
  }
#    else /* (kHashSearchListCountEx > 0) */
  {
#     if defined( C_ENABLE_NOT_MATCHED_FCT )
    ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#     endif
    goto finishBasicCan;
  }
#    endif /* (kHashSearchListCountEx > 0) */

#    if defined( C_ENABLE_MIXED_ID )
  else   /* if((CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) )) == kCanIdTypeStd)  */
#    endif
#   endif /* If defined( C_ENABLE_EXTENDED_ID ) */

#   if defined( C_ENABLE_MIXED_ID ) || !defined( C_ENABLE_EXTENDED_ID ) 
#    if (kHashSearchListCount > 0)
  {
    idStd          = ((vuint16)CanRxActualId( CAN_HL_P_RX_INFO_STRUCT(channel) ) | ((vuint16)channel << 11));    /* calculate the logical ID */

#     if (kHashSearchListCount == 1)
    rxHandle       = (CanReceiveHandle)0;
#     else
    winternStd     = idStd + kHashSearchRandomNumber;
    rxHandle       = (CanReceiveHandle)(winternStd % kHashSearchListCount);
#     endif /* (kHashSearchListCount == 1) */

#     if ((kHashSearchListCount == 1)  || (kHashSearchMaxSteps == 1))
    if (idStd != CanRxHashId[rxHandle])
    {
#      if defined( C_ENABLE_NOT_MATCHED_FCT )
      ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#      endif
      goto finishBasicCan;
    }
#     else /* ((kHashSearchListCount == 1)  || (kHashSearchMaxSteps == 1)) */

    i_increment = (vuint16)((winternStd % (kHashSearchListCount - 1)) + (vuint8)1);
    count       = (vsint16)kHashSearchMaxSteps-1;

    /* type of CanRxHashId table depends on the used type of Id */
    while ( idStd != CanRxHashId[rxHandle])
    {
      if (count == (vsint16)0)
      {
#     if defined( C_ENABLE_NOT_MATCHED_FCT )
        ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#     endif
        goto finishBasicCan;
      }
      count--; 
      rxHandle += i_increment;
      if ( rxHandle >= kHashSearchListCount )
      {
        rxHandle -= kHashSearchListCount;
      }
    }
#     endif /* ((kHashSearchListCount == 1)  || (kHashSearchMaxSteps == 1)) */
    rxHandle = CanRxMsgIndirection[rxHandle];
  }
#    else /* (kHashSearchListCount > 0) */
  {
#     if defined( C_ENABLE_NOT_MATCHED_FCT )
    ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#     endif
    goto finishBasicCan;
  }
#    endif /* (kHashSearchListCount > 0) */
#   endif /* defined( C_ENABLE_MIXED_ID ) || !defined( C_ENABLE_EXTENDED_ID ) */ 
#  endif /* defined( C_SEARCH_HASH ) */



  /**************************** handle filtered message ****************************************************/
#  if defined( C_SEARCH_HASH )
  assertInternal((rxHandle < kCanNumberOfRxObjects), kCanAllChannels , kErrorRxHandleWrong);  /* PRQA S 3109 */ /* legal rxHandle ? */
#  else
  if ( rxHandle < CAN_HL_RX_BASIC_STOPINDEX(channel)) 
#  endif
  {
    /* ID found in table */
#  if defined( C_SEARCH_HASH ) 
#  else
#   if defined( C_ENABLE_RX_MSG_INDIRECTION )
    rxHandle = CanRxMsgIndirection[rxHandle];       /* indirection for special sort-algoritms */
#   endif
#  endif

    CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel) = rxHandle;  

#  if defined( C_ENABLE_RX_QUEUE )
    if (CanHL_ReceivedRxHandleQueue( CAN_CHANNEL_CANPARA_ONLY ) == kCanHlContinueRx)
#  else
    if (CanHL_ReceivedRxHandle( CAN_CHANNEL_CANPARA_ONLY ) == kCanHlContinueRx)
#  endif
    { 
#  if defined( C_ENABLE_INDICATION_FLAG ) || \
          defined( C_ENABLE_INDICATION_FCT )
      /* KB begin CanLL_RxBasicReleaseObj */
      /* KB end CanLL_RxBasicReleaseObj */

      CanHL_IndRxHandle( rxHandle );
      
      /* KB begin CanLL_RxBasicMsgReceivedEnd */
      /* KB end CanLL_RxBasicMsgReceivedEnd */

      return;
#  endif
    }
  }
#  if defined( C_ENABLE_NOT_MATCHED_FCT )
#   if defined( C_SEARCH_HASH )
#   else
  else
  {
    ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
  }
#   endif
#  endif
# else  /* kCanNumberOfRxBasicCANObjects > 0 */
#  if defined( C_ENABLE_NOT_MATCHED_FCT )
  ApplCanMsgNotMatched( CAN_HL_P_RX_INFO_STRUCT(channel) );
#  endif
# endif /* kCanNumberOfRxBasicCANObjects > 0 */

# endif

  goto finishBasicCan;     /* to avoid compiler warning */

/* Msg(4:2015) This label is not a case or default label for a switch statement. MISRA Rule 55 */
finishBasicCan:

  /* make receive buffer free*/
  /* KB begin CanLL_RxBasicReleaseObj */
  /* KB end CanLL_RxBasicReleaseObj */
  /* KB begin CanLL_RxBasicMsgReceivedEnd */
  /* KB end CanLL_RxBasicMsgReceivedEnd */


  return;    /* to avoid compiler warnings about label without code */

} /* end of BasicCan */
/* CODE CATEGORY 1 END*/
/* PRQA S 2001 -- */    /* suppress misra message about multiple return and usage of goto */
#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/****************************************************************************
| NAME:             CanFullCanMsgReceived
| CALLED BY:        CanISR()
| PRECONDITIONS:
| INPUT PARAMETERS: internal can chip number
| RETURN VALUES:    none
| DESCRIPTION:      - full can receive
****************************************************************************/
/* PRQA S 2001 ++ */    /* suppress misra message about usage of goto */
/* CODE CATEGORY 1 START*/
static void CanFullCanMsgReceived( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxObjHandle )
{
  CanReceiveHandle   rxHandle; 

# if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  tCanRxInfoStruct    *pCanRxInfoStruct;
# endif  

  /* KB begin CanLL_RxFullCanMsgReceivedLocalParameter */
  #if defined( C_ENABLE_HW_LOOP_TIMER )
  vuint8 canTimerResult;
  #endif
  CanDeclarePointerToCanHardware;
  /* KB end CanLL_RxFullCanMsgReceivedLocalParameter */

  CANDRV_SET_CODE_TEST_POINT(0x101);
   
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);   /* PRQA S 3109 */
# endif



  /* KB begin CanLL_RxFullMsgReceivedBegin */
  CanSetPointerToCanHardware;
  
  /* WrRd,Mask,Arb,Control,ClrIntPnd,TxRqstNDat,DataA,DataB set */
  IF_RECEIVE.ComMask    = kSetMask | kSetArb | kSetControl | kSetClrIntPnd | kSetTxRqstNDat | kSetDataA | kSetDataB;
  IF_RECEIVE.ComRequest = rxObjHandle + 1;
  
  APPLCANTIMERSTART(kCanLoopBusyReq);
  
  do{
      CANTIMERRESULT_UPDATE(kCanLoopBusyReq);
  
    } WHILE_CONDITON( ((IF_RECEIVE.ComRequest & kIFxBusy) == kIFxBusy) );
  
  APPLCANTIMEREND(kCanLoopBusyReq);
  
  
  # if defined( C_ENABLE_EXTENDED_ID )
  RX_MSGOBJ_ID_LOW(channel)    =  IF_RECEIVE.ArbitrFld1;
  # endif
  RX_MSGOBJ_ID_HIGH(channel)   =  IF_RECEIVE.ArbitrFld2;
  
  /* only Bit0-3 are interesting for DLC */
  RX_MSGOBJ_DLC(channel)             =  IF_RECEIVE.MessageCntrl & 0xF;  /* only Bit0-3 are interesting for DLC */
  
  #if defined(C_CPUTYPE_BIGENDIAN)
  RX_MSGOBJ(channel).Data.ucData[3]  =  IF_RECEIVE.Data.ucData[0];
  RX_MSGOBJ(channel).Data.ucData[2]  =  IF_RECEIVE.Data.ucData[1];
  RX_MSGOBJ(channel).Data.ucData[1]  =  IF_RECEIVE.Data.ucData[2];
  RX_MSGOBJ(channel).Data.ucData[0]  =  IF_RECEIVE.Data.ucData[3];
  RX_MSGOBJ(channel).Data.ucData[7]  =  IF_RECEIVE.Data.ucData[4];
  RX_MSGOBJ(channel).Data.ucData[6]  =  IF_RECEIVE.Data.ucData[5];
  RX_MSGOBJ(channel).Data.ucData[5]  =  IF_RECEIVE.Data.ucData[6];
  RX_MSGOBJ(channel).Data.ucData[4]  =  IF_RECEIVE.Data.ucData[7];
  #endif
  
  
  RX_MSGOBJ_MSGCNTRL(channel)        =  IF_RECEIVE.MessageCntrl;
  /* KB end CanLL_RxFullMsgReceivedBegin */

# if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  /* pointer needed for other modules */
  pCanRxInfoStruct =  &canRxInfoStruct[channel];
  /* KB begin CanLL_RxFullGetCANObjPtr */
  (pCanRxInfoStruct->pChipMsgObj) = (CanChipMsgPtr)&RX_MSGOBJ(channel);
  /* KB end CanLL_RxFullGetCANObjPtr */
  /* KB begin CanLL_RxFullGetCANDataPtr */
  (pCanRxInfoStruct->pChipData) = (CanChipDataPtr)&(RX_MSGOBJ_DATA(channel));
  /* KB end CanLL_RxFullGetCANDataPtr */
  canRDSRxPtr[channel] = pCanRxInfoStruct->pChipData;
# else
  /* KB begin CanLL_RxFullGetCANObjPtr */
  (canRxInfoStruct[channel].pChipMsgObj) = (CanChipMsgPtr)&RX_MSGOBJ(channel);
  /* KB end CanLL_RxFullGetCANObjPtr */
  /* KB begin CanLL_RxFullGetCANDataPtr */
  (canRxInfoStruct[channel].pChipData) = (CanChipDataPtr)&(RX_MSGOBJ_DATA(channel));
  /* KB end CanLL_RxFullGetCANDataPtr */
  canRDSRxPtr[channel] = canRxInfoStruct[channel].pChipData;
# endif

# if defined( C_ENABLE_CAN_RAM_CHECK )
  if(canComStatus[channel] == kCanDisableCommunication)
  {
    goto finishRxFullCan; /* ignore reception */
  }
# endif

#  if defined( C_ENABLE_FULLCAN_OVERRUN )

  /* KB begin CanLL_if_RxFullCanOverrun */
  if (RX_MSGOBJ_MSGCNTRL(channel) & kSetMsgLst)
  {
    /* WrRd,Mask,Arb,Control,ClrIntPnd,TxRqstNDat,DataA,DataB set */
    IF_RECEIVE.ComMask = kSetWrRd | kSetControl;
    
    /* clear MsgLst */
    #if defined (C_ENABLE_INDIVIDUAL_POLLING)
      if(CAN_INDIV_POLLING(channel,rxObjHandle) != 0)
      {
        IF_RECEIVE.MessageCntrl = kSetEoB;
      }
      else
      {
        IF_RECEIVE.MessageCntrl = kSetEoB | kSetRxIE;
      }
    #else
      # if defined (C_ENABLE_RX_FULLCAN_POLLING)
        IF_RECEIVE.MessageCntrl = kSetEoB;
      #else
        IF_RECEIVE.MessageCntrl = kSetEoB | kSetRxIE;
      #endif
    #endif
  
    IF_RECEIVE.ComRequest = rxObjHandle + 1;
  
  /* KB end CanLL_if_RxFullCanOverrun */
     ApplCanFullCanOverrun( CAN_CHANNEL_CANPARA_ONLY );
  }
#  endif


# if defined( C_HL_ENABLE_REJECT_UNWANTED_IDTYPE )
  /**************************** reject messages with unallowed ID type ****************************************/
#  if defined( C_ENABLE_EXTENDED_ID )
#   if defined( C_ENABLE_MIXED_ID )
#   else
  if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) != kCanIdTypeExt)
  {
    goto finishRxFullCan;
  }
#   endif
#  else
  if (CanRxActualIdType( CAN_HL_P_RX_INFO_STRUCT(channel) ) != kCanIdTypeStd)
  {
    goto finishRxFullCan;
  }
#  endif
# endif /* C_HL_ENABLE_REJECT_UNWANTED_IDTYPE */

# if defined( C_ENABLE_COND_RECEIVE_FCT )
  /**************************** conditional message receive function  ****************************************/
  if(canMsgCondRecState[channel]==kCanTrue)
  {
    ApplCanMsgCondReceived( CAN_HL_P_RX_INFO_STRUCT(channel) );
  }
# endif

# if defined( C_ENABLE_RECEIVE_FCT )
  /**************************** call ApplCanMsgReceived() ****************************************************/
  if (APPL_CAN_MSG_RECEIVED( CAN_HL_P_RX_INFO_STRUCT(channel) )==kCanNoCopyData)
  {
     goto finishRxFullCan;
  }
# endif

  /* calculate the message handle to access the generated data for the received message */

  /* brackets to avoid lint info 834 */
  rxHandle = (rxObjHandle - CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel))
# if defined( C_SEARCH_HASH )
                         + kHashSearchListCount
                         + kHashSearchListCountEx
# endif
                         + CAN_HL_RX_FULL_STARTINDEX(canHwChannel);

# if defined( C_HL_ENABLE_ADJUST_RXHANDLE )
  /* KB begin CanLL_AdjustRxHandle */
  /*
  if(something)
  {
    do something with rxHandle
  }
  */
  /* KB end CanLL_AdjustRxHandle */
# endif

# if defined( C_ENABLE_RX_MSG_INDIRECTION ) || \
     defined( C_SEARCH_HASH ) 
  rxHandle = CanRxMsgIndirection[rxHandle];
# endif

  assertInternal((rxHandle < kCanNumberOfRxObjects), kCanAllChannels , kErrorRxHandleWrong);  /* PRQA S 3109 */ /* legal rxHandle ? */

  CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel) = rxHandle;  

# if defined( C_ENABLE_RX_QUEUE )
  if (CanHL_ReceivedRxHandleQueue( CAN_CHANNEL_CANPARA_ONLY) == kCanHlContinueRx)
# else
  if (CanHL_ReceivedRxHandle( CAN_CHANNEL_CANPARA_ONLY ) == kCanHlContinueRx)
# endif
  { 
# if defined( C_ENABLE_INDICATION_FLAG ) || \
        defined( C_ENABLE_INDICATION_FCT )
    /* KB begin CanLL_RxFullReleaseObj */
    /* KB end CanLL_RxFullReleaseObj */

    CanHL_IndRxHandle( rxHandle );

    /* KB begin CanLL_RxFullMsgReceivedEnd */
    /* KB end CanLL_RxFullMsgReceivedEnd */

    return;
# endif
  }

  goto finishRxFullCan;     /* to avoid compiler warning */

/* Msg(4:2015) This label is not a case or default label for a switch statement. MISRA Rule 55 */
finishRxFullCan:

  /* make receive buffer free*/
  /* KB begin CanLL_RxFullReleaseObj */
  /* KB end CanLL_RxFullReleaseObj */
  /* KB begin CanLL_RxFullMsgReceivedEnd */
  /* KB end CanLL_RxFullMsgReceivedEnd */


  return;    /* to avoid compiler warnings about label without code */
}
/* CODE CATEGORY 1 END*/
/* PRQA S 2001 -- */    /* suppress misra message about usage of goto */

#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )  || \
    defined( C_ENABLE_RX_BASICCAN_OBJECTS )
# if ( kCanNumberOfRxObjects > 0 )
/****************************************************************************
| NAME:             CanHL_ReceivedRxHandle
| CALLED BY:        CanBasicCanMsgReceived, CanFullCanMsgReceived
| PRECONDITIONS:
| INPUT PARAMETERS: Handle of received Message to access generated data
| RETURN VALUES:    none
| DESCRIPTION:      DLC-check, Precopy and copy of Data for received message
****************************************************************************/
/* CODE CATEGORY 1 START*/
#  if defined( C_ENABLE_RX_QUEUE )
static vuint8 CanHL_ReceivedRxHandle( CAN_CHANNEL_CANTYPE_FIRST tCanRxInfoStruct *pCanRxInfoStruct )
{
#  else
static vuint8 CanHL_ReceivedRxHandle( CAN_CHANNEL_CANTYPE_ONLY )
{
#  endif
#  if !defined( C_ENABLE_RX_QUEUE ) &&\
    defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  tCanRxInfoStruct    *pCanRxInfoStruct;
#  endif

#  if defined( C_ENABLE_COPY_RX_DATA )
#   if C_SECURITY_LEVEL > 20
  CanDeclareGlobalInterruptOldStatus
#   endif
#  endif

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(channel < kCanNumberOfChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);  /* PRQA S 3109 */
# endif

#  if !defined( C_ENABLE_RX_QUEUE ) &&\
    defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )
  pCanRxInfoStruct =  &canRxInfoStruct[channel];
#  endif

#  if defined( C_ENABLE_MULTI_ECU_PHYS )
  if ( (CanRxIdentityAssignment[CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)] & V_ACTIVE_IDENTITY_MSK) == (tVIdentityMsk)0 )
  {
    /* message is not a receive message in the active indentity */
    CANDRV_SET_CODE_TEST_POINT(0x10B);
    return  kCanHlFinishRx;
  }
#  endif


#  if defined( C_ENABLE_DLC_CHECK )  
#   if defined( C_ENABLE_DLC_CHECK_MIN_DATALEN )
  if ( (CanGetRxMinDataLen(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel))) > CanRxActualDLC( CAN_HL_P_RX_INFO_STRUCT(channel) ) )
#   else
  if ( (CanGetRxDataLen(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel))) > CanRxActualDLC( CAN_HL_P_RX_INFO_STRUCT(channel) ) )
#   endif
  {
    /* ##RI1.4 - 2.7: Callbackfunction-DLC-Check */
#   if defined( C_ENABLE_DLC_FAILED_FCT )
    ApplCanMsgDlcFailed( CAN_HL_P_RX_INFO_STRUCT(channel) ); 
#   endif  /*C_ENABLE_DLC_FAILED_FCT */
    return  kCanHlFinishRx;
  }
#  endif

#  if defined( C_ENABLE_VARIABLE_RX_DATALEN )
  CanSetVariableRxDatalen (CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel), CanRxActualDLC( CAN_HL_P_RX_INFO_STRUCT(channel)));
#  endif

#  if defined( C_ENABLE_GENERIC_PRECOPY )
  if ( APPL_CAN_GENERIC_PRECOPY( CAN_HL_P_RX_INFO_STRUCT(channel) ) != kCanCopyData)
  {
    return kCanHlFinishRx;  
  }
#  endif

#  if defined( C_ENABLE_PRECOPY_FCT )
#   if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
#   else
  if ( CanGetApplPrecopyPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)) != V_NULL )    /*precopy routine */
#   endif
  {
    /* canRxHandle in indexed drivers only for consistancy check in higher layer modules */
    canRxHandle[channel] = CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel);
    
    if ( CanGetApplPrecopyPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel))( CAN_HL_P_RX_INFO_STRUCT(channel) )==kCanNoCopyData )
    {  /* precopy routine returns kCanNoCopyData:   */
      return  kCanHlFinishRx;
    }                      /* do not copy data check next irpt */
  }
#  endif

#  if defined( C_ENABLE_COPY_RX_DATA )
  /* no precopy or precopy returns kCanCopyData : copy data -- */
  /* copy via index -------------------------------------------*/
  if ( CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)) != V_NULL )      /* copy if buffer exists */
  {
    /* copy data ---------------------------------------------*/
#   if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptDisable();
#   endif
    CANDRV_SET_CODE_TEST_POINT(0x107);
#   if defined( C_ENABLE_COPY_RX_DATA_WITH_DLC )
    if ( CanRxActualDLC( CAN_HL_P_RX_INFO_STRUCT(channel)) < CanGetRxDataLen(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)) )
    {
#    if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )    
      /* KB begin CanLL_RxCopyFromCan */
        vsint16         copycount;
        CanChipDataPtr  sptr;
        V_DEF_P2VAR(V_NONE, vuint8, AUTOMATIC, APPL_VAR) dptr;
      
        sptr = pCanRxInfoStruct->pChipData;
        dptr = CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)); 
      
        for (copycount = CanRxActualDLC(CAN_HL_P_RX_INFO_STRUCT(channel)); copycount > 0; copycount--)
        {
          /* copy data from CAN receive buffer to the RAM buffer */
          *dptr = *sptr;
          dptr++;
          sptr++;
        }
      
      /* KB end CanLL_RxCopyFromCan */
#    else
      /* KB begin CanLL_RxCopyFromCan */
        vsint16         copycount;
        CanChipDataPtr  sptr;
        V_DEF_P2VAR(V_NONE, vuint8, AUTOMATIC, APPL_VAR) dptr;
      
        sptr = canRxInfoStruct[channel].pChipData;
        dptr = CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)); 
      
        for (copycount = CanRxActualDLC(CAN_HL_P_RX_INFO_STRUCT(channel)); copycount > 0; copycount--)
        {
          /* copy data from CAN receive buffer to the RAM buffer */
          *dptr = *sptr;
          dptr++;
          sptr++;
        }
      
      /* KB end CanLL_RxCopyFromCan */
#    endif 
    }
    else
#   endif   /* C_ENABLE_COPY_RX_DATA_WITH_DLC */
    {
#   if defined( C_HL_ENABLE_RX_INFO_STRUCT_PTR )    
      /* KB begin CanLL_RxCopyFromCan */
        vsint16         copycount;
        CanChipDataPtr  sptr;
        V_DEF_P2VAR(V_NONE, vuint8, AUTOMATIC, APPL_VAR) dptr;
      
        sptr = pCanRxInfoStruct->pChipData;
        dptr = CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)); 
      
        for (copycount = CanGetRxDataLen(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)); copycount > 0; copycount--)
        {
          /* copy data from CAN receive buffer to the RAM buffer */
          *dptr = *sptr;
          dptr++;
          sptr++;
        }
      
      /* KB end CanLL_RxCopyFromCan */
#   else
      /* KB begin CanLL_RxCopyFromCan */
        vsint16         copycount;
        CanChipDataPtr  sptr;
        V_DEF_P2VAR(V_NONE, vuint8, AUTOMATIC, APPL_VAR) dptr;
      
        sptr = canRxInfoStruct[channel].pChipData;
        dptr = CanGetRxDataPtr(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)); 
      
        for (copycount = CanGetRxDataLen(CAN_HL_P_RX_INFO_STRUCT_HANDLE(channel)); copycount > 0; copycount--)
        {
          /* copy data from CAN receive buffer to the RAM buffer */
          *dptr = *sptr;
          dptr++;
          sptr++;
        }
      
      /* KB end CanLL_RxCopyFromCan */
#   endif 
    }
#   if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptRestore();
#   endif
  }
#  endif /* ( C_ENABLE_COPY_RX_DATA ) */

  CANDRV_SET_CODE_TEST_POINT(0x105);
  return kCanHlContinueRx;
} /* end of CanReceivceRxHandle() */
/* CODE CATEGORY 1 END*/

#  if defined( C_ENABLE_INDICATION_FLAG ) || \
     defined( C_ENABLE_INDICATION_FCT )
/****************************************************************************
| NAME:             CanHL_IndRxHandle
| CALLED BY:        CanBasicCanMsgReceived, CanFullCanMsgReceived
| PRECONDITIONS:
| INPUT PARAMETERS: Handle of received Message to access generated data
| RETURN VALUES:    none
| DESCRIPTION:      DLC-check, Precopy and copy of Data for received message
****************************************************************************/
/* CODE CATEGORY 1 START*/
static void CanHL_IndRxHandle( CanReceiveHandle rxHandle )
{
#   if defined( C_ENABLE_INDICATION_FLAG )
#    if C_SECURITY_LEVEL > 20
  CanDeclareGlobalInterruptOldStatus
#    endif
#   endif

#   if defined( C_ENABLE_INDICATION_FLAG )
#    if C_SECURITY_LEVEL > 20
  CanNestedGlobalInterruptDisable();
#    endif
  CanIndicationFlags._c[CanGetIndicationOffset(rxHandle)] |= CanGetIndicationMask(rxHandle);
#    if C_SECURITY_LEVEL > 20
  CanNestedGlobalInterruptRestore();
#    endif
#   endif

#   if defined( C_ENABLE_INDICATION_FCT )
#    if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
#    else
  if ( CanGetApplIndicationPtr(rxHandle) != V_NULL )
#    endif
  {
    CanGetApplIndicationPtr(rxHandle)(rxHandle);  /* call IndicationRoutine */
  }
#   endif
}
/* CODE CATEGORY 1 END*/
#  endif /* C_ENABLE_INDICATION_FLAG || C_ENABLE_INDICATION_FCT  */
# endif /* ( kCanNumberOfRxObjects > 0 ) */
#endif


/****************************************************************************
| NAME:             CanHL_TxConfirmation
| CALLED BY:        CanISR()
| PRECONDITIONS:
| INPUT PARAMETERS: - internal can chip number
|                   - interrupt ID
| RETURN VALUES:    none
| DESCRIPTION:      - full can transmit
****************************************************************************/
/* PRQA S 2001 ++ */    /* suppress misra message about usage of goto */
/* CODE CATEGORY 1 START*/
static void CanHL_TxConfirmation( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle txObjHandle)
{
  CanObjectHandle       logTxObjHandle;
  CanTransmitHandle     txHandle;

 
#if defined( C_ENABLE_TRANSMIT_QUEUE )
  /* KB begin CanHL_LocalParameterTxQueueRestart */
  CanSignedTxHandle         queueElementIdx;    /* use as signed due to loop */
  CanSignedTxHandle         elementBitIdx;
  tCanQueueElementType             elem;
  /* KB end CanHL_LocalParameterTxQueueRestart */
  CanDeclareGlobalInterruptOldStatus
#else
# if defined( C_ENABLE_CONFIRMATION_FLAG )
#  if C_SECURITY_LEVEL > 20
  CanDeclareGlobalInterruptOldStatus
#  endif
# endif
#endif


#if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION ) && \
    defined( C_ENABLE_TRANSMIT_QUEUE )
  vuint8 rc;
#endif

  /* KB begin CanLL_TxMsgConfLocalParameter */
  CanDeclarePointerToCanHardware;
  CanSetPointerToCanHardware;
  /* KB end CanLL_TxMsgConfLocalParameter */


# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(canHwChannel < kCanNumberOfHwChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);  /* PRQA S 3109 */
# endif



  logTxObjHandle = (CanObjectHandle)((vsintx)txObjHandle + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));

  /* KB begin CanLL_TxMsgConfBegin */
  {
    CanDeclareGlobalInterruptOldStatus 
    CanNestedGlobalInterruptDisable();
  
    IF_TRANSMIT.ComMask       =  kSetWrRd  |  kSetControl | kSetClrIntPnd;
  
    if(CAN_INDIV_POLLING(channel,txObjHandle) != 0)
    {
      IF_TRANSMIT.MessageCntrl   = kSetEoB;
    }
    else
    {
      IF_TRANSMIT.MessageCntrl   = kSetEoB |  kSetEnableTxCanInt;
    }
  
    IF_TRANSMIT.ComRequest    =  txObjHandle + 1;
    CanNestedGlobalInterruptRestore();
  }
  /* KB end CanLL_TxMsgConfBegin */

  txHandle = canHandleCurTxObj[logTxObjHandle];           /* get saved handle */

  /* check associated transmit handle */
  if (txHandle == kCanBufferFree)
  {
    assertInternal (0, channel, kErrorTxHandleWrong);          /* PRQA S 3109 */ /*lint !e506 !e774*/
    goto finishCanHL_TxConfirmation;
  }  

#if defined( C_ENABLE_TX_OBSERVE ) || \
    defined( C_ENABLE_CAN_TX_CONF_FCT )
# if defined( C_ENABLE_CANCEL_IN_HW )
  /* KB begin CanLL_TxIsMsgTransmitted */
  /* KB end CanLL_TxIsMsgTransmitted */
# endif
  {
# if defined( C_ENABLE_TX_OBSERVE )
    {
      ApplCanTxObjConfirmed( CAN_CHANNEL_CANPARA_FIRST logTxObjHandle );
    }
# endif

# if defined( C_ENABLE_CAN_TX_CONF_FCT )
/* ##RI-1.10 Common Callbackfunction in TxInterrupt */
    txInfoStructConf[channel].Handle  = txHandle;
    /* KB begin CanLL_AddTxConfStructMember */
    /* KB end CanLL_AddTxConfStructMember */
    APPL_CAN_TX_CONFIRMATION(&txInfoStructConf[channel]);
# endif
  }
#endif /* defined( C_ENABLE_TX_OBSERVE ) || defined( C_ENABLE_CAN_TX_CONF_FCT ) */

#if defined( C_ENABLE_TRANSMIT_QUEUE )
# if defined( C_ENABLE_TX_FULLCAN_OBJECTS )  || \
     defined( C_ENABLE_MSG_TRANSMIT )
  if (txObjHandle != CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel))
  {
    canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;                 /* free msg object of FullCAN or LowLevel Tx obj. */
  }
# endif
#else
  canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;                   /* free msg object if queue is not used */
#endif

  if (txHandle != kCanBufferCancel)
  {
#if defined( C_ENABLE_MSG_TRANSMIT )
    if (txObjHandle == CAN_HL_HW_MSG_TRANSMIT_INDEX(canHwChannel))
    {
# if defined( C_ENABLE_MSG_TRANSMIT_CONF_FCT )
      APPL_CAN_MSGTRANSMITCONF( CAN_CHANNEL_CANPARA_ONLY );
# endif

      goto finishCanHL_TxConfirmation;
    }
#endif

#if defined( C_ENABLE_MULTI_ECU_PHYS )
    assertInternal(((CanTxIdentityAssignment[txHandle] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk)0 ), 
                                                                channel , kErrorInternalDisabledTxMessage);  /* PRQA S 3109 */
#endif

#if defined( C_ENABLE_CONFIRMATION_FLAG )       /* set transmit ready flag  */
# if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptDisable();
# endif
    CanConfirmationFlags._c[CanGetConfirmationOffset(txHandle)] |= CanGetConfirmationMask(txHandle);
# if C_SECURITY_LEVEL > 20
    CanNestedGlobalInterruptRestore();
# endif
#endif

#if defined( C_ENABLE_CONFIRMATION_FCT )
    {
# if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
# else
      if ( CanGetApplConfirmationPtr(txHandle) != V_NULL )
# endif
      {
        (CanGetApplConfirmationPtr(txHandle))(txHandle);   /* call completion routine  */
      }
    }
#endif /* C_ENABLE_CONFIRMATION_FCT */

  } /* end if kCanBufferCancel */
  
#if defined( C_ENABLE_TRANSMIT_QUEUE )
# if defined( C_ENABLE_TX_FULLCAN_OBJECTS ) ||\
     defined( C_ENABLE_MSG_TRANSMIT )
  if (txObjHandle == CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel)) 
# endif
  {
    CanNestedGlobalInterruptDisable();                /* ESCAN00008914 */

    /* KB begin CanHL_TxQueueIsAnyObjQueuedBegin */
    for(queueElementIdx = CAN_HL_TXQUEUE_STOPINDEX(channel) - (CanSignedTxHandle)1; 
                             queueElementIdx >= CAN_HL_TXQUEUE_STARTINDEX(channel); queueElementIdx--)
    {
      elem = canTxQueueFlags[queueElementIdx];
      if(elem != (tCanQueueElementType)0) /* is there any flag set in the queue element? */
      {
    /* KB end CanHL_TxQueueIsAnyObjQueuedBegin */

        CanNestedGlobalInterruptRestore();

        /* KB begin CanHL_TxQueueSearchQueuedTxHandleBegin */
        /* start the bitsearch */
        #if defined( C_CPUTYPE_32BIT )
        if((elem & (tCanQueueElementType)0xFFFF0000) != (tCanQueueElementType)0)
        {
          if((elem & (tCanQueueElementType)0xFF000000) != (tCanQueueElementType)0)
          {
            if((elem & (tCanQueueElementType)0xF0000000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 28] + 28;
            }
            else /*0x0F000000*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 24] + 24;
            }
          }
          else
          {
            if((elem & (tCanQueueElementType)0x00F00000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 20] + 20;
            }
            else /* 0x000F0000*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 16] + 16;
            }
          }
        }
        else
        #endif
        {
        #if defined( C_CPUTYPE_32BIT ) || defined( C_CPUTYPE_16BIT )
          if((elem & (tCanQueueElementType)0x0000FF00) != (tCanQueueElementType)0)
          {
            if((elem & (tCanQueueElementType)0x0000F000) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 12] + 12;
            }
            else /*0x00000F00*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 8] + 8;
            }
          }
          else
        #endif
          {
            if((elem & (tCanQueueElementType)0x000000F0) != (tCanQueueElementType)0)
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem >> 4] + 4;
            }
            else /* 0x0000000F*/
            {
              elementBitIdx = (CanSignedTxHandle)CanGetHighestFlagFromNibble[elem];
            }
          }
        }
        txHandle = (CanTransmitHandle)((((CanTransmitHandle)queueElementIdx << kCanTxQueueShift) + (CanTransmitHandle)elementBitIdx) - CAN_HL_TXQUEUE_PADBITS(channel));
        {
        /* KB end CanHL_TxQueueSearchQueuedTxHandleBegin */

            /* compute the logical message handle */
            CanNestedGlobalInterruptDisable();
 
            /* KB begin CanHL_TxQueueVerifyAndRemoveRequest */
            if ( (canTxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) != (tCanQueueElementType)0 )
            {
              canTxQueueFlags[queueElementIdx] &= ~CanShiftLookUp[elementBitIdx]; /* clear flag from the queue */
            /* KB end CanHL_TxQueueVerifyAndRemoveRequest */

              CanNestedGlobalInterruptRestore();  
              canHandleCurTxObj[logTxObjHandle] = txHandle;/* Save hdl of msgObj to be transmitted*/
# if defined( C_ENABLE_CAN_CANCEL_NOTIFICATION )
              rc = CanCopyDataAndStartTransmission( CAN_CHANNEL_CANPARA_FIRST txObjHandle,txHandle); 
              if ( rc == kCanTxNotify)
              {
                APPLCANCANCELNOTIFICATION(channel, txHandle);
              }
# else       /* C_ENABLE_CAN_CANCEL_NOTIFICATION */
              (void)CanCopyDataAndStartTransmission( CAN_CHANNEL_CANPARA_FIRST txObjHandle,txHandle); 
# endif /* C_ENABLE_CAN_CANCEL_NOTIFICATION */

              goto finishCanHL_TxConfirmation;
            }
            /* meanwhile, the queue is empty. E.g. due to CanOffline on higher level */
            canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;  /* free msg object if queue is empty */
            CanNestedGlobalInterruptRestore();  
            goto finishCanHL_TxConfirmation;
            
        /* KB begin CanHL_TxQueueSearchQueuedTxHandleEnd */
        }
        /* KB end CanHL_TxQueueSearchQueuedTxHandleEnd */
        /* no entry found in Queue */
# if defined( CANHL_TX_QUEUE_BIT )
# else
        CanNestedGlobalInterruptDisable();                /*lint !e527 ESCAN00008914 */
                                                 /* unreachable in case of Bit-Queue */
# endif                                                 
    /* KB begin CanHL_TxQueueIsAnyObjQueuedEnd */
      }
    }
    /* KB end CanHL_TxQueueIsAnyObjQueuedEnd */

    canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;  /* free msg object if queue is empty */
    CanNestedGlobalInterruptRestore();                 /* ESCAN00008914 */
  }
#endif
  /* check for next msg object in queue and transmit it */

/* Msg(4:2015) This label is not a case or default label for a switch statement. MISRA Rule 55 */
finishCanHL_TxConfirmation:

  /* KB begin CanLL_TxMsgConfEnd */
  /* KB end CanLL_TxMsgConfEnd */

  return;

} /* END OF CanTxInterrupt */
/* CODE CATEGORY 1 END*/
/* PRQA S 2001 -- */    /* suppress misra message about usage of goto */


#if defined( C_ENABLE_ECU_SWITCH_PASS )
/************************************************************************
* NAME:               CanSetActive
* CALLED BY:          application
* PRECONDITIONS:      none
* PARAMETER:          none or channel
* RETURN VALUE:       none
* DESCRIPTION:        Set the CAN driver into active mode
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetActive( CAN_CHANNEL_CANTYPE_ONLY )
{
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#endif

  canPassive[channel] = 0;
} /* END OF CanSetActive */
/* CODE CATEGORY 4 END*/

/************************************************************************
* NAME:               CanSetPassive
* CALLED BY:          application
* PRECONDITIONS:      none
* PARAMETER:          none or channel
* RETURN VALUE:       none
* DESCRIPTION:        Set the can driver into passive mode
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetPassive( CAN_CHANNEL_CANTYPE_ONLY )
{
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);      /* PRQA S 3109 */
#endif

  canPassive[channel] = 1;
 
# if defined( C_ENABLE_TRANSMIT_QUEUE )
  /* clear all Tx queue flags: */
  CanDelQueuedObj( CAN_CHANNEL_CANPARA_ONLY ); 
# endif
 

} /* END OF CanSetPassive */
/* CODE CATEGORY 4 END*/
#endif /* IF defined( C_ENABLE_ECU_SWITCH_PASS ) */


#if defined( C_ENABLE_OFFLINE )
/************************************************************************
* NAME:               CanOnline( CanChannelHandle channel )
* CALLED BY:          netmanagement
* PRECONDITIONS:      none
* PARAMETER:          none or channel
* RETURN VALUE:       none
* DESCRIPTION:        Switch on transmit path
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanOnline(CAN_CHANNEL_CANTYPE_ONLY)
{
  CanDeclareGlobalInterruptOldStatus

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
#endif

  CanNestedGlobalInterruptDisable();

  canStatus[channel] |= kCanTxOn;

# if defined( C_ENABLE_ONLINE_OFFLINE_CALLBACK_FCT )
  APPL_CAN_ONLINE(CAN_CHANNEL_CANPARA_ONLY);
# endif
  CanNestedGlobalInterruptRestore();

}
/* CODE CATEGORY 4 END*/


/************************************************************************
* NAME:               CanOffline( CanChannelHandle channel )
* CALLED BY:          netmanagement
* PRECONDITIONS:      none
* PARAMETER:          none or channel
* RETURN VALUE:       none
* DESCRIPTION:        Switch off transmit path
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanOffline(CAN_CHANNEL_CANTYPE_ONLY) C_API_3
{
  CanDeclareGlobalInterruptOldStatus

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#endif

  CanNestedGlobalInterruptDisable();

  canStatus[channel] &= kCanTxNotOn;

# if defined( C_ENABLE_ONLINE_OFFLINE_CALLBACK_FCT )
  APPL_CAN_OFFLINE(CAN_CHANNEL_CANPARA_ONLY);
# endif
  CanNestedGlobalInterruptRestore();

# if defined( C_ENABLE_TRANSMIT_QUEUE )
  CanDelQueuedObj( CAN_CHANNEL_CANPARA_ONLY );
# endif

}
/* CODE CATEGORY 4 END*/
#endif /* if defined( C_ENABLE_OFFLINE ) */


#if defined( C_ENABLE_PART_OFFLINE )
/************************************************************************
* NAME:               CanSetPartOffline
* CALLED BY:          application
* PRECONDITIONS:      none
* PARAMETER:          (channel), sendGroup
* RETURN VALUE:       none
* DESCRIPTION:        Switch partial off transmit path
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetPartOffline(CAN_CHANNEL_CANTYPE_FIRST vuint8 sendGroup)
{
  CanDeclareGlobalInterruptOldStatus

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
#endif

  CanNestedGlobalInterruptDisable();
  canTxPartOffline[channel] |= sendGroup;   /* set offlinestate and Save for use of CanOnline/CanOffline */
  CanNestedGlobalInterruptRestore();
}
/* CODE CATEGORY 4 END*/


/************************************************************************
* NAME:               CanSetPartOnline
* CALLED BY:          application
* PRECONDITIONS:      none
* PARAMETER:          (channel), invSendGroup
* RETURN VALUE:       none
* DESCRIPTION:        Switch partial on transmit path
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetPartOnline(CAN_CHANNEL_CANTYPE_FIRST vuint8 invSendGroup)
{
  CanDeclareGlobalInterruptOldStatus

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
#endif

  CanNestedGlobalInterruptDisable();
  canTxPartOffline[channel] &= invSendGroup;
  CanNestedGlobalInterruptRestore();
}
/* CODE CATEGORY 4 END*/


/************************************************************************
* NAME:               CanGetPartMode
* CALLED BY:          application
* PRECONDITIONS:      none
* PARAMETER:          none or channel
* RETURN VALUE:       canTxPartOffline
* DESCRIPTION:        return status of partoffline-Mode
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanGetPartMode(CAN_CHANNEL_CANTYPE_ONLY)
{
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
#endif

  return canTxPartOffline[channel];
}
/* CODE CATEGORY 4 END*/
#endif


/****************************************************************************
| NAME:             CanGetStatus
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none or channel
| RETURN VALUES:    Bit coded status (more than one status can be set):
|                   kCanTxOn
|                   kCanHwIsStop        
|                   kCanHwIsInit        
|                   kCanHwIsInconsistent
|                   kCanHwIsWarning     
|                   kCanHwIsPassive     
|                   kCanHwIsBusOff      
|                   kCanHwIsSleep       
| DESCRIPTION:      returns the status of the transmit path and the CAN hardware.
|                   Only one of the statusbits Sleep,Busoff,Passiv,Warning is set.
|                   Sleep has the highest priority, error warning the lowerst. 
****************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 vuint8 C_API_2 CanGetStatus( CAN_CHANNEL_CANTYPE_ONLY ) C_API_3
{
#if defined( C_ENABLE_EXTENDED_STATUS )
  /* KB begin CanLL_GetStatusLocalParameter */
  /* KB end CanLL_GetStatusLocalParameter */
#endif


#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
#endif

#if defined( C_ENABLE_EXTENDED_STATUS )
  /* KB begin CanLL_GetStatusBegin */
  /* KB end CanLL_GetStatusBegin */

# if defined( C_ENABLE_SLEEP_WAKEUP )
  /***************************** verify Sleep mode *************************************/
  if ( CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY)   )  { return ( VUINT8_CAST ( canStatus[channel] | kCanHwIsSleep ) ); }

# endif

  /***************************** verify Stop mode *************************************/
  if ( CanLL_HwIsStop(CAN_HW_CHANNEL_CANPARA_ONLY)    )  { return ( VUINT8_CAST ( canStatus[channel] | kCanHwIsStop ) ); }

  /***************************** verify Busoff *************************************/
  if ( CanLL_HwIsBusOff(CAN_HW_CHANNEL_CANPARA_ONLY)  )  { return ( VUINT8_CAST ( canStatus[channel] | kCanHwIsBusOff ) ); }

  /***************************** verify Error Passiv *******************************/
  {
    if ( CanLL_HwIsPassive(CAN_HW_CHANNEL_CANPARA_ONLY) )  { return ( VUINT8_CAST ( canStatus[channel] | kCanHwIsPassive ) ); }
  }

  /***************************** verify Error Warning ******************************/
  {
    if ( CanLL_HwIsWarning(CAN_HW_CHANNEL_CANPARA_ONLY) )  { return ( VUINT8_CAST ( canStatus[channel] | kCanHwIsWarning ) ); }
  }
#endif
  return ( VUINT8_CAST (canStatus[channel] & kCanTxOn) );

} /* END OF CanGetStatus */
/* CODE CATEGORY 3 END*/


/****************************************************************************
| NAME:             CanSleep
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none or channel
| RETURN VALUES:    kCanOk, if CanSleep was successfull
|                   kCanFailed, if function failed
|                   kCanNotSupported, if this function is not supported
| DESCRIPTION:      disable CAN 
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanSleep(CAN_CHANNEL_CANTYPE_ONLY)
{
#if defined( C_ENABLE_SLEEP_WAKEUP )
  vuint8         canReturnCode;
#endif

#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
#endif
  assertUser((canCanInterruptCounter[channel] == (vsintx)0), channel, kErrorDisabledCanInt);    /* PRQA S 3109 */

#if defined( C_ENABLE_COND_RECEIVE_FCT )
  /* this has to be done, even if SLEEP_WAKEUP is not enabled */
  canMsgCondRecState[channel] = kCanTrue;
#endif

#if defined( C_ENABLE_SLEEP_WAKEUP )

  assertUser((canStatus[channel] & kCanTxOn) != kCanTxOn, channel, kErrorCanOnline);   /* PRQA S 3109 */

  {
    assertUser(!CanLL_HwIsStop(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanStop);     /* PRQA S 3109 */
    /* KB begin CanLL_Sleep */
    {
    #if (defined (C_COMP_TI_TMS470_DCAN) )
    CanDeclareGlobalInterruptOldStatus
    # if defined (C_ENABLE_WAKEUP_POLLING)
    #  if (CAN_ENABLE_SLEEP_WAKEUP_GLOBAL != STD_ON)
    CanDeclarePointerToCanHardware;
    CanSetPointerToCanHardware;
    #  endif
    # else
    CanDeclarePointerToCanHardware;
    CanSetPointerToCanHardware;
    # endif
    #endif
    
    
    
    CanNestedGlobalInterruptDisable();
    
    #if (defined (C_COMP_TI_TMS470_DCAN) )
    
    
    #  if defined( C_ENABLE_WAKEUP_POLLING )
    #  else
    CNTRLREG |= kSetSIE;
    #  endif
    
    canReturnCode = ApplCanGoToSleepModeRequest(CAN_CHANNEL_CANPARA_ONLY);
    if(canReturnCode == kCanOk) 
    { 
      STATUS_SLEEP(channel) = kCanTrue;
    }
    #endif
    
    
    CanNestedGlobalInterruptRestore(); 
    }
    /* KB end CanLL_Sleep */
  }
  return canReturnCode;
#else
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && \
     defined( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;
# endif
  return kCanNotSupported;
#endif
} /* END OF CanSleep */
/* CODE CATEGORY 4 END*/

/****************************************************************************
| NAME:             CanWakeUp
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none or channel
| RETURN VALUES:    kCanOk, if CanWakeUp was successfull
|                   kCanFailed, if function failed
|                   kCanNotSupported, if this function is not supported
| DESCRIPTION:      enable CAN 
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanWakeUp( CAN_CHANNEL_CANTYPE_ONLY )
{
#if defined( C_ENABLE_SLEEP_WAKEUP )
  vuint8         canReturnCode;


#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#endif
  assertUser((canCanInterruptCounter[channel] == (vsintx)0), channel, kErrorDisabledCanInt);    /* PRQA S 3109 */

  {
    /* KB begin CanLL_WakeUp */
    #if (defined (C_COMP_TI_TMS470_DCAN) )
    #endif
    CanDeclareGlobalInterruptOldStatus
    CanDeclarePointerToCanHardware;
    CanSetPointerToCanHardware;
    
    
    CanNestedGlobalInterruptDisable();
    
    #if (defined (C_COMP_TI_TMS470_DCAN) )
    canReturnCode = ApplCanWakeUpFromSleepModeRequest(CAN_CHANNEL_CANPARA_ONLY);
    
    if(canReturnCode == kCanOk)
    {
      CNTRLREG = NORMAL_MODE(channel);
      STATUS_SLEEP(channel)   = 0;
      STATUS_BUS_OFF(channel) = 0;
      CAN_LL_STATUS(channel)  = STATREG;
    }
    #endif
    
    
    CanNestedGlobalInterruptRestore();      
    /* KB end CanLL_WakeUp */
  }
  return canReturnCode;
#else
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && \
     defined( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;
# endif
  return kCanNotSupported;
#endif /* C_ENABLE_SLEEP_WAKEUP */
} /* END OF CanWakeUp */
/* CODE CATEGORY 4 END*/


#if defined( C_ENABLE_STOP )
/****************************************************************************
| NAME:             CanStop
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    kCanOk, if success
|                   kCanFailed, if function failed
|                   kCanNotSupported, if this function is not supported
| DESCRIPTION:      stop CAN-controller
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanStop( CAN_CHANNEL_CANTYPE_ONLY )
{
  vuint8         canReturnCode;

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
# endif
  assertUser((canStatus[channel] & kCanTxOn) != kCanTxOn, channel, kErrorCanOnline);   /* PRQA S 3109 */

  {
# if defined( C_ENABLE_SLEEP_WAKEUP )
    assertUser(!CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanSleep);   /* PRQA S 3109 */
# endif
    /* KB begin CanLL_Stop */
    {
    #if defined( C_ENABLE_DCAN_ISSUE22_WORKAROUND )
      vuint16 nbOfIterations;
    #endif  
      CanDeclarePointerToCanHardware;
      CanSetPointerToCanHardware;
    
      if((CNTRLREG & kSetInit) == 0)
      {
        CNTRLREG |= kSetInit;
    #if defined( C_ENABLE_DCAN_ISSUE22_WORKAROUND )
        /* neither power-on nor bus-off did occur -> DCAN#22 issue workaround is necessary */
        /* according to the erratum the CAN interrupts have to locked at this point */
    
        /* wait into the loop at least 6 CAN clock cycles */
        nbOfIterations = CAN_GLOBAL_CONFIG(CanErrata22Iterations);
        while(nbOfIterations > 0)
        {
          nbOfIterations--;
          asm(" nop");
          asm(" nop");
          asm(" nop");
          asm(" nop");
          asm(" nop");
          asm(" nop");
        }
    
        CNTRLREG |= kSetSWR;
    #endif
      }
    
      STATUS_STOP_MODE(channel) = kSetStopMode;
      canReturnCode = kCanOk;
    }
    /* KB end CanLL_Stop */
  }
  return canReturnCode;
}
/* CODE CATEGORY 4 END*/

/****************************************************************************
| NAME:             CanStart
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    kCanOk, if success
|                   kCanFailed, if function failed
|                   kCanNotSupported, if this function is not supported
| DESCRIPTION:      restart CAN-controller
****************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 vuint8 C_API_2 CanStart( CAN_CHANNEL_CANTYPE_ONLY )
{
  vuint8         canReturnCode;

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
# endif

  {
    /* KB begin CanLL_Start */
    # if defined( C_ENABLE_DCAN_ISSUE22_WORKAROUND )
    /* CBD: due to stop mode DCAN is hardware initialized (SWR), and that means transition to normal mode = CanInit() */
    CanInit(CAN_CHANNEL_CANPARA_FIRST lastInitObject[channel]);
    # else
    {
      CanDeclarePointerToCanHardware;
      CanSetPointerToCanHardware;
    
      CNTRLREG = NORMAL_MODE(channel);
    }
    # endif
    STATUS_STOP_MODE(channel) = 0;
    canReturnCode = kCanOk;
    /* KB end CanLL_Start */
  }
  return canReturnCode;
}
/* CODE CATEGORY 4 END*/
#endif /* if defined( C_ENABLE_STOP ) */

#if defined (C_ENABLE_CAN_CAN_INTERRUPT_CONTROL)
/****************************************************************************
| NAME:             CanCanInterruptDisable
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      disables CAN interrupts and stores old interrupt status
****************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 CanCanInterruptDisable( CAN_CHANNEL_CANTYPE_ONLY ) C_API_3
{
# if defined (C_ENABLE_OSEK_CAN_INTCTRL)

  {
    OsCanCanInterruptDisable(CAN_HW_CHANNEL_CANPARA_ONLY);
  }
# else  /* defined (C_ENABLE_OSEK_CAN_INTCTRL) */

  CanDeclareGlobalInterruptOldStatus
#  if defined( C_HL_ENABLE_CAN_IRQ_DISABLE )
#  endif

  /* local variable must reside on stack or registerbank, switched */
  /* in interrupt level                                            */
  /* disable global interrupt                                      */
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
#  endif
  assertUser(canCanInterruptCounter[channel]<(vsint8)0x7f, kCanAllChannels, kErrorIntDisableTooOften);    /* PRQA S 3109 */

  CanNestedGlobalInterruptDisable();
  if (canCanInterruptCounter[channel] == (vsintx)0)  /* if 0 then save old interrupt status */
  {
#  if defined( C_HL_ENABLE_CAN_IRQ_DISABLE )
    {
#   if defined( C_ENABLE_SLEEP_WAKEUP )
      assertUser(!CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanSleep);     /* PRQA S 3109 */
#   endif

      CanLL_CanInterruptDisable(canHwChannel, &canCanInterruptOldStatus[canHwChannel]);
    }
#  endif
#  if defined( C_ENABLE_INTCTRL_ADD_CAN_FCT )
    ApplCanAddCanInterruptDisable(channel);
#  endif
  }
  canCanInterruptCounter[channel]++;               /* common for all platforms */

  CanNestedGlobalInterruptRestore();
# endif  /* C_ENABLE_OSEK_CAN_INTCTRL */
} /* END OF CanCanInterruptDisable */
/* CODE CATEGORY 1 END*/

/****************************************************************************
| NAME:             CanCanInterruptRestore
| CALLED BY:
| PRECONDITIONS:
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      restores the old interrupt status of the CAN interrupt if 
|                   canCanInterruptCounter[channel] is zero
****************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 CanCanInterruptRestore( CAN_CHANNEL_CANTYPE_ONLY ) C_API_3
{
# if defined (C_ENABLE_OSEK_CAN_INTCTRL)

  {
    OsCanCanInterruptRestore(CAN_HW_CHANNEL_CANPARA_ONLY);
  }
# else  /* defined (C_ENABLE_OSEK_CAN_INTCTRL) */

  CanDeclareGlobalInterruptOldStatus
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
#  endif
  assertUser(canCanInterruptCounter[channel]>(vsintx)0, kCanAllChannels, kErrorIntRestoreTooOften);   /* PRQA S 3109 */

  CanNestedGlobalInterruptDisable();
  /* restore CAN interrupt */
  canCanInterruptCounter[channel]--;

  if (canCanInterruptCounter[channel] == (vsintx)0)         /* restore interrupt if canCanInterruptCounter=0 */
  {
#  if defined( C_HL_ENABLE_CAN_IRQ_DISABLE )    
    {
#   if defined( C_ENABLE_SLEEP_WAKEUP )
      assertUser(!CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanSleep);   /* PRQA S 3109 */
#   endif

      CanLL_CanInterruptRestore(canHwChannel, canCanInterruptOldStatus[canHwChannel]);
    }
#  endif

#  if defined( C_ENABLE_INTCTRL_ADD_CAN_FCT )
    ApplCanAddCanInterruptRestore(channel);
#  endif
  }
  CanNestedGlobalInterruptRestore();
# endif  /* defined (C_ENABLE_OSEK_CAN_INTCTRL) */
} /* END OF CanCanInterruptRestore */
/* CODE CATEGORY 1 END*/
#endif /* defined (C_ENABLE_CAN_CAN_INTERRUPT_CONTROL) */

#if defined( C_ENABLE_MSG_TRANSMIT )
/************************************************************************
* NAME:               CanMsgTransmit
* CALLED BY:          CanReceivedFunction
* PRECONDITIONS:      Called in Receive Interrupt
* PARAMETER:          Pointer to message buffer data block; This can either be
*                     a RAM structure data block or the receive buffer in the
*                     CAN chip
* RETURN VALUE:       The return value says that a transmit request was successful
*                     or not
* DESCRIPTION:        Transmit functions for gateway issues (with dynamic
*                     messages). If the transmit buffer is not free, the message
*                     is inserted in the FIFO ring buffer.
*************************************************************************/
/* Msg(4:3673) The object addressed by the pointer "txMsgStruct" is not modified in this function.
   The use of "const" should be considered to indicate that it never changes. MISRA Rule 81 - no change */
/* CODE CATEGORY 2 START*/
# if defined ( V_ENABLE_USED_GLOBAL_VAR )
/* txMsgStruct is located in far memory */
C_API_1 vuint8 C_API_2 CanMsgTransmit( CAN_CHANNEL_CANTYPE_FIRST V_MEMRAM1_FAR tCanMsgTransmitStruct V_MEMRAM2_FAR V_MEMRAM3_FAR *txMsgStruct )       /* PRQA S 3673 */      /* suppress message about const pointer */
{
# else
C_API_1 vuint8 C_API_2 CanMsgTransmit( CAN_CHANNEL_CANTYPE_FIRST tCanMsgTransmitStruct *txMsgStruct )       /* PRQA S 3673 */      /* suppress message about const pointer */
{
# endif
  CanDeclareGlobalInterruptOldStatus
  vuint8                 rc;
  CanObjectHandle          txObjHandle;
  CanObjectHandle          logTxObjHandle;

  /* KB begin CanLL_TxTransmissionLocalParameter */
  #if defined( C_ENABLE_HW_LOOP_TIMER )
  vuint8 canTimerResult;
  #endif
  
  CanDeclarePointerToCanHardware;
  CanSetPointerToCanHardware; 
  
  /* KB end CanLL_TxTransmissionLocalParameter */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
# endif


  CanNestedGlobalInterruptDisable();

  /* --- test on CAN transmit switch --- */
  if ( (canStatus[channel] & kCanTxOn) != kCanTxOn )                /* transmit path switched off */
  {
    CanNestedGlobalInterruptRestore();
    return kCanTxFailed;
  }

# if defined( C_ENABLE_CAN_RAM_CHECK )
  if(canComStatus[channel] == kCanDisableCommunication)
  {
    CanNestedGlobalInterruptRestore();
    return(kCanCommunicationDisabled);
  }
# endif

# if defined( C_ENABLE_SLEEP_WAKEUP )
  assertUser(!CanLL_HwIsSleep(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanSleep);    /* PRQA S 3109 */
# endif
  assertUser(!CanLL_HwIsStop(CAN_HW_CHANNEL_CANPARA_ONLY), channel, kErrorCanStop);      /* PRQA S 3109 */
  
  /* --- check on passive state --- */
# if defined( C_ENABLE_ECU_SWITCH_PASS )
  if ( canPassive[channel] != (vuint8)0)                             /*  set passive ? */
  {
    CanNestedGlobalInterruptRestore();
#  if defined( C_ENABLE_MSG_TRANSMIT_CONF_FCT )
    APPL_CAN_MSGTRANSMITCONF( CAN_CHANNEL_CANPARA_ONLY );
#  endif
    return (kCanTxOk);
  }
# endif /* C_ENABLE_ECU_SWITCH_PASS */

  /* calculate index for canhandleCurTxObj (logical object handle) */
  logTxObjHandle = (CanObjectHandle)((vsintx)CAN_HL_HW_MSG_TRANSMIT_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel));

  /* check for transmit message object free ---------------------------------*/
  /* MsgObj used?  */
  if (( canHandleCurTxObj[logTxObjHandle] != kCanBufferFree ))    
  {
    CanNestedGlobalInterruptRestore();
    return kCanTxFailed;
  }

  /* Obj, pMsgObject points to is free, transmit msg object: ----------------*/
  /* Save hdl of msgObj to be transmitted*/
  canHandleCurTxObj[logTxObjHandle] = kCanBufferMsgTransmit;
  CanNestedGlobalInterruptRestore();



  txObjHandle = CAN_HL_HW_MSG_TRANSMIT_INDEX(canHwChannel);
  assertHardware( CanLL_TxIsHWObjFree(canHwChannel, txObjHandle ), channel, kErrorTxBufferBusy);

  /* KB begin CanLL_TxBegin */
  #if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  txObjHandle = txObjHandle;
  #endif
  /* KB end CanLL_TxBegin */

  CanNestedGlobalInterruptDisable();
  /* Copy all data into transmit object */


  /* If CanTransmit was interrupted by a re-initialization or CanOffline */  
  /* no transmitrequest of this action should be started      */  
  if ((canHandleCurTxObj[logTxObjHandle] == kCanBufferMsgTransmit) && 
                                   ( (canStatus[channel] & kCanTxOn) == kCanTxOn ) )
  {  
     /* KB begin CanLL_TxCopyMsgTransmit */
     
     APPLCANTIMERSTART(kCanLoopBusyReq);
     
     do{
     
         CANTIMERRESULT_UPDATE(kCanLoopBusyReq);
     
       } WHILE_CONDITON( ((IF_TRANSMIT.ComRequest & kIFxBusy) == kIFxBusy) );
     
     APPLCANTIMEREND(kCanLoopBusyReq);
     
         
     /* WrRd,Mask,Arb,Control,DataA,DataB set */
     IF_TRANSMIT.ComMask         =  kSetWrRd     |  kSetMask   |  kSetArb     |
                                    kSetControl  |  kSetDataA  |  kSetDataB;
     
     /* copy ID, Dlc and Data from the MsgObjectBuffer in IF1 */
     # if defined( C_ENABLE_EXTENDED_ID )
     IF_TRANSMIT.ArbitrFld1      =  (txMsgStruct->IdRawExt);
     # endif  
     IF_TRANSMIT.ArbitrFld2      =  (txMsgStruct->IdRaw) |  kSetMsgVal | kSetDir;
     
     /* set Dlc and TxRqst */
     IF_TRANSMIT.MessageCntrl    =  txMsgStruct->DlcRaw  |  kSetTxRqst | kSetEoB | kSetEnableTxCanInt;
     
     IF_TRANSMIT.Data.ucData[0]  =  *(V_DEF_P2SFR_CAN(V_NONE, vuint8, AUTOMATIC))&(txMsgStruct->DataFld[3]);
     IF_TRANSMIT.Data.ucData[1]  =  *(V_DEF_P2SFR_CAN(V_NONE, vuint8, AUTOMATIC))&(txMsgStruct->DataFld[2]);
     IF_TRANSMIT.Data.ucData[2]  =  *(V_DEF_P2SFR_CAN(V_NONE, vuint8, AUTOMATIC))&(txMsgStruct->DataFld[1]);
     IF_TRANSMIT.Data.ucData[3]  =  *(V_DEF_P2SFR_CAN(V_NONE, vuint8, AUTOMATIC))&(txMsgStruct->DataFld[0]);
     IF_TRANSMIT.Data.ucData[4]  =  *(V_DEF_P2SFR_CAN(V_NONE, vuint8, AUTOMATIC))&(txMsgStruct->DataFld[7]);
     IF_TRANSMIT.Data.ucData[5]  =  *(V_DEF_P2SFR_CAN(V_NONE, vuint8, AUTOMATIC))&(txMsgStruct->DataFld[6]);
     IF_TRANSMIT.Data.ucData[6]  =  *(V_DEF_P2SFR_CAN(V_NONE, vuint8, AUTOMATIC))&(txMsgStruct->DataFld[5]);
     IF_TRANSMIT.Data.ucData[7]  =  *(V_DEF_P2SFR_CAN(V_NONE, vuint8, AUTOMATIC))&(txMsgStruct->DataFld[4]);                                                      
     /* KB end CanLL_TxCopyMsgTransmit */

     /* KB begin CanLL_TxStartMsgTransmit */
     IF_TRANSMIT.ComRequest  =  CAN_HL_HW_MSG_TRANSMIT_INDEX(channel) + 1;
     
     TX_SEND_FLAG(channel, ((txObjHandle & 0xF8)>>3) ) |= ((vuint8)0x1<<(CAN_HL_HW_MSG_TRANSMIT_INDEX(channel) & 0x07));
     /* KB end CanLL_TxStartMsgTransmit */

# if defined( C_ENABLE_TX_OBSERVE )
     ApplCanTxObjStart( CAN_CHANNEL_CANPARA_FIRST logTxObjHandle );
# endif
   
     rc = kCanTxOk;                                    
  }  
  else  
  {  
    /* release TxHandle (CanOffline) */
    canHandleCurTxObj[logTxObjHandle] = kCanBufferFree;  
    rc = kCanTxFailed;   
  }  

  CanNestedGlobalInterruptRestore();

  /* KB begin CanLL_TxEnd */
  /* KB end CanLL_TxEnd */

  return rc;
} /*end of CanMsgTransmit() */
/* CODE CATEGORY 2 END*/
#endif


#if defined( C_ENABLE_DYN_TX_OBJECTS )
/************************************************************************
* NAME:           CanGetDynTxObj
* PARAMETER:      txHandle - Handle of the dynamic object to reserve
* RETURN VALUE:   kCanNoTxDynObjAvailable (0xFF) - 
*                   object not available
*                 0..F0 - 
*                   Handle to dynamic transmission object
* DESCRIPTION:    Function reserves and return a handle to a dynamic 
*                   transmission object
*
*                 To use dynamic transmission, an application must get
*                 a dynamic object from CAN-driver. 
*                 Before transmission, application must set all attributes 
*                 (id, dlc, data, confirmation function/flag, pretransmission
*                 etc. - as configurated). 
*                 Application can use a dynamic object for one or many
*                 transmissions (as it likes) - but finally, it must
*                 release the dynamic object by calling CanReleaseDynTxObj.
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 CanTransmitHandle C_API_2 CanGetDynTxObj(CanTransmitHandle txHandle ) C_API_3
{
  CanTransmitHandle nTxDynObj;
  CanDeclareGlobalInterruptOldStatus
  CAN_CHANNEL_CANTYPE_LOCAL
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);    /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
# endif

  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
# if ( kCanNumberOfTxStatObjects > 0) || defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */
# endif

  nTxDynObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel); /* PRQA S 3382,0291 */

  CanNestedGlobalInterruptDisable();
  if ( canTxDynObjReservedFlag[nTxDynObj] != (vuint8)0)
  {
    CanNestedGlobalInterruptRestore();
    return kCanNoTxDynObjAvailable;
  }
  /*  Mark dynamic object as used  */
  canTxDynObjReservedFlag[nTxDynObj] = 1;

# if defined( C_ENABLE_CONFIRMATION_FLAG )
  CanConfirmationFlags._c[CanGetConfirmationOffset(txHandle)] &= 
                            (vuint8)(~CanGetConfirmationMask(txHandle));
# endif
  CanNestedGlobalInterruptRestore();

  /* Initialize dynamic object */
# if defined( C_ENABLE_DYN_TX_DATAPTR )  
  canDynTxDataPtr[nTxDynObj] = V_NULL;  
# endif  
  

  return (txHandle);
}
/* CODE CATEGORY 3 END*/

/************************************************************************
* NAME:           CanReleaseDynTxObj
* PARAMETER:      hTxObj -
*                   Handle of dynamic transmission object
* RETURN VALUE:   --
* DESCRIPTION:    Function releases dynamic transmission object
*                   which was reserved before (calling CanGetDynTxObj)
*                 
*                 After a transmission of one or more messages is finished,
*                 application must free the reserved resource, formally the
*                 dynamic transmission object calling this function.
*
*                 As the number of dynamic transmission object is limited,
*                 application should not keep unused dynamic transmission
*                 objects for a longer time.
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 vuint8 C_API_2 CanReleaseDynTxObj(CanTransmitHandle txHandle) C_API_3
{
  CanTransmitHandle dynTxObj;
  CAN_CHANNEL_CANTYPE_LOCAL
# if defined( C_ENABLE_TRANSMIT_QUEUE )
  /* KB begin CanHL_LocalParameterTxQueueModifyEntry */
  CanSignedTxHandle queueElementIdx; /* index for accessing the tx queue */
  CanSignedTxHandle elementBitIdx;  /* bit index within the tx queue element */
  CanTransmitHandle queueBitPos;  /* physical bitposition of the handle */
  /* KB end CanHL_LocalParameterTxQueueModifyEntry */
# endif
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);    /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
# endif

  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
# if ( kCanNumberOfTxStatObjects > 0) || defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */
# endif

  dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel);  /* PRQA S 3382,0291 */

  assertInternal((canTxDynObjReservedFlag[dynTxObj] != (vuint8)0), channel, kErrorReleasedUnusedDynObj);  /* PRQA S 3109 */

# if defined( C_ENABLE_TRANSMIT_QUEUE )
  /* KB begin CanHL_TxQueueIfTxRequest */
  #if defined( C_ENABLE_INTERNAL_CHECK ) &&\
      defined( C_MULTIPLE_RECEIVE_CHANNEL )
  if (sizeof(queueBitPos) == 1)
  {
    assertInternal( (((vuint16)kCanNumberOfTxObjects + (vuint16)CanTxQueuePadBits[kCanNumberOfChannels-1]) <= 256u), kCanAllChannels, kErrorTxQueueTooManyHandle) /* PRQA S 3109 */ /*lint !e572 !e506*/
  }
  else
  {
    assertInternal( (((vuint32)kCanNumberOfTxObjects + (vuint32)CanTxQueuePadBits[kCanNumberOfChannels-1]) <= 65536u), kCanAllChannels, kErrorTxQueueTooManyHandle) /* PRQA S 3109 */ /*lint !e572 !e506*/
  }
  #endif
  queueBitPos  = txHandle + CAN_HL_TXQUEUE_PADBITS(channel);
  queueElementIdx = (CanSignedTxHandle)(queueBitPos >> kCanTxQueueShift); /* get the queue element where to set the flag */
  elementBitIdx  = (CanSignedTxHandle)(queueBitPos & kCanTxQueueMask);   /* get the flag index wihtin the queue element */
  if( (canTxQueueFlags[queueElementIdx] & CanShiftLookUp[elementBitIdx]) != (tCanQueueElementType)0 )
  {
  /* KB end CanHL_TxQueueIfTxRequest */
  }
  else
# endif
  {
    if (
# if defined( C_ENABLE_CONFIRMATION_FCT ) && \
    defined( C_ENABLE_TRANSMIT_QUEUE )
         (confirmHandle[channel] == txHandle) ||       /* confirmation active ? */
# endif
         (canHandleCurTxObj[(vsintx)CAN_HL_HW_TX_NORMAL_INDEX(canHwChannel) + CAN_HL_TX_OFFSET_HW_TO_LOG(canHwChannel)] != txHandle) )
    {
      /*  Mark dynamic object as not used  */
      canTxDynObjReservedFlag[dynTxObj] = 0;
      return(kCanDynReleased);
    }
  }
  return(kCanDynNotReleased);
}
/* CODE CATEGORY 3 END*/
#endif /* C_ENABLE_DYN_TX_OBJECTS */


#if defined( C_ENABLE_DYN_TX_ID ) 
# if !defined( C_ENABLE_EXTENDED_ID ) ||\
     defined( C_ENABLE_MIXED_ID )
/************************************************************************
* NAME:           CanDynTxObjSetId
* PARAMETER:      hTxObj -
*                   Handle of dynamic transmission object
*                 id -
*                   Id (standard-format) to register with dynamic object
* RETURN VALUE:   --
* DESCRIPTION:    Function registers submitted id (standard format)
*                 with dynamic object referenced by handle.
*************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetId(CanTransmitHandle txHandle, vuint16 id) C_API_3
{
  CanTransmitHandle dynTxObj;

  CAN_CHANNEL_CANTYPE_LOCAL
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);  /* PRQA S 3109 */

#  if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
#  endif

  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
# if ( kCanNumberOfTxStatObjects > 0) || defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */
# endif
  assertUser(id <= (vuint16)0x7FF, channel, kErrorWrongId);                                              /* PRQA S 3109 */

  dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel); /* PRQA S 3382,0291 */

#  if defined( C_ENABLE_MIXED_ID )
#   if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#   else
  canDynTxIdType[dynTxObj]  = kCanIdTypeStd; 
#   endif
#  endif

  canDynTxId0[dynTxObj] = MK_STDID0(id);
#  if (kCanNumberOfUsedCanTxIdTables > 1)
  canDynTxId1[dynTxObj] = MK_STDID1(id);
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 2)
  canDynTxId2[dynTxObj] = MK_STDID2(id);
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 3)
  canDynTxId3[dynTxObj] = MK_STDID3(id);
#  endif
#  if (kCanNumberOfUsedCanTxIdTables > 4)
  canDynTxId4[dynTxObj] = MK_STDID4(id);
#  endif
}
/* CODE CATEGORY 2 END*/
# endif /* !defined( C_ENABLE_EXTENDED_ID ) || defined( C_ENABLE_MIXED_ID ) */
#endif /* C_ENABLE_DYN_TX_ID */

#if defined( C_ENABLE_DYN_TX_ID ) && \
    defined( C_ENABLE_EXTENDED_ID )
/************************************************************************
* NAME:           CanDynTxObjSetExtId
* PARAMETER:      hTxObj -  Handle of dynamic transmission object
*                 idExtHi - Id low word (extended-format) to register with
*                                                         dynamic object
*                 idExtLo - Id high word (extended-format) 
* RETURN VALUE:   --
* DESCRIPTION:    Function registers submitted id (standard format)
*                 with dynamic object referenced by handle.
*************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetExtId(CanTransmitHandle txHandle, vuint16 idExtHi, vuint16 idExtLo) C_API_3
{
  CanTransmitHandle dynTxObj;
  CAN_CHANNEL_CANTYPE_LOCAL
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);   /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
# endif

  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
# if ( kCanNumberOfTxStatObjects > 0) || defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */
# endif
  assertUser(idExtHi <= (vuint16)0x1FFF, channel, kErrorWrongId);                                        /* PRQA S 3109 */

  dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel); /* PRQA S 3382,0291 */

# if defined( C_ENABLE_MIXED_ID )
#  if defined( C_HL_ENABLE_IDTYPE_IN_ID )
#  else
  canDynTxIdType[dynTxObj] = kCanIdTypeExt; 
#  endif
# endif

  canDynTxId0[dynTxObj]      = MK_EXTID0( ((vuint32)idExtHi<<16) | (vuint32)idExtLo );
# if (kCanNumberOfUsedCanTxIdTables > 1)
  canDynTxId1[dynTxObj]      = MK_EXTID1( ((vuint32)idExtHi<<16) | (vuint32)idExtLo );
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
  canDynTxId2[dynTxObj]      = MK_EXTID2( ((vuint32)idExtHi<<16) | (vuint32)idExtLo );
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
  canDynTxId3[dynTxObj]      = MK_EXTID3( ((vuint32)idExtHi<<16) | (vuint32)idExtLo );
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
  canDynTxId4[dynTxObj]      = MK_EXTID4( ((vuint32)idExtHi<<16) | (vuint32)idExtLo );
# endif
}
/* CODE CATEGORY 2 END*/
#endif


#if defined( C_ENABLE_DYN_TX_DLC )
/************************************************************************
* NAME:           CanDynTxObjSetDlc
* PARAMETER:      hTxObj -
*                   Handle of dynamic transmission object
*                 dlc -
*                   data length code to register with dynamic object
* RETURN VALUE:   --
* DESCRIPTION:    Function registers data length code with 
*                 dynamic object referenced by submitted handle.
*************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetDlc(CanTransmitHandle txHandle, vuint8 dlc) C_API_3
{
  CanTransmitHandle dynTxObj;
  CAN_CHANNEL_CANTYPE_LOCAL
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);     /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
# endif
  
  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
# if ( kCanNumberOfTxStatObjects > 0) || defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */
# endif
  assertUser(dlc<(vuint8)9, channel, kErrorTxDlcTooLarge);                                               /* PRQA S 3109 */
  
  dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel); /* PRQA S 3382,0291 */
  
# if defined( C_ENABLE_EXTENDED_ID )
  canDynTxDLC[dynTxObj] = MK_TX_DLC_EXT(dlc);
# else
  canDynTxDLC[dynTxObj] = MK_TX_DLC(dlc);
# endif
}
/* CODE CATEGORY 2 END*/
#endif /* C_ENABLE_DYN_TX_DLC */


#if defined( C_ENABLE_DYN_TX_DATAPTR )
/************************************************************************
* NAME:           CanDynTxObjSetData
* PARAMETER:      hTxObj -
*                   Handle of dynamic transmission object
*                 pData -
*                   data reference to be stored in data buffer of dynamic object
* RETURN VALUE:   --
* DESCRIPTION:    Functions stores reference to data registered with
*                 dynamic object.
*                 
*                 The number of byte copied is (always) 8. The number of 
*                 relevant (and consequently evaluated) byte is to be 
*                 taken from function CanDynObjGetDLC.
*************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanDynTxObjSetDataPtr(CanTransmitHandle txHandle, void* pData) C_API_3
{
  CanTransmitHandle dynTxObj;
  CAN_CHANNEL_CANTYPE_LOCAL
  
  assertUser((txHandle < kCanNumberOfTxObjects), kCanAllChannels, kErrorTxHdlTooLarge);    /* PRQA S 3109 */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  channel = CanGetChannelOfTxObj(txHandle);
# endif

  assertUser((txHandle <  CAN_HL_TX_DYN_ROM_STOPINDEX(channel)), channel, kErrorAccessedInvalidDynObj);  /* PRQA S 3109 */
# if ( kCanNumberOfTxStatObjects > 0) || defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((txHandle >= CAN_HL_TX_DYN_ROM_STARTINDEX(channel)), channel, kErrorAccessedStatObjAsDyn);  /* PRQA S 3109 */ /*lint !e568 */
# endif

  dynTxObj = (txHandle - CAN_HL_TX_DYN_ROM_STARTINDEX(channel)) + CAN_HL_TX_DYN_RAM_STARTINDEX(channel);  /* PRQA S 3382,0291 */

  canDynTxDataPtr[dynTxObj] = pData;
}
/* CODE CATEGORY 2 END*/
#endif /* C_ENABLE_DYN_TX_DATAPTR */




#if defined( C_ENABLE_TX_MASK_EXT_ID )
/************************************************************************
* NAME:               CanSetTxIdExtHi
* CALLED BY:          
* PRECONDITIONS:      CanInitPower should already been called.
* PARAMETER:          new source address for the 29-bit CAN-ID
* RETURN VALUE:       -
* DESCRIPTION:        Sets the source address in the lower 8 bit of the
*                     29-bit CAN identifier.
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtHi( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask )
{  
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
# endif
  assertUser(mask <= (vuint8)0x1F, channel, kErrorWrongMask);                                /* PRQA S 3109 */

  canTxMask0[channel] = (canTxMask0[channel] & MK_EXTID0(0x00FFFFFFUL)) | MK_EXTID0((vuint32)mask<<24);
# if (kCanNumberOfUsedCanTxIdTables > 1)
  canTxMask1[channel] = (canTxMask1[channel] & MK_EXTID1(0x00FFFFFFUL)) | MK_EXTID1((vuint32)mask<<24);
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
  canTxMask2[channel] = (canTxMask2[channel] & MK_EXTID2(0x00FFFFFFUL)) | MK_EXTID2((vuint32)mask<<24);
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
  canTxMask3[channel] = (canTxMask3[channel] & MK_EXTID3(0x00FFFFFFUL)) | MK_EXTID3((vuint32)mask<<24);
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
  canTxMask4[channel] = (canTxMask4[channel] & MK_EXTID4(0x00FFFFFFUL)) | MK_EXTID4((vuint32)mask<<24);
# endif
}
/* CODE CATEGORY 4 END*/

/************************************************************************
* NAME:               CanSetTxIdExtMidHi
* CALLED BY:          
* PRECONDITIONS:      CanInitPower should already been called.
* PARAMETER:          new source address for the 29-bit CAN-ID
* RETURN VALUE:       -
* DESCRIPTION:        Sets the source address in the lower 8 bit of the
*                     29-bit CAN identifier.
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtMidHi( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
# endif

  canTxMask0[channel] = (canTxMask0[channel] & MK_EXTID0(0xFF00FFFFUL)) | MK_EXTID0((vuint32)mask<<16);   /*lint !e572*/
# if (kCanNumberOfUsedCanTxIdTables > 1)
  canTxMask1[channel] = (canTxMask1[channel] & MK_EXTID1(0xFF00FFFFUL)) | MK_EXTID1((vuint32)mask<<16);   /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
  canTxMask2[channel] = (canTxMask2[channel] & MK_EXTID2(0xFF00FFFFUL)) | MK_EXTID2((vuint32)mask<<16);   /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
  canTxMask3[channel] = (canTxMask3[channel] & MK_EXTID3(0xFF00FFFFUL)) | MK_EXTID3((vuint32)mask<<16);   /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
  canTxMask4[channel] = (canTxMask4[channel] & MK_EXTID4(0xFF00FFFFUL)) | MK_EXTID4((vuint32)mask<<16);   /*lint !e572*/
# endif
}
/* CODE CATEGORY 4 END*/

/************************************************************************
* NAME:               CanSetTxIdExtMidLo
* CALLED BY:          
* PRECONDITIONS:      CanInitPower should already been called.
* PARAMETER:          new source address for the 29-bit CAN-ID
* RETURN VALUE:       -
* DESCRIPTION:        Sets the source address in the lower 8 bit of the
*                     29-bit CAN identifier.
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtMidLo( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif

  canTxMask0[channel] = (canTxMask0[channel] & MK_EXTID0(0xFFFF00FFUL)) | MK_EXTID0((vuint32)mask<<8);    /*lint !e572*/
# if (kCanNumberOfUsedCanTxIdTables > 1)
  canTxMask1[channel] = (canTxMask1[channel] & MK_EXTID1(0xFFFF00FFUL)) | MK_EXTID1((vuint32)mask<<8);    /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
  canTxMask2[channel] = (canTxMask2[channel] & MK_EXTID2(0xFFFF00FFUL)) | MK_EXTID2((vuint32)mask<<8);    /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
  canTxMask3[channel] = (canTxMask3[channel] & MK_EXTID3(0xFFFF00FFUL)) | MK_EXTID3((vuint32)mask<<8);    /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
  canTxMask4[channel] = (canTxMask4[channel] & MK_EXTID4(0xFFFF00FFUL)) | MK_EXTID4((vuint32)mask<<8);    /*lint !e572*/
# endif
}
/* CODE CATEGORY 4 END*/

/************************************************************************
* NAME:               CanSetTxIdExtLo
* CALLED BY:          
* PRECONDITIONS:      CanInitPower should already been called.
* PARAMETER:          new source address for the 29-bit CAN-ID
* RETURN VALUE:       -
* DESCRIPTION:        Sets the source address in the lower 8 bit of the
*                     29-bit CAN identifier.
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanSetTxIdExtLo( CAN_CHANNEL_CANTYPE_FIRST  vuint8 mask )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif

  canTxMask0[channel] = (canTxMask0[channel] & MK_EXTID0(0xFFFFFF00UL)) | MK_EXTID0((vuint32)mask);     /*lint !e572*/
# if (kCanNumberOfUsedCanTxIdTables > 1)
  canTxMask1[channel] = (canTxMask1[channel] & MK_EXTID1(0xFFFFFF00UL)) | MK_EXTID1((vuint32)mask);     /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 2)
  canTxMask2[channel] = (canTxMask2[channel] & MK_EXTID2(0xFFFFFF00UL)) | MK_EXTID2((vuint32)mask);     /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 3)
  canTxMask3[channel] = (canTxMask3[channel] & MK_EXTID3(0xFFFFFF00UL)) | MK_EXTID3((vuint32)mask);     /*lint !e572*/
# endif
# if (kCanNumberOfUsedCanTxIdTables > 4)
  canTxMask4[channel] = (canTxMask4[channel] & MK_EXTID4(0xFFFFFF00UL)) | MK_EXTID4((vuint32)mask);    /*lint !e572*/
# endif
}
/* CODE CATEGORY 4 END*/
#endif

#if defined( C_ENABLE_TX_OBSERVE )
/************************************************************************
* NAME:               CanTxGetActHandle
* CALLED BY:          
* PRECONDITIONS:      
* PARAMETER:          logical hardware object handle
* RETURN VALUE:       handle of the message in the assigned mailbox
* DESCRIPTION:        get transmit handle of the message, which is currently
*                     in the mailbox txHwObject.
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 CanTransmitHandle C_API_2 CanTxGetActHandle( CanObjectHandle logicalTxHdl ) C_API_3
{
  assertUser(logicalTxHdl < kCanNumberOfUsedTxCANObjects, kCanAllChannels, kErrorTxHwHdlTooLarge);     /* PRQA S 3109 */

  return (canHandleCurTxObj[logicalTxHdl]);       /*lint !e661*/
}
/* CODE CATEGORY 3 END*/
#endif

#if defined( C_ENABLE_VARIABLE_RX_DATALEN )
/************************************************************************
* NAME:               CanSetVariableRxDatalen
* CALLED BY:          
* PRECONDITIONS:      
* PARAMETER:          rxHandle: Handle of receive Message for which the datalen has
*                               to be changed
*                     dataLen:  new number of bytes, which have to be copied to the 
*                               message buffer.
* RETURN VALUE:       -
* DESCRIPTION:        change the dataLen of a receive message to copy a 
*                     smaller number of bytes than defined in the database.
*                     the dataLen can only be decreased. If the parameter
*                     dataLen is bigger than the statically defined value
*                     the statically defined value will be set.
*************************************************************************/
/* CODE CATEGORY 1 START*/
static void CanSetVariableRxDatalen (CanReceiveHandle rxHandle, vuint8 dataLen)
{
  assertInternal(rxHandle < kCanNumberOfRxObjects, kCanAllChannels , kErrorRxHandleWrong);  /* PRQA S 3109 */ /* legal rxHandle ? */
  /* assertion for dataLen not necessary due to runtime check */

  if (dataLen < CanGetRxDataLen(rxHandle))
  {
    canVariableRxDataLen[rxHandle]=dataLen;
  }
  else
  {
    canVariableRxDataLen[rxHandle] = CanGetRxDataLen(rxHandle);
  }
}
/* CODE CATEGORY 1 END*/
#endif

#if defined( C_ENABLE_COND_RECEIVE_FCT )
/************************************************************************
* NAME:               CanSetMsgReceivedCondition
* CALLED BY:          Application
* PRECONDITIONS:      
* PARAMETER:          -.
* RETURN VALUE:       -
* DESCRIPTION:        The service function CanSetMsgReceivedCondition()
*                     enables the calling of ApplCanMsgCondReceived()
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 void C_API_2 CanSetMsgReceivedCondition( CAN_CHANNEL_CANTYPE_ONLY )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((channel < kCanNumberOfChannels), kCanAllChannels, kErrorChannelHdlTooLarge);     /* PRQA S 3109 */
# endif

  canMsgCondRecState[channel] = kCanTrue;
}
/* CODE CATEGORY 3 END*/

/************************************************************************
* NAME:               CanResetMsgReceivedCondition
* CALLED BY:          Application
* PRECONDITIONS:      
* PARAMETER:          -
* RETURN VALUE:       -
* DESCRIPTION:        The service function CanResetMsgReceivedCondition()
*                     disables the calling of ApplCanMsgCondReceived()
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 void C_API_2 CanResetMsgReceivedCondition( CAN_CHANNEL_CANTYPE_ONLY )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((channel < kCanNumberOfChannels), kCanAllChannels, kErrorChannelHdlTooLarge);    /* PRQA S 3109 */
# endif

  canMsgCondRecState[channel] = kCanFalse;
}
/* CODE CATEGORY 3 END*/

/************************************************************************
* NAME:               CanGetMsgReceivedCondition
* CALLED BY:          Application
* PRECONDITIONS:      
* PARAMETER:          -
* RETURN VALUE:       status of Conditional receive function:
*                     kCanTrue : Condition is set -> ApplCanMsgCondReceived 
*                                will be called
*                     kCanFalse: Condition is not set -> ApplCanMsgCondReceived
*                                will not be called
* DESCRIPTION:        The service function CanGetMsgReceivedCondition() 
*                     returns the status of the condition for calling
*                     ApplCanMsgCondReceived()
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 vuint8 C_API_2 CanGetMsgReceivedCondition( CAN_CHANNEL_CANTYPE_ONLY )
{
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser((channel < kCanNumberOfChannels), kCanAllChannels, kErrorChannelHdlTooLarge);   /* PRQA S 3109 */
# endif

  return( canMsgCondRecState[channel] );
}
/* CODE CATEGORY 3 END*/
#endif


#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
/************************************************************************
* NAME:           ApplCanChannelDummy
* PARAMETER:      channel
*                 current receive channel
* RETURN VALUE:   ---
* DESCRIPTION:    dummy-function for unused Callback-functions
*************************************************************************/
/* CODE CATEGORY 3 START*/
C_API_1 void C_API_2 ApplCanChannelDummy( CanChannelHandle channel )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;     /* to avoid lint warnings */
# endif
}
/* CODE CATEGORY 3 END*/
#endif   /* C_MULTIPLE_RECEIVE_CHANNEL */


#if defined( C_MULTIPLE_RECEIVE_CHANNEL ) || \
    defined( C_HL_ENABLE_DUMMY_FCT_CALL )
/************************************************************************
* NAME:           ApplCanRxStructPtrDummy
* PARAMETER:      rxStruct
*                 pointer of CanRxInfoStruct
* RETURN VALUE:   kCanCopyData 
* DESCRIPTION:    dummy-function for unused Callback-functions
*************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 vuint8 C_API_2 ApplCanRxStructPtrDummy( CanRxInfoStructPtr rxStruct )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  rxStruct = rxStruct;     /* to avoid lint warnings */
# endif
  return kCanCopyData;
}
/* CODE CATEGORY 1 END*/

/************************************************************************
* NAME:           ApplCanTxHandleDummy
* PARAMETER:      txHandle
*                 transmit handle
* RETURN VALUE:   ---
* DESCRIPTION:    dummy-function for unused Callback-functions
*************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 ApplCanTxHandleDummy( CanTransmitHandle txHandle )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  txHandle = txHandle;     /* to avoid lint warnings */
# endif
}
/* CODE CATEGORY 1 END*/
#endif   /* C_MULTIPLE_RECEIVE_CHANNEL || C_HL_ENABLE_DUMMY_FCT_CALL */

#if defined( C_HL_ENABLE_DUMMY_FCT_CALL )
/************************************************************************
* NAME:           ApplCanTxStructDummy
* PARAMETER:      txStruct
*                 pointer of CanTxInfoStruct
* RETURN VALUE:   kCanCopyData
* DESCRIPTION:    dummy-function for unused Callback-functions
*************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 vuint8 C_API_2 ApplCanTxStructDummy( CanTxInfoStruct txStruct )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  txStruct = txStruct;     /* to avoid lint warnings */
# endif
  return kCanCopyData;
}
/* CODE CATEGORY 1 END*/

/************************************************************************
* NAME:           ApplCanRxHandleDummy
* PARAMETER:      rxHandle
*                 receive handle
* RETURN VALUE:   ---
* DESCRIPTION:    dummy-function for unused Callback-functions
*************************************************************************/
/* CODE CATEGORY 1 START*/
C_API_1 void C_API_2 ApplCanRxHandleDummy( CanReceiveHandle rxHandle )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
  rxHandle = rxHandle;     /* to avoid lint warnings */
# endif  
}
/* CODE CATEGORY 1 END*/
#endif /* C_HL_ENABLE_DUMMY_FCT_CALL */

#if defined( C_ENABLE_RX_QUEUE )
/************************************************************************
* NAME:               CanHL_ReceivedRxHandleQueue
* CALLED BY:          CanBasicCanMsgReceived, CanFullCanMsgReceived
* Preconditions:      none
* PARAMETER:          none
* RETURN VALUE:       none
* DESCRIPTION:        Writes receive data into queue or starts further
*                     processing for this message
*************************************************************************/
/* CODE CATEGORY 1 START*/
static vuint8 CanHL_ReceivedRxHandleQueue(CAN_CHANNEL_CANTYPE_ONLY)
{
  CanDeclareGlobalInterruptOldStatus
  tCanRxInfoStruct    *pCanRxInfoStruct;

  /* KB begin CanLL_ReceivedRxHandleQueueLocalParameter */
  V_DEF_P2VAR(V_NONE, tCanMsgTransmitStruct, AUTOMATIC, VAR_NOINIT) pSrc;
  V_DEF_P2VAR(V_NONE, tCanMsgTransmitStruct, AUTOMATIC, VAR_NOINIT) pDst;
  vuint8 canllidx;
  /* KB end CanLL_ReceivedRxHandleQueueLocalParameter */

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  assertInternal(channel < kCanNumberOfChannels, kCanAllChannels, kErrorInternalChannelHdlTooLarge);  /* PRQA S 3109 */
# endif

  /* Rx Queue is supported with C_HL_ENABLE_RX_INFO_STRUCT_PTR only! */
  pCanRxInfoStruct =  &canRxInfoStruct[channel];

  /* if C_ENABLE_APPLCANPRERXQUEUE is not set, a macro ApplCanPreRxQueue has to be provided by the tool */
  /* in case of ranges, ApplCanPreRxQueue has to return kCanCopyData! */
# if defined( C_ENABLE_APPLCANPRERXQUEUE )
  if(ApplCanPreRxQueue(CAN_HL_P_RX_INFO_STRUCT(channel)) == kCanCopyData)
# endif
  {
    /* Disable the interrupts because nested interrupts can take place -
      CAN interrupts of all channels have to be disabled here*/
    CanNestedGlobalInterruptDisable();
    if(canRxQueue.canRxQueueCount < kCanRxQueueSize)   /* Queue full ? */
    {
      if (canRxQueue.canRxQueueWriteIndex == (kCanRxQueueSize - 1) )
      {
        canRxQueue.canRxQueueWriteIndex = 0;
      }
      else
      {
        canRxQueue.canRxQueueWriteIndex++;
      }
      canRxQueue.canRxQueueBuf[canRxQueue.canRxQueueWriteIndex].Channel = channel;
      canRxQueue.canRxQueueBuf[canRxQueue.canRxQueueWriteIndex].Handle  = pCanRxInfoStruct->Handle;

      /* KB begin CanLL_ReceivedRxHandleQueueCopyMsgObj */
      pDst = &canRxQueue.canRxQueueBuf[canRxQueue.canRxQueueWriteIndex].CanChipMsgObj;
      pSrc = (V_DEF_P2VAR(V_NONE, tCanMsgTransmitStruct, AUTOMATIC, VAR_NOINIT)) pCanRxInfoStruct->pChipMsgObj;
      for (canllidx=0; canllidx<8; canllidx++) {
        pDst->DataFld[canllidx] = pSrc->DataFld[canllidx];
      }
      pDst->DlcRaw   = pSrc->DlcRaw;
      pDst->IdRawExt = pSrc->IdRawExt;
      pDst->IdRaw    = pSrc->IdRaw;
      /* KB end CanLL_ReceivedRxHandleQueueCopyMsgObj */

      canRxQueue.canRxQueueCount++;
    }
# if defined( C_ENABLE_RXQUEUE_OVERRUN_NOTIFY )
    else
    {
      ApplCanRxQueueOverrun();
    }
# endif
    CanNestedGlobalInterruptRestore();
  } 
# if defined( C_ENABLE_APPLCANPRERXQUEUE )
  else
  {
    /* Call the application call-back functions and set flags */
#  if defined( C_ENABLE_RX_QUEUE_RANGE )
    if (pCanRxInfoStruct->Handle < kCanNumberOfRxObjects )
#  endif
    { 
      return CanHL_ReceivedRxHandle(CAN_CHANNEL_CANPARA_FIRST pCanRxInfoStruct);
    }
  }
# endif
  return kCanHlFinishRx;
}
/* CODE CATEGORY 1 END*/

/************************************************************************
* NAME:               CanHandleRxMsg
* CALLED BY:          Application
* Preconditions:      none
* PARAMETER:          none
* RETURN VALUE:       none
* DESCRIPTION:        Calls PreCopy and/or Indication, if existent and
*                     set the indication flag
*************************************************************************/
/* CODE CATEGORY 2 START*/
C_API_1 void C_API_2 CanHandleRxMsg(void)
{
  CanDeclareGlobalInterruptOldStatus
  CAN_CHANNEL_CANTYPE_LOCAL
  tCanRxInfoStruct        localCanRxInfoStruct;

  while ( canRxQueue.canRxQueueCount != (vuintx)0 )
  {

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
    channel = canRxQueue.canRxQueueBuf[canRxQueue.canRxQueueReadIndex].Channel;
# endif


    CAN_CAN_INTERRUPT_DISABLE( CAN_CHANNEL_CANPARA_ONLY );

    /* Call the application call-back functions and set flags */
    localCanRxInfoStruct.Handle      = canRxQueue.canRxQueueBuf[canRxQueue.canRxQueueReadIndex].Handle;
    localCanRxInfoStruct.pChipData   = (CanChipDataPtr)&(canRxQueue.canRxQueueBuf[canRxQueue.canRxQueueReadIndex].CanChipMsgObj.DataFld[0]);
    canRDSRxPtr[channel] = localCanRxInfoStruct.pChipData;
    localCanRxInfoStruct.pChipMsgObj = (CanChipMsgPtr) &(canRxQueue.canRxQueueBuf[canRxQueue.canRxQueueReadIndex].CanChipMsgObj);
    localCanRxInfoStruct.Channel     = channel;
    /* KB begin CanLL_CanHandleRxMsgCopyHwExtension */
    /* KB end CanLL_CanHandleRxMsgCopyHwExtension */

# if defined( C_ENABLE_RX_QUEUE_RANGE )
    switch ( localCanRxInfoStruct.Handle)
    {
#  if defined( C_ENABLE_RANGE_0 )
      case kCanRxHandleRange0: (void)APPLCANRANGE0PRECOPY( &localCanRxInfoStruct ); break;
#  endif
#  if defined( C_ENABLE_RANGE_1 )
      case kCanRxHandleRange1: (void)APPLCANRANGE1PRECOPY( &localCanRxInfoStruct ); break;
#  endif
#  if defined( C_ENABLE_RANGE_2 )
      case kCanRxHandleRange2: (void)APPLCANRANGE2PRECOPY( &localCanRxInfoStruct ); break;
#  endif
#  if defined( C_ENABLE_RANGE_3 )
      case kCanRxHandleRange3: (void)APPLCANRANGE3PRECOPY( &localCanRxInfoStruct ); break;
#  endif
      default:
#  if defined( C_ENABLE_INDICATION_FLAG ) || \
      defined( C_ENABLE_INDICATION_FCT )
             if( CanHL_ReceivedRxHandle( CAN_CHANNEL_CANPARA_FIRST &localCanRxInfoStruct ) == kCanHlContinueRx )
             {
               CanHL_IndRxHandle(localCanRxInfoStruct.Handle);
             }
#  else
             (void) CanHL_ReceivedRxHandle( CAN_CHANNEL_CANPARA_FIRST &localCanRxInfoStruct );
#  endif
             break;
   }
# else
#  if defined( C_ENABLE_INDICATION_FLAG ) || \
      defined( C_ENABLE_INDICATION_FCT )
    if( CanHL_ReceivedRxHandle( CAN_CHANNEL_CANPARA_FIRST &localCanRxInfoStruct ) == kCanHlContinueRx )
    {
      CanHL_IndRxHandle(localCanRxInfoStruct.Handle);
    }
#  else
    (void) CanHL_ReceivedRxHandle( CAN_CHANNEL_CANPARA_FIRST &localCanRxInfoStruct );
#  endif
# endif
    
    CAN_CAN_INTERRUPT_RESTORE( CAN_CHANNEL_CANPARA_ONLY );

    CanNestedGlobalInterruptDisable();
    if (canRxQueue.canRxQueueReadIndex == (kCanRxQueueSize - 1) )
    {
      canRxQueue.canRxQueueReadIndex = 0;
    }
    else
    {
      canRxQueue.canRxQueueReadIndex++;
    }
    canRxQueue.canRxQueueCount--;
    CanNestedGlobalInterruptRestore();
  }
  return;
} /* end of CanHandleRxMsg() */
/* CODE CATEGORY 2 END*/

/************************************************************************
* NAME:               CanDeleteRxQueue
* CALLED BY:          Application, CAN driver
* Preconditions:      none
* PARAMETER:          none
* RETURN VALUE:       none
* DESCRIPTION:        delete receive queue
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanDeleteRxQueue(void)
{
  CanDeclareGlobalInterruptOldStatus
  
  CanNestedGlobalInterruptDisable();
  canRxQueue.canRxQueueWriteIndex  = (vuintx)0xFFFFFFFF;
  canRxQueue.canRxQueueReadIndex   = 0;
  canRxQueue.canRxQueueCount       = 0;  
  CanNestedGlobalInterruptRestore();
} /* end of CanDeleteRxQueue() */
/* CODE CATEGORY 4 END*/

#endif /* C_ENABLE_RX_QUEUE */

#if defined(C_ENABLE_BASE_ADDRESS_UPDATE)
/************************************************************************
* NAME:           CanBaseAddressRequest
* CALLED BY:      Application
* Preconditions:  none
* PARAMETER:      channel: the CAN channel for which the address is requested
* RETURN VALUE:   ---
* DESCRIPTION:    The application calls this function in order to tell the 
*                 CAN driver to request the computation of the virtual 
*                 address of the CAN controller.
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanBaseAddressRequest(CAN_CHANNEL_CANTYPE_ONLY)
{

  {
    /* KB begin CanLL_BaseAddressRequest */
    /* e.g. canNodePtrTemp[canHwChannel] = (tCanMSCAN*)ApplCanGetBaseAddress(<physical adress>, <size of CAN controller>); */
    /* KB end CanLL_BaseAddressRequest */
  }
}
/* CODE CATEGORY 4 END*/

/************************************************************************
* NAME:           CanBaseAddressActivate
* CALLED BY:      Application
* Preconditions:  Interrupts have to be disabled
* PARAMETER:      channel: the CAN channel for which the address is requested
* RETURN VALUE:   ---
* DESCRIPTION:    The application calls this function in order to tell the 
*                 CAN driver to activate the virtual address of the CAN 
*                 controller. The adress has to be requested with 
*                 CanBaseAddressRequest() before.
*                 Call is only allowed on Task level and must not interrupt
*                 any CAN driver service functions.
*************************************************************************/
/* CODE CATEGORY 4 START*/
C_API_1 void C_API_2 CanBaseAddressActivate(CAN_CHANNEL_CANTYPE_ONLY)
{

  {
    /* KB begin CanLL_BaseAddressActivate */
    /* e.g. canNodePtr[canHwChannel]        = canNodePtrTemp[canHwChannel]; */
    /* KB end CanLL_BaseAddressActivate */
  }
}
/* CODE CATEGORY 4 END*/
#endif  /* defined(VGEN_ENABLE_MDWRAP) || defined(VGEN_ENABLE_QWRAP) || defined(C_ENABLE_BASE_ADDRESS_UPDATE) */



/* End of channel */
/* STOPSINGLE_OF_MULTIPLE */
/* Kernbauer Version: 1.14 Konfiguration: can_driver Erzeugungsgangnummer: 1 */

/* Kernbauer Version: 1.14 Konfiguration: can_driver Erzeugungsgangnummer: 1 */

/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
