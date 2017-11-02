// Created by Oleksandra Baga on 02.11.17.

#include <stdio.h>
#include <stdlib.h>
#include "processmodel.h"
#include "process.h"

TPctx *ctx_new(TQueue *q)
{
    TPctx *ctx = malloc(sizeof(TPctx));
    if (ctx) {
        ctx->qready = q;
        ctx->running = NULL;
        return ctx;
    }
    else {
        perror("Memory allocation problem");
    }
    return ctx;
}

void print(TPctx *ctx){
    printf("Running process: ");
    p_print(ctx->running);
    q_print(ctx->qready);
}

void step(TPctx *ctx) {
    if (ctx == NULL){
        return;
    }
// Case 1
//Case 2:
    if(ctx->running != NULL) {
        p_switch_state(ctx->running);
        q_add(ctx->qready, ctx->running);
    }

    TProcess *p_newRunning = q_remove(ctx->qready);
    p_switch_state(p_newRunning);
    ctx->running = p_newRunning;
}



