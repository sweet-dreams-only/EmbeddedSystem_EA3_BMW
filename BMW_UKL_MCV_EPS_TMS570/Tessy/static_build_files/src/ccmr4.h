/** @file ccmr4.h
*   @brief CCMR4 Driver Definition File
*   @date 11.August.2009
*   @version 1.00.000
*   
*   (c) Texas Instruments 2009, All rights reserved.
*/

#ifndef __CCMR4_H__
#define __CCMR4_H__

/** @struct ccmr4Base
*   @brief CCMR4 Base Register Definition
*
*   This structure is used to access the CCMR4 module registers.
*/
typedef volatile struct ccmr4Base
{
	    
    union										
	{
		unsigned int CCMSR_UL; 
		struct
		{
			unsigned int  :15;
			unsigned int CPME :1;
			unsigned int  :7;
			unsigned int STC :1;
			unsigned int :6;
			unsigned int STET :1;
			unsigned int STE :1;
		
		}CCMSR_ST;

	}CCMSR_UN;    
    
    union										
	{
		unsigned int CCMKEYR_UL; 
		struct
		{
			unsigned int  :28;			
			unsigned int MKEY :4;
		
		}CCMKEYR_ST;

	}CCMKEYR_UN;
         	
}ccmr4Base_t;

void CCM_R4_Compare(void);

/** @def ccmr4REG
*   @brief CCMR4 Register Frame Pointer
*
*   This pointer is used by the CCMR4 driver to access the esm module registers.
*/

#define CCMR4REG    ((ccmr4Base_t *)		0xFFFFF600U)

#endif
