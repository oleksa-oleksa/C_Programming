#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void sig_usr(int signum) {
    if(signum == SIGUSR1) {
        write(STDOUT_FILENO, "USR1\n", 5);
    }

    else {
        write(STDOUT_FILENO, "USR2\n",5);
    }
    sleep(3);
}

int main() {
    signal(SIGUSR1, sig_usr);
    signal(SIGUSR2, sig_usr);

    while(1) {
        printf("%u\n", getpid());
        sleep(2);
    }
}