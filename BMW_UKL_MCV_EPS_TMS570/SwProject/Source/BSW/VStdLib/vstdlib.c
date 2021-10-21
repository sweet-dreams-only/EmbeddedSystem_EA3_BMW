/* Kernbauer Version: 1.16 Konfiguration: VStdLib Erzeugungsgangnummer: 1 */


/**********************************************************************************************************************
| Project Name: vstdlib library
|    File Name: vstdlib_ll.c
|
|  Description: Low level part of the implementation of standard Vector functions.
|               ARM core specific implementation.
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
| Hs           Hannes Haas               Vctr Informatik GmbH
| Ard          Thomas Arnold             Vctr Informatik GmbH
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
|2006-01-12  01.01.00    Ml     - Added VStdDeclare_LocalConst
|2006-02-02  01.02.00    Ml     - Added support for tms ARM7
|2006-02-14  01.03.00    Ard    - Add version history
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
|                        Ard    - ESCAN00030163: Support Omap derivative + Core update 3.3
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
|*********************************************************************************************************************/

/**********************************************************************************************************************
|
| Project Name : vstdlib library
|    File Name : vstdlib_HL.c
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
|2004-05-17  01.01.00    Ml     - added assertion
|                        Ml     - added define section
|                        Ml     - changed memoryqualifier
|                        Ml     - changed bugfix into releaseversion
|                        Ml     - added check for correct v_def.h version
|2004-05-18  01.02.00    Ms/HH  - changed memory qualifier concept
|2004-06-01  01.03.00    Ml     - corrected define for IRQ functions
|2004-08-06  01.04.00    Ml     - Split of library into HL and LL
|2004-08-18  01.05.00    Ml     - Added function qualifier
|2004-09-06  01.06.00    Ml     - ESCAN00009316: no changes
|2004-09-27  01.07.00    Ml     - no changes
|                        Ml     - changed namingconvention     
|2004-09-29  01.08.00    Et     - ESCAN00009692: split VStdMemCpy in VStdRamMemCpy and VStdRomMemCpy   
|2004-10-01  01.09.00    Ml     - ESCAN00009731: usage of standard type qualifiers
|2004-10-26  01.10.00    Ml     - ESCAN00010000: LL parts are split into HW specific files
|2004-11-09  01.11.00    Ml     - added VStd_LLPostInclude
|2004-11-15  01.12.00    Ml     - ESCAN00010533: Added optimized memory functions for HC08
|                        Ml     - ESCAN00010672: Added memory qualifier
|2005-01-24  01.13.00    Ml     - ESCAN00010670: Added memset
|2005-02-25  01.14.00    Ml     - ESCAN00011215: Added VStdInitPowerOn
|2005-04-26  01.15.00    Ml     - ESCAN00012047: Encapsulate VStdInitPowerOn
|            01.16.00    Ml     - ESCAN00012105: no changes
|2005-05-30  02.00.00    Ml     - ESCAN00013446: Development concept changed
|2005-09-12  02.01.00    Ml     - ESCAN00013512: Fixed Misra warnings
|2005-11-06  02.02.00    Ml     - ESCAN00014183: Added token for defines and types
|2005-11-28  02.03.00    Ml     - Changed version defines
|                        Ml     - ESCAN00014428: VStdMemClr/Set are now internal functions
|                        Ml     - ESCAN00014409: No changes       
|2005-12-12  02.04.00    Ml/Bus - ESCAN00012774: insert comments for different resource categories
|2006-01-12  02.05.00    Ml     - ESCAN00014897: Changed interrupt handling
|2006-01-14  02.06.00    Ml     - ESCAN00014908: Adapted interrupt control handling for RI1.5
|2006-02-07  02.07.00    Ml     - Added VStdGetInterruptState
|                        Hs     - ESCAN00015802: no changes
|2006-05-09  02.08.00    Ces    - ESCAN00016289: Insert memory qualifier V_MEMROM3 to VStdRomMemCpy()
|2006-05-24  02.09.00    BWR    - ESCAN00016488: Compiler error in VStdSuspendAllInterrupts and VStdResumeAllInterrupts
|2006-07-16  02.10.00    Ml     - Changed return type of VStdGetInterruptState from uint8 to tVStdIrqStateType
|2006-07-31  02.11.00    Ml     - ESCAN00017133: Changed assertion handling
|2006-08-04  02.12.00    Ml     - ESCAN00017188: no changes
|2006-11-20  02.13.00    Ml     - Removed VStdGetInterruptState
|2006-12-07  02.14.00    Ml     - Changed switch names
|                        Ml     - ESCAN00018889: Fixed code inspection report findings
|                               - ESCAN00018880: No changes
|2007-01-27  02.15.00    Ml,Ard - ESCAN00019251: VStdLib HL usable for RI1.4 and RI1.5
|2007-02-19  02.16.00    Ml     - ESCAN00019672: include os.h for AUTOSAR
|                        Ml     - ESCAN00019674: Changed names of interrupt lock macros
|2007-05-10  02.17.00    Ml     - ESCAN00020705: Added _COMMENT switches for single source filtering
|                        Ml     - ESCAN00020241: No changes
|2007-11-26  03.00.00    Ml     - ESCAN00024126: Support word and dword copy routines
|                        Ml     - ESCAN00024192: Default and specific implementations supported at the same time
|2008-06-25  03.01.00    Ml     - ESCAN00023334: Added u suffix to the version numbers
|                        Ml     - ESCAN00018659: Removed warnings if interrupt counter not used
|                        Ml     - ESCAN00015501: No changes
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

#define _VSTD_LIB_C_

#include "v_cfg.h"
#include "v_def.h"

#if defined(V_OSTYPE_AUTOSAR)
# include "os.h"
#elif defined(V_OSTYPE_OSEK)
# include "osek.h"
#endif

/* Encapsulation of AUTOSAR library check */
#if defined(VGEN_ENABLE_GW_ASRPDUR)
# define VSTD_ENABLE_MSR_LIB_VERSION_CHECK
#endif

