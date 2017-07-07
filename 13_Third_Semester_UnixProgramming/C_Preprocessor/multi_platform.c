// by compilation set the OS:
// gcc -D__DOORS_10__ -o multi_platform multi_platform.c
// run the program:
// ./multi_platform 2 4 8
// The result is: 14


#include <stdio.h>
#include <stdlib.h>


#ifdef __BIRNE_X__
	typedef long type;
	long getTerm(char *par){
		long x = atol(par);
		return x;
	}
	void printDigit(long res){
		printf("The result is: %li\n", res);
	}
#endif

#ifdef __LOCKED_BSE__
	typedef int type;
	int getTerm(char *par){
		int x = atoi(par);
		return x;
	}
	void printDigit(int res){
                printf("The result is: %d\n", res);
        }

#endif

#ifdef __DOORS_10__
	typedef short type;
	short getTerm(char *par){
		short x = atoi(par);
		return x;
	}
	void printDigit(short res){
                printf("The result is: %hi\n", res);
        }
#endif


int main (int argc, char *argv[]){

	if (argc == 4){

		type a = getTerm(argv[1]);
		type b = getTerm(argv[2]);
		type c = getTerm(argv[3]);
		
		type result = a + b + c;
		
		printDigit(result);
	}

	else { 
	
		printf("The program argv[0] requires three digits!\n");
		return -1;
	}

	
	#ifdef __BANANA_MAC__
	#pragma GCC error "Unsupported operation system."
	#endif
	return 0;
}
