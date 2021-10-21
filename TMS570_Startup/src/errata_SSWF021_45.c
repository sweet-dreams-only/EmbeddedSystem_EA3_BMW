/* Original Header copied from TI file */
/*
 * errata_SSWF021_45.c
 *
 *  Created on: May 4, 2016
 *      Author: a0319960
 */
/*****************************************************************************
* Module File Name  : errata_SSWF021_45.c
* Module Description: This file contains the function definitions for the errata for PLL provided by TI
					  as per the erratum SSWF021#45
* Product           : Gen II Plus EA3.0
* Author            : Avinash James
*****************************************************************************/
/* Version Control:
 * Date Created:      Sat Jun 04 12:17:00 2016
 * %version:          1 %
 * %derived_by:       rzk04c %
 * %date_modified:    Fri Feb 15 16:29:22 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/23/16  1        AJM        Initial version for PLL errata functions									 EA3#9142
 * 08/24/16  2        AJM        Removed the retry count parameter											 EA3#10463
 */

#include "Std_Types.h"
#include "startup_cfg.h"
#include "system_regs.h"
#include "errata_SSWF021_45.h"

static uint32 check_frequency(uint32 cnt1_clksrc);
static uint32 disable_plls(uint32 plls);


uint32 _errata_SSWF021_45_both_plls(uint32 count)
{
	uint32 failCode_Cnt_T_u32;
	uint32 retries_Cnt_T_u32;
	uint32 clkCntlSav_Cnt_T_u32;

    /* save CLKCNTL, then set VCLK = HCLK, enable peripherals */
	clkCntlSav_Cnt_T_u32 = (systemREG1->VCLK2R << 24U) | (systemREG1->VCLKR << 16U) | (systemREG1->PENA << 8U);
	systemREG1->VCLK2R = 0U;
	systemREG1->VCLKR = 0U;
	systemREG1->PENA = 1U;
	
	for(retries_Cnt_T_u32 = 0U; (retries_Cnt_T_u32 < count) || (count == 0U); retries_Cnt_T_u32++)
	{
		failCode_Cnt_T_u32 = 0U;
		/* Disable PLL1 and PLL2 */
		if(failCode_Cnt_T_u32 = disable_plls(SYS_CLKSRC_PLL1 | SYS_CLKSRC_PLL2) != 0U)
		{
			break;
		}

		/* Clear Global Status Register */
		systemREG1->GBLSTAT = 0x00000301U;

		/* Clear the ESM PLL slip flags */
		esmREG->SR1[0U] = ESM_SR1_PLL1SLIP;
		esmREG->SR4[0U] = ESM_SR4_PLL2SLIP;
		/* set both PLLs to OSCIN/1*27/(2*1) */

		systemREG1->PLLCTL1 = 0x20001A00U;
	    systemREG1->PLLCTL2 = 0x3FC0723DU;
	    systemREG2->PLLCTL3 = 0x20001A00U;

	    systemREG1->CSDISCLR =	SYS_CLKSRC_PLL1 | SYS_CLKSRC_PLL2;
		/* Check for (PLL1 valid or PLL1 slip) and (PLL2 valid or PLL2 slip) */
		while  (((systemREG1->CSVSTAT & SYS_CLKSRC_PLL1) == 0U) && ((esmREG->SR1[0U] & ESM_SR1_PLL1SLIP) == 0U) ||
				((systemREG1->CSVSTAT & SYS_CLKSRC_PLL2) == 0U) && ((esmREG->SR4[0U] & ESM_SR4_PLL2SLIP) == 0U))
		{
			/* Wait */
		}
		/* If PLL1 valid, check the frequency */
		if((esmREG->SR1[0U] & ESM_SR1_PLL1SLIP) != 0U)
		{
		  failCode_Cnt_T_u32 |= 1U;
		}
		else
		{
			failCode_Cnt_T_u32 |= check_frequency(dcc1CNT1_CLKSRC_PLL1);
		}
		/* If PLL2 valid, check the frequency */
		if((esmREG->SR4[0U] & ESM_SR4_PLL2SLIP) != 0U)
		{
		  failCode_Cnt_T_u32 |= 2U;
		}
		else
		{
			failCode_Cnt_T_u32 |= (check_frequency(dcc1CNT1_CLKSRC_PLL2) << 1U);
		}
		if (failCode_Cnt_T_u32 == 0U)
		{
			break;
		}
	}
	
	disable_plls(SYS_CLKSRC_PLL1 | SYS_CLKSRC_PLL2);
	/* restore CLKCNTL */
	systemREG1->VCLKR = (uint8)((clkCntlSav_Cnt_T_u32 >> 16U) & 0xFU);
	systemREG1->VCLK2R = (uint8)((clkCntlSav_Cnt_T_u32 >> 24U) & 0xFU);
	systemREG1->PENA = (uint8)((clkCntlSav_Cnt_T_u32 >> 8U) & 0xFU);
	
	return failCode_Cnt_T_u32;
}

