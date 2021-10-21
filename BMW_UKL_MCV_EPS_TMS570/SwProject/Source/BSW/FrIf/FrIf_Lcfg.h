/* STARTSINGLE_OF_MULTIPLE */
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2011 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*! \file         FrIf_Lcfg.h
 *    Component:  MICROSAR FrIf
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Header file of the FlexRay Interface containing the definition of the link-time configuration data, 
 *                according to: AUTOSAR FlexRay Interface, AUTOSAR Release 3.0
 **********************************************************************************************************************

 **********************************************************************************************************************
 *  \author AUTHOR IDENTITY
 -  -------------------------------------------------------------------------------------------------------------------
 -  Name                          Initials      Company
 -  -------------------------------------------------------------------------------------------------------------------
 -  Klaus Bergdolt                ber           Vctr Informatik GmbH
 -  Oliver Reineke                ore           Vctr Informatik GmbH
 -  -------------------------------------------------------------------------------------------------------------------
 *  \version REVISION HISTORY
 -  -------------------------------------------------------------------------------------------------------------------
 -  Version   Date        Author  Change Id     Description
 -  -------------------------------------------------------------------------------------------------------------------
 -  3.0.0     2007-12-12  ber     -             release of version 3.0.0 
 -  3.0.1     2008-02-22  ber     -             release of version 3.0.1 
 -  3.0.2     2008-03-20  ber     ESCAN00025115 No changes here
 -            2008-04-02  ber     ESCAN00023644 No changes here
 -            2008-04-03  ber     -             release of version 3.0.2
 -  3.0.3     2008-04-17  ber     ESCAN00026131 Memory Access Violation in embedded code during FrIf job list execution
 -            2008-04-18  ber     ESCAN00025799 No changes here
 -            2008-04-18  ber     -             release of version 3.0.3 
 -  3.0.4     2008-04-25  ore     ESCAN00026130 No changes here
 -            2008-04-25  ore     ESCAN00026216 No changes here
 -            2008-04-25  ore     ESCAN00026256 Rename files and #include statements according coding styles
 -            2008-04-28  ore     ESCAN00026445 No changes here
 -            2008-04-28  ore     ESCAN00026447 No changes here
 -            2008-04-28  ore     ESCAN00026449 No changes here
 -            2008-05-15  ore     ESCAN00026651 No changes here
 -            2008-05-19  ore     ESCAN00026973 No changes here
 -            2008-05-21  ore     -             release of version 3.0.4
 -  3.0.5     2008-06-09  ore     ESCAN00026972 Inconsistent Memory Mapping for FrIf_Lcfg.c
 -            2008-06-09  ore     ESCAN00026341 No changes here
 -            2008-07-08  ore     ESCAN00027356 No changes here
 -            2008-07-09  ore     ESCAN00028155 No changes here
 -            2008-07-11  ore     -             release of version 3.0.5
 -  3.0.6     2008-07-17  ore     ESCAN00027548 No changes here
 -            2008-07-17  ore     -             release of version 3.0.6
 -  3.0.7     2008-07-18  ore     ESCAN00027867 No changes here
 -            2008-07-24  ore     ESCAN00027210 No changes here
 -            2008-07-28  ore     ESCAN00028772 FrIf Single-Controller Optimization
 -            2008-08-01  ore     ESCAN00027451 No changes here
 -            2008-08-07  ore     ESCAN00029068 No changes here
 -            2008-08-07  ore     ESCAN00029042 No changes here
 -            2008-08-13  ore     ESCAN00029218 No changes here
 -            2008-08-13  ore     ESCAN00029219 No changes here
 -            2008-08-13  ore     ESCAN00029184 No changes here
 -            2008-08-13  ore     -             added PduDirtyByte optimization
 -            2008-08-14  ore     -             unified define usage
 -            2008-08-15  ore     -             release of version 3.0.7
 -  3.0.8     2008-08-22  ore     ESCAN00029101 No constant is generated as link time paramter for FrIf_Init()
 -            2008-08-22  ore     -             release of version 3.0.8
 -  3.0.9     2008-09-17  ore     -             release of version 3.0.9
 -  3.0.10    2008-10-01  ore     ESCAN00030038 No changes here
 -            2008-10-01  ore     ESCAN00030039 FrIf type name conventions
 -            2008-10-01  ore     ESCAN00030040 FrIf variable/function name conventions
 -            2008-10-01  ore     ESCAN00029696 No changes here
 -            2008-10-01  ore     ESCAN00029736 No changes here
 -            2008-11-03  ore     ESCAN00031030 Unused frame parts are not always initialized
 -            2008-11-03  ore     ESCAN00031026 No changes here
 -            2008-11-04  ore     -             release of version 3.0.10
 -  3.1.0     2008-11-10  ore     ESCAN00030776 No changes here
 -            2008-11-10  ore     ESCAN00030577 No changes here
 -            2008-11-10  ore     ESCAN00030264 No changes here
 -            2008-11-10  ore     ESCAN00030764 No changes here
 -            2008-11-17  ore     ESCAN00031345 No changes here
 -            2008-11-17  ore     ESCAN00030264 PreCompile and Linktime Crc Check
 -            2008-11-18  ore     -             removed redundant FrIf_Config declaration
 -            2008-11-18  ore     -             added MISRA violation comments
 -            2008-11-24  ore     ESCAN00031360 No changes here
 -            2008-12-01  ore     ESCAN00031710 No changes here
 -            2008-12-08  ore     ESCAN00031843 No changes here
 -            2008-12-19  ore     -             release of version 3.1.0
 -  3.2.0     2009-02-02  ore     ESCAN00032463 No changes here
 -            2009-02-10  ore     ESCAN00032944 No changes here
 -            2009-02-17  ore     ESCAN00033102 No changes here
 -            2009-02-18  ore     ESCAN00027867 No changes here
 -            2009-02-18  ore     ESCAN00033318 No changes here
 -            2009-02-18  ore     ESCAN00033145 No changes here
 -            2009-02-18  ore     ESCAN00033220 No changes here
 -            2009-02-18  ore     ESCAN00032895 No changes here
 -            2009-02-18  ore     ESCAN00033309 Remove FrIf memory class macros to reduce the number of misra 
 *                                              violations.
 -            2009-02-18  ore     ESCAN00031278 No changes here
 -            2009-02-25  ore     ESCAN00033399 No changes here
 -            2009-02-25  ore     ESCAN00033402 The FrIf source and header files are not implemented as SingleSource.
 -            2009-03-06  ore     -             Added missing compiler abstraction for FrIf_TxPduTxRequestCounter
 -            2009-02-26  ore     ESCAN00033441 No changes here
 -            2009-02-26  ore     ESCAN00032715 No changes here
 -            2009-03-05  ore     ESCAN00033650 No changes here
 -            2009-03-06  ore     ESCAN00033651 No changes here
 -            2009-03-06  ore     ESCAN00033665 Add missing Link-time configuration variant
 -            2009-03-18  ore     ESCAN00033669 No changes here
 -            2009-03-10  ore     ESCAN00033732 Generate FrIf wrapper functions instead of function tables to call 
 *                                              the upperlayer functions
 -            2009-03-23  ore     ESCAN00034040 No changes here
 -            2009-03-23  ore     -             release of version 3.2.0
 -  3.3.0     2009-04-06  ore     ESCAN00036436 Add PRQA misra justification comments for QAC
 -            2009-05-28  ore     ESCAN00035398 No changes here
 -            2009-05-28  ore     ESCAN00035048 No changes here
 -            2009-06-29  ore     ESCAN00035991 No changes here
 -            2009-07-06  ore     ESCAN00036053 No changes here
 -            2009-07-20  ore     ESCAN00036397 No changes here
 -            2009-07-14  ore     ESCAN00035990 No changes here
 -            2009-07-14  ore     ESCAN00035399 The static header files of the FrIf don't include the Memmap.h file 
 -            2009-07-15  ore     ESCAN00036426 No changes here
 -            2009-07-15  ore     ESCAN00036427 No changes here
 -            2009-07-15  ore     ESCAN00036429 No changes here
 -            2009-07-15  ore     ESCAN00036451 No changes here
 -            2009-07-16  ore     ESCAN00036471 No changes here
 -            2009-07-17  ore     ESCAN00034459 No changes here
 -            2009-07-28  ore     ESCAN00036120 No changes here
 -            2009-07-31  ore     ESCAN00036776 No changes here
 -            2009-07-31  ore     -             release of version 3.3.0 
 -  3.4.0     2009-08-24  ore     ESCAN00036905 No changes here
 -            2009-08-24  ore     ESCAN00037257 No changes here
 -            2009-09-08  ore     ESCAN00035396 No changes here
 -            2009-09-08  ore     ESCAN00037643 No changes here
 -            2009-09-08  ore     ESCAN00037633 Implement wrapper functions for FrTpIso with AUTOSAR 4.0 Buffer API
 -            2009-09-21  ore     ESCAN00036013 No changes here
 -            2009-10-27  ore     ESCAN00038513 No changes here
 -            2009-11-02  ore     ESCAN00038914 No changes here
 -            2009-11-02  ore     ESCAN00038855 No changes here
 -            2009-11-03  ore     ESCAN00038930 The revision history of all source and header files shall contain all 
 *                                              implementation relevant ClearQuest issues of the FrIf.
 -            2009-11-17  ore     ESCAN00039212 No changes here
 -            2009-11-30  ore     ESCAN00039411 No changes here
 -            2009-12-07  ore     ESCAN00039607 No changes here
 -            2009-12-07  ore     ESCAN00039609 No changes here
 -            2009-12-07  ore     -             release of version 3.4.0 
 -  3.5.0     2010-02-01  ore     ESCAN00040508 No changes here
 -            2010-02-16  ore     ESCAN00040867 No changes here
 -            2010-02-18  ore     ESCAN00040951 No changes here
 -            2010-02-18  ore     ESCAN00040960 No changes here
 -            2010-02-22  ore     ESCAN00039809 Store the update byte position as link-time variable or pre-compile define
 -            2010-03-18  ore     ESCAN00041666 No changes here
 -            2010-03-24  ore     ESCAN00041766 No changes here
 -            2010-03-24  ore     ESCAN00041788 No changes here
 -            2010-03-30  ore     ESCAN00041966 No changes here
 -            2010-04-22  ore     ESCAN00042422 No changes here
 -            2010-05-05  ore     ESCAN00041396 No changes here 
 -            2010-05-05  ore     -             release of version 3.5.0 
 -  3.6.0     2010-05-19  ore     ESCAN00042989 No changes here
 -            2010-05-28  ore     ESCAN00043268 No changes here 
 -            2010-06-24  ore     ESCAN00043567 No changes here 
 -            2010-06-24  ore     ESCAN00043569 No changes here 
 -            2010-07-07  ore     -             Fixed function descriptions so that they are correctly considered by Doxygen
 -            2010-07-22  ore     ESCAN00042986 No changes here 
 -            2010-07-29  ore     ESCAN00044336 Ensure consistency to C-sources for all FrIf header files
 -            2010-07-29  ore     ESCAN00044339 No changes here 
 -            2010-08-02  ore     -             Changed QAC justifications to be CDK compliant
 -            2010-08-03  ore     -             release of version 3.6.0 
 -  3.6.1     2010-09-22  ore     ESCAN00044465 No changes here 
 -            2010-09-22  ore     ESCAN00045547 No changes here 
 -            2010-09-22  ore     -             release of version 3.6.1
 -  3.7.0     2010-11-02  ore     ESCAN00045650 No changes here 
 -            2010-11-02  ore     ESCAN00046417 Pointer cast without using memory abstraction
 -            2010-11-02  ore     ESCAN00046257 No changes here 
 -            2010-11-05  ore     ESCAN00046607 Add DualChannelRedundancy support according to Bugzillla 42025.
 -            2010-11-16  ore     ESCAN00046950 No changes here 
 -            2010-11-25  ore     ESCAN00046093 AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
 -            2010-11-26  ore     ESCAN00047186 PreCompileCrc changes if parameter FrIfSchedulingAlgorithm is set to 
 *                                              'HandleDynamicAsStatic' 
 -            2010-12-01  ore     ESCAN00047302 No changes here 
 -            2010-12-01  ore     ESCAN00047327 No changes here 
 -            2011-01-27  ore     ESCAN00048244 No changes here 
 -            2011-01-27  ore     -             release of version 3.7.0
 -  3.7.1     2011-02-23  ore     ESCAN00048836 No changes here 
 -            2011-03-16  ore     -             release of version 3.7.1
 -  3.7.2     2011-05-02  ore     ESCAN00049388 No changes here 
 -            2011-05-02  ore     -             release of version 3.7.2
 -  3.7.3     2011-09-20  ore     ESCAN00051840 No changes here 
 -            2011-09-20  ore     -             release of version 3.7.3
 -  3.7.4     2011-10-25  ore     ESCAN00054422 No changes here 
 -            2011-10-25  ore     -             release of version 3.7.4
 *********************************************************************************************************************/

