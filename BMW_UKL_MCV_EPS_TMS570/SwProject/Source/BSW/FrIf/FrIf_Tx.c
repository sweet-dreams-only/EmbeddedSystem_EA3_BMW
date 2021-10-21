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
/*! \file         FrIf_Tx.c
 *    Component:  MICROSAR FrIf
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Implementation of data transmission, according to:
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
 *  \version REVISION HISTORY
 -  -------------------------------------------------------------------------------------------------------------------
 -  Version   Date        Author  Change Id     Description
 -  -------------------------------------------------------------------------------------------------------------------
 -  3.0.0     2007-12-12  ber     -             release of version 3.0.0 
 -  3.0.1     2008-02-08  ber     -             Adapted TxPduWasSentFlags to new configuration data layout
 -            2008-02-22  ber     -             release of version 3.0.1 
 -  3.0.2     2008-03-10  ber     -             FrIf_Transmit checks for null pointer inside PduInfo
 -            2008-03-20  ber     ESCAN00025115 Configuration of FrIf Update Bit for TX PDUs
 -            2008-03-27  ore     -             renamed Fr_RxLSduStatusType to Fr_RxLPduStatusType   
 -            2008-04-02  ber     ESCAN00023644 No changes here
 -            2008-04-03  ber     -             release of version 3.0.2
 -  3.0.3     2008-04-18  ber     ESCAN00025799 Tx call back functions called with wrong PDU-ID in case some PDUs are 
 *                                              configured for immediate transmission
 -            2008-04-18  ber     ESCAN00026131 Memory Access Violation in embedded code during FrIf job list execution
 -            2008-04-18  ber     -             release of version 3.0.3 
 -  3.0.4     2008-04-25  ore     ESCAN00026130 No changes here
 -            2008-04-25  ore     ESCAN00026216 No changes here
 -            2008-04-25  ore     ESCAN00026256 Rename files and #include statements according coding styles
 -            2008-04-28  ore     ESCAN00026445 No changes here
 -            2008-04-28  ore     ESCAN00026447 No changes here
 -            2008-04-28  ore     ESCAN00026449 No changes here
 -            2008-05-15  ore     ESCAN00026651 No changes here
 -            2008-05-19  ore     ESCAN00026973 Inconsistent Memory Mapping
 -            2008-05-21  ore     -             release of version 3.0.4
 -  3.0.5     2008-06-09  ore     ESCAN00026972 No changes here
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
 -            2008-08-13  ore     ESCAN00029184 Call TxConf-callbacks in case of stopping or resynchronizing the FrIf-JobList
 -            2008-08-13  ore     -             added minor optimizations (PduDirtyByte) to reduce the execution times 
 *                                              of the FrIf Tx tasks.
 -            2008-08-14  ore     -             unified define usage
 -            2008-08-15  ore     -             release of version 3.0.7
 -  3.0.8     2008-08-22  ore     ESCAN00029101 No changes here
 -            2008-08-22  ore     -             release of version 3.0.8
 -  3.0.9     2008-09-17  ore     -             release of version 3.0.9
 -  3.0.10    2008-10-01  ore     -             Apdapted TxConf-Handling to support configurable task times
 -            2008-10-01  ore     ESCAN00030038 FrIf file name conventions
 -            2008-10-01  ore     ESCAN00030039 FrIf type name conventions
 -            2008-10-01  ore     ESCAN00030040 FrIf variable/function name conventions
 -            2008-10-01  ore     ESCAN00029696 No changes here
 -            2008-10-01  ore     ESCAN00029736 No changes here
 -            2008-11-03  ore     ESCAN00031030 Unused frame parts are not always initialized
 -            2008-11-03  ore     ESCAN00031026 No changes here
 -            2008-11-04  ore     -             release of version 3.0.10
 -  3.1.0     2008-11-10  ore     ESCAN00030776 No changes here
 -            2008-11-10  ore     ESCAN00030577 Clear PduConfCounter in case Fr_CheckTxLPduStatus returns E_NOT_OK
 -            2008-11-10  ore     ESCAN00030264 No changes here
 -            2008-11-10  ore     ESCAN00030764 No changes here
 -            2008-11-17  ore     ESCAN00031345 No changes here
 -            2008-11-17  ore     ESCAN00030264 No changes here
 -            2008-11-18  ore     -             added MISRA violation comments
 -            2008-11-24  ore     -             fixed code-review findings   
 -            2008-11-24  ore     ESCAN00031360 No changes here
 -            2008-12-01  ore     ESCAN00031710 Rollback TxRequestCounter in case of FrDrv-API errors
 -            2008-12-08  ore     ESCAN00031843 No changes here
 -            2008-12-19  ore     -             release of version 3.1.0
 -  3.2.0     2009-02-02  ore     ESCAN00032463 No changes here
 -            2009-02-10  ore     ESCAN00032944 No changes here
 -            2009-02-17  ore     ESCAN00033102 FrIf_Transmit does not return E_NOT_OK in case the FrIf_Status is 
 *                                              FRIF_OFFLINE
 -            2009-02-18  ore     ESCAN00027867 No changes here
 -            2009-02-18  ore     ESCAN00033318 No changes here
 -            2009-02-18  ore     ESCAN00033145 Transmit with Direct Buffer Access
 -            2009-02-18  ore     ESCAN00033220 The functions FrIf_RxTask_0 and FrIf_TxTask_0 shall have standard 
 *                                              return values.
 -            2009-02-18  ore     ESCAN00032895 No changes here
 -            2009-02-18  ore     ESCAN00033309 Remove FrIf memory class macros to reduce the number of misra 
 *                                              violations.
 -            2009-02-18  ore     ESCAN00031278 No changes here
 -            2009-02-25  ore     ESCAN00033399 Simplify FrIf include structure
 -            2009-02-25  ore     ESCAN00033402 The FrIf source and header files are not implemented as SingleSource.
 -            2009-02-26  ore     ESCAN00033441 The FrIf source and header files don't use the Compiler-Abstraction 
 *                                              keyword STATIC.
 -            2009-02-26  ore     ESCAN00032715 No changes here
 -            2009-03-05  ore     ESCAN00033650 No changes here
 -            2009-03-06  ore     -             Renamed TxConfirmation routine to FrIf_TxConfirmation
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
 -            2009-07-20  ore     ESCAN00036397 No changes here
 -            2009-07-14  ore     ESCAN00035990 Pointer in FrIf_Init() is not pointer to the Flexray Init configuration
 -            2009-07-14  ore     ESCAN00035399 The static header files of the FrIf don't include the Memmap.h file 
 -            2009-07-15  ore     ESCAN00036426 No changes here
 -            2009-07-15  ore     ESCAN00036427 No changes here
 -            2009-07-15  ore     ESCAN00036429 No changes here
 -            2009-07-15  ore     ESCAN00036451 No changes here
 -            2009-07-16  ore     ESCAN00036471 Add precompile switch to enable/disable the usage of the request counter 
 *                                              handling
 -            2009-07-17  ore     ESCAN00034459 No changes here
 -            2009-07-28  ore     ESCAN00036120 No changes here
 -            2009-07-31  ore     ESCAN00036776 FrIf_StopJobListExec can take some seconds if the FrIf is re-initialized
 *                                              with a new PB-config at runtime
 -            2009-07-31  ore     -             release of version 3.3.0 
 -  3.4.0     2009-08-24  ore     ESCAN00036905 FrIf does not support TX frames with more than 8 PDUs
 -            2009-08-24  ore     ESCAN00037257 No changes here
 -            2009-09-08  ore     ESCAN00035396 The FrIf bitarrays in postbuild structures are not supported by the 
 *                                              GenTool_GenyFrameworkPostbuildconfig component.
 -            2009-09-08  ore     ESCAN00037643 No changes here
 -            2009-09-08  ore     ESCAN00037633 Implement wrapper functions for FrTpIso with AUTOSAR 4.0 Buffer API
 -            2009-09-21  ore     ESCAN00036013 Similar DET Usage
 -            2009-10-27  ore     ESCAN00038513 Use E_PENDING in FrIf_Transmit if data is copied in PduR_FrIfTriggerTransmit, 
 *                                              FrNm_TriggerTransmit and FrTp_TriggerTransmit
 -            2009-11-02  ore     ESCAN00038914 No changes here
 -            2009-11-02  ore     ESCAN00038855 No changes here
 -            2009-11-03  ore     ESCAN00038930 The revision history of all source and header files shall contain all 
 *                                              implementation relevant ClearQuest issues of the FrIf.
 -            2009-11-17  ore     ESCAN00039212 No changes here
 -            2009-11-30  ore     ESCAN00039411 FrIf does not set update bit if last PDU of frame has no update bit
 -            2009-12-07  ore     ESCAN00039607 Add code-size optimization for configurations with uniform update byte usage
 -            2009-12-07  ore     ESCAN00039609 No changes here
 -            2009-12-07  ore     -             release of version 3.4.0 
 -  3.5.0     2010-01-11  ore     -             Added additional code-size and runtime optimizations
 -            2010-02-01  ore     -             Removed obsolete AUTOSAR 2.1 FlexRay IL Support 
 -            2010-02-01  ore     ESCAN00040508 No changes here
 -            2010-02-16  ore     ESCAN00040867 The TxRequestCounter shall only decremented if a frame in the dynamic segment 
 *                                              has not been suppressed
 -            2010-02-18  ore     ESCAN00040951 No changes here
 -            2010-02-18  ore     ESCAN00040960 No changes here
 -            2010-02-22  ore     ESCAN00039809 Store the update byte position as link-time variable or pre-compile define
 -            2010-03-18  ore     ESCAN00041666 Compile error for missing C_COMP_x xx_yyy definition if v_cfg.h is not included
 *                                              by Compiler_Cfg.h
 -            2010-03-24  ore     ESCAN00041766 Support return value E_PENDING when calling Fr_RequestBuffer_DBA routine
 -            2010-03-24  ore     ESCAN00041788 Compile error because integer conversion resulted in a change of sign
 -            2010-03-30  ore     ESCAN00041966 No changes here
 -            2010-04-22  ore     ESCAN00042422 No changes here
 -            2010-05-05  ore     ESCAN00041396 Reduce the duration of critical sections of the FrIf when the FrIfJobList
 *                                              execution goes out of sync 
 -            2010-05-05  ore     -             release of version 3.5.0 
 -  3.6.0     2010-05-19  ore     ESCAN00042989 No changes here
 -            2010-05-28  ore     ESCAN00043268 No changes here 
 -            2010-06-24  ore     ESCAN00043567 No changes here 
 -            2010-06-24  ore     ESCAN00043569 No changes here 
 -            2010-07-07  ore     -             Fixed function descriptions so that they are correctly considered by Doxygen
 -            2010-07-22  ore     ESCAN00042986 Add feature to support a delayed TxConfirmation for a FrIf Tx Job
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
 -            2010-11-16  ore     ESCAN00046950 Configurable TxConfirmation CommunicationOperation assignment (AR3-1229)
 -            2010-11-25  ore     ESCAN00046093 AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
 -            2010-11-26  ore     ESCAN00047186 No changes here 
 -            2010-12-01  ore     ESCAN00047302 No changes here 
 -            2010-12-01  ore     ESCAN00047327 Missing confirmation in case of immediate transmission in context of TxConfirmation
 -            2011-01-27  ore     ESCAN00048244 No changes here 
 -            2011-01-27  ore     -             release of version 3.7.0
 -  3.7.1     2011-02-23  ore     ESCAN00048836 No changes here 
 -            2011-05-02  ore     -             All component specific MISRA deviations are now justified in FrIf.c
 -            2011-03-16  ore     -             release of version 3.7.1
 -  3.7.3     2011-09-20  ore     ESCAN00051840 No changes here 
 -            2011-09-20  ore     -             release of version 3.7.3
 -  3.7.4     2011-10-25  ore     ESCAN00054422 No changes here 
 -            2011-10-25  ore     -             release of version 3.7.4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrIf_Priv.h"
# include "Fr_Ext.h"            /* for FR_VENABLE_TX_INTERRUPT */
#include "v_cfg.h"              /* for v_def.h    */
#include "v_def.h"              /* for vstdlib.h  */
#include "vstdlib.h"            /* for VStdMemSet */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if ( IF_ASRIFFR_VERSION != 0x0307u )
# error "The included header FrIf.h is incompatible with the FrIf_Tx.c version."
#endif
#if ( IF_ASRIFFR_RELEASE_VERSION != 0x04u )
# error "The included header FrIf.h is incompatible with the FrIf_Tx.c release version."
#endif

