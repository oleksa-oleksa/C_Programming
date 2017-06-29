#include <stdio.h>
#include "tools.h"

/******** saveDays receives as parameter:
* String with a name of a month
* Amount of a days
* The year
* Array with names of a days
* The Index for a day of a week for a first day of a month (0: Mo, 1: Tu ... )
*
* saveDays has to write all days of a month to a file with a format
* 01. July 2017 (Friday)
* ....
* 31. July 2017 (Sunday)
* ***************/

void saveDays(char *, int, int, char **, int);

int main() {
    char *WeekDays[] = {"Monday", "Tuesday", "Wednesday",
                        "Thursday", "Friday", "Saturday", "Sunday"};


    saveDays("July", 31, 2017, WeekDays, 4); // test case for Friday

}

void saveDays (char *Month, int DaysInMonth, int Y, char **WDays, int D)
{

    FILE *Days = NULL;
    Days = fopen("data/days.txt", "w");

    if (Days)
    {
        for (int i = 1; i <= DaysInMonth; i++)
        {
            fprintf(Days, "%02i. %s %i (%s)\n", i, Month, Y, WDays[(D + i - 1) % 7]);
        }


        fclose(Days);
    }

    else
    {
        printf("File can not be opened...\n");
        waitForEnter();
    }
}