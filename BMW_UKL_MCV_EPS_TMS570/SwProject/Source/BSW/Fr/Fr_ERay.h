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
 *         File:  Fr_ERay.h
 *      Project:  FlexRay Stack
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Public header containing typedefs for use by FlexRay driver
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
 *  03.00.02  2007-12-12  Jsr                   no changes
 *  03.00.03  2008-02-29  Jsr                   no changes
 *  03.00.04  2008-02-29  Jsr                   no changes
 *  03.00.05  2008-02-29  Jsr                   no changes
 *  03.00.06  2008-02-29  Jsr                   no changes
 *  03.00.07  2008-02-19  Jsr     ESCAN00024975
 *                                ESCAN00024950
 *                                ESCAN00024946
 *                                ESCAN00023416
 *                                ESCAN00024997 Rename of variable in Fr_GetNmVector
 *  03.00.08  2008-03-25  Jsr                   no changes
 *  03.00.09  2008-03-27  Alr                   no changes
 *  03.00.10  2008-04-03  Jsr                   New version
 *  03.00.11  2008-04-10  Jsr                   TMS470 added
 *  03.00.12  2008-04-14  Jsr                   Rename internal variables from VFRDRV_ to FR_V and vFrDrv_ to Fr_V
 *  03.01.00  2008-05-05  Jsr                   No changes
 *  03.01.01  2008-05-20  Jsr                   No changes
 *  03.02.00  2008-06-05  Seg     ESCAN00027381 missing selfdiag functions (ErrorFlag defines) 
 *                                ESCAN00027389 renamed CCREG_SWNIT_TBNB to CCREG_SWNIT_SBNB
 *  03.02.01  2008-06-24  Jsr     No changes
 *  03.03.00  2008-07-10  Jsr     No changes
 *                                ESCAN00025647
 *                                ESCAN00026728
 *                                ESCAN00027389
 *  03.04.00  2008-08-22  Seg     new version
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
 *                        Seg     ESCAN00031774 MISRA rework
 *                                ESCAN00031903 insufficient interrupt lock
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
#if (!defined FR_ERAY_H)
# define FR_ERAY_H

/**************************************************************************************************
* INCLUDES
**************************************************************************************************/
# include "Platform_Types.h"

/**************************************************************************************************
* DEFINES / CONSTANTS
**************************************************************************************************/

/* PRQA S 0857 EOF */ /* Misra rule 11.3. Standard justification for Macro usage in Fr */

/* register adress */
# define CCREG_CIF_0                             0x00000000UL
# define CCREG_CIF_1                             0x00000004UL
# define CCREG_CIF_2                             0x00000008UL
# define CCREG_CIF_3                             0x0000000CUL
/* ... special register */
# define CCREG_LCK                               0x0000001CUL
/* ... interrupt register */
# define CCREG_EIR                               0x00000020UL
# define CCREG_SIR                               0x00000024UL
# define CCREG_EILS                              0x00000028UL
# define CCREG_SILS                              0x0000002CUL
# define CCREG_EIES                              0x00000030UL
# define CCREG_EIER                              0x00000034UL
# define CCREG_SIES                              0x00000038UL
# define CCREG_SIER                              0x0000003CUL
# define CCREG_ILE                               0x00000040UL
# define CCREG_T0C                               0x00000044UL
# define CCREG_T1C                               0x00000048UL
# define CCREG_STPW1                             0x0000004CUL
# define CCREG_STPW2                             0x00000050UL
/* ... CC control register */
# define CCREG_SUCC1                             0x00000080UL
# define CCREG_SUCC2                             0x00000084UL
# define CCREG_SUCC3                             0x00000088UL
# define CCREG_NEMC                              0x0000008CUL
# define CCREG_PRTC1                             0x00000090UL
# define CCREG_PRTC2                             0x00000094UL
# define CCREG_MHDC                              0x00000098UL
# define CCREG_GTUC1                             0x000000A0UL
# define CCREG_GTUC2                             0x000000A4UL
# define CCREG_GTUC3                             0x000000A8UL
# define CCREG_GTUC4                             0x000000ACUL
# define CCREG_GTUC5                             0x000000B0UL
# define CCREG_GTUC6                             0x000000B4UL
# define CCREG_GTUC7                             0x000000B8UL
# define CCREG_GTUC8                             0x000000BCUL
# define CCREG_GTUC9                             0x000000C0UL
# define CCREG_GTUC10                            0x000000C4UL
# define CCREG_GTUC11                            0x000000C8UL
/* ... CC status register */
# define CCREG_CCSV                              0x00000100UL
# define CCREG_CCEV                              0x00000104UL
# define CCREG_SCV                               0x00000110UL
# define CCREG_MTCCV                             0x00000114UL
# define CCREG_RCV                               0x00000118UL
# define CCREG_OCV                               0x0000011CUL
# define CCREG_SFS                               0x00000120UL
# define CCREG_SWNIT                             0x00000124UL
# define CCREG_ACS                               0x00000128UL
# define CCREG_ESIDn                             0x00000130UL
# define CCREG_ESID1                             0x00000130UL
# define CCREG_ESID2                             0x00000134UL
# define CCREG_ESID3                             0x00000138UL
# define CCREG_ESID4                             0x0000013CUL
# define CCREG_ESID5                             0x00000140UL
# define CCREG_ESID6                             0x00000144UL
# define CCREG_ESID7                             0x00000148UL
# define CCREG_ESID8                             0x0000014CUL
# define CCREG_ESID9                             0x00000150UL
# define CCREG_ESID10                            0x00000154UL
# define CCREG_ESID11                            0x00000158UL
# define CCREG_ESID12                            0x0000015CUL
# define CCREG_ESID13                            0x00000160UL
# define CCREG_ESID14                            0x00000164UL
# define CCREG_ESID15                            0x00000168UL
# define CCREG_OSIDn                             0x00000170UL
# define CCREG_OSID1                             0x00000170UL
# define CCREG_OSID2                             0x00010174UL
# define CCREG_OSID3                             0x00020178UL
# define CCREG_OSID4                             0x0003017CUL
# define CCREG_OSID5                             0x00040180UL
# define CCREG_OSID6                             0x00050184UL
# define CCREG_OSID7                             0x00060188UL
# define CCREG_OSID8                             0x0007018CUL
# define CCREG_OSID9                             0x00080190UL
# define CCREG_OSID10                            0x00090194UL
# define CCREG_OSID11                            0x00100198UL
# define CCREG_OSID12                            0x0011019CUL
# define CCREG_OSID13                            0x001201A0UL
# define CCREG_OSID14                            0x001301A4UL
# define CCREG_OSID15                            0x000001A8UL
# define CCREG_NMVn                              0x000001B0UL
# define CCREG_NMV1                              0x000001B0UL
# define CCREG_NMV2                              0x000001B4UL
# define CCREG_NMV3                              0x000001B8UL
/* ... message buffer control register */
# define CCREG_MRC                               0x00000300UL
# define CCREG_FRF                               0x00000304UL
# define CCREG_FRFM                              0x00000308UL
# define CCREG_FCL                               0x0000030CUL
/* ... message buffer status register */
# define CCREG_MHDS                              0x0000031CUL
# define CCREG_LDTS                              0x00000314UL
# define CCREG_FSR                               0x00000318UL
# define CCREG_TXRQn                             0x00000320UL
# define CCREG_NDATn                             0x00000330UL
# define CCREG_MBSCn                             0x00000340UL
/* ... identification register */
# define CCREG_CREL                              0x000003F0UL
# define CCREG_ENDN                              0x000003F4UL
/* ... input buffer register */
# define CCREG_WRDSn                             0x00000400UL
# define CCREG_WRHS1                             0x00000500UL
# define CCREG_WRHS2                             0x00000504UL
# define CCREG_WRHS3                             0x00000508UL
# define CCREG_IBCM                              0x00000510UL
# define CCREG_IBCR                              0x00000514UL
/* ... output buffer register */
# define CCREG_RDDSn                             0x00000600UL
# define CCREG_RDHS1                             0x00000700UL
# define CCREG_RDHS2                             0x00000704UL
# define CCREG_RDHS3                             0x00000708UL
# define CCREG_MBS                               0x0000070CUL
# define CCREG_OBCM                              0x00000710UL
# define CCREG_OBCR                              0x00000714UL

/*********************************** Register CIF_2 *******************************************/
# define CCREG_CIF_2_CSLK_FIRST_MASK             ((uint32) 0x67000000)
# define CCREG_CIF_2_CSLK_SECOND_MASK            ((uint32) 0x98000000)

