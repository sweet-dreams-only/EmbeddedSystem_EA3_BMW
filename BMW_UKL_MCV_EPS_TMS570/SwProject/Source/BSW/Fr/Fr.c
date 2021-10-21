/*  *****   STARTSINGLE_OF_MULTIPLE_COMMENT    *****  */


/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Fr.c
 *      Project:  FlexRay Stack
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  FlexRay Driver
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
 *  03.00.05  2008-02-21  Jsr                   rename of copy functions
 *  03.00.06  2008-02-22  Jsr                   rename of GENY generated defines
 *  03.00.07  2008-02-19  Jsr     ESCAN00024975
 *                                ESCAN00024950
 *                                ESCAN00024946
 *                                ESCAN00023416
 *                                ESCAN00024997 Rename of variable in Fr_GetNmVector
 *  03.00.08  2008-03-04  Jsr                   Delete needless allocation of Fr_ControllerInit
 *  03.00.09  2008-03-27  Alr     ESCAN00025564 missing DFI support
 *  03.00.10  2008-04-03  Jsr                   New version
 *  03.00.11  2008-04-10  Jsr                   TMS470 added
 *  03.01.00  2008-04-14  Jsr                   Rename internal variables from VFRDRV_ to FR_V and vFrDrv_ to Fr_V
 *                                              Updates because of changed Fr_VTxVirtBuf2PhysBufMap 
 *                                              Updated memmap and compiler abstraction definitions
 *  03.01.01  2008-04-14  Jsr                   Rename internal variables from VFRDRV_ to FR_V and vFrDrv_ to Fr_V
 *                                ESCAN00026643 (Lib check)
 *  03.01.02  2008-06-04  Seg                   dependend defines for FR_DEM_E_ACCESS                                
 *  03.02.00  2008-06-14  Seg     ESCAN00027381 added extended cc status (flexray diagnosis)
 *  03.02.01  2008-06-24  Jsr     ESCAN00027823
 *  03.03.00  2008-07-29  Jsr     ESCAN00028231 Fr_ReceiveRxLPdu does not return the payload length of a received frame.
 *                                ESCAN00025647
 *                                ESCAN00026728
 *                                ESCAN00027389
 *  03.03.01  2008-08-15  Jsr     ESCAN00029232 LibCheck update
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
 *                                ESCAN00030042 DrvFr_V85xErayVx Fr_TransmitTxLPdu configuration check
 *                                ESCAN00030798 Warnings in Fr.c if Visual Studio 8 used
 *                                ESCAN00030416 Add MBF to CANoeemu driver
 *                                ESCAN00030821 Channel name of the simulation of the remaining bus
 *  03.05.01  2008-10-27  Ssr     ESCAN00030895 Return value of Fr_CheckTxLPduStatus
 *                                ESCAN00030896 Contend of Fr_PrepareLPdu within CANoe Driver
 *                                ESCAN00031028 Correct MTS API for CANoe Driver
 *  03.06.00  2008-11-07  Ssr     ESCAN00031133 Optimize CRC calculation
 *                                ESCAN00031238 FlexRay Driver reports DET error when Fr_PrepareLPdu is called
 *                                ESCAN00031358 Remove swap Message Id filtering CANoe driver 
 *                                ESCAN00030962 Add Fr_GetClockCorrection and Fr_GetChannelStatus instead current Fr_GetChannelStatus
 *                                ESCAN00030456 Declaration of the postbuild arrays
 *                                ESCAN00030903 Postbuild message buffer Id filtering
 *                                ESCAN00029693 AUTOSAR Dummy Statements
 *                        Seg     ESCAN00030266 PreCompile and Linktime Crc Check
 *                        Jsr     ESCAN00031643 Mb88121 added and updated
 *                        Seg     ESCAN00031903 insufficient interrupt lock
 *                                ESCAN00030543 FlexRay Driver does not always report an production error in case of CC access errors
 *                                ESCAN00031999 TMS C-Copy-Function updated
 *  03.06.01  2009-01-14  Ssr     ESCAN00032377 Frames with dynamic payload length can be truncated
 *  03.07.00  2009-01-26  Jsr     ESCAN00031239 Status of sync frames changed from cyclic to event triggered
 *                                ESCAN00032528 No FrIf_JobListExec_0 with "Application callback at timer 0 interrupt" is switched off
 *                                ESCAN00032341 Unneccessary call of FrIf_JobListExec_0 at specific configuration
 *                                ESCAN00032152 CANoeEmu Driver does not transmit some frames in dyn segment if Buffer Reconf is enabled
 *                        Ssr     ESCAN00032825 Add tricore specific parameters
 *                                ESCAN00032943 Unnecessarary Dem event FR_E_ACCESS report
 *  03.07.01  2009-02-23  Ssr     ESCAN00033310 Clean unnecessary comments
 *  03.08.00  2009-04-17  Jsr     ESCAN00033251 FTU support
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

/* PRQA S 0303 EOF */ /* Misra rule 11.3. Standard justification for HW-access of Fr */
/* PRQA S 0857 EOF */ /* Misra rule 11.3. Standard justification for Macro usage in Fr */

/**********************************************************************************************************************
* Filtered for DrvFr_Tms470ErayAsr 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fr_Priv.h"
#include "Std_Types.h"

#if (!defined  V_SUPPRESS_EXTENDED_VERSION_CHECK )
#include "v_ver.h"
#endif

#if ((!defined ( V_SUPPRESS_EXTENDED_VERSION_CHECK )) || ( FR_CRC_CHECK == STD_ON ))
#include "EcuM_Cbk.h"
#endif


/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check consistency of source and header file. */
#if ( (FR_SW_MAJOR_VERSION != 0x3u) || (FR_SW_MINOR_VERSION != 0x14u) || (FR_SW_PATCH_VERSION != 0x04u) )
# error "Fr.c: Source and Header file are inconsistent!"
#endif




/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define FR_VCC_NEW_DAT_N_REG_MAX         4u    /* number of NDATn registers in CC */
#define FR_VNMV1_BYTECOUNT               4u
#define FR_VNMV2_BYTECOUNT               8u
#define FR_VNMV3_BYTECOUNT               12u
#define FR_VMAX_ARRAY_FOR_NMVECTOR       3u
#define FR_FIFO_MARK                     0x80u
#define FR_LAST_FIFO_FRAME               1u

#define FR_TXVIRTBUF_INFO_DYNPAYLOAD            ((uint8)0x1)
#define FR_TXVIRTBUF_INFO_RECONFIG              ((uint8)0x2)
#define FR_TXVIRTBUF_INFO_RECONFIG_LPDU         ((uint8)0x4)
#define FR_TXVIRTBUF_INFO_BIDIROUT              ((uint8)0x8)

#define FR_RXVIRTBUF_CYCLEBASE_RECONFIG_LPDU    ((uint8)0x80)
#define FR_RECONFIG_LPDU_WRHS1_MASK             (0x3C000000UL)

#define FR_SYNC_FRAME_LIST_MAX                ((uint8)15)     
#define FR_HEADER_CRC_MAX                     ((uint16)0x7FF) /* Must be 2^x-1 bitvalue to allow bitfiltering */


# if (defined (FR_VCHANNEL_STATUS_EXT)) && ( FR_VCHANNEL_STATUS_EXT == STD_ON )

#define FR_SIGNEDBIT_RCV                 0x0800u
#define FR_SIGNEDBIT_OCV                 0x00040000UL

#define FR_FILLSIGNED_RCV                0xF000u
#define FR_FILLSIGNED_OCV                0xFFF80000UL

#define FR_GETCHANNELSTATUS_ACS_MASK 0x1F
#define FR_GETCHANNELSTATUS_TXCONFLICT_SHIFT  5
#define FR_GETCHANNELSTATUS_MTS_SHIFT  8
#define FR_GETCHANNELSTATUS_SWS_SHIFT  9
#define FR_GETCHANNELSTATUS_NIT_SHIFT  12
# endif
 /* FR_VCHANNEL_STATUS_EXT */


#define FR_MASK_NMBYTEPOS                   0x03


/* PRQA S 1503 EOF */ /* MISRA rule 14.1 violation because of single project Misra check */
  
/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
#if (FR_CONFIG_VARIANT == 3)
#define Fr_VGetCcBufCfgAt(Idx)              (&Fr_VPostBuildConfigPtr->CcBufs[(Idx)])      /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_VGetCcCfgAddrAt(Idx)             (Fr_VPostBuildConfigPtr->CcRegAddrs[(Idx)])   /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_VGetCcCfgValAt(Idx)              (Fr_VPostBuildConfigPtr->CcRegVals[(Idx)])    /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_VGetNumRxVirtBuf2PhysBufs()      (Fr_VPostBuildConfigPtr->NumRxVirtBuf2PhysBufs)/* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_VGetNumTxVirtBuf2PhysBufs()      (Fr_VPostBuildConfigPtr->NumTxVirtBuf2PhysBufs)/* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_VGetNumCcBufs()                  (Fr_VPostBuildConfigPtr->NumCcBufs)           /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_VGetNumCcRegs()                  (Fr_VPostBuildConfigPtr->NumCcRegs)           /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#if defined FR_GENERATOR_GENY
#  define Fr_GetRXTXVirtBufIdx(Idx)         (Fr_VLPduIdx2RxTxVirtBufMapPtr[(Idx)])
#  define Fr_GetRxVirtBuf2Phys(Idx)         (Fr_VRxVirtBuf2PhysBufMapPtr[Fr_GetRXTXVirtBufIdx((Idx))]) 
#  define Fr_GetTxVirtBuf2Phys(Idx)         (Fr_VTxVirtBuf2PhysBufMapPtr[Fr_GetRXTXVirtBufIdx((Idx))])
#else
#  define Fr_GetRxVirtBuf2Phys(Idx)         (Fr_VRxVirtBuf2PhysBufMapPtr[(Idx)])          /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#  define Fr_GetTxVirtBuf2Phys(Idx)         (Fr_VTxVirtBuf2PhysBufMapPtr[(Idx)])          /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#endif /* FR_GENERATOR_GENY */
#if ( FR_NMVECTOR_ENABLE == STD_ON )
#define Fr_GetNMVectorLength()              (Fr_VPostBuildConfigPtr->NmVectorLength)      /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#endif
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)  
#define FR_VGETTIMEOUT_DURATION    (Fr_VPostBuildConfigPtr->Fr_VTimeoutDuration)
# endif
#  if defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON)
#define Fr_VGetFtuCfgAddrAt(Idx)            (Fr_VPostBuildConfigPtr->Fr_VFtuRegAdr[(Idx)]) /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_VGetFtuCfgValAt(Idx)             (Fr_VPostBuildConfigPtr->Fr_VFtuRegVal[(Idx)]) /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_VGetTBABufAdr(Idx)               ((Fr_VPostBuildConfigPtr->Fr_VTcrBufs[(Idx)])) /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#  endif  /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
#endif /* (FR_CONFIG_VARIANT == 3) */


#if defined(FR_PROD_ERROR_DETECT) && (STD_ON == FR_PROD_ERROR_DETECT)
# define FR_DEM_E_ACCESS                 FR_DEM_GEN_E_ACCESS
# define FR_DEM_E_CTRLTESTRESULT         FR_DEM_GEN_E_CtrlTestResult
#endif


#if (FR_CONFIG_VARIANT == 2)
#define Fr_VGetNumRxVirtBuf2PhysBufs()      (Fr_VNumRxVirtBuf2PhysBufs)
#define Fr_VGetNumTxVirtBuf2PhysBufs()      (Fr_VNumTxVirtBuf2PhysBufs)
#define Fr_VGetNumCcBufs()                  (Fr_VNumCcBufs)
#define Fr_VGetNumCcRegs()                  (Fr_VNumCcRegs)
#if ( FR_NMVECTOR_ENABLE == STD_ON )
#define Fr_GetNMVectorLength()              (Fr_NmVectorLength)
#endif
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)  
#define FR_VGETTIMEOUT_DURATION    (Fr_VTimeoutDuration)
# endif
#endif /* (FR_CONFIG_VARIANT == 2) */
     
#if ((FR_CONFIG_VARIANT == 2) || (FR_CONFIG_VARIANT == 1))
#define Fr_VGetCcBufCfgAt(Idx)              (&Fr_VCcBufs[(Idx)])    /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
#define Fr_VGetCcCfgAddrAt(Idx)             (Fr_VCcRegAddrs[(Idx)]) /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
#define Fr_VGetCcCfgValAt(Idx)              (Fr_VCcRegVals[(Idx)])  /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
#if defined FR_GENERATOR_GENY
#  define Fr_GetRXTXVirtBufIdx(Idx)         (Fr_VLPduIdx2RxTxVirtBufMap[(Idx)])
#  define Fr_GetRxVirtBuf2Phys(Idx)         (Fr_VRxVirtBuf2PhysBufMap[Fr_GetRXTXVirtBufIdx((Idx))]) 
#  define Fr_GetTxVirtBuf2Phys(Idx)         (Fr_VTxVirtBuf2PhysBufMap[Fr_GetRXTXVirtBufIdx((Idx))])
#else
#  define Fr_GetRxVirtBuf2Phys(Idx)         (Fr_VRxVirtBuf2PhysBufMap[(Idx)]) /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
#  define Fr_GetTxVirtBuf2Phys(Idx)         (Fr_VTxVirtBuf2PhysBufMap[(Idx)])/* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
#endif /* FR_GENERATOR_GENY */
#  if defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON)
#define Fr_VGetFtuCfgAddrAt(Idx)            (Fr_VFtuRegAdr[(Idx)]) /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
#define Fr_VGetFtuCfgValAt(Idx)             (Fr_VFtuRegVal[(Idx)]) /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
#define Fr_VGetTBABufAdr(Idx)               (Fr_VTcrBufs[(Idx)]) /* PRQA S 3453 */ /* MISRA-C:2004 19.7, Macro is defined to increase readibility and to reduce execution time */
#  endif  /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
#endif /* ((FR_CONFIG_VARIANT == 2) || (FR_CONFIG_VARIANT == 1)) */

#if (FR_CONFIG_VARIANT == 1)
#define Fr_VGetNumRxVirtBuf2PhysBufs()      (FR_SIZE_RXVIRTBUF2PHAYBUFMAP)
#define Fr_VGetNumTxVirtBuf2PhysBufs()      (FR_SIZE_TXVIRTBUF2PHAYBUFMAP)
#define Fr_VGetNumCcBufs()                  (FR_SIZE_MB_ARRAY)
#define Fr_VGetNumCcRegs()                  (FR_SIZE_CONTROLREGCONFARRAY)

# if ( FR_NMVECTOR_ENABLE == STD_ON )
#define Fr_GetNMVectorLength()              (FR_NM_VECTOR_LENGTH)
# endif
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)  
#define FR_VGETTIMEOUT_DURATION  FR_VTIMEOUT_DURATION
# endif
#endif /* FR_CONFIG_VARIANT == 1 */

#if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
#define  FR_NOHWTIMEOUT                    (Fr_VLoopTimeout <= FR_VGETTIMEOUT_DURATION)
#define  FR_INCREASETIMEOUTCOUNTER         (Fr_VLoopTimeout++)
#else
#define  FR_NOHWTIMEOUT      1 == 1
#define  FR_INCREASETIMEOUTCOUNTER         
#endif 

# define FR_VALUEWRHS1    pBufCfg->WRHS1

