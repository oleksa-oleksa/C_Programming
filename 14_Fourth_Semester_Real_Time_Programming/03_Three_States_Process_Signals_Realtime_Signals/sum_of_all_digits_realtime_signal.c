// Created by Oleksandra Baga on 09.12.17.
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "sum_of_digits.h"

#define FAILURE -1
#define CHILD 0
#define NUMBER_OF_CHILDREN 5

int g_sum;
int n = 0;

int fold_numbers(char *file_name){
    int sum_of_allSums = 0;
    FILE *f = fopen(file_name, "rt");
    if (!f) {
        printf("Error opening file %s\n", file_name);
        return -2;
    }

    char char_numbers[5]; // we assume that number is in a range 1 - 1000;
    int sum = 0;

    while(!feof(f)) {
        fgets(char_numbers, 5, f);
        sum = sum_of_digits(char_numbers);
        if (sum < 0){
            continue;
        }
        sum_of_allSums += sum;
    }
    fclose(f);

    return sum_of_allSums;
}

void child_process(char *file)
{
    int sum = 0;

    sum = fold_numbers(file);
    if(sum < 0){
        printf("Parse error!\n");
        return;
    } else {
        printf("Successfully parsed.\n");
    }
    printf("The sum of all random numbers is: %i\n", sum);
    union sigval v;
    v.sival_int = sum;
    sigqueue(getppid(), SIGRTMIN + 5, v);
}

void handler_realTime(int signum, siginfo_t *si, void *data) {
    if (signum == SIGRTMIN + 5) {
        n -= 1;
        g_sum += si->si_value.sival_int;
        printf("RealTime Signal: sum = %d\n", g_sum);
    }
}

int main(int args, char *argv[]){

    if (args != 2) {
        printf("Usage: program_name <infile>\n");
        return -1;
    }

    char *file = argv[1];
    pid_t pids[5];

    struct sigaction act;
    act.sa_sigaction = handler_realTime;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGRTMIN + 5, &act, NULL);
    sigset_t signalset;
    sigemptyset(&signalset);
    sigaddset(&signalset, SIGRTMIN + 5);

    int i;
    for (i = 0; i < NUMBER_OF_CHILDREN; i++) {
        pids[i] = fork();

        if (pids[i] == FAILURE) {
            perror("fork() failed");
        } else if (pids[i] == CHILD) {
            child_process(file);
            return 0;
        } else {
            n++;
            printf("Child %d: started (n = %d)\n", pids[i], n);
        }

    }

    while (n > 0) {
        sleep(1);
    }
    printf("The sum of all sums is: %d\n", g_sum);
    return EXIT_SUCCESS;
}

