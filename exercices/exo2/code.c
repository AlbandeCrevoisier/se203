#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void
f();

int
main()
{
    int64_t a = 42;
    int64_t *b = malloc(sizeof(int64_t));
    int64_t c = (int64_t)&f;
    printf("stack: %p\n", (void*)&a);
    printf("heap: %p\n", (void*)b);
    printf("other sections: 0x%lx\n", c);

    return 0;
}

void
f() {}