#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
#define Fr_VNewData(physBufIdx)    (Fr_VFtuNewData((physBufIdx))) /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
/* Hint: Null Frame is indicated as NFI == 0 (see ERay-Spec) */ 
#define Fr_CheckNFI()              (CCREG_MBS_NFIS == (pTba[3] & CCREG_MBS_NFIS))             /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_CheckValidFrame()       ((CCREG_ACS_VFRA == (pTba[3] & (CCREG_ACS_VFRA))) || (CCREG_ACS_VFRB == (pTba[3] & (CCREG_ACS_VFRB))))
#define Fr_ReceiveCycleCount()     ((pTba[2] & CCREG_RDHS3_RCC_MASK) >> CCREG_RDHS3_RCC_SHIFT)  /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_CheckPPI()              (CCREG_RDHS3_PPI == (pTba[2] & CCREG_RDHS3_PPI))             /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_IsDynamicFrame()        (((uint16)(pTba[0] & CCREG_RDHS1_FID_MASK)) > FR_GETLAST_STATIC_FRAMEID) /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_GetMessageID()          ((uint16)(pTba[4] >> 16))                                    /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_GetReceiveByteLength()  ((uint8)((pTba[1] & CCREG_RDHS2_PLR_MASK)>>(CCREG_RDHS2_PLR_SHIFT -1)))  /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_GetRDHS1()              (pTba[0])
#define Fr_GetMBS()                (pTba[3])
#define Fr_WriteWRHS1(value)       (pTba[0] = (value))  /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_WriteWRHS2(value)       (pTba[1] = (value))  /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_WriteWRHS3(value)       (pTba[2] = (value))  /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#else
#define Fr_VNewData(physBufIdx)    (Fr_VCCNewData((physBufIdx)))  /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
/* Hint: Null Frame is indicated as NFI == 0 (see ERay-Spec) */ 
#define Fr_ReceiveCycleCount()     (Fr_VCCReadBitsShift(CCREG_RDHS3, CCREG_RDHS3_RCC_MASK, CCREG_RDHS3_RCC_SHIFT))  /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_CheckPPI()              (CCREG_RDHS3_PPI == Fr_VCCReadBits(CCREG_RDHS3, CCREG_RDHS3_PPI))                /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_IsDynamicFrame()        (((uint16) Fr_VCCReadBits(CCREG_RDHS1, CCREG_RDHS1_FID_MASK)) > FR_GETLAST_STATIC_FRAMEID) /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_GetMessageID()          ((uint16) Fr_VCCReadBits(CCREG_RDDSn, 0xFFFFUL))                                 /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_GetReceiveByteLength()  (Fr_VCCGetReceiveLength() << 1)
#define Fr_GetRDHS1()              (Fr_VCCReadValue(CCREG_RDHS1))     
#define Fr_WriteWRHS1(value)       (Fr_VCCWriteValueWRHS(CCREG_WRHS1, (value)))   /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_WriteWRHS2(value)       (Fr_VCCWriteValueWRHS(CCREG_WRHS2, (value)))   /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#define Fr_WriteWRHS3(value)       (Fr_VCCWriteValueWRHS(CCREG_WRHS3, (value)))   /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
#if defined FR_GENERATOR_GENY
#define FR_GETRXTXLPDUIDX(Idx)     Fr_GetRXTXVirtBufIdx((Idx))
#else
#define FR_GETRXTXLPDUIDX(Idx)     (Idx)  /* PRQA S 3453 */ /* MISRA-C:2004 Rule 19.7  Macro is used to reduce execution time */
#endif
#if FR_MULTI_ID_CONFIG == STD_ON
#define FR_MULTI_ID_INVALID 0xFFu
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
#define FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */


#if (FR_CONFIG_VARIANT == 3 )
STATIC P2CONST(Fr_VRxVirtBuf2PhysBufMapType, FR_VAR_NOINIT_FAST, FR_PBCFG) Fr_VRxVirtBuf2PhysBufMapPtr;
STATIC P2CONST( Fr_VTxVirtBuf2PhysBufMapType, FR_VAR_NOINIT_FAST, FR_PBCFG) Fr_VTxVirtBuf2PhysBufMapPtr;
STATIC P2CONST( Fr_ConfigType, FR_VAR_NOINIT_FAST, FR_PBCFG) Fr_VPostBuildConfigPtr;
#if defined FR_GENERATOR_GENY
STATIC P2CONST(uint16, FR_VAR_NOINIT_FAST, FR_PBCFG)                       Fr_VLPduIdx2RxTxVirtBufMapPtr;
#endif
#endif

#define FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */

#define FR_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */


#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
static VAR( uint8, FR_VAR_NOINIT) Fr_VFtuLockCounter;
#if (defined (FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)  
static VAR( uint8, FR_VAR_NOINIT) Fr_VFtuImmediateTxFlag;
#endif /* defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */ 
#endif

#define FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */

#define FR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */


STATIC CONST(Fr_POCStateType, FR_CONST) Fr_VPocStateMapTable[3][16] =  /* PRQA S 3218 */ /* MISRA rule 8.7 Movement of this array in function would result in other MISRA violations */
{
  { 
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:DEFAULT_CONFIG state */
    FR_POCSTATE_READY,          /* CC:READY state */
    FR_POCSTATE_NORMAL_ACTIVE,  /* NORMAL_ACTIVE state */
    FR_POCSTATE_NORMAL_PASSIVE, /* NORMAL_PASSIVE state */
    FR_POCSTATE_HALT,           /* HALT state */ 
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:MONITOR_MODE state */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_DEFAULT_CONFIG, /* CC:reserved */
    FR_POCSTATE_CONFIG 
  },
  {
    FR_POCSTATE_WAKEUP, /* CC:WAKEUP_STANDBY state */
    FR_POCSTATE_WAKEUP, /* CC:WAKEUP_LISTEN state */
    FR_POCSTATE_WAKEUP, /* CC:WAKEUP_SEND state */
    FR_POCSTATE_WAKEUP, /* CC:WAKEUP_DETECT state */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP, /* CC:reserved */
    FR_POCSTATE_WAKEUP  /* CC:reserved */
  },
  {
    FR_POCSTATE_STARTUP,  /* CC:STARTUP_PREPARE state */
    FR_POCSTATE_STARTUP,  /* CC:COLDSTART_LISTEN state */
    FR_POCSTATE_STARTUP,  /* CC:COLDSTART_COLLISION_RESOLUTION state */
    FR_POCSTATE_STARTUP,  /* CC:COLDSTART_CONSISTENCY_CHECK state */
    FR_POCSTATE_STARTUP,  /* CC:COLDSTART_GAP state */
    FR_POCSTATE_STARTUP,  /* CC:COLDSTART_JOIN State */
    FR_POCSTATE_STARTUP,  /* CC:INTEGRATION_COLDSTART_CHECK state */
    FR_POCSTATE_STARTUP,  /* CC:INTEGRATION_LISTEN state */
    FR_POCSTATE_STARTUP,  /* CC:INTEGRATION_CONSISTENCY_CHECK state */
    FR_POCSTATE_STARTUP,  /* CC:INITIALIZE_SCHEDULE state */
    FR_POCSTATE_STARTUP,  /* CC:ABORT_STARTUP state */
    FR_POCSTATE_STARTUP,  /* CC:reserved */
    FR_POCSTATE_STARTUP,  /* CC:reserved */
    FR_POCSTATE_STARTUP,  /* CC:reserved */
    FR_POCSTATE_STARTUP,  /* CC:reserved */
    FR_POCSTATE_STARTUP   /* CC:reserved */
   } 
};
STATIC CONST(Fr_SlotModeType, FR_CONST) Fr_VSlotModeMapTable[] =   /* PRQA S 3218 */ /* MISRA rule 8.7 Movement of this array in function would result in other MISRA violations */
{
  FR_SLOTMODE_SINGLE,
  FR_SLOTMODE_SINGLE,
  FR_SLOTMODE_ALL_PENDING,
  FR_SLOTMODE_ALL
};
STATIC CONST(Fr_StartupStateType, FR_CONST) Fr_VStartupStateMapTable[] =  /* PRQA S 3218 */ /* MISRA rule 8.7 Movement of this array in function would result in other MISRA violations */
{
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_COLDSTART_LISTEN,
  FR_STARTUP_COLDSTART_COLLISION_RESOLUTION,
  FR_STARTUP_COLDSTART_CONSISTENCY_CHECK,
  FR_STARTUP_COLDSTART_GAP,
  FR_STARTUP_COLDSTART_JOIN,
  FR_STARTUP_INTEGRATION_COLDSTART_CHECK, 
  FR_STARTUP_INTEGRATION_LISTEN, 
  FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK,
  FR_STARTUP_INITIALIZE_SCHEDULE,
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_UNDEFINED,
  FR_STARTUP_UNDEFINED
};
#if FR_VEXTENDED_CC_STATUS == STD_ON
STATIC CONST(Fr_StartupStateType, FR_CONST) Fr_VErrorModeTable[] =  /* PRQA S 3218 */ /* MISRA rule 8.7 Movement of this array in function would result in other MISRA violations */
{
  CC_ERROR_ERRM_ACTIVE,
  CC_ERROR_ERRM_PASSIVE,
  CC_ERROR_ERRM_COMMHALT,
  CC_ERROR_ERRM_ACTIVE
};
 #endif  /* FR_EXTENDED_CC_STATUS == STD_ON */
 

#define FR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */
/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FR_START_SEC_CONST_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */

#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
  CONST( uint32, FR_CONST ) DRVFR_XERAYASR_LIB_SYMBOL = DRVFR_XERAYASR_LIB_VERSION;  /* PRQA S 3408 */ /* MISRA rule 8.8 variable is declated as extern within sip_check.c file of the intergration */
#endif

#define FR_STOP_SEC_CONST_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */

#define FR_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */

#if (FR_DEV_ERROR_DETECT == STD_ON )
VAR( Fr_VFrDrvStateType, FR_VAR_NOINIT) Fr_VFrDrvState;
#endif

#define FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */

/**************************************************************************************************
* LOCAL FUNCTION PROTOTYPES
**************************************************************************************************/
#define FR_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */

STATIC FUNC( Std_ReturnType, FR_CODE) Fr_VEnterConfigMode(void);
STATIC FUNC( Std_ReturnType, FR_CODE) Fr_VLeaveConfigMode(void);
STATIC FUNC( Std_ReturnType, FR_CODE) Fr_VExecutePOCCommand(uint32 Fr_PocCommand);
STATIC FUNC(uint16, FR_CODE) Fr_VCalHeaderCRC(uint8 Fr_PayloadLength, uint16 Fr_CRC);


# if (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_OFF)
static 
FUNC(void, FR_CODE) Fr_VWriteDataToCC  /* PRQA S 3408 */ /* MISRA rule 8.8 function is declated as extern caused by asm variant */
(
  Fr_RegisterPtrType pDst, 
  P2CONST(uint8, AUTOMATIC, FR_APPL_DATA) pSrc, 
  uint16 CpyLength
);

static 
FUNC(void, FR_CODE) Fr_VReadDataFromCC  /* PRQA S 3408 */ /* MISRA rule 8.8 function is declated as extern caused by asm variant */
(
  P2VAR  (uint8, AUTOMATIC, FR_APPL_DATA) pDst, 
  volatile P2CONST(uint32, AUTOMATIC, MSR_REGSPACE) pSrc, 
  uint16 CpyLength
);
# endif /* if (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_OFF) */


#if (defined(FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
# if defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON)
STATIC FUNC(void, FR_CODE) Fr_VCopyRAM32
(
  P2VAR (void, AUTOMATIC, FR_VAR_NOINIT) pDst, 
  P2CONST (void, AUTOMATIC, FR_VAR_NOINIT) pSrc, 
  uint16 CpyLength
);
# endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
#endif  /* defined(FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */


#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
static FUNC(void, FR_CODE) Fr_LockFtu(uint8 BufIdx);
static FUNC(void, FR_CODE) Fr_UnLockFtu(void);
#endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */

/**************************************************************************************************
*  GLOBAL FUNCTIONS
**************************************************************************************************/
/**************************************************************************************************
                                      A  U  T  O  S  A  R
**************************************************************************************************/
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
FUNC( void, FR_CODE) Fr_Init( P2CONST(Fr_ConfigType, AUTOMATIC, FR_PBCFG) Fr_ConfigPtr)   /* PRQA S 3206 */ /* MISRA-C:2004 , Parameter Fr_ConfigPtr is only used in postbuild configuration */
{
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
  uint32 Fr_VLoopTimeout = 0;
#endif
# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (1 == FR_CONFIG_VARIANT)  )
  Fr_ConfigPtr = Fr_ConfigPtr; 
# endif

#if (!defined V_SUPPRESS_EXTENDED_VERSION_CHECK )
/* Check the PBCfg Configuration. The detailed implementation may differ. The check tests that major and minor version in the library are valid. The patch version */
# if (FR_CONFIG_VARIANT == 3 )
 if((((Fr_ConfigPtr->Fr_BaseGeneratorVersion & 0x00FFFF00)!=
      ((DRVFR__BASEASR_GENTOOL_GENY_MAJOR_VERSION<<16) | (DRVFR__BASEASR_GENTOOL_GENY_MINOR_VERSION<<8))) 
#  if (DRVFR__BASEASR_GENTOOL_GENY_PATCH_VERSION != 0)      
    || ((Fr_ConfigPtr-> Fr_BaseGeneratorVersion & (uint32)0x000000FF) < DRVFR__BASEASR_GENTOOL_GENY_PATCH_VERSION)   
#  endif
      )
      &&
      (((Fr_ConfigPtr->Fr_CcGeneratorVersion & (uint32)0x00FFFF00)!=
      (((uint32)DRVFR_XERAYASR_GENTOOL_GENY_MAJOR_VERSION<<16) | ((uint32)DRVFR_XERAYASR_GENTOOL_GENY_MINOR_VERSION<<8)))
#  if (DRVFR_XERAYASR_GENTOOL_GENY_PATCH_VERSION != 0)
      || ((Fr_ConfigPtr->Fr_CcGeneratorVersion & (uint32)0x000000FF) < (uint32)DRVFR_XERAYASR_GENTOOL_GENY_PATCH_VERSION)
#  endif
      ))
# else /* ( (FR_CONFIG_VARIANT == 2) || (FR_CONFIG_VARIANT == 1) ) */
 if((((Fr_ExtVersionCheckStruct.Fr_BaseGeneratorVersion & (uint32)0x00FFFF00)!=
      (((uint32)DRVFR__BASEASR_GENTOOL_GENY_MAJOR_VERSION<<16) | ((uint32)DRVFR__BASEASR_GENTOOL_GENY_MINOR_VERSION<<8)))
#  if (DRVFR__BASEASR_GENTOOL_GENY_PATCH_VERSION != 0)   
      || ((Fr_ExtVersionCheckStruct.Fr_BaseGeneratorVersion & (uint32)0x000000FF)<DRVFR__BASEASR_GENTOOL_GENY_PATCH_VERSION)
#  endif
      )
      &&
      (((Fr_ExtVersionCheckStruct.Fr_CcGeneratorVersion & (uint32)0x00FFFF00)!=
      (((uint32)DRVFR_XERAYASR_GENTOOL_GENY_MAJOR_VERSION<<16) | ((uint32)DRVFR_XERAYASR_GENTOOL_GENY_MINOR_VERSION<<8)))
#  if (DRVFR_XERAYASR_GENTOOL_GENY_PATCH_VERSION != 0)
      || ((Fr_ExtVersionCheckStruct.Fr_CcGeneratorVersion & (uint32)0x000000FF)<DRVFR_XERAYASR_GENTOOL_GENY_PATCH_VERSION)
#  endif
      ))
# endif
  {
    /* Call the Vector specific EcuM Error callback and do NOT Call Det_ReportError. */
    EcuM_GeneratorCompatibilityError((uint16) FR_MODULE_ID, (uint8) 0);
    return; /* Do not continue with the initialization of the component the Application may be influenced critically. */ 
  }
#endif
  /* !defined  V_SUPPRESS_EXTENDED_VERSION_CHECK */

#if ( FR_CRC_CHECK == STD_ON )
# if (FR_CONFIG_VARIANT == 2)
  if (Fr_PrecompileCRC != FR_PRECOMPILE_CRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) FR_MODULE_ID, (uint8) 0u);
    return; 
  }
#  if ((FR_CONFIG_VARIANT == 3 ))
  if (Fr_ConfigPtr->Fr_PrecompileCRC != FR_PRECOMPILE_CRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) FR_MODULE_ID, (uint8) 0u);
    return; 
  }
  if ( Fr_ConfigPtr->Fr_LinktimeCRCPb != Fr_LinktimeCRC)
  {
    EcuM_GeneratorCompatibilityError((uint16) FR_MODULE_ID, (uint8) 0u);
    return; 
  }
