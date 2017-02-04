#include <stdio.h>
#include <string.h>
#include "tools.h"

// FUNKTIONS

// Print a title's table and a program's name
void PrintTitle (int *Row, int *Col);

// Sets Array at Zero
void resetArray(int *A, int Anz);

// Reads String
void getText(char *T, int *Row, int *Col);

// zählen, wie oft die einzelnen Buchstaben im eingegebenen Text vorkommen
void countChar(char *T, int *A);

// Groß-/Kleinschreibung ignorieren
void setUpper2Lower(int *A);

void printTable(int *A, int *Row, int *Col);

void PrintLine (int *FoundElements, int *Row, int *Col);



//============================================

int main ()
{
	char EnteredText [151];
	int FoundElements [256];
	int Col, Row;
	
	do
	{
		Row = 1; // Set initial position
		Col = 1;

		CLEAR;

		HOME;

		resetArray(FoundElements, 256);

		PrintTitle (&Row, &Col); 

		getText (EnteredText, &Row, &Col);

		countChar(EnteredText, FoundElements);
		setUpper2Lower(FoundElements);

		printTable(FoundElements, &Row, &Col);

		// Sets position for asking User if they want to quit
		Row += 2;
		
	} while (askAgain(Row, Col));

	printf("Programm wurde beendet...\n\n");

	return 0;
}

//===========================================

void PrintTitle (int *Row, int *Col)
{	
	POSITION (*Row, *Col);
	printf("========================\n");
	printf("||                    ||\n");
	printf("||   Zeichenzaehler   ||\n");
	printf("||                    ||\n");
	printf("========================\n");
	(*Row) += 6; 
	POSITION (*Row, *Col);
	printf("Geben Sie bitte den Text ein (mind. 1 Zeichen / max. 150 Zeichen),\n");
	printf("dessen Zeichen gezaehlt werden sollen:\n");
	*Row += 2;
}

// Sets Array at Null to delete previous search result
void resetArray(int *FoundElements, int Anz)
{
	int i;

	for (i = 0; i < Anz; i++)
	{
		*(FoundElements + i) = 0;
	} 
}


void getText(char *EnteredText, int *Row, int *Col)
{
	unsigned short CheckInput;

	do
	{

		POSITION(*Row, *Col);

		CheckInput = scanf("%150[^\n]", EnteredText);
		clearBuffer();

		// checks the Input
		if (*EnteredText == '\n')
	     {
	        clearBuffer();
	        CheckInput = 0;
			POSITION(*Row, *Col);
	        CLEAR_LINE;
			POSITION(*Row, *Col);
	     }

		if (CheckInput == 1)
		{
			
			if (strlen(EnteredText) <= 1)
			{
				POSITION(*Row, *Col);
				CLEAR_LINE;
				POSITION(*Row, *Col);
				CheckInput = 0;
			}
		}

	} while (!CheckInput);	

}


void countChar(char *EnteredText, int *FoundElements)
{
	int i;

	for (i = 0; i < strlen(EnteredText); i++)
	{
		(*(FoundElements + *(EnteredText + i))) += 1;
	}
}

void setUpper2Lower(int *FoundElements)
{
	int i;

	for (i = 97; i < 123; i++)
	{
		*(FoundElements + i) += *(FoundElements + i - 32);
		*(FoundElements + i - 32) = 0;
	}
}

void printTable (int *FoundElements, int *Row, int *Col)
{
	printf("Anzahl der Zeichen:\n");
	printf("-----------------------------------------------------------------\n");
	PrintLine(FoundElements, Row, Col);
	printf("-----------------------------------------------------------------\n");

}

void PrintLine (int *FoundElements, int *Row, int *Col)
{
	int printedChars = 0, index = 0;
	char empty = ' ';

	while (index < 256)
	{
		if (*(FoundElements + index) != 0) 
		{
			if (index <= 32)
			{
				printf("| %c (%#04x): %3i ", empty, index, *(FoundElements + index));
				printedChars++;
				if ((printedChars%4) == 0) 
				{
				printf("|\n");
				}
			}

			else
			{
				printf("| %c (%#04x): %3i ", index, index, *(FoundElements + index));
				printedChars++;
				if ((printedChars%4) == 0) 
				{
					printf("|\n");
				}
			}
		}

		index++;
		}
		if ((printedChars%4) != 0)
		{
			printf("|");
			do
			{
				printf("               |");
				++printedChars;

			} while((printedChars%4) != 0);
		
		printf("\n");


	}

	*Row += (printedChars/4)+3;

}

