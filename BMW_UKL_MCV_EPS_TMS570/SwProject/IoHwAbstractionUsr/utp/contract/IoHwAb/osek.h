 
/* From tcb.h */
#define OS_MEM_AREA_ESMEKR 24
  
/* From osektype.h */
typedef unsigned char  osuint8;
typedef unsigned short osuint16;
typedef unsigned long  osuint32;
typedef signed   char  osint8;
typedef signed   short osint16;
typedef signed   long  osint32;
 
 
 
/* From osek.h */
void osWritePeripheral32(osuint16 area, osuint32 address, osuint32 value); /* TR:SPMF95:0006 */
 