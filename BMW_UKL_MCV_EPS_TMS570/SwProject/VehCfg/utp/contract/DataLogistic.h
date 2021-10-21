
/* From Bootloader_Cfg.h*/
#define NUMBEROFHWESGBMIDS          2u
#define ECUSERIALNUMBERLENGTH       10u
#define HWEDEVELOPMENTINFOLENGTH          14u

/* From DataLogstic.h */
#define ECUMANUFACTURINGDATALENGTH    0x03u
#define SWECLASSIFICATIONLENGTH           1u
#define SWELOGISTICIDENTIFIERLENGTH       4u
#define SWESOFTWAREVERSIONLENGTH          3u

#define SGBM_ID_LENGTH ( SWECLASSIFICATIONLENGTH +                             \
                         SWELOGISTICIDENTIFIERLENGTH +                         \
                         SWESOFTWAREVERSIONLENGTH                              \
                       )

typedef struct
{
   /* --- logistic data ----------------------------------------------------- */
   uint8 HWESgbmId[SGBM_ID_LENGTH];

   /* --- HWE development Information --------------------------------------- */
   uint8 HWEDevelopmentInfo[HWEDEVELOPMENTINFOLENGTH + 0x01u];
} HweTableType;



typedef struct
{
   /* HardwareLogisticData                                                    */
   HweTableType HweTable[NUMBEROFHWESGBMIDS];
   /* ECUSerialNumber                                                         */
   uint8 ECUSerialNumber[ECUSERIALNUMBERLENGTH];
   /* ECUManufacturingData                                                    */
   uint8 ECUManufacturingData[ECUMANUFACTURINGDATALENGTH];
} HwDescDataType;


extern CONST(HwDescDataType, COMMON_CONST) HwDescData;