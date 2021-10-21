/*****************************************************************************
* Copyright 2010, 2016 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Nhet.h
* Module Description: NHET data structure definition
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#14 %
 * %derived_by:       jzk9cc %
 * %date_modified:    Fri Apr 19 11:38:43 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 10/13/11  2        LWW       Added NHET1 in addition to NHET0
 * 12/12/11	 3		  KJS		Added function prototype for NHET2
 * 01/27/12	 4		  JJW       Consolidated NHET1 and NHET2 initializations
 * 01/27/12	 5		  JJW       std_nhet.h name replaced std_het.h to match new TI header naming
 *                              Nhet2_Prog.h added
 * 01/31/12	 6		  JJW       Updated NHET Reg struct to contain reg defs based on TI Data sheet SPNU499-September 2011
 * 07/27/12	 7		  JJW       Removed NHET reg struct and instead included n2het_regs.h
 *                              Created buffered control structure type that mirrors the Nhet Prog structure to support HTU use
 *								Added API for setting pwm edges to abstract the user from the underlying
 *								structure names (macro access used for efficient use in mtr ctrl ISR)
 * 01/24/13	 9		  JJW       Added GetPhaseDscntCmd_m API 
 * 04/19/13	 13		  KJS       Updated constants based on anomaly 2660
 * 08/16/16	 14		  Rijvi		Updated per NHET1 design rev. 8                                               EA3#10328
 */


#ifndef NHET_H
#define NHET_H

#include "Std_Types.h"
#include "n2het_regs.h"
#include "std_nhet.h"
#include "Nhet_Prog.h"
#include "Nhet2_Prog.h"
#include "htu_regs.h"

#define D_NHETNUMHRBITS_CNT_U16    7UL   /* This is number of HR bits in the NHET Data field */
#define D_PHASEDSCNTPRD_CNT_U32    8UL   /* This is the value of PDC_PRD from the *.het program */
#define D_PHASEDSCNTOFF_CNT_U32    ((D_PHASEDSCNTPRD_CNT_U32 + 1UL) << D_NHETNUMHRBITS_CNT_U16) /* Compare Value for creating 100% Duty Cycle*/
#define D_PHASEDSCNTON_CNT_U32     (((D_PHASEDSCNTPRD_CNT_U32/2UL) - 1UL) << D_NHETNUMHRBITS_CNT_U16)     /* Compare value for creating 50% Duty Cycle */

/* NHET API Macros */
#define Nhet_Start_m()         (NHET0->NHETGCR |= 0x1U) 
#define SetPhaseDscntOn_m()    (HET_MPDC_0.memory.data_word = D_PHASEDSCNTON_CNT_U32)
#define SetPhaseDscntOff_m()   (HET_MPDC_0.memory.data_word = D_PHASEDSCNTOFF_CNT_U32)
#define GetPhaseDscntCmd_m()   (HET_MPDC_0.memory.data_word == D_PHASEDSCNTOFF_CNT_U32 ? STD_OFF : STD_ON ) /* FDD47 v007 sec 5.1.2.4 does not specify how to handle an invalid value.  This design arbitrarily defaults to Closed/STD_ON for invalid value */

#define Nhet_SetPhAUp( start, end )		Nhet_PwmControl_Cnt_G_str.UpperStart_PHASEA = start; \
										Nhet_PwmControl_Cnt_G_str.UpperEnd_PHASEA = end
#define Nhet_SetPhALo( start, end )		Nhet_PwmControl_Cnt_G_str.LowerStart_PHASEA = start; \
										Nhet_PwmControl_Cnt_G_str.LowerEnd_PHASEA = end

#define Nhet_SetPhBUp( start, end )		Nhet_PwmControl_Cnt_G_str.UpperStart_PHASEB = start; \
										Nhet_PwmControl_Cnt_G_str.UpperEnd_PHASEB = end
#define Nhet_SetPhBLo( start, end )		Nhet_PwmControl_Cnt_G_str.LowerStart_PHASEB = start; \
										Nhet_PwmControl_Cnt_G_str.LowerEnd_PHASEB = end

#define Nhet_SetPhCUp( start, end )		Nhet_PwmControl_Cnt_G_str.UpperStart_PHASEC = start; \
										Nhet_PwmControl_Cnt_G_str.UpperEnd_PHASEC = end
#define Nhet_SetPhCLo( start, end )		Nhet_PwmControl_Cnt_G_str.LowerStart_PHASEC = start; \
										Nhet_PwmControl_Cnt_G_str.LowerEnd_PHASEC = end

#define Nhet_SetPwmPeriod( x )		Nhet_PwmControl_Cnt_G_str.PWMPeriod = x
#define Nhet_SetAdcTrigA( x )		Nhet_PwmControl_Cnt_G_str.AdcTrigA = x
#define Nhet_SetAdcTrigB( x )		Nhet_PwmControl_Cnt_G_str.AdcTrigB = x

/* Must Clear buffer full interrupt flag for Control Packet 0, and re-enable CPA enabled for Control Packet0, disable CPB for this control packet (set to b01) */
#define Nhet_SetDataReady()			htuREG1->BFINTFL = 0x01UL; \
									htuREG1->CPENA = 0x01UL;   \
									HET_DATA_RDY_0.memory.data_word = 1U<<7U

/* Global NHET Functions */
FUNC(void, NHET_CODE) Nhet_Init1(void);
FUNC(void, NHET_CODE) Nhet_Per1(void);

/* NHet Shadow Structure must mirror the command structure in NHet memory */
typedef struct{

	uint32 UpperStart_PHASEA;      /* Upper Edge 1*/
	uint32 UpperEnd_PHASEA;      /* Upper Edge 2*/
	uint32 LowerStart_PHASEA;      /* Lower Edge 1*/
	uint32 LowerEnd_PHASEA; 	  /* Lower Edge 2*/

	uint32 UpperStart_PHASEB;      /* Upper Edge 1*/
	uint32 UpperEnd_PHASEB;      /* Upper Edge 2*/
	uint32 LowerStart_PHASEB;      /* Lower Edge 1*/
	uint32 LowerEnd_PHASEB; 	  /* Lower Edge 2*/

	uint32 UpperStart_PHASEC;      /* Upper Edge 1*/
	uint32 UpperEnd_PHASEC;      /* Upper Edge 2*/
	uint32 LowerStart_PHASEC;      /* Lower Edge 1*/
	uint32 LowerEnd_PHASEC; 	  /* Lower Edge 2*/

	uint32 PWMPeriod;

	uint32 AdcTrigA;
	uint32 AdcTrigB;
	uint32 BufferReadyForTransfer;
}HetPwmControl_Type;


/* Extern pwm control structure for use with the Nhet optimized API defined as macros */
extern VAR(HetPwmControl_Type, AUTOMATIC)	Nhet_PwmControl_Cnt_G_str;
extern VAR(boolean,            AUTOMATIC)   Nhet_Htu1RstFail_Cnt_G_lgc;	


#endif