/*********************************** Register LCK ********************************************/
# define CCREG_LCK_CLK_MASK                      ((uint32) 0x000000FF)
# define CCREG_LCK_CLK_SHIFT                     0
# define CCREG_LCK_CLK_KEY1                      ((uint32) 0x000000CE)
# define CCREG_LCK_CLK_KEY2                      ((uint32) 0x00000031)
# define CCREG_LCK_TMK_MASK                      ((uint32) 0x000000FF)
# define CCREG_LCK_TMK_SHIFT                     8

/*********************************** Register EIR ********************************************/
# define CCREG_EIR_PEMC                                    ((uint32) (0x00000001 << 0) )
# define CCREG_EIR_CNA                                     ((uint32) (0x00000001 << 1) )
# define CCREG_EIR_SFBM                                    ((uint32) (0x00000001 << 2) )
# define CCREG_EIR_SFO                                     ((uint32) (0x00000001 << 3) )
# define CCREG_EIR_CCF                                     ((uint32) (0x00000001 << 4) )
# define CCREG_EIR_CCL                                     ((uint32) (0x00000001 << 5) )
# define CCREG_EIR_PERR                                    ((uint32) (0x00000001 << 6) )
# define CCREG_EIR_RFO_EIR                                 ((uint32) (0x00000001 << 7) )
# define CCREG_EIR_EFA                                     ((uint32) (0x00000001 << 8) )
# define CCREG_EIR_HBA                                     ((uint32) (0x00000001 << 9) )
# define CCREG_EIR_IOBA                                    ((uint32) (0x00000001 << 10))
# define CCREG_EIR_MHF                                     ((uint32) (0x00000001 << 11))
# define CCREG_EIR_EDA                                     ((uint32) ((uint32)0x00000001 << 16))
# define CCREG_EIR_LTVA                                    ((uint32) ((uint32)0x00000001 << 17))
# define CCREG_EIR_TABA                                    ((uint32) ((uint32)0x00000001 << 18))
# define CCREG_EIR_EDB                                     ((uint32) ((uint32)0x00000001 << 24))
# define CCREG_EIR_LTVB                                    ((uint32) ((uint32)0x00000001 << 25))
# define CCREG_EIR_TABB                                    ((uint32) ((uint32)0x00000001 << 26))

/*********************************** Register SIR ********************************************/
# define CCREG_SIR_WST                                     ((uint32) (0x00000001 << 0) )
# define CCREG_SIR_CAS                                     ((uint32) (0x00000001 << 1) )
# define CCREG_SIR_CYCS                                    ((uint32) (0x00000001 << 2) )
# define CCREG_SIR_TXI                                     ((uint32) (0x00000001 << 3) )
# define CCREG_SIR_RXI                                     ((uint32) (0x00000001 << 4) )
# define CCREG_SIR_RFNE                                    ((uint32) (0x00000001 << 5) )
# define CCREG_SIR_RFCL                                    ((uint32) (0x00000001 << 6) )
# define CCREG_SIR_NMVC                                    ((uint32) (0x00000001 << 7) )
# define CCREG_SIR_TI0                                     ((uint32) (0x00000001 << 8) )
# define CCREG_SIR_TI1                                     ((uint32) (0x00000001 << 9) )
# define CCREG_SIR_TIBC                                    ((uint32) (0x00000001 << 10))
# define CCREG_SIR_TOBC                                    ((uint32) (0x00000001 << 11))
# define CCREG_SIR_SWE                                     ((uint32) (0x00000001 << 12))
# define CCREG_SIR_SUCS                                    ((uint32) (0x00000001 << 13))
# define CCREG_SIR_MBSI                                    ((uint32) (0x00000001 << 14))
# define CCREG_SIR_SDS                                     ((uint32) (0x00000001 << 15))
# define CCREG_SIR_WUPA                                    ((uint32) ((uint32)0x00000001 << 16))
# define CCREG_SIR_MTSA                                    ((uint32) ((uint32)0x00000001 << 17))
# define CCREG_SIR_WUPB                                    ((uint32) ((uint32)0x00000001 << 25))
# define CCREG_SIR_MTSB                                    ((uint32) ((uint32)0x00000001 << 26))

/*********************************** Register EILS ********************************************/
# define CCREG_EILS_PEMCL                                   ((uint32) (0x00000001 << 0) )
# define CCREG_EILS_CNAL                                    ((uint32) (0x00000001 << 1) )
# define CCREG_EILS_SFBML                                   ((uint32) (0x00000001 << 2) )
# define CCREG_EILS_SFOL                                    ((uint32) (0x00000001 << 3) )
# define CCREG_EILS_CCFL                                    ((uint32) (0x00000001 << 4) )
# define CCREG_EILS_CCLL                                    ((uint32) (0x00000001 << 5) )
# define CCREG_EILS_PERRL                                   ((uint32) (0x00000001 << 6) )
# define CCREG_EILS_RFOL                                    ((uint32) (0x00000001 << 7) )
# define CCREG_EILS_EFAL                                    ((uint32) (0x00000001 << 8) )
# define CCREG_EILS_IIBAL                                   ((uint32) (0x00000001 << 9) )
# define CCREG_EILS_IOBAL                                   ((uint32) (0x00000001 << 10))
# define CCREG_EILS_MHFL                                    ((uint32) (0x00000001 << 11))
# define CCREG_EILS_EDAL                                    ((uint32) ((uint32)0x00000001 << 16))
# define CCREG_EILS_LTVAL                                   ((uint32) ((uint32)0x00000001 << 17))
# define CCREG_EILS_TABAL                                   ((uint32) ((uint32)0x00000001 << 18))
# define CCREG_EILS_EDBL                                    ((uint32) ((uint32)0x00000001 << 24))
# define CCREG_EILS_LTVBL                                   ((uint32) ((uint32)0x00000001 << 25))
# define CCREG_EILS_TABBL                                   ((uint32) ((uint32)0x00000001 << 26))

/*********************************** Register SILS ********************************************/
# define CCREG_SILS_WSTL                                    ((uint32) (0x00000001 << 0) )
# define CCREG_SILS_CASL                                    ((uint32) (0x00000001 << 1) )
# define CCREG_SILS_CYCSL                                   ((uint32) (0x00000001 << 2) )
# define CCREG_SILS_TXIL                                    ((uint32) (0x00000001 << 3) )
# define CCREG_SILS_RXIL                                    ((uint32) (0x00000001 << 4) )
# define CCREG_SILS_RFNEL                                   ((uint32) (0x00000001 << 5) )
# define CCREG_SILS_RFCCL                                   ((uint32) (0x00000001 << 6) )
# define CCREG_SILS_NMVCL                                   ((uint32) (0x00000001 << 7) )
# define CCREG_SILS_TI0L                                    ((uint32) (0x00000001 << 8) )
# define CCREG_SILS_TI1L                                    ((uint32) (0x00000001 << 9) )
# define CCREG_SILS_TIBCL                                   ((uint32) (0x00000001 << 10))
# define CCREG_SILS_TOBCL                                   ((uint32) (0x00000001 << 11))
# define CCREG_SILS_SWEL                                    ((uint32) (0x00000001 << 12))
# define CCREG_SILS_SUCSL                                   ((uint32) (0x00000001 << 13))
# define CCREG_SILS_MBSIL                                   ((uint32) (0x00000001 << 14))
# define CCREG_SILS_SDSL                                    ((uint32) (0x00000001 << 15))
# define CCREG_SILS_WUPAL                                   ((uint32) ((uint32)0x00000001 << 16))
# define CCREG_SILS_MTSAL                                   ((uint32) ((uint32)0x00000001 << 17))
# define CCREG_SILS_WUPBL                                   ((uint32) ((uint32)0x00000001 << 24))
# define CCREG_SILS_MTSBL                                   ((uint32) ((uint32)0x00000001 << 25))

