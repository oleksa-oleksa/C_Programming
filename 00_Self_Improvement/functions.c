#include <stdio.h>
#include "functions.h"


// FUNCTIONS DEFINITIONS

void ClearBuffer ()
{
	char RestInput;

	do
		scanf("%c", &RestInput);
	while (RestInput != '\n');
}

void GetTextLine (char *s)
{
	int CheckInput;

	do
	{

		CheckInput = scanf("%[^\n]", s);
		/* the %[^\n] conversion specification, which matches a string of all characters 
		not equal to the new line character ('\n') 
		and stores it (plus a terminating '\0' character) in s */
		ClearBuffer();

		if (*s == '\n')
		{
			ClearBuffer();
			CheckInput = 0;
		}

	} while (!CheckInput);
}


int askAgain()
{
  	char Repeat;

  	do // Loop for asking unill a correct char is given
    {

      printf("Wollen Sie noch einmal? (j/n): \n");
      

      scanf("%[^\n]", &Repeat);

      if (Repeat == '\n')
        ClearBuffer();

      ClearBuffer();

      if (Repeat == 'j' || Repeat == 'J') 
      {
        return 1;
      } 
      else 
        if (Repeat == 'n' || Repeat == 'N') 
        {
        return 0;
        }

    } while (1);
}


char* reverseString(char *s)
{
	int i;
	char *tmpLast = s; 
	char CopyItem;
	char *tmpFirst = tmpLast;

	while (*tmpLast)
		tmpLast++; 
	tmpLast--;

	while (tmpFirst < tmpLast)
	{
		
		CopyItem = *tmpFirst;
		*tmpFirst = *tmpLast;
		*tmpLast = CopyItem;
		tmpFirst++;
		tmpLast--;
	}
	
	return s;
	
}

int* GetNumber (int *x)
{
	int CheckInput;

	do
	{
		printf("Please enter an integer number: \n");
		
		CheckInput = scanf("%i", x);
		ClearBuffer();

	} while (!CheckInput);

	return x;
}

