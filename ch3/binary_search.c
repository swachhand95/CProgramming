#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define SIZE 100

/* binsearch:   find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n);

/* escape:  convert escape sequences into visible characters */
void escape(char t[], char s[]);

/* unescape:    convert visible chars in s into escape sequences in t */
void unescape(char t[], char s[]);

/* atoi:    converts string into int */
int atoi(char s[]);

clock_t begin, end;
double time_spent;

int main()
{
    int v[10] = {1, 2, 3, 4, 4, 5, 5, 5, 100, 324};

    char a[SIZE] = "HELLO\nBYE\tBYE\t\n";
    char b[SIZE] = {0};
    char c[SIZE] = {0};

    int i;
    begin = clock();
    for (i = 0; i < 10; ++i)
        printf("%d\n", binsearch(i, v, 10));
    printf("%d\n", binsearch(-12, v, 10));
    printf("%d\n", binsearch(324, v, 10));
    printf("%d\n", binsearch(100, v, 10));
    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("%lf\n", time_spent);

    printf("%s", a);
    escape(b, a);
    printf("%s", b);

    unescape(c, b);
    printf("%s", c);

    char n1[] = "   -123445";
    char n2[] = "   123445";
    char n3[] = "   +123445";
    char n4[] = "123445";

    printf("%d\n", atoi(n1));
    printf("%d\n", atoi(n2));
    printf("%d\n", atoi(n3));
    printf("%d\n", atoi(n4));
    
    return 0;
}


int binsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;

    while (low <= high && v[mid] != x) {
        mid = low + (high - low) / 2;

        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (v[mid] == x)
        return mid;

    return -1;
}


void escape(char t[], char s[])
{
    int i = 0;
    int j = 0;

    while (s[i] != 0) {
        switch (s[i]) {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        default:
            t[j++] = s[i];
            break;
        }
        ++i;
    }
}


void unescape(char a[], char b[])
{
    int i = 0;
    int j = 0;
    while (b[i] != 0) {
        if (b[i] == '\\') {
            ++i;
            switch(b[i]) {
                case 'n':
                    a[j++] = '\n';
                    break;
                case 't':
                    a[j++] = '\t';
                    break;
            }
        }
        else {
            a[j++] = b[i];
        }
        ++i;
    }
}


int atoi(char s[])
{
    int i;
    int sign;
    int n;

    for (i = 0; isspace(s[i]); ++i)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    
    if (s[i] == '-' || s[i] == '+')
        ++i;

    for (n = 0; isdigit(s[i]); ++i)
        n = 10 * n + (s[i] - '0');

    return n * sign;
}
