
/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
#if (!defined NVM_H_)
#define NVM_H_

/**********************************************************************************************************************
 * API RELEVANT (PUBLIC) SECTION OF CONFIGURATION
 *********************************************************************************************************************/
#include "NvM_Types.h"

/**********************************************************************************************************************
 * API FUNCTIONS
 *********************************************************************************************************************/

#define NVM_START_SEC_CODE
#include "MemMap.h"

/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_Init()
!
!-----------------------------------------------------------------------------
!   Function Description: Service for basic NVRAM manager initialisation:
!                         initializes internal structures and the state
!                         machines.
!
!-----------------------------------------------------------------------------
!   Parameter (Input):   none
!   Parameter (Output):  none
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_Init(void);


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_SetDataIndex(BlockId, DataIndex)
!
!-----------------------------------------------------------------------------
!   Function Description: The request shall set the index to associate a
!   dataset NV/ROM block with its corresponding RAM block.
!
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId, DataIndex
!   Parameter (Output):  none
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_SetDataIndex
    (
        NvM_BlockIdType BlockId,
        uint8 DataIndex
    );

/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_GetDataIndex(BlockId)
!
!-----------------------------------------------------------------------------
!   Function Description: The request shall get the current index
!   (association) of a dataset NV/ROM block with its corresponding
!   RAM block.
!
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId
!   Parameter (Output):  DataIndexPtr
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_GetDataIndex
    (
        NvM_BlockIdType BlockId,
        P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr
    );


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_SetBlockProtection(BlockId)
!
!-----------------------------------------------------------------------------
!   Function Description: The request shall set/reset the write protection for
!   the NV block. This shall be done by setting the write lock attribute in the
!   administrative part of the corresponding RAM block. Any further write/erase
!   requests to the NVRAM block shall be rejected synchronously if the NV block
!   write protection is set. The data area of the RAM block shall remain 
!   writeable in case of write protection.
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId, ProtectionEnabled
!   Parameter (Output):  none
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_SetBlockProtection
    (
        NvM_BlockIdType BlockId,
        boolean ProtectionEnabled
    );


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_GetErrorStatus(BlockId)
!
!-----------------------------------------------------------------------------
!   Function Description: The request shall read the block dependent error/
!   status information in the administrative part of a RAM block. The
!   status/error information shall be set by a former or current asynchronous
!   request.
!
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId
!   Parameter (Output):  RequestResultPtr
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_GetErrorStatus
    (
        NvM_BlockIdType BlockId,
        P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
    );


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_GetVersionInfo(versioninfo)
!
!-----------------------------------------------------------------------------
!   Function Description: The request shall read the version info of the
!   module: Module Id, Vendor Id, Vendor specific version numbers
!-----------------------------------------------------------------------------
!   Parameter (Input):   none
!   Parameter (Output):  versioninfo
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_GetVersionInfo
    (
        P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_DATA) versioninfo
    );


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_SetRamBlockStatus(BlockId, BlockChanged)
!
!-----------------------------------------------------------------------------
!   Function Description: The request shall set a permanent RAM block to the
!   valid or the invalid state.
!
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId, BlockChanged
!   Parameter (Output):  none
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_SetRamBlockStatus
    (
        NvM_BlockIdType BlockId,
        boolean BlockChanged
    );


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_ReadBlock(BlockId, NvM_DstPtr)
!
!-----------------------------------------------------------------------------
!   Function Description: Request to copy the data of the NV block to
!   its corresponding RAM block. If the block to be written is permanent a
!   NULL_PTR shall be given as parameter, otherwise a pointer to the ram
!   block shall be given.
!
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId
!   Parameter (Output):  NvM_DstPtr
!   Returnvalue:         Std_ReturnType
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_ReadBlock
    (
        NvM_BlockIdType BlockId,
        P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
    );


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_WriteBlock(BlockId, NvM_SrcPtr)
!
!-----------------------------------------------------------------------------
!   Function Description: Request to copy the data of the RAM block to its
!   corresponding NV block. If the block to be written is permanent a NULL_PTR
!   shall be given as parameter, otherwise a pointer to the ram block shall be
!   given.
!
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId, NvM_SrcPtr
!   Parameter (Output):  none
!   Returnvalue:         Std_ReturnType
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_WriteBlock
    (
        NvM_BlockIdType BlockId,
        P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
    );


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_RestoreBlockDefaults(BlockId, NvM_DstPtr)
!
!-----------------------------------------------------------------------------
!   Function Description: Request to restore the ROM block default data to
!   its corresponding RAM block. If the ram block is not permanent NvM_DstPtr
!   shall be used as output pointer, otherwise a NULL_PTR shall be handed.
!
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId
!   Parameter (Output):  NvM_DstPtr
!   Returnvalue:         Std_ReturnType
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_RestoreBlockDefaults
    (
        NvM_BlockIdType BlockId,
        P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
    );


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_EraseNvBlock(BlockId)
!
!-----------------------------------------------------------------------------
!   Function Description: Request to erase a NV block. The content of the RAM
!   block shall remain unmodified.
!
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId
!   Parameter (Output):  none
!   Returnvalue:         Std_ReturnType
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_EraseNvBlock
    (
        NvM_BlockIdType BlockId
    );


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_InvalidateNvBlock(BlockId)
!
!-----------------------------------------------------------------------------
!   Function Description: Request to invalidate a NV block. The RAM block shall
!   remain unmodified.
!
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId
!   Parameter (Output):  none
!   Returnvalue:         Std_ReturnType
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_InvalidateNvBlock
    (
        NvM_BlockIdType BlockId
    );


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_ReadAll()
!
!-----------------------------------------------------------------------------
!   Function Description: Request to read the data of all configured RAM
!   blocks from their corresponding NV blocks.
!   Only the data of valid NV blocks is read.
!-----------------------------------------------------------------------------
!   Parameter (Input):   none
!   Parameter (Output):  none
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_ReadAll(void);


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_WriteAll()
!
!-----------------------------------------------------------------------------
!   Function Description: Request to copy the data of all configured RAM
!   blocks to their corresponding NV blocks.
!   Only the data of valid RAM blocks shall be written.
!-----------------------------------------------------------------------------
!   Parameter (Input):   none
!   Parameter (Output):  none
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_WriteAll(void);


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_CancelWriteAll()
!
!-----------------------------------------------------------------------------
!   Function Description: Request to cancel a pending WriteAll request.
!-----------------------------------------------------------------------------
!   Parameter (Input):   none
!   Parameter (Output):  none
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_CancelWriteAll(void);

