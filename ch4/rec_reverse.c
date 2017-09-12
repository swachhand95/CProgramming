#include <stdio.h>

#define SWAP(t,x,y) t c=x;x=y;y=c;
#define dprint(expr) printf(#expr "=%g\n", expr)

void swap(char s[], int i, int j);
void reverse(char s[], int left, int right);

void swap(char s[], int i, int j)
{
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
}

void reverse(char s[], int left, int right)
{
    if (left >= right)
        return;

    swap(s, left, right);
    reverse(s, left + 1, right - 1);
}

int main()
{
    char s[] = "Swachhand";

    printf("%s\n", s);
    reverse(s, 0, 8); 
    printf("%s\n", s);

    int x = 9;
    int y = 2;
    SWAP(int,x,y);
    dprint((double)x);
    dprint((double)y);
}
