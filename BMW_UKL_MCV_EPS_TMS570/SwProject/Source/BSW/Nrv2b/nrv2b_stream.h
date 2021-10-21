/******************************************************************************
**                                                                            **
**  SRC-MODULE: nrv2b_stream_inc.h                                            **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : generic                                                       **
**                                                                            **
**  PROJECT   : BMW Function Library                                          **
**                                                                            **
**  AUTHOR    : Markus Franz Xaver Johannes Oberhumer                         **
**              Markus Einsle                                                 **
**                                                                            **
**  PURPOSE   : public interface for the NRV stream decompression             **
**                                                                            **
**  REMARKS   : derived from nrv-V1.183                                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Author Identity                               **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** qx32511      Markus Einsle              Mixed Mode GmbH                    **
**                                                                            **
** AK           Alexander Kühndel          Berner&Mattner                     **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                           Revision Control History                         **
*******************************************************************************/
/* added by A. Kühndel */
/*===============================================================================
 *  Letzte Änderung von: $LastChangedBy: Kuehndel $
 *  Revision           : $LastChangedRevision: 931 $
 * Letzte Änderung am : $LastChangedDate: 2008-11-24 15:19:46 +0100 (Mo, 24 Nov 2008) $
 * Autor              : $Author: Kuehndel $
 * Beschreibung       : Change Request RT-Ticket-15217:
 *                      Anpassungen nrv2bStream_Decompress, change PATCH_VERSION
  ===============================================================================  */
  
/*
 * $LastChangedRevision: 931 $
 * $LastChangedDate: 2008-11-24 15:19:46 +0100 (Mo, 24 Nov 2008) $
 * $LastChangedBy: Kuehndel $
 */


#ifndef NRV2B_STREAM_H
#define NRV2B_STREAM_H
/*******************************************************************************
**                             Include Section                                **
*******************************************************************************/

#include "Std_Types.h"           /* this will also include the platform types */
#ifdef UNIT_TEST
  /* for getting the unit test configuration data                             */
  #include "nrv2b_stream_Unittest_cfg.h"
#else
  #include "nrv2b_stream_cfg.h"  /* for getting the configuration data        */
#endif /* UNIT_TEST */


/*******************************************************************************
**                      Global Symbols and Macros                             **
*******************************************************************************/
/*
 * Module version identification
 */
#define NRV2BS_SW_MAJOR_VERSION  1
#define NRV2BS_SW_MINOR_VERSION  0
#define NRV2BS_SW_PATCH_VERSION  3


/** decompression has paused, because of #NRV2BSTREAM_STEPWISE       */
#define NRVSTREAM_PAUSED                 ( 0)
/** decompression has finished                                       */
#define NRVSTREAM_FINISHED               ( 1)
/** source buffer empty (-> refill buffer)                           */
#define NRVSTREAM_SOURCE_BUFFER_EMPTY    (-1)
/** temporary buffer full (-> consume current or provide new buffer) */
#define NRVSTREAM_TEMP_BUFFER_FULL       (-2)
/** fatal error, decompression failed                                */
#define NRVSTREAM_FATAL_ERROR            (-3)


#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************************
**                            Global Function Prototypes                      **
*******************************************************************************/
#define NRV2BS_START_SEC_CODE
#include "MemMap.h" /* Flexible memory mapping */

/** Initialize the stream decompression engine
  *
  * This function is required to be called before any other function
  * of this module may be used. The buffers must be provided by the calling
  * application.
  *
  * \pre none
  *
  * \param source_buffer  pointer to a source buffer providing compressed data
  * \param source_size    size of the source buffer
  * \param temp_buffer    pointer to a temporary buffer taking the
  *                       uncompressed data
  * \param temp_size      size of the temporary buffer
  * \param destination    physical location, the
  *                       uncompressed data has finally been written to,
  *                       e.g. flash memory.
  */

extern FUNC(void,NRV2BS_PUBLIC_CODE) nrv2bStream_Init
              (
                CONSTP2CONST(uint8, AUTOMATIC, NRV2BS_APPL_DATA) source_buffer,
                CONST(uint16, AUTOMATIC) source_size,
                CONSTP2VAR(uint8, AUTOMATIC, NRV2BS_APPL_DATA) temp_buffer,
                CONST(uint16, AUTOMATIC) temp_size,
                CONSTP2CONST(uint8, AUTOMATIC, NRV2BS_APPL_DATA) destination
              );             
              

/** Signalize, the source buffer has been refilled
  *
  * Whenever the source buffer has been consumed, the decompression engine
  * returns #NRVSTREAM_SOURCE_BUFFER_EMPTY.
  *
  * nrv2bStream_SignalSourceBufferRefilled must be called, after the source
  * buffer has been refilled by the application.
  *
  * \pre nrv2bStream_Init() has been called initially
  * \pre nrv2bStream_Decompress() returned #NRVSTREAM_SOURCE_BUFFER_EMPTY
  * \pre the source buffer has been refilled with valid compressed data
  *
  * \param source_size   number of new bytes provided
  */
