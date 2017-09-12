#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define INSIDE  1
#define OUTSIDE 0
#define DEFAULT_LIM 6

char *keywords[] = {        /* Contains a list of sorted keywords */
    "for",
    "while",
    "int",
    "char",
    "double",
    /* ... */
    "break"
};

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int get_identifier(char *word, int lim)
{
        
}

struct tnode *talloc(void);
struct tnode *addtree(struct tnode *p, char *word, int lim);
void treeprint(struct tnode *p);
char *strDup(char *w);
int strcmp(char *a, char *b, int lim);

int main(int argc, char *argv[])
{
    char word[MAXWORD];
    struct tnode *root;

    int lim = 0;
    if (argc == 2)
        lim = atoi(argv[1]);
    if (lim == 0)
        lim = DEFAULT_LIM;
    
    while (get_identifier(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word, lim);
        }
    }

    treeprint(root);

    return 0;
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strDup(char *w)
{
    char *p = (char *) malloc(strlen(w) + 1);
    if (p != NULL)
        strcpy(p, w);
    return p;
}

int strcmp(char *a, char *b, int lim)
{
    int i;

    if (lim <= 0)
        return 0;

    for (i = 0; i < lim && a[i] == b[i]; ++i)
        ;
    return a[i] - b[i];
}

struct tnode *addtree(struct tnode *p, char *word, int lim)
{
    int cond = 0;

    if (p == NULL) {
        p = talloc();
        p->word = strDup(word);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(word, p->word, lim)) == 0) {
        ++p->count;
    }
    else if (cond < 0) {
        p->left = addtree(p->left, word);
    }
    else {
        p->right = addtree(p->right, word);
    }

    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

