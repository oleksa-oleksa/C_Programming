#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"
#include "menu.h"
#include "sort.h"
#include "tools.h"
#include "datetime.h"
#include <string.h>
#include <math.h>
#include "escapesequenzen.h"
#include "list.h"
#include "datastructure.h"


void createAppointment() {

    TAppointment createdAppointment; // temporary
    memset(&createdAppointment, 0, sizeof(createdAppointment)); // set all to NULL

    clearScreen();

    printLine('=', 35);
    printf("   Erfassung eines neuen Termins\n");
    printLine('=', 35);
    printf("\n");

    getDate("Datum        : ", &(createdAppointment.Date));
    getTime("Uhrzeit      : ", &(createdAppointment.Time), 0, 0);

    TTime *duration = malloc(sizeof(TTime));
    memset(duration, 0, sizeof(TTime));
    getTime("Dauer        : ", duration, 0, 1);
    if (duration->Second == duration->Minute == duration->Hour == 0) {
        free(duration);
    } else {
        createdAppointment.Duration = duration;
    }

    getText("Beschreibung : ", MAX_DESCRIPTION, &(createdAppointment.Description), 0);
    getText("Ort          : ", MAX_LOCATION, &(createdAppointment.Location), 1);

    insertInDList(&createdAppointment);

    FORECOLOR_GREEN;
    printf("\n\nNeuen Termin ist angelegt. \n\n");
    ATTRIBUTE_OFF;
    waitForEnter();
}

void editAppointment() {

}

void deleteAppointment() {

    int isValid = 0;
    int choice, i;

    TAppointment *thisAppointment = FirstAppointment;

    clearScreen();

    printLine('=', 90);
    FORECOLOR_RED;
    printf("                                 Löschen eines Termins\n");
    ATTRIBUTE_OFF;
    printLine('=', 90);
    printf("\n");

    if (thisAppointment == NULL)
    {
        printf("Keine Termine in der Datenbank\n");
        waitForEnter();
    }


    for (i = 1; ;i++)
    {
        if (thisAppointment->Next != NULL)
        {
            printf("%i: ", i);
            printDListeinLine(thisAppointment);
            thisAppointment = thisAppointment->Next;
        }

        else
        {
            printf("%i: ", i);
            printDListeinLine(thisAppointment);
            break;
        }

    }

    int total = i;

    printLine('=', 90);
    printf("\n\n");
    printf("Welchen Termin wollen Sie ");
    FORECOLOR_RED;
    printf("löschen?\n\n");
    ATTRIBUTE_OFF;
    printf("Bitte geben Sie eine Zahl ein (0 für Abbrechen):\n");

    do
    {
        isValid = scanf("%i", &choice);
        clearBuffer();

        if (choice > total || choice < 0)
        {
            printf("Fehler, kein gültiger Termin \n\n");
            isValid = 0;
        }

        if (choice == 0)
            break;

    }while(!isValid);

    /** Removes an element from double linked list **/
    if (choice > 0)
    {
        removeFromDList(choice);
        newCount--;
        printf("Der Termin ist gelöscht...\n\n");
        waitForEnter();
    }



}

void searchAppointment() {

}


int orderByTime(TAppointment *a, TAppointment *b) {
    if (a->Time.Hour < b->Time.Hour) {
        return -1;
    }


    if (a->Time.Hour > b->Time.Hour) {
        return 1;
    }


    if (a->Time.Minute == b->Time.Minute) {

        if (a->Time.Second == b->Time.Second) {
            return 0;
        } else {
            if (a->Time.Second > b->Time.Second) {
                return 1;
            } else {
                return -1;
            }
        }
    } else {
        if (a->Time.Minute > b->Time.Minute) {
            return 1;
        } else {
            return -1;
        }
    }
}



int orderByDate(TAppointment *a, TAppointment *b) {

    if (a->Date.Year < b->Date.Year) {
        return -1;
    }


    if (a->Date.Year > b->Date.Year) {
        return 1;
    }


    if (a->Date.Month == b->Date.Month) {

        if (a->Date.Day == b->Date.Day) {
            return 0;
        } else {
            if (a->Date.Day > b->Date.Day) {
                return 1;
            } else {
                return -1;
            }
        }
    } else {
        if (a->Date.Month > b->Date.Month) {
            return 1;
        } else {
            return -1;
        }
    }

}

int orderByDateTime(TAppointment *a, TAppointment *b) {
    int dateComparison = orderByDate(a, b);

    if (dateComparison == 0)
        return orderByTime(a, b);

    return dateComparison;

}


void sortCalendar() {
    // not necessary for a double linked list
}

