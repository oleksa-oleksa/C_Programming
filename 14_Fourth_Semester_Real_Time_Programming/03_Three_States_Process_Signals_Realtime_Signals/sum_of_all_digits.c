// Created by Oleksandra Baga on 09.12.17.
#include "sum_of_digits.h"
#include <stdio.h>
#include <stdlib.h>

int fold_numbers(char *file_name){
    int sum_of_allSums = 0;
    FILE *f = fopen(file_name, "rt");
    if (!f) {
        printf("Error opening file %s\n", file_name);
        return -2;
    }

    char c;
    int lines = 0;
    // counting lines for array allocation
    while(!feof(f))
    {
        c = fgetc(f);
        if(c == '\n')
        {
            lines++;
        }
    }
    printf("%i lines are in the file %s\n", lines, file_name);

    // go to the begin of the file
    fseek(f, 0L, SEEK_SET);

    char *char_numbers[5]; // we assume that number is in a range 1 - 1000;
    int numbers[lines];
    int i = 0;

    while(!feof(f)) {
        fgets(char_numbers[i], 5, f);
        numbers[i] = sum_of_digits(char_numbers[i]);
        i++;
    }
    fclose(f);

    // numbers holds the all sum_of_digits from all random numbers
    // numbers-array should be fold and its sum should be the result of function execution

    // if the sum is bigger as single-digit number - the new sum will be counted
    for (i = 0; i < lines; i++){
        numbers[i] = sum_of_numbers(numbers[i]);
        sum_of_allSums = sum_of_allSums + numbers[i];
    }
    return sum_of_allSums;
}

int main(int args, char *argv[]){

    int sum = 0;

    if (args != 2) {
        printf("Usage: program_name <infile>\n");
        return -1;
    }

    sum = fold_numbers(argv[1]);
    if(sum < 0){
        printf("Parse error!\n");
        return -1;
    }
    else {
        printf("Successfully parsed.\n");
    }
    printf("The sum of all random numbers is: %i\n", sum);

    return EXIT_SUCCESS;
}

