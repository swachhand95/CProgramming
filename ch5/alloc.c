#include <stdio.h>
#include <string.h>
#include "alloc.h"

#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* Returns a pointer to n consecutive chars */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    return NULL;
}

/* Frees storage pointed to by p */
void afree(char *p)
{
    if (p >= allocbuf && p < allocp)
        allocp = p;
}

/* Copies string t to the end of string s */
void strCat(char *s, char *t)
{
    while (*s != '\0')
        ++s;
    while ((*s++ = *t++) != '\0')
        ;
    *s = '\0';
}


int strEnd(char *s, char *t)
{
    int slen = strlen(s);
    int tlen = strlen(t);

    char *send = s + slen;
    char *tend = t + tlen;

    while (send >= s && tend >= t && *send == *tend) {
        --send;
        --tend;
    }

    return tend <= t;
}
