// Carry-Look-Ahead
/*
Realisation of Adder (Electronics) to calculate a sum of two integers under conditions when it is prohibited to user + or - signs. 
Using AND bit operand for generating Carry-out signal. XOR bit-operand for generating a simple sum. 
*/

int getSum(int a, int b)
{
	int carry;

	do
	{
		int c = a & b;
		b = a ^ b;
		carry = c;
		printf("%i\n", b);
		a = c << 1;

	} while (a != 0);

	return b;

	if (carry) // If Carry-Out is 1
	{
		b = b | 0x0000;
		b = b & 0x8000;
	}

	return b;
}
