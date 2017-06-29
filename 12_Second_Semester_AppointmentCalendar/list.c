#include "datastructure.h"
#include <stdlib.h>
#include "calendar.h"
#include "sort.h"

TAppointment *FirstAppointment = NULL;
TAppointment *LastAppointment = NULL;
int appointmentCount = 0;

/***************************************************************************
 Inserts the new element at the end of the list
 Creates new element dynamic while works
 ***************************************************************************/
void insertInDList(TAppointment *loaded)
{

    TAppointment *NewAppointment = NULL;
    NewAppointment = malloc(sizeof(TAppointment));

    if (NewAppointment)
    {
        *NewAppointment = *loaded;
        NewAppointment->Previous = NULL;
        NewAppointment->Next = NULL; // new end of a list

        if (FirstAppointment == NULL) // list is still empty
        {

         FirstAppointment = LastAppointment = NewAppointment;

        }

        else // list has already elements
        {
            TAppointment *insertTo = FirstAppointment;

            // search for a node
            while(insertTo && orderByDateTime(insertTo, NewAppointment) < 0)
            {
              insertTo = insertTo->Next;
            }

            // if the date is biggest in the list
            if (insertTo == NULL)
            {
                LastAppointment->Next = NewAppointment;
                NewAppointment->Previous = LastAppointment;
                LastAppointment = NewAppointment;

            } else if (insertTo == FirstAppointment) {
                NewAppointment->Next = insertTo;
                insertTo->Previous = NewAppointment;
                FirstAppointment = NewAppointment;
            } else
            {
                NewAppointment->Previous = insertTo->Previous;
                NewAppointment->Next = insertTo;
                insertTo->Previous->Next = NewAppointment;
                insertTo->Previous = NewAppointment;

            }
        }
    }
}

void removeFromDList(int Index)
{

    TAppointment *toDeleteAppointment = FirstAppointment;



    for (int i = 1; i < Index; i++)
    {
        toDeleteAppointment = toDeleteAppointment->Next;
    }

    if (FirstAppointment == LastAppointment)
    {
        LastAppointment = NULL;
        FirstAppointment = NULL;
        free(toDeleteAppointment);
        return;

    }

    // if not the last and not the first
    if (toDeleteAppointment != FirstAppointment && toDeleteAppointment != LastAppointment) {
        toDeleteAppointment->Previous->Next = toDeleteAppointment->Next;
        toDeleteAppointment->Next->Previous = toDeleteAppointment->Previous;
    }
    else
    {
        if (toDeleteAppointment == FirstAppointment)
        {
            FirstAppointment = toDeleteAppointment->Next;
            toDeleteAppointment->Next->Previous = NULL;
        }
        else
        {
            LastAppointment = toDeleteAppointment->Previous;
            toDeleteAppointment->Previous->Next = NULL;
        }
    }

    free(toDeleteAppointment);
}