/*********************************** Register EIES/EIER **************************************/
# define CCREG_EIES_PEMCE                                   ((uint32) (0x00000001 << 0) )
# define CCREG_EIES_CNAE                                    ((uint32) (0x00000001 << 1) )
# define CCREG_EIES_SFBME                                   ((uint32) (0x00000001 << 2) )
# define CCREG_EIES_SFOE                                    ((uint32) (0x00000001 << 3) )
# define CCREG_EIES_CCFE                                    ((uint32) (0x00000001 << 4) )
# define CCREG_EIES_PERRE                                   ((uint32) (0x00000001 << 5) )
# define CCREG_EIES_RFOE                                    ((uint32) (0x00000001 << 6) )
# define CCREG_EIES_EFAE                                    ((uint32) (0x00000001 << 7) )
# define CCREG_EIES_IIBAE                                   ((uint32) (0x00000001 << 8) )
# define CCREG_EIES_IOBAE                                   ((uint32) (0x00000001 << 9) )
# define CCREG_EIES_MHFE                                    ((uint32) (0x00000001 << 11))
# define CCREG_EIES_EDAE                                    ((uint32) ((uint32)0x00000001 << 16))
# define CCREG_EIES_LTVAE                                   ((uint32) ((uint32)0x00000001 << 17))
# define CCREG_EIES_TABAE                                   ((uint32) ((uint32)0x00000001 << 18))
# define CCREG_EIES_EDBE                                    ((uint32) ((uint32)0x00000001 << 24))
# define CCREG_EIES_LTVBE                                   ((uint32) ((uint32)0x00000001 << 25))
# define CCREG_EIES_TABBE                                   ((uint32) ((uint32)0x00000001 << 26))

/*********************************** Register SIES/SIER ********************************************/
# define CCREG_SIES_WSTE                                    ((uint32) (0x00000001 << 0) )
# define CCREG_SIES_CASE                                    ((uint32) (0x00000001 << 1) )
# define CCREG_SIES_CYCSE                                   ((uint32) (0x00000001 << 2) )
# define CCREG_SIES_TXIE                                    ((uint32) (0x00000001 << 3) )
# define CCREG_SIES_RXIE                                    ((uint32) (0x00000001 << 4) )
# define CCREG_SIES_RFNEE                                   ((uint32) (0x00000001 << 5) )
# define CCREG_SIES_RFFE                                    ((uint32) (0x00000001 << 6) )
# define CCREG_SIES_NMVCE                                   ((uint32) (0x00000001 << 7) )
# define CCREG_SIES_TI0E                                    ((uint32) (0x00000001 << 8) )
# define CCREG_SIES_TI1E                                    ((uint32) (0x00000001 << 9) )
# define CCREG_SIES_TIBCE                                   ((uint32) (0x00000001 << 10))
# define CCREG_SIES_TOBCE                                   ((uint32) (0x00000001 << 11))
# define CCREG_SIES_SWEE                                    ((uint32) (0x00000001 << 12))
# define CCREG_SIES_SUCSE                                   ((uint32) (0x00000001 << 13))
# define CCREG_SIES_MBSIE                                   ((uint32) (0x00000001 << 14))
# define CCREG_SIES_SDSE                                    ((uint32) (0x00000001 << 15))
# define CCREG_SIES_WUPAE                                   ((uint32) ((uint32)0x00000001 << 16))
# define CCREG_SIES_MTSAE                                   ((uint32) ((uint32)0x00000001 << 17))
# define CCREG_SIES_WUPBE                                   ((uint32) ((uint32)0x00000001 << 24))
# define CCREG_SIES_MTSBE                                   ((uint32) ((uint32)0x00000001 << 25))

/*********************************** Register ILE ********************************************/
# define CCREG_ILE_EINT0_ILE                               ((uint32) (0x00000001 << 0))
# define CCREG_ILE_EINT1_ILE                               ((uint32) (0x00000001 << 1))

/*********************************** Register T0C ********************************************/
# define CCREG_T0C_T0RC                                    ((uint32) (0x00000001 << 0))
# define CCREG_T0C_T0MS                                    ((uint32) (0x00000001 << 1))
# define CCREG_T0C_T0CC_MASK                               ((uint32) 0x0000007F)
# define CCREG_T0C_T0CC_SHIFT                              8
# define CCREG_T0C_T0MO_MASK                               ((uint32) 0x00003FFF)
# define CCREG_T0C_T0MO_SHIFT                              16

/*********************************** Register T1C ********************************************/
# define CCREG_T1C_T1RC                                    ((uint32) (0x00000001 << 0))
# define CCREG_T1C_T1MS                                    ((uint32) (0x00000001 << 1))
# define CCREG_T1C_T1MO_MASK                               ((uint32) 0x00003FFF)
# define CCREG_T1C_T1MO_SHIFT                              16

/*********************************** Register STPW1 ********************************************/
# define CCREG_STPW1_ESWT                                    ((uint32) (0x00000001 << 0))
# define CCREG_STPW1_SWMS                                    ((uint32) (0x00000001 << 1))
# define CCREG_STPW1_EDGE                                    ((uint32) (0x00000001 << 2))
# define CCREG_STPW1_SSWT                                    ((uint32) (0x00000001 << 3))
# define CCREG_STPW1_EETP                                    ((uint32) (0x00000001 << 4))
# define CCREG_STPW1_EINT0_STPW1                             ((uint32) (0x00000001 << 5))
# define CCREG_STPW1_EINT1_STPW1                             ((uint32) (0x00000001 << 6))
# define CCREG_STPW1_SCCV_MASK                               ((uint32) (0x0000003F)     )
# define CCREG_STPW1_SCCV_SHIFT                              8
# define CCREG_STPW1_SMTV0_MASK                              ((uint32) 0x00003FFF)
# define CCREG_STPW1_SMTV0_SHIFT                             16

/*********************************** Register STPW2 ********************************************/
# define CCREG_STPW2_SSCVA_MASK                              ((uint32) 0x000007FF)
# define CCREG_STPW2_SSCVA_SHIFT                             0
# define CCREG_STPW2_SSCVB_MASK                              ((uint32) 0x000007FF)
# define CCREG_STPW2_SSCVB_SHIFT                             16

/************************************** Register SUCC1 **************************************/
# define CCREG_SUCC1_CMD_MASK                                ((uint32) 0x0000000F)
# define CCREG_SUCC1_CMD_SHIFT                               0
# define CCCMD_CNA                                           ((uint32) 0x00000000)
# define CCCMD_CONFIG                                        ((uint32) 0x00000001)
# define CCCMD_READY                                         ((uint32) 0x00000002)
# define CCCMD_WAKEUP                                        ((uint32) 0x00000003)
# define CCCMD_RUN                                           ((uint32) 0x00000004)
# define CCCMD_ALL_SLOTS                                     ((uint32) 0x00000005)
# define CCCMD_HALT                                          ((uint32) 0x00000006)
# define CCCMD_FREEZE                                        ((uint32) 0x00000007)
# define CCCMD_SEND_MTS                                      ((uint32) 0x00000008)
# define CCCMD_ALLOW_COLDSTART                               ((uint32) 0x00000009)
# define CCCMD_RESET_STATUS_INDICATORS                       ((uint32) 0x0000000A)
# define CCCMD_MONITOR_MODE                                  ((uint32) 0x0000000B)
# define CCCMD_CLEAR_RAMS                                    ((uint32) 0x0000000C)
# define CCREG_SUCC1_PBSY                                    ((uint32) (0x00000001 << 7))
# define CCREG_SUCC1_TXST                                    ((uint32) (0x00000001 << 8))
# define CCREG_SUCC1_TXSY                                    ((uint32) (0x00000001 << 9))
# define CCREG_SUCC1_CSA_MASK                                ((uint32) 0x0000F800)
# define CCREG_SUCC1_CSA_SHIFT                               11
# define CCREG_SUCC1_PTA_MASK                                ((uint32) 0x001F0000)
# define CCREG_SUCC1_PTA_SHIFT                               16
# define CCREG_SUCC1_WUCS                                    ((uint32) ((uint32)0x00000001 << 21))
# define CCREG_SUCC1_TSM                                     ((uint32) ((uint32)0x00000001 << 22))
# define CCREG_SUCC1_HCSE                                    ((uint32) ((uint32)0x00000001 << 23))
# define CCREG_SUCC1_MTSA                                    ((uint32) ((uint32)0x00000001 << 24))
# define CCREG_SUCC1_MTSB                                    ((uint32) ((uint32)0x00000001 << 25))
# define CCREG_SUCC1_CCHA                                    ((uint32) ((uint32)0x00000001 << 26))
# define CCREG_SUCC1_CCHB                                    ((uint32) ((uint32)0x00000001 << 27))

/************************************** Register SUCC2 **************************************/
# define CCREG_SUCC2_LT_MASK                                 ((uint32) 0x001FFFFF)
# define CCREG_SUCC2_LT_SHIFT                                0
# define CCREG_SUCC2_LTN_MASK                                ((uint32) 0x0F000000)
# define CCREG_SUCC2_LTN_SHIFT                               24

