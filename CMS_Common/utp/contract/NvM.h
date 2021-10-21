/* The following is only part of the header that was required at the 
 * time this component was made. 
 */
#ifndef NVM_H
#define NVM_H

#include "NvM_Cfg.h" /* KS - Added for QAC to include all files */
#include "NvM_Types.h" /* KS - Added for QAC to include all files */
 
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_WriteBlock (NvM_BlockIdType BlockId, P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr);

#endif /* NVM_H */
