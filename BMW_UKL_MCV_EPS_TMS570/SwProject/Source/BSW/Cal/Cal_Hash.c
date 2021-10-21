/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Cal_Hash.c
 *      Project:  SysService_AsrCal
 *       Module:  MICROSAR Crypto Abstraction Library (Cal)
 *    Generator:  -
 *
 *  Description:  This module implements the Crypto Abstraction Layer to perform
 *                cryptographic routine. The CAL provides synchronous services
 *                to enable a unique access to basic cryptographic functionalities
 *                for all software modules and software components.
 *
 *  Limitation to the Autosar specification:
 *                This implementation provides only a sub-set of the functionality
 *                as specified in the CAL_SWS of Autosar.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file (Cal.h).
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define CAL_HASH_SOURCE
/**********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/
#include "Cal.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if (  (CAL_SW_MAJOR_VERSION != (0x02)) \
    || (CAL_SW_MINOR_VERSION != (0x01)) \
    || (CAL_SW_PATCH_VERSION != (0x01)) )
# error "Vendor specific version numbers of Cal_Hash.c and Cal.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 7 */ /* MD_CAL_3453 */
#ifndef CAL_DUMMYSTATEMENT
# if (CAL_USE_DUMMY_STATEMENT == STD_ON)
#  define CAL_DUMMYSTATEMENT(x) (void)(x)
# else
#  define CAL_DUMMYSTATEMENT(x)
# endif
#endif

#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) )
/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
  Cal_AlignType Status;
  Cal_AlignType Buffer[CAL_HASH_CONTEXT_BUFFER_SIZE - 1]; /* Generator added one additional element for the status */
} Cal_HashCtxBufStruct;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define CAL_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if ( CAL_NUMBER_OF_HASH_CONFIGS != 0 )
STATIC FUNC(P2CONST(Cal_HashConfigType, AUTOMATIC, CAL_APPL_DATA), CAL_CODE) Cal_HashGetCfg(Cal_ConfigIdType cfgId);
# endif /* ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

# if ( CAL_NUMBER_OF_HASH_CONFIGS != 0 )
/**********************************************************************************************************************
  Cal_HashGetCfg
**********************************************************************************************************************/
STATIC FUNC(P2CONST(Cal_HashConfigType, AUTOMATIC, CAL_APPL_DATA), CAL_CODE) Cal_HashGetCfg(Cal_ConfigIdType cfgId)
{
  P2CONST(Cal_HashConfigType, AUTOMATIC, CAL_APPL_DATA) calRtn;
  uint8 i;

  calRtn = NULL_PTR;

  for(i = 0; i < CAL_NUMBER_OF_HASH_CONFIGS; i++)
  {
    if(cfgId == Cal_HashConfig[i].ConfigId)
    {
      calRtn = &Cal_HashConfig[i];
      break;
    }
  }

  return calRtn;
}
# endif /* ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) */

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
**********************************************************************************************************************/

/***********************************************************************************************************************
 *  Cal_HashStart
 **********************************************************************************************************************/
/*! \brief                     This function shall be used to initialize the hash service of the CAL module.
 *  \param[in]  cfgId          Holds the identifier of the CAL module configuration that has to be used during the hash
 *                             value computation.
 *  \param[in/out] contextBuffer  Buffer pointer to the context data.
 *  \return CAL_E_OK              - Request successful
 *  \return CAL_E_NOT_OK          - Request failed
 *  \description               The function shall initialize the context buffer given by "contextBuffer", call the
 *                             function Cpl_<Primitive>Start of the primitive which is identified by the "cfgId" and
 *                             return the value returned by that function. If Cpl_<Primitive>Start returned
 *                             successfully, the function shall set the state of this service to "active", and store
 *                             this state in the context buffer.
 **********************************************************************************************************************/
