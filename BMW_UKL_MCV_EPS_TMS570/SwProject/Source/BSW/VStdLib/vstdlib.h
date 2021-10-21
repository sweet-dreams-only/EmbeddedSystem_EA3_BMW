/* Kernbauer Version: 1.16 Konfiguration: VStdLib Erzeugungsgangnummer: 1 */


/**********************************************************************************************************************
| Project Name: vstdlib library
|    File Name: vstdlib_ll.h
|
|  Description : Low level part of the implementation of standard Vector functions.
|                ARM core specific implementation.
|                               
|----------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|----------------------------------------------------------------------------------------------------------------------
|   Copyright (c) by Vctr Informatik GmbH.     All rights reserved.
|
|   This software is copyright protected and proprietary to 
|   Vctr Informatik GmbH. Vctr Informatik GmbH grants to you 
|   only those rights as set out in the license conditions. All 
|   other rights remain with Vctr Informatik GmbH.
|
|----------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|----------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------------------------------------------------
| Ml           Patrick Markl             Vctr Informatik GmbH
| Fn           Matthias Fleischmann      Vctr Informatik GmbH
| Ard          Thomas Arnold             Vctr Informatik GmbH
| Hs           Hannes Haas               Vctr Informatik GmbH
| Kk           Karol Kostolny            Vctr Informatik GmbH
| Ces          Senol Cendere             Vctr Informatik GmbH
| Pl           Georg Pfluegel            Vctr Informatik GmbH
| Aj           Arthur Jendrusch          Vctr Informatik GmbH
| Seg          Sebastian Gaertner        Vctr Informatik GmbH
| Rna          Ruediger Naas             Vctr Informatik GmbH 
|----------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|----------------------------------------------------------------------------------------------------------------------
| Date       Version   Author  Description
|----------  --------  ------  ----------------------------------------------------------------------------------------
|2005-06-16  01.00.00    Ml     - Creation
|2006-01-12  01.01.00    Ml     - no changes
|2006-02-02  01.02.00    Fn     - added support for ARM7
|2006-02-14  01.03.00    Ard    - add version history
|2006-02-24  01.04.00    Ard    - add version scan comment
|2006-03-06  01.05.00    Ard    - released HL version 2.05.00
|2006-03-09  01.06.00    Ard    - remove unused prototypes (defaults from HL are used)
|2006-03-23  01.07.00    Hs     - HL part updated
|2006-06-26  01.08.00    Ard    - ESCAN00017417: Add IRQ functions for MAC7100
|2006-07-31  01.09.00    Ard    - ESCAN00017420: Changes in vstdlib.kon
|2006-08-23  01.10.00    Ard    - ESCAN00017421: Add IRQ functions for TMS470
|2006-08-23  01.11.00    Ard    - ESCAN00017422: Support AVCCORE
|2006-08-25  01.12.00    Ard    - ESCAN00017444: Support LPC2xxx
|2006-10-30  01.13.00    Ard    - ESCAN00018191: Support MAC7100 GHS
|2006-11-08  01.14.00    Ard    - ESCAN00018283: Support TMS470_DCAN
|2007-01-15  01.15.00    Ard    - ESCAN00018932: Support new high level version (TMS470 - Texas Instruments/ARM)
|2007-03-05  01.16.00    Ces    - ESCAN00019841: Support SAF7780_PELICAN with compiler Green Hills
|2007-07-23  01.17.00    Ard    - ESCAN00021557: Interrupts won't be restored if compiler optimization is activated
|2007-07-31  01.18.00    Ard    - ESCAN00021688: Modules using the macros defined by VStdLib to Restore/Disable IRQs 
|                                                  will not compile in THUMB mode
|                               - ESCAN00021915: Support GHS compiler for TMS470
|2007-09-12  01.19.00    Ard    - ESCAN00022325: Save registers before using inline assembler (Texas Instruments)
|                               - ESCAN00022358: Fix interrupt handling for GHS compiler
|2007-11-27  01.20.00    Ard    - ESCAN00023430: Add platform TMS320ARM
|2008-07-10  01.21.00    Kk     - ESCAN00028311: Add platform Fujitsu MB86R0X for GNU compiler
|                        Ard    - ESCAN00030163: Support Omap derivative
|2008-11-21  01.22.00    Ces    - ESCAN00031486: Support platform Freescale IMX
|2009-01-28  01.23.00    Pl     - ESCAN00032648: Support ST30 GNU
|2009-04-02  01.24.00    Fn     - ESCAN00034336: Support Mac7100 and ARM compiler
|                        Aj     - ESCAN00034775: Support TeleChips (TCC800x) and ARM compiler
|2009-06-06  01.25.00    Seg    - ESCAN00036632: Support TI TMS470MSF542 derivative with ARM compiler
|2009-10-23  01.26.00    Rna    - ESCAN00038742: Support STM32BXCAN derivative with ARM compiler
|2010-07-13  01.27.00    Ces    - ESCAN00044028: Support IMX53 (Cortex A8) with GreenHills compiler
|2010-08-27  01.28.00    Ht     - ESCAN00044915: Support Cortex M3 core with C_COMP_TMS470_DCAN
|2011-03-04  01.29.00    Pl     - ESCAN00045901: Optimization of the different interrupt disable and restore functions
|                               - ESCAN00047518: Support AVNA with TI compiler
|                               - ESCAN00049098: Support TX03 with ARM compiler
|2011-07-13  01.30.00    Pl     - ESCAN00052181: Support global interrupt handling by application for the Tms320
|2011-08-10  01.31.00    Pl     - ESCAN00052679: Support Fcr4 with GHS compiler
|2011-09-01  01.32.00    Pl     - ESCAN00053194: Support LPC1768 with Keil compiler
|2011-11-17  01.32.01    Pl     - ESCAN00054916: VStdLL_GlobalInterruptRestore with ARM compiler do not write the old
|                                                saved value from localInterruptOldStatusPtr back
|********************************************************************************************************************/

