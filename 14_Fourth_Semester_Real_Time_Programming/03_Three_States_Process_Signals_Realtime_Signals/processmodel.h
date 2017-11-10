#pragma once
#include "queue.h"
#include "process.h"

typedef struct pctx_t
{
    queue *qready;
    process *running;
} pctx;

pctx *ctx_new(queue *q);

// Human-readable information
void print(pctx *ctx);

// The "Running" Process will be added into qready-queue with the status "Ready" and
// the first process from the queue will be executed and its status set to "Running"
void step(pctx *ctx);