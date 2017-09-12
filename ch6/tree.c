#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

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

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc(void);
struct tnode *addtree(struct tnode *p, char *word);
void treeprint(struct tnode *p);
char *strDup(char *w);

int main()
{
    char word[MAXWORD];
    struct tnode *root;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
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

struct tnode *addtree(struct tnode *p, char *word)
{
    int cond = 0;

    if (p == NULL) {
        p = talloc();
        p->word = strDup(word);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(word, p->word)) == 0) {
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
