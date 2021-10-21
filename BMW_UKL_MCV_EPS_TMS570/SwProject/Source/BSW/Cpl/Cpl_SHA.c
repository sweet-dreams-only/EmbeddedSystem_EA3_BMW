/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Cpl
*
*  This file contains the implementation of the BMW SWC Cpl
*  for usage in the BMW AUTOSAR Core.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW Group 2015
*
*  \version     3.0.2
*
*  \remarks     --
*
*/
/*----------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* MISRA-C:2004 Rule 8.7: Static constant is located here, because memory mapping
   is not allowed inside a function, see PRQA: 3218 */

/* MISRA-C:2004 Rule 11.4: This type cast is specified in AUTOSAR_SWS_Crypto-
   AbstractionLibrary.pdf.It is ensured by a requirement, that this type cast
   does not violate memory bounds, see PRQA: 0310 */

/* MISRA-C:2004 Rule 12.8: This shift operation is for reading 8 bit or 16 bit of
   a 32 bit value, see PRQA: 0501 */

/* MISRA-C:2004 Rule 17.4: Pointers are needed instead of array types to be able
   to use the Autosar compiler abstraction, see PRQA: 0491 */

/* MISRA-C:2004 Rule 19.1: Including Auth_MemMap.h is necessary throughout the
   file according to memory abstraction, see PRQA: 5087 */

/* MISRA-C:2004 Rule 19.7: C90 does not support inline functions, see PRQA: 3453 */


/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Cal.h"
#include "Cpl_Cfg.h"
#include "Cpl_Version.h"
#include "Cpl_Common.h"
#include "Cpl_SHA.h"
#include "BUtil_Assert.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Cpl_CHECK_VERSION(3,0,2))
   #error "Version of Cpl_SHA.c does not match the version of the module!"
#endif

#if (CPL_SHA_CODE_ENABLED == STD_ON)

/**
 * \brief A message which is hashed is divided into blocks which are processed
 *         individually. This macro gives the length of a block in bytes.
 *
 */
#define CPL_SHA_BLOCK_LEN_BYTES 64U

/**
 * \brief A message which is hashed is divided into blocks which are processed
 *         individually. This macro gives the length of a block in words.
 *
 */
#define CPL_SHA_BLOCK_LEN_WORDS 16U



/**
 * \brief The number of rounds performed by the SHA-1 algorithm.
 */
#define CPL_SHA1_ROUNDS 80U

/**
 * \brief The hash algorithm uses a state which is modified by processing the input.
 *         The state after processing the whole input is the hash digest. This macro
 *         gives the length of the SHA-1 state in 32-bit words.
 *
 */
#define CPL_SHA1_STATE_WORDS  5U



/**
 * \brief The number of rounds performed by the SHA-256 algorithm.
 */
#define CPL_SHA256_ROUNDS 64U

/**
 * \brief The hash algorithm uses a state which is modified by processing the input.
 *         The state after processing the whole input is the hash digest. This macro
 *         gives the length of the SHA-256 state in 32-bit words.
 */
#define CPL_SHA256_STATE_WORDS  8U

/**
 * \brief Rotate a 32-bit word by a given amount of bits to the right.
 */
#define CPL_SHA256_ROTR(Word, Amount) \
   ((uint32)(((Word) >> (Amount)) | ((Word) << (32 - (Amount))))) /* PRQA S 3453 */


/**
 * \brief Rotate a 32-bit word by a given amount of bits to the left.
 */
#define CPL_SHA256_ROTL(Word, Amount) \
   ((uint32)(((Word) << (Amount)) | ((Word) >> (32 - (Amount))))) /* PRQA S 3453 */


/**
 * \brief The function \Sigma^{\{256\}}_0(x) from the
 *         descpription of SHA-256 in chapter 4.1.2 of the standard FIPS 180-2.
 */
#define CPL_SHA256_CAPITAL_SIGMA_0(Word) \
(                                       \
   (uint32)                             \
   (                                    \
      CPL_SHA256_ROTR(Word,  2) ^       \
      CPL_SHA256_ROTR(Word, 13) ^       \
      CPL_SHA256_ROTR(Word, 22)         \
   )                                    \
) /* PRQA S 3453 */


/**
 * \brief The function (in LaTex notation) \Sigma^{\{256\}}_1(x) from the
 *         descpription of SHA-256 in chapter 4.1.2 of the standard FIPS 180-2.
 */
#define CPL_SHA256_CAPITAL_SIGMA_1(Word) \
(                                       \
   (uint32)                             \
   (                                    \
      CPL_SHA256_ROTR(Word,  6) ^       \
      CPL_SHA256_ROTR(Word, 11) ^       \
      CPL_SHA256_ROTR(Word, 25)         \
   )                                    \
) /* PRQA S 3453 */
/**
 * \brief The function \sigma^{\{256\}}_0(x) from the
 *         descpription of SHA-256 in chapter 4.1.2 of the standard FIPS 180-2.
 */
#define CPL_SHA256_SMALL_SIGMA_0(Word) \
(                                     \
   (uint32)                           \
   (                                  \
      CPL_SHA256_ROTR(Word,  7) ^     \
      CPL_SHA256_ROTR(Word, 18) ^     \
      (uint32)((Word) >> 3)           \
   )                                  \
) /* PRQA S 3453 */


/**
 * \brief The function \sigma^{\{256\}}_1(x) from the
 *         descpription of SHA-256 in chapter 4.1.2 of the standard FIPS 180-2.
 */
#define CPL_SHA256_SMALL_SIGMA_1(Word) \
(                                     \
   (uint32)                           \
   (                                  \
      CPL_SHA256_ROTR(Word, 17) ^     \
      CPL_SHA256_ROTR(Word, 19) ^     \
      (uint32)((Word) >> 10)          \
   )                                  \
) /* PRQA S 3453 */

/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/

/**
 * \brief Enumeration of the internal states of the SHA computation.
 */
typedef enum
{
   CPL_SHA_S_IDLE,
   CPL_SHA_S_INITIALIZED
}
Cpl_SHAStateType;


/**
 * \brief Enumeration of the internal states of Cpl_SHAProcessInput()
 */
typedef enum
{
   CPL_SHA_S_PROCESS_IDLE,
   CPL_SHA_S_PROCESS,
   CPL_SHA_S_PROCESS_COPY1,
   CPL_SHA_S_PROCESS_COMPRESS1,
   CPL_SHA_S_PROCESS_COMPRESS2,
   CPL_SHA_S_PROCESS_COMPRESS3
}
Cpl_SHAProcessInputStateType;


/**
 * \brief Enumeration of the internal states of Cpl_SHA1Compress()
 */
