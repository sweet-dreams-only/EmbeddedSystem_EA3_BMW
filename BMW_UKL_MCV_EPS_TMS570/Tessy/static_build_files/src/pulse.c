/** @file pulse.c 
*   @brief NHET instruction opcode file
*   @date 14.September.2009
*   @version 1.00.000
*
*   This file is create from pulse.het assembly file using 
*   NHET assembler( hetp.exe -n0 -hc32 pulse.het)
* 
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "std_het.h"  

HET_MEMORY const HET_INIT0_PST[3] = 
{ 

 	/* CN_0 */ 
	{
		0x00002C20, 
		0x00000032, 
		0x00000000, 
		0x00000000
	}, 

 	/* EA_0 */ 
	{
		0x00004000, 
		0x00404608, 
		0x00001413, 
		0x00000000
	}, 

 	/* EB_0 */ 
	{
		0x00000E07, 
		0x0C000000, 
		0x00000000, 
		0x00000000
	} 
}; 
