#include <stdio.h>

#define MAXLINE 5

int getLine(char line[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len;
    int maxlen;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getLine(line, MAXLINE)) != 0)
    {
        if (len > maxlen)
        {
            maxlen = len;
            copy(longest, line);
        }
    }

    printf("%d %s\n", maxlen, longest);
}

int getLine(char line[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    for (i = 0; (to[i] = from[i]) != '\0'; ++i)
        ;
}

int slen(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; ++i)
        ;
    return i + 1;
}