/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1  */
/*lint -e613 */ /* Suppress ID613 due to MD_FrIf_0505 */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define FRIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

#if (STD_OFF == FRIF_PDUDIRTYBYTE_USAGE)
FRIF_DECLARE_BITVECTOR_LOOKUP_TABLE_SET_BIT;
#endif

#define FRIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FRIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

/* declaration of FrIf_TxConfirmation to prevent mirsa rule 8.1 violation */
STATIC FUNC(void, FRIF_CODE) FrIf_TxConfirmation(
                                            FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr, 
                                            uint16 Handle);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  FrIf_TxConfirmation
**********************************************************************************************************************/
/*! \brief      Perform transmission confirmation for all PDUs contained in the frame with index Handle. 
 *              Only those PDUs are confirmed which have been sent. This information is stored in FrIf_TxPduWasSent
 *  \param[in]  FrameDescriptorPtr: The pointer to the frame descriptor
 *  \param[in]  Handle:             The index of the frame descriptor
 *  \return     void
 *  \see        The function is called by FrIf_TxConfTask_0 function of the FrIf
 *  \note       -
 *********************************************************************************************************************/
STATIC FUNC(void, FRIF_CODE) FrIf_TxConfirmation(
                                          FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr, 
                                          uint16 Handle)
{
  uint16_least FrameLayoutElIndex = FrameDescriptorPtr->FirstFrameLayoutElementHandle;
  sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;
  /* get transmitted pdu information, last pdu of frame in LSB */
  FrIf_NumberOfPduType PduUsage = FrIf_TxPduWasSentFlags[Handle];
  FrIf_NumberOfPduType Mask = (FrIf_NumberOfPduType) (1 << PduNumber);

  FrIf_TxPduWasSentFlags[Handle] = 0;

  for(; PduNumber >= (sint16_least) 0; PduNumber--)
  {
    FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr = 
                      &FrIf_GetTxPduDescriptor(FrIf_GetTxFrameLayoutElement(FrameLayoutElIndex).PduHandle);

    if (   (0 != (PduUsage & Mask))
        && (FALSE != (TxPduDescriptorPtr->PduConfig & FrIf_TxPduIsTxConfirmation)))
    {
      FrIf_TxConfirmationFunctions(TxPduDescriptorPtr->PduConfig & FrIf_TxPduOwner, TxPduDescriptorPtr->UpperLayerPduId);
    }
    Mask >>= 1u;
    FrameLayoutElIndex++;
  }  
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  FrIf_TxConfTask_0
**********************************************************************************************************************/
/*! \brief      Perform transmission confirmation for all frames that have been copied to the driver during a 
 *              previous task. This previous task is determined by the TxConfJobNo attribute of the current task.
 *  \see        The function is called by the FrIf_JobListExec_0 function of the FrIf
 *  \param[in]  void
 *  \return     void
 *  \note       -
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_TxConfTask_0(void)
{
  const uint16_least JobStartTime = FrIf_GetJobData(FrIf_Status.CurrentJobNumber).StartTimeInMakroTicks;
  const uint8_least  MinJobNumber = FrIf_GetJobData(FrIf_Status.CurrentJobNumber).MinTxConfJobNo;
  const uint8_least  MaxJobNumber = FrIf_GetJobData(FrIf_Status.CurrentJobNumber).MaxTxConfJobNo;

  uint8_least JobNumber = MinJobNumber;
  for(; JobNumber <= MaxJobNumber; JobNumber++)
  {
    FRIF_P2CONSTCFG(FrIf_TaskScheduleDataType) JobDataPtr = &FrIf_GetJobData(JobNumber);

    if(FALSE == (JobDataPtr->JobConfig & FrIf_JobDataIsRxTask))
    {
      const uint16_least MaxColumn = JobDataPtr->MaxColumnNumber;
      uint16_least ColumnNumber = JobDataPtr->MinColumnNumber;
      uint8_least  currentCycle;
# if defined ( FRIF_DELAYEDTXCONFSUPPORT ) && ( STD_ON == FRIF_DELAYEDTXCONFSUPPORT )
      if (FALSE != (JobDataPtr->JobConfig & FrIf_JobIsConfirmedBeforeTx)) 
      {
        currentCycle = (uint8_least)(((JobNumber < FrIf_Status.CurrentJobNumber) && (JobStartTime > JobDataPtr->EndTimeProtectedRange)) ? NEXT_CYCLE(FrIf_Status.CurrentCycle) : FrIf_Status.CurrentCycle);
      }
      else
# endif
      {
        currentCycle = (uint8_least)(((JobNumber < FrIf_Status.CurrentJobNumber) && (JobStartTime > JobDataPtr->EndTimeProtectedRange)) ? FrIf_Status.CurrentCycle : PREVIOUS_CYCLE(FrIf_Status.CurrentCycle));
      }
      for(; ColumnNumber <= MaxColumn; ColumnNumber++)
      {
        const uint16 Handle = FrIf_GetTxColumn(ColumnNumber)
        [currentCycle & FrIf_GetTxCycleNumberMask(ColumnNumber)];

        FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetTxFrameDescriptor(Handle);

        if (   (FrIf_GetInvalidTxHandle() != Handle)
           && (FALSE != (FrameDescriptorPtr->FrameConfig & FrIf_FrameIsTxConfirmation))
#if defined (FR_VENABLE_TX_INTERRUPT) && ( STD_ON == FR_VENABLE_TX_INTERRUPT )
           && (FALSE == (FrameDescriptorPtr->FrameConfig & FrIf_FrameIsInterruptMode))
#endif
           && (FALSE != FrIf_TxPduWasSentFlags[Handle]))
        {
          Fr_TxLPduStatusType TxLPduStatus;
          Std_ReturnType result = Fr_CheckTxLPduStatus(0, Handle, &TxLPduStatus);
          if (  (E_OK == result) 
            &&(FR_TRANSMITTED==TxLPduStatus))
          {
            FrIf_TxConfirmation(FrameDescriptorPtr, Handle);
          }
          else if(E_NOT_OK == result)
          {
            /* The FrIf shall not try to repeat the FrIf_TxConfirmation. In case of buffer reconfiguration     */
            /* it could happen that FrIf retries the TxConf until the frame is transmitted again. But the      */
            /* frame might not be transmitted again.                                                           */

            FrIf_TxPduWasSentFlags[Handle] = 0;
          }
          else
          {
            /* do not call FrIf_TxConfirmation --> FrIf_TxPduWasSentFlags is not cleared */
          }
        }
      }
    }
  }
}

