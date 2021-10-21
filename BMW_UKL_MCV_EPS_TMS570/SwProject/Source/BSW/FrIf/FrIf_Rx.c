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
/*! \file         FrIf_Rx.c
 *    Component:  MICROSAR FrIf
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Implementation of data reception, according to:
 *                AUTOSAR FlexRay Interface, AUTOSAR Release 3.0
 **********************************************************************************************************************

 **********************************************************************************************************************
 *  \author AUTHOR IDENTITY
 -  -------------------------------------------------------------------------------------------------------------------
 -  Name                          Initials      Company
 -  -------------------------------------------------------------------------------------------------------------------
 -  Klaus Bergdolt                ber           Vctr Informatik GmbH
 -  Oliver Reineke                ore           Vctr Informatik GmbH
 -  -------------------------------------------------------------------------------------------------------------------
 -  \version REVISION HISTORY
 -  -------------------------------------------------------------------------------------------------------------------
 -  Version   Date        Author  Change Id     Description
 -  -------------------------------------------------------------------------------------------------------------------
 -  3.0.0     2007-12-12  ber     -             release of version 3.0.0 
 -  3.0.1     2008-02-22  ber     -             release of version 3.0.1 
 -  3.0.2     2008-03-10  ber     -             fixed order of rx indication calls
 -            2008-03-20  ber     ESCAN00025115 Configuration of FrIf Update Bit for TX PDUs
 -            2008-03-27  ore     -             renamed Fr_RxLSduStatusType to Fr_RxLPduStatusType   
 -            2008-04-02  ber     ESCAN00023644 No changes here
 -            2008-04-03  ber     -             release of version 3.0.2
 -  3.0.3     2008-04-17  ber     ESCAN00026131 No changes here
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
 -  3.0.5     2008-06-09  ore     ESCAN00026972 No changes here
 -            2008-06-09  ore     ESCAN00026341 No changes here
 -            2008-07-08  ore     ESCAN00027356 No changes here
 -            2008-07-09  ore     ESCAN00028155 No changes here
 -            2008-07-11  ore     -             release of version 3.0.5
 -  3.0.6     2008-07-17  ore     ESCAN00027548 No changes here
 -            2008-07-17  ore     -             release of version 3.0.6
 -  3.0.7     2008-07-18  ore     ESCAN00027867 Receive with Direct Buffer Access
 -            2008-07-24  ore     ESCAN00027210 FrIf shall call Fr_PrepareLPdu to enable the driver to use a more 
 *                                              efficient message buffer assignment for RX
 -            2008-07-28  ore     ESCAN00028772 FrIf Single-Controller Optimization
 -            2008-08-01  ore     ESCAN00027451 No changes here
 -            2008-08-07  ore     ESCAN00029068 FrIf does not detect that a received frame is shorter than configured.
 -            2008-08-07  ore     ESCAN00029042 No changes here
 -            2008-08-13  ore     ESCAN00029218 No changes here
 -            2008-08-13  ore     ESCAN00029219 No changes here
 -            2008-08-13  ore     ESCAN00029184 No changes here
 -            2008-08-14  ore     -             unified define usage
 -            2008-08-15  ore     -             release of version 3.0.7
 -  3.0.8     2008-08-22  ore     ESCAN00029101 No changes here
 -            2008-08-22  ore     -             release of version 3.0.8
 -  3.0.9     2008-09-17  ore     -             release of version 3.0.9
 -  3.0.10    2008-10-01  ore     ESCAN00030038 FrIf file name conventions
 -            2008-10-01  ore     ESCAN00030039 FrIf type name conventions
 -            2008-10-01  ore     ESCAN00030040 FrIf variable/function name conventions
 -            2008-10-01  ore     ESCAN00029696 No changes here
 -            2008-10-01  ore     ESCAN00029736 No changes here
 -            2008-11-03  ore     ESCAN00031030 No changes here
 -            2008-11-03  ore     ESCAN00031026 No changes here
 -            2008-11-04  ore     -             release of version 3.0.10
 -  3.1.0     2008-11-10  ore     ESCAN00030776 No changes here
 -            2008-11-10  ore     ESCAN00030577 No changes here
 -            2008-11-10  ore     ESCAN00030264 No changes here
 -            2008-11-10  ore     ESCAN00030764 No changes here
 -            2008-11-17  ore     ESCAN00031345 FrIf indicates PDUs in non received frame areas
 -            2008-11-17  ore     ESCAN00030264 No changes here
 -            2008-11-18  ore     -             added MISRA violation comments
 -            2008-11-24  ore     ESCAN00031360 No changes here
 -            2008-11-24  ore     -             fixed code-review findings   
 -            2008-12-01  ore     ESCAN00031710 No changes here
 -            2008-12-08  ore     ESCAN00031843 No changes here
 -            2008-12-19  ore     -             release of version 3.1.0
 -  3.2.0     2009-02-02  ore     ESCAN00032463 No changes here
 -            2009-02-10  ore     ESCAN00032944 No changes here
 -            2009-02-17  ore     ESCAN00033102 No changes here
 -            2009-02-18  ore     ESCAN00027867 Receive with Direct Buffer Access
 -            2009-02-18  ore     ESCAN00033318 No changes here
 -            2009-02-18  ore     ESCAN00033145 No changes here
 -            2009-02-18  ore     ESCAN00033220 The functions FrIf_RxTask_0 and FrIf_TxTask_0 shall have standard 
 *                                              return values.
 -            2009-02-18  ore     ESCAN00032895 No changes here
 -            2009-02-18  ore     ESCAN00033309 Remove FrIf memory class macros to reduce the number of misra 
 *                                              violations.
 -            2009-02-18  ore     ESCAN00031278 No changes here
 -            2009-02-25  ore     ESCAN00033399 Simplify FrIf include structure
 -            2009-02-25  ore     ESCAN00033402 The FrIf source and header files are not implemented as SingleSource.
 -            2009-02-26  ore     ESCAN00033441 No changes here
 -            2009-02-26  ore     ESCAN00032715 No changes here
 -            2009-03-05  ore     ESCAN00033650 No changes here
 -            2009-03-06  ore     ESCAN00033651 Unify DET implementation
 -            2009-03-06  ore     ESCAN00033665 No changes here
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
 -            2009-07-20  ore     ESCAN00036397 FlexRay Interface shall support FIFOs (Asr 4.0)
 -            2009-07-14  ore     ESCAN00035990 Pointer in FrIf_Init() is not pointer to the Flexray Init configuration
 -            2009-07-14  ore     ESCAN00035399 No changes here
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
 -            2009-09-08  ore     ESCAN00035396 The FrIf bitarrays in postbuild structures are not supported by the 
 *                                              GenTool_GenyFrameworkPostbuildconfig component.
 -            2009-09-08  ore     ESCAN00037643 No changes here
 -            2009-09-08  ore     ESCAN00037633 Implement wrapper functions for FrTpIso with AUTOSAR 4.0 Buffer API
 -            2009-09-21  ore     ESCAN00036013 No changes here
 -            2009-11-02  ore     ESCAN00038914 FrIf_StartJobExecution routine shall call Fr_PrepareLPdu for all Rx and 
 *                                              Tx handles to flush the complete hardware FIFO
 -            2009-11-02  ore     ESCAN00038855 No changes here
 -            2009-11-03  ore     ESCAN00038930 The revision history of all source and header files shall contain all 
 *                                              implementation relevant ClearQuest issues of the FrIf.
 -            2009-11-17  ore     ESCAN00039212 No changes here
 -            2009-11-30  ore     ESCAN00039411 No changes here
 -            2009-12-07  ore     ESCAN00039607 Add code-size optimization for configurations with uniform update byte usage
 -            2009-12-07  ore     ESCAN00039609 No changes here
 -            2009-12-07  ore     -             release of version 3.4.0 
 -  3.5.0     2010-02-01  ore     -             Removed obsolete AUTOSAR 2.1 FlexRay IL Support 
 -            2010-02-01  ore     ESCAN00040508 No changes here
 -            2010-02-16  ore     ESCAN00040867 No changes here
 -            2010-02-18  ore     ESCAN00040951 No changes here
 -            2010-02-18  ore     ESCAN00040960 No changes here
 -            2010-02-22  ore     ESCAN00039809 Store the update byte position as link-time variable or pre-compile define
 -            2010-03-18  ore     ESCAN00041666 No changes here
 -            2010-03-24  ore     ESCAN00041766 No changes here
 -            2010-03-24  ore     ESCAN00041788 Compile error because integer conversion resulted in a change of sign
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
 -            2010-07-29  ore     ESCAN00044336 No changes here 
 -            2010-07-29  ore     ESCAN00044339 No changes here 
 -            2010-08-02  ore     -             Changed QAC justifications to be CDK compliant
 -            2010-08-03  ore     -             release of version 3.6.0 
 -  3.6.1     2010-09-22  ore     ESCAN00044465 No changes here 
 -            2010-09-22  ore     ESCAN00045547 No changes here 
 -            2010-09-22  ore     -             release of version 3.6.1
 -  3.7.0     2010-11-02  ore     ESCAN00045650 No changes here 
 -            2010-11-02  ore     ESCAN00046417 No changes here 
 -            2010-11-02  ore     ESCAN00046257 No changes here 
 -            2010-11-05  ore     ESCAN00046607 Add DualChannelRedundancy support according to Bugzillla 42025.
 -            2010-11-16  ore     -             Added additional PcLint and QAC justifications
 -            2010-11-16  ore     ESCAN00046950 No changes here 
 -            2010-11-25  ore     ESCAN00046093 AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
 -            2010-11-26  ore     ESCAN00047186 No changes here 
 -            2010-12-01  ore     ESCAN00047302 No changes here 
 -            2010-12-01  ore     ESCAN00047327 No changes here 
 -            2011-01-27  ore     ESCAN00048244 No changes here 
 -            2011-01-27  ore     -             release of version 3.7.0
 -  3.7.1     2011-02-23  ore     ESCAN00048836 The actual PduLength of Rx Pdus is not given to the upper layer if 
 *                                              DualChannelRedundancySupport and UsePduInfoType is enabled
 -            2011-03-16  ore     -             release of version 3.7.1
 -  3.7.2     2011-05-02  ore     ESCAN00049388 No changes here 
 -            2011-05-02  ore     -             release of version 3.7.2
 -  3.7.3     2011-09-20  ore     ESCAN00051840 No changes here 
 -            2011-09-20  ore     -             release of version 3.7.3
 -  3.7.4     2011-10-25  ore     ESCAN00054422 No changes here 
 -            2011-10-25  ore     -             release of version 3.7.4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrIf_Priv.h"
# include "Fr_Ext.h"            /* for FR_VENABLE_RX_INTERRUPT */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if ( IF_ASRIFFR_VERSION != 0x0307u )
# error "The included header FrIf.h is incompatible with the FrIf_Rx.c version."
#endif
#if ( IF_ASRIFFR_RELEASE_VERSION != 0x04u )
# error "The included header FrIf.h is incompatible with the FrIf_Rx.c release version."
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define FRIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

