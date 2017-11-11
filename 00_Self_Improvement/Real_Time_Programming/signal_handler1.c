#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(){
	// when SIGINT occurs - "Nice try" will be printed
	puts("Nice try.");
	// the default action for SIGINT will be restored => next CTRL+C will end the programm
	signal(SIGINT, SIG_DFL);
}

int main(){
	// sets the signal handler to SIGINT (CTRL+C)
	signal(SIGINT, sigint_handler);
	while(1) {
		pause();
	}
	return 0;
}
