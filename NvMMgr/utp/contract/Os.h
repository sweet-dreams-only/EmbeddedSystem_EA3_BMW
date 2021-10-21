#ifndef _OS_H
#define _OS_H

typedef unsigned short osuint16;

typedef osuint16                 TrustedFunctionIndexType;
typedef void*                    TrustedFunctionParameterRefType;

StatusType CallTrustedFunction(TrustedFunctionIndexType Param1FunctionIndex, TrustedFunctionParameterRefType Param2FunctionParams);

#endif/* double include preventer */
