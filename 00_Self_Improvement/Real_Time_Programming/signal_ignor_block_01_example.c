#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void sig_usr1() {
    write(STDOUT_FILENO, "USR1\n",5);
    sleep(4);
}
void sig_usr2() {
    write(STDOUT_FILENO, "USR2\n",5);
    sleep(2);
}

int main() {
    signal(SIGUSR1, sig_usr1);
    signal(SIGUSR2, sig_usr2);

    while(1) {
        printf("%u\n", getpid());
        sleep(10);
    }
}

