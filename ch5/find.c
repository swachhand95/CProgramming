#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *line;
    int found = 0;
    size_t len = 0;

    if (argc != 2) {
        printf("Usage: find pattern\n");
    }
    else {
        do {
            getline(&line, &len, stdin);
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                ++found;
            }
        } while (len > 0);
    }
}
