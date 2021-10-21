/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */


/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007-2011 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Fr.h
 *    Component:  FlexRay Stack
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Public header for FlexRay Driver
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Sebastian Schmar              Ssr           Vctr Informatik GmbH
 *  Juergen Schaeffer             Jsr           Vctr Informatik GmbH
 *  Sebastian Gaertner            Seg           Vctr Informatik GmbH
 *  Mario Kunz                    Mkz           Vctr Informatik GmbH
 *  Alex Lunkenheimer             Alr           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  03.00.00  2007-08-23  Ssr                   Adapt to AUTOSAR 3.0 (pre)
 *  03.00.01  2007-12-12  Ssr     ESCAN00023676 optimize code, Add dynamic payload support
 *  03.00.02  2008-01-16  Jsr                   Add memory mapping, compiler abstraction, compiler switches 
 *                                              added memcopy functions
 *  03.00.03  2008-02-07  Jsr                   updates after review
 *  03.00.04  2008-02-15  Jsr                   minor changes
 *  03.00.05  2008-02-21  Jsr                   Add version check for DLL
 *  03.00.06  2008-02-22  Jsr                   rename of GENY generated defines
 *  03.00.07  2008-02-19  Jsr     ESCAN00024975
 *                                ESCAN00024950
 *                                ESCAN00024946
 *                                ESCAN00023416
 *                                ESCAN00024997 
 *  03.00.08  2008-03-02  Jsr     ESCAN00025275 optimazation. DLL version changed
 *  03.00.09  2008-03-27  Alr     ESCAN00025564 missing DFI support
 *  03.00.10  2008-04-03  Jsr                   DLL version changed
 *  03.00.11  2008-04-10  Jsr     ESCAN00025999 TMS470 added
 *  03.01.00  2008-04-14  Jsr                   Rename internal variables
 *                                              Adapted code consitency check
 *                                ESCAN00026209
 *                                ESCAN00026137
 *                                ESCAN00026259
 *                                ESCAN00026284
 *                                ESCAN00022574
 *                                ESCAN00026448
 *                                              Updated memmap and compiler abstraction definitions
 *  03.01.01  2008-05-20  Jsr                   Adapted revision calculation
 *                                ESCAN00026643 (Lib check)
 *  03.02.00  2008-06-14  Seg     ESCAN00027381 added Fr_VErrorStatusType and Prototypes
 *  03.02.01  2008-06-24  Jsr     ESCAN00027823 
 *                                ESCAN00027841
 *  03.03.00  2008-08-05  Jsr     ESCAN00028065
 *                                ESCAN00025647
 *                                ESCAN00026728
 *                                ESCAN00027389
 *                                ESCAN00028231 Fr_ReceiveRxLPdu does not return the payload length of a received frame.
 *  03.03.01  2008-08-19  Jsr     ESCAN00029232 LibCheck update
 *                                ESCAN00029154
 *                                ESCAN00029268 Single channel api
 *  03.04.00  2008-08-22  Seg     ESCAN00029279 Message ID filtering
 *                                ESCAN00029395 Improvements for pointer names for being ASR conform
 *                                ESCAN00029391 compiler abstractions for precompile time and postbuild variant (FR_CONST -> FR_PBCFG)
 *                                ESCAN00029620 FR_NULL_FRAME_RECEIVED is used, but not defined
 *                                ESCAN00029154 No Fr communication (optional inline optimization)
 *                                ESCAN00029711 incomplete API optimization makros for relative timer
 *  03.04.01  2008-09-11  Ssr     ESCAN00029920 Returnvalue within Fr_ReceiveRxLPdu 
 *                                ESCAN00029922 Correct Fr_LPduStatusPtr and Fr_LPduLengthPtr
 *  03.04.02  2008-09-23  Seg     ESCAN00030202 ERay module on TC1797 needs to be enabled by the driver 
 *  03.05.00  2008-10-24  Ssr     ESCAN00029733 instanceID by <MSN>_GetVersionInfo
 *                                ESCAN00029737 DET by <MSN>_GetVersionInfo as Macro
 *                                ESCAN00030041 Eray buffer reconfiguration
 *                                ESCAN00030042 DrvFr_V85xErayVx Fr_TransmitTxLPdu configuration
 *                                              check
 *                                ESCAN00030798 Warnings in Fr.c if Visual Studio 8 used
 *                                ESCAN00030416 Add MBF to CANoeemu driver
 *                                ESCAN00030821 Channel name of the simulation of the remaining bus
 *  03.05.01  2008-10-27  Ssr     ESCAN00030895 Return value of Fr_CheckTxLPduStatus
 *                                ESCAN00030896 Contend of Fr_PrepareLPdu within CANoe Driver
 *                                ESCAN00031028 Correct MTS API for CANoe Driver
 *  03.06.00  2008-11-07  Ssr     ESCAN00031133 Optimize CRC calculation
 *                                ESCAN00031238 FlexRay Driver reports DET error when Fr_PrepareLPdu is called
 *                                ESCAN00031358 Remove swap Message Id filtering CANoe driver
 *                                ESCAN00030962 Add Fr_GetClockCorrection and Fr_GetChannelStatus instead
 *                                              current Fr_GetChannelStatus
 *                                ESCAN00030456 Declaration of the postbuild arrays
 *                                ESCAN00030903 Postbuild message buffer Id filtering
 *                                ESCAN00029693 AUTOSAR Dummy Statements
 *                        Seg     ESCAN00030266 PreCompile and Linktime Crc Check
 *                                ESCAN00031774 MISRA rework
 *                        Seg     ESCAN00031903 insufficient interrupt lock
 *                                ESCAN00030543 FlexRay Driver does not always report an production error in case of CC access errors
 *  03.06.01  2009-01-14  Ssr     ESCAN00032377 Frames with dynamic payload length can be truncated
 *  03.07.00  2009-01-26  Jsr     ESCAN00031239 Status of sync frames changed from cyclic to event triggered
 *                                ESCAN00032528 No FrIf_JobListExec_0 with "Application callback at timer 0 interrupt" is switched off
 *                                ESCAN00032341 Unneccessary call of FrIf_JobListExec_0 at specific configuration
 *                                ESCAN00032152 CANoeEmu Driver does not transmit some frames in dyn segment if Buffer Reconf is enabled
 *                        Ssr     ESCAN00032825 Add tricore specific parameters
 *                                ESCAN00032943 Unnecessarary Dem event FR_E_ACCESS report
 *  03.07.01  2009-02-23  Ssr     ESCAN00033310 Clean unnecessary comments
 *  03.08.00  2009-03-31  Jsr     ESCAN00033251 FTU support
 *                                ESCAN00033647 Fr_VReadDataFromCC and Fr_VWriteDataToCC with unique lengh
 *                        Ssr     ESCAN00032560 Det check for relative timer
 *                                ESCAN00033265 Check timely pickup of Rx Frames
 *                                ESCAN00033666 Version shall be BCD coded
 *                                ESCAN00033421 Hardware Loop Check
 *                                ESCAN00033679 Simplify the include structure of Fr_Priv.h
 *                                ESCAN00033539 Add Link Time Support
 *                                ESCAN00034077 incorrect DET check for wrong channel index
 *                                ESCAN00033850 Add POLYSPACE support
 *                                ESCAN00034035 Compile warnings by extended version checks
 *                                ESCAN00034554 Timer0 optimization
 *                                ESCAN00034556 MTS on channel B
 *                                ESCAN00034658 Interrupts not enabled correctly
 *  03.08.01  2009-05-26  Ssr     ESCAN00035352 CANoeEmu. Compile errors
 *                                ESCAN00032332 CANoeEmu: FlexRay_Init should be called by Flexray Driver (CANoe)
 *                                ESCAN00033218 CANoeEmu: Register frames with half payload  
 *                                ESCAN00032680 CANoeEmu: message "FlexRay channel 2 not allowed!"
 *                                ESCAN00035403 CANoeEmu: Cycle Multiplexing
 *                                ESCAN00035406 Remove the Fr_PrepareLPdu API from source code
 *  03.08.02  2009-06-03  Jsr     ESCAN00035483 DBA: break interrupt locks over functions
 *                                ESCAN00035560 MSG ID Filtering for TMS with FTU and ISO-TP
 *  03.09.00  2009-07-30  Ssr     ESCAN00036314 FlexRay Driver shall support FIFOs (Asr 4.0)
 *                        Jsr     ESCAN00031969 update function headers
 *                                ESCAN00029731 undefined symbols with Tx/Rx-Interrupt configuration
 *                                ESCAN00036136 pre-processor checks for building the library
 *                                ESCAN00033134 Add Version-number [BR:012]
 *  03.09.01  2009-07-31  Jsr                   Update DLL Version in h file
 *  03.09.02  2009-08-06  Jsr     ESCAN00036853 Bugfix: Fifo support with CANoe Emu 
 *                                ESCAN00036973 Wrong memmap defines for SEC_PBCFG_ROOT
 *  03.10.00  2009-09-15  Ssr     ESCAN00036487 FlexRay Driver shall support FIFOs (Asr 4.0) for TMS
 *                                ESCAN00037806 Add TMS to single source
 *                        Jsr     ESCAN00037052 No memap for an variable declaration
 *                                ESCAN00036852 No FlexRay Communication with CANoe Emu and Real Bus
 *                        Mkz     ESCAN00037911 Enable access to internal E-Ray registers
 *                        Ssr     ESCAN00037988 Partially data lost FTU
 *  03.10.01  2009-10-16  Jsr     ESCAN00038534 v_def.h should be included to import VGEN_ENABLE_IF_ASRIFFR
 *  03.10.02  2009-11-11  Jsr     ESCAN00039062 CANoe EMU driver does not stop transmitting frames after Fr_HaltCommunication
 *                                ESCAN00035703 Similar DET Usage
 *  03.10.03  2009-11-12  Jsr     ESCAN00039130 CANoe emu driver shall handle FrameIds with illegal values
 *  03.10.04  2009-11-13  Jsr     ESCAN00039150 EXTENDED_VERSION_CHECK produces compiler error at link time variant
 *  03.11.00  2009-11-13  Jsr     ESCAN00037153 Read and verification of the FlexRay configuration
 *                                ESCAN00039056 FlexRay CANoe emu driver shall not includes "FrTrcv.h"
 *  03.11.01  2009-11-27  Jsr                   Update CCConfig
 *                                ESCAN00037929 Use of FR_PROCESSOR_FX4 instead of C_PROCESSOR_FX4
 *                                ESCAN00039750 Compile Error at SW-Fifo Configuration
 *                        Ssr     ESCAN00037153 Add the verification part
 *                                ESCAN00035423 Compiler errors
 *                                ESCAN00033431 Missing compiler abstraction in the CC register access macros
 *                                ESCAN00039804 Compiler errors CRC check
 *  03.12.00  2010-01-27  Jsr     ESCAN00039795 Wrong comparison in Extended Version Check at 16bit micro controller
 *                                ESCAN00040412 Resource Improvement of Link Time Configuration Variant 
 *                                ESCAN00039986 Compiler Errors
 *                                ESCAN00039487 Solve MISRA finding in Fr_ERay.h
 *                                ESCAN00039511 Compatibility with 16bit host
 *                                ESCAN00041307 Wrong Er_GetGlobalTime values
 *                                ESCAN00041447 Callback to get configuration data of application for hardware initialization of CANoe before stack is started.
 *                                ESCAN00040287 Disable cycle start interrupt if not required
 *                                ESCAN00042203 Workaround Errata No.35
 *                                ESCAN00042207 Missing Rx Frame
 *                                ESCAN00042574 Optimization Eray access
 *                                ESCAN00039952 Similar DET Usage 
 *                        Seg     ESCAN00041418 Support multi identity configurations
 *                                ESCAN00041422 Det Error Check returns wrong API ID value
 *                                ESCAN00041423 Compile Error 
 *            2010-04-07  Ssr     ESCAN00041910 Add one handle room for frames
 *                                ESCAN00041911 Compiler Errors
 *                                ESCAN00041912 Compiler Errors
 *                                ESCAN00041921 Compiler Errors  
 *                                ESCAN00041307 Wrong Er_GetGlobalTime values
 *                                ESCAN00042040 Remove include "v_def.h"
 *  03.13.00  2010-05-18  Jsr     ESCAN00042985 Wrong value of Service ID FR_API_ID_READCCCONFIG
 *                                ESCAN00041681 Support Generic derivative
 *                                ESCAN00042889 Null Frame reception
 *                                ESCAN00043529 data loss due to insufficient compiler abstraction
 *                                ESCAN00043905 Add support Fr_GetClockCorrection switch and synchronize it with FrIf
 *                                ESCAN00043670 Remove FR_E_INV_MBUF_IDX
 *                                ESCAN00043748 No reset of FTU when FTU is not used
 *                                ESCAN00043899 Delete SPI code of the derivate XMB88121B
 *                                ESCAN00043901 Add Fr_DeInit function
 *                                ESCAN00043913 Remove compiler warning of 'statement is unreachable' if DET is enabled
 *                                ESCAN00044818 Wrong return value in Fr_ControllerInit if CCconfiguration does not fit in CC 
 *                                ESCAN00044851 Compiler warning at configuration with enabled "Read and Verify FlexRay Parameters" and "Amount of reconfiguration"=0 
 *                                ESCAN00044858 Generate data for NmVectorLength only if Fr-NM is enabled 
 *                                ESCAN00042899 Optimization NFI check 
 *                                ESCAN00039656 optimization of Fr_ISR_Timer0 and Fr_IrqTimer0 to reduce resources 
 *                                ESCAN00039987 Missing DET checks 
 *                                ESCAN00044292 check compiler abstractions  
 *                                ESCAN00041157 DEM usage configurable   
 *                                ESCAN00044449 check memory abstraction 
 *                                ESCAN00045055 Compile error 
 *                                ESCAN00045084 [CANoeEmu] Compile Error  
 *  03.13.01  2010-09-20  Ssr     ESCAN00045507 Missing DET check for Null_Ptr at ReadCCConfig
 *                                ESCAN00046009 Add additional DET check for incorrect channel name configuration
 *                                ESCAN00046022 Remove unused code
 *                                ESCAN00045912 Compile Error
 *  03.14.00  2010-10-25  Ssr     ESCAN00046175 Remove support of Bit5 at Fr_GetChannelStatus
 *                                ESCAN00046317 Lost of aggregated channel status information
 *                                ESCAN00046333 Add bidirectional routing
 *                                ESCAN00046366 Adapt AUTOSAR version check
 *                                ESCAN00046939 Remove exclusive area at Fr_ReceiveLpdu
 *                                ESCAN00046514 Include dem.h only if used
 *                                ESCAN00046516 Optimize Fr_DisableLpdu
 *                                ESCAN00046638 Unbalanced calls of enter/leave critical section
 *                                ESCAN00046648 Remove pragma at void Irq(void) function
 *                                ESCAN00046448 Fr_ReadCCConfig shall return E_NOT_OK if parameter out of bounds
 *                                ESCAN00046945 Remove unused feature
 *                                ESCAN00047062 Missing include of FrIf.h at Fr_Irq.c
 *                                ESCAN00048216 Correct history
 *                                ESCAN00048386 Adjusted of DEM macros access
 *                                ESCAN00048614 Move checks of feature support
 *                                ESCAN00047950 Update include structure
 *                                ESCAN00048664 Optimize implementation of Fr_VReadDataFromCC
 *  03.14.01  2011-02-22  Ssr     ESCAN00048824 Premature locking of the FTU
 *                                ESCAN00048825 Fail Key Slot check  
 *                                ESCAN00047733 add compiler abstractions
 *                                ESCAN00048829 Add new FR_EXCLUSIVE_AREA for the FTU locking
 *  03.14.02  2011-03-09  Ssr     ESCAN00049160 Add support for Sh2 derivat
 *  03.14.03  2011-04-06  Ssr     ESCAN00049507 Reception of empty Frame
 *  03.14.04  2011-08-05  Ssr     ESCAN00052588 Add support for Px4
 *********************************************************************************************************************/