#if (!defined FRIF_L_CFG_H_)
# define FRIF_L_CFG_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "FrIf_Types.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* AUTOSAR FlexRay Interface version */
# define FRIF_LCFG_VERSION            0x0307u /*!< BCD coded FrIf Lcfg Header version number */
# define FRIF_LCFG_RELEASE_VERSION    0x04u   /*!< BCD coded FrIf Lcfg Header release version number */

#  if ( STD_OFF == FRIF_DIRECT_BUFFER_ACCESS_ENABLE )
#   define FRIF_GET_FRAMEBUFFER()                  ((P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT))FrIf_FrameBuffer)
#  else
#   define FRIF_GET_FRAMEBUFFER()                 NULL_PTR
#  endif

# if defined(FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON ) 
#  define FRIF_GET_REDUNDANT_FRAMEBUFFER()        ((P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT))FrIf_RedundantFrameBuffer)
# endif

# define FRIF_INITIALIZE_FRAMEBUFFER_START()      (FrIf_FrameBuffer[0] = FRIF_FILL_PATTERN_DWORD)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define FRIF_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

/* declarations of the FrIf upperlayer wrapper functions */
# if defined (FRIF_USEPDUINFOTYPE) && (FRIF_USEPDUINFOTYPE == STD_ON)
     extern FUNC(Std_ReturnType, FRIF_CODE) FrIf_TriggerTransmitFunctions(uint8 PduOwner, 
                                                       PduIdType FrTxPduId, 
                                                       P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) Payload,
                                                       P2VAR(PduLengthType, AUTOMATIC, FRIF_VAR_NOINIT) Length);
     extern FUNC(void, FRIF_CODE) FrIf_RxIndicationFunctions(uint8 PduOwner, 
                                                       PduIdType FrRxPduId, 
                                                       P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) Payload, 
                                                       PduLengthType Length);     
