#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "alloc.h"
#define MAXLINES 1000
#define MAXLEN 1000
#define DEFAULT 10

int getLine(char *s, int lim)
{
    int i;
    int c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines)
{
    int nlines = 0;
    int len;
    char *p;
    char line[MAXLEN];

    while ((len = getLine(line, MAXLEN)) > 0 && (p = alloc(len)) != NULL && nlines < maxlines) {
        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
    }

    return nlines;
}

void writelines(char *lineptr[], int start, int end)
{
    if (start > end)
        return;
    if (start < 0)
        start = 0;

    while (start <= end)
        printf("%s\n", lineptr[start++]);
}

/* atoi : returns 1 if the value is valid, 0 otherwise */
int atoi(char str[], int *val)
{
    int value = 0;
    int c;
    int sign;
    char *s = str;

    while (isspace(*s))
        ++s;

    sign = (*s == '-') ? -1 : 1;

    if (*s == '-' || *s == '+')
        ++s;

    for (value = 0; isdigit(c = *s++) && c != '\0'; )
        value = 10 * value + (c - '0');
    if (c != '\0')
        return 0;

    *val = sign * value;
    return 1;
}


int main(int argc, char *argv[])
{
    int n = DEFAULT;
    int nlines = 0;
    char *lineptr[MAXLINES];

    if (argc == 2 && (*++argv)[0] == '-') {
        if (!atoi(++argv[0], &n))
            n = DEFAULT;
    }

    nlines = readlines(lineptr, MAXLINES);

    printf("--------------------\n");
    if (nlines) {
        writelines(lineptr, nlines - n, nlines - 1);
    }

    return 0;
}