/************************************** Register SUCC3 **************************************/
# define CCREG_SUCC3_WCP_MASK                                ((uint32) 0x0000000F)
# define CCREG_SUCC3_WCP_SHIFT                               0
# define CCREG_SUCC3_WCF_MASK                                ((uint32) 0x000000F0)
# define CCREG_SUCC3_WCF_SHIFT                               4

/************************************** Register NEMC **************************************/
# define CCREG_NEMC_NML_MASK                                ((uint32) 0x0000000F)
# define CCREG_NEMC_NML_SHIFT                               0

/************************************** Register PRTC1 **************************************/
# define CCREG_PRTC1_TSST_MASK                               ((uint32) 0x0000000F)
# define CCREG_PRTC1_TSST_SHIFT                              0
# define CCREG_PRTC1_CASM_MASK                               ((uint32) 0x000007F0)
# define CCREG_PRTC1_CASM_SHIFT                              4
# define CCREG_PRTC1_SPP_MASK                                ((uint32) 0x00003000)
# define CCREG_PRTC1_SPP_SHIFT                               12
# define CCREG_PRTC1_BRP_MASK                                ((uint32) 0x0000C000)
# define CCREG_PRTC1_BRP_SHIFT                               14
# define CCREG_PRTC1_RXW_MASK                                ((uint32) 0x01FF0000)
# define CCREG_PRTC1_RXW_SHIFT                               16
# define CCREG_PRTC1_RWP_MASK                                ((uint32) 0xFC000000)
# define CCREG_PRTC1_RWP_SHIFT                               26

/************************************** Register PRTC2 **************************************/
# define CCREG_PRTC2_RXI_MASK                                ((uint32) 0x0000003F)
# define CCREG_PRTC2_RXI_SHIFT                               0
# define CCREG_PRTC2_RXL_MASK                                ((uint32) 0x00003F00)
# define CCREG_PRTC2_RXL_SHIFT                               8
# define CCREG_PRTC2_TXI_MASK                                ((uint32) 0x00FF0000)
# define CCREG_PRTC2_TXI_SHIFT                               16
# define CCREG_PRTC2_TXL_MASK                                ((uint32) 0x3F000000)
# define CCREG_PRTC2_TXL_SHIFT                               24

/************************************** Register MHDC **************************************/
# define CCREG_MHDC_SFDL_MASK                               ((uint32) 0x0000007F)
# define CCREG_MHDC_SFDL_SHIFT                              0
# define CCREG_MHDC_SLT_MASK                                ((uint32) 0x1FFF0000)
# define CCREG_MHDC_SLT_SHIFT                               16

/************************************** Register GTUC1 **************************************/
# define CCREG_GTUC1_UT_MASK                                 ((uint32) 0x000FFFFF)
# define CCREG_GTUC1_UT_SHIFT                                0

/************************************** Register GTUC2 **************************************/
# define CCREG_GTUC2_MPC_MASK                                ((uint32) 0x00003FFF)
# define CCREG_GTUC2_MPC_SHIFT                               0
# define CCREG_GTUC2_SNM_MASK                                ((uint32) 0x000F0000)
# define CCREG_GTUC2_SNM_SHIFT                               16

/************************************** Register GTUC3 **************************************/
# define CCREG_GTUC3_UIOA_MASK                               ((uint32) 0x000000FF)
# define CCREG_GTUC3_UIOA_SHIFT                              0
# define CCREG_GTUC3_UIOB_MASK                               ((uint32) 0x0000FF00)
# define CCREG_GTUC3_UIOB_SHIFT                              8
# define CCREG_GTUC3_MIOA_MASK                               ((uint32) 0x007F0000)
# define CCREG_GTUC3_MIOA_SHIFT                              16
# define CCREG_GTUC3_MIOB_MASK                               ((uint32) 0x7F000000)
# define CCREG_GTUC3_MIOB_SHIFT                              24

/************************************** Register GTUC4 **************************************/
# define CCREG_GTUC4_NIT_MASK                                ((uint32) 0x00003FFF)
# define CCREG_GTUC4_NIT_SHIFT                               0
# define CCREG_GTUC4_OCS_MASK                                ((uint32) 0x3FFF0000)
# define CCREG_GTUC4_OCS_SHIFT                               16

/************************************** Register GTUC5 **************************************/
# define CCREG_GTUC5_DCA_MASK                                ((uint32) 0x000000FF)
# define CCREG_GTUC5_DCA_SHIFT                               0
# define CCREG_GTUC5_DCB_MASK                                ((uint32) 0x0000FF00)
# define CCREG_GTUC5_DCB_SHIFT                               8
# define CCREG_GTUC5_CDD_MASK                                ((uint32) 0x001F0000)
# define CCREG_GTUC5_CDD_SHIFT                               16
# define CCREG_GTUC5_DEC_MASK                                ((uint32) 0xFF000000)
# define CCREG_GTUC5_DEC_SHIFT                               24

/************************************** Register GTUC6 **************************************/
# define CCREG_GTUC6_ASR_MASK                                ((uint32) 0x000007FF)
# define CCREG_GTUC6_ASR_SHIFT                               0
# define CCREG_GTUC6_MOD_MASK                                ((uint32) 0x07FF0000)
# define CCREG_GTUC6_MOD_SHIFT                               16

/************************************** Register GTUC7 **************************************/
# define CCREG_GTUC7_SSL_MASK                                ((uint32) 0x000003FF)
# define CCREG_GTUC7_SSL_SHIFT                               0
# define CCREG_GTUC7_NSS_MASK                                ((uint32) 0x03FF0000)
# define CCREG_GTUC7_NSS_SHIFT                               16

/************************************** Register GTUC8 **************************************/
# define CCREG_GTUC8_MSL_MASK                                ((uint32) 0x0000003F)
# define CCREG_GTUC8_MSL_SHIFT                               0
# define CCREG_GTUC8_NMS_MASK                                ((uint32) 0x1FFF0000)
# define CCREG_GTUC8_NMS_SHIFT                               16

/************************************** Register GTUC9 **************************************/
# define CCREG_GTUC9_APO_MASK                                ((uint32) 0x0000003F)
# define CCREG_GTUC9_APO_SHIFT                               0
# define CCREG_GTUC9_MAPO_MASK                               ((uint32) 0x00001F00)
# define CCREG_GTUC9_MAPO_SHIFT                              8
# define CCREG_GTUC9_DSI_MASK                                ((uint32) 0x00030000)
# define CCREG_GTUC9_DSI_SHIFT                               16

/************************************** Register GTUC10 **************************************/
# define CCREG_GTUC10_MOC_MASK                                ((uint32) 0x00003FFF)
# define CCREG_GTUC10_MOC_SHIFT                               0
# define CCREG_GTUC10_MCR_MASK                                ((uint32) 0x07FF0000)
# define CCREG_GTUC10_MCR_SHIFT                               16

/************************************** Register GTUC11 **************************************/
# define CCREG_GTUC11_EOCC_NONE                               ((uint32) 0x00000000)
# define CCREG_GTUC11_EOCC_DEC                                ((uint32) 0x00000002)
# define CCREG_GTUC11_EOCC_INC                                ((uint32) 0x00000003)
# define CCREG_GTUC11_EOCC_MASK                               ((uint32) 0x00000003)
# define CCREG_GTUC11_EOCC_SHIFT                              0
# define CCREG_GTUC11_ERCC_NONE                               ((uint32) 0x00000000)
# define CCREG_GTUC11_ERCC_DEC                                ((uint32) 0x00000002)
# define CCREG_GTUC11_ERCC_INC                                ((uint32) 0x00000003)
# define CCREG_GTUC11_ERCC_MASK                               ((uint32) 0x00000003)
# define CCREG_GTUC11_ERCC_SHIFT                              0
# define CCREG_GTUC11_EOC_MASK                                ((uint32) 0x00070000)
# define CCREG_GTUC11_EOC_SHIFT                               16
# define CCREG_GTUC11_ERC_MASK                                ((uint32) 0x07000000)
# define CCREG_GTUC11_ERC_SHIFT                               24

