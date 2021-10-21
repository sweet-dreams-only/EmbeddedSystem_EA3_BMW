/*****************************************************************************
* Copyright 2010, 2016 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Nhet.c
* Module Description: NHET PWM Driver
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#13 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Tue May 21 09:32:04 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial Synergy Version
 * 01/27/12  2        JJW       Add NHET 2 Initialization to support Hercules parts
 * 01/31/12  3        OT        Updated to latest FDD (enabled suppression filters)
 * 01/31/12  4        JJW       Changed NHET reg names to match those defined in Nhet.h
 * 04/24/12  5        LWW       Updated NHET1 prescale and suppression filter
 * 07/27/12  6        JJW       HTU init added to support runtime optimization
 *								Global Pwm Control Command structure defined to be used as HTU source buffer 
 * 09/25/12  7		  SAH		Set pwm relay pin(28) to an output. 
 * 10/25/12  8		  Selva		NHET Periodic added for updating Nhet_PwmControl_Cnt_G_str Refer FDD 15c
 * 02/15/13	 9		  Selva     "Nhet" in global variable names are changed to CDD to make it more generic	
 * 02/18/13	 10		  KJS		Corrected anomaly 4441 and QAC warnings. 
 * 05/21/13	 11		  JJW		Added MemMap statements
 * 08/16/16	 12		  Rijvi		Updated per NHET1 design rev. 8                                               EA3#10328
 * 09/27/16  13       Selva     Updated for Anomaly EA3#11152                                                 EA3#11187
 */


/******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "Nhet.h"
#include "esm_regs.h"
#include "CalConstants.h"
#include "CDD_Data.h"
#include "GlobalMacro.h"
#include "uDiag.h"
#include <string.h> /* provide memset() and memcpy() definitions */


#  define D_PHASEA_CNT_U16 (0U)
#  define D_PHASEB_CNT_U16 (1U)
#  define D_PHASEC_CNT_U16 (2U)

#define D_INSTTODATARATIO_CNT_U16	4U	/* instructions are 16 byte aligned, data field is 4 bytes.  Expressed as a ratio is 16/4 = 4*/
#define D_DATAFLDOFFSET_CNT_U16 	8U
#define D_INITNHETADDR_CNT_U32		((uint32)&HET_AAA_BUF_0 + D_DATAFLDOFFSET_CNT_U16)	/* Initial HTU transfer instruction data field. */
#define D_HTUELEMENT_CNT_U32		(uint32)(sizeof(Nhet_PwmControl_Cnt_G_str)/4U)		/* Number of elements (32 bit words) to transfer in a single event. */
#define D_HTUFRAME_CNT_U32			1UL													/* Number of frames */

#define NHET_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */
VAR(HetPwmControl_Type, AUTOMATIC)	Nhet_PwmControl_Cnt_G_str;
#define NHET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"/* PRQA S 5087 */


#define NHET_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
VAR(boolean, AUTOMATIC) Nhet_Htu1RstFail_Cnt_G_lgc; /* Global variable for peripheral startup diagnostic -- HTU1 failed to exit reset */ 
#define NHET_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


STATIC INLINE FUNC(void, NHET_CODE) HTU1_Init(void);


