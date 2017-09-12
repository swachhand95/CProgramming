#include <stdio.h>
#include <ctype.h>

#define SIZE 1000

void expand(char s1[], char s2[]);

int main()
{
    char s1[] = "a-zA-Z0-9";
    char s2[] = "afkjld-jdkfj5-9A-z";
    char s[SIZE] = {0};

    expand(s1, s);
    printf("%s\n", s);
    expand(s2, s);
    printf("%s\n", s);

    return 0;
}


void expand(char s1[], char s2[])
{
    int i, j;
    
    j = 0;
    for (i = 1; s1[i] != 0; ++i) {
        if (s1[i] == '-') {
            if (isdigit(s1[i-1]) && isdigit(s1[i+1]) &&
                    s1[i-1] < s1[i+1]) {
                /* put s1[i-1] to s1[i+1] in s2 */
                int a = s1[i-1];
                int b = s1[i+1];
                while (a <= b) {
                    s2[j++] = a++;
                }
            }
            else if (islower(s1[i-1]) && islower(s1[i+1]) &&
                    s1[i-1] < s1[i+1]) {
                /* put s1[i-1] to s1[i+1] in s2 */
                int a = s1[i-1];
                int b = s1[i+1];
                while (a <= b) {
                    s2[j++] = a++;
                }
            }
            else if (isupper(s1[i-1]) && isupper(s1[i+1]) &&
                    s1[i-1] < s1[i+1]) {
                /* put s1[i-1] to s1[i+1] in s2 */
                int a = s1[i-1];
                int b = s1[i+1];
                while (a <= b) {
                    s2[j++] = a++;
                }
            }
            else {
                /* copy as is */
                s2[j++] = s1[i-1];
                s2[j++] = s1[i];
                s2[j++] = s1[i+1];
            }
        }
    }

    s2[j] = '\0';
}
