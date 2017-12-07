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
    pid_t pid;

    pid = wait(NULL);
    n -= 1;
    printf("Child %d: terminated (n = %d)\n", pid, n);
}

void child_process()
{
    while (1) {
        sleep(1);
    }
}

int main(int args, char *argv[]) {

    if (args != 2) {
        printf("Usage: childwait <amount of children>\n");
        return EXIT_SUCCESS;
    }

    signal(SIGCHLD, signal_childHandler);

    int k = atoi(argv[1]);
    int ppid = getpid();

    pid_t pids[k];

    if (k <= 0)
        return -1;

    for (int i = 0; i < k; i++) {
        pids[i] = fork();

        if (pids[i] == FAILURE) {
            perror("fork() failed");
        } else if (pids[i] == CHILD) {
            child_process();
        } else {
            n++;
            printf("Child %d: started (n = %d)\n", pids[i], n);
        }

    }

    while (n > 0) {
        printf("Parent %d: sleep\n", ppid);
        sleep(2);

    }

    return EXIT_SUCCESS;
}

