#pragma once
void clearScreen();
int askYesOrNo(char *pPrompt);
void clearBuffer();
void waitForEnter();
void getText(char *pInfoText, char **pTargetText);
void printLine(char printedChar, int amount);