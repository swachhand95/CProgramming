#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...)
{
    /*
     * va_list ap : declares ap as the vararg list pointer
     *
     * va_start(ap, last_named_argument) : initializes ap to the argument
     * after the last_named_argument
     *
     * val = va_arg(ap, data_type) : assigns val a value specified by
     * the data_type and the argument ap
     *
     * va_end(ap) : does clean up
     */

    va_list ap;
    char *p, *str;
    int ival;
    double dval;

    va_start(ap, fmt);

    for (p = fmt; *p; ++p) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;            
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (str = va_arg(ap, char *); *str; ++str)
                putchar(*str);
            break;
        default:
            putchar(*p);
            break;
        }
    }

    va_end(ap);
}


int main()
{
    int a = 24;
    double d = 34.23;
    char *s = "Swachhand";

    minprintf("%d %f %s\n", a, d, s);
}
