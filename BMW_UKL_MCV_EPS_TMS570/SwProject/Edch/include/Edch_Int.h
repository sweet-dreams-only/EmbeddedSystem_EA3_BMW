/* --------{ BMW C Source File }-------- */
/* !LINKSTO EDCH_SDD_0025, 1
 */

#ifndef EDCH_INT_H
#define EDCH_INT_H

/*==================[inclusions]==============================================*/

#include <Std_Types.h>           /* AUTOSAR standard types */

/*==================[macros]==================================================*/

/*------------------[Helper macros]-------------------------------------------*/
#if (defined HEX2ASCII)
#error HEX2ASCII is already defined
#endif
/**
 * \brief Helper macro for mapping hex.nibble to ASCII
 */
#define HEX2ASCII(hexval) (((hexval)<0x0AU)?((hexval)+0x30U):((hexval)+0x37U))

#if (defined EDCH_GET_HIHI_BYTE)
#error EDCH_GET_HIHI_BYTE is already defined
#endif
/**
 * \brief Helper macro for get HiHi byte of given 32 bit value
 */
#define EDCH_GET_HIHI_BYTE(data)                ((uint8)(((uint32)(data))>>24U))

#if (defined EDCH_GET_HILO_BYTE)
#error EDCH_GET_HILO_BYTE is already defined
#endif
/**
 * \brief Helper macro for get HiLo byte of given 32 bit value
 */
#define EDCH_GET_HILO_BYTE(data)                ((uint8)(((uint32)(data))>>16U))

#if (defined EDCH_GET_LOHI_BYTE)
#error EDCH_GET_LOHI_BYTE is already defined
#endif
/**
 * \brief Helper macro for get LoHi byte of given 32 bit value
 */
#define EDCH_GET_LOHI_BYTE(data)                ((uint8)(((uint32)(data))>>8U))

#if (defined EDCH_GET_LOLO_BYTE)
#error EDCH_GET_LOLO_BYTE is already defined
#endif
/**
 * \brief Helper macro for get LoLo byte of given 32 bit value
 */
#define EDCH_GET_LOLO_BYTE(data)                ((uint8)(data))

/*------------------[Helper macros for ST_DIAG_OBD_DATA access]-----------*/

/* !LINKSTO EDCH_046, 1
 */
/* !LINKSTO EDCH_047, 1
 */
/* !LINKSTO EDCH_048, 1
 */

#if (defined EDCH_IMME_OF_DIAGNUM)
#error EDCH_IMME_OF_DIAGNUM is already defined
#endif
/**
 * \brief Helper macro for IMME for given diagnostic
 */
#define EDCH_IMME_OF_DIAGNUM(diagNum) ((((diagNum) - 1U) / 8U)  + 4U)

#if (defined EDCH_DATANUM_OF_DIAGNUM)
#error EDCH_DATANUM_OF_DIAGNUM is already defined
#endif
/**
 * \brief Helper macro for event number within ST_DIAG_OBD_DATA for given diagnostic
 */
#define EDCH_DATANUM_OF_DIAGNUM(diagNum) (((diagNum) - 1U) % 8U)

#if (defined EDCH_IPDUBYTE_OF_DIAGNUM)
#error EDCH_IPDUBYTE_OF_DIAGNUM is already defined
#endif
/**
 * \brief Helper macro for byten within ST_DIAG_OBD_DATA for given diagnostic
 */
#define EDCH_IPDUBYTE_OF_DIAGNUM(diagNum) \
(Edch_sendIpduData[EDCH_IMME_OF_DIAGNUM(diagNum)].IpduData[EDCH_DATANUM_OF_DIAGNUM(diagNum)])

#if (defined EDCH_SET_DIAGNUM_FLAGORDER)
#error EDCH_SET_DIAGNUM_FLAGORDER is already defined
#endif
/**
 * \brief Helper macro for set given bit/flag for given diagnostic
 */
#define EDCH_SET_DIAGNUM_FLAGORDER(diagNum,flagOrder) \
  (EDCH_IPDUBYTE_OF_DIAGNUM(diagNum) \
    |= 0x01U << (flagOrder))

#if (defined EDCH_RESET_DIAGNUM_FLAGORDER)
#error EDCH_RESET_DIAGNUM_FLAGORDER is already defined
#endif
/**
 * \brief Helper macro for reset given bit/flag for given diagnostic
 */
