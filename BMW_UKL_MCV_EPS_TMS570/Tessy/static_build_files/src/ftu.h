/** @file ftu.h
*   @brief FTU Driver Definition File
*   @date 11.August.2009
*   @version 1.00.000
*   
*   (c) Texas Instruments 2009, All rights reserved.
*/

#ifndef __FTU_H__
#define __FTU_H__

/** @struct ftuBase
*   @brief FTU Base Register Definition
*
*   This structure is used to access the FTU module registers.
*/

typedef volatile struct ftuBase
{
	unsigned long  GSN0_UL;								/* 0x0 */
	
	unsigned long  GSN1_UL;								/* 0x4 */
	
	unsigned int		:32;							/* 0x8 */
	unsigned int		:32;							/* 0xC */

	union
	{
		unsigned long GCS_UL;							/* 0x10 */
		struct
		{
		   unsigned int	ENDVBM_B1 :1;
		   unsigned int	ENDVBS_B1 :1;
		   unsigned int	ENDRx_B2  :2;
		   unsigned int	ENDHx_B2  :2;
		   unsigned int	ENDPx_B2  :2;
		   unsigned int		      :2;
		   unsigned int	PROI_B1   :1;
		   unsigned int	PFT_B1    :1;
		   unsigned int	PALx_B4   :4;
		   unsigned int		      :1;
		   unsigned int	CETESM_B1 :1;
		   unsigned int	CTTCC_B1  :1;
		   unsigned int	CTTSM_B1  :1;
		   unsigned int		      :3 ;
		   unsigned int	ETSM_B1   :1;
		   unsigned int		      :2;
		   unsigned int	SILE_B1   :1;
		   unsigned int	EILE_B1   :1;
		   unsigned int		      :2;
		   unsigned int	TUH_B1    :1;
		   unsigned int	TUE_B1    :1;
		} GCS_ST;
	} GCS_UN;
           
	union
	{
		unsigned long GCR_UL;							/* 0x14 */
		struct
		{
		   unsigned int	ENDVBM_B1 :1;
		   unsigned int	ENDVBS_B1 :1;
		   unsigned int	ENDRx_B2  :2;
		   unsigned int	ENDHx_B2  :2;
		   unsigned int	ENDPx_B2  :2;
		   unsigned int		      :2;
		   unsigned int	PROI_B1   :1;
		   unsigned int	PFT_B1    :1;
		   unsigned int	PALx_B4   :4;
		   unsigned int		      :1;
		   unsigned int	CETESM_B1 :1;
		   unsigned int	CTTCC_B1  :1;
		   unsigned int	CTTSM_B1  :1;
		   unsigned int	          :3;
		   unsigned int	ETSM_B1   :1;
		   unsigned int		      :2;
		   unsigned int	SILE_B1   :1;
		   unsigned int	EILE_B1   :1;
		   unsigned int		      :2;
		   unsigned int	TUH_B1    :1;
		   unsigned int	TUE_B1    :1;
		} GCR_ST;
	} GCR_UN;
           
	union
	{
		unsigned long TSCB_UL;							/* 0x18 */
		struct
		{
		   unsigned int		  		  :11;
		   unsigned int	TSMS_B5 	  :5;
		   unsigned int		  		  :3;
		   unsigned int	STUH_B1 	  :1;
		   unsigned int		  		  :3;
		   unsigned int	IDLE_B1 	  :1;
		   unsigned int		  		  :1;
           unsigned int	BN_B7	 	  :7;
		} TSCB_ST ;
	} TSCB_UN;
           
	unsigned long LTBCC_UL;							/* 0x1C */
	           
	unsigned long LTBSM_UL;							/* 0x20 */
           
	unsigned long TBA_UL;							/* 0x24 */
           
	unsigned long NTBA_UL;							/* 0x28 */
           
	unsigned long BAMS_UL;							/* 0x2C */
           
	unsigned long SAMP_UL;							/* 0x30 */
        
	unsigned long EAMP_UL;							/* 0x34 */

	unsigned int		:32;						/* 0x38 */
	unsigned int		:32;						/* 0x3C */

	unsigned long TSMO1_UL;							/* 0x40 */
    unsigned long TSMO2_UL;							/* 0x44 */
    unsigned long TSMO3_UL;							/* 0x48 */
    unsigned long TSMO4_UL;							/* 0x4C */

	unsigned long TCCO1_UL;							/* 0x50 */
    unsigned long TCCO2_UL;							/* 0x54 */
    unsigned long TCCO3_UL;							/* 0x58 */
    unsigned long TCCO4_UL;							/* 0x5C */

        union
	{
		unsigned long TOFF_UL;						/* 0x60 */
		struct
		{
           unsigned int          : 23;
		   unsigned int TDIR_B1  : 1;
		   unsigned int OFF_B8   : 8;
		}TOFF_ST ;
	} TOFF_UN;
        
	
	unsigned int		:32;						/* 0x64 */
	unsigned int		:32;						/* 0x68 */
	unsigned int		:32;						/* 0x6c */

	unsigned long PEADR_UL;							/* 0x70 */

	union
	{
		unsigned long TEIR_UL;						/* 0x74 */
		struct
		{
           unsigned int          : 14;
		   unsigned int MPV_B1   : 1;
		   unsigned int PE_B1    : 1;
	       unsigned int          : 5;
	       unsigned int RSTAT_B3 : 3;
	       unsigned int          : 1;
	       unsigned int SSTAT_B3 : 3;
		   unsigned int          : 2;
		   unsigned int TNR_B1   : 1;
		   unsigned int FAC_B1   : 1;
		}TEIR_ST ;
	} TEIR_UN;   
        
        union
	{
		unsigned long TEIRES_UL;					/* 0x78 */
		struct
		{
	         unsigned int          : 21;
	         unsigned int RSTAT_B3 : 3;
	         unsigned int          : 1;
	         unsigned int SSTAT_B3 : 3;
		     unsigned int          : 2;
		     unsigned int TNR_B1   : 1;
		     unsigned int FAC_B1   : 1;
		}TEIRES_ST ;
	} TEIRES_UN;  

        union
	{
		unsigned long TEIRER_UL;					/* 0x7c */
		struct
		{
	         unsigned int          : 21;
	         unsigned int RSTAT_B3 : 3;
	         unsigned int          : 1;
	         unsigned int SSTAT_B3 : 3;
		     unsigned int          : 2;
		     unsigned int TNR_B1   : 1;
		     unsigned int FAC_B1   : 1;
		}TEIRER_ST ;
	} TEIRER_UN;     
	
	unsigned long 	TTSMS1_UL; 						/* 0x80 */    
	unsigned long 	TTSMR1_UL; 						/* 0x84 */         
	unsigned long 	TTSMS2_UL; 						/* 0x88 */    
	unsigned long 	TTSMR2_UL; 						/* 0x8c */         
	unsigned long 	TTSMS3_UL; 						/* 0x90 */         
	unsigned long 	TTSMR3_UL; 						/* 0x94 */         
	unsigned long 	TTSMS4_UL; 						/* 0x98 */         
	unsigned long 	TTSMR4_UL; 						/* 0x9c */         

	unsigned long 	TTCCS1_UL; 						/* 0xA0 */         
	unsigned long 	TTCCR1_UL; 						/* 0xA4 */         
	unsigned long 	TTCCS2_UL; 						/* 0xA8 */         
	unsigned long 	TTCCR2_UL; 						/* 0xAC */         
	unsigned long 	TTCCS3_UL; 						/* 0xB0 */         
	unsigned long 	TTCCR3_UL; 						/* 0xB4 */         
	unsigned long 	TTCCS4_UL; 						/* 0xB8 */         
	unsigned long 	TTCCR4_UL; 						/* 0xBC */         

	unsigned long 	ETESMS1_UL;						/* 0xC0 */         
	unsigned long 	ETESMR1_UL;						/* 0xC4 */              
	unsigned long 	ETESMS2_UL;						/* 0xC8 */              
	unsigned long 	ETESMR2_UL;						/* 0xCC */              
	unsigned long 	ETESMS3_UL;						/* 0xD0 */              
	unsigned long 	ETESMR3_UL;						/* 0xD4 */              
	unsigned long 	ETESMS4_UL;						/* 0xD8 */              
	unsigned long 	ETESMR4_UL;						/* 0xDC */              

	unsigned long 	CESMS1_UL;						/* 0xE0 */      
	unsigned long 	CESMR1_UL;						/* 0xE4 */       
	unsigned long 	CESMS2_UL;						/* 0xE8 */       
	unsigned long 	CESMR2_UL;						/* 0xEC */       
	unsigned long 	CESMS3_UL;						/* 0xF0 */       
	unsigned long 	CESMR3_UL;						/* 0xF4 */       
	unsigned long 	CESMS4_UL;						/* 0xF8 */       
	unsigned long 	CESMR4_UL;						/* 0xFC */       

	unsigned long 	TSMIES1_UL;						/* 0x100 */      
	unsigned long 	TSMIER1_UL;						/* 0x104 */      
	unsigned long 	TSMIES2_UL;						/* 0x108 */      
	unsigned long 	TSMIER2_UL;						/* 0x10C */      
	unsigned long 	TSMIES3_UL;						/* 0x110 */      
	unsigned long 	TSMIER3_UL;						/* 0x114 */      
	unsigned long 	TSMIES4_UL;						/* 0x118 */      
	unsigned long 	TSMIER4_UL;						/* 0x11C */  

	unsigned long 	TCCIES1_UL;						/* 0x120 */      
	unsigned long 	TCCIER1_UL;						/* 0x124 */      
	unsigned long 	TCCIES2_UL;						/* 0x128 */      
	unsigned long 	TCCIER2_UL;						/* 0x12C */      
	unsigned long 	TCCIES3_UL;						/* 0x130 */      
	unsigned long 	TCCIER3_UL;						/* 0x134 */      
	unsigned long 	TCCIES4_UL;						/* 0x138 */      
	unsigned long 	TCCIER4_UL;						/* 0x13C */  
}  ftuBASE_t;


