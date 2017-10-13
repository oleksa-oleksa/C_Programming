#pragma once

typedef enum
{
    READY = 0,
    RUNNING = 1
} TState;

typedef struct
{
    uint32_t p_id; //unsigned int
    TState p_state;
} TProcess;

void p_switch_state(TProcess *p);

void p_print(TProcess *p);