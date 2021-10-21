/***********************************************************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : TMS570LS202x6SFlashLnk.cmd
* Module Description: Linker Command File
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
***********************************************************************************************************************/
/*----------------------------------------------------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec 14 14:58:07 2010
* %version:          EA3#66 %
* %derived_by:       pzswj8 %
* %date_modified:    Wed Nov 27 22:18:43 2013 %
*-----------------------------------------------------------------------------------------------------------------------
*   Date       Rev      Author         Change Description                                                        SCR #
* ---------  --------  -------- ------------------------------------------------------------------------------  --------
* 06/01/12      3       JJW     Updates to fill Flash regions to provide contiguous regions for nowECC

* 12/07/10      1.0     JJW     Initial Creation
* 12/22/10      2.0     JJW     Allocated Calibrations to RAM to support tuning.
* 12/22/10      3.0     JJW     Corrected Calibration RAM allocation
* 01/18/11      4.0     Ash     Memory Arch change for multiple SWEs                                              CR3722
* 01/19/11      5.0     Ash     Move HWDESC to BM                                                                 CR3722
* 01/20/11      5.0     Ash     Correct start of memory for HWDESC                                                CR3722
* 01/24/11      6.0     JJW     Correct vector table locations                                                    CR3722
* 01/26/11      7.0     JJW     Correctet RAM length to 160k
* 02/01/11      8.0     JJW     Move HWEL Table to RAM
* 02/01/11      10.0    JJW     Added fill character in memory regions
* 02/07/11      11.0    JJW     removed fill character from BTLD and BMGR memory regions to prevent overlapping 
*                               sections with the BMGR and BTLD projects.
* 02/09/11      12.0    JJW     Added crc table commands
* 03/22/11      13.0    JJW     Moved .cinit and .pinit into the CRC table
* 04/15/11      14      JJW     Added allocation of FlashCalSeg and RamCalSeg
* 04/15/11      16      SMW     Added crypto CryNoInitRng CryNoInitMd5, CryNoInitAsym, CryNoInitCanc
* 04/15/11      17      JJW     Reduced RAM are to ensure it does not ovelay the FTU
* 05/13/11      18      JJW     Remvoed explicit metrics cals obj placement
* 06/07/11      19      LWW     Fixed ResetCause flag to fixed address right before FTU RAM to allow bootmanager 
*                               to not have access to this RAM address.
* 08/02/11      20      JJW     reset vector section rename for BAC3.0 Os and added noload for HwDESC RAM for 
*                               correctness
* 08/03/11      21      JJW     Corrected reset vector location
* 09/14/11      23      JJW     Changes to support SafeContext Os integration Increased RAM size due to 
*                               inefficiency in MPU regions. 
*                               Added allocation of new Os sections 
*                               Removed memory regions for Bootloader/Bootmanager to prevent allocation of 
*                               application memory to those areas
* 09/24/11      24     JJW      Updates for shared Boot Application MPU alignment
* 09/30/11      25     JJW      Update .CAL_RAM for MPU alignment to allow XCP write access by user application.
* 10/04/11      26     JJW      Added CCT symbol for Os Config data CRC
* 10/09/11      26.1.1 LWW      Moved sysmem to be in mpu accessable area
* 10/10/11      27     JJW      Add allocation .FlashCal2Seg
* 10/10/11      28     JJW      Merged parallel files
* 12/19/11      30     SMW      Removed linker symbols for checking Cal ECC region.
* 12/19/11      31     JJW      Added Fill character for application regions
*                               Exteneded Ecc calc region to include full 2MB
* 01/07/12      32     JJW      Removed Ecc Update Features
* 01/24/12      33     JJW      Re-introduced Ecc Update Features
* 02/02/12      35     JJW      Added RAM location for NHET2
* 05/30/12      36     JJW      Removed EccPrg module, which allowed the Fapi lib
*                               allocation in RAM to be removed and the state flag
* 08/07/12      37,38  KJS      Updates to linker for CRC checks for FDD34B
* 08/08/12      39     KJS      Removed CRC2 for bootloader. Reconfigured CRC1 for entire bootloader area. 
* 08/20/12      40,41  KJS      Updated CRC section for the bootloader, removed extra fill from CRC section for 
*                               the BL.
* 08/20/12      42     KJS      Removed group 2 (around sections .text, .const, etc)
* 09/29/12      43     KJS      Added tuning select support
* 10/01/12      44     JJW      Os v5.04 integration: allocation of new (.ossctxdata) data section
*                               allocation correction to move (.osconst) to Flash
* 10/01/12      45     JJW      CalRam removal to support increased number of task stacks for
*                               Nxtr BMW safety concept.
* 10/14/12      46     KJS      Added CalRAM back in to support tuning needs.
* 12/04/12      47     JJW      Added .noclear RAM section
* 02/22/13      48     KJS      Added support for new calibration structure for BMW. 
* 03/08/13      50     KJS      Added support back for calibrations in CAL_RAM.
* 03/13/13      51     KJS      Reduced RAM usage to 128K, added support for tuning activities.
* 05/02/13      52     JJW      Changed end of application alignment to meet CRC block alignment
*                               critera.  Moved osvtable into general APP_FLASH memory region because
*                               it is not required to be at a fixed location and moving it allowed
*                               the proper alignment of the end of application crc region.
* 06/26/13      53     KJS      Added build constant for putting calibrations into RAM.
* 08/19/13      55     KJS      Update memory sections for 768K migration.
* 09/06/13      56     KJS      Update sections for calibration allocation Rev5 (removed tuning sets/pers that 
*                               were not needed)
* 10/29/13      57     KJS      Update sections for calibration allocation Rev8 and updated memory map layout 
*                               for 768K
* 11/26/13      58     KJS      Updated Dummy fill to fill the regions left by calibrations that are no longer 
*                               between the 768K and 1MB limits.
* 06/04/14      59     KJS      Added no load to bootloader section to prevent section overlaps
* 09/02/14      61     KJS      Removed support for SWE3 CVN table for Edch/OBD
* 12/09/14      61     AS       GliwaT1 component integration
* 03/23/15      64     KJS      Added global share section to .data for anomaly 7294 correction                  CR12922
* 10/05/16      65     ABS      Authentication and Signature changes - 2048bit key and SHA256 hash		  		EA3#7986
* 11/02/16      66     ABS      updated for Torque Overlay updates		  										EA3#11165

*---------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Linker Settings                                                                                                    */
/*--------------------------------------------------------------------------------------------------------------------*/
--retain="*(.intvecs)"

