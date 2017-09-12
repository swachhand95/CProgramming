#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, nc, nl, nw, state;

    nc = nl = nw = 0;
    state = OUT;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (state == IN && c != '\n')
            putchar(c);
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN)
                putchar('\n');
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            putchar(c);
            ++nw;
        }
    }

    printf("%d %d %d\n", nc, nl, nw);
}