typedef enum
{
   CPL_SHA1_S_COMPRESS_IDLE,
   CPL_SHA1_S_COMPRESS,
   CPL_SHA1_S_COMPRESS_PRECALC,
   CPL_SHA1_S_COMPRESS_TRANSFORM1,
   CPL_SHA1_S_COMPRESS_TRANSFORM2,
   CPL_SHA1_S_COMPRESS_TRANSFORM3
}
Cpl_SHA1CompressStateType;


/**
 * \brief Enumeration of the internal states of Cpl_SHA256Compress()
 */
typedef enum
{
   CPL_SHA256_S_COMPRESS_IDLE,
   CPL_SHA256_S_COMPRESS,
   CPL_SHA256_S_COMPRESS_PRECSMC,
   CPL_SHA256_S_COMPRESS_TRANS1,
   CPL_SHA256_S_COMPRESS_DEFAULT
}
Cpl_SHA256CompressStateType;


/**
 * \brief Structure which contains the context of the SHA algorithm.
 */
typedef struct
{
   P2CONST(Cpl_SHAConfigType,  TYPEDEF, Cpl_APPL_DATA) cfgPtr;
   Cal_ReturnType                           ErrorCode;
   boolean                                  TruncationAllowed;
   P2VAR(uint8,   TYPEDEF, Cpl_APPL_DATA)   Result;
   P2VAR(uint32,  TYPEDEF, Cpl_APPL_DATA)   ResultLengthPtr;
   P2CONST(uint8, TYPEDEF, Cpl_APPL_DATA)   Data;
   uint32                                   DataLength;
   Cpl_SHAStateType                         State;
   uint32                                   Internalstate[CPL_SHA256_STATE_WORDS];
   uint32                                   Count;
   uint8                                    Partial[CPL_SHA_BLOCK_LEN_BYTES];
   uint8                                    length[8U];
   uint8                                    SHAPad[CPL_SHA_BLOCK_LEN_BYTES];
   P2CONST(uint8, TYPEDEF, Cpl_APPL_DATA)   p;
   uint32                                   left;
   uint8                                    copy;
   uint8                                    offset;
   Cpl_SHAProcessInputStateType             ProcessInputState;
   Cpl_SHA1CompressStateType                SHA1CompressState;
   Cpl_SHA256CompressStateType              SHA256CompressState;
   uint32                                   a;
   uint32                                   b;
   uint32                                   c;
   uint32                                   d;
   uint32                                   e;
   uint32                                   f;
   uint32                                   g;
   uint32                                   h;
   uint32                                   t1;
   uint32                                   t2;
   uint32                                   W[CPL_SHA_BLOCK_LEN_WORDS];
   uint8                                    i;
   uint8                                    k;
   uint8                                    l;
}
Cpl_SHACtxType;

/* PRQA S 4104 1 *//* tested macro of module BUtil*/
BUTIL_STATIC_ASSERT(sizeof(Cal_HashCtxBufType) >= sizeof(Cpl_SHACtxType),
   "The configured context buffer size in the CAL for the hash generation is incorrect!");

/**
 * \brief The different compression functions for SHA-1 and SHA-2 all have an
 *         identical API. This function pointer type describes that API.
 */
typedef P2FUNC(boolean, Cpl_CODE, Cpl_SHACompressFctType)
(
   P2VAR(Cpl_SHACtxType, TYPEDEF, Cpl_APPL_DATA) Ctx,
   P2CONST(uint8,        TYPEDEF, Cpl_APPL_DATA) Data
);

/*------------------------------------------------------------------------------
                      Local Functions Prototypes
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Cpl_START_SEC_CODE
#include "Cpl_MemMap.h"

static FUNC(void, Cpl_CODE) Cpl_SHAProcessInputCopy(
   P2VAR(Cpl_SHACtxType,      AUTOMATIC, Cpl_APPL_DATA) Ctx);

static FUNC(boolean, Cpl_CODE) Cpl_SHAProcessInputCompress(
   P2VAR(Cpl_SHACtxType,      AUTOMATIC, Cpl_APPL_DATA) Ctx);

static FUNC(boolean, Cpl_CODE) Cpl_SHAProcessInput(
   P2VAR(Cpl_SHACtxType,      AUTOMATIC, Cpl_APPL_DATA) Ctx);

static FUNC(void, Cpl_CODE) Cpl_SHACompressStart(
   P2VAR(Cpl_SHACtxType,      AUTOMATIC, Cpl_APPL_DATA) Ctx);

static FUNC(void, Cpl_CODE) Cpl_SHACountConvert(
   uint32                                 Count,
   P2VAR(uint8, AUTOMATIC, Cpl_APPL_DATA) Convert);

static FUNC(void, Cpl_CODE) Cpl_SHAExport(
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx);



static FUNC(boolean, Cpl_CODE) Cpl_SHA1Compress(
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx,
   P2CONST(uint8,        AUTOMATIC, Cpl_APPL_DATA) Data);

static FUNC(void, Cpl_CODE) Cpl_SHA1CompressTransform(
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx);



static FUNC(boolean, Cpl_CODE) Cpl_SHA256Compress(
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx,
   P2CONST(uint8,        AUTOMATIC, Cpl_APPL_DATA) Data);

static FUNC(void, Cpl_CODE) Cpl_SHA256CompressExpansion(
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx);

static FUNC(void, Cpl_CODE) Cpl_SHA256CompressTransform(
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx);

/* PRQA S 5087 2 */
#define Cpl_STOP_SEC_CODE
#include "Cpl_MemMap.h"

/*------------------------------------------------------------------------------
                      Local Variables
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                      Local Constants
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Cpl_START_SEC_CONST_32
#include "Cpl_MemMap.h"

/**
 * \brief For each computation round i, the SHA-256 computation uses a constant K_i
 *         in the computation of T_1. This array contains those constants.
 */