#ifndef FR_H
#define FR_H

/* PRQA S 0857 EOF */ /* Misra rule 11.3. Standard justification for Macro usage in Fr */

/**************************************************************************************************
* Filtered for DrvFr_Tms470ErayAsr 
**************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Fr_GeneralTypes.h"
#include "Fr_ERay.h"
#include "Fr_Cfg.h"
#include "Fr_Lcfg.h"
#include "Fr_PBcfg.h"
#include "Fr_Ext.h"
#if (FR_PROD_ERROR_DETECT == STD_ON)
#include "Dem.h"
#endif
#if (FR_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif


/**************************************************************************************************
* VERSION CHECK
**************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject :   DrvFr_XErayAsr CQComponent : Implementation */
#define DRVFR_XERAYASR_VERSION          0x0314u /* BCD coded version number */
#define DRVFR_XERAYASR_RELEASE_VERSION  0x04u   /* BCD coded release version number  */

/* FR ModuleId */
#define FR_VENDOR_ID                           30u   /* Vctr ID */
#define FR_MODULE_ID                           81u   /* FlexRay Driver ID */

/* Implemented AUTOSAR Specification Version */
# define FR_AR_VERSION                  0x0202u
# define FR_AR_RELEASE_VERSION          0x01u

/* Check consistency of source and generation files. */
#if ( DRVFR__BASEASR_DLL_VERSION != 0x0314u )
  #error "Fr Component: Embedded component and GENy configuration are inconsistent!"
#endif
#if ( DRVFR_XERAYASR_DLL_VERSION != 0x0312u )
  #error "Fr Component: Embedded component and GENy configuration are inconsistent!"
#endif
#if ( DRVFR_TMS470ERAYASR_DLL_VERSION != 0x0209u )
  #error "Fr Component: Embedded component and GENy configuration are inconsistent!"
#endif

#if defined ( DET_VENDOR_ID )
# if (DET_VENDOR_ID == FR_VENDOR_ID)
#  if (FR_DEV_ERROR_DETECT == STD_ON)
#   if defined(DET_AR_MAJOR_VERSION) && defined(DET_AR_MINOR_VERSION)
#    if((DET_AR_MAJOR_VERSION != 0x02u) || (DET_AR_MINOR_VERSION != 0x02u))
#     error "Imported module has incompatible AR version - expected DET version is 0x02u.0x02u \
                                                      (DET_AR_MAJOR_VERSION.DET_AR_MINOR_VERSION)."
