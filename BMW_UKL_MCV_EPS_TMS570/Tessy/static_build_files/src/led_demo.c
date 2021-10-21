/** @file led_demo.c 
*   @brief led demo implementation File
*   @date 11.August.2009
*   @version 1.00.000
*
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "nhet.h"
#include "gio.h"

extern unsigned int 	SubTask_Number;
extern unsigned int 	Task_Number;
#define PACKAGE_MEM	 	(*(volatile unsigned int *) 0x06040AC)
#define PACKAGE_337		0x0151

/** @fn void Running_LED_demo(void)
*   
*   This function is used for LED demo based on the SCI
*   command different LED's are turned on and a running 
*	LED demo is included
*/
void Running_LED_demo(void)
{
	unsigned int temp;		/** - Temporary Variable */
	unsigned int pwm;		/** - Variable to count the width */
	unsigned int count;		/** - Vaiable to toggle the pulse width*/
	unsigned int delay;		/** - Delay Variable */
	
	delay				= 0x200000;

    /** - NHET is configured as Master 
     *  - NHET is turned On */    
   	nhetREG->GCR     	= 0x01000001; 
	
	/** - PULL functinality is enabled */
	nhetREG->HETPULDIS	= 0x00000000;

	/** - Check for the Package Details from OTP location
	 * 	  337 Package - MDK Board 		- 0x151
	 *    144 Package - USB Stick Board - 0x090
	 * 	  LEO show software routines are selected based on the 
	 * 	  since same image is progammed for all packages */
	 
	/** - It's not 337 package */
	if(((PACKAGE_MEM & 0xFFFF0000) >> 16) != PACKAGE_337)
	{
   		/** - Configure NHET[0-5] pins as output 
   		 *  - These pins are connected to the LED's */
   		nhetREG->CCDIR   	= 0x0000003F; 
   		
		switch(SubTask_Number)
		{

			case 0:
					/** - Take all pins to level 0 */
					nhetREG->CCDWR   	= 0x00000000;
					break;
			case 1:
					pwm = 0;
					count = 0;
					/** - Do the LED Demo Toggle, Until othe Task selected 
					 *  - The below loop generates a varying pulse width at
					 *    HET pins[0-5] which helps in blinking LEO demo */
					
					while((Task_Number == 9) && (SubTask_Number ==1))
					{
						
						/** - Set only NHET Pin 0,2,3,5 
						 * 	  Clr NHET Pin 1,4 */
						nhetREG->CCDWR   	= 0x0000002D;
						
						for(temp=0;temp<pwm;temp++);
					
						if((pwm == 0x800))
						{
							for(temp=0;temp<0x100000;temp++);
						}
						/** - Set only NHET Pin 1,4 
						 *    Clr NHET Pin 0,2,3,5 */
						nhetREG->CCDWR   	= 0x00000012;
						
						for(temp=0;temp<(0x800 - pwm);temp++);

						if((pwm == 0x00))
						{
							for(temp=0;temp<0x100000;temp++);
						}

						if(pwm == 0x800)
						{
							count = 1;
						
						}
						if(pwm == 0)
						{
							count = 0;
						}

						if(count != 0)
						{
							pwm--;
						}
						else
						{
							pwm++;
						}
					}
					/** - Clear HET pins end of the demo */
					nhetREG->CCDWR   	= 0x00000000;
					break;
			case 2:
					/** - Set NHET Pin 0 */
					nhetREG->CCDSET   	= 0x00000001;
					break;
			case 3:
					/** - Clear NHET Pin 0 */
					nhetREG->CCDCLR   	= 0x00000001;
					break;
			case 4:
					/** - Set NHET Pin 1 */
					nhetREG->CCDSET   	= 0x00000002;
					break;
			case 5:
					/** - Clear NHET Pin 1 */
					nhetREG->CCDCLR   	= 0x00000002;
					break;
			case 6:
					/** - Set NHET Pin 2 */
					nhetREG->CCDSET   	= 0x00000004;
					break;
			case 7:
					/** - Clear NHET Pin 2 */					
					nhetREG->CCDCLR   	= 0x00000004;
					break;
			case 8:
					/** - Set NHET Pin 3 */
					nhetREG->CCDSET   	= 0x00000008;
					break;
			case 9:
					/** - Clear NHET Pin 3 */					
					nhetREG->CCDCLR   	= 0x00000008;
					break;
			case 10:
					/** - Set NHET Pin 4 */
					nhetREG->CCDSET   	= 0x00000010;
					break;
			case 11:
					/** - Clear NHET Pin 4 */
					nhetREG->CCDCLR   	= 0x00000010;
					break;
			case 12:
					/** - Set NHET Pin 5 */
					nhetREG->CCDSET   	= 0x00000020;
					break;
			case 13:
					/** - Clear NHET Pin 5 */					
					nhetREG->CCDCLR   	= 0x00000020;
					break;
		}
	}
	/** - It's 337 package */
	else
	{
   		/** - Configure NHET[31,0-5] pins as output */ 
   		nhetREG->CCDIR   	= 0x8000003F;
   		
		switch(SubTask_Number)
		{
			case 0:
					/** - Take all HET and GIO Port A pins to level 0 */
					nhetREG->CCDWR   	= 0x00000000;
					gioSetPort(gioPORTA, 0);
					break;
			case 1:
					/** - Do the LED Demo Toggle, Until othe Task selected 
					 *  - The below loop generates a varying pulse width at
					 *    GIOA[0,3,4,5], HET pins[0-5] which helps in blinking LEO demo */
					while((Task_Number == 9) && (SubTask_Number ==1))
					{
						/** - Set only GIOA Pin 0 */
						gioSetPort(gioPORTA, 1);
						/** - Simple Dealy */
						for(temp=0;temp<delay;temp++);
						/** - Set only GIOA Pin 3 */
						gioSetPort(gioPORTA, 8);
						/** - Simple Dealy */
						for(temp=0;temp<delay;temp++);
						/** - Set only GIOA Pin 4 */
						gioSetPort(gioPORTA, 0x10);
						/** - Simple Dealy */
						for(temp=0;temp<delay;temp++);
						/** - Set only GIOA Pin 5 */
						gioSetPort(gioPORTA, 0x20);	
						/** - Simple Dealy */
						for(temp=0;temp<delay;temp++);
						/** - Clr all pins in GIOA Port */
						gioSetPort(gioPORTA, 0);	
						/** - Set only NHET[1] pin  */
						nhetREG->CCDWR   	= 0x00000002;
						/** - Simple Dealy */
						for(temp=0;temp<delay;temp++);
						/** - Set only NHET[31] pin */
						nhetREG->CCDWR   	= 0x80000000;
						/** - Simple Dealy */
						for(temp=0;temp<delay;temp++);
						/** - Set only NHET[1] pin */
						nhetREG->CCDWR   	= 0x00000002;
						/** - Simple Dealy */
						for(temp=0;temp<delay;temp++);
						/** - Clr all NHET pins */
						nhetREG->CCDWR   	= 0x00000000;
						/** - Set only GIOA Pin 5 */
						gioSetPort(gioPORTA, 0x20);	
						/** - Simple Dealy */
						for(temp=0;temp<delay;temp++);
						/** - Set only GIOA Pin 5 */
						gioSetPort(gioPORTA, 0x10);
						/** - Simple Dealy */
						for(temp=0;temp<delay;temp++);
						/** - Set only GIOA Pin 3 */
						gioSetPort(gioPORTA, 8);
						/** - Simple Dealy */
						for(temp=0;temp<delay;temp++);
						/** - Set only GIOA Pin 0 */
						gioSetPort(gioPORTA, 1);
					}
				/** - Take all HET and GIO Port A pins to level 0 */
				gioSetPort(gioPORTA, 0);
				nhetREG->CCDWR   	= 0x00000000;
				break;

			case 2:
					/** - Set GIOA Pin 0 */
					gioSetBit(gioPORTA, 0, 1);
					break;
			case 3:
					/** - Clr GIOA Pin 0 */
					gioSetBit(gioPORTA, 0, 0);
					break;
			case 4:
					/** - Set GIOA Pin 3 */
					gioSetBit(gioPORTA, 3, 1);
					break;
			case 5:
					/** - Clr GIOA Pin 3 */
					gioSetBit(gioPORTA, 3, 0);
					break;
			case 6:
					/** - Set GIOA Pin 4 */
					gioSetBit(gioPORTA, 4, 1);
					break;
			case 7:
					/** - Clr GIOA Pin 4 */
					gioSetBit(gioPORTA, 4, 0);
					break;
			case 8:
					/** - Set GIOA Pin 6 */
					gioSetBit(gioPORTA, 5, 1);	
					break;
			case 9:
					/** - Clr GIOA Pin 6 */
					gioSetBit(gioPORTA, 5, 0);	
					break;
			case 10:
					/** - Set NHET Pin 1 */
					nhetREG->CCDSET   	= 0x00000002;
					break;
			case 11:
					/** - Clr NHET Pin 31 */
					nhetREG->CCDCLR   	= 0x00000002;
					break;
			case 12:
					/** - Set NHET Pin 31 */
					nhetREG->CCDSET   	= 0x80000000;
					break;
			case 13:
					/** - Clr NHET Pin 31 */
					nhetREG->CCDCLR   	= 0x80000000;
					break;
		}
	}
}
/** @fn run_LED_StartUp(void)
*   
*   This function is called during the start up, LED's are turned on 
*   in a sequence to indicate the board is powerd up and ready to run
*   the demo software.  
*   
*/
void run_LED_StartUp(void)
{
   	int temp,delay;
	/** - Delay Parameter */
	delay				= 0x200000;

    /** - NHET is configured as Master 
     *  - NHET is turned On */    
   	nhetREG->GCR     	= 0x01000001; 
	
	/** - PULL functinality is enabled */
	nhetREG->HETPULDIS	= 0x00000000;
   	
	/** - Check for the Package Details from OTP location
	 * 	  337 Package - MDK Board 		- 0x151
	 *    144 Package - USB Stick Board - 0x090
	 * 	  LEO show software routines are selected based on the 
	 * 	  since same image is progammed for all packages */
	 
	/** - It's not 337 package */
	if(((PACKAGE_MEM & 0xFFFF0000) >> 16) != PACKAGE_337)
	{
   		/** - Configure NHET[0-5] pins as output */
   		nhetREG->CCDIR   	= 0x0000003F; 
		/** - Clear all pins by taking them to zero */
		nhetREG->CCDWR   	= 0x00000000;
		
		/** - Set only NHET[2,5] */ 
		nhetREG->CCDWR   	= 0x00000024;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		
		/** - Set only NHET[1,4] */
		nhetREG->CCDWR   	= 0x00000012;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		
		/** - Set only NHET[0,3] */
		nhetREG->CCDWR   	= 0x00000009;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);

		/** - Set only NHET[1,4] */
		nhetREG->CCDWR   	= 0x00000012;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		
		/** - Set only NHET[2,5] */
		nhetREG->CCDWR   	= 0x00000024;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);

		/** - Set only NHET[0-5] */
		nhetREG->CCDWR   	= 0x0000003F;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		
		/** - Clr all NHET[0-5] pins */
		nhetREG->CCDWR   	= 0x00000000;
	}
	else
	{
		/** Initialize GIO Module */
		gioInit();
   		
		/** - Configure NHET[31, 0-5] pins as output pins*/
   		nhetREG->CCDIR   	= 0x8000003F; 
		
		/** - Clr all NHET[0-5] pins */
		nhetREG->CCDWR   	= 0x00000000;
		/** - Set only GIOA[0] pin */ 
		gioSetPort(gioPORTA, 1);
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Set only GIOA[3] pin */
		gioSetPort(gioPORTA, 8);
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Set only GIOA[4] pin */
		gioSetPort(gioPORTA, 0x10);
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Set only GIOA[5] pin */
		gioSetPort(gioPORTA, 0x20);	
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Clear GIOA[0-5] pin */
		gioSetPort(gioPORTA, 0);	
		/** - Set only NHET[1] pin */
		nhetREG->CCDWR   	= 0x00000002;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Set only NHET[31] pin */
		nhetREG->CCDWR   	= 0x80000000;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Set only NHET[1] pin */
		nhetREG->CCDWR   	= 0x00000002;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Clear NHET[0-31] pins */
		nhetREG->CCDWR   	= 0x00000000;
		/** - Set only GIOA[5] pin */
		gioSetPort(gioPORTA, 0x20);	
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Set only GIOA[4] pin */
		gioSetPort(gioPORTA, 0x10);
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Set only GIOA[3] pin */
		gioSetPort(gioPORTA, 8);
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Set only GIOA[0] pin */
		gioSetPort(gioPORTA, 1);
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Set GIOA[0,3,4,5] pins */
		gioSetPort(gioPORTA, 0x39);
		/** - Set NHET[1,31] pin */
		nhetREG->CCDWR   	= 0x80000002;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		/** - Clear GIOA[0,3,4,5] pins */
		gioSetPort(gioPORTA, 0);
		/** - Clear all NHET pins */
		nhetREG->CCDWR   	= 0x00000000; 	
	}
}

