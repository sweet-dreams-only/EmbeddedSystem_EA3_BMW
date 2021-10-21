#ifndef _NVM_H 
#define _NVM_H

	typedef uint16 NvM_BlockIdType;

	#define NVM_BLOCK_DIAGMGR_NTCSTRG	1U
	#define NVM_BLOCK_DIAGMGR_BLACKBOX	2U

	extern FUNC(void, NVM_PUBLIC_CODE) NvM_SetRamBlockStatus( NvM_BlockIdType BlockId, boolean BlockChanged);

#endif