#define EDCH_RESET_DIAGNUM_FLAGORDER(diagNum,flagOrder) \
  (EDCH_IPDUBYTE_OF_DIAGNUM(diagNum) \
    &= ~(0x01U << (flagOrder)))

#if (defined EDCH_GET_DIAGNUM_FLAGORDER)
#error EDCH_GET_DIAGNUM_FLAGORDER is already defined
#endif
/**
 * \brief Helper macro for get given bit/flag for given diagnostic
 */
#define EDCH_GET_DIAGNUM_FLAGORDER(diagNum,flagOrder) \
  (EDCH_IPDUBYTE_OF_DIAGNUM(diagNum) \
    & (0x01U << (flagOrder)))  \

#if (defined EDCH_SET_DIAGNUM_FLAGORDER_VAL)
#error EDCH_SET_DIAGNUM_FLAGORDER_VAL is already defined
#endif
/**
 * \brief Helper macro for set given bit/flag to given value for given diagnostic
 */
#define EDCH_SET_DIAGNUM_FLAGORDER_VAL(diagNum,flagOrder,val) \
  (EDCH_IPDUBYTE_OF_DIAGNUM(diagNum) = \
    (EDCH_IPDUBYTE_OF_DIAGNUM(diagNum) & \
      (~(0x01U << (flagOrder)))) | \
       (uint8)((val) << (flagOrder)))

#if (defined EDCH_IMME_OF_DIAGIDX)
#error EDCH_IMME_OF_DIAGIDX is already defined
#endif
/**
 * \brief Helper macro for IMME for given diagnostic index
 */
#define EDCH_IMME_OF_DIAGIDX(diagIdx) EDCH_IMME_OF_DIAGNUM(Edch_Diagnostics_Number[(diagIdx)])

#if (defined EDCH_DATANUM_OF_DIAGIDX)
#error EDCH_DATANUM_OF_DIAGIDX is already defined
#endif
/**
 * \brief Helper macro for for event number within ST_DIAG_OBD_DATA for given diagnostic index
 */
#define EDCH_DATANUM_OF_DIAGIDX(diagIdx) EDCH_DATANUM_OF_DIAGNUM(Edch_Diagnostics_Number[(diagIdx)])

#if (defined EDCH_BYTENUM_OF_DIAGIDX_FLAGORDER)
#error EDCH_BYTENUM_OF_DIAGIDX_FLAGORDER is already defined
#endif
/**
 * \brief Helper macro for for bytenumber within ST_DIAG_OBD_DATA for given diagnostic index
 */
#define EDCH_BYTENUM_OF_DIAGIDX_FLAGORDER(diagIdx,flagOrder) EDCH_BYTENUM_OF_DIAGNUM_FLAGORDER(Edch_Diagnostics_Number[(diagIdx)],(flagOrder))

#if (defined EDCH_BITNUM_OF_DIAGIDX_FLAGORDER)
#error EDCH_BITNUM_OF_DIAGIDX_FLAGORDER is already defined
#endif
/**
 * \brief Helper macro for for bitnumber within right byte of ST_DIAG_OBD_DATA for given diagnostic index
 */
#define EDCH_BITNUM_OF_DIAGIDX_FLAGORDER(diagIdx,flagOrder) EDCH_BITNUM_OF_DIAGNUM_FLAGORDER(Edch_Diagnostics_Number[(diagIdx)],(flagOrder))

#if (defined EDCH_SET_DIAGIDX_FLAGORDER)
#error EDCH_SET_DIAGIDX_FLAGORDER is already defined
#endif
/**
 * \brief Helper macro for set given bit/flag for given diagnostic index
 */
#define EDCH_SET_DIAGIDX_FLAGORDER(diagIdx,flagOrder) EDCH_SET_DIAGNUM_FLAGORDER(Edch_Diagnostics_Number[(diagIdx)],(flagOrder))

#if (defined EDCH_RESET_DIAGIDX_FLAGORDER)
#error EDCH_RESET_DIAGIDX_FLAGORDER is already defined
#endif
/**
 * \brief Helper macro for reset given bit/flag for given diagnostic index
 */
#define EDCH_RESET_DIAGIDX_FLAGORDER(diagIdx,flagOrder) EDCH_RESET_DIAGNUM_FLAGORDER(Edch_Diagnostics_Number[(diagIdx)],(flagOrder))

