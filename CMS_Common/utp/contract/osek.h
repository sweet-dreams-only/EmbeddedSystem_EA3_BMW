/* The following is only part of the header that was required at the 
 * time this component was made. 
 */
#ifndef OSEK_H
#define OSEK_H

void osPsysSuspendAllInterrupts(void);
#define SuspendAllInterrupts() (osPsysSuspendAllInterrupts())

void osPsysResumeAllInterrupts(void);
#define ResumeAllInterrupts() (osPsysResumeAllInterrupts())


typedef uint32              TickType;
typedef TickType            *TickRefType;
typedef uint16              osAlarmIndexType;
typedef osAlarmIndexType    AlarmType;

void osGetAlarm(AlarmType, TickRefType);
#define GetAlarm(x, y) (osGetAlarm((x), (y)))

void osCancelAlarm(AlarmType);
#define CancelAlarm(x) (osCancelAlarm(x))

void osSetRelAlarm(AlarmType, TickType, TickType);
#define SetRelAlarm(x, y, z) (osSetRelAlarm((x), (y), (z)))

#endif /* OSEK_H */