/*Transfer Unit RAM*/
typedef volatile struct ftuMemBase
{
 struct
{
	union
	{
		unsigned long TCR_UL;						/* 0x0 - 0x1FC */  
		struct
		{
	         unsigned int          : 13;
	         unsigned int STXR_B1  : 1;
	         unsigned int THTSM_B1 : 1;
	         unsigned int TPTSM_B1 : 1;
		     unsigned int THTCC_B1 : 1;
		     unsigned int TPTCC_B1 : 1;
		     unsigned int TSO_B14  : 14;
		}TCR_ST ;
	} TCR_UN;
	
} FTUTCR_ST[128];
} ftuMemBase_t;

/*Transfer Unit Parity RAM*/
typedef volatile struct ftuMemParBase
{
 struct
 { 
  	union
	{
		unsigned long TCRPT_UL;						/* 0x200 - 0x3fC */  
		struct
		{
	           unsigned int          : 15;
	           unsigned int PAB2_B1  : 1;
	           unsigned int 	     : 7;
	           unsigned int PAB1_B1  : 1;
		       unsigned int 	     : 7;
		       unsigned int PAB0_B1  : 1;
		}TCRPT_ST ;
	} TCRPT_UN;
	
  } FTUTCRPT_ST[128];

}ftuMemParBase_t;

/** @def ftuREG
*   @brief FTU Register Frame Pointer
*
*   This pointer is used by the FTU driver to access the esm module registers.
*/

#define ftuREG    ((ftuBASE_t *)		0xFFF7A000U)
#define ftuMEM    ((ftuMemBase_t *)		0xFF500000U)
#define ftuParMEM ((ftuMemParBase_t *)	0xFF500200U)

void FTU_Parity(void);
void FTU_MPU(void);

#endif
