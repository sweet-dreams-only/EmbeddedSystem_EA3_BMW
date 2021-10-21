/*****************************************************************************
* Copyright 2011 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Compiler_Cfg.h
* Module Description: This file contains a stub header for UTP and QAC 
*                     projects
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri May  9 16:48:22 2003
* %version:          1 %
* %derived_by:       cz7lt6 %
* %date_modified:    Tue May 28 15:52:09 2013 %
*---------------------------------------------------------------------------*/
#ifndef NHET_H
#define NHET_H

#include "Nhet_Prog.h"

#define D_NHETNUMHRBITS_CNT_U16    7UL   /* This is number of HR bits in the NHET Data field */
#define D_PHASEDSCNTPRD_CNT_U32    8UL   /* This is the value of PDC_PRD from the *.het program */
#define D_PHASEDSCNTOFF_CNT_U32    ((D_PHASEDSCNTPRD_CNT_U32 + 1UL) << D_NHETNUMHRBITS_CNT_U16) /* Compare Value for creating 100% Duty Cycle*/
#define D_PHASEDSCNTON_CNT_U32     (((D_PHASEDSCNTPRD_CNT_U32/2UL) - 1UL) << D_NHETNUMHRBITS_CNT_U16)     /* Compare value for creating 50% Duty Cycle */


#define SetPhaseDscntOn_m()    (HET_MPDC_0.memory.data_word = D_PHASEDSCNTON_CNT_U32)
#define SetPhaseDscntOff_m()   (HET_MPDC_0.memory.data_word = D_PHASEDSCNTOFF_CNT_U32)
#define SetPhaseDscntOff_m()   (HET_MPDC_0.memory.data_word = D_PHASEDSCNTOFF_CNT_U32)
#define GetPhaseDscntCmd_m()   (HET_MPDC_0.memory.data_word == D_PHASEDSCNTOFF_CNT_U32 ? STD_OFF : STD_ON ) /* FDD47 v007 sec 5.1.2.4 does not specify how to handle an invalid value.  This design arbitrarily defaults to Closed/STD_ON for invalid value */


#endif  /* NHET_H */





