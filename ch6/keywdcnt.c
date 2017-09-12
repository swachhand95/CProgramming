#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "double", 0,
    "float", 0,
    "for", 0,
    "int", 0,
    "void", 0,
    "while", 0
};

int getword(char *word, int lim)
{
    char *w = word;
    int c;

    while (isspace(c = getchar()))
        ;
    if (c == EOF)
        return c;

    *w++ = c;
    for ( ; lim > 1 && isalnum(c = getchar()); --lim) {
        *w++ = c;
    }

    *w = '\0';
    return w[0];
}

int binsearch(char *word, struct key tab[], int n)
{
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(word, tab[mid].word);

        if (cmp < 0)
            high = mid - 1;
        else if (cmp > 0)
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int main()
{
    int n;
    char word[MAXWORD];


    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;

    for (n = 0; n < NKEYS; ++n)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}
