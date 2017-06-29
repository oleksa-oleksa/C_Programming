#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "tools.h"
#include "escapesequenzen.h"
#include <math.h>


/***************************************************************************
*  function:    isLeapYear
*  description: Checks if the input date is a leap year.
***************************************************************************/
int isLeapYear(int year)
{
   int isLeapYear;

   if (year % 4 == 0)
    {
       if (year % 100 != 0)
        {
           isLeapYear = 1;
        }

        else if (year % 400 == 0)
        {
           isLeapYear = 1;
        }

        else
        {
           isLeapYear = 0;
        }
    }
    else
    {
       isLeapYear = 0;
    }

   return isLeapYear;
}

/***************************************************************************
*  function:    getDaysOfMonth
*  description: Returns the amount of days of the input month.
***************************************************************************/
int getDaysOfMonth(TDate date)
{
    int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if (date.Month == 2)
    {
       if (isLeapYear(date.Year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
   if (date.Month >= 1 && date.Month <= 12)
    {
       return daysOfMonth[date.Month];
    }
    else
    {
        return 0;
    }
}
/***************************************************************************
*  function:    isDateValid
*  description: Checks if the input date is valid.
***************************************************************************/

int isDateValid(TDate date)
{
   if (getDaysOfMonth(date) && date.Day <= getDaysOfMonth(date) && date.Day > 0 && date.Year >= 0)
    {
        return 1;
    }
    else{
        return 0;
    }
}


/* Checks if the entered year is a leap year, if a 29.02 was entered
*/ // added new Tim

/***************************************************************************
 *  function:    getDateFromString
 *  description: Parses the input string into a TDate.
 ***************************************************************************/
int getDateFromString(char *pInput, TDate *pDate)
{

   int givenDay;
   int givenMonth;
   int givenYear;
   int isValid; //If the given delimiter is valid.
   int intDayOfTheWeek;
   char delimiter = '.';
   char *pDay; //String that holds the number of the day.
   char *pMonth; //String that holds the number of the month.
   char *pYear; //String that holds the number of the year.
   char *pTmp; //String to save a string temporarily

   pDay = pInput;
   pTmp = pInput;

    // Looking for a first non-digit sign and moving a pointer to a month´s side
   while (*pTmp && (*pTmp >= '0' && *pTmp <= '9'))
    {
       pTmp++;
    }

   givenDay = atoi(pDay);

   // checks if the correct delimiter was entered
   isValid = (delimiter == *pTmp);

   pTmp++; // Skips the dots

   pMonth = pTmp;

   while (*pTmp && (*pTmp >= '0' && *pTmp <= '9'))
    {
       pTmp++;
    }

   givenMonth = atoi(pMonth);

   isValid *= (delimiter == *pTmp);

   if (*pTmp == '\0')
   {
        return 0;
    }
   pTmp++; // Skips the dots
   pYear = pTmp;

   givenYear = atoi(pYear);

    if (givenYear < 1583) {
        isValid = 0;// Only Gregorian Dates are allowed
        printf("Das ist zu früh :) Geben Sie das Jahr später als 1583 ein! \n");
    }

   pDate->Day = givenDay;
   pDate->Month = givenMonth;
   pDate->Year = givenYear;

   isValid *= isDateValid(*pDate);

    /********* Determine the day of the week */
    /********* Works only after the year 1582*/
    int a = (14 - givenMonth) / 12;
    int y = givenYear - a;
    int m = givenMonth + 12 * a - 2;
    int x = (7000 + (givenDay + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12));



    intDayOfTheWeek = x % 7;

    switch (intDayOfTheWeek) {
        case 0:
           pDate->DayOfTheWeek = Su;
            break;
        case 1:
           pDate->DayOfTheWeek = Mo;
            break;
        case 2:
           pDate->DayOfTheWeek = Tu;
            break;
        case 3:
           pDate->DayOfTheWeek = We;
            break;
        case 4:
           pDate->DayOfTheWeek = Th;
            break;
        case 5:
           pDate->DayOfTheWeek = Fr;
            break;
        case 6:
           pDate->DayOfTheWeek = Sa;
            break;
        default:
            break;
    }

   if (isValid == 0)
   {
       FORECOLOR_YELLOW;
       printf("Das Datumformat ist falsch.\n");
       ATTRIBUTE_OFF;
   }

   return isValid;

}

/***************************************************************************
*  function:    isTimeValid
*  description: Checks if the input time is valid.
***************************************************************************/
int isTimeValid(TTime time)
{
   if (time.Hour >= 0 && time.Hour <= 23 && time.Minute >= 0 && time.Minute <= 59 && time.Second >= 0 &&
       time.Second <= 59)
        return 1;
    else
        return 0;
}

/***************************************************************************
*  function:    getTimeFromString
*  description: Parses the input string into a TTime.
***************************************************************************/
int getTimeFromString(char *input, TTime *pTime, int withSeconds)
{
    //h = hour, m = minute, s = second
   int hour;
   int minute;
   int second;
   int isValid;
   char delimiter = ':';

   //pHour = pHour, pM = pMinute, pS = pSecond, tmpT = pTmpTime
   char *pHour;
   char *pMinute;
   char *pSecond;
   char *pTmp;

   pHour = input;
   pTmp = input;

   while (*pTmp >= '0' && *pTmp <= '9')
    {
       pTmp++;
    }

    // the (probably) semicolon was found
    // reading the hours
   hour = atoi(pHour);

    // checking if a semicolon stays in a string entered
   isValid = (delimiter == *pTmp);

   pTmp++;
   pMinute = pTmp;

   while (*pTmp >= '0' && *pTmp <= '9')
    {
       pTmp++;
    }

    // the (probably) semicolon was found
    // reading the minutes
   minute = atoi(pMinute);

   if (withSeconds)
   {
        // checking if a semicolon stays in a string entered
      isValid *= (delimiter == *pTmp);

      pTmp++;
      pSecond = pTmp;


        // reading the seconds
      second = atoi(pSecond);
      pTime->Hour = hour;
      pTime->Minute = minute;
      pTime->Second = second;
    }

    else {

      second = 0;
      pTime->Hour = hour;
      pTime->Minute = minute;
      pTime->Second = second;
    }

   isValid *= isTimeValid(*pTime);

   if (isValid == 0)
   {
       printf("Das Zeit- oder Dauerformat ist falsch.\n");
   }


    return isValid;

}

void printTime(TTime time) {
    printf("%02d:%02d", time.Hour, time.Minute);
}


/***************************************************************************
*  function:    getDate
*  description: reads an user´s Input, calls the sub-function for check
***************************************************************************/
void getDate(char *pInfoText, TDate *pDate)
{
   char enteredDate[MAX_CHARS];
   int isValid;

    do
    {
       printf("%s", pInfoText);
       isValid = scanf("%[^\n]s", enteredDate);
        clearBuffer();
       if (isValid)
        {

           isValid *= getDateFromString(enteredDate, pDate);
        }

    } while (!isValid);

}


/***************************************************************************
*  function:    getTime
*  description: reads an user´s Input, calls the sub-function for check
***************************************************************************/
void getTime(char *pInfoText, TTime *pTime, int withSeconds, int isAllowedEmpty)
{
   char enteredDate[MAX_CHARS];
   int isValid;

    do
    {
       printf("%s", pInfoText);
       isValid = scanf("%[^\n]s", enteredDate);
        clearBuffer();

       if (isValid)
        {
           isValid *= getTimeFromString(enteredDate, pTime, withSeconds);
        }

       if (isValid == 0 && isAllowedEmpty)
           isValid = 1;

    } while (!isValid);

}

long long timeToSec(TTime *thisTime)
{
    long long allSeconds = thisTime->Second + 60 * thisTime->Minute + 3600 * thisTime->Hour;
    return allSeconds;
}

void secToTime(long long allSeconds, TTime *end)
{
    int h = allSeconds / 3600;
    int m = (allSeconds - h * 3600) / 60;
    int s = allSeconds - h * 3600 - m * 60;

    end->Hour = h;
    end->Minute = m;
    end->Second = s;
}

void addTime(TTime *time, TTime *duration, TTime *end)
{
    // the overflow after midnight must generate 1 extra day for every 86400 seconds of overflow

    int extraDay = 0; // amount of whole days after midnight
    long long extraSeconds = 0; // amount of seconds after midnight

    long long secBegin = timeToSec(time);
    long long secDuration = timeToSec(duration);

    long long addedSec = secBegin + secDuration;

    if (addedSec > 86399) // if after midnight
    {
        extraDay = ((addedSec - 86400) / 86400) + 1;
        extraSeconds = addedSec - extraDay * 86400;
        secToTime(extraSeconds, end);
    }
    else {
        secToTime(addedSec, end);
    }

}

void printDate(TDate date) {
    char *thisDay[] = {"NotaDay", "Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};
    TDayOfTheWeek dayTest = date.DayOfTheWeek;

   if (dayTest > 7)
     dayTest = NotaDay;
    printf("%s, %02d.%02d.%04d", thisDay[dayTest], date.Day, date.Month, date.Year);

}