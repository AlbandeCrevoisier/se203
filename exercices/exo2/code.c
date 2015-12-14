#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int
main()
{
    int64_t a = 42;
    int64_t *b = malloc(sizeof(int64_t));
    int64_t c = (int64_t)&main;
    printf("stack: %p\n", (void*)&a);
    printf("heap: %p\n", (void*)b);
    printf("other sections: 0x%lx\n", c);

    return 0;
}

