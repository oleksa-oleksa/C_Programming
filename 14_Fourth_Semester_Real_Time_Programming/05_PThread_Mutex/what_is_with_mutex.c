// Created by Oleksandra Baga on 21.12.17.

// Task: What will happen if you comment the lines 19 (mutex_lock) and 23 (mutex_unlock)

// Answer:
// Threads inside one process shared the global variables
// With Mutex all Threads wait and are blocked before Mutex will be unlocked
// Without Mutex Threads have the shared access to the variable at the same time =>
// the assign the initial value to be equal to 0 anf then add 1000. The result is 1000 (with Mutex is 5000)

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define NTHRDS 5

int sharedData = 0;
pthread_mutex_t mutex;


// start routine
void *add1000 (void *n)
{
    //pthread_mutex_lock(&mutex);
    int j = sharedData;
    sleep (rand () % 3);
    sharedData = j + 1000;
    //pthread_mutex_unlock(&mutex);
    puts ("1000 added!");
    return n;
}

int main ()
{
    pthread_t thrd [NTHRDS];
    int t;
    pthread_mutex_init(&mutex, NULL);
    srand (time (NULL));

    for  (t =0; t<NTHRDS; t++)
        pthread_create(&thrd[t] , NULL,  add1000 , NULL);

    for (t =0; t<NTHRDS; t++)
        pthread_join (thrd[t] , NULL);
    printf ("Shared data = %d\n", sharedData) ;
    return 0;
}