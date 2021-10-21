/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
#if (!defined NVM_TYPES_H_)
#define NVM_TYPES_H_

/* Service ID type */
/**********************************************************************************************************************
 * API DEFINES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * API MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * API TYPE DEFINITIONS
 *********************************************************************************************************************/

/* type of a request result */
typedef uint8 NvM_RequestResultType;

typedef uint16 NvM_BlockIdType;

/* result values of asynchronous requests (stored in the RAM Mngmnt),
 * They are also defined by the RTE, since these are the important values for an SW-C */

#define NVM_REQ_OK               (0u)  /* The last asynchronous request has been finished successfully */
#define NVM_REQ_NOT_OK           (1u)  /* The last asynchronous request has been finished unsuccessfully */
#define NVM_REQ_PENDING          (2u)  /* An asynchronous request is currently being processed */
#define NVM_REQ_INTEGRITY_FAILED (3u)  /* Result of the last NvM_ReadBlock or NvM_ReadAll is an integrity failure */
#define NVM_REQ_BLOCK_SKIPPED    (4u)  /* The referenced block was skipped during a multi block request */
#define NVM_REQ_NV_INVALIDATED   (5u)  /* The NV block is invalidated. */

/* Service ID type */
typedef uint8 NvM_ServiceIdType;   /* type of a service id */

/* These Sevice IDs are important to an SW-C, as they can be passed to it in the 
   "single block job end notification" callback.
   Therefore they are also defined by the RTE */
#define NVM_READ_BLOCK             (6u) /* Service ID NvM_ReadBlock() */
#define NVM_WRITE_BLOCK            (7u) /* Service ID NvM_WriteBlock() */
#define NVM_RESTORE_BLOCK_DEFAULTS (8u) /* Service ID NvM_RestoreBlockDefaults() */
#define NVM_ERASE_BLOCK            (9u) /* Service ID NvM_EraseNvBlock() */
#define NVM_INVALIDATE_NV_BLOCK   (11u) /* Service ID NvM_InvalidateNvBlock() */
#define NVM_READ_ALL              (12u) /* Service ID NvM_ReadAll() */


/* This result will not be defined by the RTE */
#define NVM_REQ_CANCELLED        (6u)  /* A WriteAll was cancelled */

                                        
/* Service Ids of the different service routines of the NVM
 * These sevice IDs are never defined by the RTE               */
#define NVM_INIT                   (0u) /* Service ID NvM_Init() */
#define NVM_SET_DATA_INDEX         (1u) /* Service ID NvM_SetDataIndex() */
#define NVM_GET_DATA_INDEX         (2u) /* Service ID NvM_GetDataIndex() */
#define NVM_SET_BLOCK_PROTECTION   (3u) /* Service ID NvM_SetBlockProtection() */
#define NVM_GET_ERROR_STATUS       (4u) /* Service ID NvM_GetErrorStatus() */
#define NVM_SET_RAM_BLOCK_STATUS   (5u) /* Service ID NvM_SetRamBlockStatus() */

#define NVM_CANCEL_WRITE_ALL      (10u) /* Service ID NvM_CancelRequest() */

#define NVM_WRITE_ALL             (13u) /* Service ID NvM_WriteAll() */
#define NVM_MAINFUNCTION          (14u) /* Service ID NvM_MainFunction() */
#define NVM_GET_VERSION_INFO      (15u) /* Service ID NvM_GetVersionInfo() */

#define NVM_SET_BLOCK_LOCK_STATUS (16u) /* Service ID NvM_SetBlockProtection() */                                        
#define NVM_KILL_WRITE_ALL        (17u) /* Service ID NvM_KillWriteAll() */

/**********************************************************************************************************************
 * API STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * API VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * API FUNCTIONS
 *********************************************************************************************************************/

#endif /* NVM_TYPES_H_ */
/* ---- End of File --------------------------------------------------------- */