/*--------------------------------------------------------------------------------------------------------------------*/
/* CVN Definition Table                                                                                               */
/*--------------------------------------------------------------------------------------------------------------------*/

/* For OBD and the Edch component, the CVN definition table must be defined in memory that is not included with CRC
   calculation by the SWE-generator. Also, since the CVN definition contains the reference CVN checksum, the common
   checksum tool also cannot checksum this area since it can change during flashing. The table format is shown below.
   It is configured the same as the flash sectors configured for flashing the application. Values for this table are
   populated by SWE-Generator 3.8.

   For BUKL_19.xx.xx and later, the application checksum was defined in 4 blocks. Which makes the CVN table 40 bytes
   in size. For the calibration sections, 1 block is used, so the size is 16 bytes.

   +================================+=====================================================================================================+
   | CHECKSUM_TABLE_BLOCK_N_END     | (Byte 7 + ((2 * (N + 1) - 1) * sizeof(uint8*)) + 1) to (Byte 7 + (2 * (N + 1) * sizeof(uint8*)))    |
   +--------------------------------+-----------------------------------------------------------------------------------------------------+
   | CHECKSUM_TABLE_BLOCK_N_START   | (Byte 7 + (2 * N * sizeof(uint8*)) + 1) to (Byte 7 + ((2 * (N + 1) - 1) * sizeof(uint8*)))          |
   +--------------------------------+-----------------------------------------------------------------------------------------------------+
   | ...                            |                                                                                                     |
   +--------------------------------+-----------------------------------------------------------------------------------------------------+
   | CHECKSUM_TABLE_BLOCK_0_END     | (Byte 7 + (sizeof(uint8*) + 1)) to (Byte 7 + (2 * sizeof(uint8*)))                                  |
   +--------------------------------+-----------------------------------------------------------------------------------------------------+
   | CHECKSUM_TABLE_BLOCK_0_START   | (Byte 7 + 1) to (Byte 7 + (sizeof(uint8*)))                                                         |
   +--------------------------------+-----------------------------------------------------------------------------------------------------+
   | CHECKSUM_TABLE_BLOCK_CNT       | Byte 4 to 7                                                                                         |
   +--------------------------------+-----------------------------------------------------------------------------------------------------+
   | Referecne CVN                  | Byte 0 to 3                                                                                         |
   +================================+=====================================================================================================+
        Note: For EA3.x applications, sizeof(uint8*) will equal 4 bytes.
*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Memory Regions                                                                                                     */
/*--------------------------------------------------------------------------------------------------------------------*/
MEMORY
{
    /*----------------------------------------------------------------------------------------------------------------*/
    /* Bootmanager (BM)                                                                                               */
    /* Range: 0x0000 0000 - 0x0000 3FFF                                                                               */
    /*----------------------------------------------------------------------------------------------------------------*/
    ROM_BM_CRC        (R)  : origin=0x00003FF8 length=0x00000008 /* BM CRC for use by FlsCrc test                     */
    /* Range 0x0000 4000 - 0x0000 7FFF Not used and is reserved for backwards compatibility with Gladiator parts      */

    /*----------------------------------------------------------------------------------------------------------------*/
    /* Tuning Block2 / SWE3 / BMW Calibration Region                                                                  */
    /* Range: 0x0000 8000 - 0x0000 FFFF                                                                               */
    /*----------------------------------------------------------------------------------------------------------------*/
    CAL2_FLASH        (R)  : origin=0x00008000 length=0x00007DB8 fill=0xFFFFFFFF /* Flash space for BMW calibrations  */
    CAL2_CRC          (R)  : origin=0x0000FDB8 length=0x00000008 fill=0xFFFFFFFF /* CAL2 CRC for use by FlsCrc test   */
    CAL2_CALVERNUM    (R)  : origin=0x0000FDC0 length=0x00000004 fill=0xFFFFFFFF /* Compatibility check value by BM   */
    ROM_SWE3DESC      (R)  : origin=0x0000FDC4 length=0x0000020C fill=0xFFFFFFFF /* SWE3 Description table            */
    ROM_SWE3STAT      (R)  : origin=0x0000FFD0 length=0x00000030 fill=0xFFFFFFFF /* SWE3 Status table                 */

    /*----------------------------------------------------------------------------------------------------------------*/
    /* Tuning Block1 / SWE2 / Nxtr Calibration Region                                                              */
    /* Range: 0x0001 0000 - 0x0001 FFFF                                                                               */
    /*----------------------------------------------------------------------------------------------------------------*/
    CAL1_FLASH        (R)  : origin=0x00010000 length=0x0000FDA8 fill=0xFFFFFFFF /* Flash space for Nxtr cals      */
    CAL1_CVNDEFTBL    (R)  : origin=0x0001FDA8 length=0x00000010 fill=0xFFFFFFFF /* CVN table for use by Edch         */
    CAL1_CRC          (R)  : origin=0x0001FDB8 length=0x00000008 fill=0xFFFFFFFF /* CAL1 CRC for use by FlsCrc test   */
    CAL1_CALVERNUM    (R)  : origin=0x0001FDC0 length=0x00000004 fill=0xFFFFFFFF /* Compatibility check value by BM   */
    ROM_SWE2DESC      (R)  : origin=0x0001FDC4 length=0x0000020C fill=0xFFFFFFFF /* SWE2 Description table            */
    ROM_SWE2STAT      (R)  : origin=0x0001FFD0 length=0x00000030 fill=0xFFFFFFFF /* SWE2 Status table                 */

    /*----------------------------------------------------------------------------------------------------------------*/
    /* Bootloader (BL)                                                                                                */
    /* Range: 0x0002 0000 - 0x0003 FFFF                                                                               */
    /*----------------------------------------------------------------------------------------------------------------*/
    BOOT_CVNDEFTBL    (R)  : origin=0x0003F880 length=0x00000010 /* CVN table for use by Edch                         */
    ROM_BL_CRC1       (R)  : origin=0x0003F890 length=0x00000008 /* BL CRC for use by FlsCrc Test                     */
    ROM_BLSharedData  (R)  : origin=0x0003FAD4 length=0x000002D0 /* Data shared between BL and Application            */
    ROM_CCRYPJUMPT    (R)  : origin=0x0003FDA4 length=0x00000020 /* Table for signature and authentication functions  */
    ROM_BOOTSWEDESC   (R)  : origin=0x0003FDC4 length=0x0000020C /* BL SWE description table                          */
    ROM_BOOTSWESTAT   (R)  : origin=0x0003FFD0 length=0x00000030 /* BL SWE status table                               */

    /*----------------------------------------------------------------------------------------------------------------*/
    /* Application / SWE1 / (App)                                                                                     */
    /* Range: 0x0004 0000 - 0x000B FFFF                                                                               */
    /*----------------------------------------------------------------------------------------------------------------*/
    APP_FLASH        (RX)  : origin=0x00040000 length=0x0007FBC8 fill=0xFFFFFFFF /* EPS Application code              */
    APP_VECTOR       (R)   : origin=0x000BFBC8 length=0x00000020 fill=0xFFFFFFFF /* Interrupt Vector table            */
    APP_PADDING1     (R)   : origin=0x000BFBE8 length=0x000001A8 fill=0xFFFFFFFF
    APP_CVNDEFTBL    (R)   : origin=0x000BFD90 length=0x00000028 fill=0xFFFFFFFF /* CVN table for use by Edch         */
    APP_CRC          (R)   : origin=0x000BFDB8 length=0x00000008 fill=0xFFFFFFFF /* App CRC for use by FlsCrc test    */
    APP_CALVERNUM    (R)   : origin=0x000BFDC0 length=0x00000004 fill=0xFFFFFFFF /* Compatibility check value by BM   */
    ROM_SWE1DESC     (R)   : origin=0x000BFDC4 length=0x0000020C fill=0xFFFFFFFF /* App SWE description table         */
    ROM_SWE1STAT     (R)   : origin=0x000BFFD0 length=0x00000030 fill=0xFFFFFFFF /* App SWE status table              */

    /* Fill region to ensure compatibility between 768K, 1MB, and 2MB parts                                           */
    DUMMY_FILL      (R)    : origin=0x000C0000 length=0x00140000 fill=0xFFFFFFFF

    /*----------------------------------------------------------------------------------------------------------------*/
    /* RAM                                                                                                            */
    /* Range: 0x0800 0000 - 0x0801 FFFF                                                                               */
    /*----------------------------------------------------------------------------------------------------------------*/
    STACKS          (RW)   : origin=0x08000000 length=0x00001400
    RAM_RESERVE1    (RW)   : origin=0x08001400 length=0x00000400 /* 1K reserve for future needs                       */
    RAM_CRYPTO      (RW)   : origin=0x08001800 length=0x00000800 /* 2K allocated for Crypto routines                  */
    RAM_RESERVE2    (RW)   : origin=0x08002000 length=0x00001400 /* 5K reserve for future needs                       */
    RAM_BOOTSTATUS  (RW)   : origin=0x08003400 length=0x00000009 /* Used by BL (size 9) and App (size 8)              */
    RAM_RESERVE3    (RW)   : origin=0x08003409 length=0x00000007 /* 7 Byte reserved for future needs                  */
    ISR_DISPATCH    (RW)   : origin=0x08003410 length=0x00000010 /* Used by BM                                        */
    RAM_RESERVE4    (RW)   : origin=0x08003420 length=0x000004A4 /* Reserve for future needs                          */ 
    RAM_RESETCAUSE  (RW)   : origin=0x080038C4 length=0x00000004 /* Used by BM, BL, BLUP, and Application             */
    RAM_RESERVE5    (RW)   : origin=0x080038C8 length=0x00000738 /* Reserve for future needs                          */
    /* Largest MPU region is 16K. To avoid holes, RAM is located directly on a 16K address boundary                   */
    RAM             (RW)   : origin=0x08004000 length=0x000187D4 /* RAM used by the various software components       */
    CAL_RAM         (RW)   : origin=0x0801C7D4 length=0x0000382C /* RAM for Gliwa and testing needs                   */

    /* NHET RAM Regions                                                                                               */
    NHET2RAM       (RW)    : origin=0xFF440000 length=0x00000800 
    NHETRAM        (RW)    : origin=0xFF460000 length=0x00000800
}