/**********************************************************************************************************************
|
| Project Name : vstdlib library
|    File Name : vstdlib_HL.h
|
|  Description : Highlevel part of the implementation of standard Vector functions
|                               
|----------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|----------------------------------------------------------------------------------------------------------------------
|   Copyright (c) by Vctr Informatik GmbH.     All rights reserved.
|
|   This software is copyright protected and proprietary to 
|   Vctr Informatik GmbH. Vctr Informatik GmbH grants to you 
|   only those rights as set out in the license conditions. All 
|   other rights remain with Vctr Informatik GmbH.
|
|----------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|----------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------------------------------------------------
| Ml           Patrick Markl             Vctr Informatik GmbH
| HH           Hartmut Hoerner           Vctr Informatik GmbH
| Ms           Gunnar Meiss              Vctr Informatik GmbH
| Et           Thomas Ebert              Vctr Informatik GmbH
| Bus          Sabine Buecherl           Vctr Informatik GmbH
| Hs           Hannes Haas               Vctr Informatik GmbH
| BWR          Brandon Root              Vector CANtech Inc.
| Ard          Thomas Arnold             Vctr Informatik GmbH
|----------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|----------------------------------------------------------------------------------------------------------------------
| Date       Version   Author  Description
|----------  --------  ------  ----------------------------------------------------------------------------------------
|2003-09-06  00.01.00    Ml     - Creation
|                        Ml     - Added HC12 Cosmic
|2003-10-07  00.02.00    Ml/HH  - v_lib input merged
|2004-04-10  00.03.00    Ml     - Added headerfile
|                        Ml     - Added HC08 Cosmic
|                        Ml     - removed channel dependence for assertions
|                        Ml     - Added function to retrieve the IRQ state
|                        Ml     - Added VSTD_FULL_LIB_SUPPORT switch
|2004-04-27  01.00.00    Ml     - resolved issues found in code inspection
|2004-05-17  01.01.00    Ml     - no changes
|                        Ml     - changed bugfix into releaseversion
|2004-05-18  01.02.00    Ms/HH  - changed memory qualifier concept
|2004-06-01  01.03.00    Ml     - no changes
|2004-08-06  01.04.00    Ml     - Added macros for local IRQ disable
|                               - Split of library into HL and LL
|2004-08-18  01.05.00    Ml     - Added function qualifier
|2004-09-06  01.06.00    Ml     - ESCAN00009316: fixed parameter type mismatch
|2004-09-27  01.07.00    Ml     - changed memcpy macros
|                        Ml     - changed namingconvention
|2004-09-29  01.08.00    Et     - ESCAN00009692: split VStdMemCpy in VStdRamMemCpy and VStdRomMemCpy   
|2004-10-01  01.09.00    Ml     - ESCAN00009731: usage of standard type qualifiers
|2004-10-26  01.10.00    Ml     - ESCAN00010000: LL parts are split into HW specific files
|2004-11-09  01.11.00    Ml     - no changes
|2004-11-15  01.12.00    Ml     - ESCAN00010533: Added optimized memory functions for HC08
|                        Ml     - ESCAN00010672: Added memory qualifier
|2005-01-24  01.13.00    Ml     - ESCAN00010670: Added memset
|2005-02-25  01.14.00    Ml     - ESCAN00011215  Added VStdInitPowerOn
|2005-04-26  01.15.00    Ml     - ESCAN00012047: Encapsulate VStdInitPowerOn
|            01.16.00    Ml     - ESCAN00012105: Change definition of VStdMemCpy
|2005-05-30  02.00.00    Ml     - ESCAN00013446: Development concept changed
|2005-09-12  02.01.00    Ml     - ESCAN00013512: Fixed Misra warnings
|2005-11-06  02.02.00    Ml     - ESCAN00014183: no changes
|2005-11-28  02.03.00    Ml     - Changed version defines
|                        Ml     - ESCAN00014428: VStdMemClr/Set are now internal functions
|                        Ml     - ESCAN00014409: Added casts for mem function defines
|2005-12-12  02.04.00    Ml/Bus - ESCAN00012774: insert comments for different resource categories
|2006-01-12  02.05.00    Ml     - ESCAN00014897: Changed interrupt handling
|2006-01-14  02.06.00    Ml     - ESCAN00014908: Adapted interrupt control handling for RI1.5
|2006-02-07  02.07.00    Ml     - Added VStdGetInterruptState
|                        Hs     - ESCAN00015802: compatibility defines added
|2006-05-09  02.08.00    Ces    - ESCAN00016289: Insert memory qualifier V_MEMROM3 to VStdRomMemCpy()
|2006-05-24  02.09.00    BWR    - ESCAN00016488: Compiler error in VStdSuspendAllInterrupts and VStdResumeAllInterrupts
|2006-07-16  02.10.00    Ml     - Changed return type of VStdGetInterruptState from uint8 to tVStdIrqStateType
|2006-07-31  02.11.00    Ml     - ESCAN00017133: Changed assertion handling
|2006-08-04  02.12.00    Ml     - ESCAN00017188: Added compatibility for older copy functions
|2006-11-20  02.13.00    Ml     - Removed VStdGetInterruptState
|2006-12-07  02.14.00    Ml     - Changed switch names
|                        Ml     - ESCAN00018889: Fixed code inspection report findings
|                               - ESCAN00018880: added casts to memXXX macros
|2007-01-27  02.15.00    Ml,Ard - ESCAN00019251: VStdLib HL usable for RI1.4 and RI1.5
|2007-02-19  02.16.00    Ml     - ESCAN00019672: no changes
|                        Ml     - ESCAN00019674: Changed names of interrupt lock macros
|2007-05-10  02.17.00    Ml     - ESCAN00020705: no changes
|                        Ml     - ESCAN00020241: Cast of length parameter
|2007-11-26  03.00.00    Ml     - ESCAN00024126: Support word and dword copy routines
|                        Ml     - ESCAN00024192: Default and specific implementations supported at the same time
|2008-06-25  03.01.00    Ml     - ESCAN00023334: Added u suffix to the version numbers
|                        Ml     - ESCAN00018659: No changes
|                        Ml     - ESCAN00015501: Added compatibility to older version defines   
|2008-07-17  03.01.01    Ml     - ESCAN00027617: Added library version check support
|2008-07-23  03.02.00    Ml     - ESCAN00028605: old interrupt status is initialized by low level token
|2008-07-27  03.02.01    Ml     - ESCAN00028752: Include of MSR header according to naming convention
|2008-08-13  03.03.00    Ml     - ESCAN00029196: Encapsulated AUTOSAR library version check
|2008-12-08  03.03.01    Ml     - ESCAN00031855: Additional memcpy interfaces
|2009-06-30  03.04.00    Ml     - ESCAN00036089: Application must care about nested calls in case of user handling of locks
|                        Ml     - ESCAN00035049: Resolved extended version check include
|2009-10-15  03.05.00    Ml     - ESCAN00038482: Added additional function qualifier (VSTD_API_2)
|                        Ml     - ESCAN00038485: Added general OS header include.
|2009-10-19  03.05.01    Ml     - ESCAN00038485: Renamed the OS header include according to osCAN
|
|*********************************************************************************************************************/

