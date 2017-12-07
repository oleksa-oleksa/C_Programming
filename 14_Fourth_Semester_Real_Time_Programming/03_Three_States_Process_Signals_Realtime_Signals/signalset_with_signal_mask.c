// Created by Oleksandra Baga on 29.11.17.
/* Task: Implement the functions from Standard C Library:
 sigemptyset() - initializes a signal set to be empty.
 sigfillset() - initializes a signal set to contain all signals.
 sigaddset() - adds the specified signal signo to the signal set.
 sigdelset() - deletes the specified signal signo from the signal set.
 sigismember() - returns whether a specified signal signo is contained in
     the signal set.
 There are 32 signals to handle with

 // Remark for myself: There are two ways to initialize a signal set.
 You can initially specify it to be empty with sigemptyset and then add specified signals individually.
 Or you can specify it to be full with sigfillset and then delete specified signals individually.
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "menu.h"
#include "tools.h"

//  The chosen solution: using the BINARY MASK to implement the set in C

int readSigno();
void my_sigfillset(uint32_t *);
void my_sigaddset(uint32_t *, int);
void my_sigemptyset(uint32_t *);
void my_sigdelset(uint32_t *, int);
int my_sigismember(uint32_t *, int);
void print_signalSet(uint32_t *);

void my_sigfillset(uint32_t *set) {
    *set = *set | 0xFFFFFFFF;
}

void my_sigaddset(uint32_t *set, int signo) {
    *set |= (1 << signo);}

void my_sigemptyset(uint32_t *set) {
    *set = *set & 0x0;
}

void my_sigdelset(uint32_t *set, int signo) {
    *set &= ~(1 << signo);
}

int my_sigismember(uint32_t *set, int signo){
    return *set & (1<<signo);
}

int readSigno(){
    printf("\nSignal number (1 - 31): \n ");
    int isValid = 0;
    int choice;
    do {
        isValid = scanf("%i", &choice);
        clearBuffer();
        if (choice > 31 || choice <= 0)
        {
            printf("Error: invalid number input. Signal number (1 - 31):\n");
            isValid = 0;
        }
    } while (!isValid);
    return choice;
}


void print_signalSet(uint32_t *set){
    uint32_t tmp_set = *set;
    uint32_t mask = 2;
    printf("Number: %u. Signal set:\n", *set);
    for (int i = 1; i < 32; i++){
        if (tmp_set & mask) {
            printf("%d ", i);
        }
        mask <<= 1;
    }
    printf("\n");
}

int main() {
    int signo, isInSet;
    clearScreen();
    uint32_t sset = 0;
    uint32_t *set = &sset;
    int choice;
    char *Menu[] = {"Add all signals to a set",
                    "Add a signal to a set\n",
                    "Delete all signals from a set",
                    "Delete a signal from a set\n",
                    "Check if a signal in a set\n",
                    "Print signals\n",
                    "Exit"};

    do {
        choice = getMenu("Signal Set Management", Menu, 7);
        switch (choice) {
            case 1:
                my_sigfillset(set);
                printf("Signals 1 - 31 were added in a set.\n");
                break;
            case 2:
                signo = readSigno();
                my_sigaddset(set, signo);
                printf("Signal %d was added in a set.\n", signo);
                break;
            case 3:
                my_sigemptyset(set);
                printf("Signal set is empty.\n");
                break;
            case 4:
                signo = readSigno();
                my_sigdelset(set, signo);
                printf("Signal %d was deleted from a set.\n", signo);
                break;
            case 5:
                signo = readSigno();
                isInSet = my_sigismember(set, signo);
                if (isInSet){
                    printf("Signal %d is in a set.\n", signo);
                } else {
                    printf("Signal %d is not presented in a set.\n", signo);
                }
                break;
            case 6:
                print_signalSet(set);
                break;
            case 7:
                break;
        }
    } while (choice != 7);

    return EXIT_SUCCESS;
}



