// Created by Oleksandra Baga on 01.11.17.
// IBM's blog: "The parent dies or gets killed before the child.
// In the above scenario, the child process becomes the orphan process (as it has lost its parent).
// In Linux, the init process comes to the rescue of the orphan processes and adopts them.
// This means after a child has lost its parent, the init process becomes its new parent process."

// TASK: Write a program that kills parent-process and tests the new PPID of child-process

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

#define CHILD 0
#define FAILURE -1

void parentExitStatus()
{
    puts("The parent process is now dead.\n");
}

int main(int args, char *argv[])
{
    int new_ppid = 0;
    int p;

    printf("%s is started\n", argv[0]);
    waitForEnter();

    p = fork();

    if (p == FAILURE)
    {
        perror("fork() failed\n");
    }

    if (p == CHILD)
    {
        printf("I am a happy child process: PID %u / PPID %u\n", getpid(), getppid());
        while (new_ppid != 1) {
            new_ppid = getppid();
        };

        if (new_ppid == 1)
        {

            printf("\nI am a CHILD. I've got a new parent - init with ID %u\n", new_ppid);
            waitForEnter();
        }
    }

    if (p > CHILD)
    {
        printf("I am a parent process: PID %u / PPID %u\n", getpid(), getppid());
        sleep(1);
        // placing exit-handler
        atexit(parentExitStatus);
        printf("Parent is dying, child is still alive\n");

        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}
