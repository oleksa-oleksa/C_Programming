#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "process.h"
#include "queue.h"
#include "tools.h"
#include "processmodel.h"

void createTestProcesses(process **processes, int processNumber){

    // creating 10 test processes
    for (int i = 0; i < processNumber; i++) {
        processes[i] = createProcess(i+1, READY);
    }
    printf("%d demo processes were created\n", AMOUNT_OF_PROCESSES);
}

void addTestProcessIntoQueue(queue *queue, process **processes, int processNumber){
    for (int i = 0; i < processNumber; i++) {
        q_add(queue, processes[i]);
    }
    printf("%d demo processes were added into queue\n", AMOUNT_OF_PROCESSES);
    q_print(queue);
}

int main()
{
    signal(SIGUSR1, signal_usr);
    signal(SIGUSR2, signal_usr);

    queue *queueDemoStructReady= q_new();
    queue *queueDemoStructBlocked = q_new();

    if (queueDemoStructReady && queueDemoStructBlocked)
    {
        process *processList[AMOUNT_OF_PROCESSES];
        createTestProcesses(processList, AMOUNT_OF_PROCESSES);
        addTestProcessIntoQueue(queueDemoStructReady, processList, AMOUNT_OF_PROCESSES);

        dflt_pctx = ctx_new(queueDemoStructReady, queueDemoStructBlocked);

        while(1) {
            step(dflt_pctx);
            print(dflt_pctx);
            sleep(1);
        };
    }
    free(queueDemoStructReady);
    free(queueDemoStructBlocked);
    free(dflt_pctx);
    return EXIT_SUCCESS;
}