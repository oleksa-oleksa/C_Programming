// Created by Oleksandra Baga on 09.12.17.
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "sum_of_digits.h"

#define NUMBER_OF_THREADS 5
#define NUMBERS 1000

int g_sum;
int digits[NUMBERS];
int end = 1;
const int task_for_one = NUMBERS / NUMBER_OF_THREADS; // we assume there are 1000 numbers in the list

void read_file_in_array(char *file_name){
    FILE *f = fopen(file_name, "rt");
    if (!f) {
        printf("Error opening file %s\n", file_name);
        return;
    }

    char char_numbers[5]; // we assume that number is in a range 1 - 1000;
    int i = 0;
    while(!feof(f)){
        fgets(char_numbers, 5, f);
        int number = atoi(char_numbers);

        if (!number){
            continue;
        }
        digits[i] = number;
        i++;
    }
    fclose(f);
}

void print_array()
{
    for(int i = 0; i < NUMBERS; i++){
        printf("%d\n", digits[i]);
    }
}

int fold_numbers(int n){
    int sum_of_allSums = 0;
    int sum = 0;

   for (int i = n; i < end * task_for_one; i++) {
       sum = sum_of_numbers(digits[i]);
       if (sum < 0) {
           continue;
       }
       sum_of_allSums += sum;
   }
    return sum_of_allSums;
}

void *thread_process(void *arg)
{
    int *x = (int *) arg;
    int n = *x;
    int *sum =  malloc(sizeof(int));
    *sum = fold_numbers(n);
    if(*sum < 0){
        printf("Parse error!\n");
        return NULL;
    } else {
        printf("Successfully parsed.\n");
    }
    printf("The sum of all random numbers is: %i\n", *sum);

    return sum;
}

int main(int args, char *argv[]){
    if (args != 2) {
        printf("Usage: program_name <infile>\n");
        return -1;
    }

    int arr_pos[NUMBER_OF_THREADS];
    char *file = argv[1];

    // Creates Array with numbers
    read_file_in_array(file);

    pthread_t threads[NUMBER_OF_THREADS];

    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        arr_pos[i] = i * task_for_one;
        pthread_create(&threads[i] , NULL,  &thread_process , (void *) &arr_pos[i]);
    }
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("The sum of all sums is: %d\n", g_sum);
    return EXIT_SUCCESS;
}

