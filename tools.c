#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "escapesequenzen.h"

/***************************************************************************
*  function:    detectOSsetUnicode
***************************************************************************/
void setUnicode()
{
#ifdef __APPLE__
#endif

#ifdef _WIN32 // SET UTF-8 on Win32
    #include<windows.h>
    SetConsoleOutputCP(65001);
#endif
}

/***************************************************************************
*  function:    printLine
***************************************************************************/
void printLine(char printedChar, int amount)
{
    int i;

    for (i = 0; i < amount; i++)
    {
        printf("%c", printedChar);
    }
    printf("\n");
}

/***************************************************************************
 *  function:    clearBuffer
 ***************************************************************************/
void clearBuffer()
{
    char c;
    do
    {
        scanf("%c", &c);
    } while(c != '\n');
}


/***************************************************************************
 *  function:    clearScreen
 ***************************************************************************/
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#endif //WIN_32

#ifdef unix
    printf("\033[2J");
#endif

#ifdef __APPLE__
    CLEAR;
    HOME;
#endif
}

/***************************************************************************
 *  function:    askYesOrNo
 ***************************************************************************/
int askYesOrNo(char *pPrompt)
{
    char input;
    int readCharacters;
    do
    {
        //   Beispielausgabe("Möchten Sie noch einmal? (j/n) ", 'I');
        printf("%s", pPrompt);
        readCharacters = scanf("%c", &input);
        clearBuffer();

        if (input != 'J' && input != 'j' && input != 'n' && input != 'N')
            readCharacters = 0;
    } while (!readCharacters);

    if (input == 'j' || input == 'J')
        return 1;
    else
        return 0;
}


/***************************************************************************
*  function:    waitForEnter
***************************************************************************/
void waitForEnter ()
{
    printf("Bitte die Eingabetaste drücken...");
    char isValid = '0';
    while (isValid != 'r' && isValid != '\n')
    {
        isValid = (char) getchar();
    }
}

/***************************************************************************
*  function:    waitForEnter
***************************************************************************/
void waitForEnterNoPrompt() {
    char isValid = '0';
    while (isValid != 'r' && isValid != '\n')
    {
        isValid = (char) getchar();
    }
}

/***************************************************************************
*  function:    waitForEnter
***************************************************************************/
void waitForEnterSpecialPrompt(char *prompt) {
    printf("%s", prompt);
    char isValid = '0';
    while (isValid != 'r' && isValid != '\n')
    {
        isValid = (char) getchar();
    }

}

/***************************************************************************
*  function:    getText
*  description: Reads description / location of appointment
***************************************************************************/
void getText(char *pInfoText, int maxInput, char **pTargetText, short isAllowedEmpty)
{
    int input;
    char *pInputString = malloc((maxInput + 1) * sizeof(char)); // reserves a place in memory for user´s input
    char *pTargetString = NULL;
    char readFormat[100];

    printf("%s", pInfoText);
    sprintf(readFormat, "%%%i[^\n]s", maxInput);
    if (pInputString != NULL) // if memory was allocated
    {
        do
        {
            input = scanf(readFormat, pInputString);
            clearBuffer();

            // if empty input is allowed and it was given
            // the CheckDate has to be set to 1
            if (input || isAllowedEmpty)
                input = 1;

        } while (!input);
        //*(pInputString + maxInput + 1) = '\n';

        pTargetString = malloc(strlen(pInputString) * sizeof(char));

        strcpy(pTargetString, pInputString);

        *pTargetText = pTargetString;
        free(pInputString);
        //free(pTargetString);
    }

    else
        printf("Kein Speicher verfuegbar!\n");
}