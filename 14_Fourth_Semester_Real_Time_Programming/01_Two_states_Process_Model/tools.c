#include <stdio.h>
#include "tools.h"
#include "escapesequenzen.h"

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
        //   Example ("Do you want to repeat? (y/n)");
        printf("%s", pPrompt);
        readCharacters = scanf("%c", &input);
        clearBuffer();

        if (input != 'Y' && input != 'y' && input != 'n' && input != 'N')
            readCharacters = 0;
    } while (!readCharacters);

    if (input == 'Y' || input == 'y')
        return 1;
    else
        return 0;
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
*  function:    waitForEnter
***************************************************************************/
void waitForEnter ()
{
    printf("Press Enter to continue...");
    char isValid = '0';
    while (isValid != 'r' && isValid != '\n')
    {
        isValid = (char) getchar();
    }
}