#include <stdio.h>
#include "functions.h"

/*
Realisation of Adder (Electronics) to calculate a sum of two integers under conditions when it is prohibited to user + or - signs. 
Using AND bit operand for generating Carry-out signal. XOR bit-operand for generating a simple sum. 
*/


int getSum(int a, int b);

int main ()
{
	int a, b;
	int *ap = &a;
	int *bp = &b;

	do
	{
		GetNumber(ap);
		GetNumber(bp);

		b = getSum(a, b);
		printf("Sum = %i\n\n", b);



	} while (askAgain());



	return 0;
}

// Carry-Look-Ahead
int getSum(int a, int b)
{
	do
	{
		int c = a & b;
		b = a ^ b;
		a = c << 1;

	} while (a != 0);

	return b;

}