/* PRQA S 3218 Sha_ConstArray */
static CONST(uint32, Cpl_CONST) Cpl_SHA256K[CPL_SHA256_ROUNDS] =
{
   (uint32)0x428a2f98ul, (uint32)0x71374491ul, (uint32)0xb5c0fbcful, (uint32)0xe9b5dba5ul,
   (uint32)0x3956c25bul, (uint32)0x59f111f1ul, (uint32)0x923f82a4ul, (uint32)0xab1c5ed5ul,
   (uint32)0xd807aa98ul, (uint32)0x12835b01ul, (uint32)0x243185beul, (uint32)0x550c7dc3ul,
   (uint32)0x72be5d74ul, (uint32)0x80deb1feul, (uint32)0x9bdc06a7ul, (uint32)0xc19bf174ul,
   (uint32)0xe49b69c1ul, (uint32)0xefbe4786ul, (uint32)0x0fc19dc6ul, (uint32)0x240ca1ccul,
   (uint32)0x2de92c6ful, (uint32)0x4a7484aaul, (uint32)0x5cb0a9dcul, (uint32)0x76f988daul,
   (uint32)0x983e5152ul, (uint32)0xa831c66dul, (uint32)0xb00327c8ul, (uint32)0xbf597fc7ul,
   (uint32)0xc6e00bf3ul, (uint32)0xd5a79147ul, (uint32)0x06ca6351ul, (uint32)0x14292967ul,
   (uint32)0x27b70a85ul, (uint32)0x2e1b2138ul, (uint32)0x4d2c6dfcul, (uint32)0x53380d13ul,
   (uint32)0x650a7354ul, (uint32)0x766a0abbul, (uint32)0x81c2c92eul, (uint32)0x92722c85ul,
   (uint32)0xa2bfe8a1ul, (uint32)0xa81a664bul, (uint32)0xc24b8b70ul, (uint32)0xc76c51a3ul,
   (uint32)0xd192e819ul, (uint32)0xd6990624ul, (uint32)0xf40e3585ul, (uint32)0x106aa070ul,
   (uint32)0x19a4c116ul, (uint32)0x1e376c08ul, (uint32)0x2748774cul, (uint32)0x34b0bcb5ul,
   (uint32)0x391c0cb3ul, (uint32)0x4ed8aa4aul, (uint32)0x5b9cca4ful, (uint32)0x682e6ff3ul,
   (uint32)0x748f82eeul, (uint32)0x78a5636ful, (uint32)0x84c87814ul, (uint32)0x8cc70208ul,
   (uint32)0x90befffaul, (uint32)0xa4506cebul, (uint32)0xbef9a3f7ul, (uint32)0xc67178f2ul
};
/* PRQA L: Sha_ConstArray */

/* PRQA S 5087 2 */
#define Cpl_STOP_SEC_CONST_32
#include "Cpl_MemMap.h"

/* PRQA S 5087 2 */
#define Cpl_START_SEC_CONST_UNSPECIFIED
#include "Cpl_MemMap.h"

/**
 * \brief The different SHA hash functions use different compression functions. This
 *         array contains the compression functions for SHA-1 and SHA-256.
 */
static CONST(Cpl_SHACompressFctType, Cpl_CONST) Cpl_SHACompressFct[] =
{
   &Cpl_SHA1Compress,   /* accordingly to enum Cpl_SHAConfigIdType.CPL_SHA_1   */
   &Cpl_SHA256Compress  /* accordingly to enum Cpl_SHAConfigIdType.CPL_SHA_256 */
};

/* PRQA S 5087 2 */
#define Cpl_STOP_SEC_CONST_UNSPECIFIED
#include "Cpl_MemMap.h"

/*------------------------------------------------------------------------------
                      Local Functions
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Cpl_START_SEC_CODE
#include "Cpl_MemMap.h"

/*----------------------------------------------------------------------------*/
/**
 * \brief Processes the given input data.
 *
 * This function fills incomplete blocks, if existent, for the Cpl_SHAProcessInput() function.
 *
 * \global_r  -
 * \global_w  -
 * \global_rw -
 *
 * \param[in,out] Ctx    A pointer to a buffer which holds the context of the current Hash
 *                       computation.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks -
 *
 */
/*----------------------------------------------------------------------------*/

static FUNC(void, Cpl_CODE) Cpl_SHAProcessInputCopy(
   P2VAR(Cpl_SHACtxType,      AUTOMATIC, Cpl_APPL_DATA) Ctx)
{
   if (Ctx->offset > (uint8) 0)
   {
      /* find out how much data we need to copy */
      if ( (uint32)((uint32)Ctx->offset + Ctx->DataLength) > (uint32)CPL_SHA_BLOCK_LEN_BYTES )
      {
         Ctx->copy = (uint8)CPL_SHA_BLOCK_LEN_BYTES - Ctx->offset;
      }
      else
      {
         /* cast is ok here: we tested dataBytes "< 64" above */
         Ctx->copy = (uint8) Ctx->DataLength;
      }

      /* fill up the temporary buffer with as much data as possible */
      Cpl_CommonCopy
      (
         &Ctx->Partial[Ctx->offset],
         Ctx->p,
         (uint16)Ctx->copy
      );

      Ctx->ProcessInputState = CPL_SHA_S_PROCESS_COMPRESS1;
   }
   else
   {
      Cpl_SHACompressStart(Ctx);

      Ctx->ProcessInputState = CPL_SHA_S_PROCESS_COMPRESS3;
   }
} /* end of function Cpl_SHAProcessInputCopy */

/*----------------------------------------------------------------------------*/
/**
 * \brief Processes the given input data.
 *
 * This function compresses the complete blocks for the Cpl_SHAProcessInput() function.
 *
 * \global_r  -
 * \global_w  -
 * \global_rw -
 *
 * \param[in,out] Ctx    A pointer to a buffer which holds the context of the current Hash
 *                       computation.
 *
 * \returns    state of input processing.
 *
 * \retval TRUE If the Input was completely processed
 * \retval FALSE Otherwise.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks -
 *
 */
/*----------------------------------------------------------------------------*/

static FUNC(boolean, Cpl_CODE) Cpl_SHAProcessInputCompress(
   P2VAR(Cpl_SHACtxType,      AUTOMATIC, Cpl_APPL_DATA) Ctx)
{
   boolean Finished;
   P2CONST(Cpl_SHAConfigType, AUTOMATIC, Cpl_APPL_DATA) locCfgPtr;

   Finished  = FALSE;
   locCfgPtr = Ctx->cfgPtr;

   if ((Ctx->left & (uint32)0xffffffc0UL) != (uint32) 0)
   {
      if(Cpl_SHACompressFct[locCfgPtr->ConfigId](Ctx, Ctx->p) == TRUE)
      {
         /* PRQA S 0491 1 */
         Ctx->p     = &Ctx->p[CPL_SHA_BLOCK_LEN_BYTES];
         Ctx->left -= (uint32)CPL_SHA_BLOCK_LEN_BYTES;

         if ((Ctx->left & (uint32)0xffffffc0UL) != (uint32) 0)
         {
            Cpl_SHACompressStart(Ctx);
         }
      }
   }
   else
   {
      /* 4. Check if there is still data */
      if (Ctx->left > (uint32) 0U)
      {
         /* Copy data into partial buffer */
         Cpl_CommonCopy
         (
            Ctx->Partial,
            Ctx->p,
            (uint16)Ctx->left
         );
      }

      Finished = TRUE;
   }

   return Finished;
} /* end of function Cpl_SHAProcessInputCompress */