#if !defined(_VSTDLIB_H_)
# define _VSTDLIB_H_

/* Includes required in the header file */

/*********************************************************************************************************************/
/* Defines                                                                                                           */
/*********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : VStdLib_Arm7 CQComponent : Implementation */
#define VSTDLIB_ARM7_VERSION           0x0132u
#define VSTDLIB_ARM7_RELEASE_VERSION   0x01u

/* ##V_CFG_MANAGEMENT ##CQProject : VStdLib__coreHll CQComponent : Implementation */
# define VSTDLIB__COREHLL_VERSION         0x0305u
# define VSTDLIB__COREHLL_RELEASE_VERSION 0x01u

/* Introduced for comparibility with older VStdLib versions */
# define COMMON_VSTDLIB_VERSION             VSTDLIB__COREHLL_VERSION
# define COMMON_VSTDLIB_RELEASE_VERSION     VSTDLIB__COREHLL_RELEASE_VERSION

#if defined (V_COMP_GHS)
# if defined(VSTD_ENABLE_DEFAULT_INTCTRL)
#  include <arm_ghs.h>
# endif
#endif

# if defined (VSTD_ENABLE_FIQ_INTCTRL)
#  define kIrqIbitMask  ((vuint32)0x000000C0)
# else    
#  define kIrqIbitMask  ((vuint32)0x00000080)
# endif



