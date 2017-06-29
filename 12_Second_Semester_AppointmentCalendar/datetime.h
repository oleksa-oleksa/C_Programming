#ifndef DATETIME_H
#define DATETIME_H DATETIME_H

/***************************************************************************
 Checks if the input date is a leap year.
 ***************************************************************************/
int isLeapYear(int year);

/***************************************************************************
 *  Returns the amount of days of the input month.
 ***************************************************************************/
int getDaysOfMonth(TDate date);

/***************************************************************************
 *  Checks if the input date is valid.
 ***************************************************************************/
int isDateValid(TDate date);

/***************************************************************************
 *  Checks if the input time is valid.
 ***************************************************************************/
int isTimeValid(TTime time);

/***************************************************************************
 *  description: Parses the input string into a TDate.
 *  result :     1 if the date is valid, 0 if the date is invalid.
 ***************************************************************************/
int getDateFromString(char *pInput, TDate *pDate);

/***************************************************************************
 *  description: Parses the input string into a TTime.
 *  result :     1 if the date is valid, 0 if the date is invalid.
 ***************************************************************************/
int getTimeFromString(char *input, TTime *time, int sec);


/***************************************************************************
*  prints a TTime one the screen
***************************************************************************/
void printTime(TTime time);

/***************************************************************************

 ***************************************************************************/
void printDate(TDate date);

/***************************************************************************
 *  reads an user´s Input, calls the sub-function for check
 ***************************************************************************/
void getDate(char *pInfoText, TDate *pDate);

/***************************************************************************
 *  reads an user´s Input, calls the sub-function for check
 ***************************************************************************/
void getTime(char *pInfoText, TTime *pTime, int withSeconds, int e);

void addTime(TTime *time, TTime *duration, TTime *end);


#endif