/************************************** Register CCSV ***************************************/
# define CCREG_CCSV_POCS_MASK                               ((uint32) 0x0000003F)
# define CCREG_CCSV_POCS_VALUE_MASK                         ((uint32) 0x0000000F)
# define CCREG_CCSV_POCS_SHIFT                              (0)
# define CCPOCS_DEFAULT_CONFIG                              ((uint32) 0x00000000)
# define CCPOCS_READY                                       ((uint32) 0x00000001)
# define CCPOCS_NORMAL_ACTIVE                               ((uint32) 0x00000002)
# define CCPOCS_NORMAL_PASSIVE                              ((uint32) 0x00000003)
# define CCPOCS_HALT                                        ((uint32) 0x00000004)
# define CCPOCS_MONITOR_MODE                                ((uint32) 0x00000005)
# define CCPOCS_CONFIG                                      ((uint32) 0x0000000F)
# define CCPOCS_WAKEUP_GROUP                                ((uint32) 0x00000010)
# define CCPOCS_WAKEUP_STANDBY                              ((uint32) 0x00000010)
# define CCPOCS_WAKEUP_LISTEN                               ((uint32) 0x00000011)
# define CCPOCS_WAKEUP_SEND                                 ((uint32) 0x00000012)
# define CCPOCS_WAKEUP_DETECT                               ((uint32) 0x00000013)
# define CCPOCS_STARTUP_GROUP                               ((uint32) 0x00000020)
# define CCPOCS_STARTUP_PREPARE                             ((uint32) 0x00000020)
# define CCPOCS_COLDSTART_LISTEN                            ((uint32) 0x00000021)
# define CCPOCS_COLDSTART_COLLISION_RESOLUTION              ((uint32) 0x00000022)
# define CCPOCS_COLDSTART_CONSISTENCY_CHECK                 ((uint32) 0x00000023)
# define CCPOCS_COLDSTART_GAP                               ((uint32) 0x00000024)
# define CCPOCS_COLDSTART_JOIN                              ((uint32) 0x00000025)
# define CCPOCS_INTEGRATION_COLDSTART_CHECK                 ((uint32) 0x00000026)
# define CCPOCS_INTEGRATION_LISTEN                          ((uint32) 0x00000027)
# define CCPOCS_INTEGRATION_CONSISTENCY_CHECK               ((uint32) 0x00000028)
# define CCPOCS_INITIALIZE_SCHEDULE                         ((uint32) 0x00000029)
# define CCPOCS_ABORT_STARTUP                               ((uint32) 0x0000002A)
# define CCPOCS_GROUP_MASK                                  ((uint32) 0x00000030)
# define CCPOCS_GROUP_SHIFT                                 (4u)
# define CCREG_CCSV_FSI                                     ((uint32) (0x00000001 << 6))
# define CCREG_CCSV_HRQ                                     ((uint32) (0x00000001 << 7))
# define CCREG_CCSV_SLM_MASK                                ((uint32) 0x00000300)
# define CCREG_CCSV_SLM_SHIFT                               8
# define CCREG_CCSV_SLM_SINGLE                              ((uint32) 0x00000000)
# define CCREG_CCSV_SLM_ALL_PENDING                         ((uint32) 0x00000002)
# define CCREG_CCSV_SLM_ALL                                 ((uint32) 0x00000003)
# define CCREG_CCSV_CSNI                                    ((uint32) (0x00000001 << 12))
# define CCREG_CCSV_CSAI                                    ((uint32) (0x00000001 << 13))
# define CCREG_CCSV_CSI                                     ((uint32) (0x00000001 << 14))
# define CCREG_CCSV_WSV_MASK                                ((uint32) 0x00070000)
# define CCREG_CCSV_WSV_SHIFT                               16
# define CCREG_CCSV_RCA_MASK                                ((uint32) 0x00F80000)
# define CCREG_CCSV_RCA_SHIFT                               19
# define CCREG_CCSV_PLS_MASK                                ((uint32) 0x3F000000)
# define CCREG_CCSV_PLS_SHIFT                               24

/************************************** Register CCEV ***************************************/
# define CCREG_CCEV_CCFC_MASK                               ((uint32) 0x0000000F)
# define CCREG_CCEV_CCFC_SHIFT                              0
# define CCREG_CCEV_ERRM_MASK                               ((uint32) 0x000000C0)
# define CCREG_CCEV_ERRM_SHIFT                              6
# define CCREG_CCEV_ERRM_ACTIVE                             ((uint32) 0x00000000)
# define CCREG_CCEV_ERRM_PASSIVE                            ((uint32) 0x00000001)
# define CCREG_CCEV_ERRM_COMM_HALT                          ((uint32) 0x00000002)
# define CCREG_CCEV_PTAC_MASK                               ((uint32) 0x00001F00)
# define CCREG_CCEV_PTAC_SHIFT                              8

/************************************** Register SCV ***************************************/
# define CCREG_SCV_SCCA_MASK                               ((uint32) 0x000007FF)
# define CCREG_SCV_SCCA_SHIFT                              0
# define CCREG_SCV_SCCB_MASK                               ((uint32) 0x07FF0000)
# define CCREG_SCV_SCCB_SHIFT                              16

/************************************** Register MTCCV ***************************************/
# define CCREG_MTCCV_MTV_MASK                              ((uint32) 0x00003FFF)
# define CCREG_MTCCV_MTV_SHIFT                             0
# define CCREG_MTCCV_CCV_MASK                              ((uint32) 0x003F0000)
# define CCREG_MTCCV_CCV_SHIFT                             16

/************************************** Register RCV ***************************************/
# define CCREG_RCV_MASK                                    ((uint32) 0x00000FFF)
# define CCREG_RCV_SHIFT                                   0

/************************************** Register OCV ***************************************/
# define CCREGVAL_OCV_MASK                                 ((uint32) 0x0007FFFF)
# define CCREGVAL_OCV_SHIFT                                0

/************************************** Register SFS ***************************************/
# define CCREG_SFS_VSAE_MASK                               ((uint32) 0x0000000F)
# define CCREG_SFS_VSAE_SHIFT                              0
# define CCREG_SFS_VSAO_MASK                               ((uint32) 0x000000F0)
# define CCREG_SFS_VSAO_SHIFT                              4
# define CCREG_SFS_VSBE_MASK                               ((uint32) 0x00000F00)
# define CCREG_SFS_VSBE_SHIFT                              8
# define CCREG_SFS_VSBO_MASK                               ((uint32) 0x0000F000)
# define CCREG_SFS_VSBO_SHIFT                              12
# define CCREG_SFS_MOCS                                    ((uint32) (0x00000001 << 16))
# define CCREG_SFS_OCLR                                    ((uint32) (0x00000001 << 17))
# define CCREG_SFS_MRCS                                    ((uint32) (0x00000001 << 18))
# define CCREG_SFS_RCLR                                    ((uint32) (0x00000001 << 19))

/************************************** Register SWNIT ************************************/
# define CCREG_SWNIT_SESA                                    ((uint32) (0x00000001 << 0) )
# define CCREG_SWNIT_SBSA                                    ((uint32) (0x00000001 << 1) )
# define CCREG_SWNIT_TCSA                                    ((uint32) (0x00000001 << 2) )
# define CCREG_SWNIT_SESB                                    ((uint32) (0x00000001 << 3) )
# define CCREG_SWNIT_SBSB                                    ((uint32) (0x00000001 << 4) )
# define CCREG_SWNIT_TCSB                                    ((uint32) (0x00000001 << 5) )
# define CCREG_SWNIT_MTSA_SFS                                ((uint32) (0x00000001 << 6) )
# define CCREG_SWNIT_MTSB_SFS                                ((uint32) (0x00000001 << 7) )
# define CCREG_SWNIT_SENA                                    ((uint32) (0x00000001 << 8) )
# define CCREG_SWNIT_SBNA                                    ((uint32) (0x00000001 << 9) )
# define CCREG_SWNIT_SENB                                    ((uint32) (0x00000001 << 10))
# define CCREG_SWNIT_SBNB                                    ((uint32) (0x00000001 << 11))
# define CCREG_SWNIT_WIN_A_SHIFT                             ((uint8) 0x00)
# define CCREG_SWNIT_WIN_B_SHIFT                             ((uint8) 0x03)
# define CCREG_SWNIT_MTSA_SFS_SHIFT                          ((uint8) 0x06)
# define CCREG_SWNIT_MTSB_SFS_SHIFT                          ((uint8) 0x07)
# define CCREG_SWNIT_SENA_SHIFT                              ((uint8) 0x08)
# define CCREG_SWNIT_SENB_SHIFT                              ((uint8) 0x0A)
/************************************** Register ACS ***************************************/
# define CCREG_ACS_VFRA                                    ((uint32) (0x00000001 << 0) )
# define CCREG_ACS_SEDA                                    ((uint32) (0x00000001 << 1) )
# define CCREG_ACS_CEDA                                    ((uint32) (0x00000001 << 2) )
# define CCREG_ACS_CIA                                     ((uint32) (0x00000001 << 3) )
# define CCREG_ACS_SBVA                                    ((uint32) (0x00000001 << 4) )
# define CCREG_ACS_VFRB                                    ((uint32) (0x00000001 << 8) )
# define CCREG_ACS_SEDB                                    ((uint32) (0x00000001 << 9) )
# define CCREG_ACS_CEDB                                    ((uint32) (0x00000001 << 10))
# define CCREG_ACS_CIB                                     ((uint32) (0x00000001 << 11))
# define CCREG_ACS_SBVB                                    ((uint32) (0x00000001 << 12))

