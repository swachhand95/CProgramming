#include <stdio.h>

/* getbits:     get n bits from position p */
unsigned getbits(unsigned x, int p, int n);
unsigned getbits2(unsigned x, int p, int n);

/* setbits:     set n bits from position p of x to rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y);

/* invert:      inverts n bits from position p */
unsigned invert(unsigned x, int p, int n);

/* rightrot:    rightrotate x by n positions */
unsigned rightrot(unsigned x, int n);

int main()
{
    unsigned x = 45;
    unsigned y = 100;
    printf("%d\n", getbits(x, 4, 3) == getbits2(x, 4, 3));
    printf("%x\n", x);
    printf("%x\n", setbits(x, 4, 3, y));
    printf("%x\n", setbits(1, 8*sizeof(unsigned)-1, 5, 45));
    return 0;
}


unsigned getbits(unsigned x, int p, int n)
{
    return (x & ~(~0 << (p+1))) >> (p+1-n);
}


unsigned getbits2(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}


unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    x &= ~(~(~0 << n) << (p+1-n));
    return x | ((y && ~(~0 << n)) << (p+1-n));
}


unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p+1-n));
}


unsigned rightrot(unsigned x, int n)
{
    int nbits = 8 * sizeof(x);
    int to_shift = n % nbits;
    unsigned tmp = x >> to_shift;
    return setbits(tmp, nbits - 1, to_shift, x);
}
