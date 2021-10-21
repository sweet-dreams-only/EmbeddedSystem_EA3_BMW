/* Dem.h for QAC */

#define FR_COMM_FAILURE                  45U
#  define DEM_EVENT_STATUS_FAILED (1U)

typedef uint8  Dem_EventIdType;
typedef uint8 Dem_EventStatusType;

extern FUNC(void, DEM_CODE) Dem_ReportErrorStatus(
   Dem_EventIdType     EventId,
   Dem_EventStatusType EventStatus);