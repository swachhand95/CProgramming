#include <stdio.h>
#include <stdlib.h>

void file_copy(FILE *inf, FILE *outf);

int main(int argc, char *argv[])
{
    FILE *fp;
    char *prog = argv[0];

    if (argc == 1) {
        file_copy(stdin, stdout);
    }
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: Error can't open file - %s\n", prog, *argv);
                exit(1);
            }
            else {
                file_copy(fp, stdout);
                fclose(fp);
            }
        }
    }

    if (ferror(stdout)) {
        fprintf(stderr, "%s: Error writing to stdout\n", prog);
        exit(1);
    }

    exit(0);
}


void file_copy(FILE *in, FILE *out)
{
    int c;

    while ((c = getc(in)) != EOF)
        putc(c, out);
}