uint32 _errata_SSWF021_45_pll1( uint32 count)
{
	uint32 failCode_Cnt_T_u32;
	uint32 retries_Cnt_T_u32;
	uint32 clkCntlSav_Cnt_T_u32;

    /* save CLKCNTL, then set VCLK = HCLK, enable peripherals */
	clkCntlSav_Cnt_T_u32 = (systemREG1->VCLK2R << 24U) | (systemREG1->VCLKR << 16U) | (systemREG1->PENA << 8U);
	systemREG1->VCLK2R = 0U;
	systemREG1->VCLKR = 0U;
	systemREG1->PENA = 1U;
	
	for(retries_Cnt_T_u32 = 0U; (retries_Cnt_T_u32 < count) || (count == 0U); retries_Cnt_T_u32++)
	{
		failCode_Cnt_T_u32 = 0U;
		/* Disable PLL1 */
		if(failCode_Cnt_T_u32 = disable_plls(SYS_CLKSRC_PLL1) != 0U)
		{
			break;
		}

		/* Clear Global Status Register */
		systemREG1->GBLSTAT = 0x00000301U;
		
		/* Clear the ESM PLL slip flags */
		esmREG->SR1[0U] = ESM_SR1_PLL1SLIP;
		
		/* set PLL1 to OSCIN/1*27/(2*1) */
		
	    systemREG1->PLLCTL1 = 0x20001A00U;
	    systemREG1->PLLCTL2 = 0x3FC0723DU;
		
	    systemREG1->CSDISCLR =	SYS_CLKSRC_PLL1;
		/* Check for (PLL1 valid or PLL1 slip) */
		while(((systemREG1->CSVSTAT & SYS_CLKSRC_PLL1) == 0U) && ((esmREG->SR1[0] & ESM_SR1_PLL1SLIP) == 0U))
		{
			/* Wait */
		}

		/* If PLL1 valid, check the frequency */
		if((esmREG->SR1[0U] & ESM_SR1_PLL1SLIP) != 0U)
		{
		  failCode_Cnt_T_u32 |= 1U;
		}
		else
		{
			failCode_Cnt_T_u32 |= check_frequency(dcc1CNT1_CLKSRC_PLL1);
		}
		if (failCode_Cnt_T_u32 == 0U)
		{
			break;
		}
	}
	disable_plls(SYS_CLKSRC_PLL1);
	/* restore CLKCNTL */
	systemREG1->VCLKR = (uint8)((clkCntlSav_Cnt_T_u32 >> 16U) & 0xFU);
	systemREG1->VCLK2R = (uint8)((clkCntlSav_Cnt_T_u32 >> 24U) & 0xFU);
	systemREG1->PENA = (uint8)((clkCntlSav_Cnt_T_u32 >> 8U) & 0xFU);
	
	return failCode_Cnt_T_u32;
}

