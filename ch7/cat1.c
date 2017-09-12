#include <stdio.h>

void file_copy(FILE *inf, FILE *outf);

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc == 1) {
        file_copy(stdin, stdout);
    }
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: Error can't open file - %s\n", *argv);
                return -1;
            }
            else {
                file_copy(fp, stdout);
            }
        }
    }

    return 0;

}


void file_copy(FILE *in, FILE *out)
{
    int c;

    while ((c = getc(in)) != EOF)
        putc(c, out);
}