#define NHET_START_SEC_CODE
#include "MemMap.h"
/*****************************************************************************
  * Name:        Nhet_Init
  * Description: NHET primary initialization  
  * Inputs:      None 
  * Outputs:     None
  *
*****************************************************************************/
FUNC(void, NHET_CODE) Nhet_Init1(void)
{
	
	/* Start initialization of NHET 1 Peripheral */
	NHET0->NHETGCR = 
	(0UL <<24) | /* 0: Disable pin disable feature */
	(0UL <<18) | /* 0: All masters can read and write the program fields.. */
	(0UL <<17) | /* 0: NHET stops when a software breakpoint is encountered.*/
	(1UL <<16) | /* 1: NHET is master */
	(0UL << 0);  /* 0: Stop NHET */


	if ((NHET0->NHETGCR & 0x1) == 0)
	{
		/* copy the HET0 program */
		(void)memcpy((void *) &e_HETPROGRAM0_UN, (const void *) HET_INIT0_PST, sizeof(HET_INIT0_PST));


		NHET0->NHETPFR     =  
				(7 << 8) | /* 7 -> lr=128  */
				(0 << 0);  /* 0 -> hr=1  */
						   /* ts = 128*1 = 128  */

		 /* XORSHARE  */
		 NHET0->NHETXOR= 
				(0 << 15) | /* 1: XOR ch 30 and 31  */
				(1 << 14) | /* 1: XOR ch 28 and 29  */
				(0 << 13) | /* 1: XOR ch 26 and 27  */
				(1 << 12) | /* 1: XOR ch 24 and 25  */
				(1 << 11) | /* 1: XOR ch 22 and 23  */
				(1 << 10) | /* 1: XOR ch 20 and 21  */
				(1 <<  9) | /* 1: XOR ch 18 and 19  */
				(0 <<  8) | /* 1: XOR ch 16 and 17  */
				(0 <<  7) | /* 1: XOR ch 14 and 15  */
				(0 <<  6) | /* 1: XOR ch 12 and 13  */
				(0 <<  5) | /* 1: XOR ch 10 and 11  */
				(0 <<  4) | /* 1: XOR ch 8 and 9  */
				(1 <<  3) | /* 1: XOR ch 6 and 7  */
				(0 <<  2) | /* 1: XOR ch 4 and 5  */
				(1 <<  1) | /* 1: XOR ch 2 and 3  */
				(0 <<  0);  /* 1: XOR ch 0 and 1  */

		  /* First clear all NHET Interrupts  */
		 NHET0->NHETINTENAC = 0xFFFFFFFFU;
			
		 /* Initialize HET Transfer Unit (HTU) 1 */
		 HTU1_Init(); 
		
		 (NHET0->NHETGCR |= 0x1U);  /* Enable NHET */

		 NHET0->NHETREQDS = 0; 		/* Must enable request for HTU only */
		 NHET0->NHETREQENS = 1U; 	/* Enable HTU request 0 */
	}
	/* End initialization of NHET 1 Peripheral */

	
	/* Start initialization of NHET 2 Peripheral */
	NHET1->NHETGCR = 
	(0 <<24) | /* 0: Disable channel disable feature */
	(0 <<18) | /* 0: All masters can read and write the program fields.. */
	(1 <<17) | /* 1: NHET doesn't stop when a software breakpoint is encountered.*/
	(1 <<16) | /* 1: NHET is master */
	(0 << 0);  /* 0: Stop NHET */


	if ((NHET1->NHETGCR & 0x1) == 0)
	{
		/* copy the HET1 program */
		(void)memcpy((void *) &e_HETPROGRAM1_UN, (const void *) HET_INIT1_PST, sizeof(HET_INIT1_PST));
		
		
		NHET1->NHETPFR =					/* Timer Prescale */
			(4 << 8) | /* 7 -> lr=16 */
			(0 << 0);  /* 0 -> hr=1 */
					   /* ts = 16*1 = 16 */
		
		NHET1->NHETINTENAC = 0xFFFFFFFFUL;	/* Disable all interrupts */
		NHET1->NHETEXC1 = 0;					/* Disable exceptions */
		NHET1->NHETPRY = 0;					/* Interrupt priority level 2 */
		NHET1->NHETAND = 0;					/* No channels are AND shared */
		
		NHET1->NHETHRSH =					/* HR (input) Sharing */
			(0 << 15) | /* Do not share ch 30 and 31  */    
			(0 << 14) | /* Do not share ch 28 and 29  */    
			(0 << 13) | /* Do not share ch 26 and 27  */    
			(0 << 12) | /* Do not share ch 24 and 25  */    
			(0 << 11) | /* Do not share ch 22 and 23  */    
			(0 << 10) | /* Do not share ch 20 and 21  */    
			(0 <<  9) | /* Do not share ch 18 and 19  */    
			(0 <<  8) | /* Do not share ch 16 and 17  */    
			(1 <<  7) | /* Share ch 14 and 15  */    
			(1 <<  6) | /* Share ch 12 and 13  */    
			(1 <<  5) | /* Share ch 10 and 11  */          
			(1 <<  4) | /* Share ch 8 and 9  */          
			(0 <<  3) | /* Do not share ch 6 and 7  */
			(1 <<  2) | /* Share ch 4 and 5  */
			(0 <<  1) | /* Do not share ch 2 and 3  */
			(0 <<  0);  /* Do not share ch 0 and 1  */
		
		NHET1->NHETXOR = 0;					/* No channels are XOR shared */
		NHET1->NHETREQENC = 0xFFU;			/* Disable all request lines */
		NHET1->NHETREQDS = 0;				/* Assign request lines to HTU */
		NHET1->NHETDIR = 0;					/* All channels are inputs */
		NHET1->NHETPULDIS = 0;				/* Pull functionality enabled on all channels */
		NHET1->NHETPSL = 0;					/* All channels are set to pull down */
		NHET1->NHETPCR = 0xAU;				/* Disable parity bit mapping, enable parity checking */
		NHET1->NHETPPR = 0;					/* No channels are affected by a parity error */
		
		NHET1->NHETSFPRLD =					/* Set suppression filter to 1.7us */
			(0x0U  << 16) | /* Scaling factor of 1 */
			(0x6U << 0);   /* Counter preload value */
							/* 0x6 * 1 * 12.5ns = 0.075us */
		
		NHET1->NHETSFENA =					/* Enable suppression Filter */
			(1 << 15) | /* Enable on ch 15 */
			(1 << 14) | /* Enable on ch 14 */
			(1 << 13) | /* Enable on ch 13 */
			(1 << 12) | /* Enable on ch 12 */
			(1 << 11) | /* Enable on ch 11 */
			(1 << 10) | /* Enable on ch 10 */
			(1 <<  9) | /* Enable on ch 9 */
			(1 <<  8) | /* Enable on ch 8 */
			(0 <<  7) | /* Disable on ch 7 */
			(0 <<  6) | /* Disable on ch 6 */
			(1 <<  5) | /* Enable on ch 5 */
			(1 <<  4) | /* Enable on ch 4 */
			(0 <<  3) | /* Disable on ch 3 */
			(0 <<  2) | /* Disable on ch 2 */
			(0 <<  1) | /* Disable on ch 1 */
			(0 <<  0);  /* Disable on ch 0 */
		
		NHET1->NHETPINDIS = 0;				/* Output buffer enable is controlled by HETDIR */
		
		
		(NHET1->NHETGCR |= 0x01U); /* Enable NHET */
		NHET1->NHETDIR |= 0x10000000;					/* Enable relay PWM output */

	}
	/* End initialization of NHET 2 Peripheral */

}



