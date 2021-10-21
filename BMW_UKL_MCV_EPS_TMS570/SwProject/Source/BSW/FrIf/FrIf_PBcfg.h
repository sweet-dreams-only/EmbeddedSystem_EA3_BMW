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
/*! \file         FrIf_PBcfg.h
 *    Component:  MICROSAR FrIf
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Header file of the FlexRay Interface containing the definition of the post-build configuration data, 
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
 -  3.0.4     2008-04-25  ore     -             renamed INVALID_JOB_NUMBER to FRIF_INVALID_JOB_NUMBER
 -            2008-04-25  ore     ESCAN00026130 No changes here
 -            2008-04-25  ore     ESCAN00026216 No changes here
 -            2008-04-25  ore     ESCAN00026256 Rename files and #include statements according coding styles  
 -            2008-04-28  ore     ESCAN00026445 No changes here
 -            2008-04-28  ore     ESCAN00026447 FrIf_ConfigType is missing in implementation
 -            2008-04-28  ore     ESCAN00026449 No changes here
 -            2008-05-15  ore     ESCAN00026651 No changes here
 -            2008-05-19  ore     ESCAN00026973 No changes here
 -            2008-05-21  ore     -             release of version 3.0.4
 -  3.0.5     2008-06-09  ore     ESCAN00026972 Inconsistent Memory Mapping for FrIf_Lcfg.c
 -            2008-06-09  ore     ESCAN00026341 Add missing Postbuild Features
 -            2008-07-08  ore     ESCAN00027356 No changes here
 -            2008-07-09  ore     ESCAN00028155 No changes here
 -            2008-07-11  ore     -             release of version 3.0.5
 -  3.0.6     2008-07-17  ore     ESCAN00027548 No changes here
 -            2008-07-17  ore     -             release of version 3.0.6
 -  3.0.7     2008-07-18  ore     ESCAN00027867 No changes here
 -            2008-07-24  ore     ESCAN00027210 No changes here
 -            2008-07-28  ore     ESCAN00028772 No changes here
 -            2008-08-01  ore     ESCAN00027451 No changes here
 -            2008-08-07  ore     ESCAN00029068 No changes here
 -            2008-08-07  ore     ESCAN00029042 No changes here
 -            2008-08-13  ore     ESCAN00029218 No changes here
 -            2008-08-13  ore     ESCAN00029219 No changes here
 -            2008-08-13  ore     ESCAN00029184 No changes here
 -            2008-08-14  ore     -             unified define usage
 -            2008-08-15  ore     -             release of version 3.0.7
 -  3.0.8     2008-08-22  ore     ESCAN00029101 No constant is generated as link time paramter for FrIf_Init()
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
 -            2009-02-18  ore     ESCAN00031278 Missing extern declaration of FrIf_Config in FrIf.h
 -            2009-02-25  ore     ESCAN00033399 No changes here
 -            2009-02-25  ore     ESCAN00033402 The FrIf source and header files are not implemented as SingleSource.
 -            2009-02-26  ore     ESCAN00033441 No changes here
 -            2009-02-26  ore     ESCAN00032715 No changes here
 -            2009-03-05  ore     ESCAN00033650 No changes here
 -            2009-03-06  ore     ESCAN00033651 No changes here
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
 -            2009-09-08  ore     ESCAN00037633 No changes here
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
 -            2010-07-29  ore     ESCAN00044336 Ensure consistency to C-sources for all FrIf header files
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

#if (!defined  FRIF_PBCFG_H_)
# define FRIF_PBCFG_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "FrIf_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* AUTOSAR FlexRay Interface version */
# define FRIF_PBCFG_VERSION            0x0307u /*!< BCD coded FrIf PBcfg Header version number */
# define FRIF_PBCFG_RELEASE_VERSION    0x04u   /*!< BCD coded FrIf PBcfg Header release version number */

# define FRIF_INVALID_JOB_NUMBER 0xFF

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES (FrIf)
 *********************************************************************************************************************/

# if defined(FRIF_CONFIG_VARIANT) && (3u == FRIF_CONFIG_VARIANT)

#  define FRIF_START_SEC_PBCFG
#  include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

/* PRQA S 3684 DECLWITHOUSIZE *//* MD_FrIf_0812 */

     extern CONST(FrIf_TaskScheduleDataType, FRIF_PBCFG) FrIf_RxTxTaskScheduleData[];
     extern CONSTP2CONST(FrIf_RxHandleType, FRIF_PBCFG, FRIF_PBCFG) FrIf_RxHandles[];
     extern CONSTP2CONST(FrIf_TxHandleType, FRIF_PBCFG, FRIF_PBCFG) FrIf_TxHandles[];
     extern CONST(FrIf_FrameLayoutElementType, FRIF_PBCFG) FrIf_RxFrameLayoutElements[];
     extern CONST(FrIf_FrameLayoutElementType, FRIF_PBCFG) FrIf_TxFrameLayoutElements[];
     extern CONST(FrIf_FrameDescriptorType, FRIF_PBCFG) FrIf_RxFrameDescriptors[];
     extern CONST(FrIf_FrameDescriptorType, FRIF_PBCFG) FrIf_TxFrameDescriptors[];
     extern CONST(FrIf_RxPduDescriptorType, FRIF_PBCFG) FrIf_RxPduDescriptors[];
     extern CONST(FrIf_TxPduDescriptorType, FRIF_PBCFG) FrIf_TxPduDescriptors[];
     extern CONST(uint8, FRIF_PBCFG) FrIf_RxCycleMasks[];
     extern CONST(uint8, FRIF_PBCFG) FrIf_TxCycleMasks[];

/* PRQA L:DECLWITHOUSIZE *//* MD_FrIf_0812 */

#  define FRIF_STOP_SEC_PBCFG
#  include "MemMap.h" /* PRQA S 5087 *//* MD_MSR_19.1 */

# endif/* defined(FRIF_CONFIG_VARIANT) && (3u == FRIF_CONFIG_VARIANT) */

#endif
/* FRIF_PBCFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: FrIf_PBcfg.h
 *********************************************************************************************************************/

/* STOPSINGLE_OF_MULTIPLE */
