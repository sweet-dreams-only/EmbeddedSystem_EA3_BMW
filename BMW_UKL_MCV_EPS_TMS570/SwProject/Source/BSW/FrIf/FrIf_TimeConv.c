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
/*! \file         FrIf_TimeConv.c
 *    Component:  MICROSAR FrIf
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Implementation of the time conversion functions, according to:
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
 -  3.0.2     2008-03-10  ber     -             FrIf_GetMacroticksPerCycle report E_INV_CTRL_IDX
 -            2008-03-20  ber     ESCAN00025115 No changes here
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
 -            2008-10-01  ore     ESCAN00030039 No changes here
 -            2008-10-01  ore     ESCAN00030040 No changes here
 -            2008-10-01  ore     ESCAN00029696 AUTOSAR Dummy Statements
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
 -            2009-07-15  ore     ESCAN00036429 No changes here
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
 -            2010-02-18  ore     ESCAN00040951 No changes here
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
# error "The included header FrIf.h is incompatible with the FrIf_TimeConv.c version."
#endif
#if ( IF_ASRIFFR_RELEASE_VERSION != 0x04u )
# error "The included header FrIf.h is incompatible with the FrIf_TimeConv.c release version."
#endif

/*lint -e506 */ /* Suppress ID506 due to MD_MSR_14.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define FRIF_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

#if defined (FRIF_TIME_CONVERSION_DISABLE) && (STD_OFF == FRIF_TIME_CONVERSION_DISABLE)
/**********************************************************************************************************************
  FrIf_GetMacroticksPerCycle
**********************************************************************************************************************/
/*! \brief      This function returns the number of macro ticks per FlexRay cycle.
 *  \param[in]  FrIf_ClstIdx:      Index of the FlexRay cluster for which the macro ticks per cycle shall be retrieved.
 *  \return     The number of macro ticks or 0 if the FlexRay Interface is not initialized.
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_ClstIdx is void
 *********************************************************************************************************************/
FUNC(uint16, FRIF_CODE) FrIf_GetMacroticksPerCycle(FRIF_VCLST_ONLY)
{ /* PRQA S 3007 */ /*  MD_FrIf_3007 */
  uint16 Result = 0;
# if defined (V_USE_DUMMY_STATEMENT) \
     && (STD_ON == V_USE_DUMMY_STATEMENT) \
     && (STD_OFF == FRIF_VCTRL_ENABLE_API_OPTIMIZATION)
  FRIF_VCLST_IDX = FRIF_VCLST_IDX; /* PRQA S 3199 */ /* MD_FrIf_3199 */
# endif

  /* PRQA S 3109 3 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnValue(FRIF_IS_INITIALIZED(), FRIF_GETMACROTICKSPERCYCLE_SERVICE_ID, FRIF_E_NOT_INITIALIZED, Result);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1 */
  FrIf_CheckDetErrorReturnValue((0 == FRIF_VCLST_IDX), FRIF_GETMACROTICKSPERCYCLE_SERVICE_ID, FRIF_E_INV_CLST_IDX, Result);

  Result = FrIf_GetNumberOfMacroTicksPerCycle();
  return Result; 
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_ConvertNanosecToMacroticks
**********************************************************************************************************************/
/*! \brief      This function converts a time given in nanoseconds to the equivalent number of macro ticks.
 *  \param[in]  FrIf_ClstIdx:      Index of the FlexRay cluster for which the conversion shall be performed. 
 *  \param[out] FrIf_MacrotickPtr: Reference to memory location where the converted value shall be stored at.
 *  \param[in]  FrIf_Nanosec:      Time in nanoseconds to be converted.
 *  \return     void
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_ClstIdx is void
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_ConvertNanosecToMacroticks(FRIF_VCLST_ONLY,
                                                     P2VAR(uint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_MacroTickPtr,
                                                     uint32              FrIf_Nanosec)
{
# if defined (V_USE_DUMMY_STATEMENT) \
     && (STD_ON == V_USE_DUMMY_STATEMENT) \
     && (STD_OFF == FRIF_VCTRL_ENABLE_API_OPTIMIZATION)
  FRIF_VCLST_IDX = FRIF_VCLST_IDX; /* PRQA S 3199 */ /* MD_FrIf_3199 */
# endif

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnVoid(FRIF_IS_INITIALIZED(), FRIF_CONVERTNANOSECTOMACROTICKS_SERVICE_ID, FRIF_E_NOT_INITIALIZED);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1 */
  FrIf_CheckDetErrorReturnVoid((0 == FRIF_VCLST_IDX), FRIF_CONVERTNANOSECTOMACROTICKS_SERVICE_ID, FRIF_E_INV_CLST_IDX);
  FrIf_CheckDetErrorReturnVoid(((const void*)NULL_PTR != FrIf_MacroTickPtr), FRIF_CONVERTNANOSECTOMACROTICKS_SERVICE_ID, FRIF_E_INV_POINTER);  

  *FrIf_MacroTickPtr = FrIf_Nanosec / (FrIf_GetMacroTicksLengthInNanoSeconds());
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
  FrIf_ConvertMacroticksToNanosec
**********************************************************************************************************************/
/*! \brief      This function converts a number of macro ticks to the equivalent time in nanoseconds.
 *  \param[in]  FrIf_ClstIdx:      Index of the FlexRay cluster for which the conversion shall be performed. 
 *  \param[out] FrIf_MacrotickPtr: Reference to memory location where the converted value shall be stored at.
 *  \param[in]  FrIf_Macrotick:    Number of macroticks to be converted.
 *  \return     void
 *  \see        The function is called by Autosar BSW components
 *  \note       If Single Channel API is enabled, param[in] FrIf_ClstIdx is void
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_ConvertMacroticksToNanosec(FRIF_VCLST_ONLY,
                                                     P2VAR(uint32, AUTOMATIC, FRIF_APPL_DATA) FrIf_NanosecPtr,
                                                     uint32             FrIf_MacroTick)
{
# if defined (V_USE_DUMMY_STATEMENT) \
     && (STD_ON == V_USE_DUMMY_STATEMENT) \
     && (STD_OFF == FRIF_VCTRL_ENABLE_API_OPTIMIZATION)
  FRIF_VCLST_IDX = FRIF_VCLST_IDX; /* PRQA S 3199 */ /* MD_FrIf_3199 */
# endif

  /* PRQA S 3109 4 */ /* MD_MSR_14.3 */
  FrIf_CheckDetErrorReturnVoid(FRIF_IS_INITIALIZED(), FRIF_CONVERTMACROTICKSTONANOSEC_SERVICE_ID, FRIF_E_NOT_INITIALIZED);  
  /* PRQA S 3201, 3325 1 */ /*  MD_MSR_14.1 */
  FrIf_CheckDetErrorReturnVoid((0 == FRIF_VCLST_IDX), FRIF_CONVERTMACROTICKSTONANOSEC_SERVICE_ID, FRIF_E_INV_CLST_IDX);
  FrIf_CheckDetErrorReturnVoid(((const void*)NULL_PTR != FrIf_NanosecPtr), FRIF_CONVERTMACROTICKSTONANOSEC_SERVICE_ID, FRIF_E_INV_POINTER);

  *FrIf_NanosecPtr = FrIf_MacroTick * (FrIf_GetMacroTicksLengthInNanoSeconds());
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* if defined (FRIF_TIME_CONVERSION_DISABLE) && (STD_OFF == FRIF_TIME_CONVERSION_DISABLE) */

#define FRIF_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 *//*  MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_TimeConv.c
 *********************************************************************************************************************/

/* STOPSINGLE_OF_MULTIPLE */