# define CCREG_CCREG_ACS_VFRA_SHIFT                        ((uint8) 0x00)
# define CCREG_CCREG_ACS_VFRB_SHIFT                        ((uint8) 0x08)
# define CCREG_CCREG_ACS_MASK                              ((uint32) 0x0000FFFF )

/************************************** Register ESIDn ***************************************/
# define CCREG_ESIDn_EID_MASK                                ((uint32) 0x000003FF)
# define CCREG_ESIDn_EID_SHIFT                               0
# define CCREG_ESIDn_RXEA                                    ((uint32) (0x00000001 << 14))
# define CCREG_ESIDn_RXEB                                    ((uint32) (0x00000001 << 15))
# define CCREG_ESIDn_NUMBER                                  ((uint8) 15)

/************************************** Register OSIDn ***************************************/
# define CCREG_OSIDn_OID_MASK                                ((uint32) 0x000003FF)
# define CCREG_OSIDn_OID_SHIFT                               0
# define CCREG_OSIDn_RXOA                                    ((uint32) (0x00000001 << 14))
# define CCREG_OSIDn_RXOB                                    ((uint32) (0x00000001 << 15))

/************************************** Register NMVn ***************************************/
# define CCREG_NMVn_NM_MASK                                 ((uint32) 0xFFFFFFFF)
# define CCREG_NMVn_NM_SHIFT                                0

/************************************** Register MRC ***************************************/
# define CCREG_MRC_FDB_MASK                                ((uint32) 0x000000FF)
# define CCREG_MRC_FDB_SHIFT                               0
# define CCREG_MRC_FFB_MASK                                ((uint32) 0x0000FF00)
# define CCREG_MRC_FFB_SHIFT                               0
# define CCREG_MRC_LCB_MASK                                ((uint32) 0x00FF0000)
# define CCREG_MRC_LCB_SHIFT                               0
# define CCREG_MRC_SEC_MASK                                ((uint32) 0x03000000)
# define CCREG_MRC_SEC_SHIFT                               0
# define CCREG_MRC_SPLM                                    ((uint32) ((uint32)0x00000001 << 26))

/************************************** Register FRF ***************************************/
# define CCREG_FRF_CH_MASK                                 ((uint32) 0x00000003)
# define CCREG_FRF_CH_SHIFT                                0
# define CCREG_FRF_FID_MASK_FRF                            ((uint32) 0x00001FFC)
# define CCREG_FRF_FID_SHIFT_FRF                           2
# define CCREG_FRF_CYF_MASK                                ((uint32) 0x007F0000)
# define CCREG_FRF_CYF_SHIFT                               16
# define CCREG_FRF_RSS                                     ((uint32) ((uint32)0x00000001 << 23))
# define CCREG_FRF_RNF                                     ((uint32) ((uint32)0x00000001 << 24))

/************************************** Register FRFM ***************************************/
# define CCREG_FRFM_MFID_MASK                               ((uint32) 0x00001FFC)
# define CCREG_FRFM_MFID_SHIFT                              2

/************************************** Register FCL ***************************************/
# define CCREG_FCL_CL_MASK                                 ((uint32) 0x000000FF)
# define CCREG_FCL_CL_SHIFT                                0

/************************************** Register MHDS ***************************************/
# define CCREG_MHDS_PIBF                                    ((uint32) (0x00000001 << 0))
# define CCREG_MHDS_POBF                                    ((uint32) (0x00000001 << 1))
# define CCREG_MHDS_PMR                                     ((uint32) (0x00000001 << 2))
# define CCREG_MHDS_PTBF1                                   ((uint32) (0x00000001 << 3))
# define CCREG_MHDS_PTBF2                                   ((uint32) (0x00000001 << 4))
# define CCREG_MHDS_FMBD                                    ((uint32) (0x00000001 << 5))
# define CCREG_MHDS_MFMB                                    ((uint32) (0x00000001 << 6))
# define CCREG_MHDS_CRAM                                    ((uint32) (0x00000001 << 7))
# define CCREG_MHDS_FMB_MASK                                ((uint32) 0x00007F00)
# define CCREG_MHDS_FMB_SHIFT                               8
# define CCREG_MHDS_MBT_MASK                                ((uint32) 0x007F0000)
# define CCREG_MHDS_MBT_SHIFT                               16
# define CCREG_MHDS_MBU_MASK                                ((uint32) 0x7F000000)
# define CCREG_MHDS_MBU_SHIFT                               24

/************************************** Register LDTS ***************************************/
# define CCREG_LDTS_LDTA_MASK                               ((uint32) 0x000007FF)
# define CCREG_LDTS_LDTA_SHIFT                              0
# define CCREG_LDTS_LDTB_MASK                               ((uint32) 0x07FF0000)
# define CCREG_LDTS_LDTB_SHIFT                              16

/************************************** Register FSR ***************************************/
# define CCREG_FSR_RFNE_FSR                                ((uint32) (0x00000001 << 0))
# define CCREG_FSR_RFCL_FSR                                ((uint32) (0x00000001 << 1))
# define CCREG_FSR_RFO_FSR                                 ((uint32) (0x00000001 << 2))
# define CCREG_FSR_RFFL_MASK                               ((uint32) 0x0000FF00)
# define CCREG_FSR_RFFL_SHIFT                              8

/************************************** Register MHDF ***************************************/
# define CCREG_MHDF_SNUA                                    ((uint32) (0x00000001 << 0))
# define CCREG_MHDF_SNUB                                    ((uint32) (0x00000001 << 1))
# define CCREG_MHDF_FNFA                                    ((uint32) (0x00000001 << 2))
# define CCREG_MHDF_FNFB                                    ((uint32) (0x00000001 << 3))
# define CCREG_MHDF_WAHP                                    ((uint32) (0x00000001 << 8))

/************************************** Register TXRQn ***************************************/
# define CCREG_TXRQn_TXR_MASK                              ((uint32) 0xFFFFFFFF)
# define CCREG_TXRQn_TXR_SHIFT                             0

/************************************** Register NDATn ***************************************/
# define CCREG_NDATn_ND_MASK                               ((uint32) 0xFFFFFFFF)
# define CCREG_NDATn_ND_SHIFT                              0

/************************************** Register MBSCn ***************************************/
# define CCREG_MBSCn_MBC_MASK                              ((uint32) 0xFFFFFFFF)
# define CCREG_MBSCn_MBC_SHIFT                             0

/************************************** Register CREL ***************************************/
# define CCREG_CREL_DAY_MASK                                ((uint32) 0x000000FF)
# define CCREG_CREL_DAY_SHIFT                               0
# define CCREG_CREL_MON_MASK                                ((uint32) 0x0000FF00)
# define CCREG_CREL_MON_SHIFT                               8
# define CCREG_CREL_YEAR_MASK                               ((uint32) 0x000F0000)
# define CCREG_CREL_YEAR_SHIFT                              16
# define CCREG_CREL_STEP_MASK                               ((uint32) 0x0FF00000)
# define CCREG_CREL_STEP_SHIFT                              20
# define CCREG_CREL_REL_MASK                                ((uint32) 0xF0000000)
# define CCREG_CREL_REL_SHIFT                               28

/************************************** Register ENDN ***************************************/
# define CCREG_ENDN_ETV_MASK                                ((uint32) 0xFFFFFFFF)
# define CCREG_ENDN_ETV_SHIFT                               0

/************************************** Register WRDSn ***************************************/
# define CCREG_WRDSn_MD_MASK                                 ((uint32) 0xFFFFFFFF)
# define CCREG_WRDSn_MD_SHIFT                                0

