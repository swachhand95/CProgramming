#include <stdio.h>

#define BUFSIZE 1000

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6

#define NUMSTATES 6
#define NUMINPUTS 3


 
int table[NUMSTATES][NUMINPUTS] = {{B, -1, -1},
    {-1, C, -1},
    {F, D, C},
    {E, -1, -1}, 
    {-1, -1, -1},
    {C, C, C}};


 
char buffer[BUFSIZE];
int last = 0;

void buf_append(char c)
{
    if (last < BUFSIZE)
        buffer[last] = c;
    ++last;
    buffer[last] = '\0';
}

void buf_clear()
{
    int i;
    for (i = 0; i < BUFSIZE; ++i)
        buffer[i] = 0;
    last = 0;
}

int is_final_state(int state) {
    return (state == E);
}

int is_illegal_state(int state) {
    return (state == -1);
}

int main()
{
    int in_quote, in_single_quote, c, prev;
    in_quote = in_single_quote = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\'' && !in_single_quote && prev != '\\') {
            putchar(c);
            in_single_quote = 1;
        }
        else if (c == '\'' && in_single_quote && prev != '\\') {
            putchar(c);
            in_single_quote = 0;
        }
        else if (c == '"' && !in_quote && prev != '\\') {
            putchar(c);
            in_quote = 1;
        }
        else if (c == '"' && in_quote && prev != '\\') {
            putchar(c);
            in_quote = 0;
        }
        else if (c == '/' && !in_quote && !in_single_quote) {
             
            int state;
            int nl;
            nl = 0;
            state = B;
            buf_append('/');     
            while (!is_illegal_state(state) && !is_final_state(state) && (c = getchar()) != EOF) {
                int in;
                if (c == '\n') {
                    in = 2;
                    ++nl;
                }
                else if (c == '*')
                    in = 1;
                else if (c == '/')
                    in = 0;
                else {
                    in = 2;
                }
                 
                state = table[state][in];
                buf_append(c);
            }
            if (is_final_state(state)) {
                 
                if (nl) {
                     
                    int i;
                    for (i = 0; i < nl; ++i)
                        putchar('\n');
                    nl = 0;
                }
                else {
                     
                    putchar(' ');
                }
                 
                buf_clear();
            }
            else if (is_illegal_state(state) || c == EOF) {
                


                printf("%s", buffer);
                buf_clear();
            }
        }
        else {
             
            putchar(c);
        }
         
        prev = c;
    }

    return 0;
}
