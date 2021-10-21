#ifndef CODING_H
#define CODING_H

#define _STATIC_   STATIC
#define CODING_NUMBER_OF_BLOCKS   4u
#define Coding_NvData Coding_NvDataInternal.data
#define SIZEOF_ALL_BLOCKS 155
#define CODING_BLOCK_DESCRIPTORTABLE_INIT \
  { \
	 { /* Area CodingDataSet1 */ \
		0X3000, \
		0, \
		4 \
	 }, \
	 { /* Area CodingDataSet2 */ \
		0X3001, \
		4, \
		4 \
	 }, \
	 { /* Area CafId */ \
		0X3002, \
		8, \
		8 \
	 }, \
	 { /* Area Signature */ \
		0X3003, \
		16, \
		132 \
	 }, \
	 { /* Coding Proof Stamp (CPS) */ \
		0x37FE, \
		148, \
		7 \
	 } \
  }

typedef uint8 Coding_DataOffsetType;

typedef union
{
    uint32 force32BitAlignment;
	uint8  data[SIZEOF_ALL_BLOCKS];
} Coding_NvDataType;

typedef struct
{
	uint16                dataIdentifier;
	Coding_DataOffsetType dataOffset;
	uint8                 dataSize;
} Coding_BlockDescriptorTableType;





_STATIC_ CONST(Coding_BlockDescriptorTableType, CODING_CONST_DESCRIPTOR_TABLE)
    codingBlockDescriptorTable[ CODING_NUMBER_OF_BLOCKS + 1 ] =
      CODING_BLOCK_DESCRIPTORTABLE_INIT;


extern VAR(Coding_NvDataType, CODING_VAR_NVDATA) Coding_NvDataInternal;

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Coding_RequestBlock                                        **
**                                                                            **
** DESCRIPTION   : Calls a callback function that receives the pointer to the **
**                 RAM mirror data of a coding block and its size             **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** PARAMETER     : blockId: the block id of the block                         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This is a asynchronous function.                           **
**                 No additional checks will be done whether the data is      **
**                 valid or not.                                              **
**                                                                            **
*******************************************************************************/
FUNC(void, CODING_PUBLIC_CODE)
     Coding_RequestBlock( Coding_BlockIdType blockId )
{
                                            /* pointer to coding block data   */
   P2VAR( uint8, AUTOMATIC, CODING_VAR_DCMDATA ) pData =
                             &Coding_NvData
                             [ codingBlockDescriptorTable[blockId].dataOffset ];

                                            /* call block receive function    */
   /* Deviation MISRA-1 <START> */
   Coding_Call_CbkBlock_Receive( blockId,
                                 (P2VAR( Coding_BlockDataType, AUTOMATIC, CODING_VAR_NVDATA ))pData, /* Nxtr correction to remove extraneous referencing operator since pData is a pointer to the data */
                                 codingBlockDescriptorTable[blockId].dataSize );
   /* Deviation MISRA-1 <STOP> */
}

#endif
