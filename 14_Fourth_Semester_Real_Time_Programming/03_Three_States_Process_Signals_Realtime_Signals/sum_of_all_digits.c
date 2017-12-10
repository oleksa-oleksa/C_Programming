// Created by Oleksandra Baga on 09.12.17.
#include "sum_of_digits.h"
#include <stdlib.h>

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