#  endif /* (FR_CONFIG_VARIANT == 3 ) */
# endif /* FR_CONFIG_VARIANT */
#endif /* FR_CRC_CHECK */

#if ( FR_DEV_ERROR_DETECT == STD_ON )
  Fr_VFrDrvState = FR_VUNINITPTR;
#endif
#if (FR_CONFIG_VARIANT == 3 )
  Fr_CheckDetErrorReturnVoid(FR_DET_CON_PTR_CHECK(Fr_ConfigPtr), FR_API_ID_INIT, FR_E_INV_POINTER); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  
  Fr_VPostBuildConfigPtr      = (P2CONST(Fr_ConfigType, AUTOMATIC, FR_PBCFG)) Fr_ConfigPtr;
  Fr_VRxVirtBuf2PhysBufMapPtr = Fr_VPostBuildConfigPtr->RxVirtBuf2PhysBufMap;
  Fr_VTxVirtBuf2PhysBufMapPtr = Fr_VPostBuildConfigPtr->TxVirtBuf2PhysBufMap;
#if defined (FR_GENERATOR_GENY)
  Fr_VLPduIdx2RxTxVirtBufMapPtr = Fr_VPostBuildConfigPtr->LPduIdx2RxTxVirtBufMap;
#endif /* FR_GENERATOR_GENY */
#endif



# if defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON)
  Fr_VFtuWriteValue(FR_FTU_REG_GCS, FR_FTU_REG_GCS_CTTSM + FR_FTU_REG_GCS_CTTCC + FR_FTU_REG_GCS_CETESM); /* FTU Reset */
  Fr_VFtuWriteValue(FR_FTU_REG_GCS+4, 0xffffffffUL); /* Transfer Unit Disabled */
# endif   /* (FR_VCC_USE_FTU) */


  if ((Std_ReturnType)E_OK == Fr_VExecutePOCCommand(CCCMD_FREEZE)) /* currently only one driver instance is supported */
  {
    while ((CCPOCS_HALT != (uint32)Fr_VCCGetPocState()) && (FR_NOHWTIMEOUT))
    {
      FR_INCREASETIMEOUTCOUNTER;
    }
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
    if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
    {
      Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
      return;
    }
#endif
    /* A ne call of the Fr_ControllerInit necessary after Fr_AbortCommunication, that ensure clear */ 
    /* of all pending transmission and reception indication flags                 */
    Fr_VCCWriteValue(CCREG_EIER, 0xFFFFFFFFUL); /* Disable all error interrupts   */
    Fr_VCCWriteValue(CCREG_SIER, 0xFFFFFFFFUL); /* Disable all status interrupts  */
    Fr_VCCWriteValue(CCREG_EIR, 0xFFFFFFFFUL); /* Clear all error interrupts      */
    Fr_VCCWriteValue(CCREG_SIR, 0xFFFFFFFFUL); /* Clear all status interrupts     */ 
    /* the deletion of the TXI, RXI, MBSI are ensure after Fr_ControllerInit      */
    /* It is not necessary to disable the timer because the CC is in HALT         */
    /* a new call of Fr_ControllerInit ensure the new initialisation of the timer */
#if ( FR_DEV_ERROR_DETECT == STD_ON )
    Fr_VFrDrvState = FR_VUNINITCFG;
#endif
  } /* ((Std_ReturnType)E_OK == Fr_VExecutePOCCommand(CCCMD_FREEZE)) */
  return;
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */


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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_ControllerInit(FR_VCTRL_SYSTEMTYPE_ONLY, uint8 Fr_LowLevelConfSetIdx, uint8 Fr_BufConfSetIdx)
{
  Std_ReturnType returnCode;
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
  uint32 Fr_VLoopTimeout = 0;
#endif
  
  Fr_CheckDetErrorReturnValue(FR_DET_CON_UNINITPTR(), FR_API_ID_CONTROLLER_INIT, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_CONTROLLER_INIT, FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_2IDX(Fr_LowLevelConfSetIdx, (uint8)FR_VMAX_NUM_LOW_LEVEL_CONFIGS, Fr_BufConfSetIdx, (uint8)FR_VMAX_NUM_BUF_CONFIGS), FR_API_ID_CONTROLLER_INIT, FR_E_INV_CONFIG, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) )
#  if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
    Fr_CtrlIdx = Fr_CtrlIdx;  
#  endif
  Fr_LowLevelConfSetIdx = Fr_LowLevelConfSetIdx;
  Fr_BufConfSetIdx = Fr_BufConfSetIdx;
# endif  


  /* enter CC Config Mode */
  returnCode = Fr_VEnterConfigMode();
  if ( (Std_ReturnType)E_OK == returnCode )
  {
    uint16 CcRegIdx;
    uint8  u8BufIdx ;
    
#if ((FR_CONFIG_VARIANT == 3 ) || (FR_CONFIG_VARIANT == 2))
    P2CONST( Fr_VCcBufType, AUTOMATIC, FR_PBCFG) pBufCfg ;
#endif
#if (FR_CONFIG_VARIANT == 1)
    P2CONST( Fr_VCcBufType, AUTOMATIC, FR_CONST) pBufCfg;
#endif
   
    /* write CC configuration */
    for (CcRegIdx=0; CcRegIdx < Fr_VGetNumCcRegs(); CcRegIdx++)
    {
      Fr_VCCWriteValue((uint32)(Fr_VGetCcCfgAddrAt(CcRegIdx)), Fr_VGetCcCfgValAt(CcRegIdx));
    }
    /* reset CNA bit set when writing SUCC1 containig the CMD */
    Fr_VCCSetBits(CCREG_EIR, CCREG_EIR_CNA);
    /* clear TIBC after config msg buffer */
    Fr_VCCSetBits(CCREG_SIR, CCREG_SIR_TIBC);
    /* configure all Frame Buffers */
    for (u8BufIdx = 0; u8BufIdx < Fr_VGetNumCcBufs(); ++u8BufIdx)
    {
      /* wait until transfer to message buffer finished */
      while((Fr_VCCIsBitSet(CCREG_IBCR, CCREG_IBCR_IBSYH)) && (FR_NOHWTIMEOUT)) 
      {
        FR_INCREASETIMEOUTCOUNTER;
      }
#if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
      if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
      {
        Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
        return ((Std_ReturnType)E_NOT_OK);
      }
#endif
      /* Config next message buffer  */
      pBufCfg = Fr_VGetCcBufCfgAt(u8BufIdx);
      Fr_VCCWriteValueWRHS(CCREG_WRHS1, pBufCfg->WRHS1);
      Fr_VCCWriteValueWRHS(CCREG_WRHS2, pBufCfg->WRHS2);
      Fr_VCCWriteValueWRHS(CCREG_WRHS3, pBufCfg->WRHS3);
      Fr_VCCWriteValueIBCM(FR_VCCREG_IBCM_INITVALUE); 
      Fr_VCCWriteValueIBCR((uint32)pBufCfg->IBCR);

# if defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON)
      {
        P2VAR(uint32, AUTOMATIC, MSR_REGSPACE) pTmp32Tcr;
        P2VAR(Fr_VTcrBufType, AUTOMATIC, FR_VAR_FRM_DATA) pTmp32Tba;
        uint32 tcrFlag;
        uint8  physBufIdx;
        
        physBufIdx=pBufCfg->IBCR;
        /* Adress to configure Host RAM */
        pTmp32Tba=(P2VAR(Fr_VTcrBufType, AUTOMATIC, FR_VAR_FRM_DATA))Fr_VGetTBABufAdr(physBufIdx);  /* PRQA S 0306 */ /* MISRA-C:2004 11.3, Standard justification for HW-Access of Fr Registers */
        /* Adress to configure TCR */
        pTmp32Tcr=(P2VAR(uint32, AUTOMATIC, MSR_REGSPACE))FR_FTU_TCR_BASE_ADDR; /* PRQA S 0306 */ /* MISRA-C:2004 11.3, Standard justification for HW-Access of Fr Registers */
        pTmp32Tcr=(P2VAR(uint32, AUTOMATIC, MSR_REGSPACE))(&(pTmp32Tcr[physBufIdx]));   /* PRQA S 0306 */ /* MISRA-C:2004 11.3, Standard justification for HW-Access of Fr Registers */   
        
        if((pBufCfg->WRHS1 & CCREG_WRHS1_CFG) != 0)       /* Transmit buffer ? */
        {
          tcrFlag=FR_FTU_REG_TCR_TPTCC + FR_FTU_REG_TCR_STXR + FR_FTU_REG_TCR_THTSM
          ;
          if( 0 != (pBufCfg->Info &  (FR_FTU_INFO_DYN_PAYLOAD + FR_FTU_INFO_RECONFIG)))
          {
            tcrFlag |= FR_FTU_REG_TCR_THTCC ;
          }
        }
        else
        {
          tcrFlag=FR_FTU_REG_TCR_THTSM + FR_FTU_REG_TCR_TPTSM; /* prepare TCR flags */
        }

        *pTmp32Tcr=(((((uint32)pTmp32Tba) >> 2UL) & 0x3fffUL) | tcrFlag); /* Configure TCR */

        *pTmp32Tba=pBufCfg->WRHS1;
        pTmp32Tba=&(pTmp32Tba[1]);
        *pTmp32Tba=pBufCfg->WRHS2;
        pTmp32Tba=&(pTmp32Tba[1]);
        *pTmp32Tba=pBufCfg->WRHS3;
        pTmp32Tba=&(pTmp32Tba[1]);
        *pTmp32Tba=pBufCfg->IBCR;
      }
# endif    /* (FR_VCC_USE_FTU) */

    } /* for(All buffers to config) */

# if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
/* write FTU configuration and enables FTU (GCS is last register in array)*/
    {
      Fr_VFtuLockCounter=0;                 /* resets the Ftu-lock-counter as FTU is reseted */
#  if defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)  
      Fr_VFtuImmediateTxFlag=0;
#  endif /* defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */ 
      for (CcRegIdx=0; CcRegIdx <= FR_FTU_REG_POS_MAX; CcRegIdx++)
      {
        Fr_VFtuWriteValue((uint32)(Fr_VGetFtuCfgAddrAt(CcRegIdx)), Fr_VGetFtuCfgValAt(CcRegIdx));
      }
    }
# endif /* (FR_VCC_USE_FTU) */ 


    /* leave CC Config Mode */
    returnCode = Fr_VLeaveConfigMode();
#if ( FR_DEV_ERROR_DETECT == STD_ON )
    if (returnCode == (Std_ReturnType)E_OK)
    {
      Fr_VFrDrvState = FR_VINIT;
    }
    else
    {
      Fr_VFrDrvState = FR_VUNINITCFG;
    }
#endif
  }
  if ((Std_ReturnType)E_OK != returnCode)
  {
    Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
  }
  return (returnCode);
}  /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */

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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_SendMTS(FR_VCTRL_SYSTEMTYPE_ONLY, Fr_ChannelType Fr_ChnlIdx)
{
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_SEND_MTS, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_SEND_MTS,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_NOTAB(Fr_ChnlIdx), FR_API_ID_SEND_MTS, FR_E_INV_CHNL_IDX, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_POCSTATE(CCPOCS_NORMAL_ACTIVE), FR_API_ID_SEND_MTS, FR_E_INV_POCSTATE, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if (  (FR_DEV_ERROR_DETECT == STD_OFF) && ( V_USE_DUMMY_STATEMENT  ==  STD_ON) )
#  if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) 
  Fr_CtrlIdx = Fr_CtrlIdx;  
#  endif  
  Fr_ChnlIdx = Fr_ChnlIdx;
# endif  
  /* The MTS channel muss be already defined within the config phase */
  return(Fr_VExecutePOCCommand(CCCMD_SEND_MTS));
}  /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_StopMTS(FR_VCTRL_SYSTEMTYPE_ONLY, Fr_ChannelType Fr_ChnlIdx)
{
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_STOP_MTS, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_STOP_MTS,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_NOTAB(Fr_ChnlIdx), FR_API_ID_STOP_MTS, FR_E_INV_CHNL_IDX, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if (  (FR_DEV_ERROR_DETECT == STD_OFF) && ( V_USE_DUMMY_STATEMENT  ==  STD_ON) )
#  if (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) 
  Fr_CtrlIdx = Fr_CtrlIdx;  
#  endif  
  Fr_ChnlIdx = Fr_ChnlIdx;
# endif  
  /* ERay stop the send of MTS alone */
  return((Std_ReturnType)E_OK);
}  /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_CheckMTS
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  Fr_ChannelType Fr_ChnlIdx, 
  P2VAR(Fr_MTSStatusType, AUTOMATIC, FR_APPL_DATA) Fr_MTSStatusPtr
)
{
  uint32 Flag  = CCREG_SIR_MTSA;
  uint8  Shift = CCREG_SWNIT_WIN_A_SHIFT;

  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_CHECK_MTS, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_CHECK_MTS,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_NOTAB(Fr_ChnlIdx), FR_API_ID_CHECK_MTS, FR_E_INV_CHNL_IDX, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECKPTR(Fr_MTSStatusPtr), FR_API_ID_CHECK_MTS, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif  
  /* Check for channel B */
  if ( (FR_CHANNEL_B == Fr_ChnlIdx) )
  {
    Flag  = CCREG_SIR_MTSB;
    Shift = CCREG_SWNIT_WIN_B_SHIFT;
  }

  /* Consider error flags */
  if ( ( Fr_VCCCheckMTS(CCREG_SWNIT_SESA, Shift) == (CCREG_SWNIT_SESA<<Shift)) && (Fr_VCCCheckMTS(CCREG_SWNIT_SBSA, Shift) == (CCREG_SWNIT_SBSA<<Shift)) )
  {
    *Fr_MTSStatusPtr = FR_MTS_RCV_SYNERR_BVIO;
  }
  else if ( Fr_VCCCheckMTS(CCREG_SWNIT_SESA, Shift) == (CCREG_SWNIT_SESA<<Shift) )
  {
    *Fr_MTSStatusPtr = FR_MTS_RCV_SYNERR;
  }
  else if ( Fr_VCCCheckMTS(CCREG_SWNIT_SBSA, Shift) == (CCREG_SWNIT_SBSA<<Shift) )
  {
    *Fr_MTSStatusPtr = FR_MTS_RCV_BVIO;
  }
  else
  {
    *Fr_MTSStatusPtr = FR_MTS_RCV;
  }

  /* Consider MTS rx flag */
  if ( Flag != Fr_VCCCheckIrqStatusFlag(Flag) )
  {
    *Fr_MTSStatusPtr += FR_MTS_NOT_RCV;
  }
  return((Std_ReturnType)E_OK);
}  /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_StartCommunication(FR_VCTRL_SYSTEMTYPE_ONLY)
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_START_COMMUNICATION, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_START_COMMUNICATION,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_POCSTATE(CCPOCS_READY), FR_API_ID_START_COMMUNICATION, FR_E_INV_POCSTATE, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif  
  return(Fr_VExecutePOCCommand(CCCMD_RUN));
} /* PRQA S 2006 */ /* MISRA rule 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_AllowColdstart(FR_VCTRL_SYSTEMTYPE_ONLY)
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_ALLOW_COLDSTART, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_ALLOW_COLDSTART,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif  
  return(Fr_VExecutePOCCommand(CCCMD_ALLOW_COLDSTART));
} /* PRQA S 2006 */ /* MISRA rule 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_HaltCommunication(FR_VCTRL_SYSTEMTYPE_ONLY)
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */

#if FR_DEV_ERROR_DETECT == STD_ON
  uint32 pocState;
  pocState = Fr_VCCGetPocState();