# if !defined(VSTD_API_0)
#  define VSTD_API_0
# endif

# if !defined(VSTD_API_1)
#  define VSTD_API_1
# endif

# if !defined(VSTD_API_2)
#  define VSTD_API_2
# endif

# if !defined(VSTD_CALLBACK_0)
#  define VSTD_CALLBACK_0
# endif

# if !defined(VSTD_CALLBACK_1)
#  define VSTD_CALLBACK_1
# endif

#  if defined(VSTD_ENABLE_DEFAULT_INTCTRL) || \
      defined(VSTD_ENABLE_OSEK_INTCTRL)    || \
      defined(VSTD_ENABLE_APPL_INTCTRL)
#   define VSTD_ENABLE_INTCTRL_HANDLING
#   define VSTD_HL_ENABLE_SUPPORT_IRQ_FCT  /* compatibility for Autosar */
#   define VSTD_ENABLE_SUPPORT_IRQ_FCT
#  else
#   define VSTD_DISABLE_INTCTRL_HANDLING
#   define VSTD_HL_DISABLE_SUPPORT_IRQ_FCT  /* compatibility for Autosar */
#   define VSTD_DISABLE_SUPPORT_IRQ_FCT
#  endif

# if !defined(VSTD_ENABLE_LIBRARY_FUNCTIONS) && !defined(VSTD_DISABLE_LIBRARY_FUNCTIONS)
#  define VSTD_ENABLE_LIBRARY_FUNCTIONS
# endif

/*********************************************************************************************************************/
/* Error codes for assertions                                                                                        */
/*********************************************************************************************************************/
# define kVStdErrorIntDisableTooOften        ((vuint8)0x01)
# define kVStdErrorIntRestoreTooOften        ((vuint8)0x02)
# define kVStdErrorMemClrInvalidParameter    ((vuint8)0x03)
# define kVStdErrorMemCpyInvalidParameter    ((vuint8)0x04)
# define kVStdErrorFunctionNotSupportedByHw  ((vuint8)0x05)
# define kVStdErrorMemSetInvalidParameter    ((vuint8)0x06)
# define kVStdErrorUnexpectedLockState       ((vuint8)0x07)


/*********************************************************************************************************************/
/* Plattforms with optimized VStdLib support                                                                         */
/*********************************************************************************************************************/
#if defined (C_COMP_TI_TMS470)            || \
    defined (C_COMP_TI_TMS470_DCAN)       
