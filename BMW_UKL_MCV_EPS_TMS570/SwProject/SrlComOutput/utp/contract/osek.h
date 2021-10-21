/* osek.h include for QAC */


#define ActivateTask(x) (osPsysActivateTask(x))
#define ResumeAllInterrupts() (osPsysResumeAllInterrupts())
#define SuspendAllInterrupts() (osPsysSuspendAllInterrupts())

/* from osektype.h */
typedef unsigned short osuint16;
typedef osuint16       osTaskIndexType;     /* TR:SOSK22:0021 */ /* TR:SOSK22:0156 */
typedef osTaskIndexType     TaskType;      /* TR:SOSK22:0156 */


/* from tcb.h */
#define Task_10msA_9 ((TaskType)30)
#define Task_10msA_10 ((TaskType)31)
StatusType osPsysActivateTask(TaskType Param1taskIndex);




extern void osPsysResumeAllInterrupts(void); /* PRQA S 3408 */
extern void osPsysSuspendAllInterrupts(void); /* PRQA S 3408 */