# else
     extern FUNC(void, FRIF_CODE) FrIf_TriggerTransmitFunctions(uint8 PduOwner, 
                                                       PduIdType FrTxPduId, 
                                                       P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) Payload);
     extern FUNC(void, FRIF_CODE) FrIf_RxIndicationFunctions(uint8 PduOwner, 
                                                       PduIdType FrRxPduId, 
                                                       P2CONST(uint8, AUTOMATIC, FRIF_VAR_NOINIT) Payload);     
# endif /* defined (FRIF_USEPDUINFOTYPE) && (FRIF_USEPDUINFOTYPE == STD_ON) */
     
     extern FUNC(void, FRIF_CODE) FrIf_TxConfirmationFunctions(uint8 PduOwner, PduIdType FrTxPduId);    
                                                        
# define FRIF_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

/* PRQA S 3684 DECLWITHOUSIZE *//* MD_FrIf_0812 */

# if (STD_ON == FRIF_PDUDIRTYBYTE_USAGE)
/*! \var Variable with one byte per PduDirty flag for each tx pdu. Size is FrIf_MaxNumberOfTxPDUs */
     extern VAR(uint8, FRIF_VAR_NOINIT) FrIf_TxPduDirtyBytes[];
# else
/*! \var Variable with one bit for each tx pdu. Size is  (FrIf_MaxNumberOfTxPDUs+7)/8 */
     extern VAR(uint8, FRIF_VAR_NOINIT) FrIf_TxPduDirtyFlags[];
