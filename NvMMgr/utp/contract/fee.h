#ifndef FEE_H
#define FEE_H

extern void Fee_Cancel(void);
extern Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber);
extern MemIf_JobResultType Fee_GetJobResult(void);
extern MemIf_StatusType Fee_GetStatus(void);
extern void Fee_Init(void);
extern Std_ReturnType Fee_InvalidateBlock(uint16 BlockNumber);
extern Std_ReturnType Fee_Read(uint16 BlockNumber,
                               uint16 BlockOffset,
                               uint8* DataBufferPtr,
                               uint16 Length);
extern Std_ReturnType Fee_Write(uint16 BlockNumber,
                                uint8* DataBufferPtr);

/*  BSW Functions */
extern void Fee_MainFunction(void);

#endif /* FEE_H */