#    endif
#   endif
#  endif
# endif
#endif

#if defined ( DEM_VENDOR_ID )
# if (DEM_VENDOR_ID == FR_VENDOR_ID)
#  if (FR_PROD_ERROR_DETECT == STD_ON)
#   if defined(DEM_AR_MAJOR_VERSION) && defined(DEM_AR_MINOR_VERSION)
#    if((DEM_AR_MAJOR_VERSION != 0x02u) || (DEM_AR_MINOR_VERSION != 0x02u))
#     error "Imported module has incompatible AR version - expected DEM version is 0x02u.0x02u \
                                                      (DEM_AR_MAJOR_VERSION.DEM_AR_MINOR_VERSION)."
#    endif
#   endif
#  endif
# endif
#endif
#if defined ( V_USE_DUMMY_STATEMENT )
# if  ( (V_USE_DUMMY_STATEMENT == STD_OFF) || (V_USE_DUMMY_STATEMENT == STD_ON)  )
# else
#  error  "Component Fr: Enable or disable dummy statement usage!"
# endif
#endif




# if defined FR_VENABLE_MID_FILTERING
#  if ( FR_VENABLE_MID_FILTERING == STD_ON )
#   error "Fr.c: FR_VENABLE_MID_FILTERING shall not be enabled."
#  endif
# endif

# if defined FR_VENABLE_RX_INTERRUPT
#  if ( FR_VENABLE_RX_INTERRUPT == STD_ON )
#   error "Fr.c: FFR_VENABLE_RX_INTERRUPT shall not be enabled."
#  endif
# endif
# if defined FR_VENABLE_TX_INTERRUPT
#  if ( FR_VENABLE_TX_INTERRUPT == STD_ON )
#   error "Fr.c: FFR_VENABLE_TX_INTERRUPT shall not be enabled."
#  endif
# endif















/* supported Autosar version */
#define FR_AR_MAJOR_VERSION     2u
#define FR_AR_MINOR_VERSION     2u
#define FR_AR_PATCH_VERSION     1u
#define FR_SW_MAJOR_VERSION     (DRVFR_XERAYASR_VERSION >> 8u)
#define FR_SW_MINOR_VERSION     (DRVFR_XERAYASR_VERSION & 0xFF)
#define FR_SW_PATCH_VERSION     (DRVFR_XERAYASR_RELEASE_VERSION)

#if defined V_EXTENDED_BUILD_LIB_CHECK
 /* pre-processor checks for building the library */
# if (FR_CONFIG_VARIANT == 1 )
#  error  "Component Fr: Config variant must be 2 or 3 at lib delivery."
# endif
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#if ((FR_CONFIG_VARIANT == 3 ) || (FR_CONFIG_VARIANT == 2))
extern CONST(Dem_EventIdType, FR_CONST) Fr_DEM_E_Access;
extern CONST(Dem_EventIdType, FR_CONST) Fr_DEM_E_CtrlTestResult;
#endif   
      /* (FR_CONFIG_VARIANT == 3 ) || (FR_CONFIG_VARIANT == 2) */
      
# if (( FR_CRC_CHECK == STD_ON ) && (3 == FR_CONFIG_VARIANT)  )
extern CONST(uint32, FR_CONST) Fr_LinktimeCRC;
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/* Driver limitations */
#define FR_MAX_NUM_LPDU_LENGTH
#define FR_MAX_NUM_ABS_TIMER                    1u 
#define FR_MAX_NUM_REL_TIMER                    1u 



/* FR ApiIds */
#define FR_API_ID_CONTROLLER_INIT                 0x00u
#define FR_API_ID_SEND_MTS                        0x01u
#define FR_API_ID_CHECK_MTS                       0x02u
#define FR_API_ID_START_COMMUNICATION             0x03u
#define FR_API_ID_HALT_COMMUNICATION              0x04u
#define FR_API_ID_ABORT_COMMUNICATION             0x05u
#define FR_API_ID_SEND_WUP                        0x06u
#define FR_API_ID_SET_WAKEUP_CHANNEL              0x07u
#define FR_API_ID_SET_EXT_SYNC                    0x08u
#define FR_API_ID_GET_SYNC_STATE                  0x09u
#define FR_API_ID_GET_POC_STATUS                  0x0Au
#define FR_API_ID_CHECK_TX_LPDU_STATUS            0x0Du
#define FR_API_ID_GET_GLOBAL_TIME                 0x10u
#define FR_API_ID_SET_ABSOLUTE_TIMER              0x11u
#define FR_API_ID_SET_RELATIVE_TIMER              0x12u
#define FR_API_ID_CANCEL_RELATIVE_TIMER           0x14u
#define FR_API_ID_CANCEL_ABSOLUTE_TIMER           0x13u
#define FR_API_ID_ENABLE_ABSOLUTE_TIMER_IRQ       0x15u
#define FR_API_ID_ENABLE_RELATIVE_TIMER_IRQ       0x16u
#define FR_API_ID_ACK_ABSOLUTE_TIMER_IRQ          0x17u
#define FR_API_ID_ACK_RELATIVE_TIMER_IRQ          0x18u
#define FR_API_ID_DISABLE_ABSOLUTE_TIMER_IRQ      0x19u
#define FR_API_ID_DISABLE_RELATIVE_TIMER_IRQ      0x1Au
#define FR_API_ID_GET_VERSION_INFO                0x1Bu
#define FR_API_ID_INIT                            0x1Cu
#define FR_API_ID_STOP_MTS                        0x1Du
#define FR_API_ID_PREPARE_LPDU                    0x1Fu
#define FR_API_ID_GET_ABSOLUTE_TIMER_IRQ_STATUS   0x20u
#define FR_API_ID_GET_RELATIVE_TIMER_IRQ_STATUS   0x21u
#define FR_API_ID_GET_NM_VECTOR                   0x22u
#define FR_API_ID_ALLOW_COLDSTART                 0x23u
#define FR_API_ID_FR_RECONFIG_LPDU                0x25u
#define FR_API_ID_FR_DISABLE_LPDU                 0x26u
# if ( FR_VCHANNEL_STATUS_EXT == STD_ON )
#define FR_API_ID_GET_CHANNEL_STATUS              0x28u
#define FR_API_ID_GET_CLOCK_CORRECTION            0x29u
# endif

#define FR_API_ID_GET_SYNC_FRAME_LIST             0x2Au


#if (defined(FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (STD_ON == FR_DIRECT_BUFFER_ACCESS_ENABLE)
#define FR_API_ID_REQUEST_BUFFER_DBA              0x30u
#define FR_API_ID_TRANSMIT_TX_LPDU_DBA            0x31u
#define FR_API_ID_RECEIVE_RX_LPDU_DBA             0x32u
#define FR_API_ID_UNLOCK_RX_LPDU_DBA              0x33u
#endif  /* (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (STD_ON == FR_DIRECT_BUFFER_ACCESS_ENABLE) */
#define FR_API_ID_LOCK_FTU                        0x34u
#define FR_API_ID_UNLOCK_FTU                      0x35u
#define FR_API_ID_TRANSMIT_TX_LPDU_IMMEDIATE_DBA  0x36u

#if (defined(FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (STD_ON == FR_DIRECT_BUFFER_ACCESS_ENABLE)
#define FR_API_ID_TRANSMIT_TX_LPDU                FR_API_ID_TRANSMIT_TX_LPDU_DBA
#define FR_API_ID_RECEIVE_RX_LPDU                 FR_API_ID_RECEIVE_RX_LPDU_DBA 
#else 
#define FR_API_ID_TRANSMIT_TX_LPDU                0x0Bu
#define FR_API_ID_RECEIVE_RX_LPDU                 0x0Cu
#endif /* (DRVFR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */

/* FR DET errors */

#define FR_E_INV_TIMER_IDX                   0x01
#define FR_E_INV_POINTER                     0x02
#define FR_E_INV_OFFSET                      0x03
#define FR_E_INV_CTRL_IDX                    0x04
#define FR_E_INV_CHNL_IDX                    0x05
#define FR_E_INV_CYCLE                       0x06
#define FR_E_INV_CONFIG                      0x07
#define FR_E_NOT_INITIALIZED                 0x08
#define FR_E_INV_POCSTATE                    0x09
#define FR_E_INV_LENGTH                      0x0A
#define FR_E_INV_LPDU_IDX                    0x0B
#define FR_E_INV_HEADERCRC                   0x0C /* ASR 4.0 */
#define FR_E_INV_LISTSIZE                    0x40


/* Single Controller API optimization */
#if ( FR_CTRL_ENABLE_API_OPTIMIZATION == STD_ON) && ( FR_NUM_CTRL_SUPPORTED == 1u )
  #define FR_VCTRL_ENABLE_API_OPTIMIZATION   STD_ON
  #define FR_VCTRL_SYSTEMTYPE_ONLY     void             /* PRQA S 3460 */ /* MISRA-C:2004 19.4, Part of Single Channel API optimization */
  #define FR_VCTRL_SYSTEMTYPE_FIRST
#else
  #define FR_VCTRL_ENABLE_API_OPTIMIZATION   STD_OFF
  #define FR_VCTRL_SYSTEMTYPE_ONLY     uint8 Fr_CtrlIdx
  #define FR_VCTRL_SYSTEMTYPE_FIRST    uint8 Fr_CtrlIdx,