#if (defined EDCH_GET_DIAGIDX_FLAGORDER)
#error EDCH_GET_DIAGIDX_FLAGORDER is already defined
#endif
/**
 * \brief Helper macro for get given bit/flag for given diagnostic index
 */
#define EDCH_GET_DIAGIDX_FLAGORDER(diagIdx,flagOrder) EDCH_GET_DIAGNUM_FLAGORDER(Edch_Diagnostics_Number[(diagIdx)],(flagOrder))

#if (defined EDCH_SET_DIAGIDX_FLAGORDER_VAL)
#error EDCH_SET_DIAGIDX_FLAGORDER_VAL is already defined
#endif
/**
 * \brief Helper macro for set given bit/flag to given value for given diagnostic index
 */
#define EDCH_SET_DIAGIDX_FLAGORDER_VAL(diagIdx,flagOrder,val) EDCH_SET_DIAGNUM_FLAGORDER_VAL(Edch_Diagnostics_Number[(diagIdx)],(flagOrder),(val))

/*------------------[Access to bits in ST_DIAG_OBD_DATA]----------------------*/

/* !LINKSTO EDCH_047, 1
 */
#if (defined EDCH_TEST_NOT_COMPL_BITORDER)
#error EDCH_TEST_NOT_COMPL_BITORDER is already defined
#endif
/**
 * \brief Position of bit EDCH_TEST_NOT_COMPL whithin diagnostic state sub-signal
 */
#define EDCH_TEST_NOT_COMPL_BITORDER                                       0U

#if (defined EDCH_TEST_FAILED_BITORDER)
#error EDCH_TEST_FAILED_BITORDER is already defined
#endif
/**
 * \brief Position of bit EDCH_TEST_FAILED whithin diagnostic state sub-signal
 */
#define EDCH_TEST_FAILED_BITORDER                                          1U

#if (defined EDCH_TEST_FAILED_CURR_BITORDER)
#error EDCH_TEST_FAILED_CURR_BITORDER is already defined
#endif
/**
 * \brief Position of bit EDCH_TEST_FAILED_CURR whithin diagnostic state sub-signal
 */
#define EDCH_TEST_FAILED_CURR_BITORDER                                     2U

#if (defined EDCH_TEST_ACTIVE_BITORDER)
#error EDCH_TEST_ACTIVE_BITORDER is already defined
#endif
/**
 * \brief Position of bit EDCH_TEST_ACTIVE whithin diagnostic state sub-signal
 */
#define EDCH_TEST_ACTIVE_BITORDER                                          3U

#if (defined EDCH_MONITOR_ENABLED_STATUS_BITORDER)
#error EDCH_MONITOR_ENABLED_STATUS_BITORDER is already defined
#endif
/**
 * \brief Position of bit EDCH_TEST_ACTIVE whithin diagnostic state sub-signal
 */
#define EDCH_MONITOR_ENABLED_STATUS_BITORDER                               4U

/*------------------[Dem diagnostic states]-----------------------------------*/

#if (defined EDCH_DEM_FAILED)
#error EDCH_DEM_FAILED is already defined
#endif
/**
 * \brief Mask of bit FAILED whithin event state reported by Dem
 */
#define EDCH_DEM_FAILED                                                    0x01U

#if (defined EDCH_DEM_FAILED_THIS_OC)
#error EDCH_DEM_FAILED_THIS_OC is already defined
#endif
/**
 * \brief Mask of bit FAILED_THIS_OC whithin event state reported by Dem
 */
#define EDCH_DEM_FAILED_THIS_OC                                            0x02U

#if (defined EDCH_DEM_NOTCOMPL_THIS_OC)
#error EDCH_DEM_NOTCOMPL_THIS_OC is already defined
#endif
/**
 * \brief Mask of bit NOTCOMPL_THIS_OC whithin event state reported by Dem
 */
#define EDCH_DEM_NOTCOMPL_THIS_OC                                          0x40U

#if (defined EDCH_DEM_MASK)
#error EDCH_DEM_MASK is already defined
#endif
/**
 * \brief Mask for bits FAILED, FAILED_THIS_OC and NOTCOMPL_THIS_OC
 * whithin event state reported by Dem
 */
#define EDCH_DEM_MASK (EDCH_DEM_FAILED|\
                       EDCH_DEM_FAILED_THIS_OC|\
                       EDCH_DEM_NOTCOMPL_THIS_OC)


#if (defined EDCH_DEM_FAILED_BITORDER)
#error EDCH_DEM_FAILED_BITORDER is already defined
#endif
/**
 * \brief Position of bit FAILED whithin event state reported by Dem
 */
