/*******************************************************************************
**                                                                            **
**  SRC-MODULE: nrv2b_stream_inc.c                                            **
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
**  PURPOSE   : NRV stream decompression                                      **
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
** alkühl           A. Kühndel                  Berner und Mattner  **
** q208943     Thomas Weidner          BMW AG                                 **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                           Revision Control History                         **
*******************************************************************************/

/*
* $LastChangedRevision: 69 $
* $LastChangedDate: 2006-09-14 14:04:52 +0200 (Do, 14 Sep 2006) $
* $LastChangedBy: qx32511 $
*/
/*
* ^ MISRA rule 1 violation, MISRA rule 5 violation;
* dollar symbol is needed for automatic log entry generation
*/

/* CR61522 NRV2B: Fehlerhafte Behandlung von Ende-Mustern im Datenstrom (Detection of wrong end pattern) (SC6, identical to CR70047)     */
/* CR70047 NRV2B: Fehlerhafte Behandlung von Ende-Mustern im Datenstrom (Detection of wrong end pattern) (BAC2.1, identical to CR61522) */

/*******************************************************************************
**                            Doxygen-Documentation                           **
*******************************************************************************/

/** \mainpage NRV-B stream decompression module
* \section intro_sec Introduction
* This module provides the functionality necessary for decompressing streams
* of NRV-B compressed data. Usually, but not solely, this module is intended
* for compressed software download to ECU flash memory, in order to save total
* programming time by reducing the data volume to be transmitted via CAN.
* Due to the algorithm used, it is only possible to compress (and thus
* decompress) a contiguous range of memory. Non-contiguous memory ranges must
* be compressed/decompressed separately.
*
* Basic operation is depicted in the diagram following:
*
* \image html operation.png
* 
* Usually, the amount of RAM available in an embedded system is insufficient
* for taking up the compressed data on the whole. Therefore, the data is split
* up and streamed to the target system in smaller packages, which are stored
* to an input buffer.
* The NRV-decompression module decompresses data from the input buffer
* into a temporary output buffer, which must be stored to its final
* destination (e.g. flash memory) by the application.
*
* Both input and temporary output buffer must be provided by the
* application. There are no special requirements about the buffer sizes,
* which may be chosen according to the application needs.
*
* The final data storage location must be readable by the decompression
* engine, as the algorithm reverts to data already decompressed, but already
* taken out of the temporary output buffer.
*
* Since the size ratio of compressed to uncompressed data is indeterminate,
* the moment, the temporary output buffer becomes full, and the moment, the
* input buffer has been consumed will rarely be in sync.
* In order to tell the application what to do next, the decompression
* routine therefore will return - providing a status code - if
* - the input buffer has been consumed and needs to be fed with further
*   stream data
* - the temporary buffer is full and needs to be consumed by the application
*   (e.g. written down to flash memory)
* - the maximum number of bytes per decompression step has been written to the
*   temporary output buffer (only if #NRV2BSTREAM_STEPWISE is set)
* - decompression has finished
* - an error occurred
* \section config_sec Configuration
* Depending on timing constraints and the performance of the CPU used,
* the user needs to decide whether to activate the define switch
* #NRV2BSTREAM_STEPWISE, which will interrupt decompression after a certain
* number of bytes decompressed, in order to gain control for fulfilling
* other tasks (e.g. triggering a watchdog)
*
* Furthermore, a function or a function-like macro must be implemented for
* getting read access to the location, the decompressed data is finally stored
* to.
*
* Please refer to the contents of nrv2b_stream_cfg.h.
* \section usage_sec Usage
* The UML diagrams following depict the usage of the module:
*
* \image html sequence1.png
*
* \image html sequence2.png
*
* \section constr_sec Constraints
* The following constraints must be taken into account:
* - the input buffer content MUST NOT be modified in any way until the
*   decompression engine requests further data
* - the temporary output buffer content MUST NOT be modified in any way until
*   it has been filled completely by the decompression engine, or decompression
*   has
*   finished.
* - The decompressed data at its final location  MUST NOT be modified in
*   any way and MUST be readable during the complete decompression process
*   (see macro #nrv2bStream_ReadFromDestination).
*
* \section bugs_sec Known bugs
* There are no known bugs.
*/


/*******************************************************************************
**                             Include Section                                **
*******************************************************************************/
#include "nrv2b_stream.h"


