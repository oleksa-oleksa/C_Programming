#include <stdio.h>
#include "functions.h"
#include <stdbool.h>
#include <math.h>

/*
Write a program that prints the numbers from 1 to 100. 
But for multiples of three print “Fizz” instead of the number and for the multiples of five print 
“Buzz”. For numbers which are multiples of both three and five print “FizzBuzz”."
*/


void FizzBuzz();


int main ()
{
	int a[100];
	

	FizzBuzz ();



	return 0;
}


void FizzBuzz ()
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (!(i % 15))
			printf("FizzBuzz ");
		if (!(i % 3))
			printf("Fizz ");
		if (!(i % 5))
			printf("Buzz ");
		else 
			printf("%i ", i);
	}
}