#endif /* FR_DEV_ERROR_DETECT == STD_ON */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_HALT_COMMUNICATION, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_HALT_COMMUNICATION,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_2POCSTATE(CCPOCS_NORMAL_ACTIVE, CCPOCS_NORMAL_PASSIVE,pocState), FR_API_ID_HALT_COMMUNICATION, FR_E_INV_POCSTATE,(Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif    
  return(Fr_VExecutePOCCommand(CCCMD_HALT));
}  /* PRQA S 2006 */ /* MISRA rule 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_AbortCommunication(FR_VCTRL_SYSTEMTYPE_ONLY)
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
  uint32 Fr_VLoopTimeout = 0;
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_ABORT_COMMUNICATION, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_ABORT_COMMUNICATION,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif    
  if ((Std_ReturnType)E_OK == Fr_VExecutePOCCommand(CCCMD_FREEZE))
  {
    while ((CCPOCS_HALT != (uint32)Fr_VCCGetPocState()) && (FR_NOHWTIMEOUT))
    {
      FR_INCREASETIMEOUTCOUNTER;
    }
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
    if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
    {
      Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
      return ((Std_ReturnType)E_NOT_OK);
    }
#endif 
    return ((Std_ReturnType)E_OK);
  }
  else
  {
    return ((Std_ReturnType)E_NOT_OK);
  }
}  /* PRQA S 2006 */ /* MISRA rule 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling and to reduce execution time and RAM consumption */
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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_SendWUP(FR_VCTRL_SYSTEMTYPE_ONLY)
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_SEND_WUP, FR_E_NOT_INITIALIZED, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_SEND_WUP,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_POCSTATE(CCPOCS_READY), FR_API_ID_SEND_WUP, FR_E_INV_POCSTATE, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif    
  return(Fr_VExecutePOCCommand(CCCMD_WAKEUP));
}  /* PRQA S 2006 */ /* MISRA rule 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_SetWakeupChannel(FR_VCTRL_SYSTEMTYPE_ONLY, Fr_ChannelType Fr_ChnlIdx)
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_SET_WAKEUP_CHANNEL, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_SET_WAKEUP_CHANNEL,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_NOTAB(Fr_ChnlIdx), FR_API_ID_SET_WAKEUP_CHANNEL, FR_E_INV_CHNL_IDX, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_POCSTATE(CCPOCS_READY), FR_API_ID_SET_WAKEUP_CHANNEL, FR_E_INV_POCSTATE, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif    
  if ( (Std_ReturnType)E_OK != Fr_VExecutePOCCommand(CCCMD_CONFIG) )
  {
    if ( FR_CHANNEL_B == Fr_ChnlIdx ) 
    {
      Fr_VCCSetBits(CCREG_SUCC1, CCREG_SUCC1_WUCS);
    }
    else 
    {
      Fr_VCCResetBits(CCREG_SUCC1, CCREG_SUCC1_WUCS);
    }
    return (Fr_VLeaveConfigMode());
  }
  else
  {
    return ((Std_ReturnType)E_NOT_OK);
  }
}   /* PRQA S 2006 */ /* MISRA rule 14.7, If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling and to reduce execution time and RAM consumption*/
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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_SetExtSync(FR_VCTRL_SYSTEMTYPE_ONLY, Fr_OffsetCorrectionType Fr_Offset,
                                                      Fr_RateCorrectionType Fr_Rate)
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */
  uint32 RegVal = 0;

  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_SET_EXT_SYNC, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_SET_EXT_SYNC,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_POCSTATE(CCPOCS_NORMAL_ACTIVE), FR_API_ID_SET_EXT_SYNC, FR_E_INV_POCSTATE, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif    
  /* Set Offset Correction Bits */
  if ( FR_OFFSET_INC == Fr_Offset )
  {
    RegVal |= CCREG_GTUC11_EOCC_INC;
  }
  else if ( FR_OFFSET_DEC == Fr_Offset )
  {
    RegVal |= CCREG_GTUC11_EOCC_DEC;
  }
  else
  {
    RegVal |= CCREG_GTUC11_EOCC_NONE;
  }
  /* Set Rate Correction Bits */
  if ( FR_RATE_INC == Fr_Rate )
  {
    RegVal |= CCREG_GTUC11_ERCC_INC;
  }
  else if ( FR_RATE_DEC == Fr_Rate )
  {
    RegVal |= CCREG_GTUC11_ERCC_DEC;
  }
  else
  {
    RegVal |= CCREG_GTUC11_ERCC_NONE;
  }
  /* Set Rate Correction Register */
  Fr_VCCWriteValue(CCREG_GTUC11, RegVal);
  
  return((Std_ReturnType)E_OK);
}  /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_GetSyncState
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  P2VAR(Fr_SyncStateType, AUTOMATIC, FR_APPL_DATA) Fr_SyncStatePtr
)
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */
  uint32 pocState; 

  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_GET_SYNC_STATE, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_GET_SYNC_STATE,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECKPTR(Fr_SyncStatePtr), FR_API_ID_GET_SYNC_STATE, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif    
  *Fr_SyncStatePtr = FR_ASYNC;
  pocState=(uint32)Fr_VCCGetPocState();
  if ((CCPOCS_NORMAL_ACTIVE ==pocState) || (CCPOCS_NORMAL_PASSIVE==pocState))
  { 
    *Fr_SyncStatePtr = FR_SYNC;
  }
  return((Std_ReturnType)E_OK);
}  /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling */

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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_GetPOCStatus
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) Fr_POCStatusPtr
)
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */
  uint32         tempCCSVReg;

  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_GET_POC_STATUS, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_GET_POC_STATUS,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECKPTR(Fr_POCStatusPtr), FR_API_ID_GET_POC_STATUS, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif    
  tempCCSVReg = Fr_VCCReadValue(CCREG_CCSV);

  Fr_POCStatusPtr->State = Fr_VPocStateMapTable[(tempCCSVReg & CCPOCS_GROUP_MASK) >> CCPOCS_GROUP_SHIFT][tempCCSVReg & CCREG_CCSV_POCS_VALUE_MASK];

  /* set Freeze, HaltRequest and ColdStartNoise */
  Fr_POCStatusPtr->Freeze         = (boolean) (CCREG_CCSV_FSI == (tempCCSVReg & CCREG_CCSV_FSI));
  Fr_POCStatusPtr->CHIHaltRequest = (boolean) (CCREG_CCSV_HRQ == (tempCCSVReg & CCREG_CCSV_HRQ));
  Fr_POCStatusPtr->ColdstartNoise = (boolean) (CCREG_CCSV_CSNI == (tempCCSVReg &  CCREG_CCSV_CSNI));
  /* set SlotMode (1:1 mapping of FR-PocState and CC-PocState) */
  Fr_POCStatusPtr->SlotMode =  Fr_VSlotModeMapTable[(tempCCSVReg & CCREG_CCSV_SLM_MASK) >> CCREG_CCSV_SLM_SHIFT ];
  
  /* set ErrorMode, WakeupStatus */
  Fr_POCStatusPtr->ErrorMode    = (Fr_ErrorModeType) Fr_VCCReadBitsShift(CCREG_CCEV, CCREG_CCEV_ERRM_MASK, CCREG_CCEV_ERRM_SHIFT);
  Fr_POCStatusPtr->WakeupStatus = (Fr_WakeupStatusType) ((tempCCSVReg & CCREG_CCSV_WSV_MASK) >> CCREG_CCSV_WSV_SHIFT);
  /* set StartupState (1:1 mapping of FR-StartupState and CC-StartupState, CCPOCS_STARTUP_PREPARE and CCPOCS_ABORT_STARTUP result in FR_STARTUP_UNDEFINED) */
  if ((tempCCSVReg & CCPOCS_GROUP_MASK) == CCPOCS_STARTUP_GROUP)
  {
    Fr_POCStatusPtr->StartupState = Fr_VStartupStateMapTable[tempCCSVReg & CCREG_CCSV_POCS_VALUE_MASK];
  }
  else
  {
    Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED;
  }
  return((Std_ReturnType)E_OK); 
}  /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */

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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu_DBA
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  uint16 Fr_LPduIdx,
  uint8 Fr_LPduLength
)
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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu
(
 FR_VCTRL_SYSTEMTYPE_ONLY, 
 uint16 Fr_LPduIdx,
 P2CONST(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduPtr, 
 uint8 Fr_LPduLength
 )
#endif /* defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */ 
{
# if  (( FR_VHARDWARE_CANCELLATION  ==  STD_ON && ((FR_VCC_USE_FTU == STD_OFF) || (!defined (FR_VCC_USE_FTU)))))
  uint32 Fr_VLoopTimeout = 0;
#endif
  uint8 cfgBufIdx;
#if ((FR_CONFIG_VARIANT == 3 ) || (FR_CONFIG_VARIANT == 2))
  P2CONST ( Fr_VCcBufType, AUTOMATIC, FR_PBCFG ) pBufCfg;
#else
  P2CONST ( Fr_VCcBufType, AUTOMATIC, FR_CONST ) pBufCfg;
#endif
#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
  P2VAR(Fr_VTcrBufType, AUTOMATIC, FR_VAR_FRM_DATA) pTba;
#endif
  cfgBufIdx = (Fr_GetTxVirtBuf2Phys(Fr_LPduIdx)).mbIdx;
  
#if FR_MULTI_ID_CONFIG == STD_ON
  if (cfgBufIdx == FR_MULTI_ID_INVALID)
    return ((Std_ReturnType)E_OK);  
#endif
  
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_TRANSMIT_TX_LPDU, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_TRANSMIT_TX_LPDU,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_GETRXTXLPDUIDX(Fr_LPduIdx), Fr_VGetNumTxVirtBuf2PhysBufs()), FR_API_ID_TRANSMIT_TX_LPDU, FR_E_INV_LPDU_IDX, (Std_ReturnType)E_NOT_OK); /* FR220 */ /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(Fr_LPduLength, ((Fr_VGetCcBufCfgAt(cfgBufIdx)->WRHS2)>>CCREG_WRHS2_PLC_BYTE_SHIFT)), FR_API_ID_TRANSMIT_TX_LPDU, FR_E_INV_LENGTH, (Std_ReturnType)E_NOT_OK);    /* get length in byte, shift only 15 */  /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