#define VSTD_HL_DISABLE_SUPPORT_MEM_FCT
#define VSTD_HL_DISABLE_MEM_FCT_MAPPING 
#endif

/* in case of the standard implementation enable all functions */
# if defined(VSTD_HL_ENABLE_MEM_FCT_MAPPING)
# else
#  define VSTD_HL_USE_VSTD_MEMCLR
#  define VSTD_HL_USE_VSTD_MEMSET
#  define VSTD_HL_USE_VSTD_RAMMEMCPY
#  define VSTD_HL_USE_VSTD_ROMMEMCPY
#  define VSTD_HL_USE_VSTD_WORD_MEMCPY
#  define VSTD_HL_USE_VSTD_DWORD_MEMCPY
# endif

/*********************************************************************************************************************/
/* Version check                                                                                                     */
/*********************************************************************************************************************/
/* ROM CATEGORY 4 START*/
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kVStdMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kVStdSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kVStdReleaseVersion;
/* ROM CATEGORY 4 END*/

/*********************************************************************************************************************/
/* Function like macros                                                                                              */
/*********************************************************************************************************************/

#if defined (V_COMP_ARM)
# if defined( VSTD_ENABLE_CLEAR_INSTRUCTION_PIPE )
#  define VSTD_CLEAR_INSTRUCTION_PIPE()  __asm {NOP \
                                                NOP \
                                                NOP \
                                                NOP \
                                                NOP \
                                                NOP \
                                                NOP}
# else
#  define VSTD_CLEAR_INSTRUCTION_PIPE()
# endif                                           
#endif                                           

#if defined (V_COMP_GHS)
# if defined( VSTD_ENABLE_CLEAR_INSTRUCTION_PIPE )

#  define VStdLL_GlobalInterruptDisable(localInterruptOldStatusPtr)        \
{                                                                          \
  *(localInterruptOldStatusPtr) = __GETSR() & (vuint32)kIrqIbitMask;       \
  __SETSR(__GETSR() | kIrqIbitMask);                                       \
    __asm(" NOP ");                                                        \
    __asm(" NOP ");                                                        \
    __asm(" NOP ");                                                        \
    __asm(" NOP ");                                                        \
    __asm(" NOP ");                                                        \
    __asm(" NOP ");                                                        \
    __asm(" NOP ");                                                        \
}

# else                                           

#  define VStdLL_GlobalInterruptDisable(localInterruptOldStatusPtr)        \
{                                                                          \
  *(localInterruptOldStatusPtr) = __GETSR() & (vuint32)kIrqIbitMask;       \
  __SETSR(__GETSR() | kIrqIbitMask);                                       \
}

# endif

#  define VStdLL_GlobalInterruptRestore(localInterruptOldStatus)           \
{                                                                          \
  __SETSR((__GETSR() & (vuint32)~kIrqIbitMask) | localInterruptOldStatus); \
}
#endif

#if defined (V_COMP_TI) && !defined (__TI_TMS470_V7M3__)
# if defined( VSTD_ENABLE_CLEAR_INSTRUCTION_PIPE )

#  define VStdLL_GlobalInterruptDisable(localInterruptOldStatusPtr)   \
{                                                                     \
  *(localInterruptOldStatusPtr) = _get_CPSR() & kIrqIbitMask;         \
  _set_CPSR(_get_CPSR() | kIrqIbitMask);                              \
  __asm(" NOP");                                                      \
  __asm(" NOP");                                                      \
  __asm(" NOP");                                                      \
  __asm(" NOP");                                                      \
  __asm(" NOP");                                                      \
  __asm(" NOP");                                                      \
  __asm(" NOP");                                                      \
}

# else

#  define VStdLL_GlobalInterruptDisable(localInterruptOldStatusPtr)   \
{                                                                     \
  *(localInterruptOldStatusPtr) = _get_CPSR() & kIrqIbitMask;         \
  _set_CPSR(_get_CPSR() | kIrqIbitMask);                              \
}

# endif

# define VStdLL_GlobalInterruptRestore(localInterruptOldStatus)       \
{                                                                     \
  _set_CPSR((_get_CPSR() & ~kIrqIbitMask) | localInterruptOldStatus); \
}

#endif 

#if defined (V_COMP_IAR)
# if defined( VSTD_ENABLE_CLEAR_INSTRUCTION_PIPE )

