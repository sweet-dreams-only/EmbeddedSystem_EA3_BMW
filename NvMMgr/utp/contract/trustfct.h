
#ifndef _TRUSTCFT_H
#define _TRUSTCFT_H


/* Trusted Functions */

#define TWrapS_FeeIf_Init 0
void TRUSTED_TWrapS_FeeIf_Init(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
#define TWrapS_Fee_MainFunction 1
void TRUSTED_TWrapS_Fee_MainFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
#define TWrapS_Fee_Read 2
void TRUSTED_TWrapS_Fee_Read(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);

typedef struct
{
   uint16 os_arg_BlockNumber;
   uint16 os_arg_BlockOffset;
   uint8* os_arg_DataBufferPtr;
   uint16 os_arg_Length;
   Std_ReturnType os_result;
} osTFArgType_TWrapS_Fee_Read;

#define TWrapS_Fee_Write 3
void TRUSTED_TWrapS_Fee_Write(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);

typedef struct
{
   uint16 os_arg_BlockNumber;
   uint8* os_arg_DataBufferPtr;
   Std_ReturnType os_result;
} osTFArgType_TWrapS_Fee_Write;

#define TWrapS_Fee_EraseImmediateBlock 4
void TRUSTED_TWrapS_Fee_EraseImmediateBlock(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);

typedef struct
{
   uint16 os_arg_BlockNumber;
   Std_ReturnType os_result;
} osTFArgType_TWrapS_Fee_EraseImmediateBlock;

#define TWrapS_Fee_InvalidateBlock 5
void TRUSTED_TWrapS_Fee_InvalidateBlock(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);

typedef struct
{
   uint16 os_arg_BlockNumber;
   Std_ReturnType os_result;
} osTFArgType_TWrapS_Fee_InvalidateBlock;

#define TWrapS_Fee_Cancel 6
void TRUSTED_TWrapS_Fee_Cancel(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
#define TWrapS_Fee_GetStatus 7
void TRUSTED_TWrapS_Fee_GetStatus(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);

typedef struct
{
   uint8 os_result;
} osTFArgType_TWrapS_Fee_GetStatus;

#define TWrapS_Fee_GetJobResult 8
void TRUSTED_TWrapS_Fee_GetJobResult(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);

typedef struct
{
   uint8 os_result;
} osTFArgType_TWrapS_Fee_GetJobResult;

typedef struct
{
   uint8 os_arg_Command; 
} osTFArgType_TWrapS_TI_Fee_SuspendResumeErase;

typedef union
{
   osTFArgType_TWrapS_Fee_Read TWrapS_Fee_Read_args;
   osTFArgType_TWrapS_Fee_Write TWrapS_Fee_Write_args;
   osTFArgType_TWrapS_Fee_EraseImmediateBlock TWrapS_Fee_EraseImmediateBlock_args;
   osTFArgType_TWrapS_Fee_InvalidateBlock TWrapS_Fee_InvalidateBlock_args;
   osTFArgType_TWrapS_Fee_GetStatus TWrapS_Fee_GetStatus_args;
   osTFArgType_TWrapS_Fee_GetJobResult TWrapS_Fee_GetJobResult_args;
   osTFArgType_TWrapS_TI_Fee_SuspendResumeErase TWrapS_TI_Fee_SuspendResumeErase_args;
} TrustedFunctionParameterType;

#define TWrapS_TI_Fee_SuspendResumeErase 9
void TRUSTED_TWrapS_TI_Fee_SuspendResumeErase(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);

typedef enum
{
	Suspend_Erase=0U,
	Resume_Erase
}TI_Fee_EraseCommandType; 
extern void TI_Fee_SuspendResumeErase(TI_Fee_EraseCommandType Command);
 
#endif /* _TRUSTCFT_H double include preventer */
