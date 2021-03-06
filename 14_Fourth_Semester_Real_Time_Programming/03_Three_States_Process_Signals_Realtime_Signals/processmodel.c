// Created by Oleksandra Baga on 02.11.17.

#include <stdio.h>
#include <stdlib.h>
#include "processmodel.h"
#include "process.h"

pctx *dflt_pctx;


pctx *ctx_new(queue *q, queue *b)
{
    pctx *ctx = malloc(sizeof(pctx));
    if (ctx) {
        ctx->qready = q;
        ctx->qblocked = b;
        ctx->running = NULL;
        return ctx;
    }
    else {
        perror("Memory allocation problem");
    }
    return ctx;
}

void print(pctx *ctx){
    printf("Running process:\n");
    p_print(ctx->running);
    printf("Ready processes:\n");
    q_print(ctx->qready);
    printf("Blocked processes:\n");
    q_print(ctx->qblocked);
}

void step(pctx *ctx) {
    if (ctx == NULL){
        return;
    }

    if (ctx->running == NULL && ctx->qready->start == NULL){
        return;
    }

    if(ctx->running != NULL) {
        p_switch_state(ctx->running);
        q_add(ctx->qready, ctx->running);
    }

    process *p_newRunning = q_remove(ctx->qready);
    p_switch_state(p_newRunning);
    ctx->running = p_newRunning;


}



