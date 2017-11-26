// Created by Oleksandra Baga on 26.11.17.

/* Whats the difference between RT signals and standard signals?
More than one RT signal can be queued for the process if it has the signal blocked while someone sends it. In standard signals only one of a given type is queued, the rest is ignored.
Order of delivery of RT signal is guaranteed to be the same as the sending order.
PID and UID of sending process is written to si_pid and si_uid fields of siginfo_t.*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signum) {
    if(signum == SIGUSR1) {
        puts("SIGUSR1 intercepted.\n");
    }
    signal(SIGUSR1, SIG_DFL);
}

void handler_realTime(int signum, siginfo_t *si, void *data){
    if (signum == SIGINT) {
        puts("RealTime Signal for Mac OS intercepted.\n");
    }
}

int main() {
    // Real Time Signal Settings
    /* If act is non-NULL, the new action for signal signum is installed
       from act.  If oldact is non-NULL, the previous action is saved in oldact.*/
    struct sigaction act;
    act.sa_sigaction = handler_realTime;
    /* The sa_mask field allows us to specify a set of signals that aren’t permitted to interrupt execution of this handler.
     * In addition, the signal that caused the handler to be invoked is automatically added to the process signal mask.*/
    sigemptyset(&act.sa_mask);
    /* The signal handler takes three arguments, not one.  In this case, sa_sigaction should be set instead of sa_handler.*/
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &act, NULL); // Mac OS Solution for a task

    // Regular Signal Settings
    sigset_t set, signalset;
    signal(SIGUSR1, handler);
    sigaddset(&signalset, SIGUSR1);
    printf("PID: %u\n", getpid());


    while(1) {
        /* The sigprocmask() function examines and/or changes the current signal mask (those signals that are blocked from delivery).
         * Signals are blocked if they are members of the current signal mask set.*/
        sigprocmask(SIG_BLOCK, &signalset, NULL);
        puts("Signals blocking: activated\n");
        printf("Please sent SIGUSR1 to a PID: %u or wait for RT Signal message.\n", getppid());

        sleep(10);
        // SENDING REAL TIME SIGNAL
        sigqueue(getppid(), SIGINT, 10);
        printf("RT signal was sent\n");
        sleep(10);

        /* sigpending() returns the set of signals that are pending
         * for delivery to the calling thread (i.e., the signals which have been raised while blocked).*/
        sigpending(&set);

        if (sigismember(&set, SIGUSR1)){
            puts("SIGUSR1 is pending");
        }
        if (sigismember(&set, SIGINT)){
            puts("RT Signal is pending");
        }
        sigprocmask(SIG_UNBLOCK, &signalset, NULL);
        puts("Signals blocking: disabled\n");
        sleep(3);
    }

    return EXIT_SUCCESS;
}