#endif
  /* FR_CTRL_ENABLE_API_OPTIMIZATION */
#if ( FR_CTRL_ENABLE_API_OPTIMIZATION == STD_ON) && ( FR_MAX_NUM_ABS_TIMER == 1u ) && ( FR_MAX_NUM_REL_TIMER == 1u )
  #define FR_VTIMER_ENABLE_API_OPTIMIZATION  STD_ON
  #define FR_VTIMER_SYSTEMTYPE_ONLY    void           /* PRQA S 3460 */ /* MISRA-C:2004 19.4,  Part of Single Channel API optimization */
  #define FR_VTIMER_SYSTEMTYPE_FIRST
#else
  #define FR_VTIMER_ENABLE_API_OPTIMIZATION  STD_OFF
  #define FR_VTIMER_SYSTEMTYPE_ONLY    uint8 Fr_TimerIdx
  #define FR_VTIMER_SYSTEMTYPE_FIRST   uint8 Fr_TimerIdx,
#endif
  /* FR_CTRL_ENABLE_API_OPTIMIZATION */

#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_ON )
  #define FR_VCTRL_IDX                   0u
#else
  #define FR_VCTRL_IDX                   Fr_CtrlIdx
#endif /* FR_ENABLE_API_OPTIMIZATION */

#define FR_ISR_CAT2                              0x00u
#define FR_ISR_CAT1                              0x01u
#define FR_ISR_VOID                              0x02u

/* communication controller ids, for all functions that need a controller id as input parameter */
#define FR_COM_CONTROLLER_0 (0)


typedef volatile P2VAR(uint32, AUTOMATIC, MSR_REGSPACE) Fr_RegisterPtrType;

  



  /* CC register access */
  #define Fr_VCCWriteValue(Reg, Val)              (*((Fr_RegisterPtrType)((uint32)FR_VCC_REG_START_ADDR+(Reg))) = (Val))      /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */  
  #define Fr_VCCReadValue(Reg)                    (*((Fr_RegisterPtrType)((uint32)FR_VCC_REG_START_ADDR+(Reg))))              /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */   
  #define Fr_VCCSetBits(Reg, Bits)                (*((Fr_RegisterPtrType)((uint32)FR_VCC_REG_START_ADDR+(Reg))) |= (Bits))    /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
  #define Fr_VCCResetBits(Reg, Bits)              (*((Fr_RegisterPtrType)((uint32)FR_VCC_REG_START_ADDR+(Reg))) &= (~(Bits))) /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */

  #define Fr_VFtuWriteValue(Reg, Val)             (*((Fr_RegisterPtrType)(((uint32)FR_FTU_REG_BASE_ADDR+(Reg)))) = (Val)) /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
  #define Fr_VTCRWriteValue(Index,Val)            (*(uint32*)(((uint32*)FR_FTU_TCR_BASE_ADDR)[Index])   = (Val))
  #define Fr_VFtuReadValue(Reg)                   (*((Fr_RegisterPtrType)((uint32)FR_FTU_REG_BASE_ADDR+(Reg)))) /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */

  /* PRQA S 3453 11 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
  #define Fr_VFtuMsgBufRegAddr4(Reg, Idx)         ((Reg)+((((uint32)(Idx))>>3) & 0xFFFFFFFCUL) ) /* 32 buffer/register, 4 addr/register: 4*(Idx/32) == Idx & 0xE0 (i.e. (TTCCS1: Addr A0, (TTCCS2: Addr A4, ...) */  
  #define Fr_VFtuMsgBufRegAddr8(Reg, Idx)         ((Reg)+((((uint32)(Idx))>>2) & 0xFFFFFFF8UL) ) /* 32 buffer/register, 4 addr/register: 4*(Idx/32) == Idx & 0xE0 (i.e. (TTCCS1: Addr A0, (TTCCS2: Addr A8, ...) */  
  #define Fr_VFtuNewDatReg(Idx)                   ( Fr_VFtuMsgBufRegAddr4(FR_FTU_REG_TSMOn,(Idx)))  
  #define Fr_VFtuNewData(Idx)                     ((Fr_VFtuReadValue(Fr_VFtuNewDatReg((Idx)))>>(((uint32)(Idx))&31UL))&1UL)  
  #define Fr_VFtuClearNewData(Idx)                ( Fr_VFtuWriteValue(Fr_VFtuNewDatReg((uint8)(Idx)) ,1UL<<(((uint8)(Idx)) & 31UL) ))  
  #define Fr_VFtuIsSentData(Idx)                  (Fr_VFtuReadValue( Fr_VFtuSendBufRegSet((uint32)(Idx))) & (1UL<<(((uint32)(Idx)) & 31UL) ))  
  #define Fr_VFtuSendBufRegSet(Idx)               (Fr_VFtuMsgBufRegAddr8(FR_FTU_REG_TTCCS,(Idx))) 
  #define Fr_VFtuSendBufRegReset(Idx)             (Fr_VFtuMsgBufRegAddr8(FR_FTU_REG_TTCCR,(Idx))) 
  #define Fr_VFtuSendBufCCSet(Idx)                (Fr_VFtuWriteValue(Fr_VFtuSendBufRegSet((uint32)(Idx)),1UL<<(((uint32)(Idx)) & 31UL) ))  
  #define Fr_VFtuSendBufCCReset(Idx)              (Fr_VFtuWriteValue(Fr_VFtuSendBufRegReset((uint32)(Idx)),1UL<<(((uint32)(Idx)) & 31UL) ))
  #define Fr_VFTUReadBits(Reg, Mask)              ((Fr_VFtuReadValue((Reg)) & (Mask)))  




#define Fr_VCCClearIrqStatusFlag(Flag)             (Fr_VCCWriteValue(CCREG_SIR, (Flag)))    /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7 VIOLATION A function could probably be used instead of this function-like macro. */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


#if ( STD_ON == FR_DIRECT_BUFFER_ACCESS_ENABLE  )
typedef P2VAR(uint8, AUTOMATIC, FR_VAR_FRM_DATA) Fr_LPduPtrType;
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**************************************************************************************************
                                      A  U  T  O  S  A  R
**************************************************************************************************/

#define FR_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */

/***********************************************************************************************************************
 *  Fr_Init
 **********************************************************************************************************************/
/*! \brief      This API call stores the start address of the post build time
 *              configuration of the FlexRay driver, resets all FlexRay CCs 
 *              controlled by the driver and may be used to initialize the
 *              data structures of the FlexRay driver
 *  \param[in]  void *Fr_ConfigPtr
 *  \param[out] -
 *  \return     -
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_Init(P2CONST(Fr_ConfigType, AUTOMATIC, FR_PBCFG) Fr_ConfigPtr);




/***********************************************************************************************************************
 *  Fr_ControllerInit
 **********************************************************************************************************************/
/*! \brief      This API call of a specific FlexRay driver initializes the
 *              FlexRay CC with index Fr_CtrlIdx.
 *              The following actions are performed:
 *              - enter config mode
 *              - configuration of lowlevel parameters
 *              - disabling of all timers
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8 Fr_LowLevelConfSetIdx:
 *  \param[in]  uint8 Fr_BufConfSetIdx:
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       against AUTOSAR spec, disabling of timers is not guaranteed,
 *              as the configuration of the timers is part of the Fr_LowLevelConfSetIdx
 *              in the current solution. Additionally, Fr_LowLevelConfSetIdx contains
 *              initial values for interrupt configuration
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_ControllerInit(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_LowLevelConfSetIdx, uint8 Fr_BufConfSetIdx);

/***********************************************************************************************************************
 *  Fr_SendMTS
 **********************************************************************************************************************/
/*! \brief      causes FR CC Fr_CtrlIdx to send a MTS on channel Fr_ChnlIdx
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8 Fr_ChnlIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if ( FR_MTS_API == STD_ON )
extern FUNC(Std_ReturnType, FR_CODE) Fr_SendMTS(FR_VCTRL_SYSTEMTYPE_FIRST Fr_ChannelType Fr_ChnlIdx);
#endif
  /* FR_MTS_API */

/***********************************************************************************************************************
 *  Fr_StopMTS
 **********************************************************************************************************************/
/*! \brief      causes FR CC Fr_CtrlIdx stop to send a MTS on channel Fr_ChnlIdx
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8 Fr_ChnlIdx:
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if ( FR_MTS_API == STD_ON )
extern FUNC(Std_ReturnType, FR_CODE) Fr_StopMTS(FR_VCTRL_SYSTEMTYPE_FIRST Fr_ChannelType Fr_ChnlIdx);
#endif
  /* FR_MTS_API */

/***********************************************************************************************************************
 *  Fr_CheckMTS
 **********************************************************************************************************************/
/*! \brief      Used to check if a media test symbol has been received
                on channel Fr_ChnlIdx of FrCtrlIdx
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8 Fr_ChnlIdx:
 *  \param[out] Fr_MTSStatusType *Fr_MTSStatusPtr
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if ( FR_MTS_API == STD_ON )
extern FUNC(Std_ReturnType, FR_CODE) Fr_CheckMTS
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  Fr_ChannelType Fr_ChnlIdx,
  P2VAR(Fr_MTSStatusType, AUTOMATIC, FR_APPL_DATA) Fr_MTSStatusPtr
);
#endif
  /* FR_MTS_API */