#define EDCH_DEM_FAILED_BITORDER                                           0U

#if (defined EDCH_DEM_FAILED_THIS_OC_BITORDER)
#error EDCH_DEM_FAILED_THIS_OC_BITORDER is already defined
#endif
/**
 * \brief Position of bit FAILED_THIS_OC whithin event state reported by Dem
 */
#define EDCH_DEM_FAILED_THIS_OC_BITORDER                                   1U

#if (defined EDCH_DEM_NOTCOMPL_THIS_OC_BITORDER)
#error EDCH_DEM_NOTCOMPL_THIS_OC_BITORDER is already defined
#endif
/**
 * \brief Position of bit NOTCOMPL_THIS_OC whithin event state reported by Dem
 */
#define EDCH_DEM_NOTCOMPL_THIS_OC_BITORDER                                 6U

/*------------------[States of diagnostics in event trigger list]-------------*/

#if (defined EDCH_REPORT_NOT)
#error EDCH_REPORT_NOT is already defined
#endif
/**
 * \brief Event trigger state: no event pending - not in list
 */
#define EDCH_REPORT_NOT                                                       0U

#if (defined EDCH_REPORT)
#error EDCH_REPORT is already defined
#endif
/**
 * \brief Event trigger state: event pending
 */
#define EDCH_REPORT                                                           1U

#if (defined EDCH_REPORT_FAIL)
#error EDCH_REPORT_FAIL is already defined
#endif
/**
 * \brief Event trigger state: reporting failure is pending
 */
#define EDCH_REPORT_FAIL                                                      2U

#if (defined EDCH_REPORT_HEAL)
#error EDCH_REPORT_HEAL is already defined
#endif
/**
 * \brief Event trigger state: re-reporting healing failure
 */
#define EDCH_REPORT_HEAL                                                      3U

#if (defined EDCH_REPORT_PRE)
#error EDCH_REPORT_PRE is already defined
#endif
/**
 * \brief Event trigger state: reporting activity change is pending
 */
#define EDCH_REPORT_PRE                                                       4U

/*------------------[State of OBD K15 terminal]----------------------------*/

#if (defined EDCH_K15_NOT_ACTIVE)
#error EDCH_K15_NOT_ACTIVE is already defined
#endif
/**
 * \brief Macro for: Last state of Terminal 15 NOT_ACTIVE
 */
#define EDCH_K15_NOT_ACTIVE                                                   0U

#if (defined EDCH_K15_ACTIVE)
#error EDCH_K15_ACTIVE is already defined
#endif
/**
 * \brief Macro for: Last state of Terminal 15 ACTIVE
 */
#define EDCH_K15_ACTIVE                                                       1U

#if (defined EDCH_K15_ACTIVE_LOWRANGE)
#error EDCH_K15_ACTIVE_LOWRANGE is already defined
#endif
/**
 * \brief lower range for signal KL15 is ACTIVE
 */
#define EDCH_K15_ACTIVE_LOWRANGE                                           0x09U

#if (defined EDCH_K15_ACTIVE_UPPERRANGE)
#error EDCH_K15_ACTIVE_UPPERRANGE is already defined
#endif
/**
 * \brief Upper range for signal KL15 is ACTIVE
 */
#define EDCH_K15_ACTIVE_UPPERRANGE                                         0x0EU

/*------------------[Signals receiving from OBD Host]----------------------*/

#if (defined EDCH_OBD_ZYKLUS_MASK)
#error EDCH_OBD_ZYKLUS_MASK is already defined
#endif
/**
 * \brief Bitmask for subsignal OBD_ZYKLUS
 */
#define EDCH_OBD_ZYKLUS_MASK                                        (UInt6)0x0AU

#if (defined EDCH_OBD_ZYKLUS_START)
#error EDCH_OBD_ZYKLUS_START is already defined
#endif
/**
 * \brief Macro for OBD_ZYKLUS == START
 */
#define EDCH_OBD_ZYKLUS_START                                       (UInt6)0x02U

#if (defined EDCH_OBD_ZYKLUS_STOP)
#error EDCH_OBD_ZYKLUS_STOP is already defined
#endif
/**
 * \brief Macro for OBD_ZYKLUS == STOP
 */
#define EDCH_OBD_ZYKLUS_STOP                                        (UInt6)0x00U

