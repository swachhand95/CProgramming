#include <stdio.h>

int main()
{
    int count[10];
    int nwhite, nother;
    int c;

    int i;
    for (i = 0; i < 10; ++i)
        count[i] = 0;
    nwhite = nother = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9') 
            ++count[c - '0'];
        if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else 
            ++nother;
    }

    printf("Digits: ");
    for (i = 0; i < 10; ++i)
        printf("%d ", count[i]);
    printf("%d %d\n", nwhite, nother);

}
