/** @file dma.h
*   @brief DMA Driver Definition File
*   @date 11.August.2009
*   @version 1.00.000
*   
*   (c) Texas Instruments 2009, All rights reserved.
*/

#ifndef __DMA_H__
#define __DMA_H__

#define FALSE             0
#define TRUE 			  !FALSE

#define NO_ADDR             0
#define DMA_CP_RAM          0xfff80000 

#define ADDR_FIXED          0
#define ADDR_INC1           1
#define ADDR_RESERVED       2
#define ADDR_OFFSET         3

#define ACCESS_8_BIT        0
#define ACCESS_16_BIT       1
#define ACCESS_32_BIT		2
#define ACCESS_64_BIT       3

#define AUTOINIT_ON         1
#define AUTOINIT_OFF        0

#define BLOCK_TRANSFER		1
#define FRAME_TRANSFER      0

#define PORTB               4
#define PORTA2              3
#define PORTA1              2
#define RA2_WA1             1
#define RA1_WA2             0


/** @struct dmaBase
*   @brief DMA Base Register Definition
*
*   This structure is used to access the DMA module registers.
*/
typedef volatile struct dmaBase
{
    union                                       /* 0x00      */
    {
     unsigned int GCTRL_UL; 

     struct
     {
      unsigned int : 15;
      unsigned int DMA_EN :1;
      unsigned int : 1;
      unsigned int BUS_BUSY:1;
      unsigned int : 4;                         
      unsigned int DEBUG_MODE :2;
      unsigned int : 7;                          
      unsigned int DMA_RESET :1;
     }GCTRL_ST;

    }GCTRL_UN;

    unsigned int PEND_UL;                       /* 0x04      */ 
    
   union				/* 0x08      */
   {
     unsigned int FBREG_UL;  

   struct                                              
   {
    unsigned int : 20;
    unsigned int FSM_FB : 4;
    unsigned int : 4;
    unsigned int VBUSP_FB: 4;
   }FBREG_ST;

   }FBREG_UN;

    unsigned int DMASTAT_UL;                    /* 0x0C      */ 

    unsigned int : 32;                          /* 0x10      */

    unsigned int HWCHENAS_UL;                   /* 0x14      */ 

    unsigned int : 32;                          /* 0x18      */

    unsigned int HWCHENAR_UL;                   /* 0x1C      */ 

    unsigned int : 32;                          /* 0x20      */

    unsigned int SWCHENAS_UL;                   /* 0x24      */ 

    unsigned int : 32;                          /* 0x28      */

    unsigned int SWCHENAR_UL;                   /* 0x2C      */ 

    unsigned int : 32;                          /* 0x30      */

    unsigned int CHPRIOS_UL;                    /* 0x34      */ 

    unsigned int : 32;                          /* 0x38      */

    unsigned int CHPRIOR_UL;                    /* 0x3C      */ 

    unsigned int : 32;                          /* 0x40      */

    unsigned int GCHIENAS_UL;                   /* 0x44      */ 

    unsigned int : 32;                          /* 0x48      */

    unsigned int GCHIENAR_UL;                   /* 0x4C      */ 

    unsigned int : 32;                          /* 0x50      */

 //   union                                       /* 0x54-0x70  */
//    {
      unsigned int DREQASI_UL[8]; 
/*
      struct
      {
         unsigned int : 2;
         unsigned int CHNASI :6;
      }DREQASI_ST[32];

    }DREQASI_UN;
*/
	  	  
    unsigned int test2;                          /* 0x74      */

    unsigned int : 32;                          /* 0x78      */

    unsigned int : 32;                          /* 0x7C      */

    unsigned int : 32;                          /* 0x80      */

    unsigned int : 32;                          /* 0x84      */

    unsigned int : 32;                          /* 0x88      */

    unsigned int : 32;                          /* 0x8C      */
  
    unsigned int : 32;                          /* 0x90      */

//	union                                       /* 0x94-0xA0 */
//    {
     unsigned int PAR_UL[4]; 
/*
     struct                                      
     {
	  unsigned int : 1;
      unsigned int CHNPAE :3;
      unsigned int : 1;
      unsigned int CHNPAO :3;
      }PAR_ST[16];
    }PAR_UN;

*/
    unsigned int : 32;                          /* 0xA4      */

    unsigned int : 32;                          /* 0xA8      */

    unsigned int : 32;                          /* 0xAC      */

    unsigned int : 32;                          /* 0xB0      */

    unsigned int FTCMAP_UL;                     /* 0xB4      */ 

    unsigned int : 32;                          /* 0xB8      */

    unsigned int LFSMAP_UL;                     /* 0xBC      */ 

    unsigned int : 32;                          /* 0xC0      */

    unsigned int HBCMAP_UL;                     /* 0xC4      */ 

    unsigned int : 32;                          /* 0xC8      */

    unsigned int BTCMAP_UL;                     /* 0xCC      */ 

    unsigned int : 32;                          /* 0xD0      */

    unsigned int BERMAP_UL;                     /* 0xD4      */ 

    unsigned int : 32;                          /* 0xD8      */

    unsigned int FTCINTENAS_UL;                 /* 0xDC      */ 

    unsigned int : 32;                          /* 0xE0      */

    unsigned int FTCINTENAR_UL;                 /* 0xE4      */ 

    unsigned int : 32;                          /* 0xE8      */

    unsigned int LFSINTENAS_UL;                 /* 0xEC      */ 

    unsigned int : 32;                          /* 0xF0      */

    unsigned int LFSINTENAR_UL;                 /* 0xF4      */ 

    unsigned int : 32;                          /* 0xF8      */

    unsigned int HBCINTENAS_UL;                 /* 0xFC      */ 

    unsigned int : 32;                          /* 0x100     */

    unsigned int HBCINTENAR_UL;                 /* 0x104     */ 

    unsigned int : 32;                          /* 0x108     */

    unsigned int BTCINTENAS_UL;                 /* 0x10C     */ 

    unsigned int : 32;                          /* 0x110     */

    unsigned int BTCINTENAR_UL;                 /* 0x114     */ 

    unsigned int : 32;                          /* 0x118     */

    unsigned int GINTFLAG_UL;                   /* 0x11C     */ 

    unsigned int : 32;                          /* 0x120     */

    unsigned int FTCFLAG_UL;                    /* 0x124     */ 

    unsigned int : 32;                          /* 0x128     */

    unsigned int LFSFLAG_UL;                    /* 0x12C     */ 

    unsigned int : 32;                          /* 0x130     */

    unsigned int HBCFLAG_UL;                    /* 0x134     */ 

    unsigned int : 32;                          /* 0x138     */

    unsigned int BTCFLAG_UL;                    /* 0x13C     */ 

    unsigned int : 32;                          /* 0x140     */

    unsigned int BERFLAG_UL;                    /* 0x144     */ 

    unsigned int : 32;                          /* 0x148     */

    union                                       /* 0x14C      */
    {
     unsigned int FTCAOFFSET_UL; 

     struct
     {
      unsigned int : 24;
      unsigned int SBZ1 :1;
      unsigned int SBZ2: 1;                          
      unsigned int FTCA :6;
     }FTCAOFFSET_ST;

    }FTCAOFFSET_UN;

    union                                       /* 0x150      */
    {
     unsigned int LFSAOFFSET_UL; 

     struct
     {
      unsigned int : 24;
      unsigned int SBZ1 :1;
      unsigned int SBZ2: 1;                          
      unsigned int LFSA :6;
     }LFSAOFFSET_ST;

    }LFSAOFFSET_UN;

    union                                       /* 0x154      */
    {
     unsigned int HBCAOFFSET_UL; 

     struct
     {
      unsigned int : 24;
      unsigned int SBZ1 :1;
      unsigned int SBZ2: 1;                          
      unsigned int HBCA :6;
     }HBCAOFFSET_ST;

    }HBCAOFFSET_UN;

    union                                       /* 0x158      */
    {
     unsigned int BTCAOFFSET_UL; 

     struct
     {
      unsigned int : 24;
      unsigned int SBZ1 :1;
      unsigned int SBZ2: 1;                          
      unsigned int BTCA :6;
     }BTCAOFFSET_ST;

    }BTCAOFFSET_UN;

    union                                       /* 0x15C      */
    {
     unsigned int BERAOFFSET_UL; 

     struct
     {
      unsigned int : 24;
      unsigned int SBZ1 :1;
      unsigned int SBZ2: 1;                          
      unsigned int BERA :6;
     }BERAOFFSET_ST;

    }BERAOFFSET_UN;

    union                                       /* 0x160      */
    {
     unsigned int FTCBOFFSET_UL; 

     struct
     {
      unsigned int : 24;
      unsigned int SBZ1 :1;
      unsigned int SBZ2: 1;                          
      unsigned int FTCB :6;
     }FTCBOFFSET_ST;

    }FTCBOFFSET_UN;

    union                                       /* 0x164      */
    {
     unsigned int LFSBOFFSET_UL; 

     struct
     {
      unsigned int : 24;
      unsigned int SBZ1 :1;
      unsigned int SBZ2: 1;                          
      unsigned int LFSB :6;
     }LFSBOFFSET_ST;

    }LFSBOFFSET_UN;

    union                                       /* 0x168      */
    {
     unsigned int HBCBOFFSET_UL; 

     struct
     {
      unsigned int : 24;
      unsigned int SBZ1 :1;
      unsigned int SBZ2: 1;                          
      unsigned int HBCB :6;
     }HBCBOFFSET_ST;

    }HBCBOFFSET_UN;

    union                                       /* 0x16C      */
    {
     unsigned int BTCBOFFSET_UL; 

     struct
     {
      unsigned int : 24;
      unsigned int SBZ1 :1;
      unsigned int SBZ2: 1;                          
      unsigned int BTCB :6;
     }BTCBOFFSET_ST;

    }BTCBOFFSET_UN;

    union                                       /* 0x170      */
    {
     unsigned int BERBOFFSET_UL; 

     struct
     {
      unsigned int : 24;
      unsigned int SBZ1 :1;
      unsigned int SBZ2: 1;                          
      unsigned int BERB :6;
     }BERBOFFSET_ST;

    }BERBOFFSET_UN;

    unsigned int : 32;                          /* 0x174     */

    union                                       /* 0x178      */
    {
     unsigned int PTCRL_UL; 

     struct
     {
      unsigned int : 7; 
      unsigned int PENDB :1;
      unsigned int : 5;
      unsigned int BYB :1;                          
      unsigned int PSFRHQPB :1;
      unsigned int PSFRLQPB :1;
      unsigned int : 7; 
      unsigned int PENDA :1;
      unsigned int : 5;        
      unsigned int BYA :1;                          
      unsigned int PSFRHQPA :1;
      unsigned int PSFRLQPA :1;
     }PTCRL_ST;

    }PTCRL_UN;

    union                                       /* 0x17C      */
    {
     unsigned int RTCTRL_UL; 

     struct
     {
      unsigned int : 31;
      unsigned int RTC :1;                          
     }RTCTRL_ST;

    }RTCTRL_UN;

    union                                       /* 0x180      */
    {
     unsigned int DCTRL_UL; 

     struct
     {
      unsigned int : 3;
      unsigned int CHNUM :5;                          
      unsigned int : 7;        
      unsigned int DMADBGS :1;  
      unsigned int : 15;                              
      unsigned int DBGEN :1;
     }DCTRL_ST;

    }DCTRL_UN;

    unsigned int WPR_UL;                        /* 0x184      */ 

    unsigned int WMR_UL;                        /* 0x188      */ 

    unsigned int PAACSADDR_UL;                  /* 0x18C      */ 

    unsigned int PAACDADDR_UL;                  /* 0x190      */ 

    union                                       /* 0x194      */
    {
     unsigned int PAACTC_UL; 

     struct
     {
      unsigned int : 3;
      unsigned int PAFTCOUNT :13;                          
      unsigned int : 3;        
      unsigned int PAETCOUNT :13;  
     }PAACTC_ST;

    }PAACTC_UN;

    unsigned int PBACSADDR_UL;                  /* 0x198      */ 

    unsigned int PBACDADDR_UL;                  /* 0x19C      */ 

    union                                       /* 0x1A0      */
    {
     unsigned int PBACTC_UL; 

     struct
     {
      unsigned int : 3;
      unsigned int PBFTCOUNT :13;                          
      unsigned int : 3;        
      unsigned int PBETCOUNT :13;  
     }PBACTC_ST;
     
	}PBACTC_UN;
	
	unsigned int : 32;                          /* 0x1A4   for Reserverd  */
	
/* The following headers are added to make DMA.h file to be complaint to the NEW Features!!.
	by Chakradhar.A
*/
	union                                       /* 0x1A8   Parity Control Register   */
    {
     unsigned int DMAPCR_UL; 

     struct
     {
      unsigned int : 15;
      unsigned int ERRA :1;                          
      unsigned int : 7;        
      unsigned int TEST :1;  
      unsigned int :4;
      unsigned int PARITY_ENA:4;  
     }DMAPCR_ST;
    }DMAPCR_UN;

	union                                       /* 0x1AC   Parity Error Addresss Register   */
    {
     unsigned int DMAPAR_UL; 

     struct
     {
      unsigned int : 7;
      unsigned int EDFLG :1;
      unsigned int : 12;
      unsigned int ERR_Addr :12;                          
      
     }DMAPAR_ST;
    }DMAPAR_UN;

	
	union                                       /* 0x1B0   Memory protection Control Register   */
    {
     unsigned int DMAMPCTRL_UL; 

     struct
     {
      unsigned int : 3;
      unsigned int INT3AB: 1;
      unsigned int INT3ENA: 1;
      unsigned int REG3AP: 2;
      unsigned int REG3ENA: 1;
      unsigned int : 3;
      unsigned int INT2AB: 1;
      unsigned int INT2ENA: 1;
      unsigned int REG2AP: 2;
      unsigned int REG2ENA: 1;
      unsigned int : 3;
      unsigned int INT1AB: 1;
      unsigned int INT1ENA: 1;
      unsigned int REG1AP: 2;
      unsigned int REG1ENA: 1;
      unsigned int : 3;
      unsigned int INT0AB: 1;
      unsigned int INT0ENA: 1;
      unsigned int REG0AP: 2;
      unsigned int REG0ENA: 1;      
     }DMAMPCTRL_ST;
    }DMAMPCTRL_UN;

	union                                       /* 0x1B4   Memory Protection Status  Register   */
    {
     unsigned int DMAMPST_UL; 

     struct
     {
      unsigned int : 7;
      unsigned int REG3FT:1;                          
      unsigned int : 7;
      unsigned int REG2FT:1;                          
      unsigned int : 7;
      unsigned int REG1FT:1;                          
      unsigned int : 7;
      unsigned int REG0FT:1;                                
     }DMAMPST_ST;
    }DMAMPST_UN;

	unsigned int DMAMPR0S_UL;                  /* 0x1B8 Memory Protection Region 0 StartAddress     */ 	
	unsigned int DMAMPR0E_UL;                  /* 0x1BC Memory Protection Region 0 EndAddress     */ 	
	
	unsigned int DMAMPR1S_UL;                  /* 0x1C0 Memory Protection Region 1 StartAddress     */ 	
	unsigned int DMAMPR1E_UL;                  /* 0x1C4 Memory Protection Region 1 EndAddress     */ 	
	
	unsigned int DMAMPR2S_UL;                  /* 0x1C8 Memory Protection Region 2 StartAddress     */ 	
	unsigned int DMAMPR2E_UL;                  /* 0x1CC Memory Protection Region 2 EndAddress     */ 	
	
	unsigned int DMAMPR3S_UL;                  /* 0x1D0 Memory Protection Region 3 StartAddress     */ 	
	unsigned int DMAMPR3E_UL;                  /* 0x1D4 Memory Protection Region 3 EndAddress     */ 	
	
	
	
} dmaBASE_t;

