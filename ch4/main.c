#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP   100

int main()
{
    char s[MAXOP] = {0};
    int type;
    double op2;
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("Error: divide by zero\n");
            break;
        case '\n':
            printf("Result: %g\n", pop());
            break;
        default:
            printf("Error: unknown command\n");
        }
    }
}
