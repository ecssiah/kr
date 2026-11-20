#include <stdio.h>
#include "calc.h"

#define MAXVAL  100

int stack_index = 0;
double val[MAXVAL];

void 
push(double f)
{
    if (stack_index < MAXVAL)
    {
        val[stack_index++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

double 
pop(void)
{
    if (stack_index > 0)
    {
        return val[--stack_index];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double
peek(void)
{
    if (stack_index > 0)
    {
        return val[stack_index];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