/**********************************************************************************************************************
  FrIf_TxTask_0
**********************************************************************************************************************/
/*! \brief      Perform transmission for the current job.
 *  \see        The function is called by the FrIf_JobListExec_0 function of the FrIf
 *  \param[in]  void
 *  \return     E_OK:       The call of the service FrIf_TxTask_0() returns E_OK if the FrIf state was FRIF_ONLINE 
 *                          and Fr_TransmitTxLPdu returned E_OK.
 *              E_NOT_OK:   The call of the service FrIf_TxTask_0() returns E_NOT_OK if the FrIf state was 
 *                          FRIF_OFFLINE or Fr_TransmitTxLPdu returned E_NOT_OK.
 *  \note       During its runtime this function temporarily disables all interrupts.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_TxTask_0(void)
{
  Std_ReturnType Result = E_OK;
  Std_ReturnType TransmitResult = E_OK;

  FRIF_P2CONSTCFG(FrIf_TaskScheduleDataType) JobDataPtr = &FrIf_GetJobData(FrIf_Status.CurrentJobNumber);
  
# if (STD_OFF == FRIF_PDUDIRTYBYTE_USAGE)
  FRIF_DECLARE_BITVECTOR_LOOKUP_TABLE_CLR_BIT;
# endif

  const uint16_least MaxColumn = JobDataPtr->MaxColumnNumber;
  uint16_least ColumnNumber = JobDataPtr->MinColumnNumber;
  for(; ColumnNumber <= MaxColumn; ColumnNumber++)
  {
    const uint16 Handle = FrIf_GetTxColumn(ColumnNumber)[FrIf_Status.CurrentCycle & FrIf_GetTxCycleNumberMask(ColumnNumber)];
    uint8 txFrameConfig = FrIf_GetTxFrameDescriptor(Handle).FrameConfig;

    if (   (FrIf_GetInvalidTxHandle() != Handle) 
        && (FALSE == (txFrameConfig & FrIf_FrameIsImmediateTx)))
    {
      FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetTxFrameDescriptor(Handle);

      boolean FrameDirty = (boolean) (txFrameConfig & FrIf_FrameIsTransmitAlways);
      uint16_least FrameLayoutElIndex = FrameDescriptorPtr->FirstFrameLayoutElementHandle;      
      sint16_least PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;

      FrIf_NumberOfPduType PduUsage = 0;
      uint8_least CurrentPos = 4; /* first 4  bytes of frame are initialized */
      /* PRQA S 0310 1 *//* MD_FrIf_0310 */
      P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) FrameBuffer = FRIF_GET_FRAMEBUFFER();  

