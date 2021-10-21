#ifndef _OSEK_H 
#define _OSEK_H

#include "Std_Types.h"

	/* This file is created by Nxtr to provide the stub definitions for the Os API's used
	 * in this SWC.  When the Exclusive area protection mechanisms are well enough understood then
	 * it might be possible to remove the direct invocation of the Os API's from the SWC design.
	 */

	/* Arbitrarily selected data types for the API's */
	 typedef uint8 StatusType;
	 typedef uint16 ResourceType;
	 
	 
	/* Value of OsRes_SPIDriver is an arbitrarily chosen non-zero number */
	#define OsRes_SPIDriver	1U
	
	/* return and passed parameter types are arbitrarily chosen as standard Autosar types for purposes of */
	extern StatusType GetResource(ResourceType ResId);
	extern StatusType ReleaseResource(ResourceType ResId);

#endif


