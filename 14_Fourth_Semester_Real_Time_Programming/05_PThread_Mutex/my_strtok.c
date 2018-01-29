//
// Created by Oleksandra Baga on 21.12.17.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_THRDS 5

pthread_mutex_t mutex;

void *my_strtok(char *str, const char *delim, char *parsed){
    parsed = NULL;
    pthread_mutex_lock(&mutex);
    while(*str != *delim){
        *parsed = *str;
        str++;
        parsed++;
    }
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THRDS];
    char *str, *delim, *parsed;
    char *token = NULL;
    int j;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s string delim\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    str = argv[1];
    delim = argv[2];

    for (j = 1;  j < NUMBER_OF_THRDS; j++) {
        pthread_create(&threads[j], NULL, my_strtok, (void *) (&str, &delim, &parsed));

        printf("%s\n", token);

    }

    exit(EXIT_SUCCESS);
}