#if (defined (FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)  
  /* Check, is FTU is not locked */
  if ((Fr_VFTUReadBits(FR_FTU_REG_TSCB,FR_FTU_REG_TSCB_STUH) == 0) && (Fr_VFtuImmediateTxFlag == 0))
  {
    Fr_CallDetReportError(FR_API_ID_TRANSMIT_TX_LPDU_DBA, FR_E_INV_CONFIG);/* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
    return ((Std_ReturnType)E_NOT_OK);
  }
#else
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECKPTR(Fr_LPduPtr), FR_API_ID_TRANSMIT_TX_LPDU, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif /* defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */
#if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
#endif
#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
  /* No IBF or OBF handling with enabled FTU */
#else
#endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
  /* On buffer reconfiguration or dynamic Payload, rewrite header information before transmission */

  if (0 != ((Fr_GetTxVirtBuf2Phys(Fr_LPduIdx)).Info & (FR_TXVIRTBUF_INFO_DYNPAYLOAD 
#if (FR_BUFFER_RECONFIG == STD_ON)
    + FR_TXVIRTBUF_INFO_RECONFIG
#endif
    )))
  {
    uint32  tmpWRHS2;
  /* update header */
    pBufCfg = Fr_VGetCcBufCfgAt(cfgBufIdx);    


#if  (FR_BUFFER_RECONFIG == STD_ON)
    cfgBufIdx = pBufCfg->IBCR;
#endif /* (FR_BUFFER_RECONFIG == STD_ON) */

#if  (FR_BUFFER_RECONFIG == STD_ON) 
    if (0 != ((Fr_GetTxVirtBuf2Phys(Fr_LPduIdx)).Info & FR_TXVIRTBUF_INFO_DYNPAYLOAD))
#endif /* (FR_BUFFER_RECONFIG == STD_ON) */
    {
      uint8 dlcWord = (Fr_LPduLength + 1) >> 1;
      tmpWRHS2 = ((uint32)dlcWord << (CCREG_WRHS2_PLC_SHIFT)) | (uint32)Fr_VCalHeaderCRC(dlcWord, (Fr_GetTxVirtBuf2Phys(Fr_LPduIdx)).crc);
    }    
#if  (FR_BUFFER_RECONFIG == STD_ON) 
    else
    {
      tmpWRHS2=(pBufCfg->WRHS2);
    }
#endif /* (FR_BUFFER_RECONFIG == STD_ON) */ 

#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
    /* FTU already locked */
    pTba=(P2VAR(Fr_VTcrBufType, AUTOMATIC, FR_VAR_FRM_DATA))Fr_VGetTBABufAdr(cfgBufIdx); /* PRQA S 0306 */ /* MISRA-C:2004 11.3, Standard justification for HW-Access of Fr Registers */
# if defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
    /* FTU already locked */
# else
    Fr_LockFtu(cfgBufIdx);
    FR_VENTER_CRITICAL_SECTION_0();  /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
# endif
#else /* (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)  */
    FR_VENTER_CRITICAL_SECTION_0();  /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
    while((Fr_VCCIsBitSet(CCREG_IBCR, CCREG_IBCR_IBSYH))&& (FR_NOHWTIMEOUT)) 
    {
      FR_INCREASETIMEOUTCOUNTER;
    }
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
    if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
    {
      FR_VLEAVE_CRITICAL_SECTION_0();   /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
      Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
      return ((Std_ReturnType)E_NOT_OK);
    }
# endif /* ( FR_VHARDWARE_CANCELLATION  ==  STD_ON) */
#endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */

    Fr_WriteWRHS2(tmpWRHS2);          /* reconfig or dyn payload */
    Fr_WriteWRHS1(FR_VALUEWRHS1);
    Fr_WriteWRHS3(pBufCfg->WRHS3);
#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
    /* IBCM register not available at FTU */
#else
    /* Update data and header section */     
    Fr_VCCWriteValueIBCM((CCREG_IBCM_STXRH | CCREG_IBCM_LDSH | CCREG_IBCM_LHSH));     
#endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
  }
  else  /* FR_TXVIRTBUF_INFO_DYNPAYLOAD or FR_TXVIRTBUF_INFO_RECONFIG */
  {
#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
    pTba=(P2VAR(Fr_VTcrBufType, AUTOMATIC, FR_VAR_FRM_DATA))Fr_VGetTBABufAdr(cfgBufIdx); /* PRQA S 0306 */ /* MISRA-C:2004 11.3, Standard justification for HW-Access of Fr Registers */
# if defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
    /* FTU already locked */
# else
    Fr_LockFtu(cfgBufIdx);
    FR_VENTER_CRITICAL_SECTION_0();   /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
# endif /* defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */
#else 
    FR_VENTER_CRITICAL_SECTION_0();   /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
    while((Fr_VCCIsBitSet(CCREG_IBCR, CCREG_IBCR_IBSYH))&& (FR_NOHWTIMEOUT)) 
    {
      FR_INCREASETIMEOUTCOUNTER;
    }
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
    if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
    {
      FR_VLEAVE_CRITICAL_SECTION_0();   /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
      Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
      return ((Std_ReturnType)E_NOT_OK);
    }
# endif /* ( FR_VHARDWARE_CANCELLATION  ==  STD_ON) */

    /* update only data section */
    Fr_VCCWriteValueIBCM((CCREG_IBCM_STXRH | CCREG_IBCM_LDSH)); 
#endif
  }   /* FR_TXVIRTBUF_INFO_DYNPAYLOAD or FR_TXVIRTBUF_INFO_RECONFIG */
  /* Copy the payload: Length is given in bytes */
# if defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON)
#  if defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_OFF)  
  Fr_VWriteDataToCC((Fr_RegisterPtrType)(&pTba[4]), Fr_LPduPtr, Fr_LPduLength); 
#  endif /* (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_OFF) */
# else
  (void)Fr_VWriteDataToCC((Fr_RegisterPtrType)(Fr_VCCRegAddr(CCREG_WRDSn)), Fr_LPduPtr, Fr_LPduLength); /* PRQA S 0306 */ /* MISRA-C:2004 11.3, Standard justification for HW-Access of Fr Registers */
  Fr_VCCWriteValueIBCR( cfgBufIdx);
#endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */

#if (defined (FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
  /* Copy of the data is done by higher layer */
#else
  FR_VLEAVE_CRITICAL_SECTION_0();   /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif /* (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_OFF) */

# if defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON)
  Fr_VFtuSendBufCCSet(cfgBufIdx);
  Fr_UnLockFtu();

#endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
  return((Std_ReturnType)E_OK);
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */

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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu_ImmediateDBA 
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  uint16 Fr_LPduIdx,
  P2CONST(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduPtr, 
  uint8 Fr_LPduLength
)
{
  P2VAR(uint8, AUTOMATIC, FR_VAR_NOINIT) FrameBuffer = NULL_PTR;
  Std_ReturnType ret;

#if FR_MULTI_ID_CONFIG == STD_ON
  if (Fr_GetTxVirtBuf2Phys(Fr_LPduIdx).mbIdx == FR_MULTI_ID_INVALID)
    return ((Std_ReturnType)E_OK);
#endif
  
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_TRANSMIT_TX_LPDU_IMMEDIATE_DBA, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_TRANSMIT_TX_LPDU_IMMEDIATE_DBA,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_GETRXTXLPDUIDX(Fr_LPduIdx), Fr_VGetNumTxVirtBuf2PhysBufs()), FR_API_ID_TRANSMIT_TX_LPDU_IMMEDIATE_DBA, FR_E_INV_LPDU_IDX, (Std_ReturnType)E_NOT_OK); /* FR220 */ /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(Fr_LPduLength, ((Fr_VGetCcBufCfgAt((Fr_GetTxVirtBuf2Phys(Fr_LPduIdx)).mbIdx)->WRHS2)>>CCREG_WRHS2_PLC_BYTE_SHIFT)), FR_API_ID_TRANSMIT_TX_LPDU_IMMEDIATE_DBA, FR_E_INV_LENGTH, (Std_ReturnType)E_NOT_OK);    /* get length in byte, shift only 15 */ /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECKPTR(Fr_LPduPtr), FR_API_ID_TRANSMIT_TX_LPDU_IMMEDIATE_DBA, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

  FR_VENTER_CRITICAL_SECTION_0();      /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_VFtuImmediateTxFlag=1;  
  ret = Fr_RequestBuffer_DBA(0, Fr_LPduIdx, &FrameBuffer, Fr_LPduLength);
  if( E_OK == ret)
  {
    Fr_VCopyRAM32(FrameBuffer,Fr_LPduPtr,Fr_LPduLength);
    ret = Fr_TransmitTxLPdu_DBA(0, Fr_LPduIdx, Fr_LPduLength);
  }
  Fr_VFtuImmediateTxFlag=0;  
  FR_VLEAVE_CRITICAL_SECTION_0();  /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  return(ret);
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */

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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_RequestBuffer_DBA
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  uint16 Fr_LPduIdx,
  P2VAR(Fr_LPduPtrType, AUTOMATIC, FR_APPL_DATA) Fr_LPduPtr,
  uint8 Fr_LPduLength
)
{
  uint8 cfgBufIdx;
  P2VAR(uint32, AUTOMATIC, FR_VAR_FRM_DATA) pTba;
# if  (FR_BUFFER_RECONFIG == STD_ON)
#  if ((FR_CONFIG_VARIANT == 3 ) || (FR_CONFIG_VARIANT == 2))
  P2CONST ( Fr_VCcBufType, AUTOMATIC, FR_PBCFG ) pBufCfg;
#  else
  P2CONST ( Fr_VCcBufType, AUTOMATIC, FR_CONST ) pBufCfg;
#  endif
# endif

  cfgBufIdx = (Fr_GetTxVirtBuf2Phys(Fr_LPduIdx)).mbIdx;

#if FR_MULTI_ID_CONFIG == STD_ON
  if (cfgBufIdx == FR_MULTI_ID_INVALID)
    return ((Std_ReturnType)E_PENDING);
#endif
  
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_REQUEST_BUFFER_DBA, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_REQUEST_BUFFER_DBA,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_GETRXTXLPDUIDX(Fr_LPduIdx),  Fr_VGetNumTxVirtBuf2PhysBufs()), FR_API_ID_REQUEST_BUFFER_DBA, FR_E_INV_LPDU_IDX, (Std_ReturnType)E_NOT_OK); /* FR220 */ /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(Fr_LPduLength, ((Fr_VGetCcBufCfgAt(cfgBufIdx)->WRHS2)>>CCREG_WRHS2_PLC_BYTE_SHIFT)), FR_API_ID_REQUEST_BUFFER_DBA, FR_E_INV_LENGTH, (Std_ReturnType)E_NOT_OK);    /* get length in byte, shift only 15 */ /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECKPTR(Fr_LPduPtr), FR_API_ID_REQUEST_BUFFER_DBA, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

  /* Check, if FTU is still locked */
  if ((Fr_VFTUReadBits(FR_FTU_REG_TSCB,FR_FTU_REG_TSCB_STUH) != 0) && (Fr_VFtuImmediateTxFlag == 0))
  {
    Fr_CallDetReportError(FR_API_ID_REQUEST_BUFFER_DBA, FR_E_INV_CONFIG);/* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
    return ((Std_ReturnType)E_NOT_OK);
  }
# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif

# if  (FR_BUFFER_RECONFIG == STD_ON)
  pBufCfg   = Fr_VGetCcBufCfgAt(cfgBufIdx);            
  cfgBufIdx = pBufCfg->IBCR;                          
# endif
  pTba=(P2VAR(uint32, AUTOMATIC, FR_VAR_FRM_DATA))Fr_VGetTBABufAdr(cfgBufIdx); /* PRQA S 0306 */ /* MISRA-C:2004 11.3, Standard justification for HW-Access of Fr Registers */

  Fr_LockFtu(cfgBufIdx);
  
  *Fr_LPduPtr=(Fr_LPduPtrType)(&pTba[4]); /* PRQA S 0310 */ /* MISRA rule 11.4 violation see MD_CBD_11.4 in [2] */
  return((Std_ReturnType)E_OK);
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_ReceiveRxLPdu_DBA
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  uint16 Fr_LPduIdx,  
  P2VAR(Fr_LPduPtrType, AUTOMATIC, FR_APPL_DATA) Fr_LPduPtr, 
  P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_LPduStatusPtr,
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduLengthPtr
)
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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_ReceiveRxLPdu
(
 FR_VCTRL_SYSTEMTYPE_ONLY, 
 uint16 Fr_LPduIdx,  
 P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduPtr,
 P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_LPduStatusPtr,
 P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LPduLengthPtr
 )
#endif /* (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */
{
#if  (( FR_VHARDWARE_CANCELLATION == STD_ON) && ((FR_VCC_USE_FTU == STD_OFF) || (!defined (FR_VCC_USE_FTU))))
  uint32 Fr_VLoopTimeout = 0;
#endif
#if (defined (FR_FIFO_SUPPORT)) && (FR_FIFO_SUPPORT == STD_ON)
  uint8 fifoDepth;
#endif
  uint8 physBufIdx;
  uint8 lSduLength;

  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_RECEIVE_RX_LPDU, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_RECEIVE_RX_LPDU,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_GETRXTXLPDUIDX(Fr_LPduIdx),  Fr_VGetNumRxVirtBuf2PhysBufs()), FR_API_ID_RECEIVE_RX_LPDU, FR_E_INV_LPDU_IDX, (Std_ReturnType)E_NOT_OK); /* FR220 */ /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECK3PTR(Fr_LPduPtr, Fr_LPduStatusPtr, Fr_LPduLengthPtr), FR_API_ID_RECEIVE_RX_LPDU, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

#if (defined (FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
  /* Check, if FTU is still locked */
  if (Fr_VFTUReadBits(FR_FTU_REG_TSCB,FR_FTU_REG_TSCB_STUH) != 0)
  {
    Fr_CallDetReportError(FR_API_ID_RECEIVE_RX_LPDU_DBA, FR_E_INV_CONFIG);/* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
    Fr_UnLockFtu();
  }
#endif /* (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */
#if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
#endif
  *Fr_LPduStatusPtr = FR_NOT_RECEIVED;
  physBufIdx = (Fr_GetRxVirtBuf2Phys(Fr_LPduIdx)).mbIdx;

#if FR_MULTI_ID_CONFIG == STD_ON
  if (physBufIdx == FR_MULTI_ID_INVALID)
    return ((Std_ReturnType)E_OK);  
#endif

#if (defined (FR_FIFO_SUPPORT)) && ( FR_FIFO_SUPPORT  ==  STD_ON)
  if ( (Fr_GetRxVirtBuf2Phys(Fr_LPduIdx)).cycleMask == FR_FIFO_MARK) /* fifo frame */
  {
    fifoDepth = ((Fr_GetRxVirtBuf2Phys(Fr_LPduIdx)).cycleBase);
  }
  else
  {
    fifoDepth = 1;
  }
  for (;fifoDepth > 0; fifoDepth--)
  {
#endif /* (FR_FIFO_SUPPORT == STD_ON) */
    if( (uint32)0u != Fr_VNewData(physBufIdx) )
    {
#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
      P2VAR(Fr_VTcrBufType, AUTOMATIC, FR_VAR_FRM_DATA) pTba; /* pTcrBufs; */
      Fr_LockFtu(physBufIdx);
      Fr_VFtuClearNewData(physBufIdx);
      pTba=(P2VAR(Fr_VTcrBufType, AUTOMATIC, FR_VAR_FRM_DATA))Fr_VGetTBABufAdr(physBufIdx); /* PRQA S 0306 */ /* MISRA-C:2004 11.3, Standard justification for HW-Access of Fr Registers */
#endif  /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */

#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
     /* No IBF or OBF handling with enabled FTU */     
#else
      /* Copy data from Message Buffer into Output Buffer Shadow and from there into Output Buffer */
      Fr_VCCWriteValue(CCREG_OBCM, (CCREG_OBCM_RHSS | CCREG_OBCM_RDSS));
      Fr_VCCWriteValue(CCREG_OBCR, (CCREG_OBCR_REQ | (((uint32)physBufIdx) & CCREG_OBCR_OBRS_MASK))); 
      while((CCREG_OBCR_OBSYS == Fr_VCCReadBits(CCREG_OBCR, CCREG_OBCR_OBSYS)) && (FR_NOHWTIMEOUT))
      {
        FR_INCREASETIMEOUTCOUNTER;
      }
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
      if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
      {
        Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
        return ((Std_ReturnType)E_NOT_OK);
      }
# endif
      Fr_VCCSetBits(CCREG_OBCR, CCREG_OBCR_VIEW);
#endif /* defined FR_VCC_USE_FTU && (FR_VCC_USE_FTU == STD_ON) */
      /* Copy data if not a NULL_FRAME */
      if ( 
#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
        ((Fr_CheckNFI()) && (Fr_CheckValidFrame())) &&  
#endif        
          ( 
# if ( FR_FIFO_SUPPORT  ==  STD_ON )
        ((Fr_GetRxVirtBuf2Phys(Fr_LPduIdx)).cycleMask == FR_FIFO_MARK) ||
# endif /* ( FR_FIFO_SUPPORT  ==  STD_ON ) */
        ( (Fr_ReceiveCycleCount() & (Fr_GetRxVirtBuf2Phys(Fr_LPduIdx)).cycleMask) == 
        ((Fr_GetRxVirtBuf2Phys(Fr_LPduIdx)).cycleBase 
        ))))
      {
          lSduLength = Fr_GetReceiveByteLength();
          if( lSduLength > *Fr_LPduLengthPtr)
          {
            lSduLength = *Fr_LPduLengthPtr;
          }

          /* Copy the payload */

#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
# if defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
          *Fr_LPduPtr = (P2VAR(void, AUTOMATIC, FR_APPL_DATA))(&pTba[4]);  /* PRQA S 0310 */ /* MISRA rule 11.4 violation see MD_CBD_11.4 in [2] */
# else
          Fr_VReadDataFromCC(Fr_LPduPtr, (volatile P2CONST(uint32, AUTOMATIC, MSR_REGSPACE))(&(pTba[4])), lSduLength );
# endif /* defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */
#else
          (void)Fr_VReadDataFromCC(Fr_LPduPtr, (Fr_RegisterPtrType)(Fr_VCCRegAddr(CCREG_RDDSn)), lSduLength); /* PRQA S 0306 */ /* MISRA-C:2004 11.3, Standard justification for HW-Access of Fr Registers */
#endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
          *Fr_LPduLengthPtr = lSduLength;
#if (defined (FR_FIFO_SUPPORT)) && ( FR_FIFO_SUPPORT  ==  STD_ON )
          if (fifoDepth > FR_LAST_FIFO_FRAME)
          {
            *Fr_LPduStatusPtr = FR_RECEIVED_MORE_DATA_AVAILABLE;
          }
          else
          {
            *Fr_LPduStatusPtr = FR_RECEIVED;
          }
#else  /*  ( FR_FIFO_SUPPORT  ==  STD_OFF ) */
          *Fr_LPduStatusPtr = FR_RECEIVED;
#endif /* ( FR_FIFO_SUPPORT  ==  STD_ON ) */
#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
# if defined (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
          /* Must be unlock by Fr_UnlockRxLPdu_DBA */
# else
          Fr_UnLockFtu();
# endif  /* (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */
#endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */ 
          return ((Std_ReturnType)E_OK);
#if ( FR_VENABLE_MID_FILTERING  ==  STD_ON )
        }/* Message Id not match */
#endif /* FR_VENABLE_MID_FILTERING  ==  STD_ON */
      }
      else  /* Null Frame received or cycle filter no match */ 
      {
      }
#if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
      Fr_UnLockFtu();
#endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
    } /* 0u != Fr_VNewData(physBufIdx */

#if (defined (FR_FIFO_SUPPORT)) && ( FR_FIFO_SUPPORT  ==  STD_ON )
    physBufIdx++;
  } /* end for loop for FIFO */
