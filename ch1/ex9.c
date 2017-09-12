#include <stdio.h>

int main()
{
    int blank;
    int c;

    blank = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (blank != 1)
                putchar(' ');
            blank = 1;
        }
        else {
            blank = 0;
            putchar(c);
        }
    } 

    c = getchar();
    if (c == '\b')
        printf("baak\n");
    printf("%x\n", c);
}
