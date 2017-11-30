// Created by Oleksandra Baga on 30.11.17.
// Parent creats n-childs, wait they will be terminated and terminates when amount of a children is 0

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHILD 0
#define FAILURE -1

void signal_childHandler(int signo){
    if (signo == 20){

    }
}

int main (int args, char *argv[]) {

    if (args != 2){
        printf("Usage: childwait <amount of children>\n");
        return EXIT_SUCCESS;
    }

    signal(SIGCHLD, signal_childHandler);

    int k = atoi(argv[1]);

    int p = fork();

    if (p == FAILURE) {
        perror("fork() failed\n");
    }
    if (p > CHILD) {
        // Grandpa
        printf("Grandpa: %d\n", getpid());
        sleep(100);
        waitpid(p, NULL, 0);
    }


}

