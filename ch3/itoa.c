#include <stdio.h>
#include <string.h>

#define SIZE 100

void reverse(char s[]);
void itoa(int n, char s[]);
void itob(int n, char s[], int b);

int main()
{
    int a = 23551;
    int b = -34223;
    int c = 2;

    char n[SIZE] = {0};
    char n1[SIZE] = {0};
    char n2[SIZE] = {0};

    itoa(a, n);
    itoa(b, n1);
    itoa(c, n2);

    printf("%s\n", n);
    printf("%s\n", n1);
    printf("%s\n", n2);

    printf("%x\n", b);
    itob(b, n, 16);
    printf("%s\n", n);
}


void reverse(char s[])
{
    int i, j, c;

    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


void itoa(int n, char s[])
{
    int i = 0;
    int sign = 0;

    if (n < 0) {
        sign = 1;
        n = -n;
    }

    do {
        s[i++] = n % 10 + '0';
        n /= 10;
    } while (n);

    if (sign)
        s[i++] = '-';

    s[i++] = '\0';
    reverse(s);
}


char tob(int n, int b)
{
    if (n < b && n >= 10)
        return 'a' + n - 10;
    if (n < b)
        return '0' + n;
    return -1;
}

void itob(int n, char s[], int b)
{
    int i, sign;

    sign = 0;
    if (n < 0) {
        sign = 1;
        n = -n;
    }

    i = 0;
    do {
        s[i++] = tob(n % b, b);
        n /= b;
    } while (n);

    if (sign)
        s[i++] = '-';

    s[i++] = '\0';
    reverse(s);
}