/*----------------------------------------------------------------------------*/
/**
 * \brief Processes the given input data.
 *
 * This function perorms  the input data stored in the context of the algorithm.
 *
 * \global_r  -
 * \global_w  -
 * \global_rw -
 *
 * \param[in,out] Ctx    A pointer to a buffer which holds the context of the current Hash
 *                       computation.
 *
 * \returns    state of input processing.
 *
 * \retval TRUE If the Input was completely processed
 * \retval FALSE Otherwise.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks -
 *
 */
/*----------------------------------------------------------------------------*/

static FUNC(boolean, Cpl_CODE) Cpl_SHAProcessInput(
   P2VAR(Cpl_SHACtxType,      AUTOMATIC, Cpl_APPL_DATA) Ctx)
{
   boolean Finished;
   P2CONST(Cpl_SHAConfigType, AUTOMATIC, Cpl_APPL_DATA) locCfgPtr;

   Finished  = FALSE;
   locCfgPtr = Ctx->cfgPtr;

   switch(Ctx->ProcessInputState)
   {
      case CPL_SHA_S_PROCESS:
         if (Ctx->DataLength != (uint32) 0)
         {
            /* initialize temporal data */
            Ctx->p    = Ctx->Data;
            Ctx->left = Ctx->DataLength;
            Ctx->copy = (uint8) 0;

            /* 1. get unprocessed bytes from last block and update the counter */
            Ctx->offset = (uint8) ((Ctx->Count) & (uint32) 0x3f);

            /* Ignore a possible overflow here */
            Ctx->Count += Ctx->DataLength;

            Ctx->ProcessInputState = CPL_SHA_S_PROCESS_COPY1;
         }
         else
         {
            /* if there is no data, there is no work to do */
            Finished = TRUE;
         }
         break;

      case CPL_SHA_S_PROCESS_COPY1:
         /* 2. if existent, process incomplete blocks */

         Cpl_SHAProcessInputCopy(Ctx);
         break;

      case CPL_SHA_S_PROCESS_COMPRESS1:
         /* look if we have one block to compress */
         if
         (
            (uint8)(Ctx->offset + Ctx->copy) <
            (uint8)CPL_SHA_BLOCK_LEN_BYTES
         )
         {
            Finished = TRUE;
         }
         else
         {
            /* we have one complete block, so compress it */
            Cpl_SHACompressStart(Ctx);
            /* PRQA S 0491 1 */
            Ctx->p     = &Ctx->p[Ctx->copy];
            Ctx->left -= (uint32)Ctx->copy;
            Ctx->ProcessInputState = CPL_SHA_S_PROCESS_COMPRESS2;
         }
         break;

      case CPL_SHA_S_PROCESS_COMPRESS2:
         if(Cpl_SHACompressFct[locCfgPtr->ConfigId](Ctx, Ctx->Partial) == TRUE)
         {
            Cpl_SHACompressStart(Ctx);
            Ctx->ProcessInputState = CPL_SHA_S_PROCESS_COMPRESS3;
         }
         break;

      /* CPL_SHA_S_PROCESS_COMPRESS3 -
       * this case must be the default case to get 100 percent coverage
       */
      default:
         /* 3. process complete blocks */
         Finished = Cpl_SHAProcessInputCompress(Ctx);
         break;
   }

   return Finished;
} /* end of function Cpl_SHAProcessInput */



/*----------------------------------------------------------------------------*/
/**
 * \brief Initialize compress function
 *
 * This function initializes the compression states of the context variable so that the compress
 * function can be used.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in,out] Ctx    Pointer which holds the context of the current SHA calculation.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

static FUNC(void, Cpl_CODE) Cpl_SHACompressStart(
   P2VAR(  Cpl_SHACtxType,     AUTOMATIC, Cpl_APPL_DATA) Ctx)
{
   Ctx->SHA1CompressState   = CPL_SHA1_S_COMPRESS;
   Ctx->SHA256CompressState = CPL_SHA256_S_COMPRESS;

} /* end of function Cpl_SHACompressStart */



/*----------------------------------------------------------------------------*/
/**
 * \brief Converts an unsigned 32-bit number into an array of unsigned byte values.
 *
 * This function converts an unsigned 32-bit number into an array of unsigned byte values as needed
 * by the padding function of the SHA algorithms.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in]     Count   A number in an unsigned 32-bit variable which must be converted to an
 *                        array of bytes.
 * \param[out]    Convert A pointer to an array of 8-bit unsigned values which will hold the
 *                        converted number after this function has finished.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

static FUNC(void, Cpl_CODE) Cpl_SHACountConvert(
   uint32                                 Count,
   P2VAR(uint8, AUTOMATIC, Cpl_APPL_DATA) Convert)
{
   /* convert into bits and store in big endian order*/

   /* PRQA S 0492 9 */
   Convert[0U] = (uint8)0;
   Convert[1U] = (uint8)0;
   Convert[2U] = (uint8)0;
   /* PRQA S 0501 3 */
   Convert[3U] = (uint8)(Count >> 29U);
   Convert[4U] = (uint8)(Count >> 21U);
   Convert[5U] = (uint8)(Count >> 13U);
   Convert[6U] = (uint8)(Count >>  5U);
   Convert[7U] = (uint8)(Count <<  3U);
} /* end of function Cpl_SHACountConvert */



/*----------------------------------------------------------------------------*/
/**
 * \brief Cpl_SHAExport copies the digest to the output area.
 *
 * The internal state of the SHA algorithm after the input has been
 * processed completely is the digest. This function copies the digest from
 * the internal state to the output array.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in,out] Ctx   A pointer to a buffer which holds the context of the current Hash
 *                      computation.
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

static FUNC(void, Cpl_CODE) Cpl_SHAExport(P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx)
{
   uint8_least index; /* loop variable */

   if( (Ctx->cfgPtr->ConfigId   == CPL_SHA_1            ) &&
       (CPL_SHA1_HASH_LEN_BYTES <= *Ctx->ResultLengthPtr)
     )
   {
      *Ctx->ResultLengthPtr = CPL_SHA1_HASH_LEN_BYTES;
   }
   else
   if( (Ctx->cfgPtr->ConfigId     == CPL_SHA_256          ) &&
       (CPL_SHA256_HASH_LEN_BYTES <= *Ctx->ResultLengthPtr)
     )
   {
      *Ctx->ResultLengthPtr = CPL_SHA256_HASH_LEN_BYTES;
   }
   else
   {
      if(FALSE == Ctx->TruncationAllowed)
      {
         Ctx->ErrorCode = CAL_E_SMALL_BUFFER;
      }
   }

   index = (uint8_least)0;
   do
   {
      uint8_least tmpIndex; /* tmp space to save loop results */

      tmpIndex = index;
      tmpIndex <<= 2U;
      if(tmpIndex < *Ctx->ResultLengthPtr)
      {
         /* PRQA S 0491, 0501 1 */
         Ctx->Result[tmpIndex] = (uint8)(Ctx->Internalstate[index] >> 24U);
         tmpIndex++;
      }

      if(tmpIndex < *Ctx->ResultLengthPtr)
      {
         /* PRQA S 0491, 0501 1 */
         Ctx->Result[tmpIndex] = (uint8)(Ctx->Internalstate[index] >> 16U);
         tmpIndex++;
      }

      if(tmpIndex < *Ctx->ResultLengthPtr)
      {
         /* PRQA S 0491 1 */
         Ctx->Result[tmpIndex] = (uint8)(Ctx->Internalstate[index] >>  8U);
         tmpIndex++;
      }

      if(tmpIndex < *Ctx->ResultLengthPtr)
      {
         /* PRQA S 0491 1 */
         Ctx->Result[tmpIndex] = (uint8)(Ctx->Internalstate[index]       );
      }

      index++;
   } while (index < (uint8_least)(*Ctx->ResultLengthPtr));
} /* end of function Cpl_SHAExport */



