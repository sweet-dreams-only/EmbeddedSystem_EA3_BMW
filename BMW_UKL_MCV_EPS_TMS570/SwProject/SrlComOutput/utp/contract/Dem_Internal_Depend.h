/* Dem_Internal_Depend.h for QAC */

#define DEM_NUMBER_OF_EVENTS		  91U
#define DEM_NUMBER_OF_INDICATORS	   1U
#define DEM_NUM_INDICATOR_LINKS		  23U
#define DEM_DTCSTATUSBIT_WIR        0x80U
#define THERMAL_LIMIT				  43U

typedef uint8  Dem_EventIdType;
typedef uint8 Dem_IndicatorStatusType;
typedef uint8 Dem_DTCStatusMaskType;

typedef struct
{
   /** Number of events assinged to this indicator */
   Dem_EventIdType Number;
   /** Index in Dem_IndicatorLink[], where the links for this indicators
    ** begin - may be invalid if Number is 0 */
   uint32 StartIdx;
} Dem_IndicatorDescType;


typedef struct
{
   /** Event Id to which this indicator is linked to */
   Dem_EventIdType EventId;
   /** Indicator behaviour (which does not use ::DEM_INDICATOR_OFF) */
   Dem_IndicatorStatusType Behaviour;
} Dem_IndicatorLinkType;

typedef struct
{
   Dem_DTCStatusMaskType    DTCStatusMask[DEM_NUMBER_OF_EVENTS];
                                                    /**< Status of each DTC */
   uint8                    ClearPDTC[(DEM_NUMBER_OF_EVENTS - 1U) / 8U + 1U];
   /**< Bit array to store the condition wheter the pending DTC flag may be
    * cleared at the end of the current/next operation cycle */

   uint8                    EvMemOverflowFlags;
                     /**< Overflow Flags / "Condition Byte" for each origin */
} Dem_NvStatusDataType;

extern VAR(Dem_NvStatusDataType, DEM_VAR_NOINIT) Dem_NvStatusData;

extern CONST(Dem_IndicatorDescType, DEM_CONST) Dem_IndicatorDesc[DEM_NUMBER_OF_INDICATORS];
extern CONST(Dem_IndicatorLinkType, DEM_CONST) Dem_IndicatorLink[DEM_NUM_INDICATOR_LINKS];
extern CONSTP2VAR(Dem_DTCStatusMaskType, DEM_CONST, DEM_VAR_NOINIT)Dem_DTCStatusMasks;

#define DEM_IS_BIT_SET(Byte, Mask)   (((Byte) & (Mask)) != 0U)

#define DEM_IS_EV_ST_BIT_SET(EventId, Mask)    (DEM_IS_BIT_SET(Dem_DTCStatusMasks[(EventId)], (Mask)))