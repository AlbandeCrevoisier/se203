#include <stdint.h>
#include <stdio.h>

int32_t x = 42;
int32_t y;
const char msg[] = "Hello World!\n";

int
main()
{
    static uint8_t z;
    uint16_t t;

    y = 42;
    z = z + 1;
    t = y + z;

    printf(msg);
    printf("x = %d, y = %d, z = %u, t = %u\n", x, y, z, t);

    printf("\n\nsizeof:\n");
    printf("42, 42, 1, 0: %lu\n",sizeof(42));
    printf("msg, \"Hello world!\": %lu %lu\n", sizeof(msg),
        sizeof("Hello world!\n"));

    return 0;
}