#  define VStdLL_GlobalInterruptDisable(localInterruptOldStatusPtr)              \
{                                                                                \
  *(localInterruptOldStatusPtr) = __get_CPSR() & (vuint32)kIrqIbitMask;          \
  __set_CPSR(__get_CPSR() | kIrqIbitMask);                                       \
  __asm(" nop");                                                                 \
  __asm(" nop");                                                                 \
  __asm(" nop");                                                                 \
  __asm(" nop");                                                                 \
  __asm(" nop");                                                                 \
  __asm(" nop");                                                                 \
  __asm(" nop");                                                                 \
}

# else

#  define VStdLL_GlobalInterruptDisable(localInterruptOldStatusPtr)              \
{                                                                                \
  *(localInterruptOldStatusPtr) = __get_CPSR() & (vuint32)kIrqIbitMask;          \
  __set_CPSR(__get_CPSR() | kIrqIbitMask);                                       \
}

# endif

# define VStdLL_GlobalInterruptRestore(localInterruptOldStatus)                  \
{                                                                                \
  __set_CPSR((__get_CPSR() & (vuint32)~kIrqIbitMask) | localInterruptOldStatus); \
}
#endif

#if defined( V_COMP_GNU )
# if defined( VSTD_ENABLE_CLEAR_INSTRUCTION_PIPE )
#  define VSTD_CLEAR_INSTRUCTION_PIPE() (  __asm volatile ("NOP; \n              \
                                                            NOP; \n              \
                                                            NOP; \n              \
                                                            NOP; \n              \
                                                            NOP; \n              \
                                                            NOP; \n              \
                                                            NOP" : : : )         \
                                        )
# else
#  define VSTD_CLEAR_INSTRUCTION_PIPE()                                                           
# endif
#endif


/*********************************************************************************************************************/
/* Types                                                                                                             */
/*********************************************************************************************************************/

#if defined (C_COMP_TI_TMS470)            || \
    defined (C_COMP_TI_TMS470_DCAN)       
typedef volatile vuint32 tVStdIrqStateType;
#else
typedef vuint32 tVStdIrqStateType;
#endif

/*********************************************************************************************************************/
/* Defines                                                                                                           */
/*********************************************************************************************************************/
#  if defined(VSTD_ENABLE_INTCTRL_HANDLING)
#   if defined(VSTD_ENABLE_DEFAULT_INTCTRL)
#    define VStdDeclareGlobalInterruptOldStatus     tVStdIrqStateType localInterruptOldStatus;
#    define VStdPutGlobalInterruptOldStatus(x)      (localInterruptOldStatus = (x))
#    define VStdGetGlobalInterruptOldStatus(x)      ((x) = localInterruptOldStatus)
#    define VStdGlobalInterruptDisable()            VStdLL_GlobalInterruptDisable(&localInterruptOldStatus)
#    define VStdGlobalInterruptRestore()            VStdLL_GlobalInterruptRestore(localInterruptOldStatus)
#   elif defined(VSTD_ENABLE_OSEK_INTCTRL)
#    define VStdDeclareGlobalInterruptOldStatus
#    define VStdPutGlobalInterruptOldStatus(x)
#    define VStdGetGlobalInterruptOldStatus(x)
#    if defined(osdOSEK2_1)
#     define VStdGlobalInterruptDisable()           OsSaveDisableGlobalNested()
#     define VStdGlobalInterruptRestore()           OsRestoreEnableGlobalNested()
#     define VStdSuspendAllInterrupts()             OsSaveDisableGlobalNested()
#     define VStdResumeAllInterrupts()              OsRestoreEnableGlobalNested()
#    else
#     define VStdGlobalInterruptDisable()           SuspendAllInterrupts()
#     define VStdGlobalInterruptRestore()           ResumeAllInterrupts()
#     define VStdSuspendAllInterrupts()             SuspendAllInterrupts()
#     define VStdResumeAllInterrupts()              ResumeAllInterrupts()
#    endif
#   elif defined(VSTD_ENABLE_APPL_INTCTRL)
#    define VStdDeclareGlobalInterruptOldStatus
#    define VStdPutGlobalInterruptOldStatus(x)
#    define VStdGetGlobalInterruptOldStatus(x)
#    define VStdGlobalInterruptDisable()           VStdUserNestedDisable()
#    define VStdGlobalInterruptRestore()           VStdUserNestedRestore()
#    define VStdSuspendAllInterrupts()             VStdUserNestedDisable()
#    define VStdResumeAllInterrupts()              VStdUserNestedRestore()
#   else
#    error "Please check VStdLib interrupt configuration!"
#   endif
#   define VStdNestedGlobalInterruptDisable() VStdGlobalInterruptDisable()
#   define VStdNestedGlobalInterruptRestore() VStdGlobalInterruptRestore()
#  endif