extern FUNC(void,NRV2BS_PUBLIC_CODE) nrv2bStream_SignalSourceBufferRefilled
              (
                CONST(uint16, AUTOMATIC) source_size
              );        


/** Provide an alternative source buffer for decompression input
  *
  * This function may be called instead of
  * nrv2bStream_SignalSourceBufferRefilled(), if the former source buffer may
  * not be overwritten and/or the size of the source buffer needs to be changed
  *
  * \pre nrv2bStream_Init() has been called initially
  * \pre nrv2bStream_Decompress() returned #NRVSTREAM_SOURCE_BUFFER_EMPTY
  * \pre the alternative source buffer has been refilled with valid compressed data
  *
  * \param source_buffer   pinter to temporary buffer memory
  * \param source_size     number of bytes provided
  */
extern FUNC(void,NRV2BS_PUBLIC_CODE) nrv2bStream_ProvideNewSourceBuffer
              (
                CONSTP2CONST(uint8, AUTOMATIC, NRV2BS_APPL_DATA) source_buffer,
                CONST(uint16, AUTOMATIC) source_size
              );


/** Signalize, the temporary buffer may be reused
  *
  * Whenever the temporary output buffer has been filled completely, the
  * decompression engine returns #NRVSTREAM_TEMP_BUFFER_FULL.
  *
  * After that, the application must store the buffer's data to its final
  * location (e.g., write down to flash memory), and call this function in 
  * order to signalize, the buffer may be overwritten by the decompression
  * engine.
  *
  * \pre nrv2bStream_Init() has been called initially
  * \pre nrv2bStream_Decompress() returned #NRVSTREAM_TEMP_BUFFER_FULL
  * \pre the temporary output buffer has been stored to its final location
  */
extern FUNC(void,NRV2BS_PUBLIC_CODE) nrv2bStream_ReuseTempBuffer (void);


/** Provide a new temporary buffer for decompression output
  *
  * This function may be called instead of nrv2bStream_ReuseTempBuffer(),
  * if the former output buffer may not be overwritten and/or the size of
  * the temp buffer needs to be changed due to any reason.
  *
  * \pre nrv2bStream_Init() has been called initially
  * \pre nrv2bStream_Decompress() returned #NRVSTREAM_TEMP_BUFFER_FULL
  *
  * \param temp_buffer   pinter to temporary buffer memory
  * \param temp_size     number of bytes provided
  */
extern FUNC(void,NRV2BS_PUBLIC_CODE) nrv2bStream_ProvideNewTempBuffer
              (
                CONSTP2VAR(uint8, AUTOMATIC, NRV2BS_APPL_DATA) temp_buffer,
                CONST(uint16, AUTOMATIC) temp_size
              );


/** Get the temporary buffer's index position
  *
  * After the decompression has finished, the temporary buffer typically is not
  * filled completely, a certain number of unused (and therefore invalid) bytes
  * may exist at the end of the buffer, which need cleaning.
  *
  * \pre none
  *
  * \return the number of valid bytes in the buffer
  */
extern FUNC(uint16,NRV2BS_PUBLIC_CODE) nrv2bStream_GetTempBufferIndex (void);


/** The decompression engine
  *
  * Must be called repeatedly, until the overall input stream has been consumed.
  * The decompression engine keeps on running, until
  * - the source buffer has been consumed and needs to be fed with further
  *   stream data
  * - the temporary buffer is full and needs to be consumed by the application
  *   (e.g. written down to flash memory)
  * - the maximum number of bytes per decompression step has been written to the
  *   temporary output buffer (only if #NRV2BSTREAM_STEPWISE is set, especially
  *   for cooperative multitasking issues).
  * - decompression has finished
  * - an error occurred
  * The function returns, if either the source buffer becomes empty, the
  * temporary buffer is full, the decompression has finished, or an error
  * occured
  *
  * \pre nrv2bStream_Init() has been called initially
  * \pre the source buffer has been filled with valid compressed data
  *
  * \param  bytes_per_step interrupt decompression after the number of bytes
  *                        given. This might be useful on slow target MCUs.
  *                        (only available if #NRV2BSTREAM_STEPWISE is defined)
  * \return #NRVSTREAM_SOURCE_BUFFER_EMPTY, #NRVSTREAM_TEMP_BUFFER_FULL,
  *         #NRVSTREAM_FATAL_ERROR, #NRVSTREAM_PAUSED or #NRVSTREAM_FINISHED
  */
#ifndef NRV2BSTREAM_STEPWISE
extern FUNC(sint8,NRV2BS_PUBLIC_CODE) nrv2bStream_Decompress (void);
#else
extern FUNC(sint8,NRV2BS_PUBLIC_CODE) nrv2bStream_Decompress
              (
                VAR(uint16, AUTOMATIC) bytes_per_step
              );
#endif

#define NRV2BS_STOP_SEC_CODE
#include "MemMap.h" /* Flexible memory mapping */

                
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* NRV2B_STREAM_H */
