#include <stdio.h>
#include "functions.h"

/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/


int addDigits(int num);

int main ()
{
	int a;
	int *ap = &a;
	

	do
	{
		GetNumber(ap);
		

		a = addDigits(a);
		printf("Sum of all repeatedly added digits\n");
		printf("sum = %i\n", a);




	} while (askAgain());



	return 0;
}

int addDigits(int num)
{
	
	num = 1 + ((num -1) % 9);
	return num;
}


















