#include <stdio.h>
#include "calc.h"

#define MAXVAL  100

static int sp = 0;
static double val[MAXVAL];

void push(double n)
{
    if (sp >= MAXVAL)
        printf("Error: not enough space on stack to push %g\n", n);
    else
        val[sp++] = n;
}

double pop()
{
    if (sp > 0)
        return val[--sp];
    printf("Error: stack is empty\n");
    return -1;
}
