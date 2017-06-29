#include <stdio.h>
#include "escapesequenzen.h"
#include <string.h>
#include "tools.h"

void getText(char InfoText[], char *EnteredText, int *Row, int *Col)
{
	unsigned short CheckInput;

	do
	{

		POSITION(*Row, *Col);
		printf("%s\n", InfoText);

		*Row += 1;
		POSITION(*Row, *Col);
		CheckInput = scanf("%200[^\n]", EnteredText);
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


	} while (!CheckInput);	

}

void getWidth(char InfoText[], int a, int b, int *Width)
{
	unsigned short CheckInput;

	do
	{
		printf(InfoText, a, b);
		CheckInput = scanf("%i", Width);
		clearBuffer();

		// checks the Input
		if (CheckInput == 1)
	     {
	        if ((*Width < a) || (*Width > b))
	        	CheckInput = 0;
	        	CLEAR_LINE;
	     }

	     else
	     {
	     	CheckInput = 0;
	     	CLEAR_LINE;
	     }


		

	} while (!CheckInput);

}

void printText (char *EnteredText, int Width, int MaxLength)
	{
		int i, index;
		char *tmp = EnteredText;

		printf("|");
		for (i = 0; i <= Width - 2; i++)
		{
			printf("_");
		}
		printf("|\n");

		while (*tmp)
		{
			
		}

		for (index = 0; index < MaxLength; index += Width)
		{
			for (i = 0; i < Width; i++)
			{
				printf("%c", *(EnteredText + index + i));

			}
			printf("\n");

		}
	}


void resetArray(char *EnteredText, int MaxLength)
{
	int i;
	for (i = 0; i < MaxLength; i++)
	{
		*(EnteredText + i) = '\0';

	}
}