/* MICROSAR library version checks */
#if defined(VSTD_ENABLE_MSR_LIB_VERSION_CHECK)
# include "Std_Types.h"
# if !defined(V_SUPPRESS_EXTENDED_VERSION_CHECK)
#  include "v_ver.h"
# endif

#endif

/*********************************************************************************************************************/
/* Version check                                                                                                     */
/*********************************************************************************************************************/

#if(VSTDLIB_ARM7_VERSION != 0x0132u)
# error "Lowlevel Source and Header files are inconsistent!"
#endif
#if(VSTDLIB_ARM7_RELEASE_VERSION != 0x01u)
# error "Lowlevel Source and Header file are inconsistent!"
#endif
/* MICROSAR library version check */
#define VSTDLIB_LIB_VERSION  VSTDLIB_ARM7_LIB_VERSION

/* Highlevel versioncheck */
#if(VSTDLIB__COREHLL_VERSION != 0x0305u)
# error "HighLevel Source and Header files are inconsistent!"
#endif

#if(VSTDLIB__COREHLL_RELEASE_VERSION != 0x01u)
# error "HighLevel Source and Header file are inconsistent!"
#endif

/* V_def.h Compatibility Check */
#if(COMMON_VDEF_VERSION < 0x0220u)
# error "VstdLib requires at least v_def.h in version 2.20.00!"
#endif

/* MICROSAR library version checks */
#if defined(VSTD_ENABLE_MSR_LIB_VERSION_CHECK)
# if !defined(V_SUPPRESS_EXTENDED_VERSION_CHECK)
#  if !defined(VSTDLIB_LIB_VERSION)
#   error "Make sure VSTDLIB_LIB_VERSION is defined in VStd_LLVersionCheck label!"
#  endif
CONST(uint32, VSTDLIB_CONST) VSTDLIB_LIB_SYMBOL = VSTDLIB_LIB_VERSION;
# endif
#endif

/* Additional checks */
#if defined (C_COMP_TI_TMS470)            || \
    defined (C_COMP_TI_TMS470_DCAN)       
#else
# error "Platform / Compiler not supported!"
#endif