#endif /* ( FR_FIFO_SUPPORT  ==  STD_ON ) */
  *Fr_LPduLengthPtr=0;
  return((Std_ReturnType)E_OK); 
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */


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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_UnlockRxLPdu_DBA
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  uint16 Fr_LPduIdx
)
{
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_UNLOCK_RX_LPDU_DBA, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
# if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_UNLOCK_RX_LPDU_DBA,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
# endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_GETRXTXLPDUIDX(Fr_LPduIdx),  Fr_VGetNumRxVirtBuf2PhysBufs()), FR_API_ID_UNLOCK_RX_LPDU_DBA, FR_E_INV_LPDU_IDX, (Std_ReturnType)E_NOT_OK); /* FR220 */ /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif

  /* Check, if FTU is not locked */
  if (Fr_VFTUReadBits(FR_FTU_REG_TSCB,FR_FTU_REG_TSCB_STUH) == 0)
  {
    Fr_CallDetReportError(FR_API_ID_UNLOCK_RX_LPDU_DBA, FR_E_INV_CONFIG);/* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
    return ((Std_ReturnType)E_NOT_OK);
  }

  Fr_UnLockFtu();
  return((Std_ReturnType)E_OK); 
} /* PRQA S 2006 */ /* MISRA rule 14.7 If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
#endif /* (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */

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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_CheckTxLPduStatus
(
 FR_VCTRL_SYSTEMTYPE_ONLY,
 uint16 Fr_LPduIdx,
 P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_TxLPduStatusPtr
 )
{
  uint8 cfgBufIdx;
#if  (FR_BUFFER_RECONFIG == STD_ON)
# if  (( FR_VHARDWARE_CANCELLATION  ==  STD_ON) && ((FR_VCC_USE_FTU == STD_OFF) || (!defined(FR_VCC_USE_FTU))) )
  uint32 Fr_VLoopTimeout = 0;
#endif
# if ((FR_CONFIG_VARIANT == 3 ) || (FR_CONFIG_VARIANT == 2))
  P2CONST( Fr_VCcBufType, AUTOMATIC, FR_PBCFG) pBufCfg ;
# endif
# if (FR_CONFIG_VARIANT == 1)
  P2CONST( Fr_VCcBufType, AUTOMATIC, FR_CONST) pBufCfg;
# endif
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_CHECK_TX_LPDU_STATUS, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_CHECK_TX_LPDU_STATUS,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_GETRXTXLPDUIDX(Fr_LPduIdx), Fr_VGetNumTxVirtBuf2PhysBufs()), FR_API_ID_CHECK_TX_LPDU_STATUS, FR_E_INV_LPDU_IDX, (Std_ReturnType)E_NOT_OK); /* FR220 */ /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECKPTR(Fr_TxLPduStatusPtr), FR_API_ID_CHECK_TX_LPDU_STATUS, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

#if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
#endif    
  cfgBufIdx = Fr_GetTxVirtBuf2Phys(Fr_LPduIdx).mbIdx;

#if FR_MULTI_ID_CONFIG == STD_ON
  if (cfgBufIdx == FR_MULTI_ID_INVALID)
  {
    *Fr_TxLPduStatusPtr = FR_NOT_TRANSMITTED;
    return ((Std_ReturnType)E_OK);  
  }
#endif  
  
#if  (FR_BUFFER_RECONFIG == STD_ON)
  if (0 != ((Fr_GetTxVirtBuf2Phys(Fr_LPduIdx).Info) & FR_TXVIRTBUF_INFO_RECONFIG))
  {
# if defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON)
    P2VAR(Fr_VTcrBufType, AUTOMATIC, FR_VAR_FRM_DATA) pTba;
# endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
    pBufCfg   = Fr_VGetCcBufCfgAt(cfgBufIdx); /* gets the current configuration of the MB */
    cfgBufIdx = pBufCfg->IBCR;                /* get real buffer idx */
# if defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON)
    pTba=(P2VAR(Fr_VTcrBufType, AUTOMATIC, FR_VAR_FRM_DATA))Fr_VGetTBABufAdr(cfgBufIdx); /* PRQA S 0306 */ /* MISRA-C:2004 11.3, Standard justification for HW-Access of Fr Registers */
# else /* (FR_VCC_USE_FTU == STD_ON) */
    /* get configuration of the MB */
    Fr_VCCWriteValue(CCREG_OBCM, CCREG_OBCM_RHSS);
    Fr_VCCWriteValue(CCREG_OBCR, (CCREG_OBCR_REQ | (((uint32)cfgBufIdx) & CCREG_OBCR_OBRS_MASK)));
    while((CCREG_OBCR_OBSYS == Fr_VCCReadBits(CCREG_OBCR, CCREG_OBCR_OBSYS)) && (FR_NOHWTIMEOUT))
    {
      FR_INCREASETIMEOUTCOUNTER;
    }
#  if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
    if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
    {
      Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
      return ((Std_ReturnType)E_NOT_OK);
    }
#  endif /* ( FR_VHARDWARE_CANCELLATION  ==  STD_ON) */
    Fr_VCCSetBits(CCREG_OBCR, CCREG_OBCR_VIEW);
# endif /* defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
    if (pBufCfg->WRHS1 != Fr_GetRDHS1())
    {
      *Fr_TxLPduStatusPtr = FR_NOT_TRANSMITTED;
      return((Std_ReturnType)E_NOT_OK); 
    }
  } /* Reconfig buffer */
#endif  /* (FR_BUFFER_RECONFIG == STD_ON) */
  *Fr_TxLPduStatusPtr = (Fr_TxLPduStatusType)((0UL == Fr_VCCNewReq(cfgBufIdx)) ? FR_TRANSMITTED : FR_NOT_TRANSMITTED);
  return((Std_ReturnType)E_OK); 
}  /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */



 
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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_GetGlobalTime
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  P2VAR(uint8,  AUTOMATIC, FR_APPL_DATA) Fr_CyclePtr,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_MacroTickPtr
)
{
  uint32 RegVal;
  uint32 pocState; 

  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_GET_GLOBAL_TIME, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_GET_GLOBAL_TIME,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECK2PTR(Fr_CyclePtr, Fr_MacroTickPtr), FR_API_ID_GET_GLOBAL_TIME, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */ 

#if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
#endif    
#if defined( VECTOR_POLYSPACE_TEST )
#else
  RegVal =  Fr_VCCReadValue(CCREG_MTCCV);
  pocState=(uint32)Fr_VCCGetPocState();
#endif /* VECTOR_POLYSPACE_TEST */
  if (( CCPOCS_NORMAL_ACTIVE == pocState) || (CCPOCS_NORMAL_PASSIVE ==pocState))
  {
    *Fr_MacroTickPtr = (uint16)((RegVal & CCREG_MTCCV_MTV_MASK) >> CCREG_MTCCV_MTV_SHIFT);
    if(0==*Fr_MacroTickPtr) /* ESCAN00041307 */
    {
      RegVal =  Fr_VCCReadValue(CCREG_MTCCV);
    }  
    *Fr_CyclePtr = (uint8)((RegVal & CCREG_MTCCV_CCV_MASK) >> CCREG_MTCCV_CCV_SHIFT);
    return ((Std_ReturnType)E_OK);
  }
  else
  {
    return ((Std_ReturnType)E_NOT_OK);
  }
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */

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
#if ( FR_NMVECTOR_ENABLE == STD_ON )  /* FR266 */ 
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_GetNmVector
(
  FR_VCTRL_SYSTEMTYPE_ONLY,
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NmVectorPtr
)  
{
  uint32 pocState; 
  uint32 tempNMVnValue[FR_VMAX_ARRAY_FOR_NMVECTOR];
  uint8  nmBytePos;

  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_GET_NM_VECTOR, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_GET_NM_VECTOR,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECKPTR(Fr_NmVectorPtr), FR_API_ID_GET_NM_VECTOR, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif
  pocState = (uint32)Fr_VCCGetPocState();
  /* FR261: Fr_GetNmVector do not check CC access */
  
  /* FR263 */
  if ( (CCPOCS_NORMAL_ACTIVE == pocState) || (CCPOCS_NORMAL_PASSIVE == pocState) )  /* FR263 */
  {
    uint32 frCycle;

    /* FR265 Get cycle before start the read of the NM Vector */
    frCycle = Fr_VCCReadBits(CCREG_MTCCV, CCREG_MTCCV_CCV_MASK);
    tempNMVnValue[0] = Fr_VCCReadValue(CCREG_NMV1);
#if ((FR_CONFIG_VARIANT == 3 ) || (FR_CONFIG_VARIANT == 2))
    if ((uint32)FR_VNMV1_BYTECOUNT < Fr_VPostBuildConfigPtr->NmVectorLength)
    {
      tempNMVnValue[1] = Fr_VCCReadValue(CCREG_NMV2);
    }
#else
#if (FR_VNMV1_BYTECOUNT < FR_NM_VECTOR_LENGTH)
#endif
      tempNMVnValue[1] = Fr_VCCReadValue(CCREG_NMV2);
#endif

#if ((FR_CONFIG_VARIANT == 3 ) || (FR_CONFIG_VARIANT == 2))
    if ((uint32)FR_VNMV2_BYTECOUNT < Fr_VPostBuildConfigPtr->NmVectorLength)
    {
      tempNMVnValue[2] = Fr_VCCReadValue(CCREG_NMV3);
    }
#else
#if (FR_VNMV2_BYTECOUNT < FR_NM_VECTOR_LENGTH)
      tempNMVnValue[2] = Fr_VCCReadValue(CCREG_NMV3);
#endif
#endif

    for (nmBytePos = 0; nmBytePos < Fr_GetNMVectorLength(); nmBytePos++)  /* PRQA S 3356, 3359, 3201 3 */ /* MISRA rule 13.7, 14.1 If NM is enabled but NMVectorlength is set to 0, a compiler warning can ge thrown as configuration is not correct */
    {
	
      Fr_NmVectorPtr[nmBytePos] = (uint8)(tempNMVnValue[nmBytePos >> 2] >> ((nmBytePos & FR_MASK_NMBYTEPOS) << 3)) ; /* FR264 */
    }

    /* FR265 Ensure that the NM Vector is read at the time of one cycle */
    if (frCycle == Fr_VCCReadBits(CCREG_MTCCV, CCREG_MTCCV_CCV_MASK))
    {
      return ((Std_ReturnType)E_OK);
    }
  }
# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif      
  return((Std_ReturnType)E_NOT_OK); 
}  /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
#endif 
 /* FR_NMVECTOR_ENABLE */

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
#if (FR_VERSION_INFO_API == STD_ON)
# if (FR_VERSION_INFO_API_MACRO == STD_OFF)
FUNC(void, FR_CODE) Fr_GetVersionInfo( P2VAR(Std_VersionInfoType, AUTOMATIC, FR_APPL_DATA) VersionInfo)
{
  Fr_CheckDetErrorReturnVoid(FR_DET_CON_PTR_CHECK(VersionInfo), FR_API_ID_GET_VERSION_INFO, FR_E_INV_POINTER); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

  VersionInfo->vendorID = FR_VENDOR_ID;
  VersionInfo->moduleID = FR_MODULE_ID;
  VersionInfo->instanceID = 0;
  VersionInfo->sw_major_version = (uint8)FR_SW_MAJOR_VERSION;
  VersionInfo->sw_minor_version = (uint8)FR_SW_MINOR_VERSION;
  VersionInfo->sw_patch_version = (uint8)FR_SW_PATCH_VERSION;
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
# endif
#endif
  /* FR_VERSION_INFO_API, FR_VERSION_INFO_API_MACRO */

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
# if ( FR_DEV_ERROR_DETECT == STD_ON) 
FUNC(void, FR_CODE) Fr_InitMemory(void)
{
  Fr_VFrDrvState=FR_VUNINITPTR;
}
# endif /*(FR_DEV_ERROR_DETECT == STD_ON)*/

/**************************************************************************************************
*  LOCAL FUNCTIONS
**************************************************************************************************/

/***********************************************************************************************************************
 *  Fr_VEnterConfigMode
 **********************************************************************************************************************/
/*! \brief      Sets the controller into CONFIG state
 *  \param[in]  -
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Local function Called by Fr_ControllerInit()
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, FR_CODE) Fr_VEnterConfigMode(void)
{
  uint32 PocState;
  Fr_RegisterPtrType IbfAdr;
  uint16 IbfCount;
      
  PocState = (uint32)Fr_VCCGetPocState(); /* execute with consistent POC State */
  if ( CCPOCS_CONFIG != PocState )
  {
    if ( !((CCPOCS_HALT == PocState) || (CCPOCS_READY == PocState) || (CCPOCS_DEFAULT_CONFIG == PocState)) )
    {
      (void)Fr_VExecutePOCCommand(CCCMD_FREEZE);
      (void)Fr_VExecutePOCCommand(CCCMD_CONFIG);   /* go to DEFAULT-CONFIG state first */
    }
    else 
    {
      if ( (CCPOCS_HALT == PocState) )
      {
        (void)Fr_VExecutePOCCommand(CCCMD_CONFIG);   /* go to DEFAULT-CONFIG state first */
      }
    }
    (void)Fr_VExecutePOCCommand(CCCMD_CONFIG);   /* go to CONFIG state */
    /* clear RAM buffers and IBF, OBF */
    
  }
  /* clear RAM buffers and IBF, OBF */
  /* # Errata #35 */
  IbfAdr=(Fr_RegisterPtrType)(CCBUF_WRDS1+FR_VCC_REG_START_ADDR);
  for(IbfCount=70; IbfCount!=0; IbfCount--)
  {
    *IbfAdr=0;
    IbfAdr=&IbfAdr[1];
  }
  return (Fr_VExecutePOCCommand(CCCMD_CLEAR_RAMS));

} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */

/***********************************************************************************************************************
 *  Fr_VLeaveConfigMode
 **********************************************************************************************************************/
/*! \brief      Let controller leave CONFIG state
 *  \param[in]  -
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Local function Called by Fr_ControllerInit()
                E-Ray requires a sequence of unlock keys to leave CONFIG state
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, FR_CODE) Fr_VLeaveConfigMode(void)
{
  /* special sequence for leave CONFIG state */
  Fr_VCCWriteValue(CCREG_LCK, CCREG_LCK_CLK_KEY1);
  Fr_VCCWriteValue(CCREG_LCK, CCREG_LCK_CLK_KEY2);
  return(Fr_VExecutePOCCommand(CCCMD_READY));
}


  
/***********************************************************************************************************************
 *  Fr_VCalHeaderCRC
 **********************************************************************************************************************/
/*! \brief      Calculate header CRC for frames within dynamic segment 
 *  \param[in]  uint16 Fr_PayloadLength 
 *  \param[in]  uint8 Fr_CtrlIdx
 *  \param[in]  uint16 Fr_FrameID
 *  \param[out] -
 *  \return     uint16 CRC value
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note      
 **********************************************************************************************************************/
STATIC FUNC(uint16, FR_CODE) Fr_VCalHeaderCRC(uint8 Fr_PayloadLength, uint16 Fr_CRC)
{
  /* Init value */
  uint16 vCrcReg = Fr_CRC; 
  /* No startup and sync flag because frame within dynamic segment */
  uint16 vHeader = (uint8)Fr_PayloadLength << 4;
  uint8  i;
  for(i = 7; i >0; i--)
  {
    uint16 vCrcNext = (vHeader ^ vCrcReg) & (1<<10);
    vCrcReg = vCrcReg<<1;  
    if(vCrcNext > 0u)
    {
      vCrcReg^=0x385;
    }
    vHeader <<= 1;
  }
  vCrcReg&=FR_HEADER_CRC_MAX;
  return vCrcReg;
}