void printAppointment(TAppointment *appointment) {
    printf("\n   ");
    printTime(appointment->Time);

    TTime endTime = appointment->Time;

    if (appointment->Duration != NULL) {
        addTime(&appointment->Time, appointment->Duration, &endTime);
        printf(" - ");
        printTime(endTime);
    } else printf(":       ");


    char *Location = "";
    char *LP = "";


    if (appointment->Location) {
        Location = appointment->Location;
        LP = "->";
    } else {
        Location = "               ";
        LP = "  ";
    }

    /******* If Description is longer 48 symbols, then print only first 44 symbols */

    char *tmpDes = appointment->Description;

    if (strlen(appointment->Description) <= 48)
        printf(" %s %-15s | %-48s", LP, Location, appointment->Description);

    else {
        printf(" %s %-15s  | ", LP, Location);
        for (int i = 0; i < 44; i++) {
            printf("%c", *(tmpDes + i));
        }
        printf(" ...");


    }
}

void printLineAppointment() {
    printf("\n");
    printLine('=', 90);
    printf("\n\n");

}


void printInfoNewAppointments(int newN) {

    if (newN == 1) {
        FORECOLOR_BLUE;
        printf("%d neuer Termin is angelegt\n", newN);
        ATTRIBUTE_OFF;
    } else {
        FORECOLOR_BLUE;
        printf("%d neuen Termine is angelegt\n", newN);
        ATTRIBUTE_OFF;
    }
}

void printDateHeader(TAppointment *a) {
    FORECOLOR_GREEN;
    printDate(a->Date);
    ATTRIBUTE_OFF;
    printf("\n");
    printLine('-', 15);

}

void printDListeinLine(TAppointment *appointment)
{
    printDate(appointment->Date);
    printf(", ");
    printTime(appointment->Time);
    printf(":");

    /******* If Description is longer 48 symbols, then print only first 44 symbols */

    char *tmpDes = appointment->Description;

    if (strlen(appointment->Description) <= 48)
        printf(" %-48s", appointment->Description);

    else
    {
        printf(" ");
        for (int i = 0; i < 44; i++) {
            printf("%c", *(tmpDes + i));
        }
        printf(" ...");

    }

    printf("\n");
}


void listCalendar(int amount, int Direction) {

    TAppointment *thisAppointment = (Direction == 0) ? FirstAppointment : LastAppointment;

    int appointmentsOnScreen = 0; //saves the number of appointments on the screen
    int currentAppointment = 0;
    int page = 1;
    clearScreen();
    printLine('=', 90);
    printf("                                 Liste der Termine\n");
    printLine('=', 90);
    printf("\n");

    char *prompt = malloc(strlen("Bitte Enter drücken, um die nächsten 100 Termine anzuzeigen...") * sizeof(char));
    while (thisAppointment) {
        if (appointmentsOnScreen >= 10) {
            if (amount - 1 - currentAppointment >= 10) {
                sprintf(prompt, "Seite %d/%d \n\nBitte Enter drücken, um die nächsten %d Termine anzuzeigen",
                        page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN),
                        MAX_APPOINTMENTS_ON_SCREEN);
                waitForEnterSpecialPrompt(prompt);
                clearScreen();
            } else {
                sprintf(prompt, "Seite %d/%d \n\nBitte Enter drücken, um die nächsten %d Termine anzuzeigen",
                        page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN),
                        amount - currentAppointment);
                waitForEnterSpecialPrompt(prompt);
                clearScreen();
            }

            sprintf(prompt, "Seite %d/%d \n\nBitte Enter drücken... ",
                    page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN));

            appointmentsOnScreen = 0;

            page++;
        }


        /**** If current appointment has the same date as previous, the date will not be printed twice */

        int isHeaderRequired;
        if (Direction == 0)
            isHeaderRequired = thisAppointment == FirstAppointment ||
                               (thisAppointment->Previous && orderByDate(thisAppointment, thisAppointment->Previous));
        else
            isHeaderRequired = thisAppointment == LastAppointment ||
                               (thisAppointment->Next && orderByDate(thisAppointment, thisAppointment->Next));

        if (appointmentsOnScreen == 0 || isHeaderRequired) {
            // if (currentAppointment != 0)
            printLineAppointment();
            printDateHeader(thisAppointment);

        }

        // Part for each appointment
        printAppointment(thisAppointment);

        printf("\n \n");
        appointmentsOnScreen++;
        currentAppointment++;

        thisAppointment = (Direction == 0) ? thisAppointment->Next : thisAppointment->Previous;


    }

    printf("Seite %d/%d \n\n", page, (int) ceil((double) amount / (double) MAX_APPOINTMENTS_ON_SCREEN));
    free(prompt);
    waitForEnter();
}

