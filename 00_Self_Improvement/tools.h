#ifndef TOOLS_TOOLS_H
#define TOOLS_H TOOLS_H

/***************************************************************************
 *  function:    waitForEnter
 *  description: Holds the program flow before Enter key is pressed
 *  parameter:   -
 *  result :     -
 ***************************************************************************/
void waitForEnter();

/***************************************************************************
* function:    setUnicode()
*  description: If Win32 is detected, the proper UTF-8 will be set
*  parameter:   -
*  result :     -
***************************************************************************/
void setUnicode();

/***************************************************************************
 *  function:    waitForEnter
 *  description: Holds the program flow before Enter key is pressed
 *  parameter:   -
 *  result :     -
 ***************************************************************************/
void waitForEnterNoPrompt();

/***************************************************************************
 *  function:    waitForEnter
 *  description: Holds the program flow before Enter key is pressed
 *  parameter:   -
 *  result :     -
 ***************************************************************************/
void waitForEnterSpecialPrompt(char *prompt);

/***************************************************************************
 *  function:    printLine
 *  description: prints '-' n times
 *  parameter:   Char to be printed, n as an amounts of repeats
 *  result :     -
 ***************************************************************************/
void printLine(char printedChar, int amount);

/***************************************************************************
 *  function:    clearBuffer
 *  description: clears the input buffer
 *  parameter:   -
 *  result :     returns 0
 ***************************************************************************/
void clearBuffer();


/***************************************************************************
 *  function:    clearScreen
 *  description: clears the console screen
 *  parameter:   -
 *  result :     -
 ***************************************************************************/
void clearScreen();

/***************************************************************************
 *  function:    askYesOrNo
 *  description: Print out a message and take an input (j/n).
 *  parameter:   text: the message (question) to be asked.
 *  result :     returns 1 if the input is 'j'; 0 if it's 'n'.
 ***************************************************************************/
int askYesOrNo(char *);


/***************************************************************************
 *  function:    getText
 *  description: Reads description / location of appointment
 *  parameter:   text: the message (question) to be asked.
 *               Maximal lenght of input (depends from type)
 *               Pointer at data structure for keeping location or description.
 *               EmptyisOn = 1 (user can skip the input), or = 0 (Input is necessary)
 *  result :     1 if the date is valid, 0 if the date is invalid.
 ***************************************************************************/
void getText(char *pInfoText, int maxInput, char **pTargetText, short isAllowedEmpty);


#endif
