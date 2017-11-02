#include <stdio.h>
#include <time.h>
#include "process.h"
#include "tools.h"

/* it is enough for this task "Two states process model
 * use a simple statement: p->p_state = !p->p_state;
 */
void p_switch_state(TProcess *p)
{
    // toggles running => ready
    if (p->p_state == 1)
    {
        p->p_state = 0;
    }
    // toggles ready => running
    else if (p->p_state == 0)
    {
        p->p_state = 1;
    }
}


void p_print(TProcess *p) {
    char *currentState[] = {"READY", "RUNNING", "NOT A STATE"};
    TState tmpState = p->p_state;

    if (tmpState < STATE_MODEL) // no negative number for state is considering
    {
        printf("The process ID %d is %s.\n", p->p_id, currentState[tmpState]);
    }

    else // of state is a negative number or the number is greater then amount of states
    {
        tmpState = NOT_A_STATE;
        printf("Warning! %s is detected for the process ID %d\n", currentState[tmpState], p->p_id);
    }
}

TProcess *createProcess(uint32_t p_id, TState p_state)
{
    TProcess *tmpProcess = NULL;
    tmpProcess = malloc(sizeof(TProcess));

    if (tmpProcess)
    {
        tmpProcess->p_id = p_id;
        tmpProcess->p_state = p_state;
        printf("New process was created: ");
        p_print(tmpProcess);
        return tmpProcess;
    }
    else
    {
        return NULL;
    }
}