/** @file vim.c 
*   @brief VIM Driver Inmplmentation File
*   @date 11.August.2009
*   @version 1.00.000
*
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "sys_vim.h"

/** @fn void VIMRAM_Parity(void)
*   @brief VIMRAM Parity Error creation and check routines.
*/

void VIMRAM_Parity(void)
{
	volatile unsigned int temp;
	
	/** - Pointer to VIM RAM */
	unsigned int *vimram_ptr = (unsigned int *)(0xFFF82000);
	
	/** - Pointer to VIM PARITY RAM */
	unsigned int *vimpar_ptr = (unsigned int *)(0xFFF82400);
	
	/** - Enable Parity RAM memory mappring */
	VIM_PARITY->PARCTL |= 0x100;
 	
 	/** - Corrupt Parity to create Parity error */
 	vimpar_ptr++;
 	*vimpar_ptr=(~(*vimpar_ptr));
 	
 	/** - Disable Parity RAM memory mapping */
  	VIM_PARITY->PARCTL &= 0xFFFFFEFF;
 	vimram_ptr++;
  	
  	/** - Read the RAM location which has parity error */
  	temp = *vimram_ptr;
    
    asm("	nop");
    asm("	nop");
    asm("	nop");
    
	/** - Enable Parity RAM memory mappring */
	VIM_PARITY->PARCTL |= 0x100;
 	
 	/** - Go back to the correct Parity, undo corruption */
 	*vimpar_ptr=(~(*vimpar_ptr));
	
	/** - Wait till Parity Error Flag is Set */
	while(VIM_PARITY->PARFLG == 0);
	
	/** - Clear Error Flag */
	VIM_PARITY->PARFLG = 1;
}
 