/* !LINKSTO EDCH_357, 1
 */
#if (defined ST_CLEAR_MEM_OFF)
#error ST_CLEAR_MEM_OFF is already defined
#endif
/**
 * \brief Bitmask for subsignal CLEAR_ERROR_MEMORY
 */
#define ST_CLEAR_MEM_OFF                                            (UInt2)0x00U

#if (defined ST_CLEAR_MEM_ON)
#error ST_CLEAR_MEM_ON is already defined
#endif
/**
 * \brief Bitmask for subsignal CLEAR_ERROR_MEMORY
 */
#define ST_CLEAR_MEM_ON                                             (UInt2)0x02U

#if (defined ST_CLEAR_MEM_INVALID)
#error ST_CLEAR_MEM_INVALID is already defined
#endif
/**
 * \brief Bitmask for subsignal CLEAR_ERROR_MEMORY
 */
#define ST_CLEAR_MEM_INVALID                                        (UInt2)0x03U

/*------------------[Checksum calculation]---------------------------------*/

#if (defined EDCH_CHECKSUMTABLE_SIZE)
#error EDCH_CHECKSUMTABLE_SIZE is already defined
#endif
/**
 * \brief Size of checksumtable for CAL-ID and CVN calculation
 */
#if (EDCH_CODINGSW_CNT != 0U)
#define EDCH_CHECKSUMTABLE_SIZE ((EDCH_CVNTABLE_CNT + 1U) * 4U)
#else
#define EDCH_CHECKSUMTABLE_SIZE (EDCH_CVNTABLE_CNT * 4U)
#endif

/*------------------[CAL_ID - CVN ]-------------------------------------------*/

#if (defined EDCH_CALID_DEFAULT_DATA)
#error EDCH_CALID_DEFAULT_DATA is already defined
#endif
/**
 * \brief Default value for CAL-ID and CVN as written in ST_DIAG_OBD_DATA
 */
/* NXTR PATCH START
 * Added 8/22/14 by KJS
 * SCR: 12346 (Anomaly 7156)
 * Patch was applied correcting anomaly 7156, original code is below
 * #define EDCH_CALID_DEFAULT_DATA {0x0FU,0x0FU,0x0FU,0x0FU,0x0FU,0x0FU,0x0FU,0x0FU}
 */
 #define EDCH_CALID_DEFAULT_DATA {0xFFU,0xFFU,0xFFU,0xFFU,0xFFU,0xFFU,0xFFU,0xFFU}
 /* NXTR PATCH END */

/* !LINKSTO EDCH_032, 1
 */
/* !LINKSTO EDCH_037, 1
 */
#if (defined EDCH_CALID_DEFAULT_VAL)
#error EDCH_CALID_DEFAULT_VAL is already defined
#endif
/**
 * \brief Default value for CAL-ID and CVN
 */
#define EDCH_CALID_DEFAULT_VAL 0xFFFFFFFFU

/*------------------[IMME values  ]-------------------------------------------*/

#if (defined EDCH_IMME_CALID)
#error EDCH_IMME_CALID is already defined
#endif
/**
 * \brief IMME for CAL-ID
 */
#define EDCH_IMME_CALID                                                    0x01U

#if (defined EDCH_IMME_CVN)
#error EDCH_IMME_CVN is already defined
#endif
/**
 * \brief IMME for CVN
 */
#define EDCH_IMME_CVN                                                      0x02U

#if (defined EDCH_IMME_DATA_LOW)
#error EDCH_IMME_DATA_LOW is already defined
#endif
/**
 * \brief Lowest IMME contains diagnostic events
 */
#define EDCH_IMME_DATA_LOW                                                 0x04U

#if (defined EDCH_IMME_INVALID)
#error EDCH_IMME_INVALID is already defined
#endif
/**
 * \brief Invalid IMME
 */
#define EDCH_IMME_INVALID                                                  0x3FU

#if (defined EDCH_DIAG2IMME)
#error EDCH_DIAG2IMME is already defined
#endif
/**
 * \brief Count of diagnostic states assigned per IMME
 */
#define EDCH_DIAG2IMME                                                        8U

/*------------------[Event triggered send list]-------------------------------*/

#if (defined EDCH_EVENTTRIGGERLIST_HEAD)
#error EDCH_EVENTTRIGGERLIST_HEAD is already defined
#endif
/**
 * \brief Macro point on first element of event triggered send list
 */
