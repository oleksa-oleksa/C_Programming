#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include <string.h>

void swapAppointment(TAppointment *a, TAppointment *b)
{
    TAppointment swp;

    swp = *a;
    *a = *b;
    *b = swp;
}


int partition (TAppointment *appointments, int lowerBound, int upperBound, int (*ordering) (TAppointment *a, TAppointment *b),
               void (*swapAppointment) (TAppointment *a, TAppointment *b))
{
    int i = lowerBound, j = upperBound;
    TAppointment *pivot = appointments + lowerBound;

    while (i <= j)
    {
        while (i <= j && ordering(appointments + i, pivot) < 1)
        {
            i++;
        }
        while (j >= i && ordering(appointments + j, pivot) > -1)
        {
            j--;
        }

        if (i < j)
        {
            swapAppointment(appointments + i, appointments + j);

            i++;
            j--;
        }
    }
    i--;

    swapAppointment(appointments + lowerBound, appointments + i);

    return(i);
}



void qSortAlgorithm(TAppointment *appointments, int lowerBound, int upperBound,
                    int (*ordering)(TAppointment *a, TAppointment *b),
                    void (*swapAppointment)(TAppointment *a, TAppointment *b))
{

    int idx;

    if (lowerBound >= upperBound)
        return;
    else
    {
        idx = partition(appointments, lowerBound, upperBound, ordering, swapAppointment);
        qSortAlgorithm(appointments, lowerBound, idx - 1, ordering, swapAppointment);
        qSortAlgorithm(appointments, idx + 1, upperBound, ordering, swapAppointment);
    }
}


void quickSortAppointments(TAppointment *appointments, int amount, int (*ordering) (TAppointment *a, TAppointment *b))
{
    qSortAlgorithm(appointments, 0, (amount - 1), ordering, swapAppointment);
}
