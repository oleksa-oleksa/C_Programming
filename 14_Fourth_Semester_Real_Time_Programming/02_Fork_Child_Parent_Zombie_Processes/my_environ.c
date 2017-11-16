// Created by Oleksandra Baga on 01.11.17.
// Write a program that allows interactive change or ask the environment variables
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tools.h"
#include "tools.h"
#include "menu.h"

extern char **environ;


void print_environList(){
    clearScreen();

    char **tmpEnv = environ;

    while (*tmpEnv){
        puts(*tmpEnv++); //post-increment
    }
    waitForEnter();
    clearScreen();
}

void print_environEntry(){
    char *environ_entry;
    getText("What do you want to know about your environment?: ", &environ_entry);
    printf("OK...\n");
    for (size_t i = 0; i < strlen(environ_entry); i++) {
        *(environ_entry + i) = toupper(*(environ_entry + i));
    }
    char *res = getenv(environ_entry);
    if (res){
        printf("%s = %s\n", environ_entry, res);
    }
    else {
        printf("%s not found\n", environ_entry);
    }
    waitForEnter();
    clearScreen();
}

void add_environEntry(){
    char *environ_entry;
    getText("What do you want to set in your environment? (NAME=param): ", &environ_entry);
    printf("OK...");
    putenv(environ_entry);
    printf("Done!\n");
    waitForEnter();
    clearScreen();

}
void modify_environEntry(){
    char *environ_entry, *environ_value;
    getText("Environment Variable NAME:\n", &environ_entry);
    getText("Environment Variable value:\n", &environ_value);

    printf("OK...\n");
    for (size_t i = 0; i < strlen(environ_entry); i++) {
        *(environ_entry + i) = toupper(*(environ_entry + i));
    }
    char *res = getenv(environ_entry);
    if (res){
        printf("%s is already exists! ", environ_entry);
        if(askYesOrNo("Do you want to overwrite? [ y / n ]: \n")){
            setenv(environ_entry, environ_value, 1);
            printf("%s was updated/modified\n", environ_entry);
        }
        else {
            printf("Canceled.\n");
        }
    }
    else {
        setenv(environ_entry, environ_value, 0);
        printf("New %s was added\n", environ_entry);

    }
    waitForEnter();
    clearScreen();

}

void remove_environEntry(){
    char *environ_entry;
    getText("What do you want to delete from your environment? (NAME):\n", &environ_entry);
    printf("OK...");
    for (size_t i = 0; i < strlen(environ_entry); i++) {
        *(environ_entry + i) = toupper(*(environ_entry + i));
    }
    unsetenv(environ_entry);
    printf("Done!\n");
    puts(getenv(environ_entry));
    waitForEnter();
    clearScreen();

}

int main (){

    clearScreen();

    int choice;
    char *Menu[] = {"Print environment list",
                    "Print environment enrty (getenv)",
                    "Add environment entry (putenv)",
                    "Modify environment entry (setenv)",
                    "Remove environment entry (unsetenv)",
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
