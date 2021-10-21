/* Fr_ERay.h for QAC */

# define CC_ERROR_ERRM_ACTIVE            ((uint32) 0x00000000 )
# define CC_ERROR_ERRM_PASSIVE           ((uint32) 0x00000001 << 1)
# define CC_ERROR_ERRM_COMMHALT          ((uint32) 0x00000001 << 2)
# define CC_ERROR_ERRM_RESERVED          ((uint32) 0x00000001 << 3)
# define CC_ERROR_COLDSTART              ((uint32) 0x00000001 << 4)
# define CC_ERROR_CLOCKCORRECTION        ((uint32) 0x00000001 << 5)
# define CC_ERROR_SYNCFRAME              ((uint32) 0x00000001 << 6)
# define CC_ERROR_SYNTAX_A               ((uint32) 0x00000001 << 7)
# define CC_ERROR_SYNTAX_B               ((uint32) 0x00000001 << 8)
# define CC_ERROR_CHANNEL_A              ((uint32) 0x00000001 << 9)
# define CC_ERROR_CHANNEL_B              ((uint32) 0x00000001 << 10)
# define CC_ERROR_LATESTTX_A             ((uint32) 0x00000001 << 11)
# define CC_ERROR_LATESTTX_B             ((uint32) 0x00000001 << 12)
# define CC_ERROR_SW_A                   ((uint32) 0x00000001 << 14)
# define CC_ERROR_SW_B                   ((uint32) 0x00000001 << 15)
# define CC_ERROR_NIT_A                  ((uint32) 0x00000001 << 16)
# define CC_ERROR_NIT_B                  ((uint32) 0x00000001 << 17)


typedef uint32 Fr_VErrorStatusType;