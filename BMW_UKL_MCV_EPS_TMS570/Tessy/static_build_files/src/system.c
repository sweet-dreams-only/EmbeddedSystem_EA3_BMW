/** @file system.c 
*   @brief System Driver Source File
*   @date 21.July.2009
*   @version 1.00.000
*
*   This file contains:
*   - API Funcions
*   .
*   which are relevant for the System driver.
*/

/* (c) Texas Instruments 2009, All rights reserved. */

/* USER CODE BEGIN (0) */
/* USER CODE END */


/* Include Files */

#include "system.h"
#include "sys_vim.h"


/* USER CODE BEGIN (1) */
/* USER CODE END */


/** @fn void systemInit(void)
*   @brief Initializes System Driver
*
*   This function initializes the System driver.
*
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */

void systemInit(void)
{
/* USER CODE BEGIN (3) */
/* USER CODE END */

    /** @b Initialize @b Flash @b Wrapper: */

    /** - Setup flash read mode, address wait states and data wait states */
    FLASHW->FRDCNTL =  0x01000000U 
                    | (3U << 8U) 
                    | (1U << 4U) 
                    |  1U;

    /** - Setup flash bank power modes */
    FLASHW->FBFALLBACK = (SYS_SLEEP << 14U) 
                       | (SYS_SLEEP << 12U) 
                       | (SYS_SLEEP << 10U) 
                       | (SYS_SLEEP << 8U) 
                       | (SYS_ACTIVE << 6U) 
                       | (SYS_ACTIVE << 4U) 
                       | (SYS_ACTIVE << 2U) 
                       |  SYS_ACTIVE;

    /** @b Initialize @b Pll: */

    /** - Setup pll control register 1:
    *     - Setup reset on oscillator slip 
    *     - Setup bypass on pll slip
    *     - Setup Pll output clock divider
    *     - Setup reset on oscillator fail
    *     - Setup reference clock divider 
    *     - Setup Pll multiplier          
    */
    // Workaround for FMZPLL#17 errata
    SYSTEM_1->PLLCTL1 = 0x41036300U; 
    SYSTEM_1->PLLCTL1 = 0x21036300U; // Prathap 100 MHZ from 16MHZ

	// Clearing the Slip Bit
	SYSTEM_1->GBLSTAT = 0x300;

    /** - Setup pll control register 1 
    *     - Enable/Disable frequency modulation
    *     - Setup spreading rate
    *     - Setup bandwidth adjustment
    *     - Setup internal Pll output divider
    *     - Setup spreading amount
    */
    SYSTEM_1->PLLCTL2 = 0x3FC0623DU;


    /** @b Initialize @b Clock @b Tree: */

    /** - Start clock source lock */
    SYSTEM_1->CSDIS = 0x00000000U 
                    | 0x00000000U 
                    | 0x00000000U 
                    | 0x00000008U 
                    | 0x00000004U 
                    | 0x00000000U 
                    | 0x00000000U;

    /** - Wait for until clocks are locked */
    while ((SYSTEM_1->CSVSTAT & ((SYSTEM_1->CSDIS ^ 0xFF) & 0xFF)) != ((SYSTEM_1->CSDIS ^ 0xFF) & 0xFF));

    /** - Setup GCLK, HCLK and VCLK clock source for normal operation, power down mode and after wakeup */
    SYSTEM_1->GHVSRC = (SYS_PLL << 24U) 
                     | (SYS_PLL << 16U) 
                     |  SYS_PLL;

    /** - Power-up all peripharals */
    PCR->PSPWRDWNCLR0 = 0xFFFFFFFFU;
    PCR->PSPWRDWNCLR1 = 0xFFFFFFFFU;
    PCR->PSPWRDWNCLR2 = 0xFFFFFFFFU;
    PCR->PSPWRDWNCLR3 = 0xFFFFFFFFU;

    /** - Setup synchronous peripheral clock dividers for VCLK1 and VCLK2 */
    SYSTEM_1->VCLK2R = 0U;
    SYSTEM_1->VCLKR  = 0U;

    /** - Setup RTICLK1 and RTICLK2 clocks */
    SYSTEM_1->RCLKSRC = (1U << 24U)
                      | (SYS_VCLK << 16U) 
                      | (1U << 8U)  
                      |  SYS_VCLK;

    /** - Setup asynchronous peripheral clock sources for AVCLK1 and AVCLK2 */
    SYSTEM_1->VCLKASRC = (SYS_VCLK << 8U)
                       |  SYS_VCLK;

    /** - Enable Peripherals */
    SYSTEM_1->PENA = 1U;

    /** @note: HCLK >= VCLK2 >= VCLK_sys */

/* USER CODE BEGIN (4) */

    /** - Enable Peripherals */   // Prathap
    SYSTEM_1->MINITGCR 	= 0xAU;
    SYSTEM_1->MSINENA	= 0xFFFFFFFEU;
	while(SYSTEM_1->MINISTAT != 0x0000657EU); // 3 MIBSPI will not be unless out of reset.
    SYSTEM_1->MINITGCR 	= 0x5U; // Prathap

	VIM_PARITY->PARCTL = 0xA;

/* USER CODE END */
}

/* USER CODE BEGIN (5) */
/* USER CODE END */
