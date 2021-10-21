/* The following is only part of the header that was required at the 
 * time this component was made. 
 */
 
#ifndef XCPPROF_H
#define XCPPROF_H

#include "xcp_cfg.h" /* KS- Added to allow QAC to complete analysis */
 

typedef vuint8 tXcpOdtIdx;
typedef vuint8 tXcpOdtCnt;
typedef unsigned long  vuint32;
#define BYTEPTR vuint8 *
#define RAM
#  define V_MEMRAM2_FAR 
# define MEMORY_FAR    V_MEMRAM2_FAR
#define XCP_MEMORY_FAR MEMORY_FAR
#define DAQBYTEPTR vuint8 XCP_MEMORY_FAR *
#define kXcpMaxDTO                           8
#define kXcpMaxCTO                           8
#define MTABYTEPTR vuint8 XCP_MEMORY_FAR *

#define XCP_MAX_ODT_ENTRY_SIZE (kXcpMaxDTO-1)
 
 #define CRC_MEMORY_OVERFLOW     0x30
 #define CRM_SET_DAQ_PTR_LEN                             1
 
#define SS_DAQ                 0x40u

#define DaqListOdtCount(i)      ((xcp.Daq.u.DaqList[i].lastOdt-xcp.Daq.u.DaqList[i].firstOdt)+1)
#define DaqListLastOdt(i)       xcp.Daq.u.DaqList[i].lastOdt
#define DaqListFirstOdt(i)      xcp.Daq.u.DaqList[i].firstOdt
#define DaqListFirstPid(i)      xcp.Daq.u.DaqList[i].firstOdt
#define DaqListFlags(i)         xcp.Daq.u.DaqList[i].flags
#define DaqListEventChannel(i)  xcp.Daq.u.DaqList[i].eventChannel
#define DaqListPrescaler(i)     xcp.Daq.u.DaqList[i].prescaler 
#define DaqListCycle(i)         xcp.Daq.u.DaqList[i].cycle
  
#define DaqListOdtEntryCount(j) ((xcp.pOdt[j].lastOdtEntry-xcp.pOdt[j].firstOdtEntry)+1)
#define DaqListOdtLastEntry(j)  (xcp.pOdt[j].lastOdtEntry)
#define DaqListOdtFirstEntry(j) (xcp.pOdt[j].firstOdtEntry)
#define DaqListOdtStimBuffer(j) (xcp.pOdt[j].pStimBuffer)
  
#define OdtEntrySize(n)         (xcp.pOdtEntrySize[n])
#define OdtEntryAddr(n)         (xcp.pOdtEntryAddr[n])
  
extern MTABYTEPTR ApplXcpGetPointer( vuint8 addr_ext, vuint32 addr );
#  define V_MEMROM2        const
# define MEMORY_ROM        V_MEMROM2 
extern vuint8 ApplXcpUserService( MEMORY_ROM BYTEPTR pCmd );

#define XCP_CMD_DENIED              0
#define XCP_CMD_OK                  1
#define XCP_CMD_PENDING             2
#define XCP_CMD_SYNTAX              3
#define XCP_CMD_BUSY                4
#define XCP_CMD_UNKNOWN             5
#define XCP_CMD_OUT_OF_RANGE        6
#define XCP_MODE_NOT_VALID          7
#define XCP_CMD_ERROR               0xFF

#define CRO_BYTE(x)             (pCmd->b[x])
#define CRO_WORD(x)             (pCmd->w[x])
#define CRO_DWORD(x)            (pCmd->dw[x])
#define CRM_BYTE(x)             (xcp.Crm.b[x])
#define CRM_WORD(x)             (xcp.Crm.w[x])
#define CRM_DWORD(x)            (xcp.Crm.dw[x])


typedef struct {
  vuint8 b[kXcpMaxDTO];
  vuint8 l;
} tXcpDto;

typedef union {
  /* There might be a loss of up to 3 bytes. */
  vuint8  b[ ((kXcpMaxCTO + 3) & 0xFFC)      ];
  vuint16 w[ ((kXcpMaxCTO + 3) & 0xFFC) / 2  ];
  vuint32 dw[ ((kXcpMaxCTO + 3) & 0xFFC) / 4 ];
} tXcpCto;