/************************************** Register WRHS1 ***************************************/
# define CCREG_WRHS1_FID_MASK                                ((uint32) 0x000007FF)
# define CCREG_WRHS1_FID_SHIFT                               0
# define CCREG_WRHS1_CYC_MASK                                ((uint32) 0x007F0000)
# define CCREG_WRHS1_CYC_SHIFT                               16
# define CCREG_WRHS1_CHA                                     ((uint32) ((uint32)0x00000001 << 24))
# define CCREG_WRHS1_CHA_SHIFT                               24
# define CCREG_WRHS1_CHB                                     ((uint32) ((uint32)0x00000001 << 25))
# define CCREG_WRHS1_CFG                                     ((uint32) ((uint32)0x00000001 << 26))
# define CCREG_WRHS1_PPIT                                    ((uint32) ((uint32)0x00000001 << 27))
# define CCREG_WRHS1_TXM                                     ((uint32) ((uint32)0x00000001 << 28))
# define CCREG_WRHS1_MBI                                     ((uint32) ((uint32)0x00000001 << 29))

/************************************** Register WRHS2 ***************************************/
# define CCREG_WRHS2_CRC_MASK                                ((uint32) 0x000007FF)
# define CCREG_WRHS2_CRC_SHIFT                               0
# define CCREG_WRHS2_PLC_MASK                                ((uint32) 0x007F0000)
# define CCREG_WRHS2_PLC_SHIFT                               ((uint8) 16)
# define CCREG_WRHS2_PLC_BYTE_SHIFT                          ((uint8) 15) /* Shift PLC to bytevalue. Precondition: WRHS2.bit15 to be 0 */
/************************************** Register WRHS3 ***************************************/
# define CCREG_WRHS3_DP_MASK                                 ((uint32) 0x000007FF)
# define CCREG_WRHS3_DP_SHIFT                                0

/************************************** Register IBCM ***************************************/
# define CCREG_IBCM_LHSH                                    ((uint32) (0x00000001 << 0) )
# define CCREG_IBCM_LDSH                                    ((uint32) (0x00000001 << 1) )
# define CCREG_IBCM_STXRH                                   ((uint32) (0x00000001 << 2) )
# define CCREG_IBCM_LHSS                                    ((uint32) ((uint32)0x00000001 << 16))
# define CCREG_IBCM_LDSS                                    ((uint32) ((uint32)0x00000001 << 17))
# define CCREG_IBCM_STXRS                                   ((uint32) ((uint32)0x00000001 << 18))

/************************************** Register IBCR ***************************************/
# define CCREG_IBCR_IBRH_MASK                               ((uint32) 0x0000007F)
# define CCREG_IBCR_IBRH_SHIFT                              0
# define CCREG_IBCR_IBSYH                                   ((uint32) (0x00000001 << 15))
# define CCREG_IBCR_IBRS_MASK                               ((uint32) 0x007F0000)
# define CCREG_IBCR_IBRS_SHIFT                              16
# define CCREG_IBCR_IBSYS                                   ((uint32) ((uint32)0x00000001 << 31))

/************************************** Register RDDSn ***************************************/
# define CCREG_RDDSn_MD_MASK                                 ((uint32) 0xFFFFFFFF)
# define CCREG_RDDSn_MD_SHIFT                                0

/************************************** Register RDHS1 ***************************************/
# define CCREG_RDHS1_FID_MASK                                ((uint32) 0x000007FF)
# define CCREG_RDHS1_FID_SHIFT                               0
# define CCREG_RDHS1_CYC_MASK                                ((uint32) 0x007F0000)
# define CCREG_RDHS1_CYC_SHIFT                               16
# define CCREG_RDHS1_CHA                                     ((uint32) ((uint32)0x00000001 << 24))
# define CCREG_RDHS1_CHB                                     ((uint32) ((uint32)0x00000001 << 25))
# define CCREG_RDHS1_CFG                                     ((uint32) ((uint32)0x00000001 << 26))
# define CCREG_RDHS1_PPIT                                    ((uint32) ((uint32)0x00000001 << 27))
# define CCREG_RDHS1_TXM                                     ((uint32) ((uint32)0x00000001 << 28))
# define CCREG_RDHS1_MBI                                     ((uint32) ((uint32)0x00000001 << 29))

/************************************** Register RDHS2 ***************************************/
# define CCREG_RDHS2_CRC_MASK                                ((uint32) 0x000007FF)
# define CCREG_RDHS2_CRC_SHIFT                               0
# define CCREG_RDHS2_PLC_MASK                                ((uint32) 0x007F0000)
# define CCREG_RDHS2_PLC_SHIFT                               16
# define CCREG_RDHS2_PLR_MASK                                ((uint32) 0x7F000000)
# define CCREG_RDHS2_PLR_SHIFT                               24

/************************************** Register RDHS3 ***************************************/
# define CCREG_RDHS3_DP_MASK                                 ((uint32) 0x000007FF)
# define CCREG_RDHS3_DP_SHIFT                                0
# define CCREG_RDHS3_RCC_MASK                                ((uint32) 0x003F0000)
# define CCREG_RDHS3_RCC_SHIFT                               16
# define CCREG_RDHS3_RCI                                     ((uint32) ((uint32)0x00000001 << 24))
# define CCREG_RDHS3_SFI                                     ((uint32) ((uint32)0x00000001 << 25))
# define CCREG_RDHS3_SYN                                     ((uint32) ((uint32)0x00000001 << 26))
# define CCREG_RDHS3_NFI                                     ((uint32) ((uint32)0x00000001 << 27))
# define CCREG_RDHS3_PPI                                     ((uint32) ((uint32)0x00000001 << 28))
# define CCREG_RDHS3_RES                                     ((uint32) ((uint32)0x00000001 << 29))

/************************************** Register MBS ***************************************/
# define CCREG_MBS_VFRA                                    ((uint32) (0x00000001 << 0) )
# define CCREG_MBS_VFRB                                    ((uint32) (0x00000001 << 1) )
# define CCREG_MBS_SEOA                                    ((uint32) (0x00000001 << 2) )
# define CCREG_MBS_SEOB                                    ((uint32) (0x00000001 << 3) )
# define CCREG_MBS_CEOA                                    ((uint32) (0x00000001 << 4) )
# define CCREG_MBS_CEOB                                    ((uint32) (0x00000001 << 5) )
# define CCREG_MBS_SVOA                                    ((uint32) (0x00000001 << 6) )
# define CCREG_MBS_SVOB                                    ((uint32) (0x00000001 << 7) )
# define CCREG_MBS_TCIA                                    ((uint32) (0x00000001 << 8) )
# define CCREG_MBS_TCIA_SHIFT                              8
# define CCREG_MBS_TCIB                                    ((uint32) (0x00000001 << 9) )
# define CCREG_MBS_TCIB_SHIFT                              9
# define CCREG_MBS_ESA                                     ((uint32) (0x00000001 << 10))
# define CCREG_MBS_ESB                                     ((uint32) (0x00000001 << 11))
# define CCREG_MBS_MLST                                    ((uint32) (0x00000001 << 12))
# define CCREG_MBS_FTA                                     ((uint32) (0x00000001 << 14))
# define CCREG_MBS_FTB                                     ((uint32) (0x00000001 << 15))
# define CCREG_MBS_CCS_MASK                                ((uint32) 0x003F0000)
# define CCREG_MBS_CCS_SHIFT                               16
# define CCREG_MBS_RCIS                                    ((uint32)( (uint32)0x00000001 << 24))
# define CCREG_MBS_SFIS                                    ((uint32)( (uint32)0x00000001 << 25))
# define CCREG_MBS_SYNS                                    ((uint32)( (uint32)0x00000001 << 26))
# define CCREG_MBS_NFIS                                    ((uint32)( (uint32)0x00000001 << 27))
# define CCREG_MBS_PPIS                                    ((uint32)( (uint32)0x00000001 << 28))
# define CCREG_MBS_RESS                                    ((uint32)( (uint32)0x00000001 << 29))

/************************************** Register OBCM ***************************************/
# define CCREG_OBCM_RHSS                                    ((uint32) (0x00000001 << 0) )
# define CCREG_OBCM_RDSS                                    ((uint32) (0x00000001 << 1) )
# define CCREG_OBCM_RHSH                                    ((uint32) ((uint32)0x00000001 << 16))
# define CCREG_OBCM_RDSH                                    ((uint32) ((uint32)0x00000001 << 17))

