// Created by Oleksandra Baga on 01.11.17.
// Write a program that allows interactive change or ask the environment variables
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "menu.h"

extern char **environ;

print_environList(){
    while (*environ){
        puts(*environ++); //post-increment
    }
}

print_environEntry(){
    
}


int main (int argv, char *args[]){

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