FUNC(Cal_ReturnType, CAL_CODE) Cal_HashStart (Cal_ConfigIdType cfgId,
                                              Cal_HashCtxBufType contextBuffer)  /* PRQA S 3673 */ /* MD_CAL_16.7 */
{
  Cal_ReturnType calRtn = CAL_E_NOT_OK;
# if ( CAL_NUMBER_OF_HASH_CONFIGS != 0 )
  P2CONST(Cal_HashConfigType, AUTOMATIC, CAL_APPL_DATA) hashCfg;
  P2VAR(Cal_HashCtxBufStruct, AUTOMATIC, CAL_APPL_DATA) context;

  context = ((P2VAR(Cal_HashCtxBufStruct, AUTOMATIC, CAL_APPL_DATA))contextBuffer); /* Casted Context Buffer */ /* PRQA S 0310 */ /* MD_CAL_11.4 */
  hashCfg = Cal_HashGetCfg(cfgId); /* Pointer to Specific Service Configuration */

  if(hashCfg != NULL_PTR)
  {
    /* Call the configured Primitive Function */
    calRtn = hashCfg->PrimitiveStartFct(hashCfg->PrimitiveConfigPtr,
                                        context->Buffer);
  }

  if(calRtn == CAL_E_OK)
  {
    context->Status = CAL_ACT_ACTIVE;  /* Set specific Service to ACTIVE */        /* PRQA S 0310 */ /* MD_CAL_11.4 */
  }
# else
  CAL_DUMMYSTATEMENT(cfgId);                                                       /* PRQA S 3112 */ /* MD_CAL_3112 */
  CAL_DUMMYSTATEMENT(contextBuffer);                                               /* PRQA S 3112 */ /* MD_CAL_3112 */
# endif /* ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) */

  return calRtn;
}

/***********************************************************************************************************************
 *  Cal_HashUpdate
 **********************************************************************************************************************/
/*! \brief                      This function shall be used to feed the hash service with the input data.
 *  \param[in]  cfgId           Holds the identifier of the CAL module configuration that has to be used
 *                              during the hash value computation.
 *  \param[in/out]  contextBuffer   Holds the pointer to the buffer in which the context of this service can be stored.
 *  \param[in]  dataPtr             Holds a pointer to the data to be hashed.
 *  \param[in]  dataLength          Contains the number of bytes to be hashed.
 *  \return  CAL_E_OK               - Request successful
 *  \return  CAL_E_NOT_OK           - Request failed
 *  \description                If the service state given by the context buffer is "idle", the function has to return
 *                              with "CAL_E_NOT_OK". Otherwise, this function shall call the function
 *                              Cpl_<Primitive>Update of the primitive which is identified by the "cfgId", and return
 *                              the value returned by that function.
 *                              The hash computation is done by the underlying primitive.
 **********************************************************************************************************************/
FUNC(Cal_ReturnType, CAL_CODE) Cal_HashUpdate (Cal_ConfigIdType cfgId,
                                               Cal_HashCtxBufType contextBuffer,   /* PRQA S 3673 */ /* MD_CAL_16.7 */
                                               P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) dataPtr,
                                               uint32 dataLength)
{
  Cal_ReturnType calRtn = CAL_E_NOT_OK;
# if ( CAL_NUMBER_OF_HASH_CONFIGS != 0 )
  P2CONST(Cal_HashConfigType, AUTOMATIC, CAL_APPL_DATA) hashCfg;
  P2VAR(Cal_HashCtxBufStruct, AUTOMATIC, CAL_APPL_DATA) context;

  context = ((P2VAR(Cal_HashCtxBufStruct, AUTOMATIC, CAL_APPL_DATA))contextBuffer); /* Casted Context Buffer */ /* PRQA S 0310 */ /* MD_CAL_11.4 */
  hashCfg = Cal_HashGetCfg(cfgId); /* Pointer to Specific Service Configuration */

  if((hashCfg != NULL_PTR) && (dataPtr != NULL_PTR))
  {
    if(context->Status == CAL_ACT_ACTIVE)                                            /* PRQA S 0310 */ /* MD_CAL_11.4 */
    {
      /* Call the configured Primitive Function */
      calRtn = hashCfg->PrimitiveUpdateFct(hashCfg->PrimitiveConfigPtr,
                                           context->Buffer,
                                           dataPtr,
                                           dataLength);
    }
  }
# else
  CAL_DUMMYSTATEMENT(cfgId);                                                         /* PRQA S 3112 */ /* MD_CAL_3112 */
  CAL_DUMMYSTATEMENT(contextBuffer);                                                 /* PRQA S 3112 */ /* MD_CAL_3112 */
  CAL_DUMMYSTATEMENT(dataPtr);                                                       /* PRQA S 3112 */ /* MD_CAL_3112 */
  CAL_DUMMYSTATEMENT(dataLength);                                                    /* PRQA S 3112 */ /* MD_CAL_3112 */
# endif /* ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) */

  return calRtn;
}

/***********************************************************************************************************************
 *  Cal_HashFinish
 **********************************************************************************************************************/
