typedef struct
{
	uint8 Data[66u]; /* Size of the data is the size of the deprecated memory block. Note: that really the data is not in a struct, but just an array (unless you are looking at SVK_HISTORY) */
} SvkSysSuppDeprecated_Type;

typedef struct
{
	uint8 Data[66u]; /* Size of the data is the size of the deprecated memory block. Note: that really the data is not in a struct, but just an array (unless you are looking at SVK_HISTORY) */
} SvkPlantDeprecated_Type;


extern VAR(SvkSysSuppDeprecated_Type, AUTOMATIC) Deprecated_SVK_SYS_SUPP;
extern VAR(SvkPlantDeprecated_Type, AUTOMATIC) Deprecated_SVK_PLANT;