/*********************************************************************************************************************/
/* Constants                                                                                                         */
/*********************************************************************************************************************/
/* ROM CATEGORY 4 START*/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kVStdMainVersion    = (vuint8)(((vuint16)VSTDLIB_ARM7_VERSION) >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kVStdSubVersion     = (vuint8)(((vuint16)VSTDLIB_ARM7_VERSION) & (vuint16)0x00FF);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kVStdReleaseVersion = (vuint8)( (vuint16)VSTDLIB_ARM7_RELEASE_VERSION);
/* ROM CATEGORY 4 END*/

/*********************************************************************************************************************/
/* Local Types                                                                                                       */
/*********************************************************************************************************************/
/* RAM CATEGORY 1 START*/
/* RAM CATEGORY 1 END*/

/*********************************************************************************************************************/
/* Defines                                                                                                           */
/*********************************************************************************************************************/
#define VSTD_STATIC_DECL static

#if !defined( VSTD_INTERRUPT_LOCK_LEVEL )
# define VSTD_INTERRUPT_LOCK_LEVEL   0x10 /* 0x10 is the highest priority, 0x00 = no interrupt lock */
#endif

#if !defined(VSTD_STATIC_DECL)
# define VSTD_STATIC_DECL static
#endif 

/*********************************************************************************************************************/
/* Local data definitions                                                                                            */
/*********************************************************************************************************************/
# if defined(VSTD_ENABLE_INTCTRL_HANDLING)
#  if defined(VSTD_ENABLE_DEFAULT_INTCTRL)
/* RAM CATEGORY 1 START*/
VSTD_STATIC_DECL tVStdIrqStateType vstdInterruptOldStatus; /* old IRQ state, variable not static because of some inline asm!! */
/* RAM CATEGORY 1 END*/
#  endif
#  if defined(VSTD_ENABLE_DEFAULT_INTCTRL)
/* RAM CATEGORY 1 START*/
static vsintx vstdInterruptCounter;   /* interrupt counter */
/* RAM CATEGORY 1 END*/
#  endif
# endif


/*********************************************************************************************************************/
/* Local function declarations                                                                                       */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/* Macros                                                                                                            */
/*********************************************************************************************************************/

#if defined(VSTD_ENABLE_DEBUG_SUPPORT)
# define VStdAssert(p,e)       if(!(p)){ ApplVStdFatalError(e); }
#else
# define VStdAssert(p,e)
#endif

/*********************************************************************************************************************/
/* Functions                                                                                                         */
/*********************************************************************************************************************/

/*********************************************************************************************************************
Name          : VStdInitPowerOn
Called by     : init routine
Preconditions : none
Parameters    : none
Return values : none
Description   : initializes the global data of the VStdLib
*********************************************************************************************************************/
/* CODE CATEGORY 4 START*/
VSTD_API_0 void VSTD_API_1 VStdInitPowerOn(void)
{

# if defined(VSTD_ENABLE_INTCTRL_HANDLING)
#  if defined(VSTD_ENABLE_DEFAULT_INTCTRL)
  vstdInterruptOldStatus = (tVStdIrqStateType)0;
#  endif
#  if defined(VSTD_ENABLE_DEFAULT_INTCTRL)
  vstdInterruptCounter = (vsintx)0;
#  endif
# endif
  
}
/* CODE CATEGORY 4 END*/

#if defined(VSTD_HL_USE_VSTD_MEMSET)
/*********************************************************************************************************************
Name          : VStdMemSetInternal
Called by     : -
Preconditions : -
Parameters    : void*   pDest    : destination pointer          
                vuint8  nPattern : the value which is used for filling
                vuint16 nCnt     : number of bytes to be filled 
Return values : none
Description   : fills nCnt bytes from address pDest on with the nPattern value
*********************************************************************************************************************/
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdMemSetInternal(void *pDest, vuint8 nPattern, vuint16 nCnt) VSTD_API_2
{
    /* Defaultimplementation */
    VStdAssert(pDest!=V_NULL, kVStdErrorMemSetInvalidParameter);
    while(nCnt > (vuint16)0x0000)
    {  
      nCnt--;
      ((vuint8*)pDest)[nCnt] = nPattern;
    }
}
/* CODE CATEGORY 1 END*/
#endif

#if defined(VSTD_HL_USE_VSTD_MEMCLR)
/*********************************************************************************************************************
Name          : VStdMemClr
Called by     : -
Preconditions : -
Parameters    : void*   pDest : destination pointer          
                vuint16 nCnt  : number of bytes to be filled 
Return values : none
Description   : fills nCnt bytes from address pDest on with 0x00 pattern
*********************************************************************************************************************/
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdMemClrInternal(void *pDest, vuint16 nCnt) VSTD_API_2
{
    /* Defaultimplementation */
    VStdAssert(pDest!=V_NULL, kVStdErrorMemClrInvalidParameter);
    while(nCnt > (vuint16)0x0000)
    {  
      nCnt--;
      ((vuint8*)pDest)[nCnt] = (vuint8)0x00;
    } 
}
/* CODE CATEGORY 1 END*/
#endif

#if defined(VSTD_HL_USE_VSTD_RAMMEMCPY)
/*********************************************************************************************************************
Name          : VStdRamMemCpy
Called by     : -
Preconditions : -
Parameters    : void*   pDest : RAM destination pointer          
                void*   pSrc  : RAM source pointer               
                vuint16 nCnt  : number of bytes to be copied 
Return values : none
Description   : moves nCnt bytes from RAM pSrc to RAM pDest
*********************************************************************************************************************/
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdRamMemCpy(void *pDest, void* pSrc, vuint16 nCnt) VSTD_API_2
{
    /* Defaultimplementation */
    VStdAssert(pDest!=V_NULL, kVStdErrorMemCpyInvalidParameter);
    VStdAssert(pSrc!=V_NULL, kVStdErrorMemCpyInvalidParameter);
    while(nCnt > (vuint16)0x0000)
    {  
      nCnt--;
      ((vuint8*)pDest)[nCnt] = ((vuint8*)pSrc)[nCnt];
    } 
}
/* CODE CATEGORY 1 END*/
#endif

#if defined(VSTD_HL_USE_VSTD_ROMMEMCPY)
/*********************************************************************************************************************
Name          : VStdRomMemCpy
Called by     : -
Preconditions : -
Parameters    : void*   pDest : ROM destination pointer          
                void*   pSrc  : ROM source pointer               
                vuint16 nCnt  : number of bytes to be copied 
Return values : none
Description   : moves nCnt bytes from ROM pSrc to RAM pDest
*********************************************************************************************************************/
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdRomMemCpy(void *pDest, V_MEMROM1 void V_MEMROM2 V_MEMROM3 *pSrc, vuint16 nCnt) VSTD_API_2
{  
    /* Defaultimplementation */
    VStdAssert(pDest!=V_NULL, kVStdErrorMemCpyInvalidParameter);
    VStdAssert(pSrc!=V_NULL, kVStdErrorMemCpyInvalidParameter);
    while(nCnt > (vuint16)0x0000)
    {
      nCnt--;
      ((vuint8*)pDest)[nCnt] = ((V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3 *)pSrc)[nCnt];
    } 
}
/* CODE CATEGORY 1 END*/
#endif

# if defined(VSTD_HL_USE_VSTD_WORD_MEMCPY)
/*********************************************************************************************************************
Name          : VStdRamMemCpy16
Called by     : -
Preconditions : -
Parameters    : void*   pDest    : RAM destination pointer
                void*   pSrc     : RAM source pointer
                vuint16 nWordCnt : Number of words to be copied
Return values : none
Description   : moves nWordCnt words from the source RAM address to the destination RAM address
*********************************************************************************************************************/
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdRamMemCpy16(void *pDest, void *pSrc, vuint16 nWordCnt) VSTD_API_2
{
    /* Defaultimplementation */
    VStdAssert(pDest!=V_NULL, kVStdErrorMemCpyInvalidParameter);
    VStdAssert(pSrc!=V_NULL, kVStdErrorMemCpyInvalidParameter);
    while(nWordCnt > (vuint16)0x0000)
    {
      nWordCnt--;
      ((vuint16*)pDest)[nWordCnt] = ((vuint16*)pSrc)[nWordCnt];
    } 
}
/* CODE CATEGORY 1 END*/
# endif

# if defined(VSTD_HL_USE_VSTD_DWORD_MEMCPY)
/*********************************************************************************************************************
Name          : VStdRamMemCpy32
Called by     : -
Preconditions : -
Parameters    : void*   pDest    : RAM destination pointer
                void*   pSrc     : RAM source pointer
                vuint16 nDWordCnt: Number of dwords to be copied
Return values : none
Description   : moves nDWordCnt dwords from the source RAM address to the destination RAM address
*********************************************************************************************************************/
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdRamMemCpy32(void *pDest, void *pSrc, vuint16 nDWordCnt) VSTD_API_2
{
    /* Defaultimplementation */
    VStdAssert(pDest!=V_NULL, kVStdErrorMemCpyInvalidParameter);
    VStdAssert(pSrc!=V_NULL, kVStdErrorMemCpyInvalidParameter);
    while(nDWordCnt > (vuint16)0x0000)
    {
      nDWordCnt--;
      ((vuint32*)pDest)[nDWordCnt] = ((vuint32*)pSrc)[nDWordCnt];
    } 
}
/* CODE CATEGORY 1 END*/
# endif

/*********************************************************************************************************************/
/* Additional functions for memory manipulation                                                                      */
/*********************************************************************************************************************/

/*********************************************************************************************************************
The functions below require a plattform specific implementation, therefore 
they are not available for the standard implementation of the library!
*********************************************************************************************************************/
# if defined(VSTD_ENABLE_INTCTRL_HANDLING)
#  if defined(VSTD_ENABLE_DEFAULT_INTCTRL)
/*********************************************************************************************************************
Name          : VStdSuspendAllInterrupts
Called by     : -
Preconditions : -
Parameters    : none
Return values : none
Description   : disables the global IRQ and saves the current IRQ state
*********************************************************************************************************************/
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdSuspendAllInterrupts(void) VSTD_API_2
{
  VStdDeclareGlobalInterruptOldStatus
#    if defined(VSTD_ENABLE_OSEK_INTCTRL)
  VStdGlobalInterruptDisable();
  VStdGetGlobalInterruptOldStatus(vstdInterruptOldStatus);
#    else
  VStdAssert(vstdInterruptCounter < 127, kVStdErrorIntDisableTooOften);
  if(vstdInterruptCounter == 0) 
  {
    VStdGlobalInterruptDisable();
    VStdGetGlobalInterruptOldStatus(vstdInterruptOldStatus);
  }
  vstdInterruptCounter++;
#    endif
}
/* CODE CATEGORY 1 END*/

/*********************************************************************************************************************
Name          : VStdResumeAllInterrupts
Called by     : -
Preconditions : -
Parameters    : none
Return values : none
Description   : restores the previous IRQ state
*********************************************************************************************************************/
/* CODE CATEGORY 1 START*/
VSTD_API_0 void VSTD_API_1 VStdResumeAllInterrupts(void) VSTD_API_2
{
  VStdDeclareGlobalInterruptOldStatus
#    if defined(VSTD_ENABLE_OSEK_INTCTRL)
  VStdPutGlobalInterruptOldStatus(vstdInterruptOldStatus);
  VStdGlobalInterruptRestore();
#    else
  VStdAssert(vstdInterruptCounter > 0, kVStdErrorIntRestoreTooOften);
  vstdInterruptCounter--;
  if(vstdInterruptCounter == 0)
  {
    VStdPutGlobalInterruptOldStatus(vstdInterruptOldStatus);
    VStdGlobalInterruptRestore();
  }
#    endif
}
/* CODE CATEGORY 1 END*/
#  endif

/*********************************************************************************************************************/
/* Additional functions for interrupt manipulation                                                                   */
/*********************************************************************************************************************/
#if defined(VSTD_ENABLE_DEFAULT_INTCTRL)

# if defined (V_COMP_ARM) && !defined (__TARGET_CPU_CORTEX_M3)

VSTD_API_0 void VSTD_API_1 VStdLL_GlobalInterruptDisable(tVStdIrqStateType* localInterruptOldStatusPtr)
{                                                                   
  vuint32 tmp;

  __asm { MRS tmp, CPSR }

  *(localInterruptOldStatusPtr) = tmp & kIrqIbitMask; 
  tmp = tmp | kIrqIbitMask;   
                        
  __asm { MSR CPSR_c, tmp }     
                                           
  VSTD_CLEAR_INSTRUCTION_PIPE();                                                                   
}

VSTD_API_0 void VSTD_API_1 VStdLL_GlobalInterruptRestore(tVStdIrqStateType localInterruptOldStatus)
{                                                                   
  vuint32 tmp;

  __asm { MRS tmp, CPSR }  

  tmp = (tmp & ~kIrqIbitMask) | localInterruptOldStatus;                   

  __asm { MSR CPSR_c, tmp }                           
}

# endif

# if (defined (V_COMP_KEIL) && defined (V_PROCESSOR_LPC1768))
  __asm void VStdLL_GlobalInterruptDisable(tVStdIrqStateType* localInterruptOldStatusPtr)
{
  /* access in non-user mode */
  PUSH {r1}               /* save temp registers */  
  MRS r1, PRIMASK         /* Read PRIMASK register into R1 */
  STR r1, [r0]            /* Store old PRIMASK at address of function parameter */
  MOV r1, #0x1            /* update R1 */
  MSR PRIMASK, r1         /* Write R1 into PRIMASK register */
  POP {r1}                /* restore temp register */
  BX LR                   /* return */
}         

  __asm void VStdLL_GlobalInterruptRestore(tVStdIrqStateType localInterruptOldStatus)
{ 
  /* access in non-user mode */
  MSR PRIMASK, r0         /* restore value of function parameter in register */  
  BX LR                   /* return */
}
# endif


# if defined (V_COMP_TI) && defined (__TI_TMS470_V7M3__)  
/* CODE CATEGORY 1 START */
VSTD_API_0 void VSTD_API_1 VStdLL_GlobalInterruptDisable(tVStdIrqStateType* localInterruptOldStatusPtr)
{
  /* Satisfy compiler */
  *localInterruptOldStatusPtr = *localInterruptOldStatusPtr;
  
  /* access in non-user mode */
  __asm(" PUSH {r1}");           /* save temp registers */
  __asm(" MRS r1, PRIMASK");     /* Read PRIMASK register into R1 */
  __asm(" STR r1, [r0]");        /* Store old PRIMASK at address of function parameter */
  __asm(" MOV r1, #0x1");        /* update R1 */
  __asm(" MSR PRIMASK, r1");     /* Write R1 into PRIMASK register */
  __asm(" POP {r1}");            /* restore temp register */
}         
/* CODE CATEGORY 1 END */
/* CODE CATEGORY 1 START */
VSTD_API_0 void VSTD_API_1 VStdLL_GlobalInterruptRestore(tVStdIrqStateType localInterruptOldStatus)
{  
   /* Satisfy compiler */
  localInterruptOldStatus = localInterruptOldStatus;
  
  /* access in non-user mode */
  __asm(" MSR PRIMASK, r0");  /* restore value of function parameter in register */
}
/* CODE CATEGORY 1 END */
# endif 

# if defined( V_COMP_GNU )
#  if defined (VSTD_ENABLE_FIQ_INTCTRL)

VSTD_API_0 void VSTD_API_1 VStdLL_GlobalInterruptDisable(tVStdIrqStateType* localInterruptOldStatusPtr)
{
  __asm volatile ("MRS   r1, CPSR; \n                                                       \
                   AND   r2, r1, #0xC0; \n                                                  \
                   STR   r2, [%0]; \n                                                       \
                   ORR   r1, r1, #0xC0; \n                                                  \
                   MSR   CPSR_cxsf, r1"  : : "r" (localInterruptOldStatusPtr) : "r1" );
  VSTD_CLEAR_INSTRUCTION_PIPE();                                                            
};                                                                                          
      
VSTD_API_0 void VSTD_API_1 VStdLL_GlobalInterruptRestore(tVStdIrqStateType localInterruptOldStatus)
{ 
  __asm volatile ("MRS   r1, CPSR; \n                                                       \
                   BIC   r1, r1, #0xC0; \n                                                  \
                   ORR   r1, r1, %0 \n                                                      \
                   MSR   CPSR_cxsf, r1"  : : "r" (localInterruptOldStatus) : "r1" );
};                                                                                         

#  else

VSTD_API_0 void VSTD_API_1 VStdLL_GlobalInterruptDisable(tVStdIrqStateType* localInterruptOldStatusPtr)
{ 
  __asm volatile ("MRS   r1, CPSR; \n                                                       \
                   AND   r2, r1, #0x80; \n                                                  \
                   STR   r2, [%0]; \n                                                       \
                   ORR   r1, r1, #0x80; \n                                                  \
                   MSR   CPSR_cxsf, r1"  : : "r" (localInterruptOldStatusPtr) : "r1" );
  VSTD_CLEAR_INSTRUCTION_PIPE();
}; 
      
VSTD_API_0 void VSTD_API_1 VStdLL_GlobalInterruptRestore(tVStdIrqStateType localInterruptOldStatus)
{
  __asm volatile ("MRS   r1, CPSR; \n                                                       \
                   BIC   r1, r1, #0x80; \n                                                  \
                   ORR   r1, r1, %0 \n                                                      \
                   MSR   CPSR_cxsf, r1"  : : "r" (localInterruptOldStatus) : "r1" );
};

#  endif
# endif

#endif  /* if defined(VSTD_ENABLE_DEFAULT_INTCTRL) */


# endif