#if (defined(FR_GET_CLOCK_CORRECTION_EXT)) && ( FR_GET_CLOCK_CORRECTION_EXT == STD_ON )
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
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_GetClockCorrection( FR_VCTRL_SYSTEMTYPE_ONLY,
                                    P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) Fr_RateCorrectionPtr,
                                    P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) Fr_OffsetCorrectionPtr )
{
  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_GET_CLOCK_CORRECTION, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
# if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_GET_CLOCK_CORRECTION,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
# endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECK2PTR(Fr_RateCorrectionPtr, Fr_OffsetCorrectionPtr), FR_API_ID_GET_CLOCK_CORRECTION, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif
  
  *Fr_RateCorrectionPtr = (sint16)Fr_VCCReadBits(CCREG_RCV, CCREG_RCV_MASK);
  *Fr_OffsetCorrectionPtr = (sint32)Fr_VCCReadValue(CCREG_OCV);

  /* convert to sint16 value */
  if (( (uint16)*Fr_RateCorrectionPtr & FR_SIGNEDBIT_RCV) == FR_SIGNEDBIT_RCV)
  {
    *Fr_RateCorrectionPtr =  (sint16)((uint16)*Fr_RateCorrectionPtr | FR_FILLSIGNED_RCV);
  }

  /* convert to sint32 value */
  if (( (uint32)*Fr_OffsetCorrectionPtr & FR_SIGNEDBIT_OCV) == FR_SIGNEDBIT_OCV)
  {
    *Fr_OffsetCorrectionPtr = (sint32)((uint32)*Fr_OffsetCorrectionPtr | FR_FILLSIGNED_OCV);
  }

  return (Std_ReturnType)E_OK;
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
#endif

# if (defined (FR_VCHANNEL_STATUS_EXT)) && ( FR_VCHANNEL_STATUS_EXT == STD_ON )
/***********************************************************************************************************************
 *  Fr_GetChannelStatus
 **********************************************************************************************************************/
/*! \brief      Gets the aggregated channel status information.
 *  \param[in]  Fr_CtrlIdx  Index of FlexRay CC within the context of the FlexRay Driver.
 *  \param[out] Fr_ChannelAStatusPtr Address where the bitcoded aggregated channel status information shall be stored.
 *  \param[out] Fr_ChannelBStatusPtr Address where the bitcoded aggregated channel status information shall be stored.
 *    Bit 0: Channel A/B aggregated channel status vSS!ValidFrame
 *    Bit 1: Channel A/B aggregated channel status vSS!SyntaxError
 *    Bit 2: Channel A/B aggregated channel status vSS!ContentError
 *    Bit 3: Channel A/B aggregated channel status additional communication
 *    Bit 4: Channel A/B aggregated channel status vSS!Bviolation
 *    Bit 5: Channel A/B aggregated channel status vSS!TxConflict
 *    Bit 6: Not used (0)
 *    Bit 7: Not used (0)
 *    Bit 8: Channel A/B symbol window status data vSS!ValidMTS
 *    Bit 9: Channel A/B symbol window status data vSS!SyntaxError
 *    Bit 10: Channel A/B symbol window status data vSS!Bviolation
 *    Bit 11: Channel A/B symbol window status data vSS!TxConflict
 *    Bit 12: Channel A/B NIT status data vSS!SyntaxError
 *    Bit 13: Channel A/B NIT status data vSS!Bviolation
 *    Bit 14: Not used (0)
 *    Bit 15: Not used (0)
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        Fr_Init was called before
 *  \context    Function could be called from interrupt level or from task level
 *  \note      
 **********************************************************************************************************************/
/* PRQA S 3206 3 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(Std_ReturnType, FR_CODE) Fr_GetChannelStatus
(
  FR_VCTRL_SYSTEMTYPE_ONLY, 
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAStatusPtr,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBStatusPtr
)
{
  uint32         pocState;
  uint16         RegVal;
  Std_ReturnType returnCode = (Std_ReturnType)E_NOT_OK;

  Fr_CheckDetErrorReturnValue(FR_DET_CON_INIT(), FR_API_ID_GET_CHANNEL_STATUS, FR_E_NOT_INITIALIZED,(Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */  /* MISRA-C:2004 14.3,  If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#  if ( FR_VCTRL_ENABLE_API_OPTIMIZATION == STD_OFF )
  Fr_CheckDetErrorReturnValue(FR_DET_CON_IDX(FR_VCTRL_IDX, (uint8)FR_NUM_CTRL_SUPPORTED), FR_API_ID_GET_CHANNEL_STATUS,FR_E_INV_CTRL_IDX, (Std_ReturnType)E_NOT_OK);/* PRQA S 3109 */  /* MISRA-C:2004 14.3,   If DET is enabled the function-like macro will be terminated by a ; for better C-like readability. */
#  endif
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECKPTR(Fr_ChannelAStatusPtr), FR_API_ID_GET_CHANNEL_STATUS, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  Fr_CheckDetErrorReturnValue(FR_DET_CON_CHECKPTR(Fr_ChannelBStatusPtr), FR_API_ID_GET_CHANNEL_STATUS, FR_E_INV_POINTER, (Std_ReturnType)E_NOT_OK); /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

#  if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_DEV_ERROR_DETECT == STD_OFF) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
#  endif

  pocState = (uint32)Fr_VCCGetPocState();
  if ( (CCPOCS_NORMAL_ACTIVE == pocState) || (CCPOCS_NORMAL_PASSIVE == pocState)  )
  {
    /* Bit 0 - 4 */  
    RegVal = (uint16)Fr_VCCReadValue(CCREG_ACS);
     /* Delete ACS content after read */
    Fr_VCCWriteValue(CCREG_ACS, (uint32)RegVal);


    *Fr_ChannelAStatusPtr  = (RegVal >> CCREG_CCREG_ACS_VFRA_SHIFT) & FR_GETCHANNELSTATUS_ACS_MASK;
    *Fr_ChannelBStatusPtr  = (RegVal >> CCREG_CCREG_ACS_VFRB_SHIFT) & FR_GETCHANNELSTATUS_ACS_MASK;

    /* Bit 5 not required for FlexRay 2.1 */

    /* Bit 8 */
    *Fr_ChannelAStatusPtr |= (uint16)((RegVal & CCREG_SWNIT_MTSA_SFS) << (FR_GETCHANNELSTATUS_MTS_SHIFT - CCREG_SWNIT_MTSA_SFS_SHIFT));
    *Fr_ChannelBStatusPtr |= (uint16)((RegVal & CCREG_SWNIT_MTSB_SFS) << (FR_GETCHANNELSTATUS_MTS_SHIFT - CCREG_SWNIT_MTSB_SFS_SHIFT));

    /* Bit 9 - 11 */
    RegVal = (uint16)Fr_VCCReadValue(CCREG_SWNIT)  ;
    *Fr_ChannelAStatusPtr |= (uint16)((RegVal & (CCREG_SWNIT_SESA + CCREG_SWNIT_SBSA + CCREG_SWNIT_TCSA)) << (FR_GETCHANNELSTATUS_SWS_SHIFT - CCREG_SWNIT_WIN_A_SHIFT));
    *Fr_ChannelBStatusPtr |= (uint16)((RegVal & (CCREG_SWNIT_SESB + CCREG_SWNIT_SBSB + CCREG_SWNIT_TCSB)) << (FR_GETCHANNELSTATUS_SWS_SHIFT - CCREG_SWNIT_WIN_B_SHIFT));

    /* Bit 12 - 13 */
    *Fr_ChannelAStatusPtr |= (uint16)((RegVal & (CCREG_SWNIT_SENA + CCREG_SWNIT_SBNA )) << ( FR_GETCHANNELSTATUS_NIT_SHIFT - CCREG_SWNIT_SENA_SHIFT));
    *Fr_ChannelBStatusPtr |= (uint16)((RegVal & (CCREG_SWNIT_SENB + CCREG_SWNIT_SBNB )) << ( FR_GETCHANNELSTATUS_NIT_SHIFT - CCREG_SWNIT_SENB_SHIFT));

    returnCode = (Std_ReturnType)E_OK;
  }
  return (returnCode);
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
# endif
  /* FR_VCHANNEL_STATUS_EXT */





# if (defined (FR_VEXTENDED_CC_STATUS)) && (FR_VEXTENDED_CC_STATUS == STD_ON)
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
/* PRQA S 1505 1 */ /* MISRA rule 8.10  Caused by non usage in some testenvironments  */
FUNC(void, FR_CODE) Fr_VErrorMode(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr)
{
  uint32 ui32CCEV = Fr_VCCReadValue(CCREG_CCEV); /* "read only" register */

  *Fr_VErrorStatusPtr |= Fr_VErrorModeTable[((ui32CCEV & CCREG_CCEV_ERRM_MASK) >> CCREG_CCEV_ERRM_SHIFT)];
}

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
/* PRQA S 1505 1 */ /* MISRA rule 8.10  Caused by non usage in some testenvironments  */
FUNC(void, FR_CODE) Fr_VClockCorrectionError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr)
{
  uint32 ui32CCEV = Fr_VCCReadValue(CCREG_CCEV); /* "read only" register */

  if (((ui32CCEV & CCREG_CCEV_CCFC_MASK) >> CCREG_CCEV_CCFC_SHIFT) !=0)
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_CLOCKCORRECTION;
  }
}

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
/* PRQA S 1505 1 */ /* MISRA rule 8.10  Caused by non usage in some testenvironments  */
FUNC(void, FR_CODE) Fr_VSyncFrameError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr)
{
  uint32 ui32EIR = Fr_VCCReadValue(CCREG_EIR);

  if (((ui32EIR & CCREG_EIR_SFBM) |(ui32EIR & CCREG_EIR_SFO) )!=0)
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_SYNCFRAME;
    Fr_VCCWriteValue(CCREG_EIR, (CCREG_EIR_SFBM | CCREG_EIR_SFO));  /* reset bits */
  }
}

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
/* PRQA S 1505 1 */ /* MISRA rule 8.10  Caused by non usage in some testenvironments  */
FUNC(void, FR_CODE) Fr_VChannelError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr)
{
  uint32 ui32EIR = Fr_VCCReadValue(CCREG_EIR);

  if ((ui32EIR & CCREG_EIR_EDA) !=0)
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_CHANNEL_A;
    Fr_VCCWriteValue(CCREG_EIR, CCREG_EIR_EDA );  /* reset bit */
  }

  if ((ui32EIR & CCREG_EIR_EDB)!=0)
  {
   *Fr_VErrorStatusPtr |= CC_ERROR_CHANNEL_B;
    Fr_VCCWriteValue(CCREG_EIR, CCREG_EIR_EDB);  /* reset bit */
  }
}

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
/* PRQA S 1505 1 */ /* MISRA rule 8.10  Caused by non usage in some testenvironments  */
FUNC(void, FR_CODE) Fr_VSyntaxError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr)
{   
  uint32 ui32ACS = Fr_VCCReadValue(CCREG_ACS);

  if ((ui32ACS & CCREG_ACS_SEDA)!=0)
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_SYNTAX_A;
    Fr_VCCWriteValue(CCREG_ACS, CCREG_ACS_SEDA );  /* reset bit */
  }

  if ((ui32ACS & CCREG_ACS_SEDB)!=0)
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_SYNTAX_B;
    Fr_VCCWriteValue(CCREG_ACS, CCREG_ACS_SEDB);  /* reset bit */
  }
}

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
/* PRQA S 1505 1 */ /* MISRA rule 8.10  Caused by non usage in some testenvironments  */
FUNC(void, FR_CODE) Fr_VLatestTxError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr)
{
  uint32 ui32EIR = Fr_VCCReadValue(CCREG_EIR);

  if ((ui32EIR & CCREG_EIR_LTVA)!=0)
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_LATESTTX_A;
    Fr_VCCWriteValue(CCREG_EIR, CCREG_EIR_LTVA );  /* reset bit */
  }

  if ((ui32EIR & CCREG_EIR_LTVB)!=0)
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_LATESTTX_B;
    Fr_VCCWriteValue(CCREG_EIR, CCREG_EIR_LTVB);  /* reset bit */
  }
}

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
/* PRQA S 1505 1 */ /* MISRA rule 8.10  Caused by non usage in some testenvironments  */
FUNC(void, FR_CODE) Fr_VSwError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr)
{
  uint32 ui32SWNIT = Fr_VCCReadValue(CCREG_SWNIT);  /* "read only" register */

  if  (0 != (ui32SWNIT & (CCREG_SWNIT_SESA | CCREG_SWNIT_SBSA) ) )
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_SW_A;
  }

  if  (0 != (ui32SWNIT & (CCREG_SWNIT_SESB | CCREG_SWNIT_SBSB) ) )  
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_SW_B;
  }
}

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
/* PRQA S 1505 1 */ /* MISRA rule 8.10  Caused by non usage in some testenvironments  */
FUNC(void, FR_CODE) Fr_VNitError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr)
{
  uint32 ui32SWNIT = Fr_VCCReadValue(CCREG_SWNIT);  /* "read only" register */

  if (((ui32SWNIT & CCREG_SWNIT_SENA) |(ui32SWNIT & CCREG_SWNIT_SBNA) )!=0)
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_NIT_A;
  }

  if (((ui32SWNIT & CCREG_SWNIT_SENB) |(ui32SWNIT & CCREG_SWNIT_SBNB) )!=0)
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_NIT_B;
  }
}

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
/* PRQA S 1505 1 */ /* MISRA rule 8.10  Caused by non usage in some testenvironments  */
FUNC(void, FR_CODE) Fr_VColdStartError(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr)
{
  uint32 ui32CCSV = Fr_VCCReadValue(CCREG_CCSV);  /* "read only" register */

  if (((ui32CCSV & CCREG_CCSV_CSAI) |(ui32CCSV & CCREG_CCSV_CSNI) )!=0)
  {
    *Fr_VErrorStatusPtr |= CC_ERROR_COLDSTART;
  }
}

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
/* PRQA S 1505 1 */ /* MISRA rule 8.10  Caused by non usage in some testenvironments  */
FUNC(void, FR_CODE) Fr_VCheckErrorState(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr)
{
  Fr_VErrorMode(Fr_VErrorStatusPtr);
  Fr_VClockCorrectionError(Fr_VErrorStatusPtr);
  Fr_VSyncFrameError(Fr_VErrorStatusPtr);
  Fr_VChannelError(Fr_VErrorStatusPtr);
  Fr_VSyntaxError(Fr_VErrorStatusPtr);
  Fr_VLatestTxError(Fr_VErrorStatusPtr);
  Fr_VSwError(Fr_VErrorStatusPtr);
  Fr_VNitError(Fr_VErrorStatusPtr);
  Fr_VColdStartError(Fr_VErrorStatusPtr);

  if (*Fr_VErrorStatusPtr !=0)
  {
    ApplFr_CBK_CcErrorEvent(Fr_VErrorStatusPtr);
  }
}

# endif  /* FR_EXTENDED_CC_STATUS == STD_ON */
  
/***********************************************************************************************************************
 *  Fr_VExecutePOCCommand
 **********************************************************************************************************************/
/*! \brief      Forces the CC to go in appropriate POC state
 *  \param[in]  uint32 Fr_PocCommand
 *  \param[out] -
 *  \return     Std_ReturnType E_OK
 *  \return     Std_ReturnType E_NOT_OK
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
STATIC FUNC(Std_ReturnType, FR_CODE) Fr_VExecutePOCCommand(uint32 Fr_PocCommand)
{
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
  uint32 Fr_VLoopTimeout = 0;
#endif
  while (( CCREG_SUCC1_PBSY == (Fr_VCCReadBits(CCREG_SUCC1, CCREG_SUCC1_PBSY))) && (FR_NOHWTIMEOUT) ) /* Wait for free protocol control */
  {
    FR_INCREASETIMEOUTCOUNTER;
  }
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
  if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
  {
    Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
    return ((Std_ReturnType)E_NOT_OK);
  }
#endif
  Fr_VCCSetBitsMask(CCREG_SUCC1, Fr_PocCommand, CCREG_SUCC1_CMD_MASK);
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
  Fr_VLoopTimeout = 0;
#endif
  while ((CCREG_SUCC1_PBSY == (Fr_VCCReadBits(CCREG_SUCC1, CCREG_SUCC1_PBSY)))  && (FR_NOHWTIMEOUT)) /* Wait for protocol control command  */
  {
    FR_INCREASETIMEOUTCOUNTER;
  }
# if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
  if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
  {
    Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
    return ((Std_ReturnType)E_NOT_OK);
  }
#endif
  if(CCCMD_CNA != (Fr_VCCReadBits(CCREG_SUCC1, CCREG_SUCC1_CMD_MASK))) 
  { /* Command is accepted */
    return ((Std_ReturnType)E_OK);
  }
  else
  {
    Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
    return ((Std_ReturnType)E_NOT_OK);
  }
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */


/***********************************************************************************************************************
 *  Fr_VReadDataFromCC
 **********************************************************************************************************************/
/*! \brief      moves byteCnt16 words from 32-bit wide accessed RAM pSrc 
 *              to 16-bit-wide accessed RAM pDst
 *  \param[in]  void *pDst     : RAM destination pointer 
 *  \param[in]  void* pSrc     : RAM source pointer (CC)  
 *  \param[in]  uint16 WordCnt : number of bytes to be copied 
 *  \param[out] -
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_ReceiveRxLPdu
 **********************************************************************************************************************/
#if (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_OFF)
# if defined(FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION) && (FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION==STD_ON)
# error "Platform does not support ASSEMBLER copy routine! Please disable at configuration tool"

# else  /* FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION) && (FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION==STD_ON) */

