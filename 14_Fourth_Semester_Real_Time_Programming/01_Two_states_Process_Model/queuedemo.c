#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "process.h"
#include "queue.h"
#include "tools.h"


int main()
{
    int isValid = 0;
    int nProcesses;
    TQueue *queueDemoStruct = malloc(sizeof(TQueue));
    if (queueDemoStruct)
    {
        queueDemoStruct->start = NULL;
        queueDemoStruct->end = NULL;
        TProcess *queueDemoProcesses[AMOUNT_OF_PROCESSES];

        do {
            clearScreen();
            srand(time(NULL));

            // creating test processes
            for (int i = 0; i < AMOUNT_OF_PROCESSES; i++) {
                *(queueDemoProcesses + i) = createProcess(rand() % MAX_PID, READY);
            }
            printf("%d demo processes were created\n", AMOUNT_OF_PROCESSES);
            waitForEnter();

            // adding into queue
            for (int i = 0; i < AMOUNT_OF_PROCESSES; i++) {
                q_add(queueDemoStruct, queueDemoProcesses[i]);
            }
            printf("%d demo processes were added into queue\n", AMOUNT_OF_PROCESSES);
            q_print(queueDemoStruct);
            waitForEnter();

            // Executing elements from the queue
            do {
                int queue_size = q_length(queueDemoStruct);
                printf("How much elements [1 - %d] do you want to execute from the queue? : ", queue_size);
                isValid = scanf("%i", &nProcesses);
                clearBuffer();

                if (nProcesses > queue_size || nProcesses < 0) {
                    isValid = 0;
                }

            } while (!isValid);

            for (int i = 0; i < nProcesses; i++) {
                q_remove(queueDemoStruct);
            }
            printf("%d processes were executed from the queue\n", nProcesses);
            q_print(queueDemoStruct);
            waitForEnter();


        } while (askYesOrNo("Do you want to repeat? [ y / n] : "));
    }
    return EXIT_SUCCESS;
}