/**********************************************************************************************************************
  FrIf_Receive
**********************************************************************************************************************/
/*! \brief      Perform reception for the frame that is described by the frame descriptor with index Handle.
 *  \see        The function is called by the FrIf_RxTask_0() and ApplFrDrv_ISR_Rx()
 *  \param[in]  FrameDescriptorPtr:    The pointer to the frame descriptor                                           
 *  \return     FR_NOT_RECEIVED or FR_RECEIVED depending on whether a frame was received.
 *  \note       -
 *********************************************************************************************************************/
FUNC(Fr_RxLPduStatusType, FRIF_CODE) FrIf_Receive(
                                          FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr,
                                          uint16 Handle
  )
{
  Std_ReturnType Result;
  Fr_RxLPduStatusType Fr_LPduStatus = FR_NOT_RECEIVED;
  /* PRQA S 0310 1 *//* MD_FrIf_0310 */
  P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) receiveBuffer = FRIF_GET_FRAMEBUFFER();  

  /* initialize sdu length with configured frame length,         */
  /* driver will use this information to prevent buffer overflow */
  uint8 Fr_LPduLength = FrameDescriptorPtr->FrameLength;
#if defined(FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON ) 
  Std_ReturnType redundantResult;
  Fr_RxLPduStatusType Fr_RedundantLPduStatus = FR_NOT_RECEIVED;
  /* PRQA S 0310 1 *//* MD_FrIf_0310 */
  P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) redundantReceiveBuffer = FRIF_GET_REDUNDANT_FRAMEBUFFER();  
  
  uint8 Fr_RedundantLPduLength = FrameDescriptorPtr->FrameLength;    
  FrIf_TxHandleType RedundantHandle = FrameDescriptorPtr->FrameHandle;
  uint8 selectedPduIndex = 0;
