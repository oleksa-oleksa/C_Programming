#pragma once
#include <stdlib.h>
#define MAX_PID 3000
#define STATE_MODEL 3
#define AMOUNT_OF_PROCESSES 10

typedef enum
{
    READY = 0,
    RUNNING = 1,
    BLOCKED = 2,
    NOT_A_STATE = 3
} state;

typedef struct process_t
{
    uint32_t p_id; //unsigned int
    state p_state;
} process;

void p_switch_state(process *p);

void p_print(process *p);

process *createProcess(unsigned int seed_ID, state p_state);
