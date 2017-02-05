#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

#define MAX 15

/*********
 * The program opens a txt-file with a format
 *
 * 1 4 8 33 16 7
 *
 * sorts the digits and writes a new txt.file in a format
 *
 * 1
 * 4
 * 7
 * 8
 * 16
 * 33
 * *********/

void bubbleSort(int *Array, int Amount, int (*compare) (int, int));
void writeFile(char *Name, int *Digits);

/***+** This is what student has to write ***/

void readFile(char *, int **);

int compare(int, int);

void sortArray(int *);

/****** End of declarations **/

int main()
{
    int *ArrayOfDigits;

    readFile("data/unsort_digits.txt", &ArrayOfDigits);
    if (ArrayOfDigits != NULL)
    {
        sortArray(ArrayOfDigits);
        writeFile("data/sort_digits.txt", ArrayOfDigits);
    }
}

/*************
* This part is the task for a student
*************/

void readFile(char *Name, int **Digits)
{

    FILE *D = NULL;
    int *tmp = calloc(MAX, sizeof(int));

    D = fopen(Name, "r");

    if (D != NULL)
    {
        for (int i = 0; i < MAX; i++)
        {
            fscanf(D, "%i", (tmp + i));
            fgetc(D); // skip one white symbol
        }
    }
    else
    {
        printf("The source file can not be opened\n");
        waitForEnter();
    }

    fclose(D);
    *Digits = tmp;

    printf("All digits were read\n");
    waitForEnter();
}

int compare(int a, int b)
{
    return a - b;

}

void sortArray(int *Digits)
{
    int Amount;
    int *tmp = Digits;

    bubbleSort(Digits, MAX, compare);

}

/*************
* End of a task
*************/

void bubbleSort(int *Array, int Amount, int (*compare) (int, int))
{
    int i, j, temp;

    for (i = 1; i < Amount; i++)
    {
        for (j = Amount - 1; j >= 1; j-- )
        {
            if (compare(*(Array + j), *(Array + j - 1)) < 0 ) // if next is smaller than prev
            {
                temp = *(Array + j);
                *(Array + j) = *(Array + j - 1);
                *(Array + j - 1) = temp;
            }
        }
    }
}

void writeFile(char *Name, int *Digits)
{
    FILE *D;
    int i;

    D = fopen(Name, "w");

    if (D != NULL)
    {
        for (i = 0; i < MAX; i++)
        {
            fprintf(D, "%i\n", *(Digits + i));
        }

        free(Digits);
    }

    else
    {
        printf("The file for writing can not be opened\n");
        waitForEnter();

    }

    printf("All digits are now sorted. Check the sort.txt file!\n");
    waitForEnter();

}