/************************************** Register OBCR ***************************************/
# define CCREG_OBCR_OBRS_MASK                               ((uint32) 0x0000007F)
# define CCREG_OBCR_OBRS_SHIFT                              0
# define CCREG_OBCR_VIEW                                    ((uint32) (0x00000001 << 8) )
# define CCREG_OBCR_REQ                                     ((uint32) (0x00000001 << 9) )
# define CCREG_OBCR_OBSYS                                   ((uint32) (0x00000001 << 15))
# define CCREG_OBCR_OBRH_MASK                               ((uint32) 0x007F0000)
# define CCREG_OBCR_OBRH_SHIFT                              0

/************************************** Output Buffer ***************************************/
# define CCBUF_RDDS1           (uint32)0x0600
# define CCBUF_RDDS2           (uint32)0x0604
# define CCBUF_RDDS3           (uint32)0x0608
# define CCBUF_RDDS4           (uint32)0x060C
# define CCBUF_RDDS5           (uint32)0x0610
# define CCBUF_RDDS6           (uint32)0x0614
# define CCBUF_RDDS7           (uint32)0x0618
# define CCBUF_RDDS8           (uint32)0x061C
# define CCBUF_RDDS9           (uint32)0x0620
# define CCBUF_RDDS10          (uint32)0x0624
# define CCBUF_RDDS11          (uint32)0x0628
# define CCBUF_RDDS12          (uint32)0x062C
# define CCBUF_RDDS13          (uint32)0x0630
# define CCBUF_RDDS14          (uint32)0x0634
# define CCBUF_RDDS15          (uint32)0x0638
# define CCBUF_RDDS16          (uint32)0x063C
# define CCBUF_WRDS1           (uint32)0x0400
# define CCBUF_WRDS2           (uint32)0x0404
# define CCBUF_WRDS3           (uint32)0x0408
# define CCBUF_WRDS4           (uint32)0x040C
# define CCBUF_WRDS5           (uint32)0x0410
# define CCBUF_WRDS6           (uint32)0x0414
# define CCBUF_WRDS7           (uint32)0x0418
# define CCBUF_WRDS8           (uint32)0x041C
# define CCBUF_WRDS9           (uint32)0x0420
# define CCBUF_WRDS10          (uint32)0x0424
# define CCBUF_WRDS11          (uint32)0x0428
# define CCBUF_WRDS12          (uint32)0x042C
# define CCBUF_WRDS13          (uint32)0x0430
# define CCBUF_WRDS14          (uint32)0x0434
# define CCBUF_WRDS15          (uint32)0x0438
# define CCBUF_WRDS16          (uint32)0x043C
/************************************** end register defines *******************************/

/*** ERay limits ***/
# define CC_MAX_NUM_HW_BUFFERS          ((uint8)(128))
# define CC_MAX_NUM_PAYLOAD_BYTES       ((uint8)(254))
# define CC_MAX_NUM_PAYLOAD_16BIT_WORDS ((uint8)(16))
# define CC_MAX_NUM_TIMERS              2

/*** ErrorFlag defines ***/
# define CC_ERROR_ERRM_ACTIVE            ((uint32) 0x00000000 )
# define CC_ERROR_ERRM_PASSIVE           ((uint32) 0x00000001 << 1)
# define CC_ERROR_ERRM_COMMHALT          ((uint32) 0x00000001 << 2)
# define CC_ERROR_ERRM_RESERVED          ((uint32) 0x00000001 << 3)
# define CC_ERROR_COLDSTART              ((uint32) 0x00000001 << 4)
# define CC_ERROR_CLOCKCORRECTION        ((uint32) 0x00000001 << 5)
# define CC_ERROR_SYNCFRAME              ((uint32) 0x00000001 << 6)
# define CC_ERROR_SYNTAX_A               ((uint32) 0x00000001 << 7)
# define CC_ERROR_SYNTAX_B               ((uint32) 0x00000001 << 8)
# define CC_ERROR_CHANNEL_A              ((uint32) 0x00000001 << 9)
# define CC_ERROR_CHANNEL_B              ((uint32) 0x00000001 << 10)
# define CC_ERROR_LATESTTX_A             ((uint32) 0x00000001 << 11)
# define CC_ERROR_LATESTTX_B             ((uint32) 0x00000001 << 12)
# define CC_ERROR_SW_A                   ((uint32) 0x00000001 << 14)
# define CC_ERROR_SW_B                   ((uint32) 0x00000001 << 15)
# define CC_ERROR_NIT_A                  ((uint32) 0x00000001 << 16)
# define CC_ERROR_NIT_B                  ((uint32) 0x00000001 << 17)

/**************************************************************************************************
* TMS470 FTU constants
**************************************************************************************************/
#  define FR_FTU_REG_GCS                    (uint32)0x10
#  define FR_FTU_REG_GCR                    (uint32)0x14
#  define FR_FTU_REG_GCS_TUE                ((uint32) 0x00000001 << 0)
#  define FR_FTU_REG_GCS_TUH                ((uint32) 0x00000001 << 1)
#  define FR_FTU_REG_GCS_CTTSM              ((uint32) 0x00000001 << 12)
#  define FR_FTU_REG_GCS_CTTCC              ((uint32) 0x00000001 << 13)
#  define FR_FTU_REG_GCS_CETESM             ((uint32) 0x00000001 << 14)

#  define FR_FTU_REG_TSCB                   (uint32)0x18
#  define FR_FTU_REG_TSCB_STUH              ((uint32) 0x00000001 << 12)
#  define FR_FTU_REG_TSCB_IDLE              ((uint32) 0x00000001 << 8)
#  define FR_FTU_REG_TSCB_BN                ((uint32) 0x0000007F     )

#  define FR_FTU_REG_TCR_STXR               ((uint32) 0x00000001 << 18)
#  define FR_FTU_REG_TCR_THTSM              ((uint32) 0x00000001 << 17)
#  define FR_FTU_REG_TCR_TPTSM              ((uint32) 0x00000001 << 16)
#  define FR_FTU_REG_TCR_THTCC              ((uint32) 0x00000001 << 15)
#  define FR_FTU_REG_TCR_TPTCC              ((uint32) 0x00000001 << 14)
#  define FR_FTU_REG_TCR_TSO                ((uint32) 0x00000001      )

#  define FR_FTU_REG_TSMOn                  (uint32)0x00000040UL/* Transfer to SysMem occured */
#  define FR_FTU_REG_TCCOn                  (uint32)0x00000050UL/* Transfer to CC occured */
#  define FR_FTU_REG_TTCCS                  (uint32)0x000000A0UL/* Trigger Transfer to Communication Controller Set */
#  define FR_FTU_REG_TTCCR                  (uint32)0x000000A4UL/* Trigger Transfer to Communication Controller Reset */

#  define FR_FTU_INFO_DYN_PAYLOAD           ((uint32) 0x00000001 << 0)
#  define FR_FTU_INFO_SEPARATE_HWBUFFER     ((uint32) 0x00000001 << 1)
#  define FR_FTU_INFO_RECONFIG              ((uint32) 0x00000001 << 2)
#  define FR_FTU_INFO_RECONFIGLPDU          ((uint32) 0x00000001 << 3)

#  define FR_FTU_REG_TTSMS1                 (uint32)0x80
#  define FR_FTU_REG_TTSMS2                 (uint32)0x88
#  define FR_FTU_REG_TTSMS3                 (uint32)0x90
#  define FR_FTU_REG_TTSMS4                 (uint32)0x98
#  define FR_FTU_REG_TTSMR1                 (uint32)0x84
#  define FR_FTU_REG_TTSMR2                 (uint32)0x8C
#  define FR_FTU_REG_TTSMR3                 (uint32)0x94
#  define FR_FTU_REG_TTSMR4                 (uint32)0x9C

#  define FR_FTU_REG_TTCCS1                 (uint32)0xA0
#  define FR_FTU_REG_TTCCS2                 (uint32)0xA8
#  define FR_FTU_REG_TTCCS3                 (uint32)0xB0
#  define FR_FTU_REG_TTCCS4                 (uint32)0xB8
#  define FR_FTU_REG_TTCCR1                 (uint32)0xA4
#  define FR_FTU_REG_TTCCR2                 (uint32)0xAC
#  define FR_FTU_REG_TTCCR3                 (uint32)0xB4
#  define FR_FTU_REG_TTCCR4                 (uint32)0xBC



/**************************************************************************************************
* Global constants
**************************************************************************************************/

/**************************************************************************************************
* Global data types and structures
**************************************************************************************************/

/**************************************************************************************************
* Prototypes of export functions
**************************************************************************************************/

/***** end of header file ************************************************************************/
#endif
  /* FR_ERAY_H */
/* STOPSINGLE_OF_MULTIPLE */