/***********************************************************************************************************************
 *  Fr_StartCommunication
 **********************************************************************************************************************/
/*! \brief      UInitiates a transition from FR_POCSTATE_READY state into FR_POCSTATE_STARTUP
                state
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The Controller is in Ready state by previous call of Fr_ControllerInit
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_StartCommunication(FR_VCTRL_SYSTEMTYPE_ONLY);

/***********************************************************************************************************************
 *  Fr_AllowColdstart
 **********************************************************************************************************************/
/*! \brief      This method invokes the CC CHI command 'ALLOW_COLDSTART'
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The CC is in any POCState except POC:default config, POC:config or POC:halt
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_AllowColdstart(FR_VCTRL_SYSTEMTYPE_ONLY);

/***********************************************************************************************************************
 *  Fr_HaltCommunication
 **********************************************************************************************************************/
/*! \brief      Halts FlexRay communication
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_HaltCommunication(FR_VCTRL_SYSTEMTYPE_ONLY);

/***********************************************************************************************************************
 *  Fr_AbortCommunication
 **********************************************************************************************************************/
/*! \brief      Aborts FlexRay communication
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if (FR_ABORT_COMMUNICATION_DISABLE == STD_OFF)
extern FUNC(Std_ReturnType, FR_CODE) Fr_AbortCommunication(FR_VCTRL_SYSTEMTYPE_ONLY);
#endif 
      /* (FR_ABORT_COMMUNICATION_DISABLE == STD_OFF) */

/***********************************************************************************************************************
 *  Fr_SendWUP
 **********************************************************************************************************************/
/*! \brief      Restarts FlexRay communication beginning with sending a WUP
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_SendWUP(FR_VCTRL_SYSTEMTYPE_ONLY);

/***********************************************************************************************************************
 *  Fr_SetWakeupChannel
 **********************************************************************************************************************/
/*! \brief      Set the channel for a CC which shall be used for sending a WUP,
 *              this function performs the following actions:
 *              - set POC-state config
 *              - set the Wakeup-channel
 *              - set the CC back to POC-state ready
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  Fr_ChannelType Fr_ChnlIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if (FR_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF)
extern FUNC(Std_ReturnType, FR_CODE) Fr_SetWakeupChannel(FR_VCTRL_SYSTEMTYPE_FIRST Fr_ChannelType Fr_ChnlIdx);
#endif 
      /* (FR_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF) */

/***********************************************************************************************************************
 *  Fr_SetExtSync
 **********************************************************************************************************************/
/*! \brief      this function is used to adjust the global time of a FlexRay CC to
 *              an external clock source by writing a correction value to a FlexRay CC
 *              connected to the cluster
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  Fr_OffsetCorrectionType Fr_Offset
 *  \param[in]  Fr_RateCorrectionType Fr_Rate
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if (FR_SET_EXT_SYNC_DISABLE == STD_OFF)
extern FUNC(Std_ReturnType, FR_CODE) Fr_SetExtSync(FR_VCTRL_SYSTEMTYPE_FIRST Fr_OffsetCorrectionType Fr_Offset,
                                    Fr_RateCorrectionType Fr_Rate);
#endif 
      /* (FR_SET_EXT_SYNC_DISABLE == STD_OFF) */

/***********************************************************************************************************************
 *  Fr_GetSyncState
 **********************************************************************************************************************/
/*! \brief      queries whether or not the CC with index Fr_CtrlIdx
 *              is synchronous to the rest of the cluster
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] Fr_SyncStateType *Fr_SyncStatePtr  Values: FR_ASYNC, FR_SYNC
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetSyncState
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  P2VAR(Fr_SyncStateType, AUTOMATIC, FR_APPL_DATA) Fr_SyncStatePtr
);

/***********************************************************************************************************************
 *  Fr_GetPOCStatus
 **********************************************************************************************************************/
/*! \brief      Return current status of the protocol operation control
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] Fr_POCStatusType *Fr_POCStatusPtr
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetPOCStatus
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) Fr_POCStatusPtr
);

#if (defined (FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
/***********************************************************************************************************************
 *  Fr_TransmitTxLPdu_DBA
 **********************************************************************************************************************/
/*! \brief      Triggers hardware to transmit Buffer
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint16 Fr_LPduIdx
 *  \param[in]  uint8 Fr_LPduLength in bytes
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
                Fr_RequestBuffer_DBA was executed and Buffer is locked
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu_DBA
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  uint16 Fr_LPduIdx,
  uint8 Fr_LPduLength 
);
#else
/***********************************************************************************************************************
 *  Fr_TransmitTxLPdu
 **********************************************************************************************************************/
/*! \brief      Copies data from software ram to hardware buffer  
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint16 Fr_LPduIdx
 *  \param[in]  const uint8 *Fr_LPduPtr
 *  \param[in]  uint8 Fr_LPduLength in bytes
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  uint16 Fr_LPduIdx,
  P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) Fr_LPduPtr, 
  uint8 Fr_LPduLength 
);
#endif /* defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */

# if defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
/***********************************************************************************************************************
 *  Fr_TransmitTxLPdu_ImmediateDBA
 **********************************************************************************************************************/
/*! \brief      Copies data from software ram to hardware buffer
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint16 Fr_LPduIdx
 *  \param[in]  const uint8 *Fr_LPduPtr
 *  \param[in]  uint8 Fr_LPduLength in bytes
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu_ImmediateDBA 
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  uint16 Fr_LPduIdx,
  P2CONST(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduPtr, 
  uint8 Fr_LPduLength
);

/***********************************************************************************************************************
 *  Fr_RequestBuffer_DBA
 **********************************************************************************************************************/
/*! \brief      This function should be called before Fr_TransmitTxLPdu
 *              Locks Buffer, wait until buffer is locked and gives backpointer to buffer
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint16 Fr_LPduIdx
 *  \param[in]  uint8 Fr_LPduLength in bytes
 *  \param[out] const uint8 **Fr_LPduPtr
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_RequestBuffer_DBA
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  uint16 Fr_LPduIdx,
  P2VAR(Fr_LPduPtrType, AUTOMATIC, FR_APPL_DATA) Fr_LPduPtr, 
  uint8 Fr_LPduLength
);
# endif /* defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */



#if (defined (FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
/***********************************************************************************************************************
 *  Fr_ReceiveRxLPdu_DBA
 **********************************************************************************************************************/
/*! \brief      Gives back the adress of the received hardware buffer and locks the buffer
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint16 Fr_LPduIdx
 *  \param[out] uint8 **Fr_LPduPtr
 *  \param[out] Fr_RxLPduStatusType *Fr_LPduStatusPtr,
 *  \param[int/out] uint8 *Fr_LPduLengthPtr (in bytes)
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       against the AUTOSAR spec, this functions expects Fr_LPduLengthPtr to
 *              contain the frame length. Only the number of bytes given by Fr_LPduLengthPtr
 *              is copied, Fr_LPduLengthPtr gives back the amount of copied bytes 
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReceiveRxLPdu_DBA
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  uint16 Fr_LPduIdx,  
  P2VAR(Fr_LPduPtrType, AUTOMATIC, FR_APPL_DATA) Fr_LPduPtr,
  P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_LPduStatusPtr,
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduLengthPtr
);
#else
/***********************************************************************************************************************
 *  Fr_ReceiveRxLPdu
 **********************************************************************************************************************/
/*! \brief      Copies data from hardware buffer to software ram
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint16 Fr_LPduIdx
 *  \param[in]  uint8 *Fr_LPduPtr
 *  \param[out] Fr_RxLPduStatusType *Fr_LPduStatusPtr, (in bytes)
 *  \param[int/out] uint8 *Fr_LPduLengthPtr
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       against the AUTOSAR spec, this functions expects Fr_LPduLengthPtr to
 *              contain the frame length. Only the number of bytes given by Fr_LPduLengthPtr
 *              is copied, Fr_LPduLengthPtr gives back the amount of copied bytes 
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReceiveRxLPdu
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  uint16 Fr_LPduIdx, 
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduPtr, 
  P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_LPduStatusPtr,
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduLengthPtr 
);
#endif /* defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */

#if (defined (FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
/***********************************************************************************************************************
 *  Fr_UnlockRxLPdu_DBA
 **********************************************************************************************************************/
/*! \brief      Unlocks the requested buffer
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint16 Fr_LPduIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_UnlockRxLPdu_DBA
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  uint16 Fr_LPduIdx 
);
# endif /* defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */


/***********************************************************************************************************************
 *  Fr_CheckTxLPduStatus
 **********************************************************************************************************************/
/*! \brief      checks whether or not the transmission of the LPdu 
 *              referenced by FrCtrlIdx and Fr_LPduIdx has been performed
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint16 Fr_LPduIdx
 *  \param[out] Fr_TxLPduStatusType *Fr_TxLPduStatusPtr
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_CheckTxLPduStatus
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  uint16 Fr_LPduIdx, 
  P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_TxLPduStatusPtr
);

#if ( FR_PREPARE_LPDU_API == STD_ON )
/***********************************************************************************************************************
 *  Fr_PrepareLPdu
 **********************************************************************************************************************/
