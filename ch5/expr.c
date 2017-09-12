#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUMBER 0
#define OPERATOR 1
#define SIZE 100

static int stack[SIZE];
static int sp;

void push(int val)
{
    if (sp < SIZE)
        stack[sp++] = val;
}

int pop(void)
{
    if (sp > 0 && sp < SIZE)
        return stack[--sp];
    return -1;
}

int is_operator(char *s)
{
    if ((s[0] == '+'  ||
         s[0] == '-'  ||
         s[0] == '/'  ||
         s[0] == 'x') &&
         s[1] == '\0')
        return s[0];
    return NUMBER;
}

/* atoi : returns 1 if the value is valid, 0 otherwise */
int atoi(char str[], int *val)
{
    int value = 0;
    int c;
    int sign;
    char *s = str;

    while (isspace(*s))
        ++s;

    sign = (*s == '-') ? -1 : 1;

    if (*s == '-' || *s == '+')
        ++s;

    for (value = 0; isdigit(c = *s++) && c != '\0'; )
        value = 10 * value + (c - '0');
    if (c != '\0')
        return 0;

    *val = sign * value;
    return 1;
}


int main(int argc, char *argv[])
{
    char *s;

    if (argc < 2) {
        printf("Usage: expr expression\n");
        return -1;
    }

    while (--argc > 0 && (s = *++argv) != NULL) {
        char c;
        int op2;
        int val;
        if ((c = is_operator(s))) {
            switch(c) {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case 'x':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            }
        }
        else if (atoi(s, &val)) {
            push(val);
        }
        else {
            printf("Invalid input: %s\n", s);
            return -1;
        }
    }

    printf("%d\n", pop());
    return 0;
}