/*----------------------------------------------------------------------------*/
/**
 * \brief Processes one block of data to hash.
 *
 * This function compresses one block of data to hash according to the rules of SHA-1 and updates
 * the internal state accordingly. The function Cpl_SHACompressStart() has to be called before the
 * first call to this function.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in]     Data   A pointer to a block of data of size  ::CPL_SHA_BLOCK_LEN_BYTES bytes
 *                       which has to be processed.
 * \param[in,out] Ctx    A pointer to a buffer which holds the context of the current Hash
 *                       computation.
 *
 * \returns    compression state
 *
 * \retval TRUE  The compression has finished. Now, the result is stored in the context variable.
 * \retval FALSE Otherwise.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

static FUNC(boolean, Cpl_CODE) Cpl_SHA1Compress(
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx,
   P2CONST(uint8,        AUTOMATIC, Cpl_APPL_DATA) Data)
{
   boolean Finished;


   Finished = FALSE;

   switch(Ctx->SHA1CompressState)
   {
      case CPL_SHA1_S_COMPRESS:
         Ctx->a = Ctx->Internalstate[0U];
         Ctx->b = Ctx->Internalstate[1U];
         Ctx->c = Ctx->Internalstate[2U];
         Ctx->d = Ctx->Internalstate[3U];
         Ctx->e = Ctx->Internalstate[4U];

         /* copy data to local buffer */
         Ctx->i = (uint8)0;

         Ctx->SHA1CompressState = CPL_SHA1_S_COMPRESS_PRECALC;
         break;

      case CPL_SHA1_S_COMPRESS_PRECALC:
         /* precalculate 4 * i once during the loop */
         Ctx->k = Ctx->i;
         Ctx->k <<= 2U;

         /* PRQA S 0492, 0501 5 */
         Ctx->W[Ctx->i] =
            (uint32)((uint32)Data[Ctx->k           ] << 24U) |
            (uint32)((uint32)Data[Ctx->k + (uint8)1] << 16U) |
            (uint32)((uint32)Data[Ctx->k + (uint8)2] <<  8U) |
            (uint32)Data[Ctx->k + (uint8)3];

         ++Ctx->i;

         if (Ctx->i >= (uint8)(CPL_SHA_BLOCK_LEN_BYTES / 4U))
         {
            Ctx->SHA1CompressState = CPL_SHA1_S_COMPRESS_TRANSFORM1;
            /* 2. the message context.result transformation loop */
            Ctx->i = (uint8) 0;
         }
         break;

      case CPL_SHA1_S_COMPRESS_TRANSFORM1:
         /* 2.1 precalculations */
         Ctx->k = (uint8) (Ctx->i & (uint8)0x0f);
         Ctx->l = (uint8) (Ctx->i / (uint8)20);


         /* 2.2 user data expansion:
          * during the first 16 rounds, no expansion is needed. sha1 uses
          * the user input data directly
          * from rounds 17 to 79, calculate the necessary word
          */
         if ((uint8)(Ctx->i & (uint8) 0xf0) != (uint8) 0)
         {
            /* the word is constructed recursively from 4 previous words */
            Ctx->t1 =
               Ctx->W[(uint8)(Ctx->i + (uint8)13) & (uint8)0x0f] ^
               Ctx->W[(uint8)(Ctx->i +  (uint8)8) & (uint8)0x0f] ^
               Ctx->W[(uint8)(Ctx->i +  (uint8)2) & (uint8)0x0f] ^
               Ctx->W[Ctx->k];

            Ctx->W[Ctx->k] =
               (uint32)
               (
                  /* PRQA S 0501 2 */
                  (uint32)(Ctx->t1 << 1U) |
                  (uint32)(Ctx->t1 >> 31U)
               );
         }

         Ctx->SHA1CompressState = CPL_SHA1_S_COMPRESS_TRANSFORM2;
         break;

      case CPL_SHA1_S_COMPRESS_TRANSFORM2:
         /* 2.3 round transformation */
         Cpl_SHA1CompressTransform(Ctx);

         Ctx->SHA1CompressState = CPL_SHA1_S_COMPRESS_TRANSFORM3;
         break;

      /* CPL_SHA1_S_COMPRESS_TRANSFORM3 -
       * this case must be the default case to get 100 persent coverage
       */
      default:
         /* 2.4 permute the words for next round */
         Ctx->e = Ctx->d;
         Ctx->d = Ctx->c;

         /* optimization: ROTL by 30 is ROTR by 2 */
         /* PRQA S 0501 2 */
         Ctx->c = (uint32) ((uint32) ((uint32) Ctx->b >> 2U) |
            (uint32) ((uint32) Ctx->b << 30U));
         Ctx->b = Ctx->a;
         Ctx->a = Ctx->t1;

         Ctx->i++;

         if (Ctx->i != (uint8) CPL_SHA1_ROUNDS)
         {
            Ctx->SHA1CompressState = CPL_SHA1_S_COMPRESS_TRANSFORM1;
         }
         else
         {
            /* 3. copy internal state back to Ctx */
            Ctx->Internalstate[0U] += Ctx->a;
            Ctx->Internalstate[1U] += Ctx->b;
            Ctx->Internalstate[2U] += Ctx->c;
            Ctx->Internalstate[3U] += Ctx->d;
            Ctx->Internalstate[4U] += Ctx->e;

            Finished = TRUE;
         }
         break;
   }

   return Finished;
} /* end of function Cpl_SHA1Compress */