# endif

/*! \var Variable with one bit for each tx pdu. If a PDU is transmitted n times in one cycle
    then there are n bits for this PDU. Size is  (FrIf_MaxNumberOfTxFLEs+7)/8 */
     extern VAR(FrIf_NumberOfPduType, FRIF_VAR_NOINIT) FrIf_TxPduWasSentFlags[];
     
/*! \var RAM buffer for TX and RX frames. Declared as array of uint32 as some FlexRay Drivers
    can optimize the data copying if the buffers have proper alignment.*/
     extern VAR(uint32, FRIF_VAR_NOINIT) FrIf_FrameBuffer[];

# if defined(FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON ) 
/*! \var redundant RAM buffer for TX and RX frames. Declared as array of uint32 as some FlexRay Drivers
    can optimize the data copying if the buffers have proper alignment.*/
     extern VAR(uint32, FRIF_VAR_NOINIT) FrIf_RedundantFrameBuffer[];

/*! \var PduInfoType array for redundant received PDUs of a frame. This PDU array is used by the Rx Voting Function. */
     extern VAR(PduInfoType, FRIF_VAR_NOINIT) FrIf_RedundantRxPduInfo[];
     extern P2CONST(PduInfoType, AUTOMATIC, FRIF_DATA) FrIf_RedundantRxPduInfoPtr;
