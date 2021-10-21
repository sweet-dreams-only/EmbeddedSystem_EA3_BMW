/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Date.c                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Routines to parse an encoded date as stored in certificates   **
**              or FSCs.                                                      **
**                                                                            **
**  REMARKS   :                                                               **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.9.0    : 28.11.2006, mg   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Date.h"            /* declarations for the SW data routines */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/


                               /* list of guards to prevent double definition */
#if (defined ASCII_DIGIT_OFFSET)
   #error ASCII_DIGIT_OFFSET already defined
#endif                                     /* if (defined ASCII_DIGIT_OFFSET) */

#if (defined BASIS_YEAR)
   #error BASIS_YEAR already defined
#endif                                             /* if (defined BASIS_YEAR) */

#if (defined BASIS_YEAR_OFFSET_DAYS)
   #error BASIS_YEAR_OFFSET_DAYS already defined
#endif                                 /* if (defined BASIS_YEAR_OFFSET_DAYS) */

#if (defined MONTH_PER_YEAR)
   #error MONTH_PER_YEAR already defined
#endif                                         /* if (defined MONTH_PER_YEAR) */

#if (defined DAYS_IN_FOUR_YEARS)
   #error DAYS_IN_FOUR_YEARS already defined
#endif                                     /* if (defined DAYS_IN_FOUR_YEARS) */

#if (defined FOUR_YEARS)
   #error FOUR_YEARS already defined
#endif                                             /* if (defined FOUR_YEARS) */

#if (defined MINUTES_PER_DAY)
   #error MINUTES_PER_DAY already defined
#endif                                        /* if (defined MINUTES_PER_DAY) */

#if (defined MINUTES_PER_HOUR)
   #error MINUTES_PER_HOUR already defined
#endif                                       /* if (defined MINUTES_PER_HOUR) */

#if (defined DECIMAL_SHIFT)
   #error DECIMAL_SHIFT already defined
#endif                                          /* if (defined DECIMAL_SHIFT) */


#define ASCII_DIGIT_OFFSET 0x30U


#define BASIS_YEAR 1997U            /* basis year for the minutes calculation */
#define BASIS_YEAR_OFFSET_DAYS 1096U       /* the missing days until 1.1.2000 */

#define MONTH_PER_YEAR 12U                    /* the number of month per year */
#define DAYS_IN_FOUR_YEARS 1461U          /* the number of days in four years */
#define FOUR_YEARS 4U                                           /* four years */

#define MINUTES_PER_DAY 1440U                /* the number of minutes per day */
#define MINUTES_PER_HOUR 60U                /* the number of minutes per hour */

