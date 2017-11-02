#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "process.h"
#include "queue.h"
#include "tools.h"
#include "processmodel.h"

void createTestProcesses(TProcess **processes, int processNumber){


    // creating 10 test processes
    for (int i = 0; i < processNumber; i++) {
        processes[i] = createProcess(i+1, READY);
    }
    printf("%d demo processes were created\n", AMOUNT_OF_PROCESSES);
    waitForEnter();
}
void addTestProcessIntoQueue(TQueue *queue, TProcess **processes, int processNumber){
    for (int i = 0; i < processNumber; i++) {
        q_add(queue, processes[i]);
    }
    printf("%d demo processes were added into queue\n", AMOUNT_OF_PROCESSES);
    q_print(queue);
    waitForEnter();
}

int main()
{
    TQueue *queueDemoStruct = q_new();
    TPctx *ctxDemo = NULL;

    if (queueDemoStruct)
    {
        TProcess *processList[AMOUNT_OF_PROCESSES];
        createTestProcesses(processList, AMOUNT_OF_PROCESSES);
        addTestProcessIntoQueue(queueDemoStruct, processList, AMOUNT_OF_PROCESSES);

        ctxDemo = ctx_new(queueDemoStruct);

        while(1) {
            step(ctxDemo);
            print(ctxDemo);
            sleep(1);
        };
    }
    free(queueDemoStruct);
    free(ctxDemo);
    return EXIT_SUCCESS;
}