typedef struct {

  vuint16 firstOdtEntry;       /* Absolute */
  vuint16 lastOdtEntry;        /* Absolute */

  #if defined ( XCP_ENABLE_STIM )
  tXcpDto *pStimBuffer; 
  #endif

} tXcpOdt;


/* DAQ list */
typedef struct {

  tXcpOdtIdx lastOdt;             /* Absolute */
  tXcpOdtIdx firstOdt;            /* Absolute */

  vuint8 flags;        

  #if defined ( kXcpMaxEvent ) && ! defined ( XCP_ENABLE_STIM )
  /* Event-Daq association array used */
  #else
  vuint8 eventChannel; 
  #endif

  #if defined ( XCP_ENABLE_DAQ_PRESCALER )
  vuint8 prescaler;  
  vuint8 cycle;     
  #endif

} tXcpDaqList;

/* Dynamic DAQ list structures */
typedef struct {

  union {
    vuint8        b[kXcpDaqMemSize];
    tXcpDaqList   DaqList[1];
  } u;

  vuint8          DaqCount;
  tXcpOdtCnt      OdtCount;       /* Absolute count */
  vuint16         OdtEntryCount;  /* Absolute count */

  /* Session configuration id for resume mode */
  #if defined ( XCP_ENABLE_DAQ_RESUME )
  vuint16 DaqConfigId;
  #endif

  /* Event-Daq association array */ 
  #if defined ( kXcpMaxEvent ) && ! defined ( XCP_ENABLE_STIM )
  vuint8 EventDaq[kXcpMaxEvent];
  #endif
} tXcpDaq;

typedef struct {
  /* Crm has to be the first object of this structure !! (refer to XcpInit()) */

  tXcpCto Crm;                           /* RES,ERR Message buffer */
  vuint8  CrmLen;                        /* RES,ERR Message length */

#if defined ( XCP_ENABLE_SEND_EVENT ) || defined ( XCP_ENABLE_SERV_TEXT )
  tXcpCto Ev;                            /* EV,SERV Message buffer */
  vuint8 EvLen;                          /* EV,SERV Message length */
#endif
  
  vuint8 SessionStatus;

  MTABYTEPTR Mta;                        /* Memory Transfer Address */

#if defined ( XCP_ENABLE_BLOCK_DOWNLOAD ) || defined (XCP_ENABLE_BLOCK_UPLOAD)
  vuint8 NextDataBlockSize;
#endif

#if defined ( XCP_ENABLE_SEED_KEY )
  vuint8 ProtectionStatus;                /* Resource Protection Status */
#endif

#if defined ( XCP_ENABLE_CHECKSUM )
  vuint16             CheckSumSize;       /* Counter for checksum calculation */
  tXcpChecksumSumType CheckSum;           /* Actual checksum */
#endif

#if defined ( XCP_ENABLE_DAQ )            /* Data Acquisition */

  /*
    Dynamic DAQ list structures
    This structure should be stored in resume mode
  */
  tXcpDaq Daq;

  tXcpOdt       *pOdt;
  DAQBYTEPTR    *pOdtEntryAddr;
  vuint8        *pOdtEntrySize;
  
  /* Transmit Queue */
  #if defined ( XCP_ENABLE_SEND_QUEUE )
  tXcpDto *pQueue;
  vuint16  QueueSize;
  vuint16  QueueLen;
  vuint16  QueueRp;
  #endif

  /* Transmit Status */
  #if defined ( XCP_ENABLE_SEND_QUEUE)
  vuint8 SendStatus;
  #endif

  /* Pointer for SET_DAQ_PTR */
  vuint16 DaqListPtr;           
    
  #if defined ( XCP_ENABLE_STIM )
  tXcpDto StimBuffer[kXcpStimOdtCount];
  #endif
    
#endif /* XCP_ENABLE_DAQ */

} tXcpData;

#endif /* XCPPROF_H */
