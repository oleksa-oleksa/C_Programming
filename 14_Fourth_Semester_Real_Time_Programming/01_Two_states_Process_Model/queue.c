#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int q_isEmpty(TQueue *q)
{
    return (q->start == NULL) && (q->end == NULL);
}

TQueue *q_new()
{
    TQueue *q = malloc(sizeof(TQueue));
    q->start = NULL;
    q->end = NULL;
    return q;
}

int q_length(TQueue *q)
{
    int len = 0;
    TQ_node *n = q->start;

    while (n) {
        len++;
        n = n->next;
    }
    return len;
}

void q_add(TQueue *q, TProcess *p)
{
    if (p == NULL)
    {
        return;
    }
    TQ_node *newNode = malloc(sizeof(TQ_node));
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

TProcess *q_remove(TQueue *q)
{
    if (q_isEmpty(q))
    {
        return NULL;
    }

    TQ_node *deNode = q->start;
    if (q->start == q->end) {
        q->start = q->end = NULL;
    } else {
        q->start = q->start->next;

    }
    TProcess *deProcess = deNode->process;
    free(deNode);
    return deProcess;
}

void q_print(TQueue *q)
{
    if (q_isEmpty(q))
    {   printf("The queue is empty\n");
        return;
    }

    int count = 1;
    TQ_node *tmpNode = q->start;

    printf("The current queue:\n");
    while (tmpNode != NULL)
    {
        printf("%02d. Process ID %d\n", count++, tmpNode->process->p_id);
        tmpNode = tmpNode->next;
    };
}
