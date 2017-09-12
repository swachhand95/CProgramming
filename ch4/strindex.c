#include <stdio.h>
#include <string.h>

#define SIZE 1000

int getLine(char s[], int max);
int stridx(char s[], char t[]);
int strridx(char s[], char t[]);

char pattern[] = "ould";

int main()
{
    char s[SIZE] = {0};
    int found = 0;

    while (getLine(s, SIZE) > 0) {
        int idx = stridx(s, pattern);
        int ridx = strridx(s, pattern);
        if (idx >= 0) {
            ++found;
            printf("%s%d %d\n", s, idx, ridx);
        }
    }

    return found;
}


int getLine(char s[], int lim)
{
    int i = 0;
    int c = 0;

    for (i = 0; --lim > 0 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}


int stridx(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; ++i) {
        for (j = i, k = 0; s[j] != '\0' && t[k] != '\0' && s[j] == t[k]; ++j, ++k)
            ;
        if (t[k] == '\0')
            return i;
    }

    return -1;
}


int strridx(char s[], char t[])
{
    int slen = strlen(s);
    int tlen = strlen(t);
    int i, j, k;

    for (i = slen - 1; i >= 0; --i) {
        for (j = i, k = tlen - 1; j >= 0 && k >= 0 && s[j] == t[k]; --j, --k)
            ;
        if (k == -1)
            return j + 1;
    }

    return -1;
}
