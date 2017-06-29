#include <stdio.h>
#include "functions.h"
#include <stdbool.h>
#include <math.h>

/*
A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares 
of its digits, and repeat the process until the number equals 1 
(where it will stay), or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.
*/


bool isHappy(int n);


int main ()
{
	int a;
	int *ap = &a;
	

	do
	{
		GetNumber(ap);
		isHappy(a);

	} while (askAgain());



	return 0;
}


bool isHappy(int n) 
{
	
	int sum = 0;
	

	do
	{
		sum += pow ((n % 10), 2);
		n = n / 10;
		
		if (n == 0 && sum > 9)
		{
			n = sum;
			sum = 0;
		}

	} while (n != 0);

	if (sum == 1 || sum == 7)
	{
		printf("This number is HAPPY\n");
		return 1; 
	}
	else
	{
		printf("This is boring.\n");
		return 0;
	}

}

