# endif


/*! \var Variable with one byte for each tx pdu having a request counter. 
    Size is  (FrIf_MaxNumberOfTxRequestCounters */
     extern VAR(uint8, FRIF_VAR_NOINIT) FrIf_TxPduTxRequestCounter[];

     extern VAR(PduInfoType, FRIF_VAR_NOINIT) FrIf_PduInfo;

# define FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

# define FRIF_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

     extern CONST(uint8, FRIF_CONST) FrIf_NumberOfJobs;

# if defined (FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT)
     extern CONST(FrIf_TaskScheduleDataType, FRIF_CONST) FrIf_RxTxTaskScheduleData[];
     extern CONSTP2CONST(FrIf_TxHandleType, FRIF_CONST, FRIF_CONST) FrIf_TxHandles[];
     extern CONSTP2CONST(FrIf_TxHandleType, FRIF_CONST, FRIF_CONST) FrIf_RxHandles[];
     extern CONST(FrIf_FrameLayoutElementType, FRIF_CONST) FrIf_RxFrameLayoutElements[];
     extern CONST(FrIf_FrameLayoutElementType, FRIF_CONST) FrIf_TxFrameLayoutElements[];
     extern CONST(FrIf_FrameDescriptorType, FRIF_CONST) FrIf_RxFrameDescriptors[];
     extern CONST(FrIf_FrameDescriptorType, FRIF_CONST) FrIf_TxFrameDescriptors[];
     extern CONST(FrIf_RxPduDescriptorType, FRIF_CONST) FrIf_RxPduDescriptors[];
     extern CONST(FrIf_TxPduDescriptorType, FRIF_CONST) FrIf_TxPduDescriptors[];
     extern CONST(uint8, FRIF_CONST) FrIf_RxCycleMasks[];
     extern CONST(uint8, FRIF_CONST) FrIf_TxCycleMasks[];
