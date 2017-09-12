#include <stdio.h>

#define MAXLINE 1000
#define N 5

int getLine(char s[], int lim);
void print_folded_line(char s[], int n, int len);
void print_line(char s[], int start, int end);

int main()
{
    char line[MAXLINE];
    int n = N;
    int len = 0;
    
    while ((len = getLine(line, MAXLINE)) != 0) {
        print_folded_line(line, n, len);
    } 

    return 0;
}


int getLine(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';

    return i;
}

void print_folded_line(char s[], int n, int len)
{
    int i, j;

    if (len > n) {
        for (i = 1; i <= len / n; ++i) {
            for (j = n * i - 1; (s[j] == ' ' || s[j] == '\t') && j >= n * (i - 1); --j)
                ;
            print_line(s, n * (i - 1), j);
        }
        print_line(s, j + 1, len - 1);
    }
}

void print_line(char s[], int start, int end)
{
    int i;
    for (i = start; i <= end; ++i) {
        /*if (s[i] == ' ')
            putchar('_');
        else*/
            putchar(s[i]);
    }
    putchar('\n');
}