/*****************************************************************************
  * Name:        NHET_PER1
  * Description: NHET_PER1
  * Inputs:      None
  * Outputs:     None
  *  Executed if at least one of the following trigger conditions occurred:
       Triggered on MtrCtrl_Irq.C
*****************************************************************************/
FUNC(void, NHET_CODE) Nhet_Per1(void)
{
	VAR(uint16, AUTOMATIC) HalfPWMPeriod_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) tempDRise_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) tempREDf_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) UpperStart_Cnt_T_u16[3];
	VAR(uint16, AUTOMATIC) UpperEnd_Cnt_T_u16[3];
	VAR(uint16, AUTOMATIC) LowerStart_Cnt_T_u16[3];
	VAR(uint16, AUTOMATIC) LowerEnd_Cnt_T_u16[3];
	VAR(uint16, AUTOMATIC) i;
	
	STATIC VAR(uint16, AUTOMATIC) PrevLowerEnd_Cnt_M_u16[3] = {0, 0, 0};
	/* Loop used to consolidate common processing, compiler optimize for speed setting is expected to  */
	/*  perform loop unrolling in the compiled software.                                               */
	for(i = D_PHASEA_CNT_U16; i <= D_PHASEC_CNT_U16; i++)
	{	
		/* Calculate Edge Positions */
		tempDRise_Cnt_T_u16 = (CDD_PWMPeriod_Cnt_G_u16 - CDD_DCPhsComp_Cnt_G_u16[i])/2;
		UpperEnd_Cnt_T_u16[i] = tempDRise_Cnt_T_u16 + CDD_DCPhsComp_Cnt_G_u16[i];
		tempREDf_Cnt_T_u16 = tempDRise_Cnt_T_u16 + k_PwmDeadBand_Cnt_u16;
		if ( PrevLowerEnd_Cnt_M_u16[i] == tempREDf_Cnt_T_u16 )
		{
			tempREDf_Cnt_T_u16 = 0;
		}
		
		UpperStart_Cnt_T_u16[i] = Min_m(tempREDf_Cnt_T_u16, UpperEnd_Cnt_T_u16[i]);
		LowerEnd_Cnt_T_u16[i] = UpperEnd_Cnt_T_u16[i] + k_PwmDeadBand_Cnt_u16;
		LowerStart_Cnt_T_u16[i] = Max_m(tempDRise_Cnt_T_u16, PrevLowerEnd_Cnt_M_u16[i]);
		
		if (CDD_DCPhsComp_Cnt_G_u16[i] == 0)
		{
			LowerStart_Cnt_T_u16[i] = LowerEnd_Cnt_T_u16[i];
		}
		
		PrevLowerEnd_Cnt_M_u16[i] = Max_m(0, (LowerEnd_Cnt_T_u16[i] - CDD_PWMPeriod_Cnt_G_u16));
	}

		Nhet_SetPhAUp( UpperStart_Cnt_T_u16[D_PHASEA_CNT_U16], UpperEnd_Cnt_T_u16[D_PHASEA_CNT_U16] );
		Nhet_SetPhALo( LowerStart_Cnt_T_u16[D_PHASEA_CNT_U16], LowerEnd_Cnt_T_u16[D_PHASEA_CNT_U16] );

		Nhet_SetPhBUp( UpperStart_Cnt_T_u16[D_PHASEB_CNT_U16], UpperEnd_Cnt_T_u16[D_PHASEB_CNT_U16] );
		Nhet_SetPhBLo( LowerStart_Cnt_T_u16[D_PHASEB_CNT_U16], LowerEnd_Cnt_T_u16[D_PHASEB_CNT_U16] );

		Nhet_SetPhCUp( UpperStart_Cnt_T_u16[D_PHASEC_CNT_U16], UpperEnd_Cnt_T_u16[D_PHASEC_CNT_U16] );
		Nhet_SetPhCLo( LowerStart_Cnt_T_u16[D_PHASEC_CNT_U16], LowerEnd_Cnt_T_u16[D_PHASEC_CNT_U16] );

		/* Update PWM period */
		Nhet_SetPwmPeriod( CDD_PWMPeriod_Cnt_G_u16 );

		/* Update Interrupt compare value */
		HalfPWMPeriod_Cnt_T_u16 = CDD_PWMPeriod_Cnt_G_u16/2U;

		/* Update ADC trigger points */
		Nhet_SetAdcTrigA( (uint16)((sint16)HalfPWMPeriod_Cnt_T_u16 - k_ADCTrig1Offset_Cnt_s16) );
		Nhet_SetAdcTrigB( (uint16)((sint16)CDD_PWMPeriod_Cnt_G_u16 - k_ADCTrig2Offset_Cnt_s16) );

		/* Data ready for transfer */
		Nhet_SetDataReady();
}




