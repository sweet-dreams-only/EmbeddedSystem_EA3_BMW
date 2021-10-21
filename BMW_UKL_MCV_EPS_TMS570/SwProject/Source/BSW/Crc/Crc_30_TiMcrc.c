/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2009 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Crc_30_TiMcrc.c
 *    Component:  DrvCrc_Tms570Timcrc01Asr
 *       Module:  Crc_30_TiMcrc
 *    Generator:  MICROSAR EAD
 *
 *  Description:  Crc module is used to calculate CRC values for data to
 *                ensure data integrity.
 *
 *********************************************************************************************************************/

/* source code file identification */
#define CRC_30_TIMCRC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Crc_30_TiMcrc.h"

#if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
#include "TsxCrc_30_TiMcrc.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if(   (CRC_30_TIMCRC_SW_MAJOR_VERSION != (1u) ) \
    || (CRC_30_TIMCRC_SW_MINOR_VERSION != (0u) ))
#error "Version numbers of Crc_30_TiMcrc.c and Crc_30_TiMcrc.h are inconsistent!"
#endif

#if(   (CRC_30_TIMCRC_CFG_MAJOR_VERSION != (1u) ) \
    || (CRC_30_TIMCRC_CFG_MINOR_VERSION != (0u) ))
#error "Version numbers of Crc_30_TiMcrc.c and Crc_30_TiMcrc_Cfg.h are inconsistent!"
#endif

typedef 
    union
    {
        struct
        {
            uint32  ValueL_u32;
            uint32  ValueH_u32;
        } Split;

        Crc_30_TiMcrc_ValueType Value_u64;
        
} Crc_30_TiMcrc_ExtendedValueType;


#define CRC_30_TIMCRC_START_SEC_CODE
#include "MemMap.h"

static FUNC(void, CRC_30_TIMCRC_CODE) Crc_30_TiMcrc_Write64( P2VAR(uint32, AUTOMATIC, CRC_30_TIMCRC_VAR) DataPtr,
                                                      P2CONST(uint32, AUTOMATIC, CRC_30_TIMCRC_REGISTER) SrcRegAddr,  
                                                      P2CONST(uint32, AUTOMATIC, CRC_30_TIMCRC_REGISTER) CtrlRegAddr );

/*  registers of channel 0 of the MCRC unit */
#define CRC_30_TIMCRC_CRC_CTRL0     ( *((volatile uint32*) (0xFE000000u)) )
#define CRC_30_TIMCRC_CRC_CTRL1     ( *((volatile uint32*) (0xFE000008u)) )
#define CRC_30_TIMCRC_CRC_CTRL2     ( *((volatile uint32*) (0xFE000010u)) )
#define CRC_30_TIMCRC_PSA_SIGREGL0  ( *((volatile uint32*) (0xFE000060u)) )
#define CRC_30_TIMCRC_PSA_SIGREGH0  ( *((volatile uint32*) (0xFE000064u)) )

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Crc_30_TiMcrc_CalculateCRC64
 **********************************************************************************************************************/
/*! \brief      Performs a CRC64 calculation on Crc_Length data bytes, pointed to by Crc_DataPtr,
 *              with the starting value of Crc_StartValue64.
 *  \param[in]  Crc_DataPtr             reference to the data buffer from which the value
 *                                      shall be calculated
 *  \param[in]  Crc_Length              Number of bytes for calculation
 *  \param[in]  Crc_StartValue64        Initial value for calculation
 *  \return     calculated 64bit CRC value
 **********************************************************************************************************************/