#define EDCH_EVENTTRIGGERLIST_HEAD (Edch_EventTriggerHead.next)

/*------------------[Synch CRC calc]------------------------------------------*/

#if (defined EDCH_CALCODCVN_NO)
#error EDCH_CALCODCVN_NO is already defined
#endif
/**
 * \brief Value for Edch_CalculateCodingCvn_SynchFlag: No calculation
 */
#define EDCH_CALCODCVN_NO                                                  0U

#if (defined EDCH_CALCODCVN_REF)
#error EDCH_CALCODCVN_REF is already defined
#endif
/**
 * \brief Value for Edch_CalculateCodingCvn_SynchFlag: Calculate reference coding CVN
 */
#define EDCH_CALCODCVN_REF                                                 1U

#if (defined EDCH_CALCODCVN_SUB)
#error EDCH_CALCODCVN_SUB is already defined
#endif
/**
 * \brief Value for Edch_CalculateCodingCvn_SynchFlag:  Calculate sub coding CVN
 */
#define EDCH_CALCODCVN_SUB                                                 2U

#if (defined EDCH_CALSUBCVN_INVALID)
#error EDCH_CALSUBCVN_INVALID is already defined
#endif
/**
 * \brief Value for Edch_CalculateSubCvn_SynchFlag:  No calculation
 */
#define EDCH_CALSUBCVN_INVALID                                             0xFFU

/*------------------[Edch reporting timing]-----------------------------------*/

#if (defined EDCH_STOP_IN_SENDCYCLIC)
#error EDCH_STOP_IN_SENDCYCLIC is already defined
#endif
/**
 * \brief Stop cyclical sending due to (re-)initialization
 */
#define EDCH_STOP_IN_SENDCYCLIC                                            0xFFU

/*==================[type definitions]========================================*/

/**
 * \brief Type for count diagnostics
 */
typedef uint16_least Edch_DiagIdxType;

/**
 * \brief Type for count CVN definition blocks
 */
typedef uint16_least Edch_CvnTableCntType;

/* !LINKSTO EDCH_026, 1
 */
/**
 * \brief Type for access CVN definition block
 */
typedef struct Edch_CvnDefBlockStruct{
  uint32 refCvn;
  /**< Pre-calculated reference CVN */
  uint32 tableCnt;
  /**< Count of checksum table blocks */
  CONSTP2CONST(uint8, TYPEDEF, EDCH_APPL_CONST)
         tablePtr; /* overall tableCnt*2 many pointers */
  /**< Pointer to the start of the first checksum table block
   *   CHECKSUM_TABLE_BLOCK_0_START */
}Edch_CvnDefBlockType;

/**
 * \brief Type for pointer of an event trigger list
 */
typedef P2VAR(struct Edch_EventTriggerListStruct, TYPEDEF, EDCH_VAR)
                                                   Edch_EventTriggerListPtrType;

/**
 * \brief Type for elements of an event trigger list
 */
typedef struct Edch_EventTriggerListStruct{
  Edch_EventTriggerListPtrType next;
  /**< next element in the list */
  Edch_EventTriggerListPtrType prev;
  /**< previous element in the list */
  Edch_DiagIdxType idx;
  /**< index of the element within Edch_EventTriggerList */
  uint8 marker;
  /**< actual reporting/processing status of the diagnostic event */
}Edch_EventTriggerListType;

/*------------------[State of OBD operation cycle]----------------------------*/

/* !LINKSTO EDCH_149, 1
 */
/**
 * \brief Type for checksumTable for calculating CRC32 of CAL-ID and CVN
 */
typedef uint8 Edch_ChecksumTableType[EDCH_CHECKSUMTABLE_SIZE];


#if (EDCH_CODINGSW_CNT != 0U)
/* !LINKSTO EDCH_152, 1
 */
/**
 * \brief Type for checksumTable for calculating CRC32 of reference/sub-CVN of coding data
 */
typedef uint8 Edch_CodingChecksumTableType[EDCH_CODINGSWITCH_CRCTABLELEN];
#endif

/**
 * \brief Type for identify and readout an EdchCodingSwitch
 */
typedef struct Edch_CodingSwitchStruct
{
  uint16 tablePos;
  /**< Position of the coding switch within the coding checksum table */
  uint8 blockId;
  /**< ID if the coding block contains the coding switch */
  uint8 startByte;
  /**< Position of the coding switch within the coding block */
  uint8 len;
  /**< Length of the coding switch within the coding block */
  uint8 mask;
  /**< Mask for the relevant bits of the coding switch */
  uint8 rShift;
  /**< Shift the relevant bits of the switch to bit 0 */
}Edch_CodingSwitchType;

