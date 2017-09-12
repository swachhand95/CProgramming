#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alloc.h"

#define MAXLINES 1000
#define MAXLEN 100

int getLine(char line[], int len);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void sort(void *v[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    if (v1 > v2)
        return 1;
    return 0;
}

int main(int argc, char *argv[])
{
    char *lines[MAXLINES];
    int len = 0;
    int numeric = 0;

    if (argc == 2 && strcmp(argv[1], "-n") == 0)
        numeric = 1;

    if ((len = readlines(lines, MAXLINES)) > 0) {
        if (numeric)
            sort((void **) lines, 0, len - 1, (int (*)(void *, void *))(numcmp));
        else
            sort((void **) lines, 0, len - 1, (int (*)(void *, void *))(strcmp));
        printf("--------------------\n");
        writelines(lines, len);
    }
    else {
        printf("Error: Couldn't read lines\n");
        return 1;
    }

    return 0;
}


int readlines(char *lineptr[], int maxlines)
{
    char *p;
    char line[MAXLEN];
    int nlines = 0;
    int len = 0;

    while ((len = getLine(line, MAXLEN)) > 0) {
        if (nlines > maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}


void writelines(char *lineptr[], int nlines)
{
    int i = 0;
    for (i = 0; i < nlines; ++i)
        printf("%s\n", lineptr[i]);
}


int getLine(char line[], int lim)
{
    int i;
    int c = 0;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';

    return i;
}


void swap(void *arr[], int a, int b)
{
    void *temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void sort(void *lineptr[], int left, int right, 
        int (*comp)(void *, void *))
{
    int mid = left + (right - left) / 2;
    int i, last;

    if (left >= right)
        return;

    swap(lineptr, left, mid);

    last = left;
    for (i = left + 1; i <= right; ++i) {
        if ((*comp)(lineptr[i], lineptr[left]) < 0) {
            ++last;
            swap(lineptr, i, last);
        }
    }

    swap(lineptr, left, last);
    
    sort(lineptr, left, last - 1, comp);
    sort(lineptr, last + 1, right, comp);
}
