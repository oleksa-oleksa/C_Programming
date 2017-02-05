#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

typedef struct SVideo
{
    char *Titel;
    int Duration;
    struct SVideo *Next;
    struct SVideo *Prev;
} TVideo;

TVideo *First = NULL;
TVideo *Last = NULL;

int removeVideoFromList(TVideo *);

/***+** This is what student has to write ***/

TVideo * createVideo(char *, int);

int appendVideoInList(TVideo *);

void showVideoList();

void freeVideo(TVideo *);

/****** End of declarations **/

int main()
{
    // Test cases for programm
    appendVideoInList(createVideo("Titanic", 170));
    appendVideoInList(createVideo("TEST VIDEO HAS TO BE DELETED", 100));
    appendVideoInList(createVideo("Cloverfield", 115));
    appendVideoInList(createVideo("A Nightmare on Elm Street", 94));
    appendVideoInList(createVideo("Nine and a half Weeks", 75));
    appendVideoInList(createVideo("Vanilla Sky", 98));
    appendVideoInList(createVideo("Knocking On Heaven's Door", 104));

    showVideoList(); // print all videos
    removeVideoFromList(First->Next); // second Video has to be deleted
    showVideoList(); // print list without second Video

}

/*************
* This part is the task for a student
*************/

TVideo * createVideo (char *N, int T)
{
    TVideo *tmpVideo = NULL;
    tmpVideo = malloc(sizeof(TVideo));

    if (tmpVideo) // if the memory was successful allocated
    {
        tmpVideo->Titel = malloc(strlen(N)+1);

        if (tmpVideo->Titel) // if was allocated
        {
            strcpy(tmpVideo->Titel, N);
            tmpVideo->Duration = T;
        }

        else
        {
            printf("No memory, sorry\n");
            return NULL;
        }
    }

    else
    {
        printf("No memory, sorry\n");
        return NULL;
    }

    return tmpVideo;
}


int appendVideoInList(TVideo *newVideo)
{

    if (newVideo)
    {
        // if the list is empty
        if (First == NULL)
        {
            First = newVideo;
            First->Next = First->Prev = NULL;
            Last = First;
            return 1;
        }

        // if only one element in the list
        if (First == Last)
        {
            First->Next = newVideo;
            newVideo->Prev = First;
            newVideo->Next = NULL;
            Last = newVideo;
            return 1;
        }

        // if more than 1 element, the newVideo should be a new LAST
        else
        {
            newVideo->Prev = Last;
            newVideo->Next = NULL;
            Last->Next = newVideo;
            Last = newVideo;
            return 1;
        }
    }

    return 0;
}

void showVideoList()
{
    TVideo *printVideo = First; // direct order

    if (printVideo)
    {
        printf("The list of videos:\n");

        while (printVideo != NULL)
        {
            printf("Titel: %s (Duration %i min.)\n", printVideo->Titel, printVideo->Duration);
            printVideo = printVideo->Next;
        }
    }

    else
    {
        printf("Sorry, the library is empty.\n");
        waitForEnter();
    }
}

void freeVideo(TVideo *toDelete)
{
    if (toDelete) // checks if not NULL
    {
        free(toDelete->Titel);
        free(toDelete);
    }
}

/*************
* End of a task
*************/



int removeVideoFromList(TVideo *Video)
{
    TVideo *toDelete = First;

    if (First == NULL) // list is empty
        return 0;

    // if the first element of the list should be deleted
    if (strcmp(First->Titel, Video->Titel) == 0)
    {
        toDelete = First;

        if (Last == First) // only one element in the list
        {
           Last = NULL;
           First->Next = NULL;
        }
        First = First->Next; // move first forward
        if (First != NULL)
            First->Prev = NULL;

        freeVideo(toDelete);

        return 1; // was deleted (the result is not used in the sample code)

    }

    if (strcmp(Last->Titel, Video->Titel) == 0) // if the last element should be deleted
    {
        toDelete = Last;
        Last = Last->Prev;
        Last->Next = NULL;
        freeVideo(toDelete);

        return 1;
    }

    // searching for an element
    toDelete = toDelete->Next;

    while(toDelete != NULL)
    {
        if(strcmp(toDelete->Titel, Video->Titel) == 0)
        {
            toDelete->Prev->Next = toDelete->Next;
            toDelete->Next->Prev = toDelete->Prev;
            freeVideo(toDelete);
            return 1;
        }

        toDelete = toDelete->Next;

    }

    return 0; // was not deleted (not used in the sample code)

}