# if ( STD_OFF == FRIF_DIRECT_BUFFER_ACCESS_ENABLE )
      /* PRQA S 1281 1 *//* MD_FrIf_1281 */
      FRIF_INITIALIZE_FRAMEBUFFER_START();
# else
      CurrentPos = 0;
# endif

      for(; PduNumber >= (sint16_least) 0; PduNumber--)
      {
        const PduIdType FrTxPduId = FrIf_GetTxFrameLayoutElement(FrameLayoutElIndex).PduHandle;
        const uint8_least byteOffsetInFrame = FrIf_GetTxFrameLayoutElement(FrameLayoutElIndex).ByteOffsetInFrame;
#if (STD_ON == FRIF_PDUDIRTYBYTE_USAGE)
        boolean PduIsDirty = FrIf_TxPduDirtyBytes[FrTxPduId];
#else
        boolean PduIsDirty = (boolean) GetBit(FrIf_TxPduDirtyFlags, FrTxPduId);
#endif
        FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr = &FrIf_GetTxPduDescriptor(FrTxPduId);
        uint8 txPduConfig = TxPduDescriptorPtr->PduConfig;

#if defined (FRIF_REQUEST_COUNTER_HANDLING_DISABLE) && (STD_OFF == FRIF_REQUEST_COUNTER_HANDLING_DISABLE)
        if(FALSE != (txPduConfig & FrIf_TxPduHasTxRequestCounter))
        {
          const PduIdType TxReqCounterIndex = TxPduDescriptorPtr->TxRequestCounterIndex;
          /* Protect TxRequestCounter access */
          FRIF_BEGIN_CRITICAL_SECTION_0();  /* PRQA S 3109 *//* MD_MSR_14.3 */
          if ((0 < FrIf_TxPduTxRequestCounter[TxReqCounterIndex]) && (FrIf_TxPduWasSentFlags[Handle] == 0))
          {
            FrIf_TxPduTxRequestCounter[TxReqCounterIndex]--;
            PduIsDirty = TRUE;
          }
          FRIF_END_CRITICAL_SECTION_0(); /* PRQA S 3109 *//* MD_MSR_14.3 */
        }
#endif /* if defined (FRIF_REQUEST_COUNTER_HANDLING_DISABLE) && (STD_OFF == FRIF_REQUEST_COUNTER_HANDLING_DISABLE) */

        PduUsage <<= 1u;
        if( (FALSE != PduIsDirty) || (FALSE != (txPduConfig & FrIf_TxPduIsTransmitAlways)) )
        {
          PduLengthType CurrentPduLength = TxPduDescriptorPtr->PduLength;
#if defined ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE)
          /* request buffer for direct buffer access only once per frame */
          if(0 == PduUsage)
          {
            Result = Fr_RequestBuffer_DBA(0, Handle, &FrameBuffer, FrameDescriptorPtr->FrameLength);
            if(E_OK != Result)
            {
              if ((Std_ReturnType)E_PENDING != Result)
              {
                /* no buffer available for the requested frame -> throw a DetError after returning in the FrIf_JobListExec_0 routine */
                return E_NOT_OK;
              }
              else
              {
                /* this case is only entered if the FrIf tries to transmit a Frame of an identity which is currently not active in the Fr component. */
                return E_OK;
              }
            }
          }

          /* PRQA S 1281 1 *//* MD_FrIf_1281 */
          FRIF_INITIALIZE_FRAMEBUFFER_START();
#endif
          PduUsage |= 1u;
          if(byteOffsetInFrame > CurrentPos)
          {
            /* Initialize unused space in front of the PDU */
            VStdMemSet(&FrameBuffer[CurrentPos], FRIF_FILL_PATTERN, (uint8) (byteOffsetInFrame - CurrentPos));
          }

#if (STD_ON == FRIF_PDUDIRTYBYTE_USAGE)
          FrIf_TxPduDirtyBytes[FrTxPduId] = FALSE;
#else
          /* Protect Bit Operations */
          FRIF_BEGIN_CRITICAL_SECTION_0(); /* PRQA S 3109 *//* MD_MSR_14.3 */
          ClearBit(FrIf_TxPduDirtyFlags, FrTxPduId);
          FRIF_END_CRITICAL_SECTION_0(); /* PRQA S 3109 *//* MD_MSR_14.3 */
#endif

#if defined (FRIF_USEPDUINFOTYPE) && (FRIF_USEPDUINFOTYPE == STD_ON)          
          FrameDirty |= (boolean)(E_OK == FrIf_TriggerTransmitFunctions(txPduConfig & FrIf_TxPduOwner, 
            TxPduDescriptorPtr->UpperLayerPduId, 
             &(FrameBuffer[byteOffsetInFrame]), &CurrentPduLength));
#else
          FrIf_TriggerTransmitFunctions(txPduConfig & FrIf_TxPduOwner, 
            TxPduDescriptorPtr->UpperLayerPduId, 
             &(FrameBuffer[byteOffsetInFrame]));          
          
          FrameDirty = TRUE;
#endif
          CurrentPos = (uint8_least)(byteOffsetInFrame + CurrentPduLength);
        }

        FrameLayoutElIndex++;
      }
      if(FALSE != FrameDirty)
      {
#if defined ( FRIF_DUALCHANNELREDUNDANCYSUPPORT ) && (STD_ON == FRIF_DUALCHANNELREDUNDANCYSUPPORT)      
        FrIf_TxHandleType RedundantHandle = FrameDescriptorPtr->FrameHandle;
#endif
#if defined ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE)
        /* in case AlwaysTransmit flag is set for the frame and no PDU update bit is set */
        /* the buffer needs to be requested                                              */
        if(0 == PduUsage)
        {
          if(E_OK != Fr_RequestBuffer_DBA(0, Handle, &FrameBuffer, FrameDescriptorPtr->FrameLength))
          {
            return E_NOT_OK;
          }
        }
#endif
        if(CurrentPos < FrameDescriptorPtr->FrameLength)
        {
          if(FALSE == (txFrameConfig & FrIf_FrameIsDynamicLSduLength))
          {
            /* Initialize unused space at the end of the frame */
            /* PRQA S 0505 4 */ /* MD_FrIf_0505 */
            VStdMemSet(&FrameBuffer[CurrentPos], FRIF_FILL_PATTERN, (uint8) (FrameDescriptorPtr->FrameLength - CurrentPos));
            CurrentPos = FrameDescriptorPtr->FrameLength;
          }
        }
        /* store transmitted pdu information, last pdu of frame in LSB */
        FrIf_TxPduWasSentFlags[Handle] = PduUsage;

        if(FALSE != (txFrameConfig & FrIf_FrameHasPduWithUpdateBit))
        {
# if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_ON )
#  if (FRIF_ALL_FRAMES_HAVE_SAME_UPDATEBIT_BYTEPOS == STD_ON)
          const uint8_least updateBitBytePos = FrIf_GetUpdateBitBytePos();
#  else
          const uint8_least updateBitBytePos = FrameDescriptorPtr->UpdateBitBytePos;
#  endif
          FrameBuffer[updateBitBytePos] = 0;
# endif
          /* set the update bits */
          PduNumber = (sint16_least)FrameDescriptorPtr->NumberOfPdus - 1;
          FrameLayoutElIndex--;
          for(; PduNumber >= (sint16_least) 0; PduNumber--)
          {
            const uint8 updateBitMask = FrIf_GetTxFrameLayoutElement(FrameLayoutElIndex).UpdateBitMask;
            if((uint8_least) 0 != updateBitMask)
            {
# if ( FRIF_UNIFORMUPDATEBYTEPOS == STD_OFF )
              const uint8_least updateBitBytePos = FrIf_GetTxFrameLayoutElement(FrameLayoutElIndex).UpdateBitBytePos;

              if((uint16) 0 == (PduUsage & (uint16) 0x01))
              {
                FrameBuffer[updateBitBytePos] &= (uint8) ~ updateBitMask;                
              }
# endif              
              if((uint16) 0 != (PduUsage & (uint16) 0x01))
              {
                FrameBuffer[updateBitBytePos] |= updateBitMask;
              }              
            }
            PduUsage >>= 1u;
            FrameLayoutElIndex--;
          }
        }

#if defined ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE)
        TransmitResult = Fr_TransmitTxLPdu_DBA( FrIf_TimerIndex2FrCtrlIndex(0),  
                                        Handle,                                
                                        (uint8)CurrentPos);
# if defined(FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON ) 
        if(RedundantHandle  != FrIf_GetInvalidTxHandle())
        {
          P2VAR(uint8, AUTOMATIC, FRIF_VAR_NOINIT) FrameBufferToCopy = FrameBuffer;  
          TransmitResult |= Fr_RequestBuffer_DBA(0, RedundantHandle, &FrameBuffer, FrameDescriptorPtr->FrameLength);
          VStdRamMemCpy(FrameBuffer, FrameBufferToCopy, (uint8)(CurrentPos));
          
          if(E_OK == TransmitResult)
          {
            TransmitResult |= Fr_TransmitTxLPdu_DBA( FrIf_TimerIndex2FrCtrlIndex(0),  
                                          RedundantHandle,                                
                                          (uint8)CurrentPos);
          } 
        }
# endif
#else
        TransmitResult = Fr_TransmitTxLPdu( FrIf_TimerIndex2FrCtrlIndex(0),  
                                    Handle,    
                                    FrameBuffer,  
                                    (uint8)CurrentPos);
# if defined(FRIF_DUALCHANNELREDUNDANCYSUPPORT) && ( FRIF_DUALCHANNELREDUNDANCYSUPPORT == STD_ON ) 
        if(RedundantHandle  != FrIf_GetInvalidTxHandle())
        {
          TransmitResult |= Fr_TransmitTxLPdu( FrIf_TimerIndex2FrCtrlIndex(0),  
                                    RedundantHandle,    
                                    FrameBuffer,  
                                    (uint8)CurrentPos);
        }
# endif
#endif
        if(E_OK == TransmitResult)
        {
#if defined ( FRIF_FRAME_TRANSMITTED )
          /* macro can be defined to plugin monitoring or testing */
          FRIF_FRAME_TRANSMITTED(Handle, FrameBuffer, FrIf_GetTxFrameDescriptor(Handle).FrameLength);
#endif
        }
        else
        {
          /* rollback */
          Result |= TransmitResult;
          PduNumber = (sint16_least)(FrameDescriptorPtr->NumberOfPdus) - 1;

          FrameLayoutElIndex = (uint16_least) (FrameDescriptorPtr->FirstFrameLayoutElementHandle + PduNumber);
          PduUsage = FrIf_TxPduWasSentFlags[Handle];
          /* Protect TxRequestCounter access */
          FRIF_BEGIN_CRITICAL_SECTION_0();  /* PRQA S 3109 *//* MD_MSR_14.3 */
          for(; PduNumber >= (sint16_least) 0; PduNumber--)
          {
            const PduIdType FrTxPduId = FrIf_GetTxFrameLayoutElement(FrameLayoutElIndex).PduHandle;
            
            if((uint16) 0 != (PduUsage & (uint16) 0x01))
            {
#if (STD_ON == FRIF_PDUDIRTYBYTE_USAGE)
              FrIf_TxPduDirtyBytes[FrTxPduId] = TRUE;
#else
              SetBit(FrIf_TxPduDirtyFlags, FrTxPduId);
#endif
            }
#if defined (FRIF_REQUEST_COUNTER_HANDLING_DISABLE) && (STD_OFF == FRIF_REQUEST_COUNTER_HANDLING_DISABLE)
            {
              FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr = &FrIf_GetTxPduDescriptor(FrTxPduId);
              if(FALSE != (TxPduDescriptorPtr->PduConfig & FrIf_TxPduHasTxRequestCounter))
              {
                const PduIdType TxReqCounterIndex = TxPduDescriptorPtr->TxRequestCounterIndex;

                FrIf_TxPduTxRequestCounter[TxReqCounterIndex]++;
                if(0 == FrIf_TxPduTxRequestCounter[TxReqCounterIndex])
                {
                  /* on overflow occured, use previous value */
                  /* such an overflow can occured if COM calls Transmit for an I-PDU faster than the FlexRay schedule */
                  FrIf_TxPduTxRequestCounter[TxReqCounterIndex]--;
                }
              }
            }
#endif /* if defined (FRIF_REQUEST_COUNTER_HANDLING_DISABLE) && (STD_OFF == FRIF_REQUEST_COUNTER_HANDLING_DISABLE) */

            PduUsage >>= 1u;
            FrameLayoutElIndex--;
          }
          FRIF_END_CRITICAL_SECTION_0(); /* PRQA S 3109 *//* MD_MSR_14.3 */
          FrIf_TxPduWasSentFlags[Handle] = 0;
        }
      }
    }
  }

  return Result;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_Transmit
**********************************************************************************************************************/
/*! \brief      This function transmits a PDU. If the PDU is configured for Decoupled Transmission, the PDU is marked 
 *              as dirty. When a frame that contains the PDU shall be transmitted, the <UL>_TriggerTransmit call-back 
 *              function of the upper-layer component is called in order to get the PDU content.
 *              If the PDU is configured for Immediate Transmission the PDU content is directly given to the FlexRay 
 *              Driver.
 *  \param[in]  FrTxPduId:  ID of the FlexRay PDU to be transmitted.
 *  \param[in]  PduInfoPtr: Pointer to a structure with FlexRay PDU related data
 *  \return     E_OK      Immediate transmission request has been accepted.
 *              E_PENDING Decoupled transmission request has been accepted.
 *              E_NOT_OK  Transmission request has been rejected.
 *  \see        The function is called by Autosar PduR, FrNm or FrTp component
 *  \note       During its runtime this function temporarily disables all interrupts.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_Transmit(PduIdType FrTxPduId, 
                                              FRIF_P2CONSTAPPLDATA(PduInfoType) PduInfoPtr)
{
  Std_ReturnType Result = (Std_ReturnType)E_PENDING;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_TRANSMIT_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  FrIf_CheckDetErrorReturnValue((FrTxPduId < FrIf_GetNumberOfTxPdus()), FRIF_TRANSMIT_SERVICE_ID, FRIF_E_INV_TXPDUID, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != PduInfoPtr), FRIF_TRANSMIT_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != (PduInfoPtr->SduDataPtr)), FRIF_TRANSMIT_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);

  if (FrIf_IsOnline(0))
  {
    FRIF_P2CONSTCFG(FrIf_TxPduDescriptorType) TxPduDescriptorPtr = &FrIf_GetTxPduDescriptor(FrTxPduId);
    if(FALSE != (TxPduDescriptorPtr->PduConfig & FrIf_TxPduIsImmediateTx))
    {
#if defined ( FRIF_DIRECT_BUFFER_ACCESS_ENABLE ) && (STD_ON == FRIF_DIRECT_BUFFER_ACCESS_ENABLE)
      Result = Fr_TransmitTxLPdu_ImmediateDBA(FrIf_TimerIndex2FrCtrlIndex(0), 
          FrTxPduId, 
          PduInfoPtr->SduDataPtr, 
          (uint8)PduInfoPtr->SduLength); /* avoid warning if PduLengthType != uint8 */
