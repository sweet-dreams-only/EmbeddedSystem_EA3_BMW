#ifndef __pulse_h
#define __pulse_h

#define HET_CN_0	(e_HETPROGRAM0_UN.Program0_ST.CN_0)
#define pHET_CN_0  	0

#define HET_EA_0	(e_HETPROGRAM0_UN.Program0_ST.EA_0)
#define pHET_EA_0  	1

#define HET_EB_0	(e_HETPROGRAM0_UN.Program0_ST.EB_0)
#define pHET_EB_0  	2



typedef union 
{ 
 	HET_MEMORY	Memory0_PST[3];
	struct
	{
		CNT_INSTRUCTION CN_0;
		ECMP_INSTRUCTION EA_0;
		PCNT_INSTRUCTION EB_0;
	} Program0_ST; 

} HETPROGRAM0_UN;

extern volatile HETPROGRAM0_UN e_HETPROGRAM0_UN;

extern const HET_MEMORY HET_INIT0_PST[3];

#endif

