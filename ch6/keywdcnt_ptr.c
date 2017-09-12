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

struct key *binsearch(char *word, struct key tab[], int n)
{
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    
    while (low < high) {
        struct key *mid = low + (high - low) / 2;
        int cmp = strcmp(word, mid->word);

        if (cmp < 0)
            high = mid;
        else if (cmp > 0)
            low = mid + 1;
        else
            return mid;
    }

    return NULL;
}

int main()
{
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((p = binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;

    for (p = keytab; p < keytab + NKEYS; ++p)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}
