#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

typedef struct
{
    int Day;
    int Month;
    int Year;
} TDate;

typedef struct
{
    int Hour;
    int Min;
} TClock;

typedef struct
{
    TDate *Date;
    TClock *clockTime;
} TTime;

/***+** This is what student has to write ***/

int setTime(TTime *, int, int, int, int, int);

void showTime(TTime);

void freeTime(TTime);

/****** End of declarations **/

int main()
{
    TTime Time1;
    TTime *Time2 = NULL;

    // test case 20.07.2017; 08:00 o'clock
    if (setTime(&Time1, 20, 7, 2017, 8, 0))
    {
        showTime(Time1);
        freeTime(Time1);
    }

    Time2 = malloc(sizeof(TClock));

    if (Time2 != NULL)
    {
        // test case 24.12.2017; 18:30 o'clock
        if (setTime(Time2, 24, 12, 2017, 18, 30))
        {
            showTime(*Time2);
            freeTime(*Time2);
        }
        free(Time2);
    }

}


/*************
* This part is the task for a student
*************/

int setTime(TTime *thisTime, int D, int M, int Y, int H, int Min)
{
    TTime *tmpTime = NULL;

    tmpTime = malloc(sizeof(TTime));

    if (tmpTime) // if memory was allocated
    {
        tmpTime = thisTime;

        thisTime->Date = malloc(sizeof(TDate));
        thisTime->clockTime = malloc(sizeof(TClock));

        if (thisTime->Date && thisTime->clockTime) // if memory was allocated
        {

            thisTime->Date->Day = D;
            thisTime->Date->Month = M;
            thisTime->Date->Year = Y;

            thisTime->clockTime->Hour = H;
            thisTime->clockTime->Min = Min;

            return 1;

        }

        else
        {
            printf("Memory error, contact your system administrator ...\n");
            return 0;
        }
    }

    else
    {
        printf("Sorry, no free memory\n");
        waitForEnter();
        return 0;
    }

    return 0;
}

void showTime(TTime thisTime)
{
    printf("%02i.%02i.%04i; %02i:%02i o'clock\n", thisTime.Date->Day, thisTime.Date->Month, thisTime.Date->Year,
           thisTime.clockTime->Hour, thisTime.clockTime->Min);
}

void freeTime(TTime thisTime)
{
    free(thisTime.Date);
    free(thisTime.clockTime);
}

/*************
* End of a task
*************/