/*----------------------------------------------------------------------------*/
/**
 * \brief This function performs a transformation for the Cpl_SHA1Compress() function.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in,out] Ctx    Pointer which holds the context of the current SHA calculation.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

static FUNC(void, Cpl_CODE) Cpl_SHA1CompressTransform(
   P2VAR(  Cpl_SHACtxType,     AUTOMATIC, Cpl_APPL_DATA) Ctx)
{
   /* round dependent part first */
   switch (Ctx->l)
   {
      case 0:
         /* rounds 0 .. 19 */
         Ctx->t1 =
            (uint32)
            (
               (uint32)
               (
                  (uint32)((uint32)Ctx->c ^ (uint32)Ctx->d) &
                  (uint32) Ctx->b
               ) ^
               (uint32) Ctx->d
            ) +
            (uint32) 0x5a827999UL;

         break;

      case 1:
         /* rounds 20 .. 39 */
         Ctx->t1 =
            (uint32)
            (
               (uint32)((uint32)Ctx->b ^ (uint32)Ctx->c) ^
               (uint32) Ctx->d
            ) +
            (uint32) 0x6ed9eba1UL;
         break;

      case 2:
         /* rounds 40 .. 59 */
         Ctx->t1 =
            (uint32)
            (
               (uint32)
               (
                  (uint32)
                  (
                     (uint32) Ctx->b & (uint32) Ctx->c
                  ) |
                  (uint32)
                  (
                     (uint32) Ctx->b & (uint32) Ctx->d
                  )
               ) |
               (uint32)
               (
                  (uint32)
                  (
                     (uint32)Ctx->c & (uint32)Ctx->d
                  )
               )
            ) +
            (uint32) 0x8f1bbcdcUL;
         break;

      default:
         /* rounds 60 .. 79 */
         Ctx->t1 =
            (uint32)
            (
               (uint32)((uint32)Ctx->b ^ (uint32)Ctx->c) ^
               (uint32)Ctx->d
            ) +
            (uint32) 0xca62c1d6UL;
         break;
   }
   /* round independent part */
      /* PRQA S 0501 4 */
   Ctx->t1 += (uint32) ((uint32) ((uint32) Ctx->a << 5U) |
      (uint32) ((uint32) Ctx->a >> 27U)) +
      (Ctx->e) +
      (Ctx->W[Ctx->k]);

} /* end of function Cpl_SHA1CompressTransform */



/*----------------------------------------------------------------------------*/
/**
 * \brief Processes one block of data to hash.
 *
 * This function compresses one block of data to hash according to the rules of SHA-256 and updates
 * the internal state accordingly. The function Cpl_SHACompressStart() has to be called before the
 * first call to this function.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in]     Data   A pointer to a block of data of size  ::CPL_SHA_BLOCK_LEN_BYTES bytes
 *                       which has to be processed.
 * \param[in,out] Ctx    A pointer to a buffer which holds the context of the current Hash
 *                       computation.
 *
 * \returns    compression state
 *
 * \retval TRUE  The compression has finished. Now, the result is stored in the context variable.
 * \retval FALSE Otherwise.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

static FUNC(boolean, Cpl_CODE) Cpl_SHA256Compress(
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx,
   P2CONST(uint8,        AUTOMATIC, Cpl_APPL_DATA) Data)
{
   boolean Finished = FALSE;


   /* CPL_SHA256_S_COMPRESS */
   Ctx->a = Ctx->Internalstate[0U];
   Ctx->b = Ctx->Internalstate[1U];
   Ctx->c = Ctx->Internalstate[2U];
   Ctx->d = Ctx->Internalstate[3U];
   Ctx->e = Ctx->Internalstate[4U];
   Ctx->f = Ctx->Internalstate[5U];
   Ctx->g = Ctx->Internalstate[6U];
   Ctx->h = Ctx->Internalstate[7U];

   /* copy data to local buffer */
   Ctx->i = (uint8)0;

   /* CPL_SHA256_S_COMPRESS_PRECSMC */

   /* precalculate 4 * i once during the loop */
   do
   {
      Ctx->k = Ctx->i;
      Ctx->k <<= 2U;

         /* PRQA S 0492, 0501 5 */
      Ctx->W[Ctx->i] =
         (uint32)((uint32)Data[Ctx->k           ] << 24U) |
         (uint32)((uint32)Data[Ctx->k + (uint8)1] << 16U) |
         (uint32)((uint32)Data[Ctx->k + (uint8)2] <<  8U) |
         (uint32)Data[Ctx->k + (uint8)3];
      ++Ctx->i;
   } while(Ctx->i < (uint8)(CPL_SHA_BLOCK_LEN_BYTES / 4U));


   /* 2. the message Ctx->result transformation loop */
   Ctx->i = (uint8) 0;

   /* CPL_SHA256_S_COMPRESS_TRANS1 */

   do {
     Ctx->k = (uint8) (Ctx->i & (uint8)0x0f);
     Ctx->l = (uint8) (Ctx->i / (uint8)20);


     /* 2.2 user data expansion:
      * during the first 16 rounds, no expansion is needed. sha256 uses
      * the user input data directly
      * from rounds 17 to 64, calculate the necessary word
      */
     Cpl_SHA256CompressExpansion(Ctx);
     /* 2.3 round transformation */
     Cpl_SHA256CompressTransform(Ctx);
     /* 2.4 permute the words for next round */
     Ctx->h = Ctx->g;
     Ctx->g = Ctx->f;
     Ctx->f = Ctx->e;
     Ctx->e = Ctx->d + Ctx->t1;
     Ctx->d = Ctx->c;
     Ctx->c = Ctx->b;
     Ctx->b = Ctx->a;
     Ctx->a = Ctx->t1 + Ctx->t2;
     Ctx->i++;

   }while(Ctx->i != (uint8) CPL_SHA256_ROUNDS);


   /* 3. copy internal state back to Ctx */
   Ctx->Internalstate[0U] += Ctx->a;
   Ctx->Internalstate[1U] += Ctx->b;
   Ctx->Internalstate[2U] += Ctx->c;
   Ctx->Internalstate[3U] += Ctx->d;
   Ctx->Internalstate[4U] += Ctx->e;
   Ctx->Internalstate[5U] += Ctx->f;
   Ctx->Internalstate[6U] += Ctx->g;
   Ctx->Internalstate[7U] += Ctx->h;

   Finished = TRUE;

   return Finished;
} /* end of function Cpl_SHA256Compress */



/*----------------------------------------------------------------------------*/
/**
 * \brief This function performs a expansion for the Cpl_SHA256Compress() function.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in,out] Ctx    Pointer which holds the context of the current SHA calculation.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

static FUNC(void, Cpl_CODE) Cpl_SHA256CompressExpansion(
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx)
{
   if ((uint8)(Ctx->i & (uint8) 0xf0) != (uint8) 0)
   {
      /* the word is constructed recursively from 4 previous words */
      Ctx->W[Ctx->k] =
         /* PRQA S 0501 1 */
         CPL_SHA256_SMALL_SIGMA_1
         (
            Ctx->W[(uint8)(Ctx->k + (uint8)14) & (uint8)0x0f]
         ) +
         Ctx->W[(uint8)(Ctx->k + (uint8)9) & (uint8)0x0f] +
         /* PRQA S 0501 1 */
         CPL_SHA256_SMALL_SIGMA_0
         (
            Ctx->W[(uint8)(Ctx->k + (uint8)1) & (uint8)0x0f]
         ) +
         Ctx->W[Ctx->k];
   }
} /* end of function Cpl_SHA256CompressExpansion */