# if defined(VSTD_HL_ENABLE_MEM_FCT_MAPPING)
/* define hardware specific mappings of memcpy etc. */
# else
/* per default all memclr and memcpy functions are mapped on one routine which
   does not support different memory models */
/* memset abstraction */
#  define VStdMemSet(d, p, l)                 VStdMemSetInternal((void*)(d), (p), (vuint16)(l))
#  define VStdMemNearSet(d, p, l)             VStdMemSetInternal((void*)(d), (p), (vuint16)(l))
#  define VStdMemFarSet(d, p, l)              VStdMemSetInternal((void*)(d), (p), (vuint16)(l))

/* memclr abstraction */
#  define VStdMemClr(d, l)                    VStdMemClrInternal((void*)(d), (vuint16)(l))
#  define VStdMemNearClr(d, l)                VStdMemClrInternal((void*)(d), (vuint16)(l))
#  define VStdMemFarClr(d, l)                 VStdMemClrInternal((void*)(d), (vuint16)(l))

/* memcpy abstraction */
#  define VStdMemCpyRamToRam(d, s, l)         VStdRamMemCpy((void*)(d), (void*)(s), (vuint16)(l))
#  define VStdMemCpyRomToRam(d, s, l)         VStdRomMemCpy((void*)(d), (V_MEMROM1 void V_MEMROM2 V_MEMROM3 *)(s), (vuint16)(l))

#  define VStdMemCpyRamToNearRam(d, s, l)     VStdRamMemCpy((d), (void*)(s), (l))
#  define VStdMemCpyRomToNearRam(d, s, l)     VStdRomMemCpy((d), (V_MEMROM1 void V_MEMROM2 V_MEMROM3 *)(s), (vuint16)(l))

#  define VStdMemCpyRomToFarRam(d, s, l)      VStdRomMemCpy((d), (V_MEMROM1 void V_MEMROM2 V_MEMROM3 *)(s), (vuint16)(l))

#  define VStdMemCpyRamToFarRam(d, s, l)      VStdRamMemCpy((d), (s), (vuint16)(l))
#  define VStdMemCpyFarRamToRam(d, s, l)      VStdRamMemCpy((d), (s), (vuint16)(l))

#  define VStdMemCpyFarRamToFarRam(d, s, l)   VStdRamMemCpy((d), (s), (vuint16)(l))
#  define VStdMemCpyFarRomToFarRam(d, s, l)   VStdRomMemCpy((d), (s), (vuint16)(l))

#   define VStdMemCpy16RamToRam(d, s, l)     VStdRamMemCpy16((d), (s), (vuint16)(l))
#   define VStdMemCpy16RamToFarRam(d, s, l)  VStdRamMemCpy16((d), (s), (vuint16)(l))
#   define VStdMemCpy16FarRamToRam(d, s, l)  VStdRamMemCpy16((d), (s), (vuint16)(l))

#   define VStdMemCpy32RamToRam(d, s, l)     VStdRamMemCpy32((d), (s), (vuint16)(l))
#   define VStdMemCpy32RamToFarRam(d, s, l)  VStdRamMemCpy32((d), (s), (vuint16)(l))
#   define VStdMemCpy32FarRamToRam(d, s, l)  VStdRamMemCpy32((d), (s), (vuint16)(l))

# endif

/*********************************************************************************************************************/
/* Compatibility                                                                                                     */
/*********************************************************************************************************************/
# define VStdMemCpy(d,s,l)     VStdMemCpyRamToRam((d),(s),(l))

# if defined(VSTD_HL_USE_VSTD_RAMMEMCPY)
# else
#  define VStdRamMemCpy(d,s,l) VStdMemCpyRamToRam((d),(s),(l))
# endif