/**
 * \brief Type for control asynchronous runs of Edch_CalculateSubCvn
 */
typedef struct Edch_CalculateSubCvn_localStruct
{
  uint32 procLen;
  /**< count of processed bytes in actual block */
  Edch_ChecksumValType subCvn_val;
  /**< calculated checksum */
  uint8 synchflag;
  /**< synchronization flag for asynchron trigger of Edch_CalculateSubCvn */
  uint8 tableIdx;
  /**< index of block actual processed */
  uint8 subCvn_idx;
  /**< actual processed sub CVN */
}Edch_CalculateSubCvn_localType;

/**
 * \brief Type for control asynchronous runs of Edch_CalculateCodingCvn
 */
typedef struct Edch_CalculateCodingCvn_localStruct
{
  uint32 runLen;
  /**< count of actual processed bytes */
  Edch_ChecksumValType codCvn_val;
  /**< calculated checksum */
  uint8 synchflag;
  /**< synchronization flag for asynchron trigger of Edch_CalculateCodingCvn */
  uint8 codCvn_type;
  /**< actual processed coding CVN */
}Edch_CalculateCodingCvn_localType;

/**
 * \brief Type group parameter control the send process in Edch_SendCyclic
 */
typedef struct Edch_SendCyclic_ctrlStruct
{
  uint8 aliveCnt;
  /**< Actual value for ST_DIAG_OBD_ALIVE */
  uint8 wait;
  /**< Counter for wait 500msec (resp. 480msec) before start of the burst mode.
   * The time is counted in "calls of Edch_SendCyclic - 160 msec. */
  uint8 burstImmeIdx;
  /**< Actual index of multiplex part have to send in burst mode */
  uint8 cyclicalImmeIdx;
  /**< Actual index of multiplex part have to send in cyclical mode */
  uint8 cycleTimer;
  /**< Actual 160msec phase within two cyclical send (960msec); Equal 0xFF if no cyclical send mode */
  boolean burstMode;
  /**< Indicate if burst send mode is active or not */
  boolean cyclicalDelayed;
  /**< Indicate if event triggered sending displace an cyclical send */
  UInt6 lastImme;
  /**< The last sended IMME; needed for re-transmission; Initial value EDCH_IMME INVALID indicates no transmission occurred before */
  Std_ReturnType lastSendError;
  /**< The last send error occured */
}Edch_SendCyclic_ctrlType;

/*==================[external function declarations]==========================*/

extern FUNC(void, EDCH_CODE) Edch_GetEventStatus( void );

/*==================[external constants]======================================*/

#define EDCH_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST( Edch_Diagnostics_NumType, EDCH_CONST )
  Edch_Diagnostics_Number[EDCH_DIAGNOSTICS_COUNT];

#define EDCH_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[internal constants]======================================*/

/*==================[external data]===========================================*/

#define EDCH_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* !LINKSTO EDCH_059, 1
 */
extern VAR(Edch_EventStatusIpduDataType, EDCH_VAR)
  Edch_sendIpduData[EDCH_MUX_MAX + 1U];

/* !LINKSTO EDCH_150, 1
 */
extern VAR(Edch_ChecksumTableType, EDCH_VAR) Edch_CalIdChecksumTable;

/* !LINKSTO EDCH_151, 1
 */
extern VAR(Edch_ChecksumTableType, EDCH_VAR) Edch_CvnChecksumTable;

#if (EDCH_CODINGSW_CNT != 0U)
/* !LINKSTO EDCH_153, 1
 */
extern VAR(Edch_CodingChecksumTableType, EDCH_VAR) CodingChecksumTable;
#endif

#define EDCH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*==================[internal data]===========================================*/

/*==================[external function definitions]===========================*/

#define EDCH_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, EDCH_CODE) Edch_Call_NvMBlock_SubCvn_WriteBlock
                                                             (uint8 subCvn_idx);

#if (EDCH_DEV_ERROR_DETECT == STD_ON)
extern FUNC(Std_ReturnType, EDCH_CODE) Edch_CheckNvMStatus( void );
#endif

#define EDCH_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]===========================*/

#endif /* if (!defined EDCH_H) */
/*==================[end of file]=============================================*/

