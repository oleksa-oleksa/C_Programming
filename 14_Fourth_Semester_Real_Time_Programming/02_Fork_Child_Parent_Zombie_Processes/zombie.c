// Created by Oleksandra Baga on 01.11.17.
// Task: program should create k Zombie-processes (k is a command line argument)
// if k = -1 => so many zombies as possible. What will happen? Explain the behaviour.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define CHILD 0
#define FAILURE -1

int main(int args, char *argv[]) {

    int k = atoi(argv[1]);
    int n = k;

    if (n == -1) {
        k = 1;
    }

    pid_t pids[k];

    if (args != 2)
    {
        printf("Command line argument is required: "
                       "positive number for a generation of zombie processes, -1 for unlimited amount of zombies\n");
        return EXIT_FAILURE;
    }

    printf("%s is started\n", argv[0]);

    if (k >= 0) {
        for (int i = k - 1; i >= 0; i--) {
            pids[i] = fork();

            if (pids[i] < FAILURE) {
                perror("fork() failed\n");

            } else if (pids[i] == CHILD) {
                printf("The new child PID %u / PPID %u\n", getpid(), getppid());
                sleep(i+1);
                _exit(1);
            }
        }
    }
    else if (k == -1) {
        while (1) {

        }
    }


    for (int i = k-1; i > 0; i--) {
        waitpid(pids[i], NULL, 0);
    }

    return EXIT_SUCCESS;
}