# else
     extern CONST(uint32, FRIF_CONST) FrIf_LinktimeCRC;
# endif/* defined(FRIF_CONFIG_VARIANT) && (3u != FRIF_CONFIG_VARIANT) */

/* PRQA L:DECLWITHOUSIZE *//* MD_FrIf_0812 */

# if defined(FRIF_CONFIG_VARIANT) && (1u != FRIF_CONFIG_VARIANT)

/*! \var The maximum number of tx pdu that can be used by any post-build configuration.
    This value is used to dimension the variable FrIf_TxPduDirtyFlags. 
  */
     extern CONST(uint16, FRIF_CONST) FrIf_MaxNumberOfTxPDUs;
/*! \var The maximum number of tx frame layout elements that can be used by any post-build configuration.
    This value is used to dimension the variable FrIf_TxPduWasSentFlags.
  */
     extern CONST(uint16, FRIF_CONST) FrIf_MaxNumberOfTxFLEs;
/*! \var The maximum number of tx frames that can be used by any post-build configuration.
    This value is used to dimension the variable FrIf_TxFrameWasSentFlags. 
  */
     extern CONST(uint16, FRIF_CONST) FrIf_MaxNumberOfTxFrames;
/*! \var The maximum length in bytes of tx and rx frames that can be used by any post-build configuration.
    This value is used to dimension the variable FrIf_FrameBuffer. 
  */
     extern CONST(uint16, FRIF_CONST) FrIf_FramebufferLengthInBytes;
/*! \var The maximum number to tx PDUs having an request counter that can be used by any post-build 
    configuration. This value is used to dimension the variable FrIf_TxPduTxRequestCounter. 
  */
     extern CONST(uint16, FRIF_CONST) FrIf_MaxNumberOfTxRequestCounters;

#  if defined(FRIF_PROD_ERROR_DETECT) && (STD_ON == FRIF_PROD_ERROR_DETECT)
     extern CONST(uint16, FRIF_CONST) FrIf_ErrorId_JLE_Sync;
#  endif

# endif/* defined(FRIF_CONFIG_VARIANT) && (1u != FRIF_CONFIG_VARIANT) */

# if defined(FRIF_CONFIG_VARIANT) && (2u == FRIF_CONFIG_VARIANT)
     extern CONST(uint16, FRIF_CONST) FrIf_MacroTicksPerCycle;
     extern CONST(uint16, FRIF_CONST) FrIf_MacroTicksLengthInNanoSeconds;
     extern CONST(uint16, FRIF_CONST) FrIf_RxRotation;
     extern CONST(uint16, FRIF_CONST) FrIf_TxRotation;
     extern CONST(uint16, FRIF_CONST) FrIf_NumberOfRxPDUs;
     extern CONST(uint16, FRIF_CONST) FrIf_NumberOfTxPDUs;
     extern CONST(uint16, FRIF_CONST) FrIf_NumberOfTxFLEs;
     extern CONST(uint16, FRIF_CONST) FrIf_NumberOfTxFrames;
     extern CONST(FrIf_RxHandleType, FRIF_CONST) FrIf_InvalidRxHandle;
     extern CONST(FrIf_TxHandleType, FRIF_CONST) FrIf_InvalidTxHandle;
     extern CONST(uint8, FRIF_CONST) FrIf_NumberOfChannels;
#  if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) && (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
     extern CONST(uint8, FRIF_CONST) FrIf_UpdateBitBytePos;
#  endif
# endif/* defined(FRIF_CONFIG_VARIANT) && (2u == FRIF_CONFIG_VARIANT) */

# define FRIF_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

#endif
/* FRIF_L_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Lcfg.h
 *********************************************************************************************************************/

/* STOPSINGLE_OF_MULTIPLE */