/*******************************************************************************
**                      Local Symbols and Macros                              **
*******************************************************************************/

/*
* Version check
*/
#if ((NRV2BS_SW_MAJOR_VERSION != 1) || \
			(NRV2BS_SW_MINOR_VERSION != 0))
#error /* Wrong version of nrv2b_stream.h found!! */
#endif

#if ((NRV2BS_CFG_MAJOR_VERSION != 1) || \
			(NRV2BS_CFG_MINOR_VERSION != 0))
#error /* Wrong version of nrv2b_stream_cfg.h found!! */
#endif

/** Dispatch one bit from the current control byte */
#define nrv2b_dispatchControlBit() \
	{                                  \
		controlByte <<= 1;               \
		controlByte  |= 0x100;           \
	}
/*
* ^ MISRA rule 90 violation, because of curly braces;
* however, this declaration _does_ form a function-like macro.
* The rule's underlying intention, to prevent macros being used to define
* statements, part of statements, or to redefine the syntax of the language
* has not been violated at all.
* ^ MISRA rule 93 violation; however, this macro is used in order to maintain
* readability; using a C function instead would significantly slow down
* the algorithm.
*/


/** Get current control bit
*
* Current control bit is the MSB of the control byte  
*/
#define nrv2b_currentControlBit()    (controlByte & 0x80)
/*
* ^ MISRA rule 93 violation; see rationale for nrv2b_dispatchControlBit()
*/

/** Check, if the control byte is exhausted
*
* For each exhausted control bit, one bit in the high byte is
* set. Thus, 0xff means: no more bits left
*/
#define nrv2b_controlBitsExhausted() ((controlByte & (uint16) 0xff00u) == (uint16) 0xff00u)
/*
* ^ MISRA rule 93 violation; see rationale for nrv2b_dispatchControlBit()
*/



/*******************************************************************************
**                             Local Datatypes                                **
*******************************************************************************/
enum
{
	/** directly copy data from input                            */
	NRV2B_STATE_COPY_DIRECT,
	/** extract the offset of a match in the decompressed output */
	NRV2B_STATE_GET_MATCH_OFFSET,
	NRV2B_STATE_GET_MATCH_OFFSET_CHECK,
	/** extract the length of the match found                    */
	NRV2B_STATE_GET_MATCH_LENGTH,
	NRV2B_STATE_GET_MATCH_LENGTH2,
	NRV2B_STATE_GET_MATCH_LENGTH3,
	NRV2B_STATE_GET_MATCH_LENGTH3_CHECK,
	/** copy a match to output                                   */
	NRV2B_STATE_COPY_MATCH,
	/** decompression has finished                               */
	NRV2B_STATE_FINISHED   
};

/*******************************************************************************
**                             Local Variables                                **
*******************************************************************************/
#define NRV2BS_START_SEC_VAR_8BIT
#include "MemMap.h"
/** State of the decompression engine                                         */
_STATIC_ VAR(sint8, AUTOMATIC)      
nrv2b_state      = NRV2B_STATE_FINISHED;
#define NRV2BS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define NRV2BS_START_SEC_VAR_32BIT
#include "MemMap.h"
/** Buffer for compressed input stream                                        */
_STATIC_ P2CONST(uint8,AUTOMATIC,NRV2BS_APPL_DATA)    sourceBuffer     = 0;
/** Temp buffer for decompressed output stream.
* This buffer is intended for flashing one data page
*/
_STATIC_ P2VAR(uint8,AUTOMATIC,NRV2BS_APPL_DATA)      tempBuffer       = 0;
/** Final location of decompressed output data.
* Primary use: flash memory address
*/
_STATIC_ P2CONST(uint8, AUTOMATIC, NRV2BS_APPL_DATA)  destBuffer       = 0;
/** Destination index relative to the absolute target memory                  */
_STATIC_ VAR(uint32, AUTOMATIC)                       destinationIndex = 0;
/*
* ^ MISRA rule 22 violation; destinationIndex is currently used by
* nrv2bStream_Decompress only, technically indicating function sope.
* However, from a logical point of view, module scope is obviously right,
* as modukles-scope access may be neccessary for future extensions.
*/