/*----------------------------------------------------------------------------*/
/**
 * \brief This function performs a transformation for the Cpl_SHA256Compress() function.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * \param[in,out] Ctx    Pointer which holds the context of the current SHA calculation.
 *
 * \pre --
 *
 * \post --
 *
 * \remarks --
 */
/*----------------------------------------------------------------------------*/

static FUNC(void, Cpl_CODE) Cpl_SHA256CompressTransform(
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_APPL_DATA) Ctx)
{
   Ctx->t1 =
      Ctx->h +
      /* PRQA S 0501 1 */
      CPL_SHA256_CAPITAL_SIGMA_1(Ctx->e) +
      (uint32)
      (
         (uint32)
         (
            (uint32)(Ctx->f ^ Ctx->g) &
            Ctx->e
         ) ^
         Ctx->g
      ) +
      Cpl_SHA256K[Ctx->i] +
      Ctx->W[Ctx->k];

   Ctx->t2 =
      /* PRQA S 0501 1 */
      CPL_SHA256_CAPITAL_SIGMA_0(Ctx->a) +
      (uint32)
      (
         (uint32)
         (
            (uint32)(Ctx->a & Ctx->b) |
            (uint32)(Ctx->a & Ctx->c)
         ) |
         (uint32)(Ctx->b & Ctx->c)
      );
} /* end of function Cpl_SHA256CompressTransform */

/* PRQA S 5087 2 */
#define Cpl_STOP_SEC_CODE
#include "Cpl_MemMap.h"


/*------------------------------------------------------------------------------
                      Global Functions
------------------------------------------------------------------------------*/

/* PRQA S 5087 2 */
#define Cpl_START_SEC_CODE
#include "Cpl_MemMap.h"

/*----------------------------------------------------------------------------*/
/**
 * \brief  Initializes the SHA1 context.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * This function requests and performs the start of the SHA Hash computation for the given
 * configuration.
 *
 * \param[in]    CfgPtr  Pointer to the configuration parameters used for this function.
 * \param[inout] Ctx     Pointer to a buffer in which the context can be stored.
 *
 * \returns  Error value.
 *
 * \retval   CAL_E_OK      Request successful
 * \retval   CAL_E_NOT_OK  Request failed
 *
 * \pre --
 *
 * \post The SHA-1 algorithm is initialized.
 *
 * \remarks Cpl_SHAStart has to be called via the interface Cal_HashStart from the CAL module.
 *
 * \serviceid  0x00
 * \reentrancy Reentrant
 *
 * \swsid SWS_Cpl_0021
 */
/*----------------------------------------------------------------------------*/

FUNC(Cal_ReturnType, Cpl_CODE) Cpl_SHAStart(
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) CfgPtr,
   Cal_HashCtxBufType                      Ctx)
{
   Cal_ReturnType                            RetVal    = CAL_E_NOT_OK;

   CONSTP2CONST(Cpl_SHAConfigType, AUTOMATIC, Cpl_VAR) locCfgPtr =
      (P2CONST(Cpl_SHAConfigType, AUTOMATIC, Cpl_VAR)) CfgPtr;

   /* MISRA-C:2004 Rule 11.4: see MISRA Deviations */
   /* PRQA S 0310 2 */
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_VAR) locSHACtx =
      (P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_VAR)) Ctx;

   if ( (NULL_PTR                   != CfgPtr                ) &&
        (NULL_PTR                   != Ctx                   )
      )
   {
      /* 0. Init the pointer to the configuration for use in sub functions */
      locSHACtx->cfgPtr = CfgPtr;

      /* 1. Init the number of processed bytes */
      locSHACtx->Count  = (uint32)0;

      switch ( locCfgPtr->ConfigId )
      {
         case CPL_SHA_256:
         {
            locSHACtx->Internalstate[0U] = (uint32) 0x6a09e667UL;
            locSHACtx->Internalstate[1U] = (uint32) 0xbb67ae85UL;
            locSHACtx->Internalstate[2U] = (uint32) 0x3c6ef372UL;
            locSHACtx->Internalstate[3U] = (uint32) 0xa54ff53aUL;
            locSHACtx->Internalstate[4U] = (uint32) 0x510e527fUL;
            locSHACtx->Internalstate[5U] = (uint32) 0x9b05688cUL;
            locSHACtx->Internalstate[6U] = (uint32) 0x1f83d9abUL;
            locSHACtx->Internalstate[7U] = (uint32) 0x5be0cd19UL;
         }
         break;

         case CPL_SHA_1:
         default:
         {
            locSHACtx->Internalstate[0U] = (uint32) 0x67452301UL;
            locSHACtx->Internalstate[1U] = (uint32) 0xefcdab89UL;
            locSHACtx->Internalstate[2U] = (uint32) 0x98badcfeUL;
            locSHACtx->Internalstate[3U] = (uint32) 0x10325476UL;
            locSHACtx->Internalstate[4U] = (uint32) 0xc3d2e1f0UL;
         }
         break;
      }

      locSHACtx->ErrorCode         = CAL_E_OK;

      RetVal                       = CAL_E_OK;

      locSHACtx->State             = CPL_SHA_S_INITIALIZED;
   }

   return ( RetVal );
} /* end of function Cpl_SHAStart */



/*----------------------------------------------------------------------------*/
/**
 * \brief  This function feeds data to hash to the SHA1 function.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * This function requests and performs the update of the SHA Hash computation for the given
 * configuration.
 *
 * \param[in]     CfgPtr     Pointer to the configuration parameters used for this function.
 * \param[in]     dataPtr    Pointer to the data which shall be hashed.
 * \param[in]     dataLength Length in bytes of the data block which shall be hashed.
 * \param[inout]  Ctx        Pointer to a SHA Context, which has to be updated.
 *
 * \returns  Error value.
 *
 * \retval   CAL_E_OK      Request successful
 * \retval   CAL_E_NOT_OK  Request failed
 *
 * \pre The SHA algorithm must be initialized.
 *
 * \post --
 *
 * \remarks Cpl_SHAUpdate has to be called via the interface Cal_HashUpdate from the CAL module.
 *
 * \serviceid  0x01
 * \reentrancy Reentrant
 *
 * \swsid SWS_Cpl_0024
 */
/*----------------------------------------------------------------------------*/