#endif
#if defined ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE)
  Result = Fr_ReceiveRxLPdu_DBA(
    0, 
    Handle, 
    &receiveBuffer, 
    &Fr_LPduStatus, 
    &Fr_LPduLength);
#else
  Result = Fr_ReceiveRxLPdu(
    0,
    Handle,
    receiveBuffer,
    &Fr_LPduStatus,
    &Fr_LPduLength);
#endif /* ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE) */
#if defined (FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON ) 
  if(RedundantHandle  != FrIf_GetInvalidRxHandle())
  {
# if defined ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE)
#  if defined (FRIF_CPU_TMS470) && (FR_VCC_USE_FTU == STD_ON)
#    error "The dual channel redundancy feature may not be used on TMS470 if the Fr components uses the FTU."
#  else
    redundantResult = Fr_ReceiveRxLPdu_DBA(
        0, 
        RedundantHandle, 
        &redundantReceiveBuffer, 
        &Fr_RedundantLPduStatus, 
        &Fr_RedundantLPduLength);
#  endif
# else
    redundantResult = Fr_ReceiveRxLPdu(
        0,
        RedundantHandle,
        redundantReceiveBuffer,
        &Fr_RedundantLPduStatus,
        &Fr_RedundantLPduLength);    
# endif /* ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE) */
    {
      boolean HandleIsReceived = (boolean)((FR_NOT_RECEIVED != Fr_LPduStatus) && (E_OK == Result));
      boolean RedundantHandleIsReceived = (boolean)((FR_NOT_RECEIVED != Fr_RedundantLPduStatus) && (E_OK == redundantResult));
      if(HandleIsReceived || RedundantHandleIsReceived)
      {
        sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;
        uint16_least FrameLayoutElementIndex = (uint16_least) (FrameDescriptorPtr->FirstFrameLayoutElementHandle);
        
        if (TRUE == HandleIsReceived)
        {
          FRIF_FRAME_RECEIVED(Handle, receiveBuffer, Fr_LPduLength, &PduNumber);
        }
        if (TRUE == RedundantHandleIsReceived)
        {
          FRIF_FRAME_RECEIVED(RedundantHandle, redundantReceiveBuffer, Fr_RedundantLPduStatus, &PduNumber);
        }

        for(; PduNumber >= (sint16_least) 0; PduNumber--)
        {
          FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) FrameLayoutElementPtr = &FrIf_GetRxFrameLayoutElement(FrameLayoutElementIndex);
          boolean PduIsValid = HandleIsReceived;
          boolean RedudantPduIsValid = RedundantHandleIsReceived;
          uint8 CurrentPduLength = Fr_LPduLength-FrameLayoutElementPtr->ByteOffsetInFrame;
  
          if((uint8_least) 0 != FrameLayoutElementPtr->UpdateBitMask)
          {
            if ( (PduNumber != (((sint16_least)(FrameDescriptorPtr->NumberOfPdus)) - 1)) 
                 || ((Fr_LPduLength - (FrameLayoutElementPtr->ByteOffsetInFrame)) > (FrIf_GetRxPduDescriptor(FrameLayoutElementPtr->PduHandle).PduLength))
               )
            {
              CurrentPduLength = FrIf_GetRxPduDescriptor(FrameLayoutElementPtr->PduHandle).PduLength;
            }

            PduIsValid  = (boolean)(  
#   if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) 
#    if (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
                                    receiveBuffer[FrIf_GetUpdateBitBytePos()]
#    else
                                    receiveBuffer[FrameDescriptorPtr->UpdateBitBytePos] 
#    endif /* (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON) */
#   else
                                    receiveBuffer[FrameLayoutElementPtr->UpdateBitBytePos] 
#   endif /* ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) */
                                    & FrameLayoutElementPtr->UpdateBitMask);
            RedudantPduIsValid  = (boolean)(  
#    if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) 
#      if (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
                                    redundantReceiveBuffer[FrIf_GetUpdateBitBytePos()]
#      else
                                    redundantReceiveBuffer[FrameDescriptorPtr->UpdateBitBytePos] 
#      endif /* (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON) */
#    else
                                    redundantReceiveBuffer[FrameLayoutElementPtr->UpdateBitBytePos] 
#    endif /* ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) */
                                    & FrameLayoutElementPtr->UpdateBitMask);        
          }
          
          if ((FALSE != PduIsValid) && (Fr_LPduLength > FrameLayoutElementPtr->ByteOffsetInFrame))
          {
            FrIf_RedundantRxPduInfo[0].SduDataPtr = &receiveBuffer[FrameLayoutElementPtr->ByteOffsetInFrame];            
            FrIf_RedundantRxPduInfo[0].SduLength = CurrentPduLength;
          }
          else
          {
            FrIf_RedundantRxPduInfo[0].SduDataPtr = NULL_PTR;
            FrIf_RedundantRxPduInfo[0].SduLength = 0;
          }

          if ((FALSE != RedudantPduIsValid) && (Fr_RedundantLPduLength > FrameLayoutElementPtr->ByteOffsetInFrame))
          {
            FrIf_RedundantRxPduInfo[1].SduDataPtr = &redundantReceiveBuffer[FrameLayoutElementPtr->ByteOffsetInFrame]; 
            FrIf_RedundantRxPduInfo[1].SduLength = CurrentPduLength;
          }   
          else
          {
            FrIf_RedundantRxPduInfo[1].SduDataPtr = NULL_PTR;
            FrIf_RedundantRxPduInfo[1].SduLength = 0;
          }

          if (E_OK == FrIf_RxVotingFunction(&FrIf_RedundantRxPduInfoPtr, FRIF_MAX_NUMBER_OF_REDUNDANT_PDUS, &selectedPduIndex))
          {
            FrIf_RxIndicationFunctions(FrIf_GetRxPduDescriptor(FrameLayoutElementPtr->PduHandle).PduConfig & FrIf_RxPduOwner,
               FrIf_GetRxPduDescriptor(FrameLayoutElementPtr->PduHandle).Id,
                FrIf_RedundantRxPduInfo[selectedPduIndex].SduDataPtr
#    if defined (FRIF_USEPDUINFOTYPE) && (FRIF_USEPDUINFOTYPE == STD_ON)          
                ,(PduLengthType)FrIf_RedundantRxPduInfo[selectedPduIndex].SduLength
#    endif
                );
          }
          FrameLayoutElementIndex++;
        }
#  if defined ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE)
        if (TRUE == HandleIsReceived) 
        {
          (void)Fr_UnlockRxLPdu_DBA(0, Handle);
        }        
        if (TRUE == RedundantHandleIsReceived)
        {
          (void)Fr_UnlockRxLPdu_DBA(0, RedundantHandle);
        }

        /* if (FR_RECEIVED_MORE_DATA_AVAILABLE == Fr_LPduStatus) */
        /*  note: DualChannelRedundancy Frames may not lie within a FIFO range! Hence the redundant frametriggering are not processed again. */        
#  endif /* ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE) */
      }
    }
  }
  else  
