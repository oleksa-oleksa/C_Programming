#pragma once
#include "process.h"

// Queue FIFO (First In First Out)

typedef struct SQ_node
{
    struct SQ_node *next;
    TProcess *process;
} TQ_node;

typedef struct SQueue
{
    TQ_node *start;
    TQ_node *end;
} TQueue;

void q_add(TQueue *q, TProcess *p);
TProcess *q_remove(TQueue *q);
void q_print(TQueue *q);
int q_length(TQueue *q);