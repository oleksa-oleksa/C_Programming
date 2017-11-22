#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "queue.h"
#include "processmodel.h"

void signal_usr(int signo){

    // SIGUSR1 moves a process to the blocked queue
    if (signo == SIGUSR1) {
        printf("received SIGUSR1\n");
        q_add(dflt_pctx.qblocked);
    }

    // SIGUSR2 removes a process from the blocked queue
    else if (signo == SIGUSR2) {
        printf("received SIGUSR2\n");
    }

}


int q_isEmpty(queue *q)
{
    return (q->start == NULL) && (q->end == NULL);
}

queue *q_new()
{
    queue *q = malloc(sizeof(queue));
    q->start = NULL;
    q->end = NULL;
    return q;
}

int q_length(queue *q)
{
    int len = 0;
    q_node *n = q->start;

    while (n) {
        len++;
        n = n->next;
    }
    return len;
}

void q_add(queue *q, process *p)
{
    if (p == NULL)
    {
        return;
    }
    q_node *newNode = malloc(sizeof(q_node));
    if (newNode == NULL)
    {
        printf("Memory allocation error for process ID %d\n", p->p_id);
        return;
    }
    newNode->next = NULL;
    newNode->process = p;

    // Queue is empty => the first and only one process will be added
    if (q_isEmpty(q))
    {
        q->start = newNode;
    }
    else // if queue is not empty
    {
        q->end->next = newNode; // moves next on the new p
    }
    q->end = newNode; // places the new end of the queue
}

process *q_remove(queue *q)
{
    if (q_isEmpty(q))
    {
        return NULL;
    }

    q_node *deNode = q->start;
    if (q->start == q->end) {
        q->start = q->end = NULL;
    } else {
        q->start = q->start->next;

    }
    process *deProcess = deNode->process;
    free(deNode);
    return deProcess;
}

void q_print(queue *q)
{
    if (q_isEmpty(q))
    {   printf("The queue is empty\n");
        return;
    }

    int count = 1;
    q_node *tmpNode = q->start;

    printf("queue:\n");
    while (tmpNode != NULL)
    {
        printf("%02d. Process ID %d\n", count++, tmpNode->process->p_id);
        tmpNode = tmpNode->next;
    };
}
