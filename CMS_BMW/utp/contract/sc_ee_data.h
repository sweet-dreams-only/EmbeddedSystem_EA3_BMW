/* Specific items from the sc_ee_data.h and supporting information */

typedef struct global_com2                         /* type for RNG registers  */
{
   uint32 reg_a[2];                                /* reg a                   */
   uint32 reg_b[2];                                /* reg b                   */
} CR_C_s2_t;


typedef struct
{
#ifdef BOOTLOADER
   uint8     RANDOM      [RANDOMLENGTH];       /* Seed for the pseudo for SC6 */
#else
   CR_C_s2_t RANDOM;                           /* Seed for the pseudo         */
#endif
   uint8     ApplicStartedFirst;               /* Indication of first start   */
   uint8     FingerPrint [FINGERPRINTLENGTH];  /* FingerPrint                 */
   uint8     VIN         [VINLENGTH];          /* Vehicle Identification      */
} BootProgDataType;


extern VAR(BootProgDataType, COMMON_VAR) BootProgData;

#define FINGERPRINTLENGTH             13u
 #define SWECLASSIFICATIONLENGTH           1u
#define SWELOGISTICIDENTIFIERLENGTH       4u
#define SWESOFTWAREVERSIONLENGTH          3u
#define NUMBEROFHWESGBMIDS                2u
#define SWENUMBEROFBOOTSWE                      0x01u
#define SWENUMBEROFAPPLSWE                      0x03u
#define SWENUMBEROFALLSWE                       (SWENUMBEROFBOOTSWE +       \
                                                 SWENUMBEROFAPPLSWE)

#define SGBM_ID_LENGTH ( SWECLASSIFICATIONLENGTH +                             \
                         SWELOGISTICIDENTIFIERLENGTH +                         \
                         SWESOFTWAREVERSIONLENGTH                              \
                       )

#define SVK_BACKUP_SIZE ( 4u + FINGERPRINTLENGTH + (SGBM_ID_LENGTH *           \
                          (NUMBEROFHWESGBMIDS + SWENUMBEROFALLSWE))            \
                        )


typedef struct
{
   uint8 SvkLockedStatus;                          /* SysSupplier and Plant   */
                                                   /* entries can be locked   */
                                                   /* by this flag            */
   #if (NUMBEROFSVKBACKUPS > 0u)
      uint8 SvkBackupFIFOCounter;                  /* Svk Backup as FIFO      */
   #endif
   /* Nxtr Patch
    * Date: 3/19/15
    * Applied By: K. Smith
    * Reason: Removed #ifdef BOOTLOADER check and #endif. We are reading the SVKhistory
    * into RAM, and the size defined in NvM is larger then what is defined in RAM.
    */
   /* #ifdef BOOTLOADER */
   uint8 SvkSysSupp [SVK_BACKUP_SIZE];             /* system supplier SVK     */
   uint8 SvkPlant   [SVK_BACKUP_SIZE];             /* plant SVK               */
   #if (NUMBEROFSVKBACKUPS > 0u)                   /* Svk Backup as FIFO      */
      uint8 SvkBackup[NUMBEROFSVKBACKUPS][SVK_BACKUP_SIZE];
   #endif
   /* #endif */ /*BOOTLOADER*/
} SvkHistoryMemoryType;

extern VAR(uint8, NVM_APPL_DATA) Nvm_MtrSuplrByte_Cnt_u8;
extern VAR(SvkHistoryMemoryType, COMMON_VAR) SvkHistoryMemory;

/* For service FEEE 5 */

#define SWE1_SEGMENT_NUMBER_APPL   4
#define SWE2_SEGMENT_NUMBER_APPL   1
#define SWE3_SEGMENT_NUMBER_APPL   1

#define SWE_SEGMENT_NUMBER_APPL                                             \
 SWE1_SEGMENT_NUMBER_APPL,  \
 SWE2_SEGMENT_NUMBER_APPL,  \
 SWE3_SEGMENT_NUMBER_APPL

#define FLASH_SEGMENT_NUMBER_APPL (( SWE1_SEGMENT_NUMBER_APPL +			\
									SWE2_SEGMENT_NUMBER_APPL +			\
									SWE3_SEGMENT_NUMBER_APPL  ) )


#define CALC_REQUIRED_BYTES_FOR_MULTI_BYTE_BIT_ARRAY(elements)                 \
            ( ( ( (elements) - 0x01u ) / 0x08u ) + 0x01u )

#define REQUIRED_SIZE_FLASH_SEGMENT_STATUS                                     \
         CALC_REQUIRED_BYTES_FOR_MULTI_BYTE_BIT_ARRAY(FLASH_SEGMENT_NUMBER_APPL)

/* number of bootloader and application SWEs                               */
#define SWENUMBEROFBOOTSWE                      0x01u
#define SWENUMBEROFAPPLSWE                      0x03u 
#define SWENUMBEROFALLSWE                       (SWENUMBEROFBOOTSWE +       \
                                                 SWENUMBEROFAPPLSWE)

typedef struct
{
   uint8 FlashSegmentStatus   [REQUIRED_SIZE_FLASH_SEGMENT_STATUS];
   uint8 SWEProgrammingStatus [SWENUMBEROFALLSWE];
   uint8 lastProgrammedSegment;
} BootProgStatusType;

extern VAR(BootProgStatusType, COMMON_VAR) BootProgStatus;