#endif /* (FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON )  */

  if(E_OK == Result)
  {
#if defined ( FRIF_FIFO_SUPPORT_ENABLE ) && (STD_ON == FRIF_FIFO_SUPPORT_ENABLE)
    while(FR_NOT_RECEIVED != Fr_LPduStatus)
#else
    if(FR_RECEIVED == Fr_LPduStatus)
#endif
    {
      sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;
      uint16_least FrameLayoutElementIndex = (uint16_least) (FrameDescriptorPtr->FirstFrameLayoutElementHandle);
#if defined ( FRIF_FRAME_RECEIVED )
      /* macro can be defined to plugin monitoring or testing */
      FRIF_FRAME_RECEIVED(Handle, receiveBuffer, Fr_LPduLength, &PduNumber);
#endif
      for(; PduNumber >= (sint16_least) 0; PduNumber--)
      {
        FRIF_P2CONSTCFG(FrIf_FrameLayoutElementType) FrameLayoutElementPtr = &FrIf_GetRxFrameLayoutElement(FrameLayoutElementIndex);
        boolean PduIsValid = TRUE;
        if((uint8_least) 0 != FrameLayoutElementPtr->UpdateBitMask)
        {
          PduIsValid  = (boolean)(  
#if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) 
#  if (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
                                  receiveBuffer[FrIf_GetUpdateBitBytePos()]
#  else
                                  receiveBuffer[FrameDescriptorPtr->UpdateBitBytePos] 
#  endif /* (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON) */
#else
                                  receiveBuffer[FrameLayoutElementPtr->UpdateBitBytePos] 
#endif /* ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON ) */
                                  & FrameLayoutElementPtr->UpdateBitMask);
        }
        if (    (FALSE != PduIsValid) 
             && (Fr_LPduLength > FrameLayoutElementPtr->ByteOffsetInFrame))
        {
#if defined (FRIF_USEPDUINFOTYPE) && (FRIF_USEPDUINFOTYPE == STD_ON)          
          uint8 CurrentPduLength;
          if ( (PduNumber != (((sint16_least)(FrameDescriptorPtr->NumberOfPdus)) - 1)) 
                 || ((Fr_LPduLength - (FrameLayoutElementPtr->ByteOffsetInFrame)) > (FrIf_GetRxPduDescriptor(FrameLayoutElementPtr->PduHandle).PduLength))
             )
          {
            CurrentPduLength = FrIf_GetRxPduDescriptor(FrameLayoutElementPtr->PduHandle).PduLength;
          }
          else
          {
            CurrentPduLength = Fr_LPduLength-FrameLayoutElementPtr->ByteOffsetInFrame;
          }

          FrIf_RxIndicationFunctions(FrIf_GetRxPduDescriptor(FrameLayoutElementPtr->PduHandle).PduConfig & FrIf_RxPduOwner,
             FrIf_GetRxPduDescriptor(FrameLayoutElementPtr->PduHandle).Id,
                                     &receiveBuffer[FrameLayoutElementPtr->ByteOffsetInFrame],
                                     CurrentPduLength);
#else 
          FrIf_RxIndicationFunctions(FrIf_GetRxPduDescriptor(FrameLayoutElementPtr->PduHandle).PduConfig & FrIf_RxPduOwner,
             FrIf_GetRxPduDescriptor(FrameLayoutElementPtr->PduHandle).Id,
                                     &receiveBuffer[FrameLayoutElementPtr->ByteOffsetInFrame]);
#endif /* defined (FRIF_USEPDUINFOTYPE) && (FRIF_USEPDUINFOTYPE == STD_ON) */
        }
        FrameLayoutElementIndex++;
      }
#if defined ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE)
      /* note: Fr_UnlockRxLpdu is called for each Fr_ReceiveRxLPdu_DBA request if FIFO is enabled and Drv returned FR_RECEIVED_MORE_DATA_AVAILABLE */
      (void)Fr_UnlockRxLPdu_DBA(0, Handle);
#endif
#if defined ( FRIF_FIFO_SUPPORT_ENABLE ) && (STD_ON == FRIF_FIFO_SUPPORT_ENABLE)
      if(FR_RECEIVED_MORE_DATA_AVAILABLE == Fr_LPduStatus)
      {
# if defined ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE)
        Result = Fr_ReceiveRxLPdu_DBA(
          0, 
          Handle, 
          &receiveBuffer, 
          &Fr_LPduStatus, 
          &Fr_LPduLength);
# else
        Result = Fr_ReceiveRxLPdu(
          0,
          Handle,
          receiveBuffer,
          &Fr_LPduStatus,
          &Fr_LPduLength);
# endif /* if defined ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE) */        
        if (E_NOT_OK == Result)
        {
          Fr_LPduStatus = FR_NOT_RECEIVED;
          /* return from while */
        }
      }
      else
      {
        /* FR_RECEIVED == Fr_LPduStatus: return from while */
        break;
      }
#endif /* if defined ( FRIF_FIFO_SUPPORT_ENABLE ) && (STD_ON == FRIF_FIFO_SUPPORT_ENABLE) */
    }
  }
  else
  {
    Fr_LPduStatus = FR_NOT_RECEIVED;
  }
  return Fr_LPduStatus;
}