/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_KillWriteAll()
!
!-----------------------------------------------------------------------------
!   Function Description: Request to kill a pending WriteAll request, i.e.
!                         To cancel it destructively
!                         (in contrast to NvM_Cancelwriteall)
!                         Shall only called by EcuM (or comparable SW)
!-----------------------------------------------------------------------------
!   Parameter (Input):   none
!   Parameter (Output):  none
!   Returnvalue:         void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern void NvM_KillWriteAll(void);

/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_MainFunction
!
!-----------------------------------------------------------------------------
!   Function Description: This  function shall perform the processing of the
!   NVRAM Manager jobs. Therefore it has to be called cyclically.
!-----------------------------------------------------------------------------
!   Module Global: none
!   Parameter:     none
!   Returnvalue:   void
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(void, NVM_PUBLIC_CODE) NvM_MainFunction(void);


/*!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!   Function name: NvM_SetBlockLockStatus(BlockId, Locked)
!
!-----------------------------------------------------------------------------
!   Function Description: The request shall set/reset the lock status for
!   the NV block. This shall be done by setting the lock status attribute in the
!   administrative part of the corresponding RAM block. 
!   The NV contents associated to the NVRAM block identified by BlockId, will not
!   be modi-fied by any request. The Block shall be skipped during NvM_WriteAll. 
!   Other write/erase requests shall be rejected. At processing NvM_ReadAll a
!   locked block shall be loaded from NV memory.write protection.
!-----------------------------------------------------------------------------
!   Parameter (Input):   BlockId, Locked
!   Parameter (Output):  none
!   Returnvalue:         Std_ReturnType
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
extern FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_SetBlockLockStatus
    (
        NvM_BlockIdType BlockId,
        boolean Locked
    );

#define NVM_STOP_SEC_CODE
#include "MemMap.h"


#endif
/* ---- End of File --------------------------------------------------------- */
