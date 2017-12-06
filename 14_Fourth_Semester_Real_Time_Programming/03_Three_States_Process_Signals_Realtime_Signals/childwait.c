// Created by Oleksandra Baga on 30.11.17.
// Parent creats n-childs, wait they will be terminated and terminates when amount of a children is 0

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHILD 0
#define FAILURE -1
int n = 0;

void signal_childHandler() {
    pid_t pid = 0;
    n -= 1; // decrement if child dies
    pid = wait(NULL);
    printf("Child %d: terminated (n = %d)\n", pid, n);

}

int main(int args, char *argv[]) {

    if (args != 2) {
        printf("Usage: childwait <amount of children>\n");
        return EXIT_SUCCESS;
    }

    signal(SIGCHLD, signal_childHandler);

    int k = atoi(argv[1]);
    pid_t pids[k];

    if (k > 0) {
        for (int i = 0; i < k; i++) {
            pids[i] = fork();
            if (pids[i] == FAILURE) {
                perror("fork() failed\n");
            } else if (pids[i] == CHILD) {
                printf("Child %d: started (n = %d)\n", getpid(), n);
                sleep(1);
                EXIT_SUCCESS;
            }
            n += 1;
        }
    }
    do {
        printf("Parent %d: sleep(2)\n", getpid());
        sleep(2);
    } while (!n);
    EXIT_SUCCESS;
}