# if defined(VSTD_HL_USE_VSTD_ROMMEMCPY)
# else
#  define VStdRomMemCpy(d,s,l) VStdMemCpyRomToRam((d),(s),(l))
# endif

/*********************************************************************************************************************/
/* Prototypes of functions                                                                                           */
/*********************************************************************************************************************/

/* initialization */
/* CODE CATEGORY 4 START*/
VSTD_API_0 void VSTD_API_1 VStdInitPowerOn(void);
/* CODE CATEGORY 4 END*/
/* function for moving data */
# if defined(VSTD_HL_USE_VSTD_MEMCLR)
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdMemClrInternal(void *pDest, vuint16 nCnt) VSTD_API_2;
/* CODE CATEGORY 1 END*/
# endif
# if defined(VSTD_HL_USE_VSTD_MEMSET)
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdMemSetInternal(void *pDest, vuint8 nPattern, vuint16 nCnt) VSTD_API_2;
/* CODE CATEGORY 1 END*/
# endif
# if defined(VSTD_HL_USE_VSTD_RAMMEMCPY)
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdRamMemCpy(void *pDest, void *pSrc, vuint16 nCnt) VSTD_API_2;
/* CODE CATEGORY 1 END*/
# endif
# if defined(VSTD_HL_USE_VSTD_ROMMEMCPY)
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdRomMemCpy(void *pDest, V_MEMROM1 void V_MEMROM2 V_MEMROM3 *pSrc, vuint16 nCnt) VSTD_API_2;
/* CODE CATEGORY 1 END*/
# endif
# if defined(VSTD_HL_USE_VSTD_WORD_MEMCPY)
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdRamMemCpy16(void *pDest, void *pSrc, vuint16 nWordCnt) VSTD_API_2;
/* CODE CATEGORY 1 END*/
# endif
# if defined(VSTD_HL_USE_VSTD_DWORD_MEMCPY)
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdRamMemCpy32(void *pDest, void *pSrc, vuint16 nDWordCnt) VSTD_API_2;
/* CODE CATEGORY 1 END*/
# endif

/* Declaration of additional memory manipulation functions */

#  if defined(VSTD_ENABLE_INTCTRL_HANDLING)

/* interrupt control functions */
#   if defined(VSTD_ENABLE_DEFAULT_INTCTRL)
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdSuspendAllInterrupts(void) VSTD_API_2;
/* CODE CATEGORY 1 END*/
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdResumeAllInterrupts(void) VSTD_API_2;
/* CODE CATEGORY 1 END*/
#   endif

/* Declaration of additional Irq Support functions */
#if defined(VSTD_ENABLE_DEFAULT_INTCTRL)
# if (defined (V_COMP_TI)  &&  defined (__TI_TMS470_V7M3__)    ) || \
     (defined (V_COMP_ARM) && !defined (__TARGET_CPU_CORTEX_M3)) || \
      defined (V_COMP_GNU)
/* CODE CATEGORY 1 START */
VSTD_API_0 void VSTD_API_1 VStdLL_GlobalInterruptDisable(tVStdIrqStateType* localInterruptOldStatusPtr);
/* CODE CATEGORY 1 END */
/* CODE CATEGORY 1 START */
VSTD_API_0 void VSTD_API_1 VStdLL_GlobalInterruptRestore(tVStdIrqStateType localInterruptOldStatus);
/* CODE CATEGORY 1 END */
# endif
# if (defined (V_COMP_KEIL)            && defined (V_PROCESSOR_LPC1768))
  __asm void VStdLL_GlobalInterruptDisable(tVStdIrqStateType* localInterruptOldStatusPtr);
  __asm void VStdLL_GlobalInterruptRestore(tVStdIrqStateType localInterruptOldStatus);
# endif
#endif /* if defined(VSTD_ENABLE_DEFAULT_INTCTRL) */
#  endif


/*********************************************************************************************************************/
/* Callback functions                                                                                                */
/*********************************************************************************************************************/
# if defined(VSTD_ENABLE_DEBUG_SUPPORT)
/* CODE CATEGORY 4 START*/
VSTD_CALLBACK_0 void VSTD_CALLBACK_1 ApplVStdFatalError(vuint8 nErrorNumber);
/* CODE CATEGORY 4 END*/
# endif

#endif
