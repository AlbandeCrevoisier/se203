#include <stdio.h>
#include <stdint.h>

int
main ()
{
    int foo = 42;
    int bar = 42;
    int baz = 42;

    printf("%u\n", &foo);
    printf("%u\n", &bar);
    printf("%u\n", &baz);

    return 0;
}

