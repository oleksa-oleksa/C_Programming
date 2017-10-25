#pragma once

// Queue FIFO (First In First Out)

typedef struct
{
    TQ_node *next;
    TProcess *process;
} TQ_node;

typedef struct
{
    TQ_node *first;
    TQ_node *last;
} TQueue;
