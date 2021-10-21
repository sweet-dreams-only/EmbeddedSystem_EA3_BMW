/* The following is only part of the header that was required at the 
 * time this component was made. 
 */
#ifndef DESC_H
#define DESC_H

#include "v_def.h" /* KS: Added to give definitions for V_MEMRAMx */

#define DESC_P2FARRAM(baseType)                                     V_MEMRAM1 baseType V_MEMRAM2 V_MEMRAM3 *

typedef unsigned short vuint16;
typedef unsigned char  vuint8;
typedef vuint8                                        DescMsgItem;
typedef vuint16                                       DescMsgLen;
typedef DESC_P2FARRAM(DescMsgItem)                    DescMsg; 
 
#define DESC_API_CALL_TYPE
typedef vuint8 DescNegResCode;
# define DESC_CONTEXT_PARAM_ONLY                                     iContext  
# define DESC_CONTEXT_PARAM_TYPE_ONLY                                vuint8  
# define DESC_CONTEXT_FORMAL_PARAM_DEF_FIRST                         DESC_CONTEXT_PARAM_TYPE_ONLY DESC_CONTEXT_PARAM_ONLY,
void DESC_API_CALL_TYPE DescSetNegResponse(DESC_CONTEXT_FORMAL_PARAM_DEF_FIRST DescNegResCode errorCode);
#define kDescNrcNone                                                 ((DescNegResCode)0x00)

#endif /* DESC_H */