/**********************************************************************************************************************
  FrIf_RxTask_0
**********************************************************************************************************************/
/*! \brief      Perform reception for the current job.
 *  \see        The function is called by the FrIf_JobListExec_0 function of the FrIf
 *  \param[in]  void
 *  \return     E_OK:       The call of the service FrIf_RxTask_0() returns E_OK if the FrIf state was FRIF_ONLINE                             
                E_NOT_OK:   The call of the service FrIf_RxTask_0() returns E_NOT_OK if the FrIf state was 
                            FRIF_OFFLINE
 *  \note       -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_RxTask_0(void)
{
  Std_ReturnType Result = E_OK;
  const uint16 maxColumn = FrIf_GetJobData(FrIf_Status.CurrentJobNumber).MaxColumnNumber;
  uint16 columnNumber = FrIf_GetJobData(FrIf_Status.CurrentJobNumber).MinColumnNumber;
  /* If the rx task for the dynamic segment is scheduled as 1. rx task (i.e. start of cycle) it has
     to use the previos cycle as row index for the rx matrix.
     This rx task has the following properties: MaxColumn = NrOfRxColumns -1 */
  for(; columnNumber <= maxColumn; columnNumber++)
  {
    const uint16 Handle = FrIf_GetRxColumn(columnNumber)
               [  FrIf_Status.CurrentCycle 
                & FrIf_GetRxCycleNumberMask(columnNumber)
               ];

    if(FrIf_GetInvalidRxHandle() != Handle)
    {
      FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetRxFrameDescriptor(Handle);

#if defined ( FR_VENABLE_RX_INTERRUPT ) && ( STD_ON == FR_VENABLE_RX_INTERRUPT )
      if(FALSE == (FrameDescriptorPtr->FrameConfig & FrIf_FrameIsInterruptMode))
#endif
      {
        (void)FrIf_Receive(FrameDescriptorPtr, Handle);
      }
    }
  }
  return Result;
}

