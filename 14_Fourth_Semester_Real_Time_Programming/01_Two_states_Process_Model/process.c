#include <stdio.h>
#include "process.h"
#include <errno.h>

/* it is enough for this task "Two states process model
 * use a simple statement: p->p_state = !p->p_state;
 */
void p_switch_state(TProcess *p)
{
    if (p->p_state = 1)
    {
        p->p_state = 0;
    }

    else if (p->p_state = 0)
    {
        p-p_state = 1;
    }
}