typedef volatile struct dmaMemBase
{
     
     struct                                     /* 0x000-0x400 */
     {
      unsigned int ISADDR_UL;

      unsigned int IDADDR_UL;
      
      union                                       
      {
       unsigned int ITCOUNT_UL; 

       struct
       { 
        unsigned int : 3;
        unsigned int IFTCOUNT :13;
        unsigned int : 3;
        unsigned int IETCOUNT :13;
       }ITCOUNT_ST;

      }ITCOUNT_UN;

      unsigned int : 32;         
               
      union
      {
 
       unsigned int CHCTRL_UL;

       struct
       { 
        unsigned int : 10;
        unsigned int  CHAIN :6;					/* this is added from the above 16 into 10+6 as we need channel chaining*/
        unsigned int RES :2;
        unsigned int WES :2;
        unsigned int : 3;
        unsigned int TTYPE :1;
        unsigned int : 3;
        unsigned int ADDMR :2;
        unsigned int ADDMW :2;
        unsigned int AIM :1;
       }CHCTRL_ST;
      
      }CHCTRL_UN;

      union
      {
 
       unsigned int EIOFF_UL;

       struct
       { 
        unsigned int : 3;
        unsigned int EIDXD :13;
        unsigned int : 3;
        unsigned int EIDXS :13;
       }EIOFF_ST;
 
      }EIOFF_UN;

      union
      {

       unsigned int FIOFF_UL;

       struct
       { 
        unsigned int : 3;
        unsigned int FIDXD :13;
        unsigned int : 3;
        unsigned int FIDXS :13;
       }FIOFF_ST;
  
      }FIOFF_UN;

       unsigned int : 32;  

     }PCP_ST[32];

     struct                                     /* 0x400-0x800   */
     {
       unsigned int RESERVED_UL[256];
     } RESERVED_ST;

     struct                                     /* 0x800-0xA00 */
     {
      unsigned int CSADDR_UL;

      unsigned int CDADDR_UL;

      struct
      { 
       unsigned int : 3;
       unsigned int CFTCOUNT :13;
       unsigned int : 3;
       unsigned int CETCOUNT :13;
      }CTCOUNT_ST;

	  unsigned int : 32; 

     }WCP_ST[32];


} dmaMemBase_t;


void DMA_MPU(void);
void DMA_Parity(void);

/** @def ftuREG
*   @brief DMA Register Frame Pointer
*
*   This pointer is used by the DMA driver to access the esm module registers.
*/

#define dmaREG    ((dmaBASE_t *)		0xFFFFF000U)
#define dmaMEM    ((dmaMemBase_t *)		0xFFF80000U)

#endif
