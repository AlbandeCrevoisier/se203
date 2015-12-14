#include <stdio.h>

int
f();

int
main()
{
	int x = 42;
    printf("first: %p\n", (void *) &x);
    f();

    return 0;
}

int
f()
{
    int x = 42;
    printf("second: %p\n", (void *) &x);

    return 0;
}

