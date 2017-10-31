#pragma once
#include <stdlib.h>
#define MAX_PID 3000
#define STATE_MODEL 2
#define AMOUNT_OF_PROCESSES 10


typedef enum
{
    READY = 0,
    RUNNING = 1,
    NOT_A_STATE = 2
} TState;

typedef struct
{
    uint32_t p_id; //unsigned int
    TState p_state;
} TProcess;

void p_switch_state(TProcess *p);

void p_print(TProcess *p);

TProcess *createProcess(unsigned int seed_ID, TState p_state);
