// Created by Oleksandra Baga on 01.11.17.
// Write a program that allows interactive change or ask the environment variables
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"
#include "tools.h"
#include "menu.h"

extern char **environ;


void print_environList(){
    clearScreen();
    while (*environ){
        puts(*environ++); //post-increment
    }
    waitForEnter();
}

void print_environEntry(){
    char *environ_entry;
    getText("What do you want to know about your environment?:\n", &environ_entry);
}

void add_environEntry(){

}

void modify_environEntry(){

}

void remove_environEntry(){

}

int main (){

    clearScreen();

    int choice;
    char *Menu[] = {"Print environment list",
                    "Print environment enrty (getenv)",
                    "Add environment entry (putenv)",
                    "Modify environment entry (setenv)",
                    "Remove environment entry (unsetenv",
                    "End"};

    do {

        choice = getMenu("Environment-List Menu", Menu, 6);

        switch (choice) {
            case 1:
                print_environList();
                break;
            case 2:
                print_environEntry();
                break;
            case 3:
                add_environEntry();
                break;
            case 4:
                modify_environEntry();
                break;
            case 5:
                remove_environEntry();
                break;
            case 6:
                break;
        }

    } while (choice != 6);

    return EXIT_SUCCESS;
}
