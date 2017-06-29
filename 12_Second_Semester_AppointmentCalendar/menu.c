#include "menu.h"
#include "tools.h"
#include <stdio.h>
#include <string.h>
#include "escapesequenzen.h"

int getMenu(char *pTitle, char **pItems, unsigned int amount)
{
    int isValid = 0;
    int choice;
    do
    {
        int i = 0;
        printf("\n%s \n", pTitle);
        printLine('=', (strlen(pTitle) + 1));
        printf("\n");
        for (i = 0; i < amount; ++i)
        {
            printf("%i. %s \n", i + 1, pItems[i]);
        }

        printf("\nBitte wählen Sie einen Menüpunkt:\n ");
        isValid = scanf("%i", &choice);
        clearBuffer();
        if (choice > amount || choice <= 0)
        {
            printf("Fehler, keine gültige Menüwahl \n\n");
            isValid = 0;
        }

    } while (!isValid);

    return choice;

}
