//============================================================================
/*
Determine whether an integer is a palindrome. 
Do this without extra space.
*/
int isPalindrome(int x)
{
    
    int rev = 0;
    int num = abs (x);

    while (x != 0)
    {
        rev = rev * 10 + x % 10;
        x = x / 10;
    }
    
    if (rev == num)
        return 1;
    else 
        return 0;
}

//============================================================================
/*
Realisation of Adder (Electronics) to calculate a sum of two integers under conditions when it is prohibited to user + or - signs. 
Using AND bit operand for generating Carry-out signal. XOR bit-operand for generating a simple sum. 
*/
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

//============================================================================
/* 
Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh". 
*/

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


//=============================================================================
/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/

int addDigits(int num)
{
	
	num = 1 + ((num -1) % 9);
	return num;
}

// ===========================================================================
/*
A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares 
of its digits, and repeat the process until the number equals 1 
(where it will stay), or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.
*/

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