/*! \brief                         This function shall be used to finish the hash service of the CAL module.
*  \param[in]  cfgId               Holds the identifier of the CAL module configuration that has to be used
*                                  during the hash value computation.
*  \param[in/out]  contextBuffer   Holds the pointer to the buffer in which the context of this service can be stored.
*  \param[in]  resultPtr           Holds a pointer to the memory location which will hold the result of the hash value
*                                  computation. If the result does not fit into the given buffer, and truncation is
*                                  allowed, the result shall be truncated.
*  \param[in]  resultLengthPtr     Holds a pointer to the memory location in which the length information is stored.
*                                  On calling this function this parameter shall contain the size of the buffer
*                                  provided by resultPtr. On returning from this function the actual length of the
*                                  computed value shall be stored.
*  \param[in]  TruncationIsAllowed This parameter states whether a truncation of the result is allowed or not.
*                                  TRUE: Truncation is allowed.
*                                  FALSE: Truncation is not allowed.
*  \return   CAL_E_OK              - Request successful
*  \return CAL_E_NOT_OK            - Request failed
*  \return CAL_E_SMALL_BUFFER  The provided buffer is too small to store the result, and truncation was not allowed.
*  \description                If the service state given by the context buffer is "idle", the function has to return
*                              with "CAL_E_NOT_OK". Otherwise, this function shall call the function
*                              Cpl_<Primitive>Finish of the primitive which is identified by the "cfgId", and return
*                              the value returned by that function. If Cpl_<Primitive>Finish returned successfully,
*                              the function shall set the state of this service to "idle", and store this state in the
*                              context buffer. The hash computation is done by the underlying primitive.
**********************************************************************************************************************/
FUNC(Cal_ReturnType, CAL_CODE) Cal_HashFinish (Cal_ConfigIdType cfgId,
                                               Cal_HashCtxBufType contextBuffer,                       /* PRQA S 3673 */ /* MD_CAL_16.7 */
                                               P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) resultPtr,      /* PRQA S 3673 */ /* MD_CAL_16.7 */
                                               P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) resultLengthPtr,/* PRQA S 3673 */ /* MD_CAL_16.7 */
                                               boolean TruncationIsAllowed)
{
  Cal_ReturnType calRtn = CAL_E_NOT_OK;
# if ( CAL_NUMBER_OF_HASH_CONFIGS != 0 )
  P2CONST(Cal_HashConfigType, AUTOMATIC, CAL_APPL_DATA) hashCfg;
  P2VAR(Cal_HashCtxBufStruct, AUTOMATIC, CAL_APPL_DATA) context;

  context = ((P2VAR(Cal_HashCtxBufStruct, AUTOMATIC, CAL_APPL_DATA))contextBuffer);  /* Casted Context Buffer */ /* PRQA S 0310 */ /* MD_CAL_11.4 */
  hashCfg = Cal_HashGetCfg(cfgId);                   /* Pointer to Specific Service Configuration */

  if((hashCfg         != NULL_PTR) &&
     (resultPtr       != NULL_PTR) &&
     (resultLengthPtr != NULL_PTR))
  {
    if(context->Status == CAL_ACT_ACTIVE)                                          /* PRQA S 0310 */ /* MD_CAL_11.4 */
    {
      /* Call the configured Primitive Function */
      calRtn = hashCfg->PrimitiveFinishFct(hashCfg->PrimitiveConfigPtr,
                                           context->Buffer,
                                           resultPtr,
                                           resultLengthPtr,
                                           TruncationIsAllowed);
    }

    if(calRtn == CAL_E_OK)
    {
      context->Status = CAL_ACT_IDLE;  /* Set specific Service to IDLE */         /* PRQA S 0310 */ /* MD_CAL_11.4 */
    }
  }

# else
  CAL_DUMMYSTATEMENT(cfgId);                                                       /* PRQA S 3112 */ /* MD_CAL_3112 */
  CAL_DUMMYSTATEMENT(contextBuffer);                                               /* PRQA S 3112 */ /* MD_CAL_3112 */
  CAL_DUMMYSTATEMENT(resultPtr);                                                   /* PRQA S 3112 */ /* MD_CAL_3112 */
  CAL_DUMMYSTATEMENT(resultLengthPtr);                                             /* PRQA S 3112 */ /* MD_CAL_3112 */
  CAL_DUMMYSTATEMENT(TruncationIsAllowed);                                         /* PRQA S 3112 */ /* MD_CAL_3112 */
# endif /* ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) */

  return calRtn;
}

# define CAL_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) ) */

/**********************************************************************************************************************
 *  END OF FILE: CAL_HASH.C
 *********************************************************************************************************************/
