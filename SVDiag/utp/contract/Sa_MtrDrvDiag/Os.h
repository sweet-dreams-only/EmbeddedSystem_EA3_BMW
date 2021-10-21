#ifndef OS_H
#define OS_H

/* Expected osek Os Suspend and resume interrupt API's */
FUNC(void, AUTOMATIC)SuspendAllInterrupts(void);
FUNC(void, AUTOMATIC)ResumeAllInterrupts(void);

#endif/* double include preventer */