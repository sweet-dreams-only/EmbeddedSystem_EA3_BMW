/** @file pbist.c 
*   @brief PBIST Driver Inmplmentation File
*   @date 14.September.2009
*   @version 1.00.000
*
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "pbist.h"
#include "sci.h"
#include "system.h"

extern unsigned int SubTask_Number;

/** @fn void pbistInit(unsigned int RAM_GRP_SEL)
*   @brief Initializes the PBIST Driver
*
*   This function initializes the PBIST module based on the RAM group selected.
* 	Note : If value RAM Group = 0 --> All memories are selected with RAM override  
*/
void pbistInit(unsigned int RAM_GRP_SEL)
{
	/*Enable PBIST Memory Init MSI register*/
	SYSTEM_1->MSINENA = 1U;
	
	/*Enable PBIST self test*/
	SYSTEM_1->MSTGCR = 0x0A;

	/*Since ROM CLK = HCLK selected by default, MBIST will be reset for 16 VBUSclock cycles  */
	/* 		N = 16 when HCLK:PBIST ROM clock is  1:1  -- N - VBUS Wait Cycles
			N = 32 when HCLK:PBIST ROM clock is  1:2
			N = 64 when HCLK:PBIST ROM clock is  1:4
			N = 64 when HCLK:PBIST ROM clock is  1:8
	*/
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");
		asm("	nop");

	/* Enable Pbist Internal clocks and ROM I/F clocks*/
    pbistREG->PACT = 3U;

	if(RAM_GRP_SEL == 0)
	{
		/*for 1,2 PORT and ROM MEMORIES*/
		pbistREG->ALGO = 0xFFFF;
	
		/* RAM GROUP information */
		pbistREG->RINFOL = 0x3FFF;
		pbistREG->RINFOU = 0x00000000;
		
		/*selcting Run selft test with RAM overide*/
		pbistREG->PBISTOVERRRIDE = 0x01;
	}
	else // Individual RAM Test based on RAM group selected 
	{
		/*for 1,2 PORT and ROM MEMORIES*/
		pbistREG->ALGO = RAM_GRP_ALGO_SEL[RAM_GRP_SEL];
	
		/* RAM GROUP information */
		pbistREG->RINFOL = (1 << (RAM_GRP_SEL -1));
		pbistREG->RINFOU = 0x00000000;
		
		/*selcting Run selft test without RAM overide*/
		pbistREG->PBISTOVERRRIDE = 0x00;
	}
    	
	/* Microcode loading from the OnChip ROM. Default is onchip ROM*/
	pbistREG->ROM =0x03;
}

/** @fn void pbistDisableSelfTest()
*   @brief Disable Pbist Self Test.
*/
void pbistDisableSelfTest()
{
	/*Disable PBIST self test in Sys*/
	SYSTEM_1->MSTGCR = 0x0A;

	/*Disable PBIST internal ROM anc Clocks*/
	pbistREG->PACT=0x00;
}


/** @fn void pbistStartSelfTest(void)
*   @brief Triggers the pbist Self test, Wait till it completes.
*/
void pbistStartSelfTest(void)
{
	/* DataLogger register with 0x14 to start the test*/
	pbistREG->DLR =0x14;		/*test will start after writing this vaule to the DLa register*/

	/* Wait till the MSTDONE Bit- PBIST Test Complete */
	while((SYSTEM_1->MSTCGSTAT & 1) != 0x1);

	if((pbistREG->FSRFO || pbistREG->FSRF1 )==0x00)
	{
		//return TRUE;
		sciSend_32bitdata(sciREG1, 1);
	}
	else
	{
	//	return FALSE;
		sciSend_32bitdata(sciREG1, 0);
	}
}

/** @fn void pbist_test(void)
*   @brief Function used to perform PBIST self test as per selected Sub Task.
*/
void pbist_test(void)
{
	pbistInit(SubTask_Number);
	pbistStartSelfTest();
	pbistDisableSelfTest();
}	