/*! \brief      Modifiy the configuration of a message buffer
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint16 Fr_LPduIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \pre        -
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Functionality removed. 
 **********************************************************************************************************************/
# define Fr_PrepareLPdu(Fr_CtrlIdx, Fr_LPduIdx)    ((Std_ReturnType) E_OK)
#endif
  
/***********************************************************************************************************************
 *  Fr_GetGlobalTime
 **********************************************************************************************************************/
/*! \brief      retrieves the global time of a specific FlexRay CC
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] uint8 *Fr_CyclePtr
 *  \param[out] uint16 *Fr_MacroTickPtr
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetGlobalTime
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  P2VAR(uint8,  AUTOMATIC, FR_APPL_DATA) Fr_CyclePtr,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_MacroTickPtr
);

/***********************************************************************************************************************
 *  Fr_GetNmVector
 **********************************************************************************************************************/
/*! \brief      Gets the network management vector of the last communication cycle
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] uint8* Fr_NmVectorPtr 
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
                The physical layer is in sync with the network
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if ( FR_NMVECTOR_ENABLE == STD_ON )
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetNmVector
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NmVectorPtr
);
#endif 
  /* FR_NMVECTOR_ENABLE */

/***********************************************************************************************************************
 *  Fr_SetAbsoluteTimer
 **********************************************************************************************************************/
/*! \brief      programs an absolute timer (interrupt) for timer Fr_AbsTimerIdx
 *              according to the information passed 
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8 Fr_AbsTimerIdx
 *  \param[in]  uint8 Fr_Cycle
 *  \param[in]  uint16 Fr_Offset
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       This method does not turn "on" or "off" the affected timer IRQ!!!
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_SetAbsoluteTimer(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_AbsTimerIdx, uint8 Fr_Cycle, uint16 Fr_Offset);

/***********************************************************************************************************************
 *  Fr_CancelAbsoluteTimer
 **********************************************************************************************************************/
/*! \brief      stops the absolute timer handling and disables the interrupt
 *              for the absolute timer Fr_AbsTimerIdx 
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8 Fr_AbsTimerIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_CancelAbsoluteTimer(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_AbsTimerIdx);

/***********************************************************************************************************************
 *  Fr_EnableAbsoluteTimerIRQ
 **********************************************************************************************************************/
/*! \brief      enables a timer (interrupt) for absolute timer Fr_TimerIdx
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8 Fr_AbsTimerIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_EnableAbsoluteTimerIRQ(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_AbsTimerIdx);

/***********************************************************************************************************************
 *  Fr_AckAbsoluteTimerIRQ
 **********************************************************************************************************************/
/*! \brief      acknowledges the timer (interrupt) of absolute timer Fr_TimerIdx
 *              and resets the interrupt condition.
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8 Fr_AbsTimerIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF)
extern FUNC(Std_ReturnType, FR_CODE) Fr_AckAbsoluteTimerIRQ(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_AbsTimerIdx);
#endif 
      /* (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF) */

/***********************************************************************************************************************
 *  Fr_DisableAbsoluteTimerIRQ
 **********************************************************************************************************************/
/*! \brief      disables a timer (interrupt) for absolute timer Fr_TimerIdx
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8 Fr_AbsTimerIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF)
extern FUNC(Std_ReturnType, FR_CODE) Fr_DisableAbsoluteTimerIRQ(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_AbsTimerIdx);
#endif 
      /* (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF) */

/***********************************************************************************************************************
 *  Fr_GetAbsoluteTimerIRQStatus
 **********************************************************************************************************************/
/*! \brief      Gets IRQ status of the absolute timer
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8 Fr_AbsTimerIdx
 *  \param[out] boolean * Fr_IRQStatusPtr
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF)
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetAbsoluteTimerIRQStatus
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  uint8 Fr_AbsTimerIdx, 
  P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) Fr_IRQStatusPtr
);
#endif 
      /* (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF) */

/***********************************************************************************************************************
 *  Fr_SetRelativeTimer
 **********************************************************************************************************************/
/*! \brief      programs a relative timer (interrupt) for timer 
 *              Fr_RelTimerIdx according to the information passed
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8  Fr_RelTimerIdx
 *  \param[in]  uint16 Fr_Offset
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if ( FR_RELATIVE_TIMER_ENABLE == STD_ON )
extern FUNC(Std_ReturnType, FR_CODE) Fr_SetRelativeTimer(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_RelTimerIdx, uint16 Fr_Offset);
#endif
  /* FR_RELATIVE_TIMER_ENABLE */

/***********************************************************************************************************************
 *  Fr_CancelRelativeTimer
 **********************************************************************************************************************/
/*! \brief      stops the relative timer handling and disables the interrupt
 *              for the realtive timer Fr_RelTimerIdx
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8  Fr_RelTimerIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if ( FR_RELATIVE_TIMER_ENABLE == STD_ON )
extern FUNC(Std_ReturnType, FR_CODE) Fr_CancelRelativeTimer(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_RelTimerIdx);
#endif
  /* FR_RELATIVE_TIMER_ENABLE */

/***********************************************************************************************************************
 *  Fr_EnableRelativeTimerIRQ
 **********************************************************************************************************************/
/*! \brief      enables a timer (interrupt) for realtive timer Fr_TimerIdx
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8  Fr_RelTimerIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if ( FR_RELATIVE_TIMER_ENABLE == STD_ON )
extern FUNC(Std_ReturnType, FR_CODE) Fr_EnableRelativeTimerIRQ(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_RelTimerIdx);
#endif
  /* FR_RELATIVE_TIMER_ENABLE */

/***********************************************************************************************************************
 *  Fr_AckRelativeTimerIRQ
 **********************************************************************************************************************/
/*! \brief      acknowledges the timer (interrupt) of relative timer Fr_TimerIdx
 *              and resets the interrupt condition
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8  Fr_RelTimerIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if ( FR_RELATIVE_TIMER_ENABLE == STD_ON )
extern FUNC(Std_ReturnType, FR_CODE) Fr_AckRelativeTimerIRQ(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_RelTimerIdx);
#endif
  /* FR_RELATIVE_TIMER_ENABLE */

/***********************************************************************************************************************
 *  Fr_DisableRelativeTimerIRQ
 **********************************************************************************************************************/
/*! \brief      disables a timer (interrupt) for relative timer Fr_TimerIdx
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8  Fr_RelTimerIdx
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if ( FR_RELATIVE_TIMER_ENABLE == STD_ON )
extern FUNC(Std_ReturnType, FR_CODE) Fr_DisableRelativeTimerIRQ(FR_VCTRL_SYSTEMTYPE_FIRST uint8 Fr_RelTimerIdx);
#endif
  /* FR_RELATIVE_TIMER_ENABLE */

/***********************************************************************************************************************
 *  Fr_GetRelativeTimerIRQStatus
 **********************************************************************************************************************/
/*! \brief      Gets IRQ status of the absolute timer
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[in]  uint8  Fr_RelTimerIdx
 *  \param[out] boolean * Fr_IRQStatusPtr
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_InitMemory was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetRelativeTimerIRQStatus
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  uint8 Fr_RelTimerIdx, 
  P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) Fr_IRQStatusPtr
);

/***********************************************************************************************************************
 *  Fr_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief      Get Driver Version
 *  \param[in]  
 *  \param[out] Std_VersionInfoType *Versioninfo 
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Only available if (FR_VERSION_INFO_API == STD_ON) && (FR_VERSION_INFO_API_MACRO == STD_OFF)
 **********************************************************************************************************************/
#if ( FR_VERSION_INFO_API == STD_ON )
#if ( FR_VERSION_INFO_API_MACRO == STD_ON )
#if (FR_DEV_ERROR_DETECT == STD_ON)     
#define Fr_GetVersionInfo(VersionInfo) { if ( NULL_PTR == (VersionInfo) ) \
                                         { \
                                           Det_ReportError(0, 0, FR_API_ID_GET_VERSION_INFO, FR_E_INV_POINTER); \
                                           return; \
                                         } \
                                         (VersionInfo)->vendorID = FR_VENDOR_ID; \
                                         (VersionInfo)->moduleID = FR_MODULE_ID; \
                                         (VersionInfo)->instanceID = 0; \
                                         (VersionInfo)->sw_major_version = (uint8)FR_SW_MAJOR_VERSION; \
                                         (VersionInfo)->sw_minor_version = (uint8)FR_SW_MINOR_VERSION; \
                                         (VersionInfo)->sw_patch_version = (uint8)FR_SW_PATCH_VERSION; }  /* PRQA S 3458 */ /* MISRA-C:2004 19.4, Configurable function as macro */
#else
#define Fr_GetVersionInfo(VersionInfo) { (VersionInfo)->vendorID = FR_VENDOR_ID; \
                                         (VersionInfo)->moduleID = FR_MODULE_ID; \
                                         (VersionInfo)->instanceID = 0; \
                                         (VersionInfo)->sw_major_version = (uint8)FR_SW_MAJOR_VERSION; \
                                         (VersionInfo)->sw_minor_version = (uint8)FR_SW_MINOR_VERSION; \
                                         (VersionInfo)->sw_patch_version = (uint8)FR_SW_PATCH_VERSION; }  /* PRQA S 3458 */ /* MISRA-C:2004 19.4, Configurable function as macro */
