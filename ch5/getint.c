#include <stdio.h>
#include <ctype.h>
#include "func.h"

#define SIZE 5

int getint(int *pn);

int main()
{
    int n;
    int array[SIZE];
    for (n = 0; n < SIZE && (getint(&array[n]) != EOF); ++n)
        ;
    
    for (n = 0; n < SIZE; ++n)
        printf("%d ", array[n]);
    printf("\n");
}


int getint(int *pn)
{
    int c;
    int sign = 1;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (*pn == 0 && c != '0') {
        ungetch(c);
        return 0;
    }
    if (c != EOF)
        ungetch(c);
    return c;
}
