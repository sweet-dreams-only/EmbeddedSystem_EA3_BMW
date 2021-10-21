#ifndef OS_H
#define OS_H

/* Expected osek Os CAT2 ISR macro */
#define ISR(x) void x##func(void)

/* Expected Os Generated extern definitions for CAT2 ISR's */
extern void SpiNxt_IrqUnit2TxRxfunc(void);
extern void SpiNxt_IrqUnit2TxRxERRfunc(void);

#endif/* double include preventer */