#endif
  /* (FR_DEV_ERROR_DETECT == STD_ON) */
#else
extern FUNC(void, FR_CODE) Fr_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FR_APPL_DATA) VersionInfo);
#endif
  /* FR_VERSION_INFO_API_MACRO */
#endif
  /* FR_VERSION_INFO_API */




/**************************************************************************************************
                                      E X T E N S I O N
**************************************************************************************************/

# if (defined(FR_VEXTENDED_CC_STATUS)) && (FR_VEXTENDED_CC_STATUS == STD_ON)
/***********************************************************************************************************************
 *  Fr_VErrorMode
 **********************************************************************************************************************/
/*! \brief      Gets channel status information.
 *  \param[in]  
 *  \param[out] Fr_VErrorStatusType *Fr_VErrorStatusPtr
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_VCheckErrorState
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_VErrorMode(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);

/***********************************************************************************************************************
 *  Fr_VClockCorrectionError
 **********************************************************************************************************************/
/*! \brief      Gets channel status information.
 *  \param[in]  
 *  \param[out] Fr_VErrorStatusType *Fr_VErrorStatusPtr
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_VCheckErrorState
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_VClockCorrectionError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);

/***********************************************************************************************************************
 *  Fr_VSyncFrameError
 **********************************************************************************************************************/
/*! \brief      Gets channel status information.
 *  \param[in]  
 *  \param[out] Fr_VErrorStatusType *Fr_VErrorStatusPtr
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_VCheckErrorState
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_VSyncFrameError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);

/***********************************************************************************************************************
 *  Fr_VChannelError
 **********************************************************************************************************************/
/*! \brief      Gets channel status information.
 *  \param[in]  
 *  \param[out] Fr_VErrorStatusType *Fr_VErrorStatusPtr
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_VCheckErrorState
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_VChannelError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);

/***********************************************************************************************************************
 *  Fr_VSyntaxError
 **********************************************************************************************************************/
/*! \brief      Gets channel status information.
 *  \param[in]  
 *  \param[out] Fr_VErrorStatusType *Fr_VErrorStatusPtr
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_VCheckErrorState
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_VSyntaxError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);

/***********************************************************************************************************************
 *  Fr_VLatestTxError
 **********************************************************************************************************************/
/*! \brief      Gets channel status information.
 *  \param[in]  
 *  \param[out] Fr_VErrorStatusType *Fr_VErrorStatusPtr
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_VCheckErrorState
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_VLatestTxError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);

/***********************************************************************************************************************
 *  Fr_VSwError
 **********************************************************************************************************************/
/*! \brief      Gets channel status information.
 *  \param[in]  
 *  \param[out] Fr_VErrorStatusType *Fr_VErrorStatusPtr
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_VCheckErrorState
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_VSwError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);

/***********************************************************************************************************************
 *  Fr_VNitError
 **********************************************************************************************************************/
/*! \brief      Gets channel status information.
 *  \param[in]  
 *  \param[out] Fr_VErrorStatusType *Fr_VErrorStatusPtr
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_VCheckErrorState
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_VNitError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);

/***********************************************************************************************************************
 *  Fr_VColdStartError
 **********************************************************************************************************************/
/*! \brief      Gets channel status information.
 *  \param[in]  
 *  \param[out] Fr_VErrorStatusType *Fr_VErrorStatusPtr
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_VCheckErrorState
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_VColdStartError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);

/***********************************************************************************************************************
 *  Fr_VCheckErrorState
 **********************************************************************************************************************/
/*! \brief      Gets channel status information.
 *  \param[in]  
 *  \param[out] Fr_VErrorStatusType *Fr_VErrorStatusPtr
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_VCheckErrorState
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_VCheckErrorState(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);


# endif  /* FR_EXTENDED_CC_STATUS == STD_ON */




# if (defined(FR_VCHANNEL_STATUS_EXT)) && ( FR_VCHANNEL_STATUS_EXT == STD_ON )
/***********************************************************************************************************************
 *  Fr_GetChannelStatus
 **********************************************************************************************************************/
/*! \brief      Gets the aggregated channel status information.
 *  \param[in]  Fr_CtrlIdx  Index of FlexRay CC within the context of the FlexRay Driver.
 *  \param[out] Fr_ChannelAStatusPtr Address where the bitcoded aggregated channel status information shall be stored.
 *  \param[out] Fr_ChannelBStatusPtr Address where the bitcoded aggregated channel status information shall be stored.
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note      
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetChannelStatus
(
  FR_VCTRL_SYSTEMTYPE_FIRST 
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAStatusPtr,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBStatusPtr
);
# endif


#if (defined (FR_GET_CLOCK_CORRECTION_EXT)) && ( FR_GET_CLOCK_CORRECTION_EXT == STD_ON )
/***********************************************************************************************************************
 *  Fr_GetClockCorrection
 **********************************************************************************************************************/
/*! \brief      Gets the current clock correction values.
 *  \param[in]  Fr_CtrlIdx   Index of FlexRay CC within the context of the FlexRay Driver.
 *  \param[out] Fr_RateCorrectionPtr   Address where the current rate correction value hall be stored.
 *  \param[out] Fr_OffsetCorrectionPtr Address where the current of shall be stored.
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note      
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetClockCorrection(
  FR_VCTRL_SYSTEMTYPE_FIRST
  P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) Fr_RateCorrectionPtr,
  P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) Fr_OffsetCorrectionPtr );
#endif




/***********************************************************************************************************************
 *  Fr_InitMemory
 **********************************************************************************************************************/
/*! \brief      Initializes global variables at startup
 *  \param[in]  -
 *  \param[out] -
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
  
#if ( FR_DEV_ERROR_DETECT == STD_ON)
extern FUNC(void, FR_CODE) Fr_InitMemory(void);
#else
#define Fr_InitMemory()
#endif


# if (FR_CFG_APPL_CALLBACK_CYCLE_START == STD_ON)
/***********************************************************************************************************************
 *  Fr_ISR_Status
 **********************************************************************************************************************/
/*! \brief      Interrupt Handler Routine.
 *              The following interrupts are handled:
 *              - RX-Irq: get BufferIdx and map it to FrIf buffer and call FrIfRx function
 *              - TX-Irq: get BufferIdx and map it to FrIf buffer and call FrIfTx function
 *              - CycleStart-Irq: call FrIfc CycleStart function
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] -
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Called by Fr_IrqLine0 in fr_irq.c
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_ISR_Status(FR_VCTRL_SYSTEMTYPE_ONLY);
# endif


#if ( FR_RELATIVE_TIMER_ENABLE == STD_ON )
/***********************************************************************************************************************
 *  Fr_ISR_Timer1
 **********************************************************************************************************************/
/*! \brief      Interrupt Handler Routine.
 *              The following interrupts are handled:
 *              - Timer1-Irq: Relative Timer
 *  \param[in]  uint8 FR_VCTRL_SYSTEMTYPE_ONLY: Controller index
 *  \param[out] -
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Called by Fr_IrqTimer1 in fr_irq.c
 **********************************************************************************************************************/
extern FUNC(void, FR_CODE) Fr_ISR_Timer1(FR_VCTRL_SYSTEMTYPE_ONLY);
#endif


#define FR_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */
 
/**************************************************************************************************
*                ISR EXTENSION
**************************************************************************************************/
 
# define FR_START_SEC_CODE_ISR
# include "MemMap.h"



#  if ( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )
#   if(FR_CFG_STATUS_ISR_LINE == 0) 
extern FUNC(void, FR_CODE_ISR) Fr_IrqLine0(void);
#   else
extern FUNC(void, FR_CODE_ISR) Fr_IrqLine1(void);
#   endif /*FR_CFG_STATUS_ISR_LINE == 0*/
#  endif /*( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )*/

#  if ( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )
extern FUNC(void, FR_CODE_ISR) Fr_IrqTimer0(void);
#  endif /*( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )*/
#  if ( FR_RELATIVE_TIMER_ENABLE == STD_ON )
#   if ( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )
extern FUNC(void, FR_CODE_ISR) Fr_IrqTimer1(void);
#   endif /*( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )*/
#  endif /*FR_RELATIVE_TIMER_ENABLE == STD_ON*/



# define FR_STOP_SEC_CODE_ISR
# include "MemMap.h"



/**************************************************************************************************
* MACROS
**************************************************************************************************/
/* Single Controller API optimization */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_ON )
/* PRQA S 3453 MISRA_SINGLE_API */ /* MISRA rule 19.7 Part of Single Channel API optimization */
#define Fr_ControllerInit(Fr_CtrlIdx, Fr_LowLevelConfSetIdx, Fr_BufConfSetIdx) \
        Fr_ControllerInit(Fr_LowLevelConfSetIdx, Fr_BufConfSetIdx)                        /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_SendMTS(Fr_CtrlIdx, Fr_ChnlIdx)                       Fr_SendMTS(Fr_ChnlIdx)   /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_CheckMTS(Fr_CtrlIdx, Fr_ChnlIdx, Fr_MTSStatusPtr)     Fr_CheckMTS(Fr_ChnlIdx, Fr_MTSStatusPtr) /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_StopMTS(Fr_CtrlIdx, Fr_ChnlIdx)                       Fr_StopMTS(Fr_ChnlIdx)   /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */          
