#include <stdio.h>
#include "functions.h"

int main ()
{
	char s[100];

	do
	{
		printf("Please type a text line and press Enter\n");
		GetTextLine(s);
		reverseString(s);
		printf("%s\n", s);
	} while (askAgain());



	return 0;
}