static FUNC(void, FR_CODE) Fr_VReadDataFromCC
(
  P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) pDst, 
  volatile P2CONST(uint32, AUTOMATIC, MSR_REGSPACE) pSrc, 
  uint16 CpyLength
) 
{
#   if defined (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON)
    P2VAR(  uint32, AUTOMATIC, FR_APPL_DATA)p32Dst = (P2VAR(  uint32, AUTOMATIC, FR_APPL_DATA))pDst;    /* PRQA S 0310 */ /* MISRA rule 11.4 Alignment of "Dword-alginment" of FTU data is used */
    volatile P2CONST(uint32, AUTOMATIC, FR_APPL_DATA)p32Src = pSrc;
    uint16 DWordCnt;

    CpyLength=(CpyLength + 1) >> 1;
    DWordCnt = CpyLength >> 1;

    while(DWordCnt!=0)
    {
      *p32Dst =*p32Src;
      p32Dst  =&p32Dst[1];

      p32Src  =&p32Src[1];
      DWordCnt--;
    }
    if ( (CpyLength % 2)!=0 )  /* copy last 16bit for odd CpyLength */
    {  
      *((P2VAR(uint16, AUTOMATIC, FR_PBCFG))p32Dst) =(*((volatile P2CONST(uint16, AUTOMATIC, FR_PBCFG))p32Src)); /* PRQA S 0310 */ /* MISRA rule 11.4 Alignment of "Dword-alginment" of FTU data is used */
    }

#   endif   /* (FR_VCC_USE_FTU) */
#   if !defined (FR_VCC_USE_FTU) || ((FR_VCC_USE_FTU == STD_OFF))
  {
    uint32 payloadValue;
    Fr_RegisterPtrType p32Src = (Fr_RegisterPtrType) pSrc;
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) p8Dst = (P2VAR(uint8, AUTOMATIC, FR_APPL_DATA))pDst;
    uint16 DWordCnt;
    
    CpyLength=(CpyLength + 1) >> 1;
    DWordCnt = CpyLength>>1;

    while(DWordCnt!=0)
    {
      payloadValue = (uint32)(*p32Src);
      p8Dst[0] = (uint8)(payloadValue);
      p8Dst[1] = (uint8)((payloadValue)>> 8);
      p8Dst[2] = (uint8)((payloadValue)>>16);
      p8Dst[3] = (uint8)((payloadValue)>>24);
      p32Src  =&p32Src[1];
      p8Dst   =&p8Dst[4];
      DWordCnt--;
    }
    if ( (CpyLength % 2)!=0 )  /* copy last 16bit for odd CpyLength */
    { 
      payloadValue = (uint32)(*p32Src);
      p8Dst[0] = (uint8)(payloadValue);
      p8Dst[1] = (uint8)(payloadValue >> 8);
    }
  }
#   endif /* ((FR_VCC_USE_FTU == STD_OFF)) */

}
# endif /* if defined(FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION) && (FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION==STD_ON) */
#endif /* (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_OFF) */



/***********************************************************************************************************************
 *  Fr_VWriteDataToCC
 **********************************************************************************************************************/
/*! \brief      moves ByteCnt words from 16-bit-wide accessed RAM pSrc 
 *              to 32-bit wide accessed RAM pDest
 *  \param[in]  void *pDst     : RAM destination pointer 
 *  \param[in]  void* pSrc     : RAM source pointer (CC)  
 *  \param[in]  uint16 WordCnt : number of bytes to be copied 
 *  \param[out] -
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
#if (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_OFF)
# if defined(FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION) && (FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION==STD_ON)
  /* R0 = dest */
  /* R1 = source */
  /* R2 = byte */
  /* used register, R0-R3, R12 */
  asm ("Fr_WriteDataToCCLoop1:            ");
  asm ("        LDRH R3,[R1,#2]           "); /* load value from source into R12 */
  asm ("        LDRH R12,[R1],#4          "); /* load value from source into R12 */
  asm ("        LSL  R12,#16              ");
  asm ("        ADD  R12,R12,R3           "); /* load value from source into R12 */
#   ifndef FR_VTMS470_LITTLE_ENDIAN  
/* Little Endian support not tested */
  asm ("        .word 0E6BFCF3Ch          "); /* swap R12 to R12 */ 
#   endif
  asm ("        STR R12,[R0],#4           "); /* store value in dest */
  asm ("        subs R2,R2,#4             "); /* dec byte counter */
  asm ("        bgt Fr_WriteDataToCCLoop1 "); /* check if all 32 bit values are copied */
  asm ("        beq Fr_WriteDataToCCEnd   "); /* check if something is to clear */
  
  asm ("Fr_WriteDataToCCRest:             "); /* clear values not multiple of 4 */
  asm ("        subs R0,R0,#4             "); /* restore last destination */
  asm ("        add  R2,R2,#4             "); /* restore last byte counter */
  asm ("        LDR R1,Fr_WriteDataToCCTable  "); /* get  adress of mask table */
  asm ("        LDR R1,[R1,R2,LSL #2]     "); /* get mask */
  asm ("        AND R12,R12,R1            "); /* mask last value */
  asm ("        STR R12,[R0]              "); /* store value in dest */
  asm ("        b   Fr_WriteDataToCCEnd    "); /* Free stack space from 12 byte parameter */

  asm ("Fr_WriteDataToCCTable:            "); /* mask table */
  asm ("    .long  Fr_WriteDataToCCTable  "); /* inside asm function but after return */ 
  asm ("    .long 0000000ffh              ");
  asm ("    .long 00000ffffh              ");
  asm ("    .long 000ffffffh              ");
  asm ("Fr_WriteDataToCCEnd:              "); /* return */  

# else /* if defined(FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION) && (FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION==STD_ON) */

static FUNC(void, FR_CODE) Fr_VWriteDataToCC
(
  Fr_RegisterPtrType pDst, 
  P2CONST(uint8, AUTOMATIC, FR_APPL_DATA) pSrc, 
  uint16 CpyLength
) 
{

#   if defined(FR_VCC_USE_FTU)
#    if (FR_VCC_USE_FTU == STD_ON)

    /* copy function: with FTU */
    Fr_RegisterPtrType p32Dst       = (Fr_RegisterPtrType) pDst;
    P2CONST(uint32, AUTOMATIC, FR_APPL_DATA) p32Src   = (P2CONST(uint32, AUTOMATIC, FR_APPL_DATA)) pSrc;  /* PRQA S 0310 */ /* MISRA rule 11.4 Alignment of "Dword-alginment" of FTU data is used */
    uint16 DWordCnt = (CpyLength+3)>>2;

    while(DWordCnt!=0)
    {
      *p32Dst = *p32Src;  
      p32Dst  =&(p32Dst[1]);
      p32Src  =&(p32Src[1]);  /* MISRA does not like p32Src+=1 */
      DWordCnt--;
    }

#    endif   /* (FR_VCC_USE_FTU == STD_ON) */
#   endif   /* (FR_VCC_USE_FTU) */
#   if !defined (FR_VCC_USE_FTU) || ((FR_VCC_USE_FTU == STD_OFF))
  {
   /* copy function: without FTU */
    P2CONST(uint8, AUTOMATIC, FR_APPL_DATA) p8Src       = pSrc;
    Fr_RegisterPtrType p32Dst         = (Fr_RegisterPtrType) pDst;  
    uint16 DWordCnt = (CpyLength+1)>>2;

    while(DWordCnt!=0)
    {
      *p32Dst = ( (((uint32)(p8Src[3])) <<24u) | 
                  (((uint32)(p8Src[2])) <<16u) |
                  (((uint32)(p8Src[1])) << 8u) |
                  (((uint32)(p8Src[0]))      ));  
      p32Dst  =&(p32Dst[1]);
      p8Src  =&(p8Src[4]);  /* MISRA does not like p16SrcH+=2 */
      DWordCnt--;
    }
    if ( (CpyLength & 3)!=0 ) /* copy last 16bit for odd CpyLength */
    {  
      *p32Dst = (((uint16)(p8Src[1])) << 8) + ((uint16)(p8Src[0]));
    }
  }
#   endif /* ((FR_VCC_USE_FTU == STD_OFF)) */

}
# endif /* if defined(FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION) && (FR_CTRL_ENABLE_ASSEMBLER_FUNCTION_OPTIMIZATION==STD_ON) */
#endif  /* if defined(FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */


#if (defined(FR_DIRECT_BUFFER_ACCESS_ENABLE)) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON)
# if (defined(FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
/***********************************************************************************************************************
 *  Fr_VCopyRAM32
 **********************************************************************************************************************/
/*! \brief      copy byteCnt/4 4byte words from pSrc to pDest
 *  \param[in]  void *pDst     : RAM destination pointer 
 *  \param[in]  void* pSrc     : RAM source pointer (CC)  
 *  \param[in]  uint16 WordCnt : number of words (16bit) to be copied
 *  \param[out] -
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       Internal function called by Fr_TransmitTxLPdu
 **********************************************************************************************************************/
STATIC FUNC(void, FR_CODE) Fr_VCopyRAM32
(
  P2VAR(void, AUTOMATIC, FR_VAR_NOINIT) pDst, 
  P2CONST(void, AUTOMATIC, FR_VAR_NOINIT) pSrc,
  uint16 CpyLength
) 
{
  uint16 DWordCnt = (CpyLength +3) >> 2;
  P2CONST(uint32, AUTOMATIC, FR_VAR_NOINIT) p32Src = (P2CONST(uint32, AUTOMATIC, FR_VAR_NOINIT)) pSrc;
  P2VAR(uint32, AUTOMATIC, FR_VAR_NOINIT) p32Dst = (P2VAR(uint32, AUTOMATIC, FR_VAR_NOINIT)) pDst;

  while(DWordCnt!=0)
  {
    *p32Dst = *p32Src;  
    p32Src  =&(p32Src[1]);
    p32Dst  =&(p32Dst[1]);
    DWordCnt--;
  }
}
#endif /* define (FR_VCC_USE_FTU) && (FR_VCC_USE_FTU == STD_ON) */
#endif  /* define (FR_DIRECT_BUFFER_ACCESS_ENABLE) && (FR_DIRECT_BUFFER_ACCESS_ENABLE == STD_ON) */



#  if (FR_CFG_APPL_CALLBACK_CYCLE_START == STD_ON)

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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(void, FR_CODE) Fr_ISR_Status(FR_VCTRL_SYSTEMTYPE_ONLY) /* PRQA S 3206 */ /* MISRA-C:2004 , Parameter Fr_CtrlIndex is used to be compatible to Module extension */
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */
#   if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
  uint32 Fr_VLoopTimeout = 0;
#   endif
  /* Work with copies of the registers to work on a constant situation during each pass */
  uint32 ui32SIR  = Fr_VCCReadValue(CCREG_SIR);

#   if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON) && (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
#   endif
  /* Handle only these interrupts which are actually enabled (SIR indicates all of them) */
  while( ((0UL != (FR_VISR_STATUS_FILTER & ui32SIR))) && ((uint8)FR_NOHWTIMEOUT))
  {
    FR_INCREASETIMEOUTCOUNTER;

    /************************************************/
    /*           CycleStart Interrupt               */
    /************************************************/
    if(0UL != Fr_VCheckIrqFlag(CCREG_SIR_CYCS, FR_VISR_STATUS_FILTER, ui32SIR))
    {    
      /* *** Application callback *** */
#   if (FR_CFG_APPL_CALLBACK_CYCLE_START == STD_ON)
      ApplFr_ISR_CycleStart();
#   endif      
      /* Clear CYCS and MTS interrupt */
      Fr_VCCClearIrqStatusFlag(CCREG_SIR_CYCS|CCREG_SIR_MTSA|CCREG_SIR_MTSB);
    }
    /* Check for further pending Interrupts */
    ui32SIR = Fr_VCCReadValue(CCREG_SIR);
  }
#   if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
    if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
    {
      Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
      return;
    }
#   endif
  /* clear interrupt */
  Fr_VCCClearIrqStatusFlag(CCREG_SIR_CYCS|CCREG_SIR_MTSA|CCREG_SIR_MTSB|CCREG_SIR_TXI|CCREG_SIR_RXI);
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */
#  endif


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
/* PRQA S 3206 1 */ /* MISRA rule . Fr_CtrlIdx is not used but required by Autosar */
FUNC(void, FR_CODE) Fr_ISR_Timer1(FR_VCTRL_SYSTEMTYPE_ONLY)
{ /* PRQA S 3007 */ /* MISRA-C:2004 16.5, Part of Single Channel API optimization */
# if ( ( V_USE_DUMMY_STATEMENT  ==  STD_ON)&& (FR_CTRL_ENABLE_API_OPTIMIZATION == STD_OFF ) )
  Fr_CtrlIdx = Fr_CtrlIdx;  
# endif
  /* *** Application callback *** */
  ApplFr_ISR_Timer1();
  /* Clear T0 interrupt */
  Fr_VCCClearIrqStatusFlag(CCREG_SIR_TI1);
}
#endif
  /* FR_RELATIVE_TIMER_ENABLE */


# if (defined (FR_VCC_USE_FTU)) && (FR_VCC_USE_FTU == STD_ON)
/***********************************************************************************************************************
 *  Fr_LockFtu
 **********************************************************************************************************************/
/*! \brief      Locks the FTU
 *  \param[in]  uint8 BufIdx
 *  \param[out] -
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
static FUNC(void, FR_CODE) Fr_LockFtu(uint8 BufIdx)
{
#  if  ( FR_VHARDWARE_CANCELLATION  ==  STD_ON) 
  uint32 Fr_VLoopTimeout = 0;
#  endif
  FR_VENTER_CRITICAL_SECTION_1();      /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
  if(Fr_VFTUReadBits(FR_FTU_REG_TSCB,FR_FTU_REG_TSCB_BN) == BufIdx)  /* Is buffer currently transfered */
  {
    Fr_VFtuWriteValue(FR_FTU_REG_TSCB,FR_FTU_REG_TSCB_IDLE);  /* Clear Idle flag */
    Fr_VFtuWriteValue(FR_FTU_REG_GCR,FR_FTU_REG_GCS_TUH);     /* Start FTU again out of possible Halt mode */
    while((Fr_VFTUReadBits(FR_FTU_REG_TSCB,FR_FTU_REG_TSCB_BN) == BufIdx) && 
      (Fr_VFTUReadBits(FR_FTU_REG_TSCB,FR_FTU_REG_TSCB_IDLE)==0) 
      && (FR_NOHWTIMEOUT) ) /* wait until idle or another buffer is sent */
    {
      FR_INCREASETIMEOUTCOUNTER;

    }        
#  if ( FR_VHARDWARE_CANCELLATION  ==  STD_ON)
      if (Fr_VLoopTimeout > FR_VGETTIMEOUT_DURATION)
      {
        FR_VLEAVE_CRITICAL_SECTION_1();   /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
        Fr_VDemReportErrorStatus(FR_DEM_E_ACCESS, DEM_EVENT_STATUS_FAILED);
        return;
      }
#  endif /* ( FR_VHARDWARE_CANCELLATION  ==  STD_ON ) */
  }
  Fr_VFtuWriteValue(FR_FTU_REG_GCS,FR_FTU_REG_GCS_TUH);   /* Bring FTU in Halt mode */  
  Fr_VFtuLockCounter++;
  FR_VLEAVE_CRITICAL_SECTION_1();  /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
} /* PRQA S 2006 */ /* MISRA rule 14.7  If DET is enabled the function will have more than one return path by design of ressource/runtime optimized DET handling  */

/***********************************************************************************************************************
 *  Fr_UnLockFtu
 **********************************************************************************************************************/
/*! \brief      Unlocks the FTU
 *  \param[in]  -
 *  \param[out] -
 *  \return     -
 *  \pre        
 *  \context    Function could be called from interrupt level or from task level
 *  \note       
 **********************************************************************************************************************/
static FUNC(void, FR_CODE) Fr_UnLockFtu(void)
{
  FR_VENTER_CRITICAL_SECTION_1();      /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */

  if(Fr_VFtuLockCounter > 0)
  {
    Fr_VFtuLockCounter--;
  }
  
  if(0 == Fr_VFtuLockCounter)
  {
    Fr_VFtuWriteValue(FR_FTU_REG_GCR,FR_FTU_REG_GCS_TUH);     /* Start FTU again out of Halt mode */
  }

  FR_VLEAVE_CRITICAL_SECTION_1();  /* PRQA S 3109 */ /* MISRA-C:2004 14.3, If RuntimeTest is enabled the function-like macro will be terminated by a ; for better C-like readability. */
}
# endif /* defined (FR_VCC_USE_FTU) && FR_VCC_USE_FTU == STD_ON */ 

#define FR_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */




/* STOPSINGLE_OF_MULTIPLE */