/*****************************************************************************
  * Name:        HTU1_Init
  * Description: This function initializes the HTU 1 module
  * Inputs:      None
  * Outputs:     None
  *
*****************************************************************************/
STATIC INLINE FUNC(void, NHET_CODE) HTU1_Init(void)
{
	/* TI naming: HTU 1 registers named HTU0; HTU 2 registers named HTU1 */
	
 	/* check for HTU reset bit cleared; if not set flag */
	if( (htuREG1->GC & 1UL) == 1U )
	{
		/* Set global variable flag HTU 1 reset failed status for uDiag component */
		Nhet_Htu1RstFail_Cnt_G_lgc = TRUE; 
	}
	else
	{
		/* Clear global variable flag HTU 1 reset failed status for uDiag component */
		Nhet_Htu1RstFail_Cnt_G_lgc = FALSE; 
		
		/******************
		 * Initialize HTU *
		 ******************/
		/*************************************************
		 * Configure the control packet for WCAP capture *
		 *************************************************/
		/* Start by clearing the HTU memory. See section 20.5 of Gladiator TRM SPNU499 */
		htuDCP1->IFADDRA = 0UL;
		htuDCP1->IFADDRB = 0UL;
		htuDCP1->ITCOUNT = 	(0UL << 16U) | 	/* IETCOUNT */
							(0UL << 0U); 	/* IFTCOUNT */

		htuDCP1->IHADDRCT = (0UL << 23U) | 	/* DIR */
							(0UL << 22U) | 	/* SIZE */
							(0UL << 21U) | 	/* ADDMH */
							(0UL << 20U) | 	/* ADDFM */
							(0UL << 18U) | 	/* TMBA */
							(0UL << 16U) | 	/* TMBB */
							(0UL << 2U); 	/* IHADDR */

		/* HET instruction requests on HTU line 0 configure the control packet*/
		htuDCP1->IFADDRA = (uint32)&Nhet_PwmControl_Cnt_G_str;		/* Initial frame address set to the RAM buffer */

		htuDCP1->ITCOUNT = 	(D_HTUELEMENT_CNT_U32 	<< 16U) | 	/* IETCOUNT */
							(D_HTUFRAME_CNT_U32		<< 0U); 	/* IFTCOUNT */

		htuDCP1->IHADDRCT = (1UL << 23U) | 	/* DIR */		/* set to 1 for Main memory is read and then written to NHET RAM */
							(0UL << 22U) | 	/* SIZE */
							(0UL << 21U) | 	/* ADDMH */
							(0UL << 20U) | 	/* ADDFM */
							(0UL << 18U) | 	/* TMBA */		/* One shot mode for CPA */
							(0UL << 16U) | 	/* TMBB */		/* One shot buffer mode for CPB */
							((D_INITNHETADDR_CNT_U32 & 0x0FFCU) << 0U); 	/* IHADDR */	/* Address of NHET instruction data field location to start( Least significant 12 bits, with LSB 2 bits masked out) */

		/*configure the HTU*/
		htuREG1->BFINTFL = 0xFFUL;	/* Clear all CP Buffer full flags */
		htuREG1->CPENA = 0x01UL; 	/* CPA is enabled for Control Packet0, disable CPB for this control packet (set to b01) */
						
		/* Configure 1 region memory protection: */
		htuREG1->MPCS = (0UL << 17U) |	/* MPEFT1 */	/*Cleared on reset*/
						(0UL << 16U) |	/* MPEFT0 */	/*Cleared on reset*/
						(0UL << 5U) |	/* INTENA01 */
						(0UL << 4U) |	/* ACCR01 */
						(0UL << 3U) |	/* REG01ENA */
						(1UL << 2U) |	/* INTENA0 */   /* Error Signaling is enabled region 0 */
						(1UL << 1U) |	/* ACCR */      /* HTU access forbidden outside region 0 */
						(1UL << 0U);	/* REG0ENA */   /* Protection outside the memory region region 0 enable */

		/* Region 0 memory protection covers the TCM RAM buffer containing the new values for the data fields of the Nhet instructions */
		htuREG1->MP0S = (uint32)&Nhet_PwmControl_Cnt_G_str;
		htuREG1->MP0E = (uint32)&Nhet_PwmControl_Cnt_G_str + ((uint32)sizeof(Nhet_PwmControl_Cnt_G_str) - 4UL);


		/* Enble the HTU */
		htuREG1->GC = 	(0UL << 24U) | 	/* VBUSHOLD */
						(1UL << 16U) | 	/* HTUEN */
						(0UL << 8U)  | 	/* DEBM */
						(0UL << 0U) ; 	/* HTURES */

		/* Init the constant data fields of the PwmControl structure (e.g. the transfer ready flag, etc.) */
		Nhet_PwmControl_Cnt_G_str.BufferReadyForTransfer = 1<<7;
	}
}


#define NHET_STOP_SEC_CODE
#include "MemMap.h"
