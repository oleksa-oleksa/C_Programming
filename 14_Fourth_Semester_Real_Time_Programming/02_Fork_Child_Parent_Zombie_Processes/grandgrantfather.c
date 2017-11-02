// Created by Oleksandra Baga on 02.11.17.
// Task: fork() creates grandgrantfather, grandfather and child process.
// All of them have to terminate with a different time
// Who adopts the child process? When init will adopt the child process?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define CHILD 0
#define FAILURE -1

int main() {

    int p = fork();

    if (p == FAILURE) {
        perror("fork() failed\n");
    }
    if (p > CHILD) {
        sleep(10);
        waitpid(p, NULL, 0);
    }
    if (p == CHILD) {
        int s = fork();

        if (s == FAILURE) {
            perror("fork-2 failed\n");
        }
        if(s > CHILD){
            exit(0);
        }
        if (s == CHILD) {
            while (1); // grandson lives forever
        }

    }
    return EXIT_SUCCESS;
}