FUNC(Crc_30_TiMcrc_ValueType, CRC_30_TIMCRC_CODE) Crc_30_TiMcrc_CalculateCRC64
                                (
                                     P2CONST(uint8, AUTOMATIC, CRC_30_TIMCRC_APPL_DATA) Crc_DataPtr,
                                     uint32 Crc_Length,
                                     Crc_30_TiMcrc_ValueType  Crc_StartValue64
                                )
{
    Crc_30_TiMcrc_ValueType PsaSigReg_Temp;
    VAR(Crc_30_TiMcrc_ExtendedValueType, CRC_30_TIMCRC_CODE) CRC_flipped;
    Crc_30_TiMcrc_ExtendedValueType CRC_value;
    uint32 Counter = (uint32)(0u);  
    
    /* Possibly this call of the service interrupts a former call of the this service
     * so context is saved to be able to continue crc calculation                              */ 
    PsaSigReg_Temp = (*((volatile Crc_30_TiMcrc_ValueType*) (&CRC_30_TIMCRC_PSA_SIGREGL0)));
    #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
        TsxCrc_30_TiMcrc_NestedCallCalCrc64();
    #endif
    CRC_30_TIMCRC_CRC_CTRL0 = ((uint32)(0x1u)); /*  Set CRC-channel 0 to reset state  */
    #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
        TsxCrc_30_TiMcrc_NestedCallCalCrc64();
    #endif
    CRC_30_TIMCRC_CRC_CTRL2 = ((uint32)(0x0u)); /*  Set CRC-channel 0 to Data Capture mode  */
    #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
        TsxCrc_30_TiMcrc_NestedCallCalCrc64();
    #endif
    CRC_30_TIMCRC_CRC_CTRL0 = ((uint32)(0x0u)); /*  Set CRC-channel 0 to active state  */
    #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
        TsxCrc_30_TiMcrc_NestedCallCalCrc64();
    #endif

    /*Initial value set in CRC unit. Wordorder is flipped */
    CRC_30_TIMCRC_PSA_SIGREGL0 = ((Crc_30_TiMcrc_ExtendedValueType*)(&Crc_StartValue64))->Split.ValueH_u32;
    CRC_30_TIMCRC_PSA_SIGREGH0 = ((Crc_30_TiMcrc_ExtendedValueType*)(&Crc_StartValue64))->Split.ValueL_u32;

    #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
        TsxCrc_30_TiMcrc_NestedCallCalCrc64();
    #endif
   
    /* Loop over all input data */
    while( Counter < Crc_Length )
    {
        /* Get the next 8 byte of the data block */
        CRC_value.Value_u64 =(Crc_30_TiMcrc_ValueType) (*((const Crc_30_TiMcrc_ValueType*)(&Crc_DataPtr[Counter]))); 

        /*Flipp the wordorder*/
        CRC_flipped.Split.ValueH_u32=CRC_value.Split.ValueL_u32;
        CRC_flipped.Split.ValueL_u32=CRC_value.Split.ValueH_u32;
         
        /* Fill harware register with a 8 byte block of the input data */
        Crc_30_TiMcrc_Write64( (uint32*)(&CRC_flipped.Value_u64), (const uint32*) (&CRC_30_TIMCRC_PSA_SIGREGL0)
                               ,(const uint32*) (&CRC_30_TIMCRC_CRC_CTRL2));
        #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
            TsxCrc_30_TiMcrc_NestedCallCalCrc64();
        #endif

        Counter+= (uint32)(8u);
    }
    
    /*Retrieve result from CRC register but with flipped Wordorder*/
    CRC_flipped.Split.ValueH_u32=CRC_30_TIMCRC_PSA_SIGREGL0;
    CRC_flipped.Split.ValueL_u32=CRC_30_TIMCRC_PSA_SIGREGH0;


    #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
        TsxCrc_30_TiMcrc_NestedCallCalCrc64();
    #endif   

    CRC_30_TIMCRC_CRC_CTRL0 = ((uint32)(0x1u)); /*  Set CRC-channel 0 to reset state  */
    #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
        TsxCrc_30_TiMcrc_NestedCallCalCrc64();
    #endif
    CRC_30_TIMCRC_CRC_CTRL2 = ((uint32)(0x0u)); /*  Set CRC-channel 0 to Data Capture mode  */
    #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
        TsxCrc_30_TiMcrc_NestedCallCalCrc64();
    #endif
    CRC_30_TIMCRC_CRC_CTRL0 = ((uint32)(0x0u)); /*  Set CRC-channel 0 to active state  */
    #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
        TsxCrc_30_TiMcrc_NestedCallCalCrc64();
    #endif

    /* Restore value of possible interrupted CRC calculation */
    (*((volatile Crc_30_TiMcrc_ValueType*) &CRC_30_TIMCRC_PSA_SIGREGL0)) = PsaSigReg_Temp;
    #if (defined V_CRC_30_TIMCRC_VS_DEVELOPMENT_COMMENT)
        TsxCrc_30_TiMcrc_NestedCallCalCrc64();
    #endif
   
    return CRC_flipped.Value_u64;
}

