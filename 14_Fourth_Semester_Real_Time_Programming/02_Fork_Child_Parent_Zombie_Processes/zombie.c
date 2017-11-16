// new header
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

    if (args != 2)
    {
        printf("Command line argument is required: "
                       "positive number for a generation of zombie processes, -1 for unlimited amount of zombies\n");
        return EXIT_FAILURE;
    }

    int k = atoi(argv[1]);
    int n = k;

    if (n == -1) {
        k = 1;
    }
//test text bla bla
    //this is a total new file please load this
    pid_t pids[k];

    printf("%s is started\n", argv[0]);

    if (n >= 0) {
        for (int i = 0; i < k; i++) {
            pids[i] = fork();

            if (pids[i] < FAILURE) {
                perror("fork() failed\n");

            } else if (pids[i] == CHILD) {
                printf("The new child PID %u / PPID %u\n", getpid(), getppid());
                _exit(1);
            }
        }
    } else {
        while (1) {
            for (int x = 0; x < 20; x++) {
                if (fork() == 0) {
                    exit(1);
                }
            }
            //sleep(1);
        }
    }
    sleep(100);
    return EXIT_SUCCESS;
}