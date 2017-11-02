// Created by Oleksandra Baga on 02.11.17.

#include <stdio.h>
#include <stdlib.h>
#include "processmodel.h"
#include "process.h"

TPctx *ctx_new(TQueue *q)
{
    TPctx *ctx = malloc(sizeof(TPctx));
    ctx->qready = q;
    ctx->running = q->start->process;
    return ctx;
}

void print(TPctx *ctx){
    char *currentState[] = {"READY", "RUNNING", "NOT A STATE"};

    TProcess *current = ctx->running;
    printf("Current running process is %d (state %s)\n", current->p_id, currentState[current->p_state]);

    printf("Process waiting list:\n");
    q_print(ctx->qready);
}

void step(TPctx *ctx){
    if (ctx == NULL){
        return;
    }

    ctx->running->p_state = READY;
    TProcess *p = q_remove(ctx->qready);
    q_add(ctx->qready, p);
    ctx->running = ctx->qready->start->process;
    ctx->running->p_state = RUNNING;

}


