#include <stdint.h>
#include <stdio.h>

int32_t x = 42;
int32_t y;
const char *msg = "Hello World!\n";

int
main()
{
    static uint8_t z;
    uint16_t t;

    y = 42;
    z = z + 1;
    t = y + z;

    printf(msg);
    printf("x = %ld, y = %ld, z = %d, t = %u\n", x, y, z, t);

    return 0;
}

