// Created by Oleksandra Baga on 09.11.17.
// IBM's blog: "The parent dies or gets killed before the child.
// In the above scenario, the child process becomes the orphan process (as it has lost its parent).
// In Linux, the init process comes to the rescue of the orphan processes and adopts them.
// This means after a child has lost its parent, the init process becomes its new parent process."

// TASK: Write a program that kills parent-process and tests the new PPID of child-process

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

#include "tools.h"

#define CHILD 0
#define FAILURE -1

void parentExitStatus()
{
    puts("The parent process is now dead.\n");
}

void processSaysGoodbye()
{

    struct passwd *userName;
    uid_t userID = geteuid();
    userName = getpwuid(userID);
    printf("\nGoodbye %s\n\n", userName->pw_name);
}

int main(int args, char *argv[])
{
    int current_ppid, new_ppid, p;

    printf("%s is started\n", argv[0]);
    waitForEnter();

    p = fork();

    if (p == FAILURE)
    {
        perror("fork() failed\n");
    }

    if (p == CHILD)
    {
        current_ppid = getppid();
        new_ppid = current_ppid;
        printf("I am a happy child process: PID %u / PPID %u\n", getpid(), current_ppid);
        while (new_ppid == current_ppid) {
            new_ppid = getppid();
#ifdef DEBUG
	    printf("%u", new_ppid);
#endif
        };

        if (args == 2){
            atexit(processSaysGoodbye);
        }

        if (new_ppid == 1)
        {

            printf("\nI am a CHILD. My new parent is init with ID %u\n", new_ppid);
            return EXIT_SUCCESS;
        }

        else
        {
           printf("\nI am a CHILD on UBUNTU. My new parent is upstart with ID %u\n", new_ppid);
           return EXIT_SUCCESS;
        }
    }

    if (p > CHILD)
    {
        printf("I am a parent process: PID %u / PPID %u\n", getpid(), getppid());
        sleep(1);
        // placing exit-handler
        atexit(parentExitStatus);
        if (args == 2){
            atexit(processSaysGoodbye);
        }
        printf("Parent is dying, child is still alive\n");

        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}
