#include <stdio.h>

#define WIDTH 8

void detab(char s[]);

int main()
{
    int c, cnt;
    cnt = 0;

    while ((c = getchar()) != EOF) {
        int i, lim;
        ++cnt;
        lim = WIDTH - cnt % WIDTH;
        if (c == '\n') {
            cnt = 0;
        }

        if (c == '\t') {
            for (i = 0; i < lim; ++i)
                putchar(' ');
        }
        else {
            putchar(c);
        }
    }

    return 0;
}