#if defined ( FR_VENABLE_RX_INTERRUPT ) && ( STD_ON == FR_VENABLE_RX_INTERRUPT )
/**********************************************************************************************************************
  ApplFrDrv_ISR_Rx
**********************************************************************************************************************/
/*! \brief      This is a call-back function that is called by the FlexRay Driver when a frame has generated an 
                interrupt. 
 *  \param[in]  Fr_CtrlIdx: The index of the controller that generated the interrupt
 *  \param[in]  Column:     The number of the column in the schedule matrix.
 *  \return     E_OK:       The call of the service ApplFrDrv_ISR_Rx() returns E_OK if the FrIf state was FRIF_ONLINE.
                E_NOT_OK:   The call of the service ApplFrDrv_ISR_Rx() returns E_NOT_OK if the FrIf state was 
                            FRIF_OFFLINE.
 *  \see        The function is called by AUTOSAR Fr
 *  \note       -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) ApplFr_ISR_Rx(uint8 Fr_CtrlIdx, uint16 Column)
{
  uint16 MacroTicks;
  uint8 CurrentCycle;
  Std_ReturnType ErrorState = E_NOT_OK;
  if(FALSE != FrIf_IsOnline(Fr_CtrlIdx))
  {
    ErrorState = Fr_GetGlobalTime(0, &CurrentCycle, &MacroTicks);
    if(E_OK == ErrorState)
    {
      uint16 Handle = FrIf_GetRxColumn(Column)[CurrentCycle & FrIf_GetRxCycleNumberMask(Column)];
      boolean Received = FALSE;
      Fr_RxLPduStatusType ReceiveStatus = FR_NOT_RECEIVED;

      if(FrIf_GetInvalidRxHandle() != Handle)
      {
        /* call FrIf_Receive with ProvideNullIndication==FALSE as we may use the wrong handle */
        /* because of a wrong cycle value. */
        FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetRxFrameDescriptor(Handle);
        ReceiveStatus = FrIf_Receive(FrameDescriptorPtr, Handle);

        if(FR_RECEIVED == ReceiveStatus)
        {
          Received = TRUE;
        }
      }
      if(FALSE == Received)
      {
        /* The frame was not received in the current cycle, but in the previous cycle */
        CurrentCycle = PREVIOUS_CYCLE(CurrentCycle);
        Handle = FrIf_GetRxColumn(Column)[CurrentCycle & FrIf_GetRxCycleNumberMask(Column)];
        if(FrIf_GetInvalidRxHandle() != Handle)
        {
          FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetRxFrameDescriptor(Handle);
          ReceiveStatus = FrIf_Receive(FrameDescriptorPtr, Handle);

          if(FR_RECEIVED != ReceiveStatus)
          {
            ErrorState = E_NOT_OK;
          }
        }
      }
    }
    else
    {
      ErrorState = E_NOT_OK;
    }
  }
  return ErrorState;
}
#endif /* if defined ( FR_VENABLE_RX_INTERRUPT ) && ( STD_ON == FR_VENABLE_RX_INTERRUPT ) */

#define FRIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Rx.c
 *********************************************************************************************************************/

/* STOPSINGLE_OF_MULTIPLE */
