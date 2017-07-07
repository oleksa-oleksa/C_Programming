// normal compilation
// gcc -Wall -o kinda_project kinda_project.c


// compilation with DEBUG macros
// gcc -DDEBUG -Wall -o kinda_project kinda_project.c
// where -D is flag and DEBUG is name


#include <stdio.h>
#include <stdlib.h>
#include "awesome.h"

#if (__awesome_ver < 2)
#error "The program requeres awesome.h ver. 2 and newer..."
#endif

int main(){

	#ifdef DEBUG
		puts("starting");
	#endif
	
	#if (__awesome_ver == 3)
		do_something_awesome(42);
	#else
		something_awesome(42);
	#endif

	#ifdef DEBUG
		puts("done");
	#endif
	return EXIT_SUCCESS;

} 
