#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

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

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    /* 
     * --argc : decrement argument count by one
     * (*++argv)[0]: First increment argv so that it now points to 
     *               the first argument (counting starts from 0.
     *               Then dereference it so that we now get a pointer
     *               to the zeroth character of the first string.
     *               Indexing it by zero gives us the value of the 
     *               zeroth character of the first argument.
     */
    while (--argc > 0 && (*++argv)[0] == '-') {
        /* 
         * *++argv[0]:  Since [] binds more tightly to argv, argv[0]
         *              means the first argument. ++argv[0] then in-
         *              -crements the pointer so that it points   to
         *              the first char of the first arg. Dereferenc-
         *              -ing it gives us the value of the first char
         */
        while (c = *++argv[0]) {
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
        }
    }

    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (getLine(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}