FUNC(Cal_ReturnType, Cpl_CODE) Cpl_SHAUpdate(
   P2CONST(void,  AUTOMATIC, Cpl_APPL_DATA) CfgPtr,
   Cal_HashCtxBufType                       Ctx,
   P2CONST(uint8, AUTOMATIC, Cpl_APPL_DATA) dataPtr,
   uint32                                   dataLength)
{
   Cal_ReturnType                            RetVal    = CAL_E_NOT_OK;

   /* MISRA-C:2004 Rule 11.4: see MISRA Deviations */
   /* PRQA S 0310 2 */
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_VAR) locSHACtx =
               (P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_VAR)) Ctx;

   if ( (NULL_PTR              != CfgPtr          ) &&
        (NULL_PTR              != Ctx             ) &&
        (NULL_PTR              != dataPtr         ) &&
        (CPL_SHA_S_INITIALIZED == locSHACtx->State)
      )
   {
      /* Store data into context */
      locSHACtx->Data              = dataPtr;
      locSHACtx->DataLength        = dataLength;
      locSHACtx->ProcessInputState = CPL_SHA_S_PROCESS;
      locSHACtx->ErrorCode         = CAL_E_OK;

      while(Cpl_SHAProcessInput(locSHACtx) == FALSE)
      {
      }

      RetVal = locSHACtx->ErrorCode;
   }

   return ( RetVal );
} /* end of function Cpl_SHAUpdate */



/*----------------------------------------------------------------------------*/
/**
 * \brief This function computes the Hash value according to the SHA1 algorithm using the standard
 *           padding based on FIPS 180-1. The length of the Hash value resultPtr shall be 20 bytes.
 *
 * \global_r  --
 * \global_w  --
 * \global_rw --
 *
 * This function requests and performs the finish of the SHA Hash computation for the given
 * configuration.
 *
 * \param[in]     CfgPtr            Pointer to the configuration parameters used for this function.
 * \param[in]     truncationAllowed States whether a truncation of the result is allowed or not.
 *                                  TRUE: Truncation is allowed.
 *                                  FALSE: Truncation is not allowed.
 * \param[inout]  Ctx               Pointer to a SHA Context.
 * \param[inout]  resultLengthPtr   Pointer to the memory location, which holds the length information.
 *                                  On calling this function, this parameter shall contain the size of
 *                                  the buffer provided by resultPtr.
 *                                  On returning from this function, the length of the hash value is stored.
 * \param[out]    resultPtr         Pointer to a memory location, where the hash value is stored.
 *
 * \returns  Error value.
 *
 * \retval   CAL_E_OK           Request successful
 * \retval   CAL_E_SMALL_BUFFER The provided buffer is too small to store the result and truncation
 *                              is not allowed.
 * \retval   CAL_E_NOT_OK       Request failed
 *
 * \pre The SHA algorithm must be initialized.
 *
 * \post The SHA algorithm is no longer initialized.
 *
 * \remarks  Cpl_SHAFinish has to be called via the interface Cal_HashFinish from the CAL module.
 *
 * \serviceid  0x02
 * \reentrancy Reentrant
 *
 * \swsid SWS_Cpl_0025
 */
/*----------------------------------------------------------------------------*/

FUNC(Cal_ReturnType, Cpl_CODE) Cpl_SHAFinish(
   P2CONST(void, AUTOMATIC, Cpl_APPL_DATA) CfgPtr,
   Cal_HashCtxBufType                      Ctx,
   P2VAR(uint8, AUTOMATIC,  Cpl_APPL_DATA) resultPtr,
   P2VAR(uint32, AUTOMATIC, Cpl_APPL_DATA) resultLengthPtr,
   boolean                                 truncationAllowed)
{
   Cal_ReturnType                            RetVal    = CAL_E_NOT_OK;

   /* MISRA-C:2004 Rule 11.4: see MISRA Deviations */
   /* PRQA S 0310 2 */
   P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_VAR) locSHACtx =
            (P2VAR(Cpl_SHACtxType, AUTOMATIC, Cpl_VAR)) Ctx;

   if ( (NULL_PTR              != CfgPtr          ) &&
        (NULL_PTR              != Ctx             ) &&
        (NULL_PTR              != resultPtr       ) &&
        (NULL_PTR              != resultLengthPtr ) &&
        (CPL_SHA_S_INITIALIZED == locSHACtx->State)
      )
   {
      /* Store data into context */
      locSHACtx->Result            = resultPtr;
      locSHACtx->ResultLengthPtr   = resultLengthPtr;
      locSHACtx->TruncationAllowed = truncationAllowed;

      /* Set state of the state machine to finish */
      locSHACtx->ProcessInputState = CPL_SHA_S_PROCESS;

      locSHACtx->ErrorCode         = CAL_E_OK;

      /* Pad the buffer */

      /* initialize the Pad block */
      locSHACtx->SHAPad[0] = (uint8)0x80;
      locSHACtx->length[0] = (uint8)1;
      do
      {
         locSHACtx->SHAPad[locSHACtx->length[0]] = (uint8)0;
         ++locSHACtx->length[0];
      }
      while (locSHACtx->length[0] < (uint8)CPL_SHA_BLOCK_LEN_BYTES);

      /* 1. convert length information */
      Cpl_SHACountConvert(locSHACtx->Count, locSHACtx->length);

      /* 2. append padding to the context.Common.result_context */
      locSHACtx->Data = locSHACtx->SHAPad;

      locSHACtx->DataLength =
         (
            ((CPL_SHA_BLOCK_LEN_BYTES - 9U) - (locSHACtx->Count)) &
            ((uint32)0x3fUL)
         ) +
         (uint32)1U;

      while(Cpl_SHAProcessInput(locSHACtx) == FALSE)
      {
      }

      locSHACtx->ProcessInputState = CPL_SHA_S_PROCESS;

      /* 3. append length information and complete last block */
      locSHACtx->Data       = locSHACtx->length;
      locSHACtx->DataLength =  8U;

      while(Cpl_SHAProcessInput(locSHACtx) == FALSE)
      {
      }

      /* 4. export context buffer.Common.result to user */
      Cpl_SHAExport(locSHACtx);

      RetVal = locSHACtx->ErrorCode;
   }

   locSHACtx->State = CPL_SHA_S_IDLE;
   return ( RetVal );
} /* end of function Cpl_SHAFinish */

/* PRQA S 5087 2 */
#define Cpl_STOP_SEC_CODE
#include "Cpl_MemMap.h"

#else /* #if (CPL_SHA_CODE_ENABLED == STD_ON) */

/**
 * \brief Dummy type definition to prevent an empty translation unit in case no SHA Hash is
 *        configured.
 */
typedef void CplPrvntEmptyTranslationUnit_t;

#endif /* #if (CPL_SHA_CODE_ENABLED == STD_ON) #else */

/*--- End of file ------------------------------------------------------------*/