/*--------------------------------------------------------------------------------------------------------------------*/
/* Section Configurations                                                                                             */
/*--------------------------------------------------------------------------------------------------------------------*/
SECTIONS
{
    /*----------------------------------------------------------------------------------------------------------------*/
    /* Direct Address Assignments                                                                                     */
    /*----------------------------------------------------------------------------------------------------------------*/
    .osresetvect > 0x000BFBC4 
    .resetcause  > 0x080038C4

    GROUP > 0x000BFBC8, palign(8)
    {
        .osarmvect
        .fiqarmvect
    }
    
     /* Lock-down the EccPrg CDD state flag into a flash location in the BMGR. The location chosen is the last location 
      * in the allocated region this must be aligned to a 8 byte boundary to align with ECC calculation boundaries */
    .eccprg:stateconst : {} > 0x00007FF8

    /* The following sections have to be locked down as these sections are shared data between the Application 
     * and BL defined in Crypto */
    .CryNoInitRng   : {} > 0x08001800
    .CryNoInitAsym  : {} > 0x08001810
    .CryNoInitCanc  : {} > 0x08001FF0

    .osconfig : LOAD_SIZE(length_temp),
                LOAD_START(CCT_Range_00_Start)
                {
                    CCT_Range_00_BitAddrGran = 8;
                    CCT_Range_00_Category = 300; 
                    CCT_Range_00_Algorithm = 10;
                    /* Last element of the structure is the CRC, so take the ending address and subtract 2 (bytes)*/
                    CCT_Range_00_Length = length_temp - 2; 
                    CCT_Range_00_Address = CCT_Range_00_Start + CCT_Range_00_Length;
                } > 0x00040000  /*  Fixed address used for supplying to the Perl Crc Script not included in the 
                                 *  CrcTable group because it has a Crc  that is calculated post build that would 
                                 *  alter the crc result that the linker calculated for the */


    /*----------------------------------------------------------------------------------------------------------------*/
    /* Flash Memory Region Assignments                                                                                */
    /*----------------------------------------------------------------------------------------------------------------*/
    .osvtable   : { } > APP_FLASH
    .text       : { } > APP_FLASH
    .oscode     : { } > APP_FLASH
    .const      : { } > APP_FLASH
    .pinit      : { } > APP_FLASH
    .cinit      : { } > APP_FLASH
    .osconst    : { } > APP_FLASH
    .startup    : { } > APP_FLASH

    /* SWE description tables */
    .SWE1DESC   : { } > ROM_SWE1DESC
    .SWE1STAT   : { } > ROM_SWE1STAT
    
    .SWE2DESC   : { } > ROM_SWE2DESC
    .SWE2STAT   : { } > ROM_SWE2STAT
    
    .SWE3DESC   : { } > ROM_SWE3DESC
    .SWE3STAT   : { } > ROM_SWE3STAT

    /* Functions are defined by the BL. NOLOAD used so the linker can connect the application to the routines
     * defined by the BL without causing a memory overlap. */
    .CCRYPJUMPT    : { } > ROM_CCRYPJUMPT,   type = NOLOAD {}
    .BLSharedData  : { } > ROM_BLSharedData, type = NOLOAD {}
    .BOOTSWEDESC   : { } > ROM_BOOTSWEDESC,  type = NOLOAD {}
    .BOOTSWESTAT   : { } > ROM_BOOTSWESTAT,  type = NOLOAD {}

    /* Configure all tuning sets and common cals to Nxtr's SWE (Cal1) */
    .FlashCalSeg    : { } > CAL1_FLASH

    /* Assign Turns Counter PIC Code image, and relevant cals to application flash memory */
    .FlashCal2Seg   : { } > APP_FLASH

    /* BM for compatibility between calibrations and application. These symbols provide the location for the versions
     * numbers */
    .AppCalVerVal   : { } > APP_CALVERNUM
    .Cal1VerNum     : { } > CAL1_CALVERNUM
    .Cal2VerNum     : { } > CAL2_CALVERNUM

    /* Edch Cvn definition tables */
    .BootCvnDefTbl  : { } > BOOT_CVNDEFTBL, type=NOLOAD {}
    .AppCvnDefTbl   : { } > APP_CVNDEFTBL
    .Cal1CvnDefTbl  : { } > CAL1_CVNDEFTBL

    /* Tuning set and personality assignments */
    .TunSet0  : { } > CAL1_FLASH
    .TunSet1  : { } > CAL1_FLASH
    .TunSet2  : { } > CAL1_FLASH
    .TunSet3  : { } > CAL1_FLASH
    .TunSet4  : { } > CAL1_FLASH
    .TunSet5  : { } > CAL1_FLASH
    .TunSet6  : { } > CAL1_FLASH
    .TunSet7  : { } > CAL1_FLASH

    .TunPer0 : { } > CAL2_FLASH
    .TunPer1 : { } > CAL2_FLASH
    .TunPer2 : { } > CAL2_FLASH
    .TunPer3 : { } > CAL2_FLASH
    .TunPer4 : { } > CAL2_FLASH
    .TunPer5 : { } > CAL2_FLASH

    /*----------------------------------------------------------------------------------------------------------------*/
    /* RAM Memory Region Assignments                                                                                  */
    /*----------------------------------------------------------------------------------------------------------------*/
    .stack  : {
                _StackSVC_   = .+ (0x0400);
                _StackFIQ_   = .+ (0x0800);
                _StackIRQ_   = .+ (0x0C00);
                _StackUSER_  = .+ (0x1000);
                _StackABORT_ = .+ (0x1200);
                _StackUND_   = .+ (0x1400);
            } > STACKS

    .data   : {
                    #include "./Source/GenDataOS/osobjs_init.inc"
                    *(.osstack)
                    . = align(1024);   /* align to region size 1024 */
                    _osGlobalSharedStartGlobalShared=.;
                    /* Nxtr patch for math library global share requirement */
                    *(.ossGlobalShared)
                    -l=rtsv7R4_T_be_v3D16_eabi.lib (.data)
                    _osGlobalSharedEndGlobalShared=.;
                    . = . + 1;
                    _osGlobalSharedSizeGlobalShared = _osGlobalSharedEndGlobalShared - _osGlobalSharedStartGlobalShared + 1;
                    . = align(1024); /* Use 8 subregions with size 128*/
                } > RAM

    .bss        :   LOAD_END(Lnk_BSS_End),
                    LOAD_START(Lnk_BSS_Start)
                    {
                        #include "./Source/GenDataOS/osobjs.inc"
                        *(.ossctxdata)
                    } > RAM
    
    .noclear    : { } > RAM
    .TOTFCals   : { } > CAL_RAM /* Added to move tune on the fly to this section */

    .BOOTSTATUS     : { } > RAM_BOOTSTATUS
    .ISRDISPATCHFLG : { } > ISR_DISPATCH

    /*----------------------------------------------------------------------------------------------------------------*/
    /* NHET Code                                                                                                      */
    /*----------------------------------------------------------------------------------------------------------------*/
    .HET2CODE   : { e_HETPROGRAM1_UN = .;} > 0xFF440000      /* HET2 PROGRAM */
    .HETCODE    : { e_HETPROGRAM0_UN = .;} > 0xFF460000      /* HET PROGRAM */

    /*----------------------------------------------------------------------------------------------------------------*/
    /* Common Checksum Tool Settings                                                                                  */
    /*----------------------------------------------------------------------------------------------------------------*/
    .CAL2CHECKSUM: > CAL2_CRC
    {
        _CCT_Range_10_Address     = .;
        _CCT_Range_10_Length      = 0x00007DB8;
        _CCT_Range_10_BitAddrGran = 8;
        _CCT_Range_10_Category    = 200;
        _CCT_Range_10_Algorithm   = 12;
        _CCT_Range_10_Start       = 0x00008000;
    }

    .CAL1CHECKSUM: > CAL1_CRC
    {
        _CCT_Range_11_Address 	  = .;
        _CCT_Range_11_Length      = 0x0000FDA0;
        _CCT_Range_11_BitAddrGran = 8;
        _CCT_Range_11_Category    = 200;
        _CCT_Range_11_Algorithm   = 12;
        _CCT_Range_11_Start       = 0x00010000;
    }

    .APPCHECKSUM: > APP_CRC
    {
        _CCT_Range_12_Address     = .;
        _CCT_Range_12_Length      = 0x0007FD90;
        _CCT_Range_12_BitAddrGran = 8;
        _CCT_Range_12_Category    = 300;
        _CCT_Range_12_Algorithm   = 12;
        _CCT_Range_12_Start       = 0x00040000;
    }

    .BOOTMANGRCKSUM: > ROM_BM_CRC
    {
        _CRC_BootMangr_Address   = .;
        _CRC_BootMangr_Start     = 0x00;
    }

    .BOOTLOADER1CKSUM: > ROM_BL_CRC1
    {
        _CRC_BootLoader1_Address = .;
        _CRC_BootLoader1_Start   = 0x00020000;
    }

    /*----------------------------------------------------------------------------------------------------------------*/
    /* Gliwa T1                                                                                                       */
    /*----------------------------------------------------------------------------------------------------------------*/
    .T1_bss             :  { } > CAL_RAM
    .T1_traceBuffer     :  { } > CAL_RAM
    .T1_code            :  { } > APP_FLASH
    .T1_const           :  { } > APP_FLASH
    .T1_alignedCodeFast :  {
                                . = align(16);
                                *(.T1_codeFast:T1_TraceEvent_)
                                . = align(16);
                                *(.T1_codeFast:T1_TraceEventFast_)
                                . = align(16);
                                *(.T1_codeFast:T1_GetTraceTime)
                                . = align(16);
                                *(.T1_codeFast:T1_TraceEventNoSusp_)
                                . = align(16);
                                *(.T1_codeFast)
                            } > APP_FLASH
}
