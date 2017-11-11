
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sig_usr1(){
	write(STDOUT_FILENO, "USR1\n", 5);
	sleep(4);
}

void sig_usr2(){
        write(STDOUT_FILENO, "USR2\n", 5);
        sleep(2);
}


int main(){
        // sets the signal handler to SIGUSR1 (user defined signal 1)
      	signal(SIGUSR1, sig_usr1);
	signal(SIGUSR2, sig_usr2);
	while(1) {
		printf("%u\n", getpid());
		sleep(10);
        }
        return 0;
}