#define Fr_StartCommunication(Fr_CtrlIdx)                        Fr_StartCommunication()  /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_AllowColdstart(Fr_CtrlIdx)                            Fr_AllowColdstart()      /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_HaltCommunication(Fr_CtrlIdx)                         Fr_HaltCommunication()   /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */

# if (FR_ABORT_COMMUNICATION_DISABLE == STD_OFF)
#define Fr_AbortCommunication(Fr_CtrlIdx)                        Fr_AbortCommunication()  /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
# endif 

#define Fr_SendWUP(Fr_CtrlIdx)                                   Fr_SendWUP()             /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */

# if (FR_SET_WAKEUP_CHANNEL_DISABLE == STD_OFF)
#define Fr_SetWakeupChannel(Fr_CtrlIdx, Fr_ChnlIdx)              Fr_SetWakeupChannel(Fr_ChnlIdx)    /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
# endif 

# if (FR_SET_EXT_SYNC_DISABLE == STD_OFF)
#define Fr_SetExtSync(Fr_CtrlIdx, Fr_Offset, Fr_Rate)            Fr_SetExtSync(Fr_Offset, Fr_Rate)  /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
# endif 

#define Fr_GetSyncState(Fr_CtrlIdx, Fr_SyncStatePtr)             Fr_GetSyncState(Fr_SyncStatePtr)   /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_GetPOCStatus(Fr_CtrlIdx, Fr_POCStatusPtr)             Fr_GetPOCStatus(Fr_POCStatusPtr)   /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_TransmitTxLPdu(Fr_CtrlIdx, Fr_LPduIdx, Fr_LPduPtr, Fr_LPduLength) \
        Fr_TransmitTxLPdu(Fr_LPduIdx, Fr_LPduPtr, Fr_LPduLength)                                    /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_ReceiveRxLPdu(Fr_CtrlIdx, Fr_LPduIdx, Fr_LPduPtr, Fr_LPduStatusPtr, Fr_LPduLengthPtr) \
        Fr_ReceiveRxLPdu(Fr_LPduIdx, Fr_LPduPtr, Fr_LPduStatusPtr, Fr_LPduLengthPtr)                /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_CheckTxLPduStatus(Fr_CtrlIdx, Fr_LPduIdx, Fr_LPduStatusPtr) \
        Fr_CheckTxLPduStatus(Fr_LPduIdx, Fr_LPduStatusPtr)                                          /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_GetSyncFrameList( Fr_CtrlIdx, Fr_ListSize, Fr_ChannelAEvenListPtr, Fr_ChannelBEvenListPtr, Fr_ChannelAOddListPtr, Fr_ChannelBOddListPtr) \
        Fr_GetSyncFrameList( Fr_ListSize, Fr_ChannelAEvenListPtr, Fr_ChannelBEvenListPtr, Fr_ChannelAOddListPtr, Fr_ChannelBOddListPtr) /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */

#define Fr_GetGlobalTime(Fr_CtrlIdx, Fr_CyclePtr, Fr_MacroTickPtr) Fr_GetGlobalTime(Fr_CyclePtr, Fr_MacroTickPtr) /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_ISR(Fr_CtrlIdx)                                   Fr_ISR()                               /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */


# if defined(FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
#define Fr_TransmitTxLPdu_DBA(Fr_CtrlIdx, Fr_LPduIdx, Fr_LPduLength) Fr_TransmitTxLPdu_DBA(Fr_LPduIdx, Fr_LPduLength)   /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_TransmitTxLPdu_ImmediateDBA(Fr_CtrlIdx, Fr_LPduIdx, Fr_LPduPtr, Fr_LPduLength) \
        Fr_TransmitTxLPdu_ImmediateDBA(Fr_LPduIdx, Fr_LPduPtr, Fr_LPduLength)                       /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_RequestBuffer_DBA(Fr_CtrlIdx, Fr_LPduIdx, Fr_LPduPtr, Fr_LPduLength) \
        Fr_RequestBuffer_DBA(Fr_LPduIdx, Fr_LPduPtr, Fr_LPduLength)                                 /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_ReceiveRxLPdu_DBA(Fr_CtrlIdx, Fr_LPduIdx, Fr_LPduPtr, Fr_LPduStatusPtr, Fr_LPduLengthPtr) \
        Fr_ReceiveRxLPdu_DBA(Fr_LPduIdx, Fr_LPduPtr, Fr_LPduStatusPtr, Fr_LPduLengthPtr)            /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_UnlockRxLPdu_DBA(Fr_CtrlIdx, Fr_LPduIdx)  Fr_UnlockRxLPdu_DBA(Fr_LPduIdx)                /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
# endif  /* defined(FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */

# if ( FR_NMVECTOR_ENABLE == STD_ON )
#define Fr_GetNmVector(Fr_CtrlIdx, Fr_NmVectorPtr) Fr_GetNmVector(Fr_NmVectorPtr)                   /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
# endif 

#define Fr_ISR_Status(Fr_CtrlIdx) Fr_ISR_Status() /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_ISR_Timer1(Fr_CtrlIdx) Fr_ISR_Timer1() /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */

#  if ( FR_VCHANNEL_STATUS_EXT == STD_ON )
#define Fr_GetChannelStatus(Fr_CtrlIdx, Fr_ChannelAStatusPtr, Fr_ChannelBStatusPtr)  \
        Fr_GetChannelStatus(Fr_ChannelAStatusPtr, Fr_ChannelBStatusPtr)                             /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_GetClockCorrection(Fr_CtrlIdx, Fr_RateCorrectionPtr, Fr_OffsetCorrectionPtr)  \
        Fr_GetClockCorrection(Fr_RateCorrectionPtr, Fr_OffsetCorrectionPtr)                         /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#  endif
  /* FR_VCHANNEL_STATUS_EXT */
# if defined (FR_PREPARE_LPDU_API) && (FR_PREPARE_LPDU_API == STD_ON)
#define Fr_PrepareLPdu(Fr_CtrlIdx, Fr_LPduIdx)  Fr_PrepareLPdu(Fr_LPduIdx)                          /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
# endif
#endif
  /* FR_VCTRL_ENABLE_API_OPTIMIZATION */
  
#if ( FR_VTIMER_ENABLE_API_OPTIMIZATION == STD_ON )
#define Fr_SetAbsoluteTimer(Fr_CtrlIdx, Fr_TimerIdx, Fr_Cycle, Fr_Offset) Fr_SetAbsoluteTimer(Fr_TimerIdx, Fr_Cycle, Fr_Offset) /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_CancelAbsoluteTimer(Fr_CtrlIdx, Fr_TimerIdx)                      Fr_CancelAbsoluteTimer(Fr_TimerIdx)                /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_EnableAbsoluteTimerIRQ(Fr_CtrlIdx, Fr_TimerIdx)                   Fr_EnableAbsoluteTimerIRQ(Fr_TimerIdx)             /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#if (FR_ABSOLUTE_TIMER_DISABLE == STD_OFF)
#define Fr_AckAbsoluteTimerIRQ(Fr_CtrlIdx, Fr_TimerIdx)                      Fr_AckAbsoluteTimerIRQ(Fr_TimerIdx)                /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_DisableAbsoluteTimerIRQ(Fr_CtrlIdx, Fr_TimerIdx)                  Fr_DisableAbsoluteTimerIRQ(Fr_TimerIdx)            /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_GetAbsoluteTimerIRQStatus(Fr_CtrlIdx, Fr_AbsTimerIdx, Fr_IRQStatusPtr) Fr_GetAbsoluteTimerIRQStatus(Fr_AbsTimerIdx, Fr_IRQStatusPtr)   /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#endif 
  
# if FR_RELATIVE_TIMER_ENABLE == STD_ON
#define Fr_SetRelativeTimer(Fr_CtrlIdx, Fr_TimerIdx, MacrotickOffset)        Fr_SetRelativeTimer(Fr_TimerIdx, MacrotickOffset)  /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_CancelRelativeTimer(Fr_CtrlIdx, Fr_TimerIdx)                      Fr_CancelRelativeTimer(Fr_TimerIdx)                /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_EnableRelativeTimerIRQ(Fr_CtrlIdx, Fr_TimerIdx)                   Fr_EnableRelativeTimerIRQ(Fr_TimerIdx)             /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_AckRelativeTimerIRQ(Fr_CtrlIdx, Fr_TimerIdx)                      Fr_AckRelativeTimerIRQ(Fr_TimerIdx)                /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_GetRelativeTimerIRQStatus(Fr_CtrlIdx, Fr_RelTimerIdx, Fr_IRQStatusPtr) Fr_GetRelativeTimerIRQStatus(Fr_RelTimerIdx, Fr_IRQStatusPtr) /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
#define Fr_DisableRelativeTimerIRQ(Fr_CtrlIdx, Fr_TimerIdx)                  Fr_DisableRelativeTimerIRQ(Fr_TimerIdx)            /* PRQA S 3436 */ /* MISRA-C:2004 , Part of Single Channel API optimization */
# endif
/* PRQA L:MISRA_SINGLE_API */ /* MISRA rule 19.7 Part of Single Channel API optimization */
#endif
  /* FR_VTIMER_ENABLE_API_OPTIMIZATION */


/***** end of header file ************************************************************************/
#endif
  /* FR_H */
/* STOPSINGLE_OF_MULTIPLE */
