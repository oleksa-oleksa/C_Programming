#pragma once
#include "queue.h"
#include "process.h"

typedef struct
{
    TQueue *qready;
    TProcess *running;
} TPctx;

TPctx *ctx_new(TQueue *q);

// Human-readable information
void print(TPctx *ctx);

// The "Running" Process will be added into qready-queue with the status "Ready" and
// the first process from the queue will be executed and its status set to "Running"
void step(TPctx *ctx);