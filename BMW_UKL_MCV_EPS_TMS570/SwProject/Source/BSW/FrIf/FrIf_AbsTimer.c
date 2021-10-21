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
/*! \file         FrIf_AbsTimer.c
 *    Component:  MICROSAR FrIf
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Implementation of the handling of absolute timers, according to:
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
 -  3.0.1     2008-02-01  ber     -             added compiler abstraction and memory mapping
 -            2008-02-22  ber     -             release of version 3.0.1 
 -  3.0.2     2008-03-20  ber     ESCAN00025115 No changes here
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
 -  3.0.5     2008-07-11  ore     -             Added FRIF_E_INV_POINTER DetCheck for FrIf_GetAbsoluteTimerIRQStatus
 -            2008-06-09  ore     ESCAN00026972 No changes here
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
 -            2008-08-14  ore     -             unified define usage
 -            2008-08-15  ore     -             release of version 3.0.7
 -  3.0.8     2008-08-22  ore     ESCAN00029101 No changes here
 -            2008-08-22  ore     -             release of version 3.0.8
 -  3.0.9     2008-09-17  ore     -             release of version 3.0.9
 -  3.0.10    2008-10-01  ore     ESCAN00030038 FrIf file name conventions
 -            2008-10-01  ore     ESCAN00030039 FrIf type name conventions
 -            2008-10-01  ore     ESCAN00030040 No changes here
 -            2008-10-01  ore     ESCAN00029696 No changes here
 -            2008-10-01  ore     ESCAN00029736 No changes here
 -            2008-11-03  ore     ESCAN00031030 No changes here
 -            2008-11-03  ore     ESCAN00031026 No changes here
 -            2008-11-04  ore     -             release of version 3.0.10
 -  3.1.0     2008-11-10  ore     ESCAN00030776 No changes here
 -            2008-11-10  ore     ESCAN00030577 No changes here
 -            2008-11-10  ore     ESCAN00030264 No changes here
 -            2008-11-10  ore     ESCAN00030764 No changes here
 -            2008-11-17  ore     ESCAN00031345 No changes here
 -            2008-11-17  ore     ESCAN00030264 No changes here
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
 -            2009-02-25  ore     ESCAN00033399 Simplify FrIf include structure
 -            2009-02-25  ore     ESCAN00033402 The FrIf source and header files are not implemented as SingleSource.
 -            2009-02-26  ore     ESCAN00033441 No changes here
 -            2009-02-26  ore     ESCAN00032715 No changes here
 -            2009-03-05  ore     ESCAN00033650 No changes here
 -            2009-03-06  ore     ESCAN00033651 Unify DET implementation
 -            2009-03-06  ore     ESCAN00033665 No changes here
 -            2009-03-18  ore     ESCAN00033669 No changes here
 -            2009-03-10  ore     ESCAN00033732 No changes here
 -            2009-03-23  ore     ESCAN00034040 No changes here
 -            2009-03-23  ore     -             release of version 3.2.0
 -  3.3.0     2009-04-06  ore     ESCAN00036436 Add PRQA misra justification comments for QAC
 -            2009-05-28  ore     ESCAN00035398 No changes here
 -            2009-05-28  ore     ESCAN00035048 No changes here
 -            2009-06-29  ore     ESCAN00035991 No changes here
 -            2009-07-06  ore     ESCAN00036053 No changes here
 -            2009-07-20  ore     ESCAN00036397 No changes here
 -            2009-07-14  ore     ESCAN00035990 No changes here
 -            2009-07-14  ore     ESCAN00035399 No changes here
 -            2009-07-15  ore     ESCAN00036426 No changes here
 -            2009-07-15  ore     ESCAN00036427 No changes here
 -            2009-07-15  ore     ESCAN00036429 Reduce codesize by implementing the FrIf wrapper APIs as macros
 -            2009-07-15  ore     ESCAN00036451 Unused FrIf APIs cannot be disabled via precompile switch
 -            2009-07-16  ore     ESCAN00036471 No changes here
 -            2009-07-17  ore     ESCAN00034459 No changes here
 -            2009-07-28  ore     ESCAN00036120 No changes here
 -            2009-07-31  ore     ESCAN00036776 No changes here
 -            2009-07-31  ore     -             release of version 3.3.0 
 -  3.4.0     2009-08-24  ore     ESCAN00036905 No changes here
 -            2009-08-24  ore     ESCAN00037257 No changes here
 -            2009-09-08  ore     ESCAN00035396 No changes here
 -            2009-09-08  ore     ESCAN00037643 No changes here
 -            2009-09-08  ore     ESCAN00037633 No changes here
 -            2009-09-21  ore     ESCAN00036013 Similar DET Usage
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
 -            2010-02-18  ore     ESCAN00040960 No changes here
 -            2010-02-22  ore     ESCAN00039809 No changes here
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
 -            2010-11-05  ore     ESCAN00046607 No changes here 
 -            2010-11-16  ore     -             Added additional PcLint and QAC justifications
 -            2010-11-16  ore     ESCAN00046950 No changes here 
 -            2010-11-25  ore     ESCAN00046093 No changes here 
 -            2010-11-26  ore     ESCAN00047186 No changes here 
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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "FrIf_Priv.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if ( IF_ASRIFFR_VERSION != 0x0307u )
# error "The included header FrIf.h is incompatible with the FrIf_AbsTimer.c version."
#endif
#if ( IF_ASRIFFR_RELEASE_VERSION != 0x04u )
# error "The included header FrIf.h is incompatible with the FrIf_AbsTimer.c release version."
#endif

/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define FRIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

#if defined ( FRIF_API_AS_MACRO ) && (STD_OFF == FRIF_API_AS_MACRO)
# if defined (FRIF_ABSOLUTE_TIMER_API_DISABLE) && (STD_OFF == FRIF_ABSOLUTE_TIMER_API_DISABLE)
/**********************************************************************************************************************
  FrIf_SetAbsoluteTimer
**********************************************************************************************************************/
/*! \brief      This function sets the alarm time of an FlexRay absolute timer.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer to be used for setting the alarm time
 *  \param[in]  Cycle:                 Cycle in which the timer shall expire.
 *  \param[in]  MacroTickOffset:       Offset to the cycle start in macro ticks.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_SetAbsoluteAlarmTime() 
                          has returned E_OK.
                E_NOT_OK: The call of the FlexRay Driver API service Fr_SetAbsoluteAlarmTime() 
                          has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_SetAbsoluteTimer(FRIF_VCTRL_ONLY, 
                                                     uint8   FrIf_AbsTimerIdx, 
                                                     uint8   Cycle, 
                                                     uint16  MacrotickOffset)
{
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 6 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_SETABSOLUTETIMER_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_SETABSOLUTETIMER_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue((Cycle < NO_FLEXRAY_CYCLES), FRIF_SETABSOLUTETIMER_SERVICE_ID, FRIF_E_INV_CYCLE, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue((MacrotickOffset < FrIf_GetNumberOfMacroTicksPerCycle()), FRIF_SETABSOLUTETIMER_SERVICE_ID, FRIF_E_INV_MACROTICK, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue((FrIf_AbsTimerIdx < FR_MAX_NUM_ABS_TIMER), FRIF_SETABSOLUTETIMER_SERVICE_ID, FRIF_E_INV_TIMER_IDX, E_NOT_OK);

  ErrorState = Fr_SetAbsoluteTimer(
      FRIF_VCTRL_IDX, 
      FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx), 
      Cycle, 
      MacrotickOffset);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_CancelAbsoluteTimer
**********************************************************************************************************************/
/*! \brief      This function cancels an FlexRay absolute timer.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer to be used for stopping the alarm time
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_CancelAbsoluteTimer() 
                          has returned E_OK.
                E_NOT_OK: The call of the FlexRay Driver API service Fr_CancelAbsoluteTimer() 
                          has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_CancelAbsoluteTimer(FRIF_VCTRL_ONLY, 
                                                        uint8  FrIf_AbsTimerIdx)
{
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_CANCELABSOLUTETIMER_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_CANCELABSOLUTETIMER_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue((FrIf_AbsTimerIdx < FR_MAX_NUM_ABS_TIMER), FRIF_CANCELABSOLUTETIMER_SERVICE_ID, FRIF_E_INV_TIMER_IDX, E_NOT_OK);

  ErrorState = Fr_CancelAbsoluteTimer(
      FRIF_VCTRL_IDX, 
      FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx));

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_EnableAbsoluteTimerIRQ
**********************************************************************************************************************/
/*! \brief      This function enables an FlexRay absolute timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer whose interrupt shall be enabled.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_EnableAbsoluteTimerIRQ() 
                          has returned E_OK.
                E_NOT_OK: The call of the FlexRay Driver API service Fr_EnableAbsoluteTimerIRQ() 
                          has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_EnableAbsoluteTimerIRQ(FRIF_VCTRL_ONLY, 
                                                           uint8   FrIf_AbsTimerIdx)
{
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_ENABLEABSOLUTETIMERIRQ_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_ENABLEABSOLUTETIMERIRQ_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue((FrIf_AbsTimerIdx < FR_MAX_NUM_ABS_TIMER), FRIF_ENABLEABSOLUTETIMERIRQ_SERVICE_ID, FRIF_E_INV_TIMER_IDX, E_NOT_OK);

  ErrorState = Fr_EnableAbsoluteTimerIRQ(
      FRIF_VCTRL_IDX, 
      FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx));

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_DisableAbsoluteTimerIRQ
**********************************************************************************************************************/
/*! \brief      This function retrieves the interrupt status of an FlexRay absolute timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer whose interrupt shall be disabled.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_DisableAbsoluteTimerIRQ() 
                          has returned E_OK.
                E_NOT_OK: The call of the FlexRay Driver API service Fr_DisableAbsoluteTimerIRQ() 
                          has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_DisableAbsoluteTimerIRQ(FRIF_VCTRL_ONLY, 
                                                            uint8  FrIf_AbsTimerIdx)
{
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_DISABLEABSOLUTETIMERIRQ_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_DISABLEABSOLUTETIMERIRQ_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue((FrIf_AbsTimerIdx < FR_MAX_NUM_ABS_TIMER), FRIF_DISABLEABSOLUTETIMERIRQ_SERVICE_ID, FRIF_E_INV_TIMER_IDX, E_NOT_OK);

  ErrorState = Fr_DisableAbsoluteTimerIRQ(
      FRIF_VCTRL_IDX, 
      FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx));

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_AckAbsoluteTimerIRQ
**********************************************************************************************************************/
/*! \brief      This function acknowledges an FlexRay absolute timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer whose interrupt shall be acknowledged.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_AckAbsoluteTimerIRQ() 
                          has returned E_OK.
                E_NOT_OK: The call of the FlexRay Driver API service Fr_AckAbsoluteTimerIRQ() 
                          has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_AckAbsoluteTimerIRQ(FRIF_VCTRL_ONLY, 
                                                        uint8   FrIf_AbsTimerIdx)
{
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_ACKABSOLUTETIMERIRQ_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_ACKABSOLUTETIMERIRQ_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue((FrIf_AbsTimerIdx < FR_MAX_NUM_ABS_TIMER), FRIF_ACKABSOLUTETIMERIRQ_SERVICE_ID, FRIF_E_INV_TIMER_IDX, E_NOT_OK);

  ErrorState = Fr_AckAbsoluteTimerIRQ(
      FRIF_VCTRL_IDX, 
      FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx));

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_GetAbsoluteTimerIRQStatus
**********************************************************************************************************************/
/*! \brief      This function retrieves the interrupt status of an FlexRay absolute timer interrupt.
 *  \param[in]  FrIf_CtrlIdx:          Index of the CC to address
 *  \param[in]  FrIf_AbsoluteTimerIdx: Index of the absolute timer whose interrupt status shall be retrieved.
 *  \param[out] FrIf_IRQStatusPtr:     Address where the interrupt status information shall be stored.
 *  \return     E_OK:     The call of the FlexRay Driver API service Fr_GetAbsoluteTimerIRQStatus() 
                          has returned E_OK.
                E_NOT_OK: The call of the FlexRay Driver API service Fr_GetAbsoluteTimerIRQStatus() 
                          has returned E_NOT_OK or an error has been detected in development mode.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_CtrlIdx is void
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_GetAbsoluteTimerIRQStatus(FRIF_VCTRL_ONLY, 
                                                       uint8               FrIf_AbsTimerIdx, 
                                                       P2VAR(boolean, AUTOMATIC, FRIF_APPL_DATA) FrIf_IRQStatusPtr)
{
  Std_ReturnType ErrorState = E_OK;

  /* PRQA S 3109 5 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_GETABSOLUTETIMERIRQSTATUS_SERVICE_ID, FRIF_E_NOT_INITIALIZED, E_NOT_OK);
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1  */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCTRL_IDX), FRIF_GETABSOLUTETIMERIRQSTATUS_SERVICE_ID, FRIF_E_INV_CTRL_IDX, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue((FrIf_AbsTimerIdx < FR_MAX_NUM_ABS_TIMER), FRIF_GETABSOLUTETIMERIRQSTATUS_SERVICE_ID, FRIF_E_INV_TIMER_IDX, E_NOT_OK);
  FrIf_CheckDetErrorReturnValue(((const void*)NULL_PTR != FrIf_IRQStatusPtr), FRIF_GETABSOLUTETIMERIRQSTATUS_SERVICE_ID, FRIF_E_INV_POINTER, E_NOT_OK);

  ErrorState = Fr_GetAbsoluteTimerIRQStatus(
      FRIF_VCTRL_IDX, 
      FrIf_TimerIndex2FrTimerIndex(FrIf_AbsTimerIdx), 
      FrIf_IRQStatusPtr);

  return ErrorState;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
# endif /* if defined (FRIF_ABSOLUTE_TIMER_API_DISABLE) && (STD_OFF == FRIF_ABSOLUTE_TIMER_API_DISABLE) */
#endif /* if defined ( FRIF_API_AS_MACRO ) && (STD_OFF == FRIF_API_AS_MACRO) */

#define FRIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_AbsTimer.c
 *********************************************************************************************************************/

/* STOPSINGLE_OF_MULTIPLE */
