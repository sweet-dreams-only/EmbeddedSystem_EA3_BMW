/** @file htu.h
*   @brief HTU Driver Definition File
*   @date 11.August.2009
*   @version 1.00.000
*   
*   (c) Texas Instruments 2009, All rights reserved.
*/

#ifndef __HTU_H__
#define __HTU_H__

/** @struct htuBase
*   @brief HTU Base Register Definition
*
*   This structure is used to access the HTU module registers.
*/

typedef volatile struct htuBase
{
	unsigned int GC;
	unsigned int CPENA;
	unsigned int BUSY0;
	unsigned int BUSY1;
	unsigned int BUSY2;
	unsigned int BUSY3;
	unsigned int ACPE;
	unsigned int :32;
	unsigned int RLBECTRL;
	unsigned int BFINTENA;
	unsigned int BFINTC;
	unsigned int INTMAP;
	unsigned int :32;
	unsigned int INTOFF0;
	unsigned int INTOFF1;
	unsigned int BIM;
	unsigned int RLOSTFL;
	unsigned int BFINTFL;
	unsigned int BERINTFL;
	unsigned int MP1S;
	unsigned int MP1E;
	unsigned int DCTRL;
	unsigned int WPR;
	unsigned int WMR;
	unsigned int ID;
	unsigned int HTUPCR;
	unsigned int PAR;
	unsigned int :32;
	unsigned int MPCS;
	unsigned int MPS;
	unsigned int MPE;
} htuBASE_t;

/** @def htuREG
*   @brief HTU Register Frame Pointer
*
*   This pointer is used by the HTU driver to access the htu module registers.
*/
#define htuREG   ((htuBASE_t *)0xFFF7A400U)


/*Double control packet Configuration memory*/

typedef volatile struct dcb
{
	struct
	{		
		unsigned int	IFADDRA;	
		unsigned int	IFADDRB;
		unsigned int 	IHADDR;
		unsigned int 		         : 11;
		unsigned int     IETCOUNT 	 : 5;
		unsigned int 				 : 8;
		unsigned int     IFTCOUNT	 : 8;
	}DCBCP_ST[8];
}DCBCP_PTR_t;

/*current DCB packet*/

typedef volatile struct dcbcp
{	
 	struct 
	{	
		unsigned long    CFADDRA;
		unsigned long    CFADDRB;
		unsigned int 				: 8;
		unsigned int     CFTCTA		: 8;
		unsigned int 				: 8;
		unsigned int     CFTCTB		: 8;
	}DCBCCP_ST[8];
}DCBCCP_PTR_t;


#define htuDCBCP   ((DCBCP_PTR_t *)		0xFF4E0000U)
#define htuDCBCCP  ((DCBCCP_PTR_t *)	0xFF4E0100U)


#define htuMEM   0xFF4E0000U

/* HTU Interface Functions */

void HTU_Parity(void);
void HTU_MPU(void);

#endif
