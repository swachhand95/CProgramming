#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *name)
{
    unsigned hashval;
    
    for (hashval = 0; *name != '\0'; ++name)
        hashval = *name + 31 * hashval;

    return hashval % HASHSIZE;
}

struct nlist *lookup(char *name)
{
    struct nlist *p;

    for (p = hashtab[hash(name)]; p != NULL; p = p->next)
        if (strcmp(p->name, name) == 0)
            return p;

    return NULL;
}

char *strDup(char *w)
{
    char *p = (char *) malloc(strlen(w) + 1);
    if (p != NULL)
        strcpy(p, w);
    return p;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *p;
    int hashval = 0;

    if ((p = lookup(name)) == NULL) {
        p = (struct nlist *) malloc(sizeof(struct nlist));
        if (p == NULL || (p->name = strDup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        p->next = hashtab[hashval];
        hashtab[hashval] = p;
    }
    else {
        free ((void *) p->defn);
    }
    if ((p->defn = strDup(defn)) == NULL)
        return NULL;
    return p;
}