/***********************************************************************************************************************
 *  Crc_30_TiMcrc_Write64
 **********************************************************************************************************************/
/*! \brief      Function performes a 64-bit copy of from a any valid source address into a special function registers
 *              at once. 
 *  \param[in]  Crc_DataPtr             Start address of the source
 *  \param[in]  RegAddr                 Address of the destination register
 **********************************************************************************************************************/
static FUNC(void, CRC_30_TIMCRC_CODE) Crc_30_TiMcrc_Write64( P2VAR(uint32, AUTOMATIC, CRC_30_TIMCRC_VAR) DataPtr,
                                                      P2CONST(uint32, AUTOMATIC, CRC_30_TIMCRC_REGISTER) SrcRegAddr,  
                                                      P2CONST(uint32, AUTOMATIC, CRC_30_TIMCRC_REGISTER) CtrlRegAddr )
{
    /* Save stack and register content */
    asm(" stmfd sp!, {r3 - r5}"); 
    
    /* Disable all interrupts */
    asm(" mrs r5, CPSR");
    asm(" orr r3, r5, #0xC0");   
    asm(" msr CPSR, r3");

    /* Set the mcrc unit from capture mode to full cpu mode */
    asm(" mov r4, #0x00000003");
    asm(" str r4, [r2]");

    /* Disable branch prediction */
    asm(" mrc   p15, #0, r3, c1, c0, #1");
    asm(" orr   r3,  r3, #0x00030000");
    asm(" mcr   p15, #0, r3, c1, c0, #1");

    /* Write 64-bit value to the given address */
    asm(" dsb"); 
    asm(" ldrd  r3, r4, [r0], #8"); 
    asm(" strd  r3, r4, [r1]"); 

    /* Enable branch prediction */
    asm(" mrc   p15, #0, r1, c1, c0, #1");
    asm(" mvn   r0,  #0x00030000");
    asm(" and   r1, r1, r0");
    asm(" mcr   p15, #0, r1, c1, c0, #1");

    /* Enable all interrupts */
    asm(" msr CPSR, r5");

    /* restore register content */
    asm(" ldmfd sp!, {r3 - r5}"); 


}


/***********************************************************************************************************************
 *  Crc_30_TiMcrc_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief      Writes the version information to the structure referenced by the
 *              parameter 'versioninfo'.
 *  \param[out] versioninfo             reference to the structure to which the
 *                                      version information data should be
 *                                      written to.
 **********************************************************************************************************************/
#if (CRC_30_TIMCRC_VERSION_INFO_API == STD_ON)
FUNC(void, CRC_30_TIMCRC_CODE) Crc_30_TiMcrc_GetVersionInfo
                            (
                                P2VAR(Std_VersionInfoType, AUTOMATIC, CRC_30_TIMCRC_APPL_DATA) versioninfo
                            )
{
    versioninfo->vendorID = CRC_30_TIMCRC_VENDOR_ID;
    versioninfo->moduleID = CRC_30_TIMCRC_MODULE_ID;
    versioninfo->instanceID = CRC_30_TIMCRC_INSTANCE_ID;
    versioninfo->sw_major_version = CRC_30_TIMCRC_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = CRC_30_TIMCRC_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = CRC_30_TIMCRC_SW_PATCH_VERSION;

    return;
}
#endif

#define CRC_30_TIMCRC_STOP_SEC_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *  END OF FILE: REQ_SPEC.C
 *********************************************************************************************************************/

