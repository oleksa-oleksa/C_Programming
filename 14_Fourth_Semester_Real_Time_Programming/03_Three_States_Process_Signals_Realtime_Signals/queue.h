#pragma once
#include "process.h"

// Queue FIFO (First In First Out)

typedef struct q_node_t
{
    struct q_node_t *next;
    process *process;
} q_node;

typedef struct queue_t
{
    q_node *start;
    q_node *end;
} queue;

queue *q_new();
void q_add(queue *q, process *p);
process *q_remove(queue *q);
void q_print(queue *q);
int q_length(queue *q);