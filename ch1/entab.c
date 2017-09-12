#include <stdio.h>

#define WIDTH 4

int main()
{
    int c, cnt, spaces;
    spaces = 0;
    cnt = 0;

    while ((c = getchar()) != EOF) {
        ++cnt;

        if (c == ' ') {
            ++spaces;
        }
        else {
            if (spaces >= 1) {
                int num = spaces / WIDTH;
                while (num--)
                    putchar('\t');
                num = spaces % WIDTH;
                while (num--)
                    putchar(' ');
                spaces = 0;
            }
            putchar(c);
        }
    }

    return 0;
}
