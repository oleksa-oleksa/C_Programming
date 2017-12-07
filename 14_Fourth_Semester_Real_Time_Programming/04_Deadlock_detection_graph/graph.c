//
// Created by Oleksandra Baga on 07.12.17.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

#define STATE_WAITING 1
#define STATE_OCCUPIED 2

/* adjacency matrix is a square matrix used to represent a finite graph.
 * The elements of the matrix indicate whether pairs of vertices are adjacent or not in the graph.*/

int read_matrix(char *file_name, int **matrix, int *resources, int *threads)
{
    FILE *f = fopen(file_name, "rt");

    if (!f) {
        printf("Error opening file %s\n", file_name);
        return -1;
    }


    char state;
    int r, t, idx;
    int *m;

    fscanf(f, "%i\n", &r);
    fscanf(f, "%i\n", &t);

    // allocate space for adjacency matrix for the graph
    // of size r*c and access elements using pointer arithmetic.
    m = (int*)malloc(sizeof(int)*r*t);
    memset(m, 0, sizeof(int)*r*t);

    if (!m) {
        printf("Allocation failed\n");
        return -1;
    }

    // Consume graph definition line by line
    //
    while (!feof(f)) {
        int a, b;
        fscanf(f, "%c %i %i\n", &state, &a, &b);
        a--; // indexes for matrix
        b--;

        if (state == 'o') {
            // 'o' means first element is resource and second is thread
            // idx contains a one-dimensional offset equal to two-dimensional matrix address
            // it means (resource number * resources count) + thread number
            idx = a*r+b;
            m[idx] = STATE_OCCUPIED;

        } else if (state == 'w') {
            // 'w' means first element is thread and second is resource
            // Note reversed values in idx, that's because o and w has reversed arguments
            idx = b*r+a;
            m[idx] = STATE_WAITING;
        } else {
            printf("Invalid line, aborting\n");
            return -1;
        }
    }
    *threads = r;
    *resources = t;
    *matrix = m;

    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: graph <infile>\n");
        return -1;
    }

    int *matrix;
    int resources, threads;

    if (read_matrix(argv[1], &matrix, &resources, &threads) != 0) {
        return -2;
    }
    printf("Successful parsed.\n");

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    for (int i = 0; i < resources; i++){
        for (int j = 0; j < threads; j++){
            printf("%d ", *(matrix + i*threads + j));
        }
        printf("\n");
    }
    return 0;
}