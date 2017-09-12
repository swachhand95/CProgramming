#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
    char n[] = "123.45e-6";
    printf("%lf\n", atof(n));

    return 0;
}


double atof(char s[])
{
    int i;
    int sign;
    int exp_sign;
    int exp;
    double val, power;

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = 10 * val + (s[i] - '0');

    if (s[i] == '.') 
        ++i;

    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E')
        ++i;
    exp_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        ++i;

    for (exp = 0; isdigit(s[i]); ++i)
        exp = 10 * exp + (s[i] - '0');

    if (exp_sign == -1) {
        for (i = 0; i < exp; ++i)
            val /= 10;
    }
    else {
        for (i = 0; i < exp; ++i)
            val *= 10;
    }

    return sign * val / power;
}