#else
      Result = Fr_TransmitTxLPdu(FrIf_TimerIndex2FrCtrlIndex(0), 
          FrTxPduId, 
          PduInfoPtr->SduDataPtr, 
          (uint8)PduInfoPtr->SduLength); /* avoid warning if PduLengthType != uint8 */
#endif

      if(E_OK == Result)
      {
        /* For immediate transmission the following is true: Frame Handle = Tx-PduId */
        /* LSB determines that the single PDU was transmitted */
        FrIf_TxPduWasSentFlags[FrTxPduId] = 0x01u;
      }
    }
    else
    {
      /* Protect TxRequestCounter access */
      FRIF_BEGIN_CRITICAL_SECTION_0(); /* PRQA S 3109 *//* MD_MSR_14.3 */
#if (STD_ON == FRIF_PDUDIRTYBYTE_USAGE)
      FrIf_TxPduDirtyBytes[FrTxPduId] = TRUE;
#else
      SetBit(FrIf_TxPduDirtyFlags, FrTxPduId);
#endif
#if defined (FRIF_REQUEST_COUNTER_HANDLING_DISABLE) && (STD_OFF == FRIF_REQUEST_COUNTER_HANDLING_DISABLE)
      if(FALSE != (TxPduDescriptorPtr->PduConfig & FrIf_TxPduHasTxRequestCounter))
      {
        const PduIdType TxReqCounterIndex = TxPduDescriptorPtr->TxRequestCounterIndex;

        FrIf_TxPduTxRequestCounter[TxReqCounterIndex]++;
        if(0 == FrIf_TxPduTxRequestCounter[TxReqCounterIndex])
        {
          /* on overflow occured, use previous value */
          /* such an overflow can occured if COM calls Transmit for an I-PDU faster than the FlexRay schedule */
          FrIf_TxPduTxRequestCounter[TxReqCounterIndex]--;
        }
      }
#endif /* #if defined (FRIF_REQUEST_COUNTER_HANDLING_DISABLE) && (STD_OFF == FRIF_REQUEST_COUNTER_HANDLING_DISABLE) */
      FRIF_END_CRITICAL_SECTION_0();  /* PRQA S 3109 *//* MD_MSR_14.3 */
    }
  }
  else
  {
    Result = E_NOT_OK;
  }

  return Result;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_ConfirmPendingTransmissions
