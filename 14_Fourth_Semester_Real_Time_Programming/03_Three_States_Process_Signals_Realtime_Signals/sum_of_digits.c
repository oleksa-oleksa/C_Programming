// Created by Oleksandra Baga on 09.12.17.
#include <stdlib.h>

int sum_of_digits(char *num){
    int number = atoi(num);

    if (!number){
        return -1;
    }

    int sum = 0;

    do{
        sum = sum + (number % 10);
        number = number / 10;
    } while(number);

    return sum;
}


int sum_of_numbers(int num){
    // folds the number to a single-digit number
    int sum = 0;
    do{
        sum = sum + (num % 10);
        num = num / 10;
    } while(num);

    return sum;
}