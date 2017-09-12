#include <stdio.h>

void itoa(int n, char s[]);
void itoa(int n, int *i, char s[], int sign);

void itoa(int n, char s[])
{
    int i = 0;
    itoa(n, &i, s, 0);
}

void itoa(int n, int *i, char s[], int sign)
{
    if (n < 0) {
        n = -n;
        sign = 1;
    }

    if (n / 10)
        itoa(n / 10, i, s, sign);
    else if (sign)
        s[*i++] = '-';

    s[*i++] = n % 10 + '0';
}


int main()
{
    char s[10] = {0};

    itoa(12343, s);
    printf("%s\n", s);
    itoa(-12343, s);
    printf("%s\n", s);
}
