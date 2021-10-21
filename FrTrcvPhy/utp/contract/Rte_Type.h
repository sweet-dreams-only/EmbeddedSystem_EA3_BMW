
/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

typedef uint8 UInt8;
typedef uint16 UInt16;
typedef uint16 NTCNumber;
typedef uint8 NxtrDiagMgrStatus;
typedef unsigned long       uint32;  

typedef struct
{
  UInt16 Threshold;
  UInt16 PStep;
  UInt16 NStep;
} DiagSettings_Str;


#define NTC_Num_BusOffCh1			256U
#define NTC_Num_TrcvrInterfaceFlt	257U


#define NTC_STATUS_PASSED 	0U
#define NTC_STATUS_FAILED	1U

#  define D_ONE_CNT_U8 (1U)
#  define D_ZERO_CNT_U16 (0U)

#endif /* _RTE_TYPE_H */
