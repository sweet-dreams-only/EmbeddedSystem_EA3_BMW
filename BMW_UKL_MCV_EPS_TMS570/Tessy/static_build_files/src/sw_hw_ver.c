/** @file sw_hw_ver.c 
*   @brief Software and Hardware Information Source File
*   @date 10.August.2009
*   @version 1.00.000
*
*   This file contains:
*   - Funcions that are used to find the Software and the Harware information
*/
/* Include Files */
#include "sys_common.h"
#include "system.h"
#include "sci.h"

#define LOT_NUM 		(*(volatile unsigned int *) 0x06040B4)
#define WAFER_NUM 		(*(volatile unsigned int *) 0x06040B8)
#define DIE_LOC 		(*(volatile unsigned int *) 0x06040BC)
#define PACKAGE_MEM	 	(*(volatile unsigned int *) 0x06040AC)

/** @fn get_software_Version(void)
*   @brief Get the Software Version of the Demo
*/
void get_software_Version(void)
{
	sciSend(sciREG1,16, (unsigned char *)"VER 1.1 ");
}

/** @fn get_hardware_Info(void)
*   @brief Get the Hardware Information of the Micro
*		- Device ID
*  		- LOT Number
*  		- WAFFER Number + DIE Locations ( X & Y)
* 		- Package Type + Flash Memory 
*	@note: The above Hardware informations are stored in the OTP locations	
*/
void get_hardware_Info(void)
{
	sciSend_32bitdata(sciREG1, SYSTEM_1->DEV);
	sciSend_32bitdata(sciREG1, LOT_NUM);
	sciSend_32bitdata(sciREG1,((WAFER_NUM << 24) | (DIE_LOC & 0x00FFFFFF)));// WAFER_No(8 bits) + X(8 Bits) + Y(16 Bits).
	sciSend_32bitdata(sciREG1, PACKAGE_MEM);// PACAGE(16 bits) + MEMORY(16 bits).
}
