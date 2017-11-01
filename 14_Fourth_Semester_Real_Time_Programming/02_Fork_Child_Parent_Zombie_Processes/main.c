#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "menu.h"
#include "escapesequenzen.h"


int main() {


    setUnicode(); // If Win32 is detected, the proper UTF-8 will be set
    clearScreen();

    char *DbFileName = "calendar.xml";


    /******* This part loads appointments into a memory
     * and increments appointmentCount */


    appointmentCount = loadCalendar(DbFileName);

    printDbInfo(appointmentCount);
    waitForEnter();

    /******** Menu output on the screen   **/

    int choice;
    char *Menu[] = {"Neuen Termin anlegen",
                    "Termin bearbeiten",
                    "Termin löschen",
                    "Termin suchen",
                    "Termine vorwärts auflisten",
                    "Termine rückwärts auflisten",
                    "Programm beenden"};

    do
    {
        clearScreen();

        /**** Reminder about new appointments */
        if (newCount) {
            printInfoNewAppointments(newCount);
        }

        /**** MENU */

        choice = getMenu("Terminverwaltung v.6.0", Menu, 7);

        switch (choice) {
            case 1:

                    createAppointment();
                    appointmentCount++;
                    newCount++;

                    break;
            case 2: editAppointment();
                    break;
            case 3: deleteAppointment();
                    break;
            case 4: searchAppointment();
                    break;
            case 5: listCalendar(appointmentCount, 0); //forward
                    break;
            case 6:
                    listCalendar(appointmentCount, 1); // backward
                    break;
            case 7:


                    if (newCount > 0)
                    {

                        FORECOLOR_YELLOW;
                        printf("\nWollen Sie Änderungen in die Datei speichern?\n\n");
                        ATTRIBUTE_OFF;

                        int hasChangesToSave = askYesOrNo("Speichern? (j/n): ");
                        if (hasChangesToSave)
                        {

                            int isSaved = saveCalendar(DbFileName, appointmentCount);

                            if (isSaved)
                            {
                                FORECOLOR_GREEN;
                                printf(" -> Alle Terminen wurden in die Datei calendar.xml gespeichert.\n\n");
                                ATTRIBUTE_OFF;
                                printf("Das Programm wurde erfolgreich beendet...\n");
                            } else
                            {
                                FORECOLOR_RED;
                                printf("\nFehler beim Speichern!\n");
                                printf("Die neuen Terminen sind nicht gespeichert!\n\n");
                                ATTRIBUTE_OFF;
                                waitForEnter();
                                printf("Das Programm wurde beendet...\n\n");

                            }
                        }

                        else
                        {
                            FORECOLOR_BLUE;
                            printf(" -> Nicht speichern\n\n");
                            ATTRIBUTE_OFF;
                            printf("Das Programm wurde beendet...");
                            printf("\n\n");
                        }
                    }

                else
                    {
                        FORECOLOR_BLUE;
                        printf("\nKeine Änderungen in die Datenbank sind zu speichern\n");
                        ATTRIBUTE_OFF;
                        printf("Das Program wurde beendet...");
                        printf("\n\n");


                    }
                    break;

            default: printf("Fehler");
        }
    } while (choice != 7);

    return 0;

}
