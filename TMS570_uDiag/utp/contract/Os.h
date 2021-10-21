#ifndef OS_H
#define OS_H

#include "tcb.h"

/* Expected osek Os CAT2 ISR macro */
#define ISR(x) void x##func(void)

/* Expected Os Generated extern definitions for CAT2 ISR's */
extern void FlsTst_IrqCh1Errfunc(void);

/* expected osektype.h definitions for osqRAM0, osqRAM1, osqRAM2, osqRAM3, PRO_SHUTDOWN, osqFunc1, osqFunc2 */
#define osqRAM0 
#define osqRAM1 
#define osqRAM2 
#define osqRAM3 
#define PRO_SHUTDOWN              4U
#define osqFunc1
#define osqFunc2 
/* expected osektype.h definitions  */
typedef unsigned char  osuint8;
typedef unsigned short osuint16;
typedef osuint8                  ProtectionReturnType;
typedef osuint16                 TrustedFunctionIndexType;                
typedef void*                    TrustedFunctionParameterRefType;   


/* expected osekqm.h extern for osLastError and ErrorHook */
osqRAM0 extern osqRAM1           osqRAM2  osuint16             osqRAM3  osLastError          ;
extern osqFunc1 void osqFunc2 ErrorHook (StatusType Error);

/* expected osek.h definitions */
#define OSErrorGetosCANError()      osLastError 
void SuspendAllInterrupts(void);
StatusType CallTrustedFunction (TrustedFunctionIndexType x, TrustedFunctionParameterRefType y);

/* expected osekerr.h definitions for errors used in OsErrCallouts.c */
#define osdErrUEUnhandledException    0x2801U 
#define osdErrSOStackOverflow         0x6101U
#define osdErrYOStackOverflow           0xA101U

/* expected oseksctx.h declarations of ProtectionHook */
ProtectionReturnType ProtectionHook(StatusType Fatalerror);

#endif/* double include preventer */

