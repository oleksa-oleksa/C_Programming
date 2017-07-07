#include <stdio.h>
#define DOUBLED_PI 3.14 + 3.14
#define ADD(a, b) ((a) + (b))
#define MULT(a, b) ((a) * (b))

#define ADD_ERROR(a, b) (a) + (b) // error case: 3 * ADD(a, b) - wrong result
				  // instead of 3 * (2 + 3) = 15
				  // will be 3 * 2 + 3 = 9 
#define MULT_ERROR(a, b) (a * b) // error case: MULT(2 + a, b) - wrong result
				 // MULT (2 + a, b) - wrong result
   			       	// instead of (2 + 2) * 3 = 12
                                // will be 2 + (2 * 3) = 8

int main(){
	int f = 3200; // Hz
	int a = 2;
	int b = 3;
	
	printf("%.2f\n", DOUBLED_PI * f);
	printf("Here should be 15, the result is: %d\n", 3 * ADD_ERROR(a, b));
	printf("Here should be 15, the result is: %d\n", 3 * ADD(a, b));
	printf("Here should be 12, the result is: %d\n", MULT_ERROR(2 + a, b));
	printf("Here should be 12, the result is: %d\n", MULT(2 + a, b));
	
	return 0;
}
