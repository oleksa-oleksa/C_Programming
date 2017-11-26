#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int sig1=0;
static int sig2=0;

void sig_usr1() {
    sig1++;
}
void sig_usr2() {
    sig2++;
}


int main() {
    signal(SIGUSR1, sig_usr1);
    signal(SIGUSR2, sig_usr2);

    while(1) {
        printf("%u\n", getpid());
        if(sig1) {
            puts("USR1");
            sig1-=1;
        }
        if(sig2) {
            puts("USR2");
            sig2-=1;
        }
        sleep(2);
    }
}