/** Offset from current destination index for recalling data                  */
_STATIC_ VAR(uint32, AUTOMATIC)                       matchOffset;
/*
* ^ MISRA rule 22 violation; see rationale for destinationIndex
*/
/** Last offset for recalling data from the decompressed steam                */
_STATIC_ VAR(uint32, AUTOMATIC)                       lastMatchOffset  = 0;
/** Lenght of data to be recalled                                             */
_STATIC_ VAR(uint32, AUTOMATIC)                       matchLength;
/*
* ^ MISRA rule 22 violation; see rationale for destinationIndex
*/
#define NRV2BS_STOP_SEC_VAR_32BIT
#include "MemMap.h"


#define NRV2BS_START_SEC_VAR_16BIT
#include "MemMap.h"
/** Stream index relative to the source buffer                                */
_STATIC_ VAR(uint16, AUTOMATIC)                       sourceIndex      = 0;
/** Size of the source buffer                                                 */
_STATIC_ VAR(uint16, AUTOMATIC)                       sourceBufferSize = 0;

/** Stream index relative to the temp buffer                                  */
_STATIC_ VAR(uint16, AUTOMATIC)                       tempIndex        = 0;
/** Size of the temp buffer                                                   */
_STATIC_ VAR(uint16, AUTOMATIC)                       tempBufferSize   = 0;
#define NRV2BS_STOP_SEC_VAR_16BIT
#include "MemMap.h"


#define NRV2BS_START_SEC_VAR_FAST_16BIT
#include "MemMap.h"
/** Current control byte (multiplexed into stream)                            */
_STATIC_ VAR(uint16, AUTOMATIC)                       controlByte      = 0; 
#define NRV2BS_STOP_SEC_VAR_FAST_16BIT
#include "MemMap.h"

/******************************************************************************
**                             Global Functions                              **
*******************************************************************************/
#define NRV2BS_START_SEC_CODE
#include "MemMap.h"


/* #define FUNC(type, memclass)  type memclass */

FUNC(void , NRV2BS_PUBLIC_CODE) nrv2bStream_Init
(
CONSTP2CONST(uint8, AUTOMATIC, NRV2BS_APPL_DATA) source_buffer,
CONST(uint16, AUTOMATIC) source_size,
CONSTP2VAR(uint8, AUTOMATIC, NRV2BS_APPL_DATA) temp_buffer,
CONST(uint16, AUTOMATIC) temp_size,
CONSTP2CONST(uint8, AUTOMATIC, NRV2BS_APPL_DATA) destination
)
{ 
	sourceBuffer     = source_buffer;
	sourceBufferSize = source_size;
	sourceIndex      = 0;

	tempBuffer       = temp_buffer;
	tempBufferSize   = temp_size;
	tempIndex        = 0;

	destBuffer       = destination;
	destinationIndex = 0;

	controlByte      = 0xff00u;
	lastMatchOffset  = 1;  

	nrv2b_state      = NRV2B_STATE_COPY_DIRECT;
}

/*---------------------------------------------------------------------------*/
FUNC(void,NRV2BS_PUBLIC_CODE) nrv2bStream_SignalSourceBufferRefilled
(
CONST(uint16, AUTOMATIC) source_size
)
{

		sourceIndex      = 0;
		sourceBufferSize = source_size;
	}

/*---------------------------------------------------------------------------*/
FUNC(void,NRV2BS_PUBLIC_CODE) nrv2bStream_ProvideNewSourceBuffer
(
CONSTP2CONST(uint8, AUTOMATIC, NRV2BS_APPL_DATA) source_buffer,
CONST(uint16, AUTOMATIC) source_size
)
{
	
		sourceBuffer     = source_buffer;
		sourceBufferSize = source_size;
		sourceIndex      = 0;
	}


/*---------------------------------------------------------------------------*/
FUNC(void,NRV2BS_PUBLIC_CODE) nrv2bStream_ReuseTempBuffer (void)
{
		/*
* The destinatin buffer has been untilized and may be overwritten.
* Therefore, reset destination index and go on
*/
		tempIndex = 0;
}

/*---------------------------------------------------------------------------*/
FUNC(void,NRV2BS_PUBLIC_CODE) nrv2bStream_ProvideNewTempBuffer
(
CONSTP2VAR(uint8, AUTOMATIC, NRV2BS_APPL_DATA) temp_buffer,
CONST(uint16, AUTOMATIC) temp_size
)
{
		/*
* The destinatin buffer has been consumed and thus may be overwritten.
* Therefore, reset destination index and go on
*/
		tempBuffer     = temp_buffer;
		tempBufferSize = temp_size;
		tempIndex      = 0;
}

/*---------------------------------------------------------------------------*/
FUNC(uint16,NRV2BS_PUBLIC_CODE) nrv2bStream_GetTempBufferIndex (void)
{
	return tempIndex;
}

/*---------------------------------------------------------------------------*/
#ifndef NRV2BSTREAM_STEPWISE
FUNC(sint8,NRV2BS_PUBLIC_CODE) nrv2bStream_Decompress (void)
{   
#else
	FUNC(sint8,NRV2BS_PUBLIC_CODE) nrv2bStream_Decompress
	(
	VAR(uint16, AUTOMATIC) bytes_per_step
	)
	{
#endif
		while (1)
		{
			/* check, if there's still state finisherd reached*/
			/* added by A. Kühndel ,  CR61522, CR70047 */
			if(nrv2b_state == NRV2B_STATE_FINISHED)
			{
				return NRVSTREAM_FATAL_ERROR;
			} 
			/* end added by A. Kühndel ,  CR61522, CR70047 */
		/* check, if there's still source data left for processing */
			if(sourceIndex >= sourceBufferSize)
			{
				return NRVSTREAM_SOURCE_BUFFER_EMPTY;
			}    

			/* check, if there's still space left in the temp buffer   */
			if (tempIndex >= tempBufferSize)
			{
				return NRVSTREAM_TEMP_BUFFER_FULL;
			}

			#ifdef NRV2BSTREAM_STEPWISE
			if (!bytes_per_step)
			{
				return NRVSTREAM_PAUSED;
			}
			#endif

			/*
	* For decompression control, data bytes and control bits are
	* multiplexed into data stream.
	* The tream starts with a byte containing 8 control
	* bits, which decide, whether data is directly copied from the
	* input to the output stream, or there's a match within the
	* already decompressed output stream, which allows for copying
	* a certain part.
	* As soon as the control bits are exhausted, a new byte
	* containing 8 control bits will be found n the input stream.
	*/

			/* fetch a new control byte, if control bits have been exhausted */
			if(nrv2b_controlBitsExhausted())
			{
				controlByte = sourceBuffer[sourceIndex++];
			}
			
			/* otherwise process current control bit */
			else
			{
				switch(nrv2b_state)
				{
				case NRV2B_STATE_COPY_DIRECT:
					/* as long as the control bit is true, copy down */
					if(nrv2b_currentControlBit())
					{
						tempBuffer[tempIndex++] = sourceBuffer[sourceIndex++];
						#ifdef NRV2BSTREAM_STEPWISE
						-- bytes_per_step;
						#endif
						++destinationIndex;
					}
					else
					{
						matchOffset = 0x01;
						nrv2b_state = NRV2B_STATE_GET_MATCH_OFFSET;            
					}
					nrv2b_dispatchControlBit();
					/*
			* ^ MISRA rule 54 violation. Since the function-like macro
			* contains encapsulatin in curly braces, no semicolon is needed,
			* but makes the macro invocation look more familiar.
			*/
					break;
					
					
				case NRV2B_STATE_GET_MATCH_OFFSET:
					matchOffset <<= 1;
					if(nrv2b_currentControlBit())
					{
						matchOffset  |= 0x01ul;
					}
					if (matchOffset > (0xffffffUL + 3ul))
					{
						return NRVSTREAM_FATAL_ERROR;
					}
					nrv2b_state = NRV2B_STATE_GET_MATCH_OFFSET_CHECK;
					nrv2b_dispatchControlBit();
					/*
			* ^ MISRA rule 54 violation. See above.
			*/
					break;

					
				case NRV2B_STATE_GET_MATCH_OFFSET_CHECK:
					if (nrv2b_currentControlBit())
					{
						if (2ul == matchOffset)
						{
							matchOffset = lastMatchOffset;
							nrv2b_state = NRV2B_STATE_GET_MATCH_LENGTH;
						}
						else
						{
							matchOffset  -= 3ul;
							matchOffset <<= 8ul;
							matchOffset  |= sourceBuffer[sourceIndex++];

							if (0xffffffffUL == matchOffset)
							{
								/* changed by A. Kühndel, CR61522, CR70047 */
								nrv2b_state = NRV2B_STATE_FINISHED;
								if(sourceIndex < sourceBufferSize)
								{	/* file end not reached */
									return NRVSTREAM_FATAL_ERROR;
								}
								else
								{	/* file end reached */
									/* return number of bytes written to temp buffer */
									return NRVSTREAM_FINISHED;
								}
								/* end changed by A. Kühndel, CR61522, CR70047 */
							}
							else
							{
								matchOffset++;
								lastMatchOffset = matchOffset;
								nrv2b_state     = NRV2B_STATE_GET_MATCH_LENGTH;
							}
						}
					}
					else
					{
						nrv2b_state = NRV2B_STATE_GET_MATCH_OFFSET;
					}
					nrv2b_dispatchControlBit();
					/*
			* ^ MISRA rule 54 violation. See above.
			*/
					break;
					
				case NRV2B_STATE_GET_MATCH_LENGTH:
					matchLength = (controlByte & 0x80) ? 2ul : 0ul;
					nrv2b_state = NRV2B_STATE_GET_MATCH_LENGTH2;
					nrv2b_dispatchControlBit();
					/*
		* ^ MISRA rule 54 violation. See above.
		*/
					break;

				case NRV2B_STATE_GET_MATCH_LENGTH2:
					if (nrv2b_currentControlBit())
					{
						matchLength |= 0x01ul;
					}
					
					if (0ul == matchLength)
					{
						matchLength++;
						nrv2b_state = NRV2B_STATE_GET_MATCH_LENGTH3;
					}
					else
					{
						if (matchOffset > 0xd00ul)
						{
							matchLength++;
						}
						
						if(matchOffset > destinationIndex)
						{
							return NRVSTREAM_FATAL_ERROR;
						}
						
						nrv2b_state = NRV2B_STATE_COPY_MATCH;
					}
					nrv2b_dispatchControlBit();
					/*
		* ^ MISRA rule 54 violation. See above.
		*/
					break;

				case NRV2B_STATE_GET_MATCH_LENGTH3:

					matchLength <<= 1;
					if (nrv2b_currentControlBit())
					{
						matchLength |= 0x01ul;
					}

					nrv2b_state = NRV2B_STATE_GET_MATCH_LENGTH3_CHECK;          
					nrv2b_dispatchControlBit();
					/*
		* ^ MISRA rule 54 violation. See above.
		*/
					break;

				case NRV2B_STATE_GET_MATCH_LENGTH3_CHECK:
					if (nrv2b_currentControlBit())
					{
						matchLength += 2ul;
						if (matchOffset > 0xd00ul)
						{
							matchLength++;
						}
						nrv2b_state = NRV2B_STATE_COPY_MATCH;
					}
					else
					{
						nrv2b_state = NRV2B_STATE_GET_MATCH_LENGTH3;
					}
					nrv2b_dispatchControlBit();
					/*
		* ^ MISRA rule 54 violation. See above.
		*/
					break;
					
				case NRV2B_STATE_COPY_MATCH:
					/* check, if the match is contained by the temp buffer */
					if (matchOffset <= tempIndex)
					{
						/* coppy from temp buffer       */
						tempBuffer[tempIndex] = tempBuffer[tempIndex - matchOffset];
					}
					else
					{
						/* copy from destination buffer */
						tempBuffer[tempIndex] =
						nrv2bStream_ReadFromDestination(destBuffer,
						destinationIndex - matchOffset);
					}
					++tempIndex;
					++destinationIndex;
					#ifdef NRV2BSTREAM_STEPWISE
					--bytes_per_step;
					#endif

					if (!matchLength)
					{
						nrv2b_state = NRV2B_STATE_COPY_DIRECT;
					}
					else
					{
						--matchLength;
					}
					break;
					
					/* added by A. Kühndel, CR61522, CR70047 */
				case NRV2B_STATE_FINISHED:
					break;
					/* end added by A. Kühndel, CR61522, CR70047 */
				default:
					break;
				}
			}
		}
		/*
* ^ MISRA rule 83 violation.
* However, this return path will never be reached due to the while(1) loop.
* Adding a dummy return statement would violate rule 52 (unreachable code),
* even though likely not detected by the MISRA checker.
*/
	}

#define NRV2BS_STOP_SEC_CODE
#include "MemMap.h"
