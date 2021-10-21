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
 *         File:  Fr_Irq.c
 *      Project:  FlexRay Stack
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  FlexRay Driver Interrupt functions
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
 *  03.00.01  2007-12-12  Ssr    ESCAN00023676  Add dynamic payload support, optimize code
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
 *                                ESCAN00024997 Rename of variable in Fr_GetNmVector
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
 *  03.03.01  2008-08-14  Jsr                   No change
 *  03.04.00  2008-08-22  Seg                   new version
 *  03.04.01  2008-09-11  Ssr     ESCAN00029920 Returnvalue within Fr_ReceiveRxLPdu 
 *                                ESCAN00029922 Correct Fr_LPduStatusPtr and Fr_LPduLengthPtr
 *  03.04.02  2008-09-23  Seg                   new version
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

/* PRQA S 0303 EOF */ /* Misra rule 11.3. Standard justification for HW-access in Fr */
/* PRQA S 0857 EOF */ /* Misra rule 11.3. Standard justification for Macro usage in Fr */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Fr.h"

#if ( FR_CFG_ISR_TYPE == FR_ISR_CAT2 )
# include "Os.h"
#endif


# if ((FR_CFG_APPL_CALLBACK_TIMER0 == STD_OFF) && (!defined (FR_GENERATOR_GENY)))
#include "v_cfg.h"
#  if defined VGEN_ENABLE_IF_ASRIFFR
#include "FrIf.h"
#  endif
# endif

/**************************************************************************************************
* DEFINES / CONSTANTS
**************************************************************************************************/

/* PRQA S 1503 EOF */ /* MISRA rule 14.1 violation because of single project Misra check */


/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check consistency of source and header file. */
#if ( (FR_SW_MAJOR_VERSION != 0x3u) || (FR_SW_MINOR_VERSION != 0x14u) || (FR_SW_PATCH_VERSION != 0x04u) )
  #error "Fr_Irq.c: Source and Header file are inconsistent!"
#endif


/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  FUNCTIONS
 **********************************************************************************************************************/


#define FR_START_SEC_CODE_ISR
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */


# if (FR_CFG_APPL_CALLBACK_CYCLE_START == STD_ON)
/***********************************************************************************************************************
 *  Fr_IrqLinex
 **********************************************************************************************************************/
/*! \brief      Interrupt function called by operating system
 *  \param[in]  -
 *  \param[out] -
 *  \return     -
 *  \pre        -
 *  \context    Called by upper layer.
 *  \note       Define ISR() must be coming from os.h include file
 *  \sws req    
 **********************************************************************************************************************/
#  if ( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )
#   if(FR_CFG_STATUS_ISR_LINE == 0) 
FUNC(void, FR_CODE_ISR) Fr_IrqLine0(void)
#   else
FUNC(void, FR_CODE_ISR) Fr_IrqLine1(void)
#   endif
#  else
#   if(FR_CFG_STATUS_ISR_LINE == 0) 
ISR( Fr_IrqLine0 )  /* PRQA S 3408 */ /* MISRA-C:2004 Rule 8.8  Prototype define within os.h */
#   else
ISR( Fr_IrqLine1 )  /* PRQA S 3408 */ /* MISRA-C:2004 Rule 8.8  Prototype define within os.h */
#   endif
#  endif
{
  Fr_ISR_Status(FR_COM_CONTROLLER_0);
}
# endif

/***********************************************************************************************************************
 *  Fr_IrqTimer0
 **********************************************************************************************************************/
/*! \brief      Interrupt function called by operating system
 *  \param[in]  -
 *  \param[out] -
 *  \return     -
 *  \pre        -
 *  \context    Called by upper layer.
 *  \note       Define ISR() must be coming from os.h include file
 *  \sws req    
 **********************************************************************************************************************/
# if ( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )
void Fr_IrqTimer0(void)
# else
ISR (Fr_IrqTimer0)  /* PRQA S 3408 */ /* MISRA-C:2004 Rule 8.8  Prototype define within os.h */
# endif
{
  /* Clear T0 interrupt */
  Fr_VCCClearIrqStatusFlag(CCREG_SIR_TI0);
  /* *** FrIf Job list execution *** */
# if (FR_CFG_APPL_CALLBACK_TIMER0 == STD_OFF)
#  if ((defined (VGEN_ENABLE_IF_ASRIFFR)) && (!defined (FR_GENERATOR_GENY)))
  FrIf_JobListExec_0();
#  endif   /* (VGEN_ENABLE_IF_ASRIFFR) */
# else
  ApplFr_ISR_Timer0();
# endif

}

/***********************************************************************************************************************
 *  Fr_IrqTimer1
 **********************************************************************************************************************/
/*! \brief      Interrupt function called by operating system
 *  \param[in]  -
 *  \param[out] -
 *  \return     -
 *  \pre        -
 *  \context    Called by upper layer.
 *  \note       Define ISR() must be coming from os.h include file
 *  \sws req    
 **********************************************************************************************************************/
# if ( FR_RELATIVE_TIMER_ENABLE == STD_ON )
#  if ( FR_CFG_ISR_TYPE == FR_ISR_CAT1) || ( FR_CFG_ISR_TYPE == FR_ISR_VOID )
FUNC(void, FR_CODE_ISR) Fr_IrqTimer1(void)
#  else
ISR( Fr_IrqTimer1 ) /* PRQA S 3408 */ /* MISRA-C:2004 Rule 8.8  Prototype define within os.h */
#  endif
{
  
  Fr_ISR_Timer1(FR_COM_CONTROLLER_0);
}
# endif



#define FR_STOP_SEC_CODE_ISR
#include "MemMap.h" /* PRQA S 5087 */ /* MISRA rule 19.1 violation due to AUTOSAR requirement for Memory Mapping */

/**********************************************************************************************************************
 *  END OF FILE: Fr_Irq.c
 *********************************************************************************************************************/