uint32 _errata_SSWF021_45_pll2( uint32 count)
{
	uint32 failCode_Cnt_T_u32;
	uint32 retries_Cnt_T_u32;
	uint32 clkCntlSav_Cnt_T_u32;

    /* save CLKCNTL, then set VCLK = HCLK, enable peripherals */
	clkCntlSav_Cnt_T_u32 = (systemREG1->VCLK2R << 24U) | (systemREG1->VCLKR << 16U) | (systemREG1->PENA << 8U);
	systemREG1->VCLK2R = 0U;
	systemREG1->VCLKR = 0U;
	systemREG1->PENA = 1U;
	
	for(retries_Cnt_T_u32 = 0U; (retries_Cnt_T_u32 < count) || (count == 0U); retries_Cnt_T_u32++)
	{
		failCode_Cnt_T_u32 = 0U;
		/* Disable PLL2 */
		if(failCode_Cnt_T_u32 = disable_plls(SYS_CLKSRC_PLL2) != 0U)
		{
			break;
		}

		/* Clear Global Status Register */
		systemREG1->GBLSTAT = 0x00000301U;
		
		/* Clear the ESM PLL slip flags */
		esmREG->SR4[0U] = ESM_SR4_PLL2SLIP;
		
		/* set PLL2 to OSCIN/1*27/(2*1) */
	    systemREG2->PLLCTL3 = 0x20001A00U;
	    systemREG1->CSDISCLR = SYS_CLKSRC_PLL2;
		
	    /* Check for PLL2 valid or PLL2 slip */
		while (((systemREG1->CSVSTAT & SYS_CLKSRC_PLL2) == 0U) && ((esmREG->SR4[0U] & ESM_SR4_PLL2SLIP) == 0U))
		{
			/* Wait */
		}
		
		/* If PLL2 valid, check the frequency */
		if((esmREG->SR4[0U] & ESM_SR4_PLL2SLIP) != 0U)
		{
		  failCode_Cnt_T_u32 |= 2U;
		}
		else
		{
			failCode_Cnt_T_u32 |= (check_frequency(dcc1CNT1_CLKSRC_PLL2) << 1U);
		}
		if (failCode_Cnt_T_u32 == 0U)
		{
			break;
		}
	}
	disable_plls(SYS_CLKSRC_PLL2);
	
	/* restore CLKCNTL */
	systemREG1->VCLKR = (uint8)((clkCntlSav_Cnt_T_u32 >> 16U) & 0xFU);
	systemREG1->VCLK2R = (uint8)((clkCntlSav_Cnt_T_u32 >> 24U) & 0xFU);
	systemREG1->PENA = (uint8)((clkCntlSav_Cnt_T_u32 >> 8U) & 0xFU);
	
	return failCode_Cnt_T_u32;
}

static uint32 check_frequency(uint32 cnt1_clksrc)
{
	/* Setup DCC1 */
    /* DCC1 Global Control register configuration */
	dccREG1->GCTRL      = (uint32)0x5U |       /** Disable  DCC1 */
						  (uint32)((uint32)0x5U << 4U) | /** No Error Interrupt */
						  (uint32)((uint32)0xAU << 8U) | /** Single Shot mode */
						  (uint32)((uint32)0x5U << 12U); /** No Done Interrupt */
	/* Clear ERR and DONE bits */
	dccREG1->STAT = 3U;
	/* DCC1 Clock0 Counter Seed value configuration */
    dccREG1->CNT0SEED   = 68U;
    /* DCC1 Clock0 Valid Counter Seed value configuration */
    dccREG1->VALID0SEED = 4U;
    /* DCC1 Clock1 Counter Seed value configuration */
    dccREG1->CNT1SEED   = 972U;
    /* DCC1 Clock1 Source 1 Select */
    dccREG1->CNT1CLKSRC = (uint32)((uint32)10U << 12U) |     /** DCC Enable / Disable Key */
                          (uint32) cnt1_clksrc;  /** DCC1 Clock Source 1 */

    dccREG1->CNT0CLKSRC = (uint32)DCC1_CNT0_OSCIN;  /** DCC1 Clock Source 0 */

    /* DCC1 Global Control register configuration */
    dccREG1->GCTRL      = (uint32)0xAU |       /** Enable  DCC1 */
                          (uint32)((uint32)0x5U << 4U) | /** No Error Interrupt */
                          (uint32)((uint32)0xAU << 8U) | /** Single Shot mode */
                          (uint32)((uint32)0x5U << 12U); /** No Done Interrupt */
    while(dccREG1->STAT == 0U)
    {
    	/* Wait */
    }
    return (dccREG1->STAT & 0x01U);
}

static uint32 disable_plls(uint32 plls)
{
	uint32 timeout_Cnt_T_u32,failCode_Cnt_T_u32;

	systemREG1->CSDISSET = plls;
	timeout_Cnt_T_u32 =0x10U;
	while(((systemREG1->CSVSTAT & (plls)) != 0U) && (--timeout_Cnt_T_u32 != 0U))
	{
	/* Wait */
	}
	if(timeout_Cnt_T_u32 == 0U)
	{
		failCode_Cnt_T_u32 = 4U;
	}
	else
	{
		failCode_Cnt_T_u32 = 0U;
	}
	return failCode_Cnt_T_u32;

}