**********************************************************************************************************************/
/*! \brief      When stopping or resynchronizing  the FrIf-JobList execution, the FrIf shall call the FrIf_TxConfirmat-
 *              ion callback of the upper layers as if the pending transmission had been completed.
 *  \see        The function is called by the FrIf_StopJobExecution() function of the FrIf
 *  \param[in]  void
 *  \return     void
 *  \note       -
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE)FrIf_ConfirmPendingTransmissions(void)
{
  sint16_least Handle;
#if defined(FRIF_CONFIG_VARIANT) && (3u==FRIF_CONFIG_VARIANT)
  for (Handle = (sint16_least) FrIf_Status.pConfigData->NumberOfTxFrames - 1;Handle >= (sint16_least) 0; Handle--)
#else
  for (Handle = (sint16_least) FrIf_MaxNumberOfTxFrames - 1; Handle >= (sint16_least) 0; Handle--)
#endif
  {
    FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetTxFrameDescriptor(Handle);
    FrIf_TxConfirmation(FrameDescriptorPtr, (uint16) Handle);
  }
}

#if defined (FR_VENABLE_TX_INTERRUPT) && ( STD_ON == FR_VENABLE_TX_INTERRUPT )
/**********************************************************************************************************************
  ApplFrDrv_ISR_Tx
**********************************************************************************************************************/
/*! \brief      This is a call-back function that is called by the FlexRay Driver when a frame transmission has 
 *              generated an interrupt. 
 *  \param[in]  Fr_CtrlIdx: The index of the controller that generated the interrupt
 *  \param[in]  Column:     The number of the column in the schedule matrix.
 *  \return     E_OK:       The call of the service ApplFrDrv_ISR_Rx() returns E_OK if the FrIf state was FRIF_ONLINE.
 *              E_NOT_OK:   The call of the service ApplFrDrv_ISR_Rx() returns E_NOT_OK if the FrIf state was 
 *                          FRIF_OFFLINE.
 *  \see        The function is called by AUTOSAR Fr
 *  \note       -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) ApplFr_ISR_Tx(uint8 Fr_CtrlIdx, uint16 Column)
{
  uint16 MacroTicks;
  uint8 currentCycle;
  Std_ReturnType ErrorState = E_NOT_OK;
  if(FALSE != FrIf_IsOnline(Fr_CtrlIdx))
  {
    ErrorState = Fr_GetGlobalTime(0, &currentCycle, &MacroTicks);
    if(E_OK == ErrorState)
    {
      uint16 Handle = FrIf_GetTxColumn(Column)[currentCycle & FrIf_GetTxCycleNumberMask(Column)];
      if(   (Handle  != FrIf_GetInvalidTxHandle())
        && (   FALSE != GetBit(FrIf_TxFrameWasSentFlags, Handle)))
      {
        FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetTxFrameDescriptor(Handle);
        FrIf_TxConfirmation(FrameDescriptorPtr, Handle);
      }
      else
      {
        /* The frame was sent in the previous cycle */
        currentCycle = PREVIOUS_CYCLE(currentCycle);
        Handle = FrIf_GetTxColumn(Column)[currentCycle & FrIf_GetTxCycleNumberMask(Column)];
        if (   (Handle != FrIf_GetInvalidTxHandle())
            && ( FALSE != GetBit(FrIf_TxFrameWasSentFlags, Handle)))
        {
          FRIF_P2CONSTCFG(FrIf_FrameDescriptorType) FrameDescriptorPtr = &FrIf_GetTxFrameDescriptor(Handle);
          FrIf_TxConfirmation(FrameDescriptorPtr, Handle);
        }
        else
        {
          ErrorState = E_NOT_OK;
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
#endif /* if defined (FR_VENABLE_TX_INTERRUPT) && ( STD_ON == FR_VENABLE_TX_INTERRUPT ) */

#define FRIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_Tx.c
 *********************************************************************************************************************/

/* STOPSINGLE_OF_MULTIPLE */