#define DECIMAL_SHIFT 10U          /* shift to left in decimal representation */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Constants                                      **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Local Constants                                       **
*******************************************************************************/


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_DateGet                                             **
**                                                                            **
** DESCRIPTION    : Compute the minute representation of a date description.  **
**                                                                            **
** PRECONDITIONS  : - 'Date' shall be a valid pointer (not checked)           **
**                                                                            **
** POSTCONDITIONS :                                                           **
**                                                                            **
** PARAMETER      : Date : pointer to the encoding of the date representation **
**                  DateType : the type of the encoding of the date           **
**                                                                            **
** RETURN         : The minutes elapsed between the 1.1.2000 and the given    **
**                  date, if the given date representation was valid.         **
**                  0, if the given date representation was invalid.          **
**                                                                            **
** REMARKS        : The function can parse dates in UTCTime as defined in     **
**                  X.680, chapter 11.8, dates in Generalized Time as defined **
**                  in X.680, chapter 11.7, or dates in the FSC date format.  **
**                                                                            **
*******************************************************************************/
uint32 Swt_DateGet
(
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR) Date,
   const Swt_DateType                 DateType
)
{
                       /* the current position within the date representation */
   uint8_least Position;

   uint32 year;                                       /* the represented year */
   uint32 month;                                     /* the represented month */
   uint32 day;                                         /* the represented day */
   uint32 hour;                                       /* the represented hour */
   uint32 minute;                                   /* the represented minute */
   uint8  separator;     /* the time zone separator within the representation */
   uint32 offset;

   uint32 result;         /* the minutes elapsed from the 1.1.2000 until Date */

/* The following macro is defined within a block, violating MISRA rule 91.    */
/* But it is needed for memory mapping and the constant definition which is   */
/* framed by the memory mapping needs to be done inside this block or would   */
/* otherwise violate MISRA rule 22.                                           */
#define SWT_START_SEC_CONST_16BIT
#include "MemMap.h"
   SWT_STATIC_VAR const uint16 DaysUntilMonth[MONTH_PER_YEAR] =
                       {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
#define SWT_STOP_SEC_CONST_16BIT
#include "MemMap.h"

   /* Parse the date representation                                           */
   Position = 0;

   /* Get year                                                                */
   if ( Swt_DATE_UTC_TIME == DateType )
   {
      /* UTCTime encodes the year in only two bytes. We expect the omitted    */
      /* two bytes to be '0x32' and '0x30', making the year 20XX.             */
      year = ((uint32)0x32 - (uint32) ASCII_DIGIT_OFFSET)
               * (uint32) DECIMAL_SHIFT;
      year = (year + ((uint32)0x30 - (uint32) ASCII_DIGIT_OFFSET))
               * (uint32) DECIMAL_SHIFT;
   }
   else
   {
                  /* process year from left to right performing decimal shift */
      year = ((uint32) Date[Position++] - (uint32) ASCII_DIGIT_OFFSET)
               * (uint32) DECIMAL_SHIFT;
      year = (year + ((uint32) Date[Position++] - (uint32) ASCII_DIGIT_OFFSET))
               * (uint32) DECIMAL_SHIFT;
   }

   year = (year + ( (uint32) Date[Position++] - (uint32) ASCII_DIGIT_OFFSET))
            * (uint32) DECIMAL_SHIFT;
   year += ((uint32) Date[Position++] - (uint32)ASCII_DIGIT_OFFSET);

   if( ( year > (uint32)9999 ) || ( year < (uint32)2000) )
   {
      return 0;
   }

   /* Get month                                                               */
                 /* process month from left to right performing decimal shift */
   month = ( (uint32)Date[Position++] - (uint32)ASCII_DIGIT_OFFSET)
             * (uint32)DECIMAL_SHIFT;
   month += ( (uint32)Date[Position++] - (uint32)ASCII_DIGIT_OFFSET);

   if( ( month > (uint32)MONTH_PER_YEAR ) || ( 0 == month ) )
   {
      return 0;
   }

   /* Get day                                                                 */
                   /* process day from left to right performing decimal shift */
   day = ( (uint32)Date[Position++] - (uint32)ASCII_DIGIT_OFFSET)
            * (uint32)DECIMAL_SHIFT;
   day += ( (uint32)Date[Position++] - (uint32)ASCII_DIGIT_OFFSET);

   if( ( day > (uint32)31 ) || ( 0 == day ) )
   {
      return 0;
   }

   /* Get hour                                                                */
                 /* process hours from left to right performing decimal shift */
   hour = ( (uint32)Date[Position++] - (uint32)ASCII_DIGIT_OFFSET)
            * (uint32)DECIMAL_SHIFT;
   hour += ( (uint32)Date[Position++] - (uint32)ASCII_DIGIT_OFFSET);

   if( hour > (uint32)24 )
   {
      return 0;
   }

   /* Get minute                                                              */
                                        /* process minutes from left to right */
   minute = ( (uint32)Date[Position++] - (uint32) ASCII_DIGIT_OFFSET)
               * (uint32)DECIMAL_SHIFT;
   minute += ( (uint32)Date[Position++] - (uint32) ASCII_DIGIT_OFFSET);

   if( minute > (uint32)59 )
   {
      return 0;
   }

   if ( Swt_DATE_FSC_TIME != DateType )
   {
      /* This date type contains two bytes which encode seconds. Ignore the   */
      /* seconds bytes.                                                       */
      Position += 2;

      /* Check whether there are fractions of a second. */
      if( ('.' == Date[Position] ) || (',' == Date[Position]) )
      {
         /* Skip all fractional values until the separator is reached. */
         do
         {
            Position++;
         }
         while ( ( (Date[Position] != 'Z')   &&
                   (Date[Position] != '+') ) &&
                   (Date[Position] != '-') );
      }

      if( Date[Position] != 'Z' )
      {
         /* Encoding must end with a 'Z'. */
         return 0;
      }
   }

   /* Get separator ('+', '-', or 'Z')                                        */
   separator = Date[Position++];

   /* Handle time zone */
   switch(separator)
   {
      case '+':
      case '-':
         /* The hours of the time zone offset */
         offset = ( (uint32)Date[Position++] - (uint32)ASCII_DIGIT_OFFSET)
                  * (uint32)DECIMAL_SHIFT;
         offset += ( (uint32)Date[Position++] - (uint32)ASCII_DIGIT_OFFSET);

         offset *= (uint32)60;

         /* The minutes of the time zone offset */
         offset += ( (uint32)Date[Position++] - (uint32)ASCII_DIGIT_OFFSET)
                  * (uint32)DECIMAL_SHIFT;
         offset += ( (uint32)Date[Position] - (uint32)ASCII_DIGIT_OFFSET);

         if( offset > (uint32)720 )
         {
            /* The time zone offset can be no more than half a day, which is  */
            /* 720 minutes.                                                   */
            return 0;
         }
         break;

      case 'Z':
         offset = 0;
         break;

      default:
         /* This is an unrecognized separator */
         return 0;
   }

   /* Calculate minutes since 1.1.2000                                        */
   result = year;
   result -= (uint32) BASIS_YEAR;
   result *= (uint32) DAYS_IN_FOUR_YEARS;
   result /= (uint32) FOUR_YEARS;
   result += (uint32) DaysUntilMonth[month- (uint32) 1U];
   result += day;
   result -= (uint32) BASIS_YEAR_OFFSET_DAYS;

   /* Handle leap year in considered year                                     */
   if( ((0 == (year % (uint32)4)) &&
       ((0 != (year % (uint32)100)) || (0 == (year % (uint32)400)) )) &&
       (month > (uint32)2) )
   {
      result++;
   }
   /* Calculate minutes until day                                             */
   result *= (uint32) MINUTES_PER_DAY;
   result += ( hour * (uint32)MINUTES_PER_HOUR );
   result += minute;

   /* Introduce the time zone offset                                          */
   if( '+' == separator )
   {
      result -= offset;
   }
   else
   {
      result += offset;
   }

   return result;
}








































#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/

/